class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sum=0
        mul=1
        while(n!=0):
            rem=n%10
            sum=sum+rem
            mul=mul*rem
            n=n//10
        return mul-sum