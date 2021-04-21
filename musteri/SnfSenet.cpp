//github : serifegnll
#include "SnfSenet.h"

void SnfSenet::SenetEkle()
{
	int sntNo = 0;
	ypSenetVerileri senetBlg;
	SnfMusteri musteri;
	SnfKayitnolar sn;
	string cvp;
	// no ile kayýt inceliyoruz
	ypMusteriVerileri incelenecek;
	int arananNo = 0;
	//******
	do {
		system("cls");
		gotoxy(30, 5);
		cout << "SENET EKLEME EKRANI";
		gotoxy(30, 6);
		cout << "Senet eklenecek musterinin numarasini girin (iptal icin 0 girin): ";
		VeriAl(arananNo); // aranacak noyu alýyoruz
		if (arananNo == 0) return; // 0 girilirse iþlem iptal

		incelenecek = musteri.KayitArama(arananNo); // no ile kayýt arýyoruz

		if (incelenecek.musteriNo == -1) // kayitarama ile dönen deðer -1 ise bulunamamýþtýr
		{
			gotoxy(30, 8);
			cout << "Bulunamadi.[enter]";
			VeriAl(arananNo); //sadece bekletmek icin
		}
		else
		{
			// bulunursa ekranda gösterilir   

			musteri.VeriGoster(incelenecek);
			gotoxy(30, 16);
			cout << "Bu musteriye senet eklensin mi?(e/h)";
			VeriAl(cvp);

			if (cvp == "e")
			{
				system("cls");
				sntNo = sn.KyitNoGoster(1) + 1;
				
				SenetEtiket();
				gotoxy(45, 10);
				cout << incelenecek.musteriNo;

				gotoxy(45, 11);
				cout << sntNo;
				senetBlg = SenetVeriAl();
				senetBlg.mustNo = incelenecek.musteriNo;
				senetBlg.sntNo = sntNo;

				gotoxy(45, 16);
				cout << "Senet eklensin mi?(e/h)";
				VeriAl(cvp);
				if (cvp == "e")
				{
					SenetKaydet(senetBlg);
					sn.KyitNoKaydet(1, sntNo);
					gotoxy(45, 17);
					cout << "Kaydedildi[enter]";
					VeriAl(sntNo);
				}


			}


		}

		gotoxy(45, 17);
		cout << "Yeni kayit yapilacak mi?(e/h)";
		VeriAl(cvp);
		

	} while (cvp == "e");

	
	

	
}


void SnfSenet::SenetEtiket()
{
	gotoxy(30, 10);
	cout << "                                                                 ";
	gotoxy(30, 10);
	cout << "MUSTERI NO...:";
	gotoxy(30, 11);
	cout << "SENET NO.....:";
	gotoxy(30, 12);
	cout << "ACIKLAMA.....:";
	gotoxy(30, 13);
	cout << "TUTAR........:";
	gotoxy(30, 14);
	cout << "ODENEN.......:";
	gotoxy(30, 15);
	cout << "------------------------------+------------------------------";

}

ypSenetVerileri SnfSenet::SenetVeriAl()
{
	ypSenetVerileri senet = { 0,0,"",0.0,0.0};

	
	gotoxy(45, 12);
	VeriAl(senet.sntAciklama,150);
	gotoxy(45, 13);
	VeriAl(senet.sntTutar);
	gotoxy(45, 14);
	VeriAl(senet.sntOdenen);

	
	return senet;
}

void SnfSenet::SenetKaydet(ypSenetVerileri senetKaydet)
{
	
	fstream dosya;
	dosya.open("senet.dat", ios::binary | ios::app);	
	dosya.write((char*)&senetKaydet, sizeof(ypSenetVerileri));
	dosya.close();
	
}




void SnfSenet::SenetIslemleri()
{
	int sec;
	int devam;

	do
	{
	system("cls");
	gotoxy(30, 4);
	cout << "SENET ISLEMLERI";
	gotoxy(30, 5);
	cout << "1-Senet Ekle";
	gotoxy(30, 6);
	cout << "2-Musteri Senetleri Listele";
	gotoxy(30, 7);
	cout << "3-Senet Sil";
	gotoxy(30, 8);
	cout << "4-Senet Guncelle";
	gotoxy(30, 9);
	cout << "SECIMINIZ: ";
	VeriAl(sec);

	
		switch (sec)
		{
		case 1:
			system("cls");
			SenetEkle();
			break;
		case 2:
			system("cls");
			SenetSirala("SENET LISTELEME");
			gotoxy(30, 2);
			cout << "Devam etmek icin[enter]";
			VeriAl(devam);
			break;
		case 3:
			system("cls");
			SenetSil();
			break;
		case 4:
			system("cls");
			SenetGuncelle();
			break;
		}
				

	} while (sec != 5);
}

