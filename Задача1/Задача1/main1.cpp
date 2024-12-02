#include<iostream>
#include<sstream>

using namespace std;


int main() {
	char now_speed[9] = "0 km/h";
	do {
		float delta;
		cout << "Input speed delta: ";
		cin >> delta;
		stringstream speed(now_speed);
		float now_speed_f;
		char measurements[4];
		speed >> now_speed_f >> measurements;
		if (now_speed_f + delta > 150) {
			cout << "Inposible speed\n";
			continue;
		}
		sprintf_s(now_speed, "%1.f %s", now_speed_f + delta, measurements);
		cout << now_speed<<"\n";
		
	} while (stof(now_speed) > 0.01);
}