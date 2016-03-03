// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Environment.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================
//Constructeur par défaut
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
      PetriA_[i][j]=0;
      PetriB_[i][j]=0;
      PetriC_[i][j]=0;
    }
  };
}

//Constructeur par copie 
Environment::Environment(const Environment& Copy) {
  Length_ = Copy.Length();
  Width_ = Copy.Width();
  
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


//constructor with a length and a width , also x and y init
Environment::Environment(int l, int w, double Ainit) {
  Length_ = l;
  Width_ = w;
  
  PetriA_=new double*[Length_];
  PetriB_=new double*[Length_];
  PetriC_=new double*[Length_];
  
  for (int i=0;i<Length_;i++){
    PetriA_[i]=new double[Width_];
    PetriB_[i]=new double[Width_];
    PetriC_[i]=new double[Width_];
    for (int j=0;j<Width_;j++){

      PetriA_[i][j]=Ainit;
      PetriB_[i][j]=0.;
      PetriC_[i][j]=0.;
    }
  };
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

//IF NOT USES IN MAIN => PROTECTED!!
void Environment::diffusion(double D){
  Environment Copy = Environment(*this);
  
  for (int x=0;x<Length_;x++){
    for (int y=0;y<Width_;y++){
      for (int i=-1 ; i>=2 ; i++){
        for (int j=-1 ; j>=2 ; j++){
		  PetriA_[x][y]=PetriA_[x][y]+D*Copy.PetriA()[x+i][y+j];
          PetriB_[x][y]=PetriB_[x][y]+D*Copy.PetriB()[x+i][y+j];
          PetriC_[x][y]=PetriC_[x][y]+D*Copy.PetriC()[x+i][y+j];
        }
      } 		
      PetriA_[x][y]=PetriA_[x][y]-9*D*Copy.PetriA()[x][y];
      PetriB_[x][y]=PetriB_[x][y]-9*D*Copy.PetriB()[x][y];
      PetriC_[x][y]=PetriC_[x][y]-9*D*Copy.PetriC()[x][y];
    }
  }    
}  

void Environment::recycle(double Ainit){
  //delete old and renew  !
  for (int i=0; i<Length_;i++){
    for (int j=0; j<Width_;j++){
	  PetriA_[i][j]=Ainit;
	  PetriB_[i][j]=0.;
	  PetriC_[i][j]=0.;
	}
  }
}
// ===========================================================================
//                              Protected Methods
// ===========================================================================

