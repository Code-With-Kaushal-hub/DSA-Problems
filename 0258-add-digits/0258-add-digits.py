class Solution:
    def addDigits(self, num: int) -> int:
        while(num>9):
            sum=0
            while(num!=0):
               rem=num%10
               sum=sum+rem
               num=num//10
            num=sum
        return num
        