#include "LinkedList.hpp"

#include <stdexcept>

Node::Node() : value_(0), next_(nullptr) {
}

Node::Node(const int value) : value_(value), next_(nullptr) {
}

Node::~Node() {
    value_ = 0;
    next_ = nullptr;
}

void Node::SetValue(const int value) {
    value_ = value;
}

void Node::SetNext(Node* node) {
    next_ = node;
}

int Node::GetValue() {
    return value_;
}

Node* Node::GetNext() {
    return next_;
}

LinkedList::LinkedList() : begin_(nullptr), end_(nullptr) {
}

LinkedList::LinkedList(Node* node) : begin_(node), end_(node) {
}

LinkedList::LinkedList(const LinkedList& other) : begin_(nullptr), end_(nullptr) {
    if (other.begin_ == nullptr) {
        throw std::runtime_error("Invalid linked list for constructor");
    }

    Node* current = other.begin_;
    while (current != nullptr) {
        this->PushBack(current->GetValue());
        current = current->GetNext();
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }

    this->~LinkedList();

    Node* current = other.begin_;
    while (current != nullptr) {
        this->PushBack(current->GetValue());
        current = current->GetNext();
    }

    return *this;
}

LinkedList::LinkedList(LinkedList&& other) noexcept : begin_(other.GetBegin()), end_(other.GetEnd()) {
    other.begin_ = nullptr;
    other.end_ = nullptr;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (begin_ != nullptr) {
        this->~LinkedList();
    }

    if (this == &other) {
        return *this;
    }

    begin_ = other.GetBegin();
    end_ = other.GetEnd();

    other.begin_ = nullptr;
    other.end_ = nullptr;

    return *this;
}

LinkedList::~LinkedList() {
    Node* current = begin_;

    while (current != nullptr) {
        Node* temp = current;
        current = current->GetNext();

        delete temp;
    }
}

Node* LinkedList::GetBegin() {
    return begin_;
}

Node* LinkedList::GetEnd() {
    return end_;
}

void LinkedList::PushBack(const int value) {
    if (begin_ == nullptr) {
        Node* node = new Node(value);
        begin_ = node;
        end_ = node;

        return;
    }

    Node* node = new Node(value);
    end_->SetNext(node);
    end_ = node;
}

void LinkedList::Insert(const int value, const size_t position) {
    if (begin_ == nullptr && position > 0) {
        throw std::runtime_error("Invalid position for insertion");
    }

    Node* node = new Node(value);

    if (begin_ == nullptr) {
        begin_ = node;

        if (end_ == nullptr) {
            end_ = node;
        }

        return;
    }

    if (position == 0) {
        node->SetNext(begin_);
        begin_ = node;

        if (end_ == nullptr) {
            end_ = node;
        }

        return;
    }

    Node* current = begin_;
    for (size_t i = 0; i < position - 1; ++i) {
        current = current->GetNext();

        if (current == nullptr) {
            throw std::runtime_error("Invalid position for insertion");
        }
    }

    node->SetNext(current->GetNext());
    current->SetNext(node);
}

void LinkedList::Replace(const int value, const size_t position) {
    if (begin_ == nullptr) {
        throw std::runtime_error("Invalid linked list for replacement");
    }

    if (position == 0) {
        begin_->SetValue(value);

        return;
    }

    Node* current = begin_;
    for (size_t i = 0; i < position; ++i) {
        current = current->GetNext();

        if (current == nullptr) {
            throw std::runtime_error("Invalid position for replacement");
        }
    }

    current->SetValue(value);
}

void LinkedList::Delete(const size_t position) {
    if (begin_ == nullptr) {
        throw std::runtime_error("Invalid linked list for deleting an element");
    }

    if (position == 0) {
        Node* temp = begin_;
        begin_ = begin_->GetNext();

        delete temp;
        temp = nullptr;

        return;
    }

    Node* current = begin_;
    for (size_t i = 0; i < position - 1; ++i) {
        current = current->GetNext();

        if (current == nullptr) {
            throw std::runtime_error("Invalid position for deleting an element");
        }
    }

    if (current->GetNext()->GetNext() == nullptr) {
        delete current->GetNext();
        current->SetNext(nullptr);

        end_ = current;

        return;
    }

    Node* temp = current->GetNext();

    current->SetNext(current->GetNext()->GetNext());

    delete temp;
    temp = nullptr;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* current = list.begin_;

    while (current != nullptr) {
        os << current->GetValue() << ' ';
        current = current->GetNext();
    }

    return os;
}
