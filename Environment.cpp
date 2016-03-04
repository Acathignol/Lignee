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
  Length_ = Copy.Length_;
  Width_ = Copy.Width_; //posssible???????????????????????????????????????????? ou getter?
  
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
//Method to print the table
void Environment::printEnvABC(std::string str, double Ainit , double** X){	
	
  int** tab = new int*[Length_];
  for (int i=0;i<Length_;i++){
    tab[i]=new int[Width_];
    for (int j=0;j<Width_;j++){
      //~ cout<<X[i][j]<<endl;
      tab[i][j]=(X[i][j]/Ainit);
    }
  };

  Image ima(int(Length_),int(Width_) ,tab,1);
  ima.save(str);
  
  for (int i=0; i<Length_;i++){
    delete[] tab[i];
  }
  delete[] tab;
  tab = nullptr;
}

void Environment::writeEnvABC(){	

  double taba = 0;
  double tabb = 0;
  double tabc = 0;
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      taba+=PetriA_[i][j];
      tabb+=PetriB_[i][j];
      tabc+=PetriC_[i][j];
    }
  };

  ofstream fa;
  ofstream fb;
  ofstream fc;
  
  fa.open("Aout.txt",ios::out|ios::app);
  fa<<taba/double(Length_*Width_)<<endl;
  fa.close();
  
  fb.open("Bout.txt",ios::out|ios::app);
  fb<<tabb/double(Length_*Width_)<<endl;
  fb.close();

  fc.open("Cout.txt",ios::out|ios::app);
  fc<<tabc/double(Length_*Width_)<<endl;
  fc.close();
}

int Environment::sides(int xy, int LW){

  if (xy < 0){xy = (LW-1);}
  else if (xy >= LW){xy = 0;}

  return xy;
}

//IF NOT USES IN MAIN => PROTECTED!!
void Environment::diffusion(double D){
  double** CA_=new double*[Length_];
  double** CB_=new double*[Length_];
  double** CC_=new double*[Length_];
  for (int i=0;i<Length_;i++){
    CA_[i]=new double[Width_];
    CB_[i]=new double[Width_];
    CC_[i]=new double[Width_];
    for (int j=0;j<Width_;j++){

      CA_[i][j]=PetriA_[i][j];
      CB_[i][j]=PetriB_[i][j];
      CC_[i][j]=PetriC_[i][j];
    }
  };
  for (int x=0;x<Length_;x++){
    for (int y=0;y<Width_;y++){
      for (int i=-1 ; i>=2 ; i++){
        for (int j=-1 ; j>=2 ; j++){
          int x2 = x+i;
          int y2 = y+j;
          
          x2 = this->sides(x2, Length_);
          y2 = this->sides(y2, Width_);
          
    		  CA_[i][j] += D*PetriA_[x2][y2];
          CB_[x][y] += D*PetriB_[x2][y2];
          CC_[x][y] += D*PetriC_[x2][y2];
        }
      } 		
      CA_[x][y] -= 9*D*PetriA_[x][y];
      CB_[x][y] -= 9*D*PetriB_[x][y];
      CC_[x][y] -= 9*D*PetriC_[x][y];
    }
  }    
  for (int i=0; i<Length_;i++){
    delete[] PetriA_[i];
    delete[] PetriB_[i];
    delete[] PetriC_[i];
  }
  delete[] PetriA_;
  delete[] PetriB_;
  delete[] PetriC_;
  
  PetriA_ = CA_;
  PetriB_ = CB_;
  PetriC_ = CC_;
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

