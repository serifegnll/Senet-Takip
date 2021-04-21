//github : serifegnll
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//YAPILAR (her yerde kullanýcaz)

struct ypMusteriVerileri // yapýyý her yerde kullanabilmek için ortak tanýmladýk
{
	int musteriNo;
	char musteriAd[20];
	char telNo[11];
};
struct ypSenetVerileri
{
	int sntNo;
	int mustNo;	
	char sntAciklama[150];
	double sntTutar;
	double sntOdenen;
	

};
//prototipler
void gotoxy(int x, int y); 

bool VeriAl(char v[], int uz);
bool VeriAl(string& v);
bool VeriAl(int& v);
bool VeriAl(double& v);



