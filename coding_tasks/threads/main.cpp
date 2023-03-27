#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void print_hello() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "hello from " << std::this_thread::get_id() << std::endl;
}

void accum(std::vector<int>& v, std::promise<int> accumulate_promise) {
  std::this_thread::sleep_for(std::chrono::seconds(5));

  int sum = 0;
  for (auto& el : v)
    sum += el;
  accumulate_promise.set_value(sum);  // Notify future
};

void run_threads(int count) {
  std::vector<std::thread> t;

  for (int i = 0; i < count; ++i)
    t.emplace_back(print_hello);

  for (int i = 0; i < count; ++i)
    t[i].join();
}

void run_async() {
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::promise<int> prom;

  std::future<int> fut = prom.get_future();
  std::thread t(accum, std::ref(nums), std::move(prom));

  std::cout << "hello from main thread" << std::endl;
  std::cout << "result is: " << fut.get() << std::endl;

  t.join();
}

template <typename T>
class SharedPtr {
 public:
  SharedPtr(T value) : _resource(new T{value}), _counter(new size_t{1}) {
    std::cout << "called the constructor (memory allocated)" << std::endl;
  }

  ~SharedPtr() {
    if (_counter == nullptr)
      return;

    std::cout << "called the destructor" << std::endl;

    --(*_counter);
    if (*_counter == 0) {
      delete _counter;
      _counter = nullptr;

      if (_resource != nullptr) {
        delete _resource;
        _resource = nullptr;
        std::cout << "free memory" << std::endl;
      }
    }
  }

  SharedPtr(SharedPtr& other) {  // copy
    std::cout << "called the copy constructor" << std::endl;
    _resource = other._resource;
    _counter = other._counter;
    ++(*_counter);
  }

  SharedPtr& operator=(SharedPtr& other) {  // copy assignment
    std::cout << "called the copy assignment constructor" << std::endl;
    _resource = other._resource;
    _counter = other._counter;

    return *this;
  }

  SharedPtr(SharedPtr&& other) {  // move
    std::cout << "called the move constructor" << std::endl;

    _resource = other._resource;
    _counter = other._counter;

    other._resource = nullptr;
    other._counter = nullptr;
  }

  T& operator*() { return *_resource; }
  T operator->() { return _resource; }

 private:
  T* _resource;
  size_t* _counter;
};

void shared_ptr() {
  SharedPtr<int> ptr{5};
  int v1 = *ptr;

  SharedPtr<int> copy(ptr);
  int v2 = *copy;

  SharedPtr<int> assign_copy = ptr;
  int v3 = *assign_copy;

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
}

int main(int argc, char* argv[]) {
  shared_ptr();

  return 0;
}
