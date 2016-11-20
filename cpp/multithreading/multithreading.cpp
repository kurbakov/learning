#include "iostream"
#include "thread"
#include "vector"
#include "mutex"

// Define global variables
static const int N_THREADS = 4;
std::vector<int> VECTOR;
std::mutex my_mutex;

/*=================================================*/
// test print function
void print(std::string msg){
    std::cout << msg << std::endl;
}

void run_in_single_thread_print(std::string msg){
    std::thread t1(print, msg);
    t1.join();
    return;
}

void run_parallel_print(std::string msg){
    // create the array of threads
    std::thread t[N_THREADS];

    // put to each element of an array some function
    for (int i = 0; i < N_THREADS; ++i)
        t[i] = std::thread(print, msg);

    // join all threads
    for (int i = 0; i < N_THREADS; ++i)
        t[i].join();

    return;
}

/*=================================================*/
// test function with changing some element in vector
void compute(int i){
    std::lock_guard<std::mutex> guard(my_mutex);
    VECTOR[i] = VECTOR[i]*VECTOR[i] + 100;
}

void run_parallel_compute(){
    std::thread t[N_THREADS];
    for (int i = 0; i < N_THREADS; i++)
        t[i] = std::thread(compute, i);

    for (int i = 0; i < N_THREADS; i++)
        t[i].join();

    return;
}

int main(){

    run_in_single_thread_print("one thread");
    run_parallel_print("many threads are here");

    for(int i = 0; i<N_THREADS; i++)
        VECTOR.push_back(i);

    run_parallel_compute();

    for(int i = 0; i<N_THREADS; i++)
        std::cout << VECTOR[i] << " ";
    std::cout << std::endl;

    return 0;
}
