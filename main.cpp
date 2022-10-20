#include <iostream>

using namespace std;

int main() {
  int array_length;
  cin >> array_length;
  int* int_array = new int[array_length + 1];
  for (int i = 0; i < array_length; i++) {
    cin >> int_array[i];
  }
  cout << "\n";
  int begin = 0;
  int end = array_length - 1;
  int mid = (begin + end) / 2;
  while (int_array[begin] > int_array[end]) {
    if (begin == mid) {
      begin = end;
    } else if (int_array[end] < int_array[mid]) {
      begin = mid;
    } else {
      end = mid;
    }
    mid = (begin + end) / 2;
  }
  cout << begin << endl;
  delete[](int_array);
  return 0;
}
