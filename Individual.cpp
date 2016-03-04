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
//Constructeur par défaut
Individual::Individual() {
  //srand(time(NULL)); // PUT HERE  !!!!!!!!!!!!!?????
    
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

//Constructor with x and y
Individual::Individual(int a, int b) {
  //srand(time(NULL));
    
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

void Individual::baby(Individual Parent){
  G_ = Parent.G_;
  
  A_ = Parent.A_;
  B_ = Parent.B_;
  C_ = Parent.C_;
  
  w_ = Parent.w_;
  
  alive_= Parent.alive_;
}

void Individual::parent(double Wmin){
  A_ = A_/2.;
  B_ = B_/2.;
  C_ = C_/2.;

  this->fitness(Wmin);
}

//IF NOT USES IN MAIN => PROTECTED!!
void Individual::mutation(double Pmut){
  
  double mut = (double)rand() / (double)RAND_MAX;
  
  if (mut <= Pmut){
    if (G_ ==1){
      G_ = 0;
    }
    else {
      G_ = 1;
    }
  }    
}  

void Individual::massacre(double Pdeath){
  if (alive_){
    double death = (double)rand() / (double)RAND_MAX;
  
    if (death <= Pdeath){
      alive_ = false;
    } 
  }   
}  

void Individual::fitness(double Wmin){
  if (alive_){
    if (G_ == 1){
      w_ = B_;
    }
    else{
      w_ = C_;
    }
  
    if (w_ < Wmin){
      w_ = 0;
    }
  }
}  
  
// ===========================================================================
//                              Protected Methods
// ===========================================================================

