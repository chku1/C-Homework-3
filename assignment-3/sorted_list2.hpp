#ifndef lacpp_sorted_list2_hpp
#define lacpp_sorted_list2_hpp lacpp_sorted_list2_hpp
#include <mutex>

/* a sorted list implementation by David Klaftenegger, 2015
 * please report bugs or suggest improvements to david.klaftenegger@it.uu.se
 */

/* struct for list nodes */
template<typename T>
struct node2 {
	T value;
	node2<T>* next;
};

/* non-concurrent sorted singly-linked list */
template<typename T>
class sorted_list_coarse {
	node2<T>* first = nullptr;

	//make one mutex for coarse-grained locking
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
		sorted_list_coarse() = default;
		sorted_list_coarse(const sorted_list_coarse<T>& other) = default;
		sorted_list_coarse(sorted_list_coarse<T>&& other) = default;
		sorted_list_coarse<T>& operator=(const sorted_list_coarse<T>& other) = default;
		sorted_list_coarse<T>& operator=(sorted_list_coarse<T>&& other) = default;
		~sorted_list_coarse() {
			while(first != nullptr) {
				remove(first->value);
			}
		}
		/* insert v into the list */
		void insert(T v) {
			//write lock guard in the beginning of every function
			//which will lock the mutex and unlock it after leaving
			//the function.
			std::lock_guard<std::mutex> lock(mtx);
			/* first find position */
			node2<T>* pred = nullptr;
			node2<T>* succ = first;
			
			while(succ != nullptr && succ->value < v) {
				pred = succ;
				succ = succ->next;
			}
			
			/* construct new node */
			node2<T>* current = new node2<T>();
			current->value = v;

			/* insert new node between pred and succ */
			current->next = succ;
			if(pred == nullptr) {
				first = current;
				
			} else {
				pred->next = current;
			}	
			
		}

		void remove(T v) {
			//same lock guard should be done here.
			std::lock_guard<std::mutex> lock(mtx);
			/* first find position */
			node2<T>* pred = nullptr;
			node2<T>* current = first;
			
			while(current != nullptr && current->value < v) {
				pred = current;
				current = current->next;
			}

			if(current == nullptr || current->value != v) {
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
			
			delete current;
		}

		/* count elements with value v in the list */
		std::size_t count(T v) {
			//same lock guard should be done here.
			std::lock_guard<std::mutex> lock(mtx);
			std::size_t cnt = 0;
			/* first go to value v */
			node2<T>* current = first;
			while(current != nullptr && current->value < v) {
				current = current->next;
			}
			/* count elements */
			while(current != nullptr && current->value == v) {
				cnt++;
				current = current->next;
			}
			
			return cnt;
		}
};

#endif // lacpp_sorted_list_hpp