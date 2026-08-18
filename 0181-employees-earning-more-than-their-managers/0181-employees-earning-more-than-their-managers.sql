# Write your MySQL query statement below

SELECT E2.name as Employee FROM Employee E1 JOIN Employee E2 ON E1.id=E2.managerID WHERE E1.salary<E2.salary
