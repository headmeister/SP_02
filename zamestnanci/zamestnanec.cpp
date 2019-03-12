#include "stdafx.h"
#include "zamestnanec.h"
#include  "osoba.h"
using namespace std;

zamestnanec::zamestnanec() //konstruktor
{
	place = "Default";
	years_done = 0;
	wage = 0;
}

void zamestnanec::Set(string new_place, int new_years_done, int new_wage, string new_bydliste, string new_name, string new_surname, string new_bd) // nastaveni parametru tridy i materské tridy
{
	osoba::set_param(new_bydliste, new_name, new_surname, new_bd);
	set_param(new_place, new_years_done, new_wage);
}

void zamestnanec::set_param(string new_place, int new_years_done, int new_wage)//nastaveni parametru tridy zamestnanec
{
	place = new_place;;
	wage = new_wage;
	years_done = new_years_done;
}

void zamestnanec::Print() //vytisteni udaju o zamestnanci vcetne udaju z tridy osoba
{
	osoba::Print();
	cout << endl << "Zarazeni: " << place << endl;
	cout << "Odpracovano let: " << years_done << endl;
	cout << "Mzda: " << wage << endl;
}

string zamestnanec::csv_print()//vytvoreni zapisu do CSV souboru
{
	string vystup = "";
	vystup = vystup + place + ';' + to_string(years_done) + ';' + to_string(wage) + ';';
	vystup = vystup + osoba::csv_print();
	vystup = vystup + '\n';
	return vystup;
}
