class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;
        int n = n1 + n2;
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        // Swap the arrays for this condition
        while (low <= high){
            int cut1 = (low + high)/2;  // cut1 for array1 or mid1
            int left = (n1 + n2 + 1)/2;
            int cut2 = left - cut1; // cut2 for array2 or mid2
            int l1 = INT_MIN, l2 = INT_MIN; // Two left pointers
            int r1 = INT_MAX, r2 = INT_MAX; // Two right pointers
            if (cut1-1 >= 0) l1 = nums1[cut1-1];
            if (cut2-1 >= 0) l2 = nums2[cut2-1];
            if (cut1 < n1) r1 = nums1[cut1];
            if (cut2 < n2) r2 = nums2[cut2];
            // Checking the cross condition
            if (l1 <= r2 && l2 <= r1){
                // odd condition
                if (n%2 == 1) return max(l1, l2);
                // even condition
                else return (double)((double)(max(l1, l2)) + (double)(min(r1, r2)))/2.0;
            }
            // eliminate the halves
            else if (l1 > r2) high = cut1 - 1;  // eliminate right half
            else low = cut1 + 1; // eliminate left half
        }
        return 0; // dummy statement

    }
};
