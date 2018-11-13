#include <iostream>
//need string and array libraries for the 'for' loop
#include <string>
#include <array>
using namespace std;

/*
quizzes 10%
lab 35%
midterm 15%
final 30%
participation 10%
*/

int main(){
  //array of strings that name the categories of the class according to the syllabus
  string categories[5] = {"Quiz", "Lab", "Midterm", "Final", "Participation"};
  //the double where the user will input the grades
  double grades[5];
  //percentages of the categories.  Will run parrell with categories array
  double percentages[5] = {.10, .35, .15, .30, .10};
  //total grade total added up
  double gradetotal = 0;
  //max is 100% will substract when user iputes -1
  int max = 100;

  for (int i = 0; i < 5; i++) {

    //going through the categories array and getting user input for the grades as percentages
    cout << "Enter your grade for " << categories[i] << " (percentage). \n";
    cin >> grades[i];

    //checking if -1 and is substracting from max if it is
    if(grades[i] != -1)
      gradetotal +=  grades[i] * percentages[i];
    else
      max -= percentages[i] * 100;

  }

  int final_grade = ((gradetotal / max) * 100);
  //determing the final percentage and displaying it to the user
  cout << "Your  current percentage is: " <<  final_grade << endl;


  //giving student final letter grades utilizing if and else if statements
  if(final_grade>=90)
    cout << "Your grade is an A \n";
  else if(final_grade>=80)
    cout << "Yout grade is an B \n";
  else if(final_grade>=70)
    cout << "Yout grade is an C \n";
  else if(final_grade>=60)
    cout << "Yout grade is an D \n";
  else
    cout << "Yout grade is an F \n";

  return 0;

}
