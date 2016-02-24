
#ifndef CROWD_H__
#define CROWD_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "Individual.h"

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