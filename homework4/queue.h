#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template<typename N>

struct Node {
    private:
        auto data;
        N* next;
    public:
        Node(auto data, N next = nullptr): data(data), next(nullptr) {};
        Node(auto data, N next): data(data), next(new N(data)) {};

    N* getNext() {
        return next;
    }
};

struct Queue {
    private:
        int size;
        N* head;
        N* tail;
    public:
        Queue(int size, N head= nullptr, N tail = nullptr) {};
        Queue& operator=(const Queue& other) = delete;

    int get_size() {
        return size;
    }

    void enqueue(auto data) {
        unique_ptr<Node> newNode(new Node(data, tail));
        unique_ptr<Node> tail(newNode);
        size++;
    }

    void dequeue(auto data) {
        if (size == 0) {
            throw underflow_error("Queue is empty :(");
        }

        unique_ptr<Node> newHead(head.getNext());
        unique_ptr<Node> head(getHead);

    }
};
