//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low=0;
        int col=matrix[0].size();
        int high=col*matrix.size()-1;
        
        while(low<=high){
            int mid =low+ (high-low)/2;
            int rowIdx=mid/col;
            int colIdx=mid%col;
            if(matrix[rowIdx][colIdx]==target)
                return true;
            if(matrix[rowIdx][colIdx]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};