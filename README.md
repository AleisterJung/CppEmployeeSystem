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
许可证

BSD 2-Clause License

欢迎提交 issue 和 pull request！