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
//IF A METHOD IS NOT USED IN MAIN => I HAVE TO PUT IT PROTECTED!!

// DOESN'T WORK BUT UNUSEFULL FOR NOW : 
/**
 * //Method to print the table 
 * void Environment::printEnvABC(std::string str, double Ainit , double** X){	
 * int** tab = new int*[Length_];
 * for (int i=0;i<Length_;i++){
 *  tab[i]=new int[Width_];
 *  for (int j=0;j<Width_;j++){
 *    //cout<<X[i][j]<<endl;
 *    tab[i][j]=(X[i][j]*255/Ainit);
 *  }
 * };
 * 
 * Image ima(int(Length_),int(Width_) ,tab,1);
 * ima.save(str);
 * 
 * for (int i=0; i<Length_;i++){
 *  delete[] tab[i];
 * }
 * delete[] tab;
 * tab = nullptr;
 * }
 */

void Environment::writeEnvABC(std::string str, Individual** cr){	
  /**
  //OLD WAY TO DO : UNUSEFULL FOR NOW
  //~ double taba = 0.;
  //~ double tabb = 0.;
  //~ double tabc = 0.;
  //~ for (int i=0;i<Length_;i++){
    //~ for (int j=0;j<Width_;j++){
      //~ taba+=PetriA_[i][j];
      //~ tabb+=PetriB_[i][j];
      //~ tabc+=PetriC_[i][j];
    //~ }
  //~ };
//~ 
  //~ ofstream fa;
  //~ ofstream fb;
  //~ ofstream fc;
  //~ 
  //~ fa.open("Aout.txt",ios::out|ios::app);
  //~ fa<<taba/double(Length_*Width_)<<endl;
  //~ fa.close();
  //~ 
  //~ fb.open("Bout.txt",ios::out|ios::app);
  //~ fb<<tabb/double(Length_*Width_)<<endl;
  //~ fb.close();
//~ 
  //~ fc.open("Cout.txt",ios::out|ios::app);
  //~ fc<<tabc/double(Length_*Width_)<<endl;
  //~ fc.close();
  */
  
  //NEW WAY TO DO :
  double tabaA = 0.; //New double of the A concentrations' sum for the blocs where we have cells with the A genotype in the block (A out for the genotype A)
  double tabbA = 0.; //idem....
  double tabcA = 0.;
  double tabaB = 0.;
  double tabbB = 0.;
  double tabcB = 0.;
  

  //Copying the values 
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      if (cr[i][j].G() == 1){
        tabaA+=PetriA_[i][j];
        tabbA+=PetriB_[i][j];
        tabcA+=PetriC_[i][j];
      }
      if (cr[i][j].G() == 0){
        tabaB+=PetriA_[i][j];
        tabbB+=PetriB_[i][j];
        tabcB+=PetriC_[i][j];
      }
    }
  };

  //Writing the files
  
  ofstream faA;
  ofstream fbA;
  ofstream fcA;
  
  std::string strr=str + "Aout A.txt";
  
  faA.open(strr,ios::out|ios::app);
  faA<<tabaA/double(Length_*Width_)<<endl;
  faA.close();
  
  strr=str + "Bout A.txt";
  
  fbA.open(strr,ios::out|ios::app);//"Bin.txt"
  fbA<<tabbA/double(Length_*Width_)<<endl;
  fbA.close();

  strr=str + "Cout A.txt";
  
  //~ cout<<tabc<<endl;
  fcA.open(strr,ios::out|ios::app);
  fcA<<tabcA/double(Length_*Width_)<<endl;
  fcA.close();

  ofstream faB;
  ofstream fbB;
  ofstream fcB;
  
  
  strr=str + "Aout B.txt";
  
  faB.open(strr,ios::out|ios::app);
  faB<<tabaB/double(Length_*Width_)<<endl;
  faB.close();
  
  
  strr=str + "Bout B.txt";
  
  fbB.open(strr,ios::out|ios::app);//"Bin.txt"
  fbB<<tabbB/double(Length_*Width_)<<endl;
  fbB.close();

  strr=str + "Cout B.txt";
  
  //~ cout<<tabc<<endl;
  fcB.open(strr,ios::out|ios::app);
  fcB<<tabcB/double(Length_*Width_)<<endl;
  fcB.close();
  
}

int Environment::sides(int xy, int LW){ 
  // To do the toric conditions
  // Put an x or an y and the corresponding side (length or width)

  if (xy < 0){xy = (LW-1);}
  // if the x or y is inferior to 0 
  //=> the x or y = the side -1 (the opposite side of the table)
  else if (xy >= LW){xy = 0;}
  // if the x or y is superior to the side -1 
  //=> the x or y = 0 (the opposite side of the table)
  
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
        //~ printf("AAA");
        for (int j=(-1) ; j<=1 ; j++){
          int x2 = this->sides(x+i, Length_);
          int y2 = this->sides(y+j, Width_);
          //~ printf("BBB");
    		  CA_[x][y] += D*PetriA_[x2][y2];
          CB_[x][y] += D*PetriB_[x2][y2];
          CC_[x][y] += D*PetriC_[x2][y2];
          //~ cout<<x2<<endl;
          
        }
      } 	
      CA_[x][y] -= 9*D*PetriA_[x][y];
      CB_[x][y] -= 9*D*PetriB_[x][y];
      CC_[x][y] -= 9*D*PetriC_[x][y];
    }
    //Deleting the old table
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
  //Deleting the old concentrations out of the celles and renewing them!
  //It's like a renewal of the environment concentrations
  for (int i=0; i<Length_;i++){
    for (int j=0; j<Width_;j++){
	    PetriA_[i][j]=Ainit;
	    PetriB_[i][j]=0.;
	    PetriC_[i][j]=0.;
	  }
  }
}

