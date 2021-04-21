//github : serifegnll
#pragma once
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include"OrtakFonksiyonlar.h"
#include "SnfKayitnolar.h"
using namespace std;
class SnfMusteri
{
public:
	void Etiket(string baslik);
	ypMusteriVerileri MusteriVeriAl();
	void MusteriEkle();
	void MusteriKaydet(ypMusteriVerileri kayitMusteri);
	ypMusteriVerileri KayitSirasindakiMusteri(int sira);
	void VeriGoster(ypMusteriVerileri veriler);
	void VeriListele();
	ypMusteriVerileri KayitArama(int arananNo);
	void KayitIncele();
	void MusteriIslemleri();
	void MusteriSil();
	void MusteriGuncelle();
	void DosyadanSil(int silNo);
	void DosyadaGuncelle(int guncNo);


};

