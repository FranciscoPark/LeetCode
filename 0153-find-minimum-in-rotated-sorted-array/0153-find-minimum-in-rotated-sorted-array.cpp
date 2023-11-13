class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        int low= 0;
        int high =n-1;
        int result =5001;
        while(low<high){
            int mid = low + (high -low)/2;
            if(nums[mid]<nums[high]&&nums[low]>nums[mid]){
                result = min(result, nums[mid]);
                low ++;
                high --;
            }
            else if(nums[high]<nums[low]){
                low = mid+1 ;
                result = min(nums[high],result);
                result = min(nums[mid],result);
            }
            else{
                high = mid-1;
                result = min(nums[low],result);
                result = min(nums[mid],result);
            }
        }
        return result;
    }
};