#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Address {

	string name_city;
	string name_street;
	string number_home;
	string number_apartment;
public:
	Address() {

	}
	Address(string new_city, string new_street, string new_home, string new_apartment) {
		name_city = new_city;
		name_street = new_street;
		number_home = new_home;
		number_apartment = new_apartment;
	}
	string get_output() {

		return name_city + ", " + name_street + ", " + number_home + ", " + number_apartment;
	}
	string get_city() {
		return name_city;
	}
};

void sort(Address * addresses, int &N, ofstream& FFF) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string a = addresses[i].get_city();
			string b = addresses[j].get_city();
			if(a>b){ swap(addresses[i], addresses[j]); }
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream inFile("in.txt");
	int N;
	inFile >> N;

	string n_c = " ";
	string n_s = " ";
	string n_h = " ";
	string n_a = " ";
	Address* add = new Address[N];
	for (int i = 0; i < N; i++) {
		inFile >> n_c;
		inFile >> n_s;
		inFile >> n_h;
		inFile >> n_a;
		add[i] = Address(n_c, n_s, n_h, n_a);
	}
	ofstream OutFile("out.txt");
	OutFile << N << endl;
	sort(add, N, OutFile);

	for (int i = 0; i <N; i++) {
		OutFile<<add[i].get_output()<<endl;
	}
	delete[] add;
	return 0;
}