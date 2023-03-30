# 81. Search in Rotated Sorted Array II

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        low = 0
        high = len(nums) - 1

        while(low<=high):
            mid = (high + low) // 2
            if nums[mid] == target:
                return True

            if nums[mid] == nums[low] and nums[mid] == nums[high]:
                low += 1

            elif nums[low]<=nums[mid]:
                if(target>= nums[low] and target<nums[mid]):
                    high = mid - 1
                else:
                    low = mid + 1

                
            else:
                if target>nums[mid] and target<=nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1

                
        return False