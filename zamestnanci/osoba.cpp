#include "stdafx.h"
#include "osoba.h"

using namespace std;


osoba::osoba() //konstruktor tridy osoba
{
	jmeno = "Anonym";
	prijmeni = "Anonym";
	dat_nar = "0.0.0";
	bydliste = "None";
}

void osoba::set_param(string new_bydliste, string new_name, string new_surname, string new_bd) //nastaveni nove osoby
{
	jmeno = new_name;
	prijmeni = new_surname;
	bydliste = new_bydliste;
	dat_nar = new_bd;
}

void osoba::Print() //vytisteni udaju o osobe
{
	cout << endl << "Jmeno: " << jmeno << endl;
	cout << "Prijmeni: " << prijmeni << endl;
	cout << "Datum narozeni: " << dat_nar << endl;
	cout << "Bydliste: " << bydliste << endl;
}

string osoba::csv_print()//priprava dat pro ulozeni zaznamu do CSV
{
	string vystup = "";
	vystup = vystup + bydliste + ';' + jmeno + ';' + prijmeni + ';' + dat_nar;


	return vystup;
}
