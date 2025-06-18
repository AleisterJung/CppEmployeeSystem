# CppEmployeeSystem

一个基于 C++ 和 PostgreSQL 的员工管理系统示例，使用 libpqxx 作为数据库连接库。

## 功能

- 添加员工
- 查询所有员工
- 根据 ID 查询员工
- 更新员工信息
- 删除员工

## 环境要求

- C++26 标准编译器（如 GCC 13+）
- PostgreSQL 数据库
- libpqxx（PostgreSQL C++ 客户端库）
- CMake 3.10 及以上

## 编译和运行

1. 克隆项目：

```bash
git clone https://github.com/你的用户名/CppEmployeeSystem.git
cd CppEmployeeSystem

    创建构建目录并编译：

mkdir build && cd build
cmake ..
make

    运行程序：

./CppEmployeeSystem

配置

数据库连接信息保存在项目根目录的 config.json 文件中，格式如下：

{
  "connection_string": "host=localhost port=5432 dbname=employees user=postgres password=你的密码"
}

请根据实际情况修改。
接口说明
1. 添加员工

void EmployeeService::addEmployee(const Employee& emp);

    参数：emp，一个包含员工信息的 Employee 对象。

    功能：向数据库中添加新的员工记录。

2. 查询所有员工

std::vector<Employee> EmployeeService::getAllEmployees();

    返回：包含所有员工对象的列表。

    功能：获取数据库中所有员工信息。

3. 根据 ID 查询员工

Employee EmployeeService::getEmployeeById(int id);

    参数：员工 ID。

    返回：对应 ID 的员工对象。

    功能：根据员工 ID 查询员工信息。

4. 更新员工信息

void EmployeeService::updateEmployee(const Employee& emp);

    参数：包含更新信息的 Employee 对象，必须包含有效的员工 ID。

    功能：更新员工的数据库记录。

5. 删除员工

void EmployeeService::deleteEmployee(int id);

    参数：员工 ID。

    功能：删除指定 ID 的员工记录。

许可证

本项目采用 BSD 2-Clause License 许可协议。

欢迎提交 issue 和 pull request！
