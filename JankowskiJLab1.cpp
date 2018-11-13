#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 //declaring result variables
	int cent_amount, num_coins, num_q, num_d, num_n, num_p;

// declaring final variables
	int penny, nickel, dime, quarter;
	penny = 1;
	nickel = 5;
	dime = 10;
	quarter = 25;

// asking user for input
	cout << "Please input an amount of cents" << endl; 
	cin >> cent_amount;
	cout << endl;


// finding out coin type
	num_q = cent_amount / quarter;
//cent amount = cent amount % quarter
	cent_amount %= quarter;
	
	num_d = cent_amount / dime;

	cent_amount %= dime;

	num_n = cent_amount / nickel;

	cent_amount %= nickel;

	num_p = cent_amount / penny;

	cent_amount %= penny;

// total number of coins user has
	num_coins = num_q + num_d + num_n + num_p;

	cout << "total number of coins: " << num_coins << endl;
	cout << "total number of quarters: " << num_q << endl;
	cout << "total number of dimes: " << num_d << endl;
	cout << "total number of nickels: " << num_n << endl;
	cout << "total number of pennies: " << num_p << endl;

	// cents divided by quarter --> cents divided by dimes --> cents divided by 

	return 0;
}
