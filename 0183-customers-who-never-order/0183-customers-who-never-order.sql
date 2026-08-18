# Write your MySQL query statement below
SELECT E1.name as Customers FROM Customers E1 LEFT JOIN Orders E2 on E1.id=E2.customerID
WHERE E2.id IS NULL;