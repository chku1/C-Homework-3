#ifndef lacpp_sorted_list_hpp
#define lacpp_sorted_list_hpp lacpp_sorted_list_hpp
#include <mutex>

/* a sorted list implementation by David Klaftenegger, 2015
 * please report bugs or suggest improvements to david.klaftenegger@it.uu.se
 */

/* struct for list nodes */
template<typename T>
struct node {
	T value;
	node<T>* next;
	//create seperate locks for every node
	std::mutex m;
};

/* non-concurrent sorted singly-linked list */
template<typename T>
class sorted_list {
	node<T>* first = nullptr;

	//create one general lock for count
	std::mutex mtx;
	public:
		/* default implementations:
		 * default constructor
		 * copy constructor (note: shallow copy)
		 * move constructor
		 * copy assignment operator (note: shallow copy)
		 * move assignment operator
		 *
		 * The first is required due to the others,
		 * which are explicitly listed due to the rule of five.
		 */
		sorted_list() = default;
		sorted_list(const sorted_list<T>& other) = default;
		sorted_list(sorted_list<T>&& other) = default;
		sorted_list<T>& operator=(const sorted_list<T>& other) = default;
		sorted_list<T>& operator=(sorted_list<T>&& other) = default;
		~sorted_list() {
			while(first != nullptr) {
				remove(first->value);
			}
		}
		/* insert v into the list */
		void insert(T v) {
			/* first find position */
			node<T>* pred = nullptr;
			node<T>* succ = first;
			//lock succ if the list is not empty
			if(first!=nullptr){
				succ->m.lock();
			}
			while(succ != nullptr && succ->value < v) {
				//unlock the previous node
				if(pred!=nullptr){
					pred->m.unlock();
				}
				pred = succ;
				succ = succ->next;
				//lock the succ node
				if(succ!=nullptr){
					succ->m.lock();
				}
				
			}


			
			/* construct new node */
			node<T>* current = new node<T>();
			current->value = v;

			/* insert new node between pred and succ */
			current->next = succ;
			if(pred == nullptr) {
				first = current;
				
			} else {
				pred->next = current;
			}
			//unlock both of the nodes if locked
			if(pred!=nullptr){
				pred->m.unlock();
			}
			
			if(succ!=nullptr){
				succ->m.unlock();
			}
			
		}

		void remove(T v) {
			/* first find position */

			node<T>* pred = nullptr;
			node<T>* current = first;
			//lock current if the list is not empty
			if(first!=nullptr){
				current->m.lock();
			}
			while(current != nullptr && current->value < v) {
				//unlock the previous node
				if(pred!=nullptr){
					pred->m.unlock();
				}
				pred = current;
				current = current->next;
				//lock the current node
				if(current!=nullptr){
					current->m.lock();
				}
				
			}

			if(current == nullptr || current->value != v) {
				//unlock both nodes if locked
				if(current!=nullptr){
					current->m.unlock();
				}
				if(pred!=nullptr){
					pred->m.unlock();
				}
				/* v not found */
				return;
			}
			/* remove current */
			if(pred == nullptr) {
				first = current->next;
			}
			else {
				pred->next = current->next;
			}

			//unlock both nodes if locked
			if(current!=nullptr){
				current->m.unlock();
			}
			if(pred!=nullptr){
				pred->m.unlock();
			}
			delete current;
		}

		/* count elements with value v in the list */
		std::size_t count(T v) {
			std::size_t cnt = 0;
			/* first go to value v */
			node<T>* current = first;
			node<T>* temp = nullptr;
			if(first!=nullptr){
				current->m.lock();
			}else{
				return 0;
			}
			while(current != nullptr && current->value < v) {
				temp=current;
				current = current->next;
				if(current!=nullptr){
				   current->m.lock();
				}
				temp->m.unlock();
			}
			/* count elements */
			while(current != nullptr && current->value == v) {
				cnt++;
				temp=current;
				current = current->next;
				if(current!=nullptr){
				   current->m.lock();
				}
				temp->m.unlock();
			}
			if(current!=nullptr){
				current->m.unlock();
			}
			
			return cnt;
		}
};

#endif // lacpp_sorted_list_hpp
