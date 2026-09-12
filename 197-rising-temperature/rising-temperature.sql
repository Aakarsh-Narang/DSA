# Write your MySQL query statement below
SELECT today.id 
FROM weather today
JOIN weather yesterday
ON DATEDIFF(today.recordDate, yesterday.recordDate) = 1
WHERE today.temperature > yesterday.temperature