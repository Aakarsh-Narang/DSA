# Write your MySQL query statement below
select customer_id, COUNT(customer_id) as count_no_trans
from visits v
LEFT JOIN transactions t
ON v.visit_id = t.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id