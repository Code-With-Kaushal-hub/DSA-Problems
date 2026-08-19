class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        l=len(s)-1
        count=0
        while(l>=0):
            if(s[l]==" "):
                break
            count+=1
            l=l-1
        return count