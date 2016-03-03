
#ifndef LIFE_H__
#define LIFE_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Environment.h"
#include "Individual.h"
#include "Crowd.h"

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
  //                                  Getters
  // =========================================================================
  inline int T(void) const; //unused
  inline int Simul(void) const; //unused
  inline double Ainit(void) const; //unused
  inline int len(void) const; //unused
  inline int wid(void) const; //unused
  inline double D(void) const; //unused
  inline double Pmut(void) const; //unused
  inline double Pdeath(void) const; //unused
  inline double Wmin(void) const; //unused
  inline double Raa(void) const; //unused
  inline double Rbb(void) const; //unused
  inline double Rab(void) const; //unused
  inline double Rbc(void) const; //unused

  inline Environment box(void) const;
  inline Crowd ecoli(void) const;

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

  void metaboWeb();
  void combo();
  void nextStep();
  void hugeCycle();



protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================
  


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
  
  Environment box_;
  Crowd ecoli_;


};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================

// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================

inline int Life::T(void) const{
  return T_;
}
inline int Life::Simul(void) const{
  return Simul_;
}

inline double Life::Ainit(void) const{
  return Ainit_;
}

inline int Life::len(void) const{
  return len_;
}
inline int Life::wid(void) const{
  return wid_;
}

inline double Life::D(void) const{
  return D_;
}

inline double Life::Pmut(void) const{
  return Pmut_;
}
inline double Life::Pdeath(void) const{
  return Pdeath_;
}
  
inline double Life::Wmin(void) const{
  return Wmin_;
}
 
inline double Life::Raa(void) const{
  return Raa_;
}
inline double Life::Rbb(void) const{
  return Rbb_;
}
inline double Life::Rab(void) const{
  return Rab_;
}
inline double Life::Rbc(void) const{
  return Rbc_;
}


inline Environment Life::box(void) const{
  return box_;
}
inline Crowd Life::ecoli(void) const{
  return ecoli_;
}

#endif // LIFE_H__

