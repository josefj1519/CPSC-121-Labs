/*
Josef Jankowski
Lab 4
Due October 14 2018
*/



#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;


//prototype functions literally copies from the lab4 sheet.
string getInput();
string printBetween(int, int, int step = 1);
string nonalnum_removed(string);
string alphabet_numberified(string);
int sumDigits(string);
void saveString(string);




int main(){

//'again' will be the condition for the do while loop
bool again = true;
//for the switch statement
int menu_choice;
//base string
string str = "strings are cool";


  do{

    //menu
      cout << "Current string: " << str << "\n\n";

      cout << "The String Manipulator Menu!\n\n";
      cout << "************************************************\n\n";
      cout << " 1     -     Make your own string!\n";
      cout << " 2     -     Print Between\n";
      cout << " 3     -     Removes the non Alpha Numeric Characters \n";
      cout << " 4     -     Alphabet Numberified\n";
      cout << " 5     -     Sum of the Digits\n";
      cout << " 6     -     Save the String\n\n";
      cout << "************************************************\n\n";
      cin >> menu_choice;

      //getting string from user
      string input;


      //switch menu
      switch(menu_choice){
        //case to simply get input
        case 1:
        str = getInput();
        break;

        //case for the printing numbers between eachother given a certain step
        case 2:
        int a, b, step;
        cout << "Enter an 'a' value (int)\n";
        cin >> a;
        cout << "Enter an 'b' value (int)\n";
        cin >> b;
        cout << "Enter an 'step' value (enter '0' for default step of 1)\n";
        cin >> step;
        if(step==0)
          str = printBetween(a, b);
        else
          str = printBetween(a, b, step);
        break;

        //remove non alpha numeric
        case 3:
        cout << "Enter a new string\n";
        cin.ignore();
        getline(cin, input);
        str = nonalnum_removed(input);
        break;

        //turns letters into ascii and keeps numbers the same
        case 4:
        cout << "Enter a new string\n";
        cin.ignore();
        getline(cin, input);
        str = alphabet_numberified(input);
        break;

        //adds te digits given in the string and returns sum
        case 5:
        cout << "Enter a new string\n";
        cin.ignore();
        getline(cin, input);
        str = to_string(sumDigits(input));
        break;

        //writes sting to file
        case 6:
          saveString(str);
          cout << "Saved!";
          break;


      }

      //final string
      cout << "New String: " << str << "\n\n";

      //asking if want to play agiain and if not exit the loop
      char go_again;
      cout << "Do you want to again? (y/n)\n";
      cin >> go_again;

      if(go_again == 'n'){
        again = false;
      }


  }while(again);



  return 0;
}


string getInput(){

  string newstr;
  cout << "Enter your new string! \n";
  getline(cin, newstr);
  return newstr;

}

string printBetween(int a, int b, int step){
  int max, min;
  string result;
  //checking which num is bigger and setting the max and min appropiately
  if(a > b){
    max = a; min = b;
  }
  else{
    max = b; min = a;
  }
  //adding numbers to a string
  //goes between the two  numbers increment by step
  for(int i=min; i<=max;i += step ){
    result += to_string(i);
  }
  return result;

}

string nonalnum_removed(string input){

//loop of the string length
  for(int i = 0; i < input.length(); i++){
    //check if NOT alpha numeric
    if(!isalnum(input[i])){
      //erase the char
      input.erase(i,1);
      //increment backwards because we r now further back in the string
      i--;
    }
  }

  return input;
}

string alphabet_numberified(string input){
  //temp int
  int temp;
  //for loop with the string length
  for(int i = 0; i < input.length(); i++){
    //checks if not a digit
    if(!isdigit(input[i])){
      //then casts a char to and int (ascii) and stores it in temp
      temp = (int) input[i];
      //erase the previous char
      input.erase(i,1);
      //store the ascii in the string
      input.insert(i ,to_string(temp));
    }

  }

  return input;
}

int sumDigits(string input){
  //result of function
  int result = 0;
  for(int i = 0; i < input.length(); i++){
    //checks if the char is a digit and then add it to the result
      if(isdigit(input[i]))
        result += stoi(input.substr(i,1));
        //if not a digit then error statement
      else
        cout << input[i] << " is not a number\n";
  }

  return result;
}

void saveString(string str){
  //object
  ofstream fout;
  //open file
  fout.open("JankowskiJLab4.txt");
  //write to it
  fout<< str;

  fout.close();
}
