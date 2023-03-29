class Solution {
public:
    int FindPivot(vector<int>arr,int N){
	int l = 0;
	int h = N-1;
	while(l <= h){
		int m = l + (h-l)/2;
		if(arr[m]<arr[N-1]){
			h = m - 1;
		} else {
			if(arr[m]>arr[m+1]){
				return m;
			} else{
				l = m + 1;
			}
		}
	}
	return -1;
    }
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        if (N == 1){
			if(target == nums[0]){
				return 0;
			} else{
				return -1;
			}
		}
		else{
		int Pivotele=FindPivot(nums,N);
		if(target <= nums[N-1]){
			int l = Pivotele+1;
			int h = N - 1;
			while(l<=h){
				//c=0;
				int m = l + (h-l)/2;
				if(nums[m] == target){
					return m;
				}
				else if(nums[m] < target){
					l = m+1;
				} else {
					h = m-1;
				}
			}
			return -1;

		} else{
			int l = 0;
			int h = Pivotele;
			while(l<=h){
				//c=0;
				int m = l + (h-l)/2;
				if(nums[m] == target){
					return m;
				}
				if(nums[m] < target){
					l = m+1;
				} else {
					h = m-1;
				}
			}
            return -1;
		}
	}
        return 0;
	}
};
