class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l=0
        r=0
        sum=0
        mi= 10**9
        while(r<len(nums)):
            sum+=nums[r]
            if(sum>=target):
                while(l<r and sum-nums[l]>=target ):
                    if(mi>r-l+1):
                        mi=r-l+1
                    sum=sum-nums[l]
                    l+=1
                    
            if(mi>r-l+1 and sum >= target):
                mi=r-l+1
                        
            r+=1
            
        if mi == 10**9:
            return 0
        return mi