#include "db/database.hxx"
#include "model/Employee.hxx"
#include "service/EmployeeService.hxx"
#include <iostream>
#include <memory>
#include "utils/DbConfig.hxx"

int main(int argc , char *argv[]) {

  std::string connStr = loadDatabaseConnectionString("../config.json");
  std::unique_ptr<Database> db = std::make_unique<Database>(connStr);
   

  EmployeeService service(db->getConnection());

  
  Employee newEmp(0, "井文龙", "研发部", "技术总监", 22000.0, "2024-06-20");
  service.addEmployee(newEmp);
  std::cout << " 添加员工成功！" << std::endl;
 
 
 

  return 0;
}
