SELECT Temp.email
FROM(SELECT COUNT(*), email
FROM Person 
GROUP BY email
HAVING COUNT(*) >= 2
) AS Temp;