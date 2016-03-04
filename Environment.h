
#ifndef ENVIRONMENT_H__
#define ENVIRONMENT_H__

#include <iostream>
#include <cmath>
#include "Image.h"

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
  inline double** PetriA(void) const; //unused
  inline double** PetriB(void) const; //unused
  inline double** PetriC(void) const; //unused
  
  inline int Length(void) const; //unused
  inline int Width(void) const; //unused
  // =========================================================================
  //                                  Setters
  // =========================================================================

  inline void set_PetriA(double** intab); //unused
  inline void set_PetriB(double** intab) ;//unused
  inline void set_PetriC(double** intab); //unused

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  void printEnvABC(std::string str, double Ainit , double** X);
  void diffusion(double D);
  void recycle(double Ainit);
  int sides(int xy, int LW);

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

inline int Environment::Length(void) const{
  return Length_;
}
inline int Environment::Width(void) const{
  return Width_;
}
  

// ===========================================================================
//                            Setters' definitions
// ===========================================================================
inline void Environment::set_PetriA(double** intab){
  PetriA_=intab;
}
inline void Environment::set_PetriB(double** intab){
  PetriB_=intab;
}
inline void Environment::set_PetriC(double** intab){
  PetriC_=intab;
}

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================



#endif // ENVIRONMENT_H__
