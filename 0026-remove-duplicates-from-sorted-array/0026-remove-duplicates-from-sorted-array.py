class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j=0
        for i in range(0,len(nums)-1):
            if(nums[i]!=nums[i+1]):
                j=j+1
                nums[j]=nums[i+1]
        return j+1
        

