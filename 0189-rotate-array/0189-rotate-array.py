
class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        k = k % len(nums)

        l = nums[len(nums)-k:]
        r = nums[:len(nums)-k]

        nums[:] = l + r
        return nums