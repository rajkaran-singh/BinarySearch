// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int low=0;
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            
            if(nums[mid]==target) return true;
              else if (nums[low] == nums[mid] && nums[high] == nums[mid]) 
                low++, high--; 
            else if(nums[low]<=nums[mid]){
                
                if(nums[low]<=target and target<nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }else{
                if(nums[mid]<target and target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                
            }
            
        }
        return 0;
    }
};