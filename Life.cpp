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
  
  box_ = new Environment(); //nullptr
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
  
  //~ Environment envi = Environment(length,width,ainit);
  
  box_ = new Environment(length,width,ainit);//environment;//&Environment(length,width,ainit);
  //~ *box_ = Environment(length,width,ainit);
  
  //~ Crowd eco = Crowd(length,width);
  ecoli_ = new Crowd(length,width);//crowd;//&Crowd(length,width);
  //~ *ecoli_ = Crowd(length,width);
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
void Life::metaboWeb(){
  
    
  for (int i=0; i<len_;i++){
    for (int j=0; j<wid_;j++){
        
      if (ecoli_->Crowdy()[i][j].alive() == 1){ //this->ecoli()
        if (ecoli_->Crowdy()[i][j].G() == 1){ //Ga=1 Gb=0
          double A = ecoli_->Crowdy()[i][j].A();
          double B = ecoli_->Crowdy()[i][j].B();
          double Aout = box_->PetriA()[i][j];
          for (int z=0 ; z<=9 ; z++){
            //~ double A = ecoli_->Crowdy()[i][j].A();
            //~ double B = ecoli_->Crowdy()[i][j].B();
            //~ double Aout = box_->PetriA()[i][j];
            //~ printf("%f",B);
            
            B += ((A*Rab_)*0.1) ;
            A += ((Aout*Raa_-A*Rab_)*0.1) ;
            Aout -= ((Aout*Raa_)*0.1) ;
            //~ A(t+1) =A(t) + (dA/dt)*dt
          }
          ecoli_->Crowdy()[i][j].set_A(A);
          ecoli_->Crowdy()[i][j].set_B(B);
          box_->PetriA()[i][j]=Aout;
          //~ }
        }
        else if (ecoli_->Crowdy()[i][j].G() == 0){
          double B = ecoli_->Crowdy()[i][j].A();
          double C = ecoli_->Crowdy()[i][j].C();
          double Bout = box_->PetriB()[i][j];
          for (int z=0 ; z<=9 ; z++){
            //~ double B = ecoli_->Crowdy()[i][j].B();
            //~ double C = ecoli_->Crowdy()[i][j].C();
            //~ double Bout = box_->PetriB()[i][j];  
            //~ printf("%f",Bout);
            C += ((B*Rbc_)*0.1) ;
            //~ printf("%f",B);
            //~ printf("%f",Bout);
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

//Method to know the value of k at n+1
void Life::nextStep(){
  box_->diffusion(D_); // where to put !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  this->combo();
  ecoli_->muted(Pmut_);
  ecoli_->duplication(Wmin_);
  this->metaboWeb(); 
}


void Life::hugeCycle(){
  
  remove("Aout.txt");
  remove("Bout.txt");
  remove("Cout.txt");
  remove("Ain.txt");
  remove("Bin.txt");
  remove("Cin.txt");
  box_->writeEnvABC();
  ecoli_->writeCrowdABC();
  
  //~ std::string s = "PetriBox_Begin";
  //~ ecoli_->printCrowd(s);
  
  //~ box_->printEnvABC("Aout_0", Ainit_ , box_->PetriA());
  //~ box_->printEnvABC("Bout_0", Ainit_ , box_->PetriB());
  //~ box_->printEnvABC("Cout_0", Ainit_ , box_->PetriC());
  //~ 
  this->metaboWeb(); 
  //~ box_->printEnvABC("Aout_0", Ainit_ , box_->PetriA());
  //~ box_->printEnvABC("Bout_0", Ainit_ , box_->PetriB());
  //~ box_->printEnvABC("Cout_0", Ainit_ , box_->PetriC());
  for (int i = 1 ; i<=Simul_ ; i++){
    //~ cout<<"Bip "<<i<<endl;
    if ((i%T_)==0){
      //~ std::string str1 = std::string("PetriBox_");
      //~ std::string str11a = std::string("Aout_");
      //~ std::string str11b = std::string("Bout_");
      //~ std::string str11c = std::string("Cout_");
      //~ std::string str2 = std::to_string(i);
      //~ std::string str = str1 + str2;
      //~ std::string strstra = str11a + str2;
      //~ std::string strstrb = str11b + str2;
      //~ std::string strstrc = str11c + str2;
      //~ 
      //~ ecoli_->printCrowd(str);
      //~ box_->printEnvABC(strstra, Ainit_ , box_->PetriA());
      //~ box_->printEnvABC(strstrb, Ainit_ , box_->PetriB());
      //~ box_->printEnvABC(strstrc, Ainit_ , box_->PetriC());
      
      box_->recycle(Ainit_); //renewing the environment
      
    }
    this->nextStep();
    box_->writeEnvABC();
    ecoli_->writeCrowdABC();
    std::string str1 = std::string("PetriBox_");
    //~ std::string str11a = std::string("Aout_");
    //~ std::string str11b = std::string("Bout_");
    //~ std::string str11c = std::string("Cout_");
    std::string str2 = std::to_string(i);
    std::string str = str1 + str2;
    //~ std::string strstra = str11a + str2;
    //~ std::string strstrb = str11b + str2;
    //~ std::string strstrc = str11c + str2;
      
    //~ ecoli_->printCrowd(str);
    //~ box_->printEnvABC(strstra, Ainit_ , box_->PetriA());
    //~ box_->printEnvABC(strstrb, Ainit_ , box_->PetriB());
    //~ box_->printEnvABC(strstrc, Ainit_ , box_->PetriC());
    //~ 
    ecoli_->printCrowd(str);
    cout<<"iteration "<<i<<endl;
    
	}
  //~ PRINT THE CONCENTRATIONS???? !!!!
  //~ ecoli_->printCrowd("PetriBox_End");
  
  cout<<"Finit ! ;) "<<endl;
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================


