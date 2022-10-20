#include <iostream>

using namespace std;

bool BinarySearch(const int* begin, const int* end, int target) {
  const int* mid = (begin + (end - begin) / 2);
  if (mid != begin) {
    if (target >= *mid && target <= *end) {
      return BinarySearch(mid, end, target);
    }
    if (target >= *begin && target <= *mid) {
      return BinarySearch(begin, mid, target);
    }
    return false;
  }
  return *mid == target;
}

int main() {
  int array_length;
  cin >> array_length;
  int* int_array = new int[array_length + 1];
  for (int i = 0; i < array_length; i++) {
    cin >> int_array[i];
  }
  int_array[array_length] = int_array[array_length - 1];
  int queries_amount;
  cin >> queries_amount;
  int query[3];
  for (int i = 0; i < queries_amount; i++) {
    cin >> query[0] >> query[1] >> query[2];
    if (query[1] >= array_length) {
      query[1] = array_length;
    }
    if (BinarySearch(&int_array[query[0]], &int_array[query[1]], query[2])) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  delete[](int_array);
  return 0;
}
