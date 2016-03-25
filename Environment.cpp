// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Environment.h"

// ===========================================================================
//                                Constructors
// ===========================================================================

//Default constructor (UNUSED IN MY LIFE CLASS)
Environment::Environment() {
  Length_ = 0;
  Width_ = 0;
  
  PetriA_=new double*[Length_];
  PetriB_=new double*[Length_];
  PetriC_=new double*[Length_];
  
  for (int i=0;i<Length_;i++){
    PetriA_[i]=new double[Width_];
    PetriB_[i]=new double[Width_];
    PetriC_[i]=new double[Width_];
    for (int j=0;j<Width_;j++){
      PetriA_[i][j]=0.;
      PetriB_[i][j]=0.;
      PetriC_[i][j]=0.;
    }
  };
}

//Copy constructor (UNUSED IN MY LIFE CLASS) 
Environment::Environment(const Environment& Copy) {
  Length_ = Copy.Length_;
  Width_ = Copy.Width_; 
  
  PetriA_=new double*[Length_];
  PetriB_=new double*[Length_];
  PetriC_=new double*[Length_];
  
  for (int i=0;i<Length_;i++){
    PetriA_[i]=new double[Width_];
    PetriB_[i]=new double[Width_];
    PetriC_[i]=new double[Width_];
    for (int j=0;j<Width_;j++){
      PetriA_[i][j]= Copy.PetriA()[i][j];
      PetriB_[i][j]= Copy.PetriB()[i][j];
      PetriC_[i][j]= Copy.PetriC()[i][j];
    }
  };
}

//Constructor with a length, a width and a initial concentration in A (USED)
Environment::Environment(int l, int w, double Ainit) {
  Length_ = l;
  Width_ = w;
  
  PetriA_=new double*[Length_];
  PetriB_=new double*[Length_];
  PetriC_=new double*[Length_];
  //double a=0.;
  //double b=0.;
  
  for (int i=0;i<Length_;i++){
    PetriA_[i]=new double[Width_];
    PetriB_[i]=new double[Width_];
    PetriC_[i]=new double[Width_];
    
    for (int j=0;j<Width_;j++){
      PetriA_[i][j]=Ainit;
      PetriB_[i][j]=0.;
      PetriC_[i][j]=0.;
      //a+=PetriA_[i][j];
      //b+=Ainit;
    }
  };
  //cout<<a<<" "<<b<<endl;
}



// ===========================================================================
//                                 Destructor
// ===========================================================================
Environment::~Environment(){
  for (int i=0; i<Length_;i++){
    delete[] PetriA_[i];
    delete[] PetriB_[i];
    delete[] PetriC_[i];
  }
  delete[] PetriA_;
  delete[] PetriB_;
  delete[] PetriC_;
  
  PetriA_ = nullptr;
  PetriB_ = nullptr;
  PetriC_ = nullptr;
  }
  
  
  
// ===========================================================================
//                               Public Methods
// ===========================================================================
//IF A METHOD IS NOT USED IN MAIN => I HAVE TO PUT IT PROTECTED!!
void Environment::writeA(double ainit){
  double a=0.;
  double b=0.;
  
  for (int i=0;i<Length_;i++){    
    for (int j=0;j<Width_;j++){
      a+=PetriA_[i][j];
      b+=ainit;
    }
  };
  cout<<a<<" "<<b<<endl;
}	



