class Solution:
    def isPalindrome(self, s: str) -> bool:
        p=""
        for i in s:
            if i>='A' and i<='Z':
                p=p+i
            elif i>='a'and i<='z':
                p=p+i
            elif i>='0'and i<='9':
                p=p+i
        p=p.lower()
        return p[:]==p[::-1]
        