
// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Individual.h"

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
  
  
  return 0;
}
