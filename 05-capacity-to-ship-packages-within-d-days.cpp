// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// n(sum of weights) * log(n) (max of weights) time complexity
class Solution {
public:
    bool isPossible(vector<int>weights,int mid,int days){
         int cur = 0, requiredDays = 1;
          for (int weight : weights) {
              
                if (cur + weight > mid) {  
                    cur = 0;
                    requiredDays++;
                }
                cur += weight;  
            }
      return  requiredDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());  
        int right = accumulate(weights.begin(), weights.end(), 0); 
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (isPossible(weights,mid,days)) {  
                right = mid-1;
            } else { 
                left = mid + 1;
            }
        }
        return left;  
    }
  
};