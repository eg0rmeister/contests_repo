#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Node {
  int number;
  int minimal;
  Node* next_node;

  Node(int new_number, int new_min, Node* new_next_node) {
    number = new_number;
    minimal = new_min;
    next_node = new_next_node;
  }

  Node() {
    number = 0;
    minimal = 0;
  }

  ~Node(){};
};

class StackMin {
  Node* head_;
  int stack_size_;

 public:
  StackMin() {
    stack_size_ = 0;
    head_ = new Node();
  }

  ~StackMin() {
    Clear();
    delete head_;
  }

  void Push(int number) {
    if (stack_size_ == 0) {
      head_ = new Node(number, number, head_);
    } else {
      head_ = new Node(number, min(number, head_->minimal), head_);
    }
    stack_size_++;
  }

  int Pop() {
    if (stack_size_ == 0) {
      return 0;
    }
    stack_size_--;
    int ret = head_->number;
    Node* old_head = head_;
    head_ = old_head->next_node;
    delete old_head;
    return ret;
  }
  int Top() { return head_->number; }
  int Min() {
    if (stack_size_ != 0) {
      return head_->minimal;
    }
    return 0;
  }
  int Size() { return stack_size_; }
  void Clear() {
    while (stack_size_ != 0) {
      Pop();
    }
  }
};

class Deque {
  StackMin* in_stack_;
  StackMin* out_stack_;
  void Shift() {
    while (in_stack_->Size() != 0) {
      out_stack_->Push(in_stack_->Pop());
    }
  }

 public:
  Deque() {
    in_stack_ = new StackMin;
    out_stack_ = new StackMin;
  };
  ~Deque() {
    delete in_stack_;
    delete out_stack_;
  }

  void Push(int number) { in_stack_->Push(number); }

  int Pop() {
    if (out_stack_->Size() == 0) {
      Shift();
    }
    return out_stack_->Pop();
  }

  int Front() {
    if (out_stack_->Size() == 0) {
      Shift();
    }
    return out_stack_->Top();
  }

  int Size() { return out_stack_->Size() + in_stack_->Size(); }

  void Clear() {
    in_stack_->Clear();
    out_stack_->Clear();
  }

  int Min() {
    int in_min = in_stack_->Min();
    int out_min = out_stack_->Min();
    if (in_min == 0) {
      return out_min;
    }
    if (out_min == 0) {
      return in_min;
    }
    return min(out_min, in_min);
  }
};

void ConditionOut(int number) {
  if (number != 0) {
    cout << number << endl;
  } else {
    cout << "error" << endl;
  }
}

int main() {
  string command;
  int number_of_commands;
  int number;
  Deque deque;
  cin >> number_of_commands;
  for (int i = 0; i < number_of_commands; ++i) {
    cin >> command;
    if (command == "enqueue") {
      cin >> number;
      deque.Push(number);
      cout << "ok" << endl;
    } else if (command == "dequeue") {
      ConditionOut(deque.Pop());
    } else if (command == "front") {
      ConditionOut(deque.Front());
    } else if (command == "size") {
      cout << deque.Size() << endl;
    } else if (command == "clear") {
      deque.Clear();
      cout << "ok" << endl;
    } else if (command == "min") {
      ConditionOut(deque.Min());
    }
  }
  return 0;
}
