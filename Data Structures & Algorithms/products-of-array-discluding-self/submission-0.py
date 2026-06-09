# https://neetcode.io/problems/products-of-array-discluding-self/question?list=neetcode150
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arrayLeft = []
        arrayRight = []

        for i in range(len(nums)):
            if i == 0:
                arrayLeft.append(nums[i])
            else:
                arrayLeft.append(nums[i] * arrayLeft[i - 1])

        for i in range(len(nums)):
            ir = (len(nums) - 1) - i
            if i == 0:
                arrayRight.append(nums[ir])
            else:
                arrayRight.append(nums[ir] * arrayRight[i - 1])

        return_list = []
        for i in range(len(nums)):
            if i == 0:
                return_list.append(arrayRight[len(nums) - 2])
            elif i == len(nums) - 1:
                return_list.append(arrayLeft[len(nums) - 2])
            else:
                return_list.append(
                    arrayLeft[i - 1] * arrayRight[(len(nums) - 1) - (i + 1)]
                )
        return return_list
