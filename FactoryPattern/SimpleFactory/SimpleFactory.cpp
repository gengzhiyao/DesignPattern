#include <random>

// 创建方法特指将调用构造函数将对象创建方法进行包装

class Programmer
{
};

class Department
{
public:
    auto createEmployee()
    { // 封装Programmer类的创建细节：创建方法
        return new Programmer;
    }
    static auto staticCreateEmployee()
    { // 静态创建方法，返回可重用对象，相比普通创建方法，提供了额外的灵活性
        return new Programmer;
    }

    // 简单工厂：在构造函数中要求传参，能够根据参数的不同，创建不同的对象
    // 现在假设我们要增加Designer对象
    // 我们对Programmer类和Desiger类创建一个共同的父类:Employee 通过多态让create方法既能够返回Programmer对象，又能够返回Designer对象
};

class Employee
{
public:
    virtual ~Employee() {}
};

class Programmer1 : public Employee
{
};

class Designer1 : public Employee
{
};

enum class EmployeeType
{
    Programmer1,
    Designer1,
};

// 简单工厂模式：缺点：在将来如果需要增加其他员工，我们需要再次打开这个类，违背了开闭原则，由此引出工厂方法模式
class Department1
{
public:
    Employee *createEmployee(EmployeeType employeeType)
    {
        switch (employeeType)
        {
        case EmployeeType::Programmer1:
            return new Programmer1;
            break;
        case EmployeeType::Designer1:
            return new Designer1;
            break;
        default:
            break;
        }
    }
};

// 工厂方法模式的思想是将对象的创建过程下放到不同的子类工厂中，我们不会在仅有的Department1中创建不同类型的对象
// 相应的：我们让ITDepartment创建Programmer对象，让UIDepartment类创建UIDesigner对象，Department类作为父类，定义这两个子类工厂应该实现什么

class Department2
{
public:
    virtual ~Department2() {}
    virtual Employee *createEmployee() const = 0;
};

class ITDepartment2 : public Department2
{
public:
    virtual Employee *createEmployee() const override
    {
        return new Programmer1;
    }
};

class UIDepartment2 : public Department2
{
public:
    virtual Employee *createEmployee() const override
    {
        return new Designer1;
    }
};

class Employee1
{
public:
    virtual ~Employee1() {}
    virtual int RegisterAccount() const = 0;
};

class Programmer2 : public Employee1
{
public:
    virtual int RegisterAccount() const override
    {
        int accountNo = rand();
    }
};

class Designer2 : public Employee1
{
public:
    virtual int RegisterAccount() const override
    {
        int accountNo = rand();
    }
};
// 由以上代码，每个员工都需要经过创建员工对象以及调用工号注册方法，可以构成一个固定的业务流程模板

class Department3
{
public:
    virtual ~Department3() {}
    virtual Employee1 *createEmployee() const = 0;

    void OnBoard() const
    { // 工厂方法的核心所在
        Employee1 *employee1 = this->createEmployee();
        employee1->RegisterAccount();
        delete employee1;
    }
};

class ITDepartment3 : public Department3
{
public:
    virtual Employee1 *createEmployee() const override
    {
        return new Programmer2;
    }
};

int main()
{
    Department department;
    department.createEmployee();
    Department::staticCreateEmployee();

    Department1 department1;
    department1.createEmployee(EmployeeType::Programmer1);

    // 子类工厂承担了具体的对象创建职责，在需要添加新员工时，只需要由新的子类工厂创建，其核心远不止如此
    // 这就是对修改关闭，对扩展开放
    ITDepartment2 iTDepartment2;
    iTDepartment2.createEmployee();

    ITDepartment3 iTDepartment3;
    iTDepartment3.OnBoard(); // 此时，OnBoard中createEmployee接口的实现由ITDepartment提供，而RegisterAccount方法由Programmer类提供
    return 0;
}