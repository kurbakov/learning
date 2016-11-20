#include "iostream"
#include "thread"

// Define number of threads
static const int N_THREADS = 4;

// test void function
void print(std::string msg){
    std::cout << msg << std::endl;
}

void run_in_single_thread(std::string msg){
    std::thread t1(print, msg);
    t1.join();
    return;
}

void run_parallel_print(std::string msg){
    // create the array of threads
    std::thread t[N_THREADS];

    // put to each element of an array some function
    for (int i = 0; i < N_THREADS; ++i)
        t[i] = std::thread(print, "a lot of threads are here!");

    // join all threads
    for (int i = 0; i < N_THREADS; ++i)
        t[i].join();

    return;
}

int main(){

    run_in_single_thread("one thread");
    run_parallel_print("many threads are here");

    return 0;
}
