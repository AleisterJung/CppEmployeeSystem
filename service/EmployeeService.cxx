#include "EmployeeService.hxx"
 
#include <optional>
#include <vector>
 


EmployeeService::EmployeeService(pqxx::connection& conn):db(conn){}

 

void EmployeeService::addEmployee(const Employee& Employee) 
{
    pqxx::work txn(db);
    pqxx::params p{
       
    Employee.getName(),
    Employee.getDepartment(),
    Employee.getPosition(),
    Employee.getSalary(),
    Employee.getHireDate()
    };
    txn.exec("INSERT INTO employee (name, department, position, salary, hire_date)"
    " VALUES ($1, $2, $3, $4, $5)",p);  
    
    txn.commit(); 
}

std::vector<Employee> EmployeeService::getAllEmployee()
{
    std::vector<Employee> employee;

    pqxx::work txn(db);

    pqxx::result result = txn.exec("SELECT id, name, department, position, salary, hire_date FROM employee");
    
    std::vector<Employee> list;

    list.reserve(result.size());

    for(const auto& row :result)
    {
        list.emplace_back(
            row[0].as<int>(),
            row[1].as<std::string>(),
            row[2].as<std::string>(),
            row[3].as<std::string>(),
            row[4].as<double>(),
            row[5].as<std::string>()
        );

    }

    return list;
}
std::optional<Employee> EmployeeService::getEmployeeById(int id) {
    pqxx::work txn(db);

    // 使用 exec(zview, params) 替代 exec_params
    pqxx::result res = txn.exec(

        "SELECT id, name, department, position, salary, hire_date FROM employee WHERE id = $1",
        pqxx::params{id}
    );

    if (!res.empty()) {
        const auto& row = res[0];
        return Employee{
            row[0].as<int>(),
            row[1].as<std::string>(),
            row[2].as<std::string>(),
            row[3].as<std::string>(),
            row[4].as<double>(),
            row[5].as<std::string>()
        };
    }
    return std::nullopt;
}
void EmployeeService::updateEmployee(const Employee& employee) {

    pqxx::work txn(db);

    pqxx::params p{
        employee.getName(),
        employee.getDepartment(),
        employee.getPosition(),
        employee.getSalary(),
        employee.getHireDate(),
        employee.getId()
    };
    txn.exec(
        "UPDATE employee SET name=$1, department=$2, position=$3, salary=$4, hire_date=$5 WHERE id=$6",
        p
    );
    txn.commit();
}

void EmployeeService::deleteEmployee(int id) noexcept
{

    pqxx::work txn(db);

    pqxx::params p{id};

    txn.exec("DELETE FROM employee WHERE id = $1", p);

    txn.commit();
}

