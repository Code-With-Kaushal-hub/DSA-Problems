class Solution:
    def average(self, salary: List[int]) -> float:
        mi=min(salary)
        mx=max(salary)
        sum=0
        c=0
        for i in salary:
            if(i!=mi and i!=mx):
                sum+=i
                c+=1
        return sum/c