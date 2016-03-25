// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Life.h"

// ===========================================================================
//                                Constructors
// ===========================================================================

//Default constructor (UNUSED)
Life::Life() {
  T_=0;
  Simul_=0;
  Ainit_=0.;
  wid_=0;
  len_=0;
  D_=0.;
  Pmut_=0.;
  Pdeath_=0.;
  Wmin_=0.;
  Raa_=0.;
  Rbb_=0.;
  Rab_=0.;
  Rbc_=0.; 
  
  box_ = new Environment();
  ecoli_ = new Crowd();
}

//Good constructor (USED in main.cpp)
Life::Life(int T, int simul, double ainit, int width, int length, double d,
double pmut, double pdeath, double wmin, double raa, double rbb,
double rab, double rbc) {

  T_=T;
  Simul_=simul;
  Ainit_=ainit;
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
  
  box_ = new Environment(len_,wid_,Ainit_);
  ecoli_ = new Crowd(len_,wid_);
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
Life::~Life(){
  delete box_;
  delete ecoli_;
 }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//change in concentration
//~ A(t+1) =A(t) + (dA/dt)*dt
void Life::metaboWeb(){
  
    
  for (int i=0; i<len_;i++){
    for (int j=0; j<wid_;j++){  
      if (ecoli_->Crowdy()[i][j].alive() == 1){
        if (ecoli_->Crowdy()[i][j].G() == 1){ //Ga=1 Gb=0
          double A = ecoli_->Crowdy()[i][j].A();
          double B = ecoli_->Crowdy()[i][j].B();
          double Aout = box_->PetriA()[i][j];
          
          for (int z=1 ; z<=10 ; z++){
            B += ((A*Rab_)*0.1) ;
            A += ((Aout*Raa_-A*Rab_)*0.1) ;
            Aout -= ((Aout*Raa_)*0.1) ;
          }
          
          ecoli_->Crowdy()[i][j].set_A(A);
          ecoli_->Crowdy()[i][j].set_B(B);
          box_->set_PetriA(i,j, Aout);//PetriA()[i][j]=Aout;
        }
        else if (ecoli_->Crowdy()[i][j].G() == 0){
          double B = ecoli_->Crowdy()[i][j].B();
          double C = ecoli_->Crowdy()[i][j].C();
          double Bout = box_->PetriB()[i][j];
          
          for (int z=1 ; z<=10 ; z++){
            C += ((B*Rbc_)*0.1) ;
            B += ((Bout*Rbb_-B*Rbc_)*0.1) ;
            Bout -= ((Bout*Rbb_)*0.1) ;
          }
          
          ecoli_->Crowdy()[i][j].set_B(B);
          ecoli_->Crowdy()[i][j].set_C(C);//1 OR HERE
          box_->set_PetriB(i,j, Bout);//PetriB()[i][j]=Bout;
        }
      }
    }
  }
  
  //new fitnesses
  ecoli_->fited(Wmin_);
}

//Method to kill and relocate the concentrations of the newly dead individual to the environment
void Life::combo(){
  ecoli_->epickill(Pdeath_);
  std::vector<Individual> vec = ecoli_->listDeads();
  for (int i=0 ; i<int(vec.size()) ; i++){
    if (not vec[i].alive()){
      box_->PetriA()[vec[i].x()][vec[i].y()] += vec[i].A();
      box_->PetriB()[vec[i].x()][vec[i].y()] += vec[i].B();
      box_->PetriC()[vec[i].x()][vec[i].y()] += vec[i].C();
    }
  }
}

void Life::killThemAll(){
  std::vector<Individual> vec = ecoli_->listDeads();
  
  for (int i=0 ; i<int(vec.size()) ; i++){
    if (not vec[i].alive()){
      ecoli_->Crowdy()[vec[i].x()][vec[i].y()].set_G(69);//Individual(vec[i].x(),vec[i].y(),69);
    }
  }
}

//Method to know if everyone is dead or not
bool Life::zombie(){
  std::vector<Individual> vec = ecoli_->listHoles();
  if (int(vec.size())==(len_*wid_)){return true;}
  else {return false;}
}

//Method which shows what happens at each generation :
void Life::nextStep(){
  
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  box_->diffusion(D_); //Concentrations diffuse
  
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  this->combo(); //Cells die
  
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  ecoli_->duplication(Wmin_, Pmut_); //Cells duplicate and mutate or not
  //~ 
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  this->metaboWeb(); //Cells metabolism (Concentrations in increase for 
  //A and B (Ga) or B and C (Gb); Concentrations out decrease for A (Ga) or B (Gb);
  
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
}


void Life::hugeCycle(){//std::string STR){
  //~ box_->writeA(Ainit_);
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  //First: in order to have positive fitnesses (non null), metabolism; 
  this->metaboWeb();
  //~ box_->writeA(Ainit_);
  //~ ecoli_->writeCrowdABC(Ainit_,T_);  
  
  //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
  //~ 
  for (int i = 1 ; i<=Simul_ ; i++){
    if ((i%T_)==0){
      box_->recycle(Ainit_); //Renewing the environment 
    }
    if ((i%5000)==0){cout<<"iteration "<<i<<endl;}
    
    this->killThemAll();
    
    if (this->zombie()){
      break;
    }
    else {this->nextStep();} //Cells metabolism (Concentrations "in" the cells increase for 
  //A and B (Ga) or B and C (Gb); Concentrations out decrease for A (Ga) or B (Gb);
    //~ box_->writeEnvABC(Ainit_,T_, ecoli_->Crowdy());
    //~ ecoli_->writeCrowdABC(Ainit_,T_);  
	}
  
  ecoli_->writeResult("results.txt", Ainit_ , T_);
  
  cout<<"Finit ! ;) "<<endl;
}
