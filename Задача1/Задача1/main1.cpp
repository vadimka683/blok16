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
		sprintf_s(now_speed, "%1.f", now_speed_f + delta);
		if (now_speed_f + delta < 10) {
			now_speed[1] += ' ';
		}
		else if (now_speed_f + delta < 100) {
			now_speed[2] += ' ';
		}
		else {
			now_speed[3] += ' ';
		}
		bool flag = false;
		int count = 0;
		for (int i = 0; i < sizeof(now_speed); i++) {
			if (now_speed[i] == ' ' && flag == false) {
				flag = true;
				continue;
			}
			if (flag) {
				now_speed[i] = measurements[count];
				count++;
			}
		}
		cout << now_speed;
		
	} while (stof(now_speed) > 0.01);
}