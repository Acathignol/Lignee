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
  
  box_ = new Environment(length,width,ainit);
  ecoli_ = new Crowd(length,width);
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
          //~ double A1 = 0.;
          //~ double B1 = 0.;
          //~ double Aout1 = 0.;
          
          for (int z=0 ; z<=9 ; z++){
            B += ((A*Rab_)*0.1) ;
            A += ((Aout*Raa_-A*Rab_)*0.1) ;
            Aout -= ((Aout*Raa_)*0.1) ;
          }
          
          ecoli_->Crowdy()[i][j].set_A(A);
          ecoli_->Crowdy()[i][j].set_B(B);
          box_->PetriA()[i][j]=Aout;
        }
        else if (ecoli_->Crowdy()[i][j].G() == 0){
          double B = ecoli_->Crowdy()[i][j].A();
          double C = ecoli_->Crowdy()[i][j].C();
          double Bout = box_->PetriB()[i][j];
          
          for (int z=0 ; z<=9 ; z++){
            C += ((B*Rbc_)*0.1) ;
            B += ((Bout*Rbb_-B*Rbc_)*0.1) ;
            Bout -= ((Bout*Rbb_)*0.1) ;
          }
          
          ecoli_->Crowdy()[i][j].set_B(B);
          ecoli_->Crowdy()[i][j].set_C(C);//1 OR HERE
          box_->PetriB()[i][j]=Bout; //PROBLEM HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!=> resolve pb cin a voir , cout viendras avec ///   ET AOUT ET B AVANT OU APRES A ????????????????????
          //~ }
        }
      }
    }
  }
  ecoli_->fited(Wmin_);
}


void Life::combo(){
  ecoli_->epickill(Pdeath_);
  std::vector<Individual> vec = ecoli_->listHoles();
  for (int i=0 ; i<int(vec.size()) ; i++){
    if (not vec[i].alive()){
      //~ cout<<box_->PetriA()[vec[i].x()][vec[i].y()]<<endl;
      box_->PetriA()[vec[i].x()][vec[i].y()] += vec[i].A();
      box_->PetriB()[vec[i].x()][vec[i].y()] += vec[i].B();
      box_->PetriC()[vec[i].x()][vec[i].y()] += vec[i].C();
    }
  }
}

//Method which shows what happens at each generation :
void Life::nextStep(){
  
  box_->diffusion(D_); //Concentrations diffuse
  this->combo(); //Cells die
  ecoli_->muted(Pmut_); //Cells mutate
  ecoli_->duplication(Wmin_); //Cells duplicate
  this->metaboWeb(); //Cells metabolism (Concentrations in increase for 
  //A and B (Ga) or B and C (Gb); Concentrations out decrease for A (Ga) or B (Gb);
}


void Life::hugeCycle(std::string STR){
  
  //~ remove("Aout A.txt");
  //~ remove("Bout A.txt");
  //~ remove("Cout A.txt");
  //~ remove("Ain A.txt");
  //~ remove("Bin A.txt");
  //~ remove("Cin A.txt");
  //~ remove("Aout B.txt");
  //~ remove("Bout B.txt");
  //~ remove("Cout B.txt");
  //~ remove("Ain B.txt");
  //~ remove("Bin B.txt");
  //~ remove("Cin B.txt");
  box_->writeEnvABC(STR, ecoli_->Crowdy());
  ecoli_->writeCrowdABC(STR);

  //First: in order to have positive fitnesses (non null), metabolism; 
  this->metaboWeb(); 
  
  for (int i = 1 ; i<=Simul_ ; i++){
    if ((i%T_)==0){
      box_->recycle(Ainit_); //Renewing the environment
      
    }
    if ((i%500)==0){cout<<"iteration "<<i<<endl;
      box_->writeEnvABC(STR, ecoli_->Crowdy());
      ecoli_->writeCrowdABC(STR);}
    this->nextStep(); //Cells metabolism (Concentrations in increase for 
  //A and B (Ga) or B and C (Gb); Concentrations out decrease for A (Ga) or B (Gb);
    
    //~ box_->writeEnvABC(STR, ecoli_->Crowdy());
    //~ ecoli_->writeCrowdABC(STR);
	}
  
  std::string str= STR + "PetriBox_End_10000";
  ecoli_->printCrowd(str);
  
  cout<<"Finit ! ;) "<<endl;
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


