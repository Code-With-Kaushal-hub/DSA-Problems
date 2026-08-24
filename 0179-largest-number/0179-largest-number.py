from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        

        arr = [3, 30, 34, 5, 9]
        s=""
        def compare(a, b):
            if str(a) + str(b) > str(b) + str(a):
                return -1
            elif str(a) + str(b) < str(b) + str(a):
                return 1
            return 0

        nums.sort(key=cmp_to_key(compare))

        for i in nums:
             s=s+str(i)
        if s[0]=="0":
            return "0"
        return s