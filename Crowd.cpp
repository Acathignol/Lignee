
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Crowd.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  
// ===========================================================================
//                                Constructors
// ===========================================================================
//Constructeur par défaut
Crowd::Crowd() {
  Length_ = 0;
  Width_ = 0;
  
  Crowdy_=new Individual*[Length_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j]=Individual();
    }
  };
}

//Constructeur par copie 
Crowd::Crowd(const Crowd& Copy) {
  Length_ = Copy.Length();
  Width_ = Copy.Width();
  
  Crowdy_=new Individual*[Length_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j]= Copy.Crowdy()[i][j];
    }
  };
}


//constructor with a length and a width , also x and y init
Crowd::Crowd(int l, int w) {
  Length_ = l;
  Width_ = w;
  
  Crowdy_=new Individual*[Length_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j]=Individual(i,j);
    }
  };
}


// ===========================================================================
//                                 Destructor
// ===========================================================================
Crowd::~Crowd(){
  for (int i=0; i<Length_;i++){
    delete[] Crowdy_[i];
  }
  delete[] Crowdy_;
  }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================
void Crowd::muted (double Pmut){
  //srand(time(NULL));
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j].mutation(Pmut);
    }
  };
}  

void Crowd::epickill(double Pdeath){
  //srand(time(NULL));
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j].massacre(Pmut);
    }
  };
}  

void Crowd::fited(double Wmin){
  //srand(time(NULL));
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j].fitness(Pmut);
    }
  };
}  


void Crowd::findWmaxi(){// put a individual, hole
  //srand(time(NULL)); HOWWWWWWWWWWWWWWWWWWWWWw ??? how to find min(Table)
  // take sides !!! add a if for the ones that are on boards
  // return random
  Crowdy_=new Individual[Length_+Width_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	  if (Crowdy_[i][j].w()==max(Crowdy_.w());
        Crowdy_[i][j].w();
      }
    }
  };
}  

void Crowd::ListHoles(){
  //srand(time(NULL)); HOWWWWWWWWWWWWWWWWWWWWWw ??? how to find min(Table)
  //parcourir list
  //put a list of all the holes

  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    
  int Count=0
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	  if (Crowdy_[i][j].alive()==0){
	    Count++;	    
      }
    }
  };
  
  Individual* ListHoles=new Individual[count];// CHECK -1 ??????????
  
  Count=0
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	  if (Crowdy_[i][j].alive()==0){
	    ListHoles[Count]=Crowdy_[i][j].alive();	    
	    Count++;
      }
    }
  };        
}  
  
void Crowd::Duplication(){ // mettre list en argument
  //srand(time(NULL)); HOWWWWWWWWWWWWWWWWWWWWWw ??? how to find min(Table)
  //take random in list
  //
  Crowdy_=new Individual[Length_+Width_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    
    
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	  if (Crowdy_[i][j].w()==min(Crowdy_.w());
        Crowdy_[i][j].w();
      }
    }
  };
}  

//checking for post-mvmt outside
void Crowd::Mvmtout(void){
  if (x_>=L_){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (x_<0){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (y_>=L_){
      x_ = L_/4;
      y_ = L_/4;
  }
  else if (y_<0){
      x_ = L_/4;
      y_ = L_/4;
  }
}
// ===========================================================================
//                              Protected Methods
// ===========================================================================


