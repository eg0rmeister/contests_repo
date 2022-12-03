#include <iostream>
#include <optional>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::uint64_t;

uint64_t max_val = 1073741824ull;

template <typename T>
class HeapMax {
 public:
  void Insert(T value);
  std::optional<T> ExtractMax();
  std::optional<T> GetMax();

  size_t Size() const { return size_; }
 private:
  std::vector<T> heap_;
  size_t size_ = 0;
  void SiftDown(size_t index);
  void SiftUp(size_t index);
};

template <typename T>
void HeapMax<T>::Insert(T value) {
  heap_.push_back(value);
  SiftUp(size_);
  size_++;
}

template <typename T>
std::optional<T> HeapMax<T>::ExtractMax() {
  if (size_ == 0) {
    return std::nullopt;
  }
  size_--;
  std::swap(heap_[0], heap_[size_]);
  T ret = heap_.back();
  heap_.pop_back();
  SiftDown(0);
  return std::optional<T>(ret);
}

template <typename T>
std::optional<T> HeapMax<T>::GetMax() {
  if (size_ == 0) {
    return std::nullopt;
  }
  return heap_[0];
}

template <typename T>
void HeapMax<T>::SiftDown(size_t index) {
  size_t to_swap_index = index;
  if (2 * index + 1 < size_ && heap_[2 * index + 1] > heap_[to_swap_index]) {
    to_swap_index = 2 * index + 1;
  }
  if (2 * index + 2 < size_ && heap_[2 * index + 2] > heap_[to_swap_index]) {
    to_swap_index = 2 * index + 2;
  }
  if (to_swap_index == index) {
    return;
  }
  std::swap(heap_[index], heap_[to_swap_index]);
  SiftDown(to_swap_index);
}

template <typename T>
void HeapMax<T>::SiftUp(size_t index) {
  if (index == 0) {
    return;
  }
  if (heap_[(index - 1) / 2] < heap_[index]) {
    std::swap(heap_[index], heap_[(index - 1) / 2]);
    SiftUp((index - 1) / 2);
  }
}

void HandleNextValue(uint64_t& curr, uint64_t x, uint64_t y, size_t to_out_amount,
                 HeapMax<uint64_t>& heap) {
  curr = (x * curr + y) % (max_val);
  if (heap.Size() >= to_out_amount) {
    if (heap.GetMax() > curr) {
      heap.ExtractMax();
      heap.Insert(curr);
    }
  } else {
    heap.Insert(curr);
  }
}

void PrintReversedAns(HeapMax<uint64_t> heap) {
  std::stack<uint64_t> out;
  while (heap.Size() != 0) {
    out.push(heap.ExtractMax().value());
  }
  while (!out.empty()) {
    cout << out.top() << " ";
    out.pop();
  }
  cout << "\n";
}

int main() {
  HeapMax<uint64_t> heap;
  size_t size_of_sequence;
  size_t to_out_amount;
  uint64_t a0;
  uint64_t x;
  uint64_t y;
  cin >> size_of_sequence >> to_out_amount >> a0 >> x >> y;
  uint64_t curr = a0;
  for (uint64_t i = 0; i < size_of_sequence; ++i) {
    HandleNextValue(curr, x, y, to_out_amount, heap);
  }
  PrintReversedAns(heap);
  return 0;
}