void SnfSenet::SenetSirala(string baslik)
{
	// no ile kayýt inceliyoruz
	ypMusteriVerileri incelenecek;
	SnfMusteri musteri;
	ypSenetVerileri senet;
	string cvp;
	int y = 12;
	int arananNo = 0;
	int tutar = 0;
	int odenen = 0;
	int fark = 0;
	//******

	system("cls");
	gotoxy(30, 5);
	cout << baslik;
	gotoxy(30, 6);
	cout << "Musteri numarasini girin:  ";
	VeriAl(arananNo); // aranacak noyu alýyoruz
	//if (arananNo == 0) return; // 0 girilirse iþlem iptal

	incelenecek = musteri.KayitArama(arananNo); // no ile kayýt arýyoruz
	if (incelenecek.musteriNo == -1) // kayitarama ile dönen deðer -1 ise bulunamamýþtýr
	{
		gotoxy(30, 8);
		cout << "Bulunamadi.[enter]";
		VeriAl(arananNo); //sadece bekletmek icin
	}
	else //bulununca
	{
		
		SenetListele(incelenecek.musteriNo);

	}
}
void SnfSenet::SenetListele(int mustNo)
{
	int tutar = 0;
	int odenen = 0;
	int fark = 0;
	int y = 12;
	ypMusteriVerileri incelenecek;
	SnfMusteri musteri;
	ypSenetVerileri senet;
	fstream dosya;
	incelenecek = musteri.KayitArama(mustNo);
	dosya.open("senet.dat", ios::binary | ios::in);


	system("cls");
	gotoxy(30, 4);
	cout << "         M U S T E R I  B I L G I L E R I";
	gotoxy(30, 5);
	cout << "M. NO             AD SOYAD                 TEL NO";
	gotoxy(30, 6);
	cout << "------     -----------------------        -----------";
	gotoxy(30, 7);
	cout << setw(6) << incelenecek.musteriNo << "     " << setiosflags(ios::left) << setw(20) << incelenecek.musteriAd << resetiosflags(ios::left) << setw(11) << "     " << incelenecek.telNo;

	gotoxy(30, 9);
	cout << "                S E N E T  B I L G I L E R I";
	gotoxy(30, 10);
	cout << "S. NO               ACIKLAMA              TUTAR      ODENEN";
	gotoxy(30, 11);
	cout << "------     ------------------------    ----------    -------";

	while (dosya.peek() != EOF)
	{
		dosya.read((char*)&senet, sizeof(ypSenetVerileri));
		if (incelenecek.musteriNo == senet.mustNo)
		{
			gotoxy(30, y);
			cout << setw(6) << senet.sntNo << "     " << setiosflags(ios::left) << setw(20) << senet.sntAciklama << "        " << setw(6) << fixed << setprecision(2) << senet.sntTutar << "        " << setw(6) << fixed << setprecision(2) << senet.sntOdenen << resetiosflags(ios::left);
			tutar = tutar + senet.sntTutar;
			odenen = odenen + senet.sntOdenen;
			fark = tutar - odenen;
			y++;
		}
	}

	gotoxy(30, y + 2);
	cout << "---------------------------------------------------------------------";
	gotoxy(30, y + 3);
	cout << "TOPLAM TUTAR: " << tutar << " /  TOPLAM ODENEN: " << odenen << " /  KALAN: " << fark;
	gotoxy(30, y + 4);
	cout << "---------------------------------------------------------------------";

	dosya.close();
}

void SnfSenet::SenetSil()

{
	string cvp = "";
	int sntNo;
	int arananNo = 0;
	ypMusteriVerileri incelenecek;
	SnfMusteri musteri;
	system("cls");
	gotoxy(30, 5);
	cout << "SENET SILME ISLEMLERI";
	gotoxy(30, 6);
	cout << "Musteri numarasini girin:  ";
	VeriAl(arananNo); // aranacak noyu alýyoruz
	//if (arananNo == 0) return; // 0 girilirse iþlem iptal

	incelenecek = musteri.KayitArama(arananNo); // no ile kayýt arýyoruz
	if (incelenecek.musteriNo == -1) // kayitarama ile dönen deðer -1 ise bulunamamýþtýr
	{
		gotoxy(30, 8);
		cout << "Bulunamadi.[enter]";
		VeriAl(arananNo); //sadece bekletmek icin
	}
	else //bulununca
	{
		do {
			system("cls");
			SenetListele(incelenecek.musteriNo);
			gotoxy(30, 2);
			cout << "Silinecek senet numarasini giriniz (0-> Ýptal): ";
			VeriAl(sntNo);
			if (sntNo == 0)break;
			DosyadanSil(sntNo);
			gotoxy(30, 2);
			cout << "Silme basarili.";
			VeriAl(cvp);
		} while (true);

	}
	
	


}

