#include <iostream>
#include <vector>
using namespace std;

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int middle, int right) {
    // Calculate the sizes of the two subarrays
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to hold the data of the two subarrays
    vector<int> leftSubarray(n1);
    vector<int> rightSubarray(n2);

    // Copy data from the main array to the temporary left and right subarrays
    for (int i = 0; i < n1; i++) {
        leftSubarray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightSubarray[j] = arr[middle + 1 + j];
    }

    // Merge the two subarrays back into the main array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            arr[k] = leftSubarray[i];
            i++;
        } else {
            arr[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left and right subarrays, if any
    while (i < n1) {
        arr[k] = leftSubarray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two subarrays
        int middle = left + (right - left) / 2;

        // Recursively sort the left and right subarrays
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, middle, right);
    }
}

int main() {
    // Input array
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    // Calculate the size of the array
    int arrSize = arr.size();

    // Call Merge Sort function
    mergeSort(arr, 0, arrSize - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
