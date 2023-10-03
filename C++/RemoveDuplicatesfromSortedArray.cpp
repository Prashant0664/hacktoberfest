
// leetcode-https://leetcode.com/problems/remove-duplicates-from-sorted-array/description

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

// function to print array
void printArray(vector<int> &num,int n)
{
    for (int i=0;i<n;i++)
    {
        cout << num[i] << " ";
    }
}

// Driver program to test above functions
int main()
{
    vector<int> arr{0,0,1,1,1,2,2,3,3,4};
    int n = removeDuplicates(arr);
    cout << "New array:"<<n<<"\n";
    printArray(arr,n);
    return 0;
}
