
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
  
  srand(time(NULL));
  
  printf("Hello world !\n");
  
  Individual Ecoli1 = Individual(2,3);  
  cout<<"Genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  Ecoli1.mutation(1);
  cout<<"After possible mutation, genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  
  Environment Pet = Environment(5,5,1,1);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  Crowd c1 = Crowd(4,3);
  c1.epickill(0.25);
  cout<<"c1 position 1,0: "<<c1.Crowdy()[1][0].alive()<<endl;
  cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].alive()<<endl;
  cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].w()<<endl;
  cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].alive()<<endl;
  cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].w()<<endl;
  
  Individual Coli = Individual(c1.findWmaxi(c1.Crowdy()[1][0]));
  cout<<"Coli from findWmaxi : "<<int(Coli.w())<<endl;
  
  
  return 0;
}
