class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Create a dictionary to store value to index mapping
        mapping = {}
        
        # In Python, we can combine the insertion and search 
        # into one loop for better efficiency
        for i, num in enumerate(nums):
            complement = target - num
            
            if complement in mapping:
                return [mapping[complement], i]
            
            mapping[num] = i
            
        return [0, 0]
