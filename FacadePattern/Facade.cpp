#include "Facade.h"

void LightSystem::TurnOff() const
{
    std::cout << "Light off" << std::endl;
}

void AirConditioner::PowerOff() const
{
    std::cout << "AirConditioner off" << std::endl;
}

void CurtainSystem::Close() const
{
    std::cout << "CurtainSystem close" << std::endl;
}

SmartHome::SmartHome(const LightSystem *ls, const AirConditioner *ac, const CurtainSystem *cs)
    :m_ls(ls),m_ac(ac),m_cs(cs)
{
    
}

void SmartHome::LeaveHome()
{
    m_ls->TurnOff();//const常量指针只能调用const成员函数
    m_ac->PowerOff();
    m_cs->Close();
}