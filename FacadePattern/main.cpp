#include "Facade.h"

int main(){
    SmartHome *sm = new SmartHome(new LightSystem(), new AirConditioner(), new CurtainSystem);
    sm->LeaveHome();
}