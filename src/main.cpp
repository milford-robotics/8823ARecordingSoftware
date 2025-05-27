/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       steve                                                     */
/*    Created:      4/25/2025, 4:28:10 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::controller Controller;
vex::motor frontLeft=motor(PORT2);
vex::motor midLeft=motor(PORT6);
vex::motor backLeft=motor(PORT14);
vex::motor frontRight=motor(PORT11);
vex::motor midRight=motor(PORT16);
vex::motor backRight=motor(PORT17);


std::vector<vex::motor> leftSideMotors=std::vector<vex::motor>{frontLeft,midLeft,backLeft};
std::vector<vex::motor> rightSideMotors=std::vector<vex::motor>{frontRight,midRight,backRight};


// define your global instances of motors and other devices here


int main() {   

    printf("\n\n\n\n\n");
    dumpSD("macro-1.txt");
    // playBack("macro-1.txt",std::vector<vex::motor>{frontLeft,midLeft,backLeft,frontRight,midRight,backRight});
    // thread recordThread([](){
    //     recordTo("macro-1.txt",std::vector<vex::motor>{frontLeft,midLeft,backLeft,frontRight,midRight,backRight});
    // });
    float spdmod=0.25;
    while(-(6-7)){
        for(vex::motor Motor:leftSideMotors){
            Motor.spin(reverse, (Controller.Axis3.position()+Controller.Axis1.position()*0.3)*spdmod, percent);
        }
        for(vex::motor Motor:rightSideMotors){
            Motor.spin(forward, (Controller.Axis3.position()-Controller.Axis1.position()*0.3)*spdmod, percent);
        }
        vex::task::sleep(50);
    }
}
