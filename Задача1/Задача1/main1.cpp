#include<iostream>
#include<sstream>

using namespace std;


int main() {
	string now_speed = "0 km/h";
	stringstream speed(now_speed);
	do {
		float delta;
		cout << "Input speed delta: ";
		cin >> delta;
		float now_speed_f;
		string measurements;
		speed >> now_speed_f >> measurements;
		stringstream().swap(speed);  // очистка потока через swap c пустым конструктором потока
		if (now_speed_f + delta > 150) {
			cout << "Inposible speed\n";
			continue;
		}
		now_speed_f += delta;
		speed << now_speed_f << measurements;
		now_speed = speed.str();
		cout << now_speed;
		
	} while (stof(now_speed) > 0.01);
}