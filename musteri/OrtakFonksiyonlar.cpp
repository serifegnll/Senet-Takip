//github : serifegnll
#include "OrtakFonksiyonlar.h"
#include "SnfMusteri.h"

using namespace std;


//gövdeler
void gotoxy(int x, int y)
{
    COORD coordinates;     // coordinates is declared as COORD
    coordinates.X = x;     // defining x-axis
    coordinates.Y = y;     //defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


bool VeriAl(char v[], int uz)
{
	// ekrandan veri alarak, uz kadarýný v dizisine yerleþtiri.Son karater '\0' dir.
	string st = "";
	VeriAl(st);
	int i = 0;
	for (i = 0; i < uz && i < st.length(); i++)v[i] = st[i];
	v[i] = '\0';
	return true;
}
bool VeriAl(string& v)
{
	//Ekrandana sitring alýr ve çaðýrýlan parametre içine (v) yerleþtiri
	cin.seekg(0, ios::end);// klavye hafýzasýndaki kalýntýlar atlamak için
	cin.clear();
	getline(cin, v);
	return true;
}
bool VeriAl(int& v)
{
	// Ekrandan int türünde sayý alýr ve çaðýrýlan parametre içine (v) yerleþtirir
	// hata olursa v'yi deðiþtirmez false döndürür
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
	// Ekrandan double türünde sayý alýr ve çaðýrýlan parametre içine (v) yerleþtirir
	// hata olursa v'yi deðiþtirmez false döndürür

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



