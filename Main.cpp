#include <iostream> // defoult
#include <ctime> //random no
#include <cstdlib> // random no
#include <chrono>//sleep
#include <thread>//sleep

using namespace std;
using namespace std::this_thread;
using namespace std::chrono; // nanoseconds

//random Numbers
int randNo(int min, int max)
{
  int range = max-min+1;
  
  srand(time(NULL));
  int randno  = (rand() % range) + min;
  return randno;
}

//Base Class
class Player
{
 public:
 int mHealth;
 int inDamage; 
 int maxHeal;
 int minHeal;
 int maxAddDamage;
 int minAddDamage;
 
 int maxHealth;
 int curHealth;
 bool alive;
 //string name;
 
 public:
 virtual void setInfo()= 0;

 //Health Function
 void health()
 {
   curHealth = mHealth;
   alive = true;
 }

 //intial damage
 void inlDamage()
 {
   curHealth -= inDamage;
   if(curHealth<=0)
   {
     cout<< getPlayerType() <<"Dies\n";
     alive = false;
     curHealth = 0; 
   }
   else
   {
     cout<<getPlayerType() <<"got intial Damage by "<<inDamage<<"points\n";
   }
 }

 //Additional Damage
 void addDamage()
 {
   int add = randNo(minAddDamage,maxAddDamage);
   curHealth -= add;
   if(curHealth<=0)
   {
     cout<< getPlayerType() <<"Dies\n";
     alive = false;
     curHealth = 0; 
   }
   else
   {
     cout<<getPlayerType() <<"got additional damage by "<<add<<"points\n";
   }

 }
  
  //Player Damage Function
  void damagePlayer()
  {
    inlDamage();
    addDamage();
  }

  //heal Function
  void healPlayer()
  {
    int heal = randNo(minHeal, maxHeal);
    curHealth += heal;

    if(curHealth>=mHealth)
    {
      curHealth = mHealth;
      cout<<getPlayerType()<<"you Have full Health\n";
    }
    else
    {
     cout<<getPlayerType() <<"is healed by"<<heal<<"points\n";
    }
  }

 //Player Type
 virtual string getPlayerType()
 {
   return "Base Player";
 }

 //DisplayHealth
 void displayHealth()
 {
   if(curHealth>0)
   {
     cout<<getPlayerType()<<"has Health :"<<curHealth<<"\n";
   }
 }

 bool playerAlive()
 {
   return alive;
 }
};

class Powerful : public Player
{
 public:
 string getPlayerType()
 {
   return "Powerful Player";
 }
 void setInfo()
 {
   mHealth = 100;
   inDamage =30;
   minHeal = 5;
   maxHeal =15;
   minAddDamage = 8;
   maxAddDamage = 18;
   health();

   //Printing Player Stats-----------
   
   cout<<"Your Player Stats\n"<<"Type : "<<getPlayerType()<<"\nHealth : "<<mHealth<<"\nDamage : "<<inDamage<<"\nHeal : "<<minHeal<<" -"<<maxHeal<<"\nAditional Damage :"<<minAddDamage<<"-"<<maxAddDamage<<endl;
 }
};

class Skillful : public Player
{
 public:
 string getPlayerType()
 {
   return "Skillful Player";
 }
 void setInfo()
 {
   mHealth = 75;
   inDamage =20;
   minHeal = 2;
   maxHeal =12;
   minAddDamage = 5;
   maxAddDamage = 15;
   health();

   //Printing Player Stats-----------
   
   cout<<"Your Player Stats\n"<<"Type : "<<getPlayerType()<<"\nHealth : "<<mHealth<<"\nDamage : "<<inDamage<<"\nHeal : "<<minHeal<<" -"<<maxHeal<<"\nAditional Damage :"<<minAddDamage<<"-"<<maxAddDamage<<endl;
 }
};

class Raged : public Player
{
 public:
 string getPlayerType()
 {
   return "Raged Player";
 }
 void setInfo()
 {
   mHealth = 50;
   inDamage =10;
   minHeal = 1;
   maxHeal =10;
   minAddDamage = 5;
   maxAddDamage = 15;
   health();

   //Printing Player Stats-----------
   
   cout<<"Your Player Stats\n"<<"Type : "<<getPlayerType()<<"\nHealth : "<<mHealth<<"\nDamage : "<<inDamage<<"\nHeal : "<<minHeal<<" -"<<maxHeal<<"\nAditional Damage :"<<minAddDamage<<"-"<<maxAddDamage<<endl;
 }
};


 Player*  selectPlayer()
 {
   Player* player;
   int n;
   cin>>n;
  
   if(n == 1)
    {
      cout<<"You Selected Powerful Player\n";
      player = new Powerful();
      player->setInfo();
    }
   else if( n ==2)
    {
      cout<<"You Selected skillfull Player\n";
      player = new Skillful();
      player->setInfo();
    }
   else if( n ==3)
    {
      cout<<"You Selected Raged Player\n";
      player = new Raged();
      player->setInfo();
    }
   else
    {
      cout<<"You Selected Powerful Player\n";
      player = new Powerful();
      player->setInfo();
    }
    return player;
 }
 
 //Play Function
 void play(Player* plr, Player* enmy)
 {
   char plrInput;
   cout<<"\nPress D to damage and Press H to heal : ";
   cin>>plrInput;

   switch(plrInput)
   {
     case 'd':
     enmy->damagePlayer();
     enmy->displayHealth();
     break;

     case 'h':
     plr->healPlayer();
     plr->displayHealth();
     break;

     default:
     cout<<"Please choose b/w d & h";
   }
 }

int main()
{
  cout<<"Lets Play a Game\n";

  cout<<"Player 1 select no b/w 1 to 3\n";
  Player* p1 = selectPlayer();

  cout<<"\nPlayer 2 select no b/w 1 to 3\n"; 
  Player* p2 = selectPlayer();

  int plrTurn = 1;
  bool gamecontinue = true;
  do
  {
    if(plrTurn == 1)
    {
      cout<<"Player 1 ("<<p1->getPlayerType()<<") It's your Turn\n";
      play(p1,p2);
    }
    else
    {
      cout<<"Player 2 ("<<p2->getPlayerType()<<") It's your Turn\n";
      play(p2,p1);
    }

    plrTurn = plrTurn == 1?2:1;
    if(p1->playerAlive() && p2->playerAlive())
    {
      gamecontinue= true;
    }
    else if(!p1->playerAlive())
    {
      cout<<"Congragulation player 2 You won the Game\n";
      gamecontinue = false;
    }
    else if(!p2->playerAlive())
    {
      cout<<"Congragulation player 1 You won the Game\n";
      gamecontinue = false;
    }
    
  } while(gamecontinue);

   //delete p1;
   // delete p2;
  
}
