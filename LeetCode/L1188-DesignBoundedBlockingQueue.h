#include <mutex>
#include <condition_variable>
#include <deque>
using namespace std;
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        _capacity = capacity;
    }

    void enqueue(int element) {
        unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [this] {
            return !isFull();
            });
        msg.push_back(element);
        _cond.notify_one();
    }

    int dequeue() {
        unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [this] {
            return !isEmpty();
            });
        int ret = msg.front();
        msg.pop_front();
        _cond.notify_one();
        return ret;
    }

    bool isEmpty() {
        return msg.size() == 0;
    }

    bool isFull() {
        return msg.size() == _capacity;
    }

    int size() {
        return msg.size();
    }
private:
    deque<int> msg;
    mutex _mutex;
    condition_variable _cond;
    int _capacity;
};