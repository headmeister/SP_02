#pragma once
#include "osoba.h"

using namespace std;

class zamestnanec:public osoba
{
protected:
	string place; //zarazeni
	int years_done; //pocet odpracovanych let
	int wage; // mzda
public:
	zamestnanec();
	void Set(string new_place, int new_years_done, int new_wage, string new_bydliste, string new_name, string new_surname, string new_bd);
	void set_param(string new_place, int new_years_done, int new_wage);
	void Print();
	string csv_print();
};
