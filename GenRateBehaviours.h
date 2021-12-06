#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

//Defines the creatures in the world
class Denizen {       
  public:             
    int geneticcode[7];
    int position[2];
	int livingstatus;
}; 

Denizen * RandomDenizenInit(int number, Denizen Denizens[2000]) {

	for (int i = 0; i < number; i++){
		//Create Denizen
		Denizen Dzn;
		//Define random Denizen outputs
		for (int j = 0; j < 7; j++) {
			Dzn.geneticcode[j] = rand()% 9 + 1;
		};
		Dzn.position[0] = rand()% 200 + 1;
		Dzn.position[1] = rand()% 200 + 1;
		Dzn.livingstatus = Dzn.geneticcode[6] * 10;
		//Denizen to box
		Denizens[i] = Dzn;
	};
		//Error Checking Output - REMOVE IN FINAL CODE
		  for (int i = 0; i < sizeof Denizens/sizeof Denizens[0]; i++){
			std::cout << "Geneticcode : " << Denizens[i].geneticcode[0] << Denizens[i].geneticcode[1] << Denizens[i].geneticcode[2] << Denizens[i].geneticcode[3] << Denizens[i].geneticcode[4] << Denizens[i].geneticcode[5] << Denizens[i].geneticcode[6] << std::endl;
			std::cout << "Position 0 : " << Denizens[i].position[0] << std::endl;
			std::cout << "Position 1 : " << Denizens[i].position[1] << std::endl;
		}; 
		/* for (int i = 0; i < 100; i++){ 
			//std::cout << "Geneticcode : " << Denizens[i].geneticcode[0] << Denizens[i].geneticcode[1] << Denizens[i].geneticcode[2] << Denizens[i].geneticcode[3] << Denizens[i].geneticcode[4] << Denizens[i].geneticcode[5] << Denizens[i].geneticcode[6] << std::endl;
			//std::cout << "Position 0 : " << Denizens[i].position[0] << std::endl;
			//std::cout << "Position 1 : " << Denizens[i].position[1] << std::endl;
		}; */
};


//Behaviours

//Movement
Denizen MovementCycle (int Length,Denizen *Denizens) {
	for (int i = 0; i < Length; i++) {
		if (Denizens[i].livingstatus > 0){
			Denizens[i].position[0] = abs(Denizens[i].position[0] - Denizens[i].geneticcode[0] + Denizens[i].geneticcode[1]);
			Denizens[i].position[1] = abs(Denizens[i].position[1] - Denizens[i].geneticcode[2] + Denizens[i].geneticcode[3]);
		};
	};
};

//Reproduction
void ReproductionCycle (int Length,Denizen *Denizens){
	//Denizen Reproduction
	for (int i = 0; i < Length; i++) {
		//Checks if alive
		if (Denizens[i].livingstatus > 0){
			for (int j = 0; j < Length; j++) {
				//Checks Denizen position
				if (abs(Denizens[i].position[0] - Denizens[j].position[0]) < 3 && abs(Denizens[i].position[1] - Denizens[j].position[1]) < 3) {
					//Determines chance of reproduction
					if (Denizens[i].geneticcode[4] + Denizens[j].geneticcode[4] + rand()% 100 > 90) {
						for (int k = 0; k < Length; k++) {
							//Finds empty position in Denizens Array
							if (Denizens[k].livingstatus <= 0) {
								//Creates new Denizen
								Denizen Dzn;
								for (int l = 0; l < 7; l++) {
									//RMS Genetic Combination Technique
									std::cout << round(sqrt((pow(Denizens[i].geneticcode[l],2) + pow(Denizens[j].geneticcode[l],2) + pow(rand()% 10 - 1,2))/3)) << std::endl;
									Dzn.geneticcode[l] = round(sqrt((pow(Denizens[i].geneticcode[l],2) + pow(Denizens[j].geneticcode[l],2) + pow(rand()% 10 - 1,2))/3));					
								};								
								Dzn.position[0] = round((Denizens[i].position[0] + Denizens[j].position[0])/2);
								Dzn.position[1] = round((Denizens[i].position[1] + Denizens[j].position[1])/2);
								Dzn.livingstatus = Dzn.geneticcode[6] * 20;
								Denizens[k] = Dzn;
								std::cout << "New Denizen at Entry : "<< k << " at X : "<< Denizens[k].position[0]<< " at Y : "<< Denizens[k].position[1]<<std::endl;							
								break;
							};
						};
					};
				
				
				};
			};
		};
	};
};

//Death
void Death (int Length,Denizen *Denizens) {
	//Checks for Denizen Death
		for (int i = 0; i < Length; i++) {
			//Denizen Life Remover
			Denizens[i].livingstatus = Denizens[i].livingstatus - 1; 
				//Denizen Kill Switch
				if (Denizens[i].livingstatus <= 0){
						for (int j = 0; j < 7; j++) {
							 Denizens[i].geneticcode[j] = 0;
		                    };
						Denizens[i].position[0] = 0;
						Denizens[i].position[1] = 0; 
					};
			};
};

