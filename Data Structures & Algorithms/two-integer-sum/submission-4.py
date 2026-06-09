class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = dict()
        for i in range(len(nums)):
            num_dict[nums[i]] = i

        for i, x in enumerate(nums):
            if target - x in num_dict and num_dict[target - x] != i:
                return [i, num_dict[target - x]]
        return []