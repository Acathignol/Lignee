
#ifndef ENVIRONMENT_H__
#define ENVIRONMENT_H__

#include <iostream>
#include <cmath>
#include "Image.h"



#include "Crowd.h"




// ===========================================================================
//                                  Includes
// ===========================================================================

class Environment {
 public :
 
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Environment();
  Environment(int l, int w, double Ainit);
  Environment(const Environment& Copy);
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Environment();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline double** PetriA(void) const; //used
  inline double** PetriB(void) const; //used
  inline double** PetriC(void) const; //used
  
  // =========================================================================
  //                                  Setters
  // =========================================================================

  inline void set_PetriA(int X, int Y, double intab);
  inline void set_PetriB(int X, int Y, double intab);
  inline void set_PetriC(int X, int Y, double intab);

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  void writeA(double ainit);
  void writeEnvABC(double& ainit,int& Tt, Individual** cr);
  void diffusion(double D);
  void recycle(double Ainit);
  int sides(int xy, int LW);

protected :

  // =========================================================================
  //                                Attributes
  // =========================================================================
  
  //size envir.
  int Length_;
  int Width_;
  
  //concentration A B C
  double** PetriA_;
  double** PetriB_;
  double** PetriC_;
  
};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline double** Environment::PetriA(void) const{
  return PetriA_;
}
inline double** Environment::PetriB(void) const{
  return PetriB_;
}
inline double** Environment::PetriC(void) const{
  return PetriC_;
}
  
// ===========================================================================
//                            Setters' definitions
// ===========================================================================
inline void Environment::set_PetriA(int X, int Y, double intab){
  PetriA_[X][Y]=intab;
}
inline void Environment::set_PetriB(int X, int Y, double intab){
  PetriB_[X][Y]=intab;
}
inline void Environment::set_PetriC(int X, int Y, double intab){
  PetriC_[X][Y]=intab;
}

#endif // ENVIRONMENT_H__