void SnfSenet::DosyadanSil(int sntNo)
{
	ypSenetVerileri senet;
	string eh = "";
	int satir = 0;

	fstream dosya;
	dosya.open("senet.dat", ios::binary | ios::in);
	fstream gecici;
	gecici.open("geciciSenet.dat", ios::binary | ios::out);


	while (dosya.peek() != EOF)

	{
		dosya.read((char*)&senet, sizeof(ypSenetVerileri));

		if (senet.sntNo != sntNo)
		{
			gecici.write((char*)&senet, sizeof(ypSenetVerileri));
		}

	}
	gecici.close();
	dosya.close();
	remove("senet.dat");
	rename("geciciSenet.dat", "senet.dat");
	
	

}


void SnfSenet::SenetGoster(ypSenetVerileri senet)
{
	SenetEtiket();
	gotoxy(47, 10);
	cout << senet.mustNo;
	gotoxy(47, 11);
	cout << senet.sntNo;
	gotoxy(47, 12);
	cout << senet.sntAciklama;
	gotoxy(47, 13);
	cout << senet.sntTutar;
	gotoxy(47, 14);
	cout << senet.sntOdenen;
}

void SnfSenet::SenetGuncelle()
{
	string cvp = "";
	int sntNo;
	int arananNo = 0;
	ypMusteriVerileri incelenecek;
	SnfMusteri musteri;
	system("cls");
	gotoxy(30, 5);
	cout << "SENET GUNCELLEME ISLEMLERI";
	gotoxy(30, 6);
	cout << "Musteri numarasini girin:  ";
	VeriAl(arananNo); // aranacak noyu alýyoruz
	//if (arananNo == 0) return; // 0 girilirse iþlem iptal

	incelenecek = musteri.KayitArama(arananNo); // no ile kayýt arýyoruz
	if (incelenecek.musteriNo == -1) // kayitarama ile dönen deðer -1 ise bulunamamýþtýr
	{
		gotoxy(30, 8);
		cout << "Bulunamadi.[enter]";
		VeriAl(arananNo); //sadece bekletmek icin
	}
	else //bulununca
	{
		do {
			system("cls");
			SenetListele(incelenecek.musteriNo);
			gotoxy(30, 2);
			cout << "Guncellenecek senet numarasini giriniz (0-> iptal): ";
			VeriAl(sntNo);
			if (sntNo == 0)break;
			DosyadaGuncelle(sntNo);			
			
		} while (true);

	}
}

void SnfSenet::DosyadaGuncelle(int no)
{
	string cvp = "";
	int gncAlan=0;
	int gncTutar = 0;
	int gncOdenen = 0;
	int sira = 0;
	char gncAciklama[150] = "";
	ypSenetVerileri senet = { 0,0,"",0,0 };
	fstream dosya;
	dosya.open("senet.dat", ios::binary | ios::in|ios::out);
	
	while (dosya.peek() != EOF)
	{
		dosya.read((char*)&senet, sizeof(ypSenetVerileri));
		sira++;

		if (senet.sntNo == no)
		{
			system("cls");
			SenetGoster(senet);
			gotoxy(27, 12);
			cout << "1-";
			gotoxy(27, 13);
			cout << "2-";
			gotoxy(27, 14);
			cout << "3-";
			gotoxy(27, 16);
			cout << "Hangi alan guncellensin? (iptal icin 0)";
			VeriAl(gncAlan);

			switch (gncAlan)
			{
			case 0:
				gotoxy(30, 3);
				cout << "Guncelleme iptal.";
				VeriAl(cvp);
				break;
			case 1:
				gotoxy(47, 12);
				cout << "                            ";
				gotoxy(47, 12);
				VeriAl(gncAciklama, 150);
				strcpy_s(senet.sntAciklama, gncAciklama);
				dosya.seekp((sira - 1) * sizeof(ypSenetVerileri),ios::beg);
				dosya.write((char*)&senet, sizeof(ypSenetVerileri));
				gotoxy(30, 3);
				cout << "Guncelleme basarili.";
				VeriAl(cvp);
				break;
			case 2:
				gotoxy(47, 13);
				cout << "                                  ";
				gotoxy(47, 13);
				VeriAl(gncTutar);
				senet.sntTutar = gncTutar;
				dosya.seekp((sira - 1) * sizeof(ypSenetVerileri),ios::beg);
				dosya.write((char*)&senet, sizeof(ypSenetVerileri));
				gotoxy(30, 3);
				cout << "Guncelleme basarili.";
				VeriAl(cvp);
				break;
			case3:
				gotoxy(47, 14);
				cout << "                                  ";
				gotoxy(47, 14);
				VeriAl(gncOdenen);
				senet.sntTutar = gncOdenen;
				dosya.seekp((sira - 1) * sizeof(ypSenetVerileri), ios::beg);
				dosya.write((char*)&senet, sizeof(ypSenetVerileri));
				gotoxy(30, 3);
				cout << "Guncelleme basarili.";
				VeriAl(cvp);
				break;
			}
			break;
			
		}
	}
	dosya.close();
	



}












