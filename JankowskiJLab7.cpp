
/*
Josef Jankowski
CSPC 121 Lab 7
Due: 12/03/18
*/



#include <iostream>
#include <stdlib.h> //random
#include <time.h> //time
using namespace std;

//#pragma once
#include <string>
//Fighter in the ring

class Gladiator {
private:
	int dmgMin,//The lowest amount of damage a gladiator can inflict with a successful attack
		dmgRange,//The most damage ABOVE Minimum Damage that the gladiator can inflict with a single, non-critical hit
		evasion, //The % chance (0-100) that the gladiator will completely avoid incoming damage when defending
		critical,//The % chance (0-100) that the gladiator will inflict twice (2x) the rolled damage when attacking the opponent (known as a crit)
		maxHealth,//The amount of HP a gladiator will start each fight with
		curHealth;//The amount of HP a gladiator has left before they have died and lost the fight

public:
	//How the gladiator is referenced to the user, provided somehow in the constructor
	string name;

	//Called upon creation; prevent any uninitialized values from being available
  Gladiator(){}
	Gladiator(string n);//Constructor
				//Use this to obtain all information on our gladiators, including their name.
				//Confirmation of the created gladiator is permitted but NOT required.

	//Accessor for health
	int getCurHealth();

	//Calculates a damage roll based on dmgMin, dmgRange, and crit
	//This would be a good place to display a crit notification
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();//you're responsible for defining this function

	//Hint: Evasion should be calculated here
	bool takeDamage(int dmgAmt);//Returns whether the gladiator was killed by the damage or not
};

Gladiator::Gladiator(string n){
  name = n;
   cout<<"\nGladiator " << n <<" created.\n";

   //mathed out the values
    dmgMin = (rand()%6)+9;
    dmgRange = (rand()%6) + 17;
    evasion = 5 *  ((rand() % 3)+1);
    critical = 5 *  ((rand() % 3)+1);
    maxHealth = ((rand() % 3)+3) * 50;
    curHealth = maxHealth;

}

int Gladiator::rollDamage(){
  int dmgAmt = dmgMin; //default alue to min

  dmgAmt = dmgMin + (rand()%dmgRange); //random value from range added to min

  //checks for critical
  if((rand() % 100)<= critical){
    dmgAmt *= 2;
    cout << "\n" <<name <<" has a crit!! (double damage)"<<endl;
  }



  return dmgAmt;
}

bool Gladiator::takeDamage(int dmgAmt){
  //checks if evaded
  if((rand() % 100)<= evasion){
    cout<< "\n"<< name<< " evaded!!\n";
    return false;
  }
  cout << "\n" << name << " took " << dmgAmt <<" damage!\n";
  curHealth -= dmgAmt;
  return true;
}

void Gladiator::display(){
  //couts stats at begging
  cout <<"\nName: " << name <<endl;
  cout << "Min Damage: "<<dmgMin<< " Damange Range: " << dmgRange << " Critical: "<<critical <<" Evasion: "<<evasion <<endl;
  cout<< "Max Health: "<<maxHealth<< " Current Health: "<<curHealth<< endl;
}

int Gladiator::getCurHealth()
{
	return curHealth;
}

//num of gladdiators
const int SIZE = 2;

int main(){
  //random, use time as a seed
  srand(time(NULL));

//string of array
  string glad_name[SIZE];

  do{
  cout << "\nYou are hosting a fight to the death between two gladiators!\n";
//go through loop to create to get names and create gladiators
  for(int i =0;i<2;i++){
    cout <<"\nName of Gladiator?" <<"(" << i+1<<")\n";
    getline(cin, glad_name[i]);
  }

  //two objects are created here (an array of objects)
  Gladiator g[SIZE] {{glad_name[0]}, {glad_name[1]}};
  g[0].display(); g[1].display();

  cout <<"\nThe Fight Begins!!!!!\n";


  int count = 0;
  int damage = 0;
  do{
    //count is index
      cout << "\n"<<g[count].name << " attacks!\n";
      damage = g[count].rollDamage();
      //switch statement to switch between gladiators
      switch (count) {
        case 0: g[1].takeDamage(damage);
        count = 1;
        break;

        case 1: g[0].takeDamage(damage);
        count = 0;
        break;

      }

      //health updates
      cout<<"\n"<< g[0].name  <<"\'s health: "<< g[0].getCurHealth() << endl;
      cout<<"\n"<< g[1].name <<"\'s health: " << g[1].getCurHealth() << endl;

      cout<<"\nPress enter to continue the fight.\n";
      cin.get(); // pause for user

      //break statement here
      if(g[0].getCurHealth()<=0 || g[1].getCurHealth()<=0){
        if(g[0].getCurHealth()<=0){
          cout<< "\n"<< g[1].name<<" is victorious!!!\n";
        }
        else{
          cout<< "\n"<< g[0].name<<" is victorious!!!\n";
        }
        break;
      }

  }while(true);


//quit or retry here
char q = ' ';
cout << "\nNew Gladiator fight? (y/n)\n";
cin >> q;
if(q=='n'){
  break;
}
cin.ignore();


}while(true);

  return 0;
}
