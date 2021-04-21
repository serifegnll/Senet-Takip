//github : serifegnll
#include "OrtakFonksiyonlar.h"
#include "SnfMusteri.h"

using namespace std;


//g�vdeler
void gotoxy(int x, int y)
{
    COORD coordinates;     // coordinates is declared as COORD
    coordinates.X = x;     // defining x-axis
    coordinates.Y = y;     //defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


bool VeriAl(char v[], int uz)
{
	// ekrandan veri alarak, uz kadar�n� v dizisine yerle�tiri.Son karater '\0' dir.
	string st = "";
	VeriAl(st);
	int i = 0;
	for (i = 0; i < uz && i < st.length(); i++)v[i] = st[i];
	v[i] = '\0';
	return true;
}
bool VeriAl(string& v)
{
	//Ekrandana sitring al�r ve �a��r�lan parametre i�ine (v) yerle�tiri
	cin.seekg(0, ios::end);// klavye haf�zas�ndaki kal�nt�lar atlamak i�in
	cin.clear();
	getline(cin, v);
	return true;
}
bool VeriAl(int& v)
{
	// Ekrandan int t�r�nde say� al�r ve �a��r�lan parametre i�ine (v) yerle�tirir
	// hata olursa v'yi de�i�tirmez false d�nd�r�r
	string st = "";
	getline(cin, st);
	try
	{
		v = stoi(st);
	}
	catch (const std::exception&)
	{
		//v = 0;
		return false;
	}
	return true;
}
bool VeriAl(double& v)
{
	// Ekrandan double t�r�nde say� al�r ve �a��r�lan parametre i�ine (v) yerle�tirir
	// hata olursa v'yi de�i�tirmez false d�nd�r�r

	string st = "";
	getline(cin, st);
	try
	{
		v = stod(st);
	}
	catch (const std::exception&)
	{
		//v = 0.0;
		return false;
	}
	return true;
}



