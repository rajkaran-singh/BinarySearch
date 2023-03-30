# 162. Find Peak Element

from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return 0 if nums[0]>nums[1] else 1

        low = 0 
        high = len(nums) - 1
        
        def isPeak(ind):
            if ind == 0:
                if nums[ind+1] < nums[ind]:
                    return True
                else:
                    return False
            elif ind == len(nums) - 1:
                if nums[ind-1] < nums[ind]:
                    return True
                else:
                    return False
            else:
                if nums[ind] > nums[ind-1] and nums[ind] > nums[ind+1]:
                    return True
                else:
                    return False

        while low<=high:
            mid = (low + high)//2

            print(mid)
            if isPeak(mid):
                return mid
            else:
                if nums[mid + 1] > nums[mid]:
                    low = mid + 1
                else:
                    high = mid - 1
        return 0
    

# ------------------------------------------------------------------------------------------------------------
# Better approach

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        low = 0 
        high = len(nums) - 1

        while low<=high:
            mid = (low + high)//2

            if (mid == low or nums[mid] > nums[mid-1]) and (mid == high or nums[mid]>nums[mid + 1]):
                return mid
            else:
                if nums[mid + 1] > nums[mid]:
                    low = mid + 1
                else:
                    high = mid - 1
        return 0