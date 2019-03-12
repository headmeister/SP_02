#pragma once
using namespace std;

class osoba//trida osoba obsahujici zakladni udaje o dane osobe
{
protected:
	string jmeno;
	string prijmeni;
	string dat_nar;
	string bydliste;
public:
	osoba();

	void set_param(string new_bydliste, string new_name, string new_surname, string new_bd);
	void Print();
	string csv_print();
};
