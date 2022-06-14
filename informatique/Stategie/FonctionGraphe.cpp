#include "MesFonctions.h"
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Graphe.h"
using namespace std;

int GrapheModeSpectacle(Graphe &adGraphe);
int GrapheModeMaintenance(Graphe &adGraphe);
int GrapheInitialisationOdometrie(Graphe &adGraphe);
int GrapheModeCompetition(Graphe &adGraphe){
	clock_t time_GrapheModeCompetition;
	time_GrapheModeCompetition = clock();
	ModeCompetitionRUN();
	if(CompetitionTerminée){
		time_GrapheModeCompetition = clock() - time_GrapheModeCompetition;
		float temps = (float)time_GrapheModeCompetition/CLOCKS_PER_SEC;
		ofstream myLogs;
		myLogs.open("debug.dot", std::ios::app);
		myLogs << "Passage au grapheModeSpectacle en ";
		myLogs << temps << "sec." << endl;
		ModeCompetitionOUT();
		ModeSpectacleIN();
		ModeSpectacleRUN();
		ModeSpectacleOUT();		adGraphe.SetetatCourant(ModeSpectacle);
		adGraphe.genererProgrammes();
GrapheModeCompetition(0x75fb88);

	}
	else if(DétectionDefaillance){
		time_GrapheModeCompetition = clock() - time_GrapheModeCompetition;
		float temps = (float)time_GrapheModeCompetition/CLOCKS_PER_SEC;
		ofstream myLogs;
		myLogs.open("debug.dot", std::ios::app);
		myLogs << "Passage au grapheModeMaintenance en ";
		myLogs << temps << "sec." << endl;
		ModeCompetitionOUT();
		ModeMaintenanceIN();
		ModeMaintenanceRUN();
		ModeMaintenanceOUT();		adGraphe.SetetatCourant(ModeMaintenance);
		adGraphe.genererProgrammes();
GrapheModeCompetition(0x75fbc4);

	}
}int GrapheModeAutoTest(Graphe &adGraphe){
	clock_t time_GrapheModeAutoTest;
	time_GrapheModeAutoTest = clock();
	ModeAutoTestRUN();
	if(robotOpérationnel){
		time_GrapheModeAutoTest = clock() - time_GrapheModeAutoTest;
		float temps = (float)time_GrapheModeAutoTest/CLOCKS_PER_SEC;
		ofstream myLogs;
		myLogs.open("debug.dot", std::ios::app);
		myLogs << "Passage au grapheInitialisationOdometrie en ";
		myLogs << temps << "sec." << endl;
		ModeAutoTestOUT();
		InitialisationOdometrieIN();
		InitialisationOdometrieRUN();
		InitialisationOdometrieOUT();		adGraphe.SetetatCourant(InitialisationOdometrie);
		adGraphe.genererProgrammes();
GrapheModeAutoTest(0x75fd18);

	}
}