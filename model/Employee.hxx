#pragma once
#include <string>

class Employee 
{
private:
    int id = 0;
    std::string name;
    std::string department;
    std::string position;
    double salary = 0.0;
    std::string hire_date;

public:
    Employee() = default;
    Employee(int id , 
        const std::string& name ,
        const std::string& department,
        const std::string& position,
        double salary,
        const std::string& hire_date 
    ); 

    int getId() const;
    void setId(int  id);

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getDepartment() const;
    void setDepartment(const std::string& department);


    const std::string& getPosition() const;
    void setPosition(const std::string& position);

    double getSalary() const;
    void setSalary(double salary);

    const std::string& getHireDate() const;
    void setHireData(const std::string& HireDate);
    
};

 