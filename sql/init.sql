CREATE TABLE employee
{
    id SERIAL PRIMARY KEY;
    name TEXT NOT NULL;
    department TEXT ; --所属部门
    position  TEXT; --职务
    salary NUMERIC;
    hire_data DATE;

};