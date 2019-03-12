#include "stdafx.h"
#include "zamestnanec.h"
using namespace std;

//deklarace globálních proměnných
int index = 0;
int velikost = 10;
zamestnanec* zam = new zamestnanec[velikost];


void new_entry(string new_place, int new_years_done, int new_wage, string new_bydliste, string new_name, string new_surname, string new_bd) //novy zapis zamestnance do pameti
{
	if (index == velikost)//pokud by se novy zamestnanec nevesel do soucasneho seznamu
	{
		//alokace noveho prostoru v pameti pro nove zamestnance
		velikost = index + 5;
		zamestnanec* new_zam = new zamestnanec[velikost];
		for (int i = 0; i < index; i++)
			new_zam[i] = zam[i];
		delete[] zam; // smazani puvodniho seznamu zamestnancù z pameti
		zam = new_zam; //nastaveni puvodniho pointeru na novou pozici v pameti
	}
	zam[index].Set(new_place, new_years_done, new_wage, new_bydliste, new_name, new_surname, new_bd); //ulozeni udaju o zamestnanci do pameti

	index++;
}

void data_extraction(string data)// extrakce dat z CSV souboru a zapisovani do objektu
{ //deklarace promennych
	int delka = data.length();
	string pom = "";
	string bydliste = "";
	string place = "";
	int plat = 0;
	string jmeno = "";
	string prijmeni = "";
	string dat_nar = "";
	int odpracovano = 0;
	int carry = 0;

	for (int j = 0; j < 8; j++)// cyklus pro jednotlive parametry
	{
		pom = "";

		for (int i = carry; i <= delka; i++)// cyklus pro vyjmuti textu z CSV souboru a vlozeni do náležité proměnné
		{
			if (data[i] == ';' || data[i] == '\0')
			{
				pom = data.substr(carry, i - carry);
				carry = i + 1;
				switch (j)
				{
				case 0:
					place = pom;
					break;
				case 1:
					odpracovano = stoi(pom);
					break;
				case 2:
					plat = stoi(pom);
					break;
				case 3:
					bydliste = pom;
					break;
				case 4:
					jmeno = pom;
					break;
				case 5:
					prijmeni = pom;
					break;
				case 6:
					dat_nar = pom;
					break;
				default:
					break;
				}
				break;
			}
		}
	}

	new_entry(place, odpracovano, plat, bydliste, jmeno, prijmeni, dat_nar); // uložení dat do nového objektu
}

int read_csv(string nazev)//cteni souboru csv s daty o zamestnancich
{
	ifstream soubor(nazev);

	if (soubor.is_open() == false)
	{
		cout << "Soubor nenalezen.";
		cin.get();
		return 0;
	}
	string text;

	while (getline(soubor, text) && text.length() > 8)//cteni souboru po radcich
	{
		data_extraction(text);
	}
	soubor.close();
	return 1;
}

bool write_csv(string input, string nazev)//zapis dat do csv souboru
{
	ofstream soubor(nazev, std::ios::app);
	soubor << input;
	soubor.close();
	return true;
}

int input_check()//kontrola vstupnich dat pro integer vstupy
{
	int promenna;
	cin >> promenna;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Zadana hodnota neni cislo. Opakujte zadani:";
			cin >> promenna;
		}
		if (!cin.fail())
		{
			break;
		}
	}
	return promenna;
}

void add_new(string nazev) //sber dat pro novy zapis do databaze
{
	string bydliste = "";
	string place = "";
	string jmeno = "";
	string prijmeni = "";
	string dat_nar = "";


	cin.ignore();
	cout << "Jmeno: ";

	getline(cin, jmeno);
	cout << "Prijmeni: ";
	getline(cin, prijmeni);
	cout << "Datum narozeni(\"DD:MM:YYYY\"): ";
	getline(cin, dat_nar);
	cout << "Bydliste: ";
	getline(cin, bydliste);
	cout << "Zarazeni: ";
	getline(cin, place);
	cout << "Plat: ";
	int plat = input_check();
	cout << "Odpracovano let: ";
	int odpracovano = input_check();

	new_entry(place, odpracovano, plat, bydliste, jmeno, prijmeni, dat_nar); // uložení dat do nového objektu

	write_csv(zam[index - 1].csv_print(), nazev);//zapis dat do csv
}


int main()
{
	string nazev;
	cout << "Zadejte nazev souboru s daty: ";
	cin >> nazev;
	int ret = read_csv(nazev);
	if (ret == 0)// pokud nebyl nacten soubor ukonci program
	{
		cin.get();
		return 0;
	}

	for (int i = 0; i < index; i++)//vytisteni informaci o zamestnancich do konzoly
	{
		zam[i].Print();
	}

	bool error = true;
	string input;


	while (error)//cyklus pro vkladani novych zaznamu
	{
		cout << "Prejete si zadat novy zaznam do databaze (y/n)?";
		cin >> input;
		if (input.compare("y") == 0)
		{
			add_new(nazev);
			zam[index - 1].Print();
		}
		else if (input.compare("n") == 0)
		{
			error = false;
		}
		else
		{
			error = true;
		}
	}


	cin.ignore();
	cin.get();

	return 0;
}
