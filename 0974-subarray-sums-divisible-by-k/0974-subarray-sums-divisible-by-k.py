class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count=0
        length=len(nums)
        d={0:1}
        for i in range(1,length):
            nums[i]=nums[i]+nums[i-1]
        for i in range (length):
            nums[i]=nums[i]%k    
        for i in range(length):
            extra=nums[i]-0
            if extra in d:
                count+=d[extra]
            if nums[i]in d:
                d[nums[i]]+=1
            else:
                d[nums[i]]=1
        return count                


