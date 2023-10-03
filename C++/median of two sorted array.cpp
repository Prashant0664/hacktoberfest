// https://leetcode.com/problems/median-of-two-sorted-arrays//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int l=0, r= m;
        int total = m+n+1;
        
        while(l<=r)
        {
            int fir = l + (r-l)/2;
            int sec = total/2 - fir;
            
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            
            if(fir > 0)
                l1 = nums1[fir-1];
            if(sec>0)
                l2 = nums2[sec-1];
            if((fir>=0) && (fir<m))
                r1 = nums1[fir];
            if((sec>=0) && (sec<n))
                r2 = nums2[sec];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2 == 0)
                    return (max(l1, l2)+min(r1, r2))/2.0;
                else
                    return max(l1, l2);
            }
            else if(l1> r2)
                r = fir-1;
            else
                l = fir+1;
        }     
        return 0;      
    }
};