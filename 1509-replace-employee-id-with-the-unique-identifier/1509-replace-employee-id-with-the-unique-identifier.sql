SELECT EUNI.unique_id, E.name
FROM Employees AS E LEFT JOIN EmployeeUNI AS EUNI
ON EUNI.id = E.id;