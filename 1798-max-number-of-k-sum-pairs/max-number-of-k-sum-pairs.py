class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        i = 0
        j = len(nums) - 1
        max = 0
        
        while i < j:
            if (nums[i] + nums[j] == k):
                max += 1
                i += 1
                j -= 1
            
            elif (nums[i] + nums[j] > k):
                j -= 1

            else:
                i += 1
        return max
                



        

        