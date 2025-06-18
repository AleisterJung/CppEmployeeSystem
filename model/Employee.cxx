#include "Employee.hxx"

Employee::Employee(int id , 
    const std::string& name ,
    const std::string& department,
    const std::string& position,
    double salary,
    const std::string& hire_date):
    id(id),
    name(name),
    department(department),
    position(position),
    salary(salary),
    hire_date(hire_date){}   
    


int Employee::getId() const {return id;}

void Employee::setId(int id){this -> id = id ;}


const std::string& Employee::getName() const {return  name;}

void Employee::setName(const std::string& name){ this ->name = name;}


const std::string& Employee::getDepartment() const {return department;}

void Employee::setDepartment(const std::string& department){this ->department = department;} 


const std::string& Employee::getPosition()const {return  position;}
void Employee::setPosition(const std::string& position){this ->position = position;}

double Employee::getSalary()const { return salary;}
void Employee::setSalary( double salary){ this -> salary = salary;}


const std::string& Employee::getHireDate() const {return hire_date; }
void Employee::setHireData(const std::string& hire_data){ this ->hire_date = hire_data;}
 
 
