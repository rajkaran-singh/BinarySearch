#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r= nums.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            if(nums[mid]==target)   return true;
            while(l<mid && nums[l]==nums[mid])   l++;
            if(nums[l]<=nums[mid]){
                if(target<nums[mid] && target>=nums[l]) r=mid-1;
                else    l=mid+1;
            }

            else{
                if(target>nums[mid] && target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }

        return false;
    }
};