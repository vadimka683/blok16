#include<iostream>
#include<string>
using namespace std;


int main() {
	string number;
	int i_num = 0;
	int d_num = 0;
	cout << "Input integer part of number: ";
	cin >> i_num;
	cout << "Input double part of number: ";
	cin >> d_num;
	number += to_string(i_num);
	number += ".";
	number += to_string(d_num);
	double i = stod(number);
	cout << i;
}