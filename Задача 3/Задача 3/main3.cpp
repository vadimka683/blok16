#include<iostream>
#include<sstream>
using namespace std;

void calculator(string& ex) {
	stringstream buffer(ex);
	double first_op, second_op;
	char operation;
	buffer >> first_op >> operation >> second_op;
	switch (operation) {
	case '+': cout << first_op + second_op; break;
	case '-': cout << first_op - second_op; break;
	case '/': cout << first_op / second_op; break;
	case '*': cout << first_op * second_op; break;
	default: cout << "Inposible operation\n"; return;
	}
}


int main() {
	string example;
	cout << "Input your example: ";
	cin >> example;
	calculator(example);
}