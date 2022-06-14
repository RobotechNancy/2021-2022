#include "MesFonctions.h"
#include <string>
#include <iostream>
#include<windows.h>

using namespace std;

void ModeAutoTestIN(){
    cout << "dans le in de autotest" << endl;
}
void ModeAutoTestRUN(){
    Sleep(10);
    cout << "dans le run de autotest" << endl;
//    string i;
//    cin >> i;
}
void ModeAutoTestOUT(){
    cout << "dans le out de autotest" << endl;
}
void InitialisationOdometrieIN(){
    cout << "dans le in de odom" << endl;
}
void InitialisationOdometrieRUN(){
    cout << "dans le run de odom" << endl;
}
void InitialisationOdometrieOUT(){
    cout << "dans le out de odom" << endl;
}
void ModeArretUrgenceIN(){
    cout << "dans le in de arret Urgence" << endl;
}
void ModeArretUrgenceRUN(){
    cout << "dans le run de arret Urgence" << endl;
}
void ModeArretUrgenceOUT(){
    cout << "dans le out de arret Urgence" << endl;
}
void ModeCompetitionIN(){
    cout << "dans le in de Competition" << endl;
}
void ModeCompetitionRUN(){
    cout << "dans le run de Competition" << endl;
}
void ModeCompetitionOUT(){
    cout << "dans le out de Competition" << endl;
}
void ModeMaintenanceIN(){
    cout << "dans le in de Maintenance" << endl;
}
void ModeMaintenanceRUN(){
    cout << "dans le run de Maintenance" << endl;
}
void ModeMaintenanceOUT(){
    cout << "dans le out de Maintenance" << endl;
}
void ModeSpectacleIN(){
    cout << "dans le in de Spectacle" << endl;
}
void ModeSpectacleRUN(){
    cout << "dans le run de Spectacle" << endl;
}
void ModeSpectacleOUT(){
    cout << "dans le out de Spectacle" << endl;
}
void ArretRobotIN(){
    cout << "dans le in de ArretRobot" << endl;
}
void ArretRobotRUN(){
    cout << "dans le run de ArretRobot" << endl;
}
void ArretRobotOUT(){
    cout << "dans le out de ArretRobot" << endl;
}

void headerFonctions(string name){
    if(name == "ModeAutoTestIN")
        ModeAutoTestIN();
    else if(name == "ModeAutoTestRUN")
        ModeAutoTestRUN();
    else if(name == "ModeAutoTestOUT")
        ModeAutoTestOUT();
    else if(name == "InitialisationOdometrieIN")
        InitialisationOdometrieIN();
    else if(name == "InitialisationOdometrieRUN")
        InitialisationOdometrieRUN();
    else if(name == "InitialisationOdometrieOUT")
        InitialisationOdometrieOUT();
    else if(name == "ModeArretUrgenceIN")
        ModeArretUrgenceIN();
    else if(name == "ModeArretUrgenceRUN")
        ModeArretUrgenceRUN();
    else if(name == "ModeArretUrgenceOUT")
        ModeArretUrgenceOUT();
    else if(name == "ModeCompetitionIN")
        ModeCompetitionIN();
    else if(name == "ModeCompetitionRUN")
        ModeCompetitionRUN();
    else if(name == "ModeCompetitionOUT")
        ModeCompetitionOUT();
    else if(name == "ModeSpectacleIN")
        ModeSpectacleIN();
    else if(name == "ModeSpectacleRUN")
        ModeSpectacleRUN();
    else if(name == "ModeSpectacleOUT")
        ModeSpectacleOUT();
    else if(name == "ModeMaintenanceIN")
        ModeMaintenanceIN();
    else if(name == "ModeMaintenanceRUN")
        ModeMaintenanceRUN();
    else if(name == "ModeMaintenanceOUT")
        ModeMaintenanceOUT();
    else if(name == "ArretRobotIN")
        ArretRobotIN();
    else if(name == "ArretRobotRUN")
        ArretRobotRUN();
    else if(name == "ArretRobotOUT")
        ArretRobotOUT();
    else
        cout << name << "ne trouve pas la fonction" << endl;
}

int test(){return 1;}
int test2(){return 1;}
int headerIntFonctions(string name){
    if(name == "test")
        return test();
    else if(name == "test2")
        return test2();
    return -1;
}

int headerVariables(string name){

}

int headerFcts(string _f){
    return headerIntFonctions(_f);
}
