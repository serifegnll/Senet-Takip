//github : serifegnll
#include "SnfKayitnolar.h"

int SnfKayitnolar::KyitNoGoster(int tur) // kay�t nosu her �al��mada kaybolmas�n diye bir dosyada tutoruz
{
	// tur =0 musteri no icin
	// tur=1 senet no icin
	int kn = 0;
	ifstream dosyaOku;
	dosyaOku.open("musteriNo.dat", ios::binary | ios::in);
	if (!dosyaOku.is_open())
	{
		
		ofstream dosyaYaz;
		dosyaYaz.open("musteriNo.dat", ios::binary | ios::out);
		dosyaYaz.write((char*)&kn, sizeof(int));
		dosyaYaz.write((char*)&kn, sizeof(int));
		dosyaYaz.close();
		dosyaOku.open("musteriNo.dat", ios::binary | ios::in);
	}
	dosyaOku.seekg(tur*sizeof(int), ios::beg);
	dosyaOku.read((char*)&kn, sizeof(int));
	
	return kn;
}

void SnfKayitnolar::KyitNoKaydet(int tur,int no)
{
	// tur =0 musteri no icin
	// tur=1 senet no icin
	//d��ardan ald��� say�y� dosyaya kay�tno olarak al�r
	ofstream dosyaYaz;
	dosyaYaz.open("musteriNo.dat", ios::binary | ios::out);
	dosyaYaz.seekp(tur * sizeof(int), ios::beg);
	dosyaYaz.write((char*)&no, sizeof(int));
	dosyaYaz.close();
}
