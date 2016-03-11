
// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
//~ #include "Individual.h"
//~ #include "Environment.h"
//~ #include "Crowd.h"
//~ #include "Image.h"
#include "Life.h"

using namespace std;

// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================
int main(int argc, char* argv[]) {
  
  srand(time(NULL));
  
  printf("Hello world !\n");
  
/**
  // ===================================================================
  //                               Individual
  // ===================================================================
  Individual Ecoli1 = Individual(2,3);  
  cout<<"Genotype of ecoli1: "<<Ecoli1.G()<<endl;
  
  Ecoli1.mutation(1);
  cout<<"After possible mutation, genotype of ecoli1: "<<Ecoli1.G()<<endl;
  Ecoli1.set_A(2.);
  Ecoli1.set_B(3.);
  Ecoli1.set_C(4.); 
  
  Ecoli1.parent(0.001);
  
  cout<<"After parent : A "<<Ecoli1.A()<<" B "<<Ecoli1.B()<<" C "<<Ecoli1.C()<<endl;
  // ===================================================================
  //                               Environment
  // ===================================================================
  
  Environment Pet = Environment(5,5,20.5);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  Pet.diffusion(0.1);
  Pet.diffusion(0.1);
  Pet.diffusion(0.1);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  Pet.recycle(25);
  cout<<"Petri A position x,y: "<<Pet.PetriA()[1][1]<<endl;
  
  
  
// TEST IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTTTTT !!!!!!!!!!!!
  
  // ===================================================================
  //                               Crowd
  // ===================================================================
  
  int W=200;
  int L=250;
  
  
  Crowd c1 = Crowd(L,W);
  for (int i=0; i<6; i++){
    cout<<c1.Crowdy()[0][i].G()<<" "<<c1.Crowdy()[1][i].G()<<" "<<c1.Crowdy()[2][i].G()<<" "<<c1.Crowdy()[3][i].G()<<endl;
  }
  cout<<"\n"<<endl;
  
  c1.printCrowd("PetriBox_1");
  c1.epickill(0.50);
  c1.printCrowd("PetriBox_2");
  //~ cout<<"c1 position 1,0: "<<c1.Crowdy()[1][0].alive()<<endl;
  //~ cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].alive()<<endl;
  //~ cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].w()<<endl;
  //~ cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].alive()<<endl;
  //~ cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].w()<<endl;
  
  //~ Individual Coli = Individual(c1.findWmaxi(c1.Crowdy()[1][0]));
  //~ cout<<"Coli from findWmaxi : "<<Coli.x()<<" "<<Coli.y()<<endl;

  //~ for (int i=0; i<6; i++){
    //~ cout<<c1.Crowdy()[0][i].alive()<<" "<<c1.Crowdy()[1][i].alive()<<" "<<c1.Crowdy()[2][i].alive()<<" "<<c1.Crowdy()[3][i].alive()<<endl;
  //~ }
  //~ cout<<"\n"<<endl;

  //~ c1.duplication(0.0001);
  //~ cout<<"c1 position 1,0: "<<c1.Crowdy()[1][0].alive()<<endl;
  //~ cout<<"c1 position 0,0: "<<c1.Crowdy()[0][0].alive()<<endl;
  //~ cout<<"c1 position 2,0: "<<c1.Crowdy()[2][0].alive()<<endl;

  
  for (int i=0; i<6; i++){
    cout<<c1.Crowdy()[0][i].alive()<<" "<<c1.Crowdy()[1][i].alive()<<" "<<c1.Crowdy()[2][i].alive()<<" "<<c1.Crowdy()[3][i].alive()<<endl;
  }
  */
  
  // ===================================================================
  //                              Life
  // ===================================================================
  
  //~ int T = 1000;
  //~ int simul = 500;
  //~ double ainit = 50;
  //~ int width = 32;
  //~ int length = 32;
  //~ double d = 0.1;
  //~ double pmut = 0; 
  //~ double pdeath = 0.01;
  //~ double wmin = 0.001;
  //~ double raa = 0.1;
  //~ double rbb = 0.1;
  //~ double rab = 0.1;
  //~ double rbc = 0.1;
  int T = atoi(argv[1]);
  double ainit = atof(argv[3]);
  int simul = atoi(argv[2]);
  int width = atoi(argv[4]);
  int length = atoi(argv[5]);
  double d = atof(argv[6]);
  double pmut = atof(argv[7]); //seee values PDF !!!
  double pdeath = atof(argv[8]);
  double wmin = atof(argv[9]);
  double raa = atof(argv[10]);
  double rbb = atof(argv[11]);
  double rab = atof(argv[12]);
  double rbc = atof(argv[13]);
  
  
  for (int i = 1; i<=500;i++){
    T = i;
    for (double j = 0. ; j<=50. ; j++){
      ainit = j;
      Life lilou = Life(T, simul, ainit, width, length, d, pmut, pdeath, wmin, raa, rbb, rab, rbc);
      lilou.hugeCycle();
    } 
  } 
  
  
  //~ Life lilou = Life(T, simul, ainit, width, length, d, pmut, pdeath, wmin, raa, rbb, rab, rbc);
  
  //~ cout<<"BOUH!"<<endl;
  
  //~ cout<<lilou.box().PetriA()[0][2];//.alive();
  //~ for (int i=0; i<6; i++){
    //~ cout<<double(*argv[i])<<endl;//<<" "<<lilou.ecoli().Crowdy()[1][i].alive()<<" "<<lilou.ecoli().Crowdy()[2][i].alive()<<" "<<lilou.ecoli().Crowdy()[3][i].alive()<<endl;
  //~ }

  //~ lilou.hugeCycle(); 
  
  //print concentration environment and cells(do a file and then see on R)
  //PB PQ MES CONCENTRATION DISPARAISSENT TOUTES ??????
  
  return EXIT_SUCCESS;
}
