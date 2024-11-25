#include<iostream>
#include<string>
using namespace std;


int main() {
	string number;
	int i_num = 0;
	double d_num = 0;
	cout << "Input integer part of number: ";
	cin >> i_num;
	cout << "Input double part of number: ";
	cin >> d_num;
	if (d_num >= 1 || d_num <= 0) {
		cout << "Error";
		return 0;
	}
	number += to_string(i_num);
	number += to_string(d_num);
	bool flag = false;
	for (int i = 0; i < number.length(); i++) {
		if (number[i + 1] == '.' || flag) {
			number[i] = number[i + 1];
			flag = true;
		}
	}
	d_num = stod(number);
	cout << d_num;
}