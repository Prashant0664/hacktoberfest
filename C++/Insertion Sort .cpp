#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Iterate through the array from the second element (index 1)
    for (int i = 1; i < n; i++) {
        // Select the current element to be inserted into the sorted part of the array
        int key = arr[i];
        int j = i - 1;

        // Move elements of the sorted part of the array that are greater than the key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the key at its correct position in the sorted part of the array
        arr[j + 1] = key;
    }
}

int main() {
    // Input array
    vector<int> arr = {12, 11, 13, 5, 6};

    // Call Insertion Sort function
    insertionSort(arr);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
