class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = m+n;
        int low = 0;
        int high = m;

        double result =0.0;
        while(low<= high){
            int mid = low + (high -low)/2;
            int mid2 = (total + 1) / 2 - mid;

            int left1 = (mid > 0) ? nums1[mid - 1] : INT_MIN;
            int right1 = (mid < m) ? nums1[mid] : INT_MAX;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                // even
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                // odd
                } else {
                    result = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
        }
        return result;

        
    }
};