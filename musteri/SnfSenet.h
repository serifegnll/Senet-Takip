//github : serifegnll
#pragma once
#include "OrtakFonksiyonlar.h"
#include "SnfMusteri.h"
class  SnfSenet
{
public:
	void SenetEkle();
	void SenetEtiket();
	ypSenetVerileri SenetVeriAl();
	void SenetKaydet(ypSenetVerileri senetKaydet);
	void SenetIslemleri();
	void SenetSirala(string baslik);
	void SenetSil();
	void DosyadanSil(int no);
	void  SenetGoster(ypSenetVerileri senet);
	void SenetGuncelle();
	void DosyadaGuncelle(int no);
	void SenetListele(int mustNo);

	




	
};

