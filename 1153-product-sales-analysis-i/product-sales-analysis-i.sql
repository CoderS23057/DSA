# Write your MySQL query statement below
select p.product_name, s.year, s. price
from  Sales s right join Product p on
p.product_id = s.product_id
WHERE s.product_id IS NOT NULL;
