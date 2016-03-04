
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
  
  Crowdy_=nullptr;
}

//Constructeur par copie 
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
  Crowdy_ = nullptr;
  }
  
// ===========================================================================
//                               Public Methods
// ===========================================================================

//Method to print the table
void Crowd::printCrowd(std::string str){	
	
  int** tab = new int*[Length_];
  for (int i=0;i<Length_;i++){
    tab[i]=new int[Width_];
    for (int j=0;j<Width_;j++){
      if (Crowdy_[i][j].alive()){
        tab[i][j]=Crowdy_[i][j].G()+1;
      }
      else {tab[i][j]=0;}
    }
  };

  Image ima(int(Length_),int(Width_) ,tab,0);
  ima.save(str);
  
  for (int i=0; i<Length_;i++){
    delete[] tab[i];
  }
  delete[] tab;
  tab = nullptr;
}

void Crowd::writeCrowdABC(){	
	
  double taba = 0;
  double tabb = 0;
  double tabc = 0;
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      taba+=Crowdy_[i][j].A();
      tabb+=Crowdy_[i][j].B();
      tabc+=Crowdy_[i][j].C();
    }
  };

  ofstream fa;
  ofstream fb;
  ofstream fc;
  
  fa.open("Ain.txt",ios::out|ios::app);
  fa<<taba/double(Length_*Width_)<<endl;
  fa.close();
  
  fb.open("Bin.txt",ios::out|ios::app);
  fb<<tabb/double(Length_*Width_)<<endl;
  fb.close();

  fc.open("Cin.txt",ios::out|ios::app);
  fc<<tabc/double(Length_*Width_)<<endl;
  fc.close();
}
//Method to print the table
//~ void Crowd::printCrowdA(std::string str, double Ainit){	
	//~ 
  //~ int** tab = new int*[Length_];
  //~ for (int i=0;i<Length_;i++){
    //~ tab[i]=new int[Width_];
    //~ for (int j=0;j<Width_;j++){
      //~ if (Crowdy_[i][j].alive()){
        //~ tab[i][j]=Crowdy_[i][j].A()+1;
      //~ }
      //~ else {tab[i][j]=0;}
    //~ }
  //~ };
//~ 
  //~ Image ima(int(Length_),int(Width_) ,tab,1);
  //~ ima.save(str);
  //~ 
  //~ for (int i=0; i<Length_;i++){
    //~ delete[] tab[i];
  //~ }
  //~ delete[] tab;
  //~ tab = nullptr;
//~ }


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
      Crowdy_[i][j].massacre(Pdeath);
    }
  };
}  

void Crowd::fited(double Wmin){
  //srand(time(NULL));
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
      Crowdy_[i][j].fitness(Wmin);
    }
  };
}  

bool Crowd::aliveTest(Individual ind){
  return ind.alive();
}

Individual Crowd::sides(int x, int y){

  if (x < 0){x = (Length_-1);}
  else if (x >= Length_){x = 0;}
  
  if (y < 0){y = (Width_-1);}
  else if (y >= Width_){y = 0;}
    
  if (this->aliveTest(Crowdy_[x][y])){
    return Crowdy_[x][y];
  }
  
  else{
    Individual dead = Individual();
    dead.massacre(1.);
    return dead;}// FIND ANOTHER WAY !!!!!!!!!!!!!
}

std::vector<Individual> Crowd::checkSides(Individual hole){
  // DO WE TAKE THE DIAGONALS TOO ???????????????????????????????????????????????????
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

Individual Crowd::findWmaxi(Individual hole){ // put a individual, hole
  // take sides !!! add a if for the ones that are on boards
  // return random
  // add SOMTHING SPECIAL IF NO NEIGHBOUR

  std::vector<Individual> Sides = this->checkSides(hole);
  double max = Sides[0].w();
  Individual Indmax = Sides[0];
  std::vector<Individual> VIndmax;
  int count = 1;

  for (int i = 0; i < int(Sides.size()); i++){
    if (this->aliveTest(Sides[i])){
      if (Sides[i].w() > max){
        max = Sides[i].w();
        Indmax = Sides[i];
      }
    }
  }
 
  for (int i = 0; i < int(Sides.size()); i++){
    if (this->aliveTest(Sides[i])){
      if (Sides[i].w() == max){
        Indmax = Sides[i];
        VIndmax.push_back(Indmax);
        count++;
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

std::vector<Individual> Crowd::listHoles(){
  //srand(time(NULL)); 
  //parcourir list
  //put a list of all the holes
  
  int Count = 0;
  std::vector<Individual> v;  
    
  for (int i=0;i<Length_;i++){
    for (int j=0;j<Width_;j++){
	    if (Crowdy_[i][j].alive()==0){
	      Count++;
        v.push_back(Crowdy_[i][j]);
      }
    }
  };

  if (Count==0){
    v.push_back(Individual());//FIND ANOTHER WAY !!!!!!!!!!!!!
  }
  return v;
}


void Crowd::duplication(double Wmin){ // mettre list en argument//take random in list
  
  std::vector<Individual> v = this->listHoles();
  while (v.size()!=0){
    int i = rand()%(int(v.size())-0) + 0 ;  
    
    if (not this->aliveTest(v[i])){
      Individual Parent = this->findWmaxi(v[i]);
      if (Parent.w()!=0){
        

        Parent.parent(Wmin);  //remove WMIN !!!

      
        Crowdy_[v[i].x()][v[i].y()].baby(Parent);
      }
    }
    v.erase(v.begin()+i);
  }
}


// ===========================================================================
//                              Protected Methods
// ===========================================================================


