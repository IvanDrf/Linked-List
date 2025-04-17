#pragma once

#include <cstddef>
#include <iostream>

// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class Node {
 private:
    int value_;
    Node* next_;

 public:
    Node();
    explicit Node(const int value);

    ~Node();

    void SetValue(const int value);
    void SetNext(Node* node);

    int GetValue();
    Node* GetNext();
};

class LinkedList {
 private:
    Node* begin_;
    Node* end_;

 public:
    LinkedList();
    explicit LinkedList(Node* node);

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(LinkedList&& other) noexcept;

    ~LinkedList();

    Node* GetBegin();
    Node* GetEnd();

    void PushBack(const int value);
    void Insert(const int value, const size_t position);

    void Replace(const int value, const size_t position);
    void Delete(const size_t position);

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};
