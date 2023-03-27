#include <iostream>
#include <unordered_map>

struct DLList {
  DLList(int key, int value)
      : _key(key), _value(value), _next(nullptr), _prev(nullptr) {}
  const int _key;
  const int _value;

  DLList* _next;
  DLList* _prev;
};

class LRUCache {
 private:
  int _max_capacity;
  DLList* _head;  // least used element
  DLList* _tail;  // most recent used element
  std::unordered_map<int, DLList*> _cache;

  void remove(int key, DLList* p) {
    if (p == nullptr || _cache.find(key) == _cache.end())
      return;

    if (_head == p && _tail == p) {  // single element in cache
      _head = nullptr;
      _tail = nullptr;
    } else if (p == _head) {  // p is the head with 2 or more elements
      _head = _head->_next;
    } else if (p == _tail) {  // p is tail with 2 or more elements
      _tail = _tail->_prev;
      _tail->_next = nullptr;
    } else if (p->_prev != nullptr &&
               p->_next != nullptr) {  // p is in the middle of the list
      p->_prev->_next = p->_next;
      p->_next->_prev = p->_prev;
    }

    p->_next = nullptr;
    p->_prev = nullptr;

    _cache.erase(key);
  }

  void append(int key, DLList* p) {
    if (_head == nullptr && _tail == nullptr) {
      _head = p;
      _tail = p;
      p->_prev = nullptr;
      p->_next = nullptr;
    } else {
      _tail->_next = p;
      p->_prev = _tail;
      p->_next = nullptr;
      _tail = _tail->_next;
    }

    _cache[key] = p;
  }

 public:
  explicit LRUCache(int capacity)
      : _max_capacity(capacity), _head(nullptr), _tail(nullptr) {}

  int get(int key) {
    if (_cache.find(key) == _cache.end()) {
      return -1;
    }

    auto p = _cache[key];
    remove(key, p);
    append(key, p);

    return p->_value;
  }

  void put(int key, int value) {
    if (_cache.find(key) != _cache.end()) {
      auto tmp = _cache[key];
      remove(key, _cache[key]);
      delete tmp;
    }

    auto p = new DLList(key, value);
    append(key, p);

    if (_cache.size() > _max_capacity) {
      auto tmp = _head;
      //      remove(_head->, _head);
      delete tmp;
    }
  }
};

int main(int argc, char* argv[]) {
  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);                         // cache is {1=1}
  lRUCache->put(2, 2);                         // cache is {1=1, 2=2}
  std::cout << lRUCache->get(1) << std::endl;  // return 1
  lRUCache->put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  std::cout << lRUCache->get(2) << std::endl;  // returns -1 (not found)
  lRUCache->put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  std::cout << lRUCache->get(1) << std::endl;  // return -1 (not found)
  std::cout << lRUCache->get(3) << std::endl;  // return 3
  std::cout << lRUCache->get(4) << std::endl;  // return 4

  return 0;
}
