
// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "Individual.h"
#include "Environment.h"
#include "Life.h"

using namespace std;

// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================
int main() {
  
  srand(time(NULL));
  
  printf("Hello world !\n");
  
  // ===================================================================
  //                               Individual
  // ===================================================================
  Individual Ecoli1 = Individual(2,3);  
  cout<<"Genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  Ecoli1.mutation(1);
  cout<<"After possible mutation, genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  
  // ===================================================================
  //                               Environment
  // ===================================================================
  
  Environment Pet = Environment(5,5,1,1);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  
  
  // ===================================================================
  //                               Crowd
  // ===================================================================
  
  Crowd c1 = Crowd(4,6);
  c1.printCrowd("PetriBox_");
  
  c1.epickill(0.95);
  cout<<"c1 position 1,0: "<<c1.Crowdy()[1][0].alive()<<endl;
  cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].alive()<<endl;
  //~ cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].w()<<endl;
  cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].alive()<<endl;
  //~ cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].w()<<endl;
  
  //~ Individual Coli = Individual(c1.findWmaxi(c1.Crowdy()[1][0]));
  //~ cout<<"Coli from findWmaxi : "<<Coli.x()<<" "<<Coli.y()<<endl;
  
  
  
  for (int i=0; i<6; i++){
    cout<<c1.Crowdy()[0][i].alive()<<" "<<c1.Crowdy()[1][i].alive()<<" "<<c1.Crowdy()[2][i].alive()<<" "<<c1.Crowdy()[3][i].alive()<<endl;
  }
    
  //PB HERE !!!!!!!!!!!!!!!!!!!!!!!!!!
  c1.duplication();
  cout<<"c1 position 1,0: "<<c1.Crowdy()[1][0].alive()<<endl;
  cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].alive()<<endl;
  cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].alive()<<endl;
  
  for (int i=0; i<6; i++){
    cout<<c1.Crowdy()[0][i].alive()<<" "<<c1.Crowdy()[1][i].alive()<<" "<<c1.Crowdy()[2][i].alive()<<" "<<c1.Crowdy()[3][i].alive()<<endl;
  }
  
  return 0;
}
