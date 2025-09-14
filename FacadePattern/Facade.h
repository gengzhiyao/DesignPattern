#pragma once
#include <iostream>

class LightSystem{
    public:
        void TurnOff() const;
};

class AirConditioner{
public:
    void PowerOff() const;
};

class CurtainSystem{
public:
    void Close() const;
};

class SmartHome{
    private:
        const LightSystem* m_ls;//const指针只能调用const成员函数，无法通过m_ls更改类中的成员变量
        const AirConditioner *m_ac;
        const CurtainSystem *m_cs;

    public:
        SmartHome() = delete;
        explicit SmartHome(const LightSystem *ls, const AirConditioner *ac, const CurtainSystem *cs) noexcept;

        void LeaveHome();
};