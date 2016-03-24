
#ifndef LIFE_H__
#define LIFE_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>

#include "Environment.h"
#include "Individual.h"
#include "Crowd.h"

using namespace std;


// ===========================================================================
//                                  Includes
// ===========================================================================

class Life {
 public :
 
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Life();
  Life(int T, int simul, double ainit, int width,int length, double d, 
   double pmut, double pdeath, double wmin, double raa, double rbb, 
   double rab, double rbc);
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Life();
  
  // =========================================================================
  //                              Public Methods
  // =========================================================================
  //IF NOT USES IN MAIN => PROTECTED!!

  void metaboWeb();
  void killThemAll();
  void combo();
  void nextStep();
  void hugeCycle();
  
  bool zombie();

protected :

  // =========================================================================
  //                                Attributes
  // =========================================================================

  int T_;
  int Simul_;
  
  double Ainit_;
  
  int wid_;
  int len_;
  
  double D_;
  
  double Pmut_;
  double Pdeath_;
  double Wmin_;
  
  double Raa_;
  double Rbb_;
  double Rab_;
  double Rbc_; 
  
  Environment* box_; 
  Crowd* ecoli_; 

};

#endif // LIFE_H__

