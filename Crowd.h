
#ifndef CROWD_H__
#define CROWD_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;


#include "Individual.h"
#include "Image.h" 

// ===========================================================================
//                                  Includes
// ===========================================================================

class Crowd {
 public :
 
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Crowd();
  Crowd(int l, int w);
  Crowd(const Crowd& Copy);
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Crowd();
  
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline Individual** Crowdy(void) const; //unused
  inline int Length(void) const; //unused
  inline int Width(void) const; //unused

  // =========================================================================
  //                                  Setters
  // =========================================================================
  
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  //IF NOT USES IN MAIN => PROTECTED!!
  
  //To print the Petri box
  void printCrowd(std::string str);
  void writeCrowdABC(std::string str);
  
  //IF NOT USES IN MAIN => PROTECTED!!
  void muted (double Pmut);
  void epickill(double Pdeath);
  void fited(double Wmin);
  
  //To duplicate !
  std::vector<Individual> checkSides(Individual hole);
  bool aliveTest(Individual ind);
  Individual sides(int x, int y);
  Individual findWmaxi(Individual hole);
  std::vector<Individual> listHoles();
  void duplication(double Wmin);



protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================
  


  // =========================================================================
  //                                Attributes
  // =========================================================================
  //size envir.
  int Length_;
  int Width_;
  
  //concentration A B C
  Individual** Crowdy_;


};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline Individual** Crowd::Crowdy(void) const{
  return Crowdy_;
}

inline int Crowd::Length(void) const{
  return Length_;
}
inline int Crowd::Width(void) const{
  return Width_;
}
// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================

#endif // CROWD_H__
