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

int main() {
  size_t array_length;
  cin >> array_length;
  int* int_array = new int[array_length + 1];
  for (size_t i = 0; i < array_length; i++) {
    cin >> int_array[i];
  }
  cout << "\n";
  int* result = BinarySearch(int_array, int_array + (array_length - 1));
  cout << result - int_array << endl;
  delete[](int_array);
  return 0;
}
