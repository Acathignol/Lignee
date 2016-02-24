
// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
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
  
  printf("Hello world !\n");
  
  Individual Ecoli1 = Individual(2,3);  
  cout<<"Genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  Ecoli1.mutation(1);
  cout<<"After possible mutation, genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  
  Environment Pet = Environment(5,5,1,1);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  return 0;
}
