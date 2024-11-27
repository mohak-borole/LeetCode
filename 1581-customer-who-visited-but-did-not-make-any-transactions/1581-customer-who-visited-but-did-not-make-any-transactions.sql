# Write your MySQL query statement below
SELECT v.customer_id , COUNT(v.visit_id) as count_no_trans
from Visits v LEFT JOIN Transactions t
on v.visit_id = t.visit_id
where t.transaction_id IS NULL GROUP BY v.customer_id;