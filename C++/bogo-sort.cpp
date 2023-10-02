#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

// Function to check if array is sorted
bool isSorted(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

// BogoSort function
void bogoSort(vector<int> &arr) {
  int iterations = 0;
  while (!isSorted(arr)) {
    iterations++;
    random_shuffle(arr.begin(), arr.end());
  }
  cout << "Iterations: " << iterations << endl;
}

int main() {
  vector<int> arr = {3, 2, 50, 1, 0, 4, 89, 9};

  auto start = high_resolution_clock::now();
  bogoSort(arr);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;

  return 0;
}
