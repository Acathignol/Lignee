
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
  inline Individual** Crowdy(void) const; //used
  inline int Length(void) const; //used
  inline int Width(void) const; //used

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  //IF NOT USES IN MAIN => PROTECTED!!
  
  //To print the Petri box
  void printCrowd(std::string str);
  void writeCrowdABC(double ainit,int Tt);
  
  
  void epickill(double Pdeath);
  void fited(double Wmin);
  
  //To duplicate !
  std::vector<Individual> checkSides(Individual hole);
  Individual sides(int x, int y);
  Individual findWmaxi(Individual hole,std::vector<Individual> v1);
  std::vector<Individual> listHoles();
  std::vector<Individual> listDeads();
  void duplication(double Wmin, double Pmut);
  
  void writeResult(std::string str, double ainit, int T);

protected :
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

#endif // CROWD_H__
