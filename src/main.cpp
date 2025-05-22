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
vex::motor Motor1=motor(PORT12);
vex::motor Motor2=motor(PORT13);


// define your global instances of motors and other devices here


int main() {   

    printf("\n\n\n\n\n");
    dumpSD("macro-1.txt");
    playBack("macro-1.txt",std::vector<vex::motor>{Motor1,Motor2});
    // recordTo("macro-1.txt",std::vector<vex::motor>{Motor1,Motor2});
    thread recordThread([](){
        recordTo("macro-1.txt",std::vector<vex::motor>{Motor1,Motor2});
    });

    while(1){
        Motor1.spin(forward,Controller.Axis3.position()*0.3,percent);
        Motor2.spin(forward,Controller.Axis2.position()*0.3,percent);
        vex::task::sleep(50);
    }
}
