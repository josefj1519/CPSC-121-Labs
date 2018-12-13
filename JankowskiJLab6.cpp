/*
Josef Jankowski
CPSC 121 LAB 6
11/16/18
*/




#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//STRUCT
struct Calculator{
  long long LHValue;
  long long * RHValue;
  char lastOperator;
};

//METHODS

//IN THE PROMPT
void processInput(Calculator *calc, string userinput);
//ERASES SPACES AND GETS OPERATOR USED
char eraseSpaces(char* again);






int main(){


  string input;

  //initialzing struct vales
  Calculator c1 ={0, NULL, '+'};
  c1.RHValue = new long long;

  cout<<"Welcome to this calc app. do some math(press 'q' to quit anytime)\n";

  do{


      getline(cin, input);

      //only break when q is inputed
      if(input=="q")
        break;

      processInput(&c1,input);

      cout << "Result: " << c1.LHValue << endl;

      //cout<< "Press 'q' to quit anytime.\n";




}while(true);


//need to delete allocated memory
delete c1.RHValue;



  return 0;
}

void processInput(Calculator *calc, string userinput){
  char *ugh = NULL; // char pointer for strtoll funciton

  //need to turn string to char array for strtoll funciton
  char gh[userinput.length()+1];
  strcpy(gh,userinput.c_str());

  //method to remove spaces and get operator
  char oper = eraseSpaces(gh); //returns operator



//ersaseSpaces returns 'o' if there is a digit that isnt a operator listed in the prompt
if(oper != 'o'){
  if(oper == '='){
    //cout<<"woo";
  }
  //for +5, 5+, *2, etc.
  else if(gh[0]== ' '|| gh[strlen(gh)-1]==' '){
      *(calc->RHValue) = strtoll(gh, &ugh, 10);

  }

  //for new values
  else{
    calc->LHValue= strtoll(gh, &ugh, 10);
    *(calc->RHValue) = strtoll(ugh, &ugh, 10);
  }
  //cout<<"right is now: "<< *(calc->RHValue)<<endl;
  //cout<<"left is now: "<< calc->LHValue<<endl;


//switch statement for all operators
      switch (oper) {
        case '+': calc->lastOperator ='+';
        calc->LHValue += *(calc->RHValue);

        break;
        case'-':  calc->lastOperator = '-';
          calc->LHValue -= *(calc->RHValue);
        break;

        case'/':  calc->lastOperator = '/';
        if(*(calc->RHValue)==0){
          cout<< "u dingus u cant divide by zero\n";
          break;
        }
        else{
          calc->LHValue /= *(calc->RHValue);
        }

        break;
        case'*':  calc->lastOperator = '*';
          calc->LHValue *= *(calc->RHValue);

        break;

        case'%': calc->lastOperator = '%';
        if(*(calc->RHValue)==0){
          cout<< "u dingus u cant divide by zero\n";
          break;
        }
        else{
          calc->LHValue %= *(calc->RHValue);
        }
        break;

        //EQUALS
        case'=':
        //SWITCH FOR lastOperator
          switch (calc->lastOperator) {
            case '+': calc->lastOperator ='+';
            calc->LHValue += *(calc->RHValue);

            break;
            case'-':  calc->lastOperator = '-';
              calc->LHValue -= *(calc->RHValue);

            break;
            case'/':  calc->lastOperator = '/';
            if(*(calc->RHValue)==0){
              cout<< "u dingus u cant divide by zero\n";
              break;
            }
            else{
              calc->LHValue /= *(calc->RHValue);
            }

            break;
            case'*':  calc->lastOperator = '*';
              calc->LHValue *= *(calc->RHValue);

            break;
            case'%': calc->lastOperator = '%';
            if(*(calc->RHValue)==0){
              cout<< "u dingus u cant divide by zero\n";
              break;
            }
            else{
              calc->LHValue %= *(calc->RHValue);
            }
            break;
          }
        break;

      }
  }
  //error
  else{
    cout<< "Oopies daysie incorrect input errrrrrrr\n";
  }
}

char eraseSpaces(char again[]){
  int nonspace = 0;
  char oper = '+';

  for(int i=0;i<strlen(again);i++){
    //delets all spaces and adjusts positions
  if(again[i] != ' '){
    again[nonspace++] = again[i];
  }

  }

  again[nonspace] = '\0';

//finds the operator and replaces with space; strtoll was having errors with '/' and '*'
  for(int i=0;i<strlen(again);i++){
    if(!isdigit(again[i])){

      if(again[i]== '+'||again[i] == '-'||again[i] == '/'||again[i]== '*' || again[i]== '=' ||again[i]== '%' ){
        oper = again[i];
        again[i] = ' ';

      }
      else{
        oper ='o';
        break;
      }
  }
  }

  //cout << "new: " <<again << endl;

  return oper;

}