void Environment::writeEnvABC(double& ainit,int& Tt, Individual** cr){	
  
  ofstream f;
  std::string strr="ConcentrationsOUT.txt";
  
  double tabaA = 0.; //New double of the A concentrations' sum for the blocs where we have cells with the A genotype in the block (A out for the genotype A)
  double tabbA = 0.; //idem....
  double tabcA = 0.;
  int countA =0;
  double tabaB = 0.;
  double tabbB = 0.;
  double tabcB = 0.;
  int countB =0;
  double tabaDead = 0.;
  double tabbDead = 0.;
  double tabcDead = 0.;
  int countDead=0;
  
  f.open(strr,ios::out|ios::app);
  
  //Copying the values 
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      if (cr[i][j].alive() and cr[i][j].G() == 1){
        //~ tabaA+=PetriA_[i][j];
        //~ tabbA+=PetriB_[i][j];
        //~ tabcA+=PetriC_[i][j];
        countA ++;
      }
      else if (cr[i][j].alive() and cr[i][j].G() == 0){
        //~ tabaB+=PetriA_[i][j];
        //~ tabbB+=PetriB_[i][j];
        //~ tabcB+=PetriC_[i][j];
        countB ++;
      }
      else {
        //~ tabaDead+=PetriA_[i][j];
        //~ tabbDead+=PetriB_[i][j];
        //~ tabcDead+=PetriC_[i][j];
        countDead ++;
      }
      tabaA+=PetriA_[i][j];
      tabbA+=PetriB_[i][j];
      tabcA+=PetriC_[i][j];
    }
  };
  //Writing the files
  f<<ainit<<" "<<Tt<<" "<<countA<<" "<<tabaA<<" "
  <<tabbA<<" "<<tabcA<<" "
  <<countB<<" "<<tabaB<<" "<<tabbB<<" "
  <<tabcB<<" "<<countDead<<" "<<tabaDead<<" "
  <<tabbDead<<" "<<tabcDead<<" "<<endl;
  f.close();
}

int Environment::sides(int xy, int LW){ 
  // To do the toric conditions
  // Put an x or an y and the corresponding side (length or width)

  if (xy < 0){xy = (LW-1);}
  else if (xy >= LW){xy = 0;}
  // if the x or y is inferior to 0 
  //=> the x or y = the side -1 (the opposite side of the table)
  
  return xy; //return the x or y newly (or not) calculated
}

void Environment::diffusion(double D){
  //Copying the old table
  double** CA_=new double*[Length_];
  double** CB_=new double*[Length_];
  double** CC_=new double*[Length_];
  
  for (int x=0;x<Length_;x++){
    CA_[x]=new double[Width_];
    CB_[x]=new double[Width_];
    CC_[x]=new double[Width_];
    
    
    for (int y=0;y<Width_;y++){
      CA_[x][y]=PetriA_[x][y];
      CB_[x][y]=PetriB_[x][y];
      CC_[x][y]=PetriC_[x][y];
      
      
      //Diffusion
      for (int i=(-1) ; i<=1 ; i++){
        for (int j=(-1) ; j<=1 ; j++){
          int x2 = this->sides(x+i, Length_);
          int y2 = this->sides(y+j, Width_);
    		  CA_[x][y] += D*PetriA_[x2][y2];
          CB_[x][y] += D*PetriB_[x2][y2];
          CC_[x][y] += D*PetriC_[x2][y2];
          
        }
      } 	
      CA_[x][y] -= 9*D*PetriA_[x][y];
      CB_[x][y] -= 9*D*PetriB_[x][y];
      CC_[x][y] -= 9*D*PetriC_[x][y];
    }
    //Deleting the old table
  }    
  
  for (int x=0;x<Length_;x++){
    delete[] PetriA_[x];
    delete[] PetriB_[x];
    delete[] PetriC_[x];
  }
  delete[] PetriA_;
  delete[] PetriB_;
  delete[] PetriC_;
  
  //Pointing to the new ones
  PetriA_ = CA_;
  PetriB_ = CB_;
  PetriC_ = CC_;
}  

void Environment::recycle(double Ainit){
  //Deleting thea old concentrations out of the celles and renewing them!
  //It's like a renewal of the environment concentrations
  for (int i=0; i<Length_;i++){
    for (int j=0; j<Width_;j++){
	    PetriA_[i][j]=Ainit;
	    PetriB_[i][j]=0.;
	    PetriC_[i][j]=0.;
	  }
  }
}

