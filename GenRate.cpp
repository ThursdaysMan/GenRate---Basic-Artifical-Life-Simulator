//Imports
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "GenRateBehaviours.h"

Denizen GlobalDenizens[2000];
int Length;

int main(){
	std::cout << "Initialise Simulation" << std::endl;
	std::cout << "/////////////////////" << std::endl;
	//Initialise Time
	int Time;
	int TimeLimit = 10000;
	
	//Initialise World
	int xdim[2] = {0,200};
	int ydim[2] = {0,200};
	
	//Initialise Denizen Repository and Initial Random Denizens
	RandomDenizenInit(100,GlobalDenizens);
	Length = sizeof GlobalDenizens/sizeof GlobalDenizens[0];
	
	//Open Loggin CSV
    std::ofstream CSV;
    CSV.open ("Generation.csv");
    CSV << "Time,G1,G2,G3,G4,G5,G6,G7,Position X,Position y,Life Force\n";

	//Run Simulation
		for (int Time = 0; Time < TimeLimit; Time++) {
			//Log CSV Entry
			for (int i = 0; i < Length; i++) {
			CSV << Time << ",";
			CSV << GlobalDenizens[i].geneticcode[0] << ",";
			CSV << GlobalDenizens[i].geneticcode[1] << ",";
			CSV << GlobalDenizens[i].geneticcode[2] << ",";
			CSV << GlobalDenizens[i].geneticcode[3] << ",";
			CSV << GlobalDenizens[i].geneticcode[4] << ",";
			CSV << GlobalDenizens[i].geneticcode[5] << ",";
			CSV << GlobalDenizens[i].geneticcode[6] << ",";
			CSV << GlobalDenizens[i].position[0] << ",";
			CSV << GlobalDenizens[i].position[1] << ",";
			CSV << GlobalDenizens[i].livingstatus << "\n";
			};
			
			MovementCycle(Length,GlobalDenizens);
				 std::cout << Time << " : " << 10 << " : " <<"Movement Geneticcode 0 : " << GlobalDenizens[10].geneticcode[0] << GlobalDenizens[10].geneticcode[1] << GlobalDenizens[10].geneticcode[2] << GlobalDenizens[10].geneticcode[3] << GlobalDenizens[10].geneticcode[4] << GlobalDenizens[10].geneticcode[5] << GlobalDenizens[10].geneticcode[6] << std::endl;
				 std::cout << Time << " : " << 10 << " : " <<"Movement Position 0 : " << GlobalDenizens[10].position[0] << std::endl;
				 std::cout << Time << " : " << 10 << " : " <<"Movement Position 1 : " << GlobalDenizens[10].position[1] << std::endl; 
			 
			 
			ReproductionCycle(Length,GlobalDenizens);
				 std::cout << Time << " : Denizen Geneticcode: " << GlobalDenizens[10].geneticcode[0] << GlobalDenizens[10].geneticcode[1] << GlobalDenizens[10].geneticcode[2] << GlobalDenizens[10].geneticcode[3] << GlobalDenizens[10].geneticcode[4] << GlobalDenizens[10].geneticcode[5] << GlobalDenizens[10].geneticcode[6] << std::endl;
				 std::cout << Time << " : Denizen LivingStatus: " << GlobalDenizens[10].livingstatus << std::endl;
			 
			 /*for (int i = 0; i < Length; i++){
				 std::cout << Time << " : Denizen Geneticcode: " << GlobalDenizens[i].geneticcode[0] << GlobalDenizens[i].geneticcode[1] << GlobalDenizens[i].geneticcode[2] << GlobalDenizens[i].geneticcode[3] << GlobalDenizens[i].geneticcode[4] << GlobalDenizens[i].geneticcode[5] << GlobalDenizens[i].geneticcode[6] << std::endl;
				 std::cout << Time << " : Denizen LivingStatus: " << GlobalDenizens[i].livingstatus << std::endl;
				 };  */
			Death(Length,GlobalDenizens);
		};
	//Close CSV Logging
	CSV.close();

}
