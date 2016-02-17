
#ifndef INDIVIDUAL_H__
#define INDIVIDUAL_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

// ===========================================================================
//                                  Includes
// ===========================================================================

class Individual {
 public :
 
  // =========================================================================
  //                               Constructors
  // =========================================================================
  Individual();
  Individual(const Individual& ind,int a, int b);
  Individual(int a, int b);
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Individual();
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline bool G(void) const; //unused
  
  inline double A(void) const; //unused
  inline double B(void) const; //unused
  inline double C(void) const; //unused

  inline double w(void) const; //unused
  
  inline int x(void) const; //unused
  inline int y(void) const; //unused
  
  inline bool alive(void) const; //unused

  // =========================================================================
  //                                  Setters
  // =========================================================================
  //~ inline void set_G(bool i) const; //unused
//~ 
  inline void set_A(double i) ; //unused
  inline void set_B(double i) ; //unused
  inline void set_C(double i) ; //unused
//~ 
  //~ inline void set_w(double i) const; //unused
 //~ 
  //~ inline void set_x(int i) const; //unused
  //~ inline void set_y(int i) const; //unused
  //~ 
  //~ inline void set_alive(bool i) const; //unused
  
  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
  //IF NOT USES IN MAIN => PROTECTED!!
  void mutation(double Pmut);
  void fitness(double Wmin);
  void massacre(double Pdeath);
  Individual baby(int a, int b);


protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================
  


  // =========================================================================
  //                                Attributes
  // =========================================================================
  //genotype
  bool G_; //1 = "you eat gluc"=GA  0 = "you eat acetate"=GB
  
  //concentration A B C
  double A_;
  double B_;
  double C_;
  
  //fitness
  double w_;
  
  //position in envir.
  int x_;
  int y_;
  
  //alive or not?
  bool alive_; // 0 dead, 1 alive
  
};


// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline bool Individual::G(void) const{
  return G_;
}

inline double Individual::A(void) const{
  return A_;
}
inline double Individual::B(void) const{
  return B_;
}

inline double Individual::C(void) const{
  return C_;
}

inline double Individual::w(void) const{
  return w_;
}
 
inline int Individual::x(void) const{
  return x_;
}
inline int Individual::y(void) const{
  return y_;
}
  
inline bool Individual::alive(void) const{
  return alive_;
}

// ===========================================================================
//                            Setters' definitions
// ===========================================================================
//~ inline void Individual::set_G(bool i) const{
  //~ G_ = i;
//~ }
//~ 
inline void Individual::set_A(double i) {
  A_ = i;
}
inline void Individual::set_B(double i) {
  B_ = i;
}
inline void Individual::set_C(double i) {
  C_ = i;
}

//~ inline void Individual::set_w(double i) const{
  //~ w_ = i;
//~ }
 
//~ inline void Individual::set_x(int i) const{
  //~ x_ = i;
//~ }
//~ inline void Individual::set_y(int i) const{
  //~ y_ = i;
//~ }
  
//~ inline void Individual::set_alive(bool i) const{
  //~ alive_ = i;
//~ }
// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================



#endif // INDIVIDUAL_H__
