# Write your MySQL query statement below
Select max(num) as num from  
    (select num from MyNumbers group By num having count(num) = 1 )
As uniqueNum