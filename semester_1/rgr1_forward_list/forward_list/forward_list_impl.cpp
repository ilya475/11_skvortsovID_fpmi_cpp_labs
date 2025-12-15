#include "forward_list_impl.h"

ForwardList::ForwardList() : head_(nullptr), size_(0) {
    std::cout << "Default constructor\n";
}
ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushFront(value);
    }
    Reverse();
}
ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(0) {
    for (int32_t value : init) {
        PushFront(value);
    }
    Reverse();
}
ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(0) {
    Node* current = rhs.head_;
    while (current != nullptr) {
        PushFront(current->value_);
        current = current->next_;
    }
    Reverse();
}
ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;
    }
    Clear();
    Node* current = rhs.head_;
    while (current != nullptr) {
        PushFront(current->value_);
        current = current->next_;
    }
    Reverse();
    return *this;
}
ForwardList::~ForwardList() {
    std::cout << "Distructor\n";
    Clear();
}
void ForwardList::PushFront(int32_t value) {
    Node* newNode = new Node(value);
    newNode->next_ = head_;
    head_ = newNode;
    ++size_;
}
void ForwardList::PopFront() {
    if (head_ == nullptr) {
        return;
    }
    Node* temp = head_;
    head_ = head_->next_;
    delete temp;
    --size_;
}
void ForwardList::Clear() {
    while (head_ != nullptr) {
        PopFront();
    }
}
bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}
void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current->value_;
        if (current->next_ != nullptr) {
            out << " ";
        }
        current = current->next_;
    }
}
size_t ForwardList::Size() const {
    return size_;
}
int32_t ForwardList::Front() const {
    if (head_ == nullptr) {
        throw std::out_of_range("List is empty, that is why we can not get value from it");
    }
    return head_->value_;
}
void ForwardList::Reverse() {
    Node* prev = nullptr;
    Node* current = head_;

    while (current != nullptr) {
        Node* next = current->next_;
        current->next_ = prev;
        prev = current;
        current = next;
    }
    head_ = prev;
}
void ForwardList::Remove(int32_t value) {
    while (head_ != nullptr && head_->value_ == value) {
        PopFront();
    }
    if (head_ == nullptr) {
        return;
    }
    Node* current = head_;
    while (current->next_ != nullptr) {
        if (current->next_->value_ == value) {
            Node* victim = current->next_;
            current->next_ = victim->next_;
            delete victim;
            --size_;
        } else {
            current = current->next_;
        }
    }
}
