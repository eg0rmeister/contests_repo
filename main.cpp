#include <iostream>

using namespace std;

int* BinarySearch(int* begin, int* end) {
  int* mid = begin + (end - begin) / 2;
  while (*begin > *end) {
    if (begin == mid) {
      begin = end;
    } else if (*end < *mid) {
      begin = mid;
    } else {
      end = mid;
    }
    mid = begin + (end - begin) / 2;
  }
  return begin;
}

void input_sequence(int* array) {
  size_t array_length;
  cin >> array_length;
  for (size_t i = 0; i < array_length; i++) {
    cin >> int_array[i];
  }
  cout << "\n";
}

int main() {
  int* int_array = new int[array_length + 1];
  input_sequence(int_array);
  int* result = BinarySearch(int_array, int_array + (array_length - 1));
  cout << result - int_array << endl;
  delete[](int_array);
  return 0;
}
