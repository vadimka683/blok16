#include<iostream>
#include<sstream>
using namespace std;

enum switches {
	ALL_ELECTRICITY = 1,
	SOCKETS = 2,
	LIGHT_IN_HOUSE = 4,
	LIGHT_GARDEN = 8,
	HEATING_ROOM = 16,
	HEATING_WATER_PIPE = 32,
	CONDITIONER = 64
};

int now_data(string& time, int day) {
	int time_hour;
	string time_min;
	char operand;
	stringstream now_time(time);
	now_time >> time_hour >> operand >> time_min;
	stringstream().swap(now_time);
	if (time_hour == 23) {
		day += 1;
		time_hour = 0;
		now_time << 0 << time_hour << operand << time_min;
		now_time >> time;
	}
	else if (time_hour + 1 < 10) {
		now_time << 0 << time_hour + 1 << operand << time_min;
		now_time >> time;
	}
	else {
		now_time << time_hour + 1 << operand << time_min;
		now_time >> time;
	}
	cout << "Day " << day + 1 << "now " << time << " o clock\n";
	return day;
}

void check_heating_water_pipe(int& status_switches, int temp_out) {
	if (temp_out < 0 && !(status_switches & HEATING_WATER_PIPE)) {
		status_switches |= HEATING_WATER_PIPE;
		cout << "heating of the water supply system coming from a well with a pump is turned on\n";
	}
	else if (temp_out > 5 && (status_switches & HEATING_WATER_PIPE)) {
		status_switches &= ~(HEATING_WATER_PIPE);
		cout << "heating of the water supply system coming from a well with a pump is turned off\n";
	}
}

void check_light_garden(int& status_switches, string time, string move) {
	int time_h = stoi(time);
	if ((time_h > 16 && time_h < 5) && !(status_switches & LIGHT_GARDEN) && move == "yes") {
		status_switches |= LIGHT_GARDEN;
		cout << "Light in the garden is turned on\n";
	}
	else if ((time_h > 16 && time_h < 5) && (status_switches & LIGHT_GARDEN) && move == "no") {
		status_switches &= ~(LIGHT_GARDEN);
		cout << "Light in the garden is turned off\n";
	}
	else if ((time_h > 5 && time_h < 16) && (status_switches & LIGHT_GARDEN)) {
		status_switches &= ~(LIGHT_GARDEN);
		cout << "Light in the garden is turned off\n";
	}
}

void check_heating_room(int& status_switches, int temp_in) {
	if (temp_in < 22 && !(status_switches & HEATING_ROOM)) {
		status_switches |= HEATING_ROOM;
		cout << "Heating in the room turned on\n";
	}
	else if (temp_in >= 25 && (status_switches & HEATING_ROOM)) {
		status_switches &= ~(HEATING_ROOM);
		cout<< "Heating in the room turned off\n";
	}
	if (temp_in >= 30 && !(status_switches & CONDITIONER)) {
		status_switches |= CONDITIONER;
		cout << "Conditioner in the room turned on\n";
	}
	else if (temp_in <= 25 && (status_switches & CONDITIONER)) {
		status_switches &= ~(CONDITIONER);
		cout << "Conditioner in the room turned off\n";
	}
}

void color_changes(int& status_switches, string time, string light) {
	int temperature = 5000;
	int time_h = stoi(time);
	if (light == "on" && !(status_switches & LIGHT_IN_HOUSE)) {
		status_switches |= LIGHT_IN_HOUSE;
		cout << "Light in house turned on\n";
	}
	else if (light == "off" && (status_switches & LIGHT_IN_HOUSE)) {
		status_switches &= ~(LIGHT_IN_HOUSE);
		cout << "Light in house turned off\n";
	}
	if (time_h >= 16 && time_h <= 20 && light == "on") {
		temperature = 2700 + (20 - time_h) * (2300 / 4);
	}
	else if (time_h > 20 && time_h <= 23 && light == "on") {
		temperature = 2700;
	}
	if (light == "on") {
		cout << "Light temperature = " << temperature << "K" << "\n";
	}
}

int main() {
	string time = { "00:00" };
	int status_switches = 0;
	int day = 0, temp_in, temp_out;
	string move, ligtht;
	while (day != 2) { 
		day = now_data(time, day); 
		cout << "input sensor status(temp in house, temp in the carden, move(yes/no), light in house(on/off)):\n";
		string sensor_status;
		getline(cin, sensor_status);
		stringstream status(sensor_status);
		status >> temp_in >> temp_out >> move >> ligtht;
		check_heating_room(status_switches, temp_in);
		check_heating_water_pipe(status_switches, temp_out);
		check_light_garden(status_switches, time, move);
		color_changes(status_switches, time, ligtht);
	}
}

