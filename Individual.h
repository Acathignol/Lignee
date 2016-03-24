
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
  Individual(int X, int Y,int a); 
  Individual(const Individual& ind,int a, int b);
  Individual(int a, int b);
  
  // =========================================================================
  //                                Destructor
  // =========================================================================
  ~Individual();
  
  // =========================================================================
  //                                  Getters
  // =========================================================================
  inline int G(void) const; //unused
  
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
  inline void set_G(int i) ; //unused

  inline void set_A(double i) ; //unused
  inline void set_B(double i) ; //unused
  inline void set_C(double i) ; //unused
  
  // =========================================================================
  //                              Public Methods
  // =========================================================================
  //IF NOT USES IN MAIN => PROTECTED!!
  void mutation(double Pmut);
  void fitness(double Wmin);
  void massacre(double Pdeath);
  void baby(Individual Parent);
  void parent(double Wmin);


protected :
  // =========================================================================
  //                                Attributes
  // =========================================================================
  //genotype
  int G_; //1 = "you eat gluc"=GA  0 = "you eat acetate"=GB
  
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
inline int Individual::G(void) const{
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
inline void Individual::set_G(int i) {
  G_ = i;
}

inline void Individual::set_A(double i) {
  A_ = i;
}
inline void Individual::set_B(double i) {
  B_ = i;
}
inline void Individual::set_C(double i) {
  C_ = i;
}

#endif // INDIVIDUAL_H__
