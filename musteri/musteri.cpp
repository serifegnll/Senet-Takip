// musteri.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
#include "OrtakFonksiyonlar.h";
#include "SnfMusteri.h";
#include "SnfKayitnolar.h";
#include "SnfSenet.h";


void AnaMenu()
{
	int sec = 0;
	SnfMusteri musteri;
	SnfSenet senet;
	do {

		system("cls");
		gotoxy(30, 5);
		cout << "ANA MENU";
		gotoxy(30, 6);
		cout << "1-MUSTERI ISLEMLERI";
		gotoxy(30, 7);
		cout << "2-SENET ISLEMLERI";
		gotoxy(30, 8);
		cout << "3-CIKIS: ";
		VeriAl(sec);


		switch (sec)
		{
		case 1:
			system("cls");
			musteri.MusteriIslemleri();
			break;
		case 2:
			system("cls");
			senet.SenetIslemleri();
			break;
		}
	} while (sec != 3);
}



int main()
{
    //SnfKayitnolar kn;
    //kn.KyitNoKaydet(0,174);
    SnfMusteri musteri;
    SnfSenet senet;
    ypMusteriVerileri musteriVeri;
    
    //musteri.VeriListele();
    // senet.SenetIslemleri();
    //senet.SenetEtiket();
    AnaMenu();
    
   
    

    
    
   
   

   
 
    

}


