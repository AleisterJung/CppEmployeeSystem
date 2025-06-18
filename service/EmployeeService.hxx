#pragma once
#include <vector>
#include <optional>
#include <pqxx/pqxx>
#include "../model/Employee.hxx"


class EmployeeService
{
public:
    explicit EmployeeService(pqxx::connection& conn);

    void addEmployee(const Employee& Employee);

    std::vector<Employee> getAllEmployee();
    std::optional<Employee> getEmployeeById(int id);

    void updateEmployee(const Employee& Employee);
    void deleteEmployee(int id) noexcept;

private:
    pqxx::connection& db;    
};