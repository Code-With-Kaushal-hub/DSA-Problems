from typing import List

class Solution:
    def check(self, nums: List[int]) -> bool:
        t = 0
        n = len(nums)

        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                t += 1

        return t <= 1