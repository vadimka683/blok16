#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

void play(string& music) {
	enum Notes {
		n_do = 1, n_re = 2, n_mi = 4, n_fa = 8, n_sol = 16, n_la = 32, n_si = 64
	};
	int accor = 0;
	for (size_t i = 0; i < music.length(); i++) {
		string t;
		t += music[i];
		int accord = stoi(t);
		accor += (accord == 1) ? n_do : 0;
		accor += (accord == 2) ? n_re : 0;
		accor += (accord == 3) ? n_mi : 0;
		accor += (accord == 4) ? n_fa : 0;
		accor += (accord == 5) ? n_sol : 0;
		accor += (accord == 6) ? n_la : 0;
		accor += (accord == 7) ? n_si : 0;
	}
	
	if (accor & n_do) { cout << "do "; }
	if (accor & n_re) { cout << "re "; }
	if (accor & n_mi) { cout << "mi "; }
	if (accor & n_fa) { cout << "fa "; }
	if (accor & n_sol) { cout << "sol "; }
	if (accor & n_la) { cout << "la "; }
	if (accor & n_si) { cout << "si "; }
}

int main() {
	string music;
	cout << "Input your music: ";
	getline(cin, music);
	play(music);
}