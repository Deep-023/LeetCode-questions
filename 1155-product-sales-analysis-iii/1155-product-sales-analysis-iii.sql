# Write your MySQL query statement below
#Select product_id,first_year,quantity,price(distinct product_id) from Sales;

SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) in (
    SELECT product_id, MIN(year) 
    FROM Sales
    GROUP BY product_id
)