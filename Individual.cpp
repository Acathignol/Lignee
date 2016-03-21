// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Individual.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================

//Default constructor (UNUSED IN MY LIFE CLASS) (srand(time(NULL)) put in main.cpp)
Individual::Individual() {
    
  G_ = rand()%(2-0) +0 ;
    
  // defining the A,B,C AND DOING ONE TURN OF DIFFERENTIAL EQUATION SO W NOT BAD!!!
  A_ = 0.;
  B_ = 0.;
  C_ = 0.;
  
  w_ = 0.;
  
  x_ = 0;
  y_ = 0;
  
  alive_ = true;
}

Individual::Individual(int X, int Y,int a) {// individual SUPER DEAD
    
  G_ = a ;
    
  // defining the A,B,C AND DOING ONE TURN OF DIFFERENTIAL EQUATION SO W NOT BAD!!!
  A_ = 0.;
  B_ = 0.;
  C_ = 0.;
  
  w_ = 0.;
  
  x_ = X;
  y_ = Y;
  
  alive_ = false;
}

//Constructor copy + x and y
Individual::Individual(const Individual& ind, int a, int b) {
  G_ = ind.G_ ;
    
  // defining the A,B,C
  A_ = ind.A_;
  B_ = ind.B_;
  C_ = ind.C_;
  
  w_ = ind.w_;
  
  x_ = a;
  y_ = b;
  
  alive_ = ind.alive_;
}

//Constructor with x and y (srand(time(NULL)) put in main.cpp)
Individual::Individual(int a, int b) {
    
  G_ = rand()%(2-0) +0 ;
    
  // defining the A,B,C
  A_ = 0.;
  B_ = 0.;
  C_ = 0.;
  
  w_ = 0.;
  
  x_ = a;
  y_ = b;
  
  alive_ = true;
}


// ===========================================================================
//                                 Destructor
// ===========================================================================
Individual::~Individual(){

  }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//New concentrations (and fitness)
void Individual::parent(double Wmin){
  A_ = A_/2.;
  B_ = B_/2.;
  C_ = C_/2.;

  this->fitness(Wmin);
}

//New baby :D !
void Individual::baby(Individual Parent){
  G_ = Parent.G_;
  
  A_ = Parent.A_;
  B_ = Parent.B_;
  C_ = Parent.C_;
  
  w_ = Parent.w_;
  
  alive_= Parent.alive_;
}

//One cell randomly realizes a mutation or not (srand(time(NULL)) put in main.cpp)
void Individual::mutation(double Pmut){
  
  double mut = (double)rand() / (double)RAND_MAX;
  
  if (alive_ and mut <= Pmut){
    if (G_ ==1){
      G_ = 0;
    }
    else {
      G_ = 1;
    }
  }    
}  

//One cell randomly dies not (srand(time(NULL)) put in main.cpp)
void Individual::massacre(double Pdeath){
  if (alive_){
    double death = (double)rand() / (double)RAND_MAX;
  
    if (death <= Pdeath){
      alive_ = false;
    } 
  }   
}  

//One cell establishes her fitness of the moment 
void Individual::fitness(double Wmin){
  if (alive_){
    if (G_ == 1){
      w_ = B_;
    }
    else{
      w_ = C_;
    }
  
    if (w_ < Wmin){
      w_ = 0.;
    }
  }
}  
  
// ===========================================================================
//                              Protected Methods
// ===========================================================================

