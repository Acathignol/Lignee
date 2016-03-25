
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Crowd.h"

// ===========================================================================
//                                Constructors
// ===========================================================================

//Default constructor (UNUSED IN MY LIFE CLASS)
Crowd::Crowd() {
  Length_ = 0;
  Width_ = 0;
  
  Crowdy_=nullptr;
}

//Copy constructor (UNUSED IN MY LIFE CLASS) 
Crowd::Crowd(const Crowd& Copy) {
  Length_ = Copy.Length_;
  Width_ = Copy.Width_;
  
  Crowdy_=new Individual*[Length_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j]= Copy.Crowdy_[i][j];
    }
  };
}

//Constructor with a length and a width , and an individual(at a position x and y given) (USED)
Crowd::Crowd(int l, int w) {
  Length_ = l;
  Width_ = w;
  
  int countA=(l*w)/2;
  int countB=(l*w)/2;
  
  Crowdy_=new Individual*[Length_];
  
  for (int i=0;i<Length_;i++){
    Crowdy_[i]=new Individual[Width_];
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j]=Individual(i,j);
      if (countA>>0 and countB>>0){
        if (Crowdy_[i][j].G()==0){countB-=1;}
        else {countA-=1;}
      }
      else if (countA==0 and countB>>0){
        Crowdy_[i][j].set_G(0);
        countB-=1;
      }
      else if (countA>>0 and countB==0){
        Crowdy_[i][j].set_G(1);
        countA-=1;
      }
        
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
  Crowdy_ = nullptr;
  }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//Method to print the table
void Crowd::printCrowd(std::string str){	
	
  //New table containing the genotype if alive (A=2 => red, B=1 => blue/green and dead=0 => black)
  int** tab = new int*[Length_];
  for (int i=0;i<Length_;i++){
    tab[i]=new int[Width_];
    for (int j=0;j<Width_;j++){
      if (Crowdy_[i][j].alive()){
        if (Crowdy_[i][j].G()==1 or Crowdy_[i][j].G()==0){
          tab[i][j]=Crowdy_[i][j].G()+1;
        }
      }
      else {tab[i][j]=0;}
    }
  };
  
  //Creating an Image of the table and saving it
  Image ima(int(Length_),int(Width_) ,tab,0);
  ima.save(str);
  
  //Deleting the table
  for (int i=0; i<Length_;i++){
    delete[] tab[i];
  }
  delete[] tab;
  tab = nullptr;
}

void Crowd::writeCrowdABC(double ainit,int Tt){	
  

  ofstream f;
  std::string strr="ConcentrationsIN.txt";//str + "Ain A.txt";
  
  double tabaA = 0.; //New double of the A concentrations' sum for the blocs where we have cells with the A genotype in the block (A out for the genotype A)
  double tabbA = 0.; //idem....
  double tabcA = 0.;
  int countA =0;
  double tabaB = 0.;
  double tabbB = 0.;
  double tabcB = 0.;
  int countB =0;
  int countDead=0;
  
  f.open(strr,ios::out|ios::app);
  
  //Copying the values 
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      if (Crowdy_[i][j].alive() and Crowdy_[i][j].G() == 1){
        //~ tabaA+=Crowdy_[i][j].A();
        //~ tabbA+=Crowdy_[i][j].B();
        //~ tabcA+=Crowdy_[i][j].C();
        countA ++;
      }
      else if (Crowdy_[i][j].alive() and Crowdy_[i][j].G() == 0){
        //~ tabaB+=Crowdy_[i][j].A();
        //~ tabbB+=Crowdy_[i][j].B();
        //~ tabcB+=Crowdy_[i][j].C();
        countB ++;
      }
      else {
        countDead ++;
        }
      if (Crowdy_[i][j].alive()){
        tabaB+=Crowdy_[i][j].A();
        tabbB+=Crowdy_[i][j].B();
        tabcB+=Crowdy_[i][j].C();
      }
    }
  };
  //Writing the files
  f<<ainit<<" "<<Tt<<" "<<countA<<" "<<tabaA<<" "
  <<tabbA<<" "<<tabcA<<" "
  <<countB<<" "<<tabaB<<" "<<tabbB
  <<" "<<tabcB<<" "<<countDead<<endl;
  f.close();
}


void Crowd::writeResult(std::string str, double ainit, int T){	

  //Writing the files
  int countA=0;
  int countB=0;  
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      if (Crowdy_[i][j].alive()){
        if (Crowdy_[i][j].G() == 0){
          countB++;}
        else if (Crowdy_[i][j].G() == 1){
          countA++;}
      }
    }
  }
      
  ofstream f;
    
  f.open(str,ios::out|ios::app);
  f<<ainit<<" "<<T<<" ";
  if (countA>>0 and countB>>0){f<<"2"<<endl;}
  else if (countA>>0 and countB==0){f<<"1"<<endl;}
  else {f<<"0"<<endl;}
  f.close();


}

//Each cell randomly dies or not (srand(time(NULL)) put in main.cpp)
void Crowd::epickill(double Pdeath){
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){ 
      if (Crowdy_[i][j].alive()){
        Crowdy_[i][j].massacre(Pdeath);
      }
    }
  };
}  

//Each cell establishes her fitness of the moment 
void Crowd::fited(double Wmin){
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      if (Crowdy_[i][j].alive()){
        Crowdy_[i][j].fitness(Wmin);
      }
    }
  };
}  

