class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n= matrix[0].size();
        int low =0;
        int high = n*m-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int x = mid / n ;
            int y = mid%n ;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]>target) high= mid-1;
            else low= mid+1;
        }
        return false;
        

    }
};