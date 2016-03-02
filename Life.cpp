// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Life.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================
//Constructeur par défaut
Life::Life() {
  Tmin_=0;
  Tmax_=0;
  Simul_=0;
  Ainitx_=0;
  Ainity_=0;
  wid_=0;
  len_=0;
  D_=0;
  Pmut_=0;
  Pdeath_=0;
  Wmin_=0;
  Raa_=0;
  Rbb_=0;
  Rab_=0;
  Rbc_=0; 

  Environment box_ = Environment();
  Crowd ecoli_ = Crowd();
}

Life::Life(int tmin, int tmax, int simul, int ainitx, int ainity, 
int width, int length, double d, double pmut, double pdeath, double wmin,
double raa, double rbb, double rab, double rbc) {

  Tmin_=tmin;
  Tmax_=tmax;
  Simul_=simul;
  Ainitx_=ainitx;
  Ainity_=ainity;
  wid_=width;
  len_=length;
  D_=d;
  Pmut_=pmut;
  Pdeath_=pdeath;
  Wmin_=wmin;
  Raa_=raa;
  Rbb_=rbb;
  Rab_=rab;
  Rbc_=rbc; 
  
  Environment box_ = Environment(length,width,ainitx,ainity);
  Crowd ecoli_ = Crowd(length,width);
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
Life::~Life(){
  }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================
//change in concentration
void Life::metaboWeb(){
  for (int i=0 ; i<10 ; i++){
    int a = 1;
  }
  
  //~ =>void Crowd::fited(double Wmin) 
  //~ Raa_=raa;
  //~ Rbb_=rbb;
  //~ Rab_=rab;
  //~ Rbc_=rbc; 
}

void Life::combo(){
  ecoli_.epickill(Pdeath_);
  std::vector<Individual> vec = ecoli_.listHoles();
  for (int i=0 ; i<int(vec.size()) ; i++){
    box_.PetriA()[vec[i].x()][vec[i].y()] = box_.PetriA()[vec[i].x()][vec[i].y()]+vec[i].A();
    box_.PetriA()[vec[i].x()][vec[i].y()] = box_.PetriB()[vec[i].x()][vec[i].y()]+vec[i].B();
    box_.PetriA()[vec[i].x()][vec[i].y()] = box_.PetriC()[vec[i].x()][vec[i].y()]+vec[i].C();
  }
}

//Method to know the value of k at n+1
void Life::nextStep(){
  box_.diffusion(D_);
  this->combo();
  ecoli_.muted(Pmut_);
  ecoli_.duplication(Wmin_);
  //~ ecoli_.metaboWeb(); OU this->metaboWeb(); =>void Crowd::fited(double Wmin) 
}

void Life::recycle(){
  //delete old and renew  !
  for (int i=0; i<len_;i++){
    for (int j=0; j<wid_;j++){
	  box_.PetriA()[i][j]=0.;
	  box_.PetriB()[i][j]=0.;
	  box_.PetriC()[i][j]=0.;
	}
  }
  box_.PetriA()[Ainitx_][Ainity_]= 1.; // IS THE CONCENTRATION INIT = 1. ?
}

void Life::hugeCycle(){
  //~ ecoli_.metaboWeb(); OU this->metaboWeb(); 
  for (int i = 1 ; i<=Simul_ ; i++){
	//~ if (MODULO )500 => this->recycle()each Tmax change the environment (recycle method)
    int a = 1;
  }
  
 //~ PRINT THE CELLS
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


