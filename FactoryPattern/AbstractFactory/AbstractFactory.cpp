#include <random>
#include <unordered_map>
#include <vector>
// 抽象工厂模式只要用于一种对象生成器来使用，创建的是同一个产品的不同系列
// 工厂方法模式的核心不在于创建对象，而是在于之前代码中调用的onboard函数
class Employee
{
public:
    virtual ~Employee() {}
    virtual int RegisterAccount() const = 0;
};

class Project
{
public:
    virtual ~Project() {}
    virtual void AssignTo(int) const = 0; // 将项目转派给指定id的员工
};

class Programmer : public Employee
{
public:
    virtual int RegisterAccount() const override
    {
        int accountNo = rand();
    }
};

class Designer : public Employee
{
public:
    virtual int RegisterAccount() const override
    {
        int accountNo = rand();
    }
};

class Department
{
public:
    virtual ~Department() {}
    virtual Employee *createEmployee() const = 0;
    virtual Project *createProject() const = 0;
};

class ITDepartment : public Department
{
public:
    virtual Employee *createEmployee() const override
    {
        return new Programmer;
    }

    virtual Project *createProject() const override
    {
        return new ITProject;
    }
};

class ITProject : public Project
{
public:
    virtual void AssignTo(int accoutNo) const override
    {
    }
};

// 类似于OnBoard函数
// 类内部需要所有的基础对象，将会全部交由抽象工厂对象负责创建
class DepartmentManager
{
public:
    const Department &department;
    std::vector<Project *> projects;
    std::unordered_map<int, Employee *> employees;
    // 在构造时接受一个抽象工厂对象，作为对象生成器
    explicit DepartmentManager(const Department &department) : department(department) {}
    auto createProject()
    {
        const auto project = department.createProject();
        projects.push_back(project);
        return project;
    }

    int createEmployee()
    {
        const auto employee = department.createEmployee();
        const auto accountNo = employee->RegisterAccount();
        employees[accountNo] = employee;
        return accountNo;
    }
};

int main()
{
    ITDepartment iTDepartment;
    DepartmentManager iTDepartmentManager{iTDepartment};
    const auto project = iTDepartmentManager.createProject();
    const auto accountNo = iTDepartmentManager.createEmployee();
    project->AssignTo(accountNo);
    return 0;
}