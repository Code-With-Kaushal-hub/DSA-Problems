# Write your MySQL query statement below
SELECT DISTINCT max(Salary) as SecondHighestSalary FROM Employee Where Salary<(
    SELECT max(Salary) FROM Employee 
)