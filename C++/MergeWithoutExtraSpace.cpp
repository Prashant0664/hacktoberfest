#include<bits/stdc++.h>
using namespace std;
void merge(int arr1[], int l1, int arr2[], int l2) {
    int total_len=l1+l2;
    int merged_array[total_len];
    int pos = 0;
    for (int i = 0; i < l1; i++) {
      merged_array[pos++] = arr1[i];
    }
    for (int i = 0; i < l2; i++) {
      merged_array[pos++] = arr2[i];
    }
   
    sort(merged_array,merged_array+total_len);
    pos = 0;
    
    for (int i = 0; i < l1; i++) {
      arr1[i] = merged_array[pos++];
    }
    for (int i = 0; i < l2; i++) {
      arr2[i] = merged_array[pos++];
    }
  }
int main() {
    int n = 4;
    int nums1[4] = {2, 9, 11, 15};

    int m = 6;
    int nums2[6] = {-18, 1, 3, 7, 10, 12};

    cout<<"Original arrays:"<<endl;
    cout<<"nums1: "<<"\t";
    for (int i = 0; i < n; i++) {
      cout<<nums1[i]<<" ";
    }
    cout<<endl;
    cout<<"nums2: "<<"\t";
    for (int i = 0; i < m; i++) {
      cout<<nums2[i]<<" ";
    }
    cout<<endl;
    merge(nums1,  n, nums2, m);
    cout<<"Arrays after merging:"<<endl;
    cout<<"nums1: "<<"\t";
    for (int i = 0; i <n; i++) {
      cout<<nums1[i]<<" ";
    }
    cout<<endl;
    cout<<"nums2: "<<"\t";
    for (int i = 0; i < m; i++) {
      cout<<nums2[i]<<" ";
    }
}
