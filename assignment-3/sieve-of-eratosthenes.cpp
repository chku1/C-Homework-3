// TODO: implement Sieve of Eratosthenes
#include <vector>
#include <error.h>
#include <chrono>
#include <string.h>
#include <iostream>
#include <thread>
#include <mutex>

using std::vector;


//find whether the number is Prime
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

//make all not prime numbers in the array false
void notPrime(int start,int end,int num,bool * prime){
    int new_start=start;
    for(int j =2; j*j<num; j++){

        //if a number until square root of num is prime,
        //then any multiplication of this number will give us
        //not prime number, with for cycle will make all of those
        //numbers in the boolean array false. 
        if(prime[j]){
            //find new_start
            while(new_start%j!=0){
            new_start++;
            }
            for (int i = new_start; i <= end; i += j)
                prime[i] = false;
        }

        //give previous value to new_start
        new_start=start;
    }
}

int main(int argc, char * argv[]){

    if (argc < 2) error(1, 0,
                        "Missing argument. "
                        "Please supply the number up to which you want to find prime numbers.");
    //get ahold of the number                    
     int num = std::stoi(argv[1]);

    //create vector of threads
    std::vector<std::thread> threads;

    //create a boolean aray with all "true" values
    bool prime[1000009];
    memset(prime,true,sizeof(prime));

    int p=2;
    for(p =2; p*p<num; p++){
        //find prime numbers before square root of num
        prime[p]=isPrime(p);
    }
    
    //find chunks for 4 threads
    int chunk=((num-p)/4)+1;
    int end=p;

    for(int i=0;i<4;i++){
        //specify the start and end point of each chunk
        p=end;
        end=end+chunk;

        //start threads to make every not prime number in array false
        threads.emplace_back(std::thread(notPrime,p,end,num,prime));
    }

    for(std::thread &thread : threads){
        //wait for all the threads to finish before printing prime numbers
        thread.join();
    }

    
    for (int i = 2; i<num;i++){
        //print prime numbers
        if(prime[i]==true) std::cout<<i<<" ";
    }
}