Individual Crowd::sides(int x, int y){
  //Checking the sides (Thoric conditions) and returning the appropriate individual
  if (x < 0){x = (Length_-1);}
  else if (x >= Length_){x = 0;}
  
  if (y < 0){y = (Width_-1);}
  else if (y >= Width_){y = 0;}
    
  if (Crowdy_[x][y].alive()){
    return Crowdy_[x][y];
  }
  
  else{
    Individual dead = Individual();
    dead.massacre(1.);
    return dead;}
}

std::vector<Individual> Crowd::checkSides(Individual hole){
  //Returns a vector containing each individual around the newly dead one ("hole")
  
  // WE TAKE THE DIAGONALS TOO !
  std::vector<Individual> vSides;
  
  //NORTH
  vSides.push_back(this->sides(hole.x()-1,hole.y()));
  //N-W
  vSides.push_back(this->sides(hole.x()-1,hole.y()-1));
  //N-E
  vSides.push_back(this->sides(hole.x()-1,hole.y()+1));
  //SOUTH
  vSides.push_back(this->sides(hole.x()+1,hole.y()));
  //S-W
  vSides.push_back(this->sides(hole.x()+1,hole.y()-1));
  //S-E
  vSides.push_back(this->sides(hole.x()+1,hole.y()+1));
  //WEST
  vSides.push_back(this->sides(hole.x(),hole.y()-1));
  //EST
  vSides.push_back(this->sides(hole.x(),hole.y()+1));
  
  return vSides;
}

Individual Crowd::findWmaxi(Individual hole,std::vector<Individual> v1){ // put a dead individual, hole, as an argument
  // takes sides !!! add a if for the ones that are on boards
  // returns random
  // adds SOMTHING SPECIAL IF NO NEIGHBOURS
  
  std::vector<Individual> Sides = this->checkSides(hole);
  for (int j = 0; j < int(v1.size()); j++){
    for (int i = 0; i < int(Sides.size()); i++){
      if (Sides[i].alive() and Sides[i].x()==v1[j].x() and Sides[i].y()==v1[j].y()){// faire un vecteur copy de sides et comparer à lui! !!!!!!!!!!!!!!!!!!!!!!!!!
        Sides.erase(Sides.begin()+i);
      }
    }
  }
  
  double max = Sides[0].w();
  Individual Indmax = Sides[0];
  std::vector<Individual> VIndmax;
  
  //Searching the maximum fitness of all 
  for (int i = 0; i < int(Sides.size()); i++){
    if (Sides[i].alive()){
      if (Sides[i].w() > max){
        max = Sides[i].w();
      }
    }
  }
  
  //If there is multiple cells around the dead which have the same max. fitness:
  // First we put them all, them we choose randomly one
  for (int i = 0; i < int(Sides.size()); i++){
    if (Sides[i].alive()){
      if (Sides[i].w() == max){
        Indmax = Sides[i];
        VIndmax.push_back(Indmax);// Faire un new indiv. et l'ajouter dans le vect!
      }
    }
  }
  
  if (int(VIndmax.size())==1){
    return VIndmax[0];
  }
  else if (int(VIndmax.size())>1) {
    int i = rand()%(int(VIndmax.size())-0) + 0 ;
    return VIndmax[i];
  }
  else {return hole;}
}

std::vector<Individual> Crowd::listDeads(){
  //(srand(time(NULL)) put in main.cpp) 
  //parcourir list
  //put a list of all the holes
  
  int Count = 0;
  std::vector<Individual> v;  
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	    if (Crowdy_[i][j].alive()==0 and Crowdy_[i][j].G()!=69){
	      Count++;
        v.push_back(Crowdy_[i][j]);
      }
    }
  };

  if (Count==0){
    v.push_back(Individual());
  }
  return v;
}

std::vector<Individual> Crowd::listHoles(){
  //(srand(time(NULL)) put in main.cpp) 
  //parcourir list
  //put a list of all the holes
  
  int Count = 0;
  std::vector<Individual> v;  
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	    if (Crowdy_[i][j].G()==69){
	      Count++;
        v.push_back(Crowdy_[i][j]);
      }
    }
  };

  if (Count==0){
    v.push_back(Individual());
  }
  return v;
}

//Duplication
void Crowd::duplication(double Wmin, double Pmut){ 
  Individual Parent;
  std::vector<Individual> v = this->listHoles(); 
  std::vector<Individual> v1; 
  
  //obtaining a list of all the holes in the map
  while (v.size()!=0){ 
    //while the list is not empty, continuing
    int i = rand()%(int(v.size())-0) + 0 ;
    //taking a random "i" which is a place in the list  
    
    if (not v[i].alive()){
      //if the place in the list is really dead (if no one is dead)
      Parent = this->findWmaxi(v[i], v1);
      //for the place in the list, finding the individual alive with the highest fitness (w) around (Parent)
      if (Parent.w()!=0 and Parent.alive()){
        
        Crowdy_[Parent.x()][Parent.y()].parent(Wmin);
        //Dividing the concentration by 2 to have the future concentrations

        Crowdy_[v[i].x()][v[i].y()].baby(Crowdy_[Parent.x()][Parent.y()]);
        Crowdy_[v[i].x()][v[i].y()].mutation(Pmut);
        Crowdy_[Parent.x()][Parent.y()].mutation(Pmut);
        
        v1.push_back(Crowdy_[Parent.x()][Parent.y()]);
        v1.push_back(Crowdy_[v[i].x()][v[i].y()]);
        
        //Copying the parent to the dead place => new baby alive
      }
    }
    v.erase(v.begin()+i);
    //deleting the individual taken randomly in the list
  }
  
}
// RAJOUTER => PARENT PEUVENT PLUS SE DIVISER ET LES NOUVEAUX NES NON PLUS

