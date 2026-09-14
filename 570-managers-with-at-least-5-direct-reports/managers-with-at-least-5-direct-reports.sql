# Write your MySQL query statement below
SELECT m.name as name
FROM employee e
JOIN employee m
ON e.managerId = m.id
GROUP BY m.id, m.name
HAVING COUNT(m.id) >= 5