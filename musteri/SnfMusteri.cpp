//github : serifegnll
#include "SnfMusteri.h"



void SnfMusteri::Etiket(string baslik)
{
    gotoxy(30, 5);
    cout << baslik;
    gotoxy(30, 6);
    cout << "------------------------------+------------------------------";
    gotoxy(30, 7);
    cout << "MUSTERI NO.:" << endl;
    gotoxy(30, 8);      
    cout << "AD SOYAD...:" << endl;
    gotoxy(30, 9);     
    cout << "TELEFON....:" << endl;
    gotoxy(30, 10);
    cout << "------------------------------+------------------------------";
    
}

ypMusteriVerileri SnfMusteri::MusteriVeriAl()

{
    ypMusteriVerileri musteri = { 0,"","" };
    string g = "";
   
    gotoxy(43, 8);
    getline(cin, g);
    strcpy_s(musteri.musteriAd, g.c_str());  
    gotoxy(43, 9);
    getline(cin, g);
    strcpy_s(musteri.telNo, g.c_str());
   
    return musteri;
}

void SnfMusteri::MusteriEkle()
{
    int yeniKN; //kayitnoyu 1 artirmak icin 
    string cvp;

    ypMusteriVerileri yeniMusteri; // MusteriVeriAl()'in donus degerini atamak icin

    SnfKayitnolar kayitNo;      //kayitNo nesnesinin KyitNoGoster fonks'nun donus degerini

    do {
        // 1 kere musteri eklenir sonra asagidaki evet hayir durumuna gore dongu tekrarlanir
        yeniKN = kayitNo.KyitNoGoster(0) + 1; //num'a at�yoruz 

        system("cls");
        Etiket("MUSTERI KAYIT EKLEME EKRANI");
        gotoxy(43, 7);
        cout << yeniKN;

        yeniMusteri = MusteriVeriAl();  //MusteriVeriAl'in donus degerini yeniMusteri'ye at�yoruz
        yeniMusteri.musteriNo = yeniKN;    // MusteriVeriAl ile no almadik,musteriNo'ya num'u atiyoruz
        gotoxy(30, 12);
        cout << "Kaydedilsin mi?(e/h): ";  //verileri kaydetmek icin onay aliyoruz
        getline(cin, cvp);
        if (cvp == "e")                    //onaylanirsa veri kaydedilir
        {
            MusteriKaydet(yeniMusteri);     //Musteri'yi dosyaya kaydediyor
            kayitNo.KyitNoKaydet(0,yeniKN);      //kayit numarasi kaybolmasin diye dosyaya yaziyo

        }
        else
        {
            gotoxy(30, 13);   
            cout << "Veriler kaydedilmedi. [enter]";
            getline(cin, cvp);
        }

        gotoxy(30, 14);   //yeni kayit icin onay al�n�yor
        cout << "Yeni kayit yapilacak mi?(e/h)?";
        getline(cin, cvp);
        
    } while (cvp == "e"); //cevap evet oldu�u s�rece d�ng� devam eder


    
}

void SnfMusteri::MusteriKaydet(ypMusteriVerileri kayitMusteri)
{
    //kendisine g�nderilen yap�n�n i�indeki verileri dosyaya kaydeder
    fstream dosyaYaz;
    dosyaYaz.open("musteri.dat", ios::binary | ios::app);
    dosyaYaz.write((char*)&kayitMusteri, sizeof(kayitMusteri));
    dosyaYaz.close();
}

ypMusteriVerileri SnfMusteri::KayitSirasindakiMusteri(int sira)
{
    // kendisine g�nderilen s�radaki m��terinin verilerini siradakiMusteri yap�s�na at�p geri d�nd�r�r
    ypMusteriVerileri siradakiMusteri = { 0,"","" };
    fstream dosyaOku;

    dosyaOku.open("musteri.dat", ios::binary| ios::in);
    dosyaOku.seekg(sira * sizeof(ypMusteriVerileri), ios::beg); //dosya basindan yap� uzunlugu*sira kadar atl�yor yani sira. s�radaki kayd�n ba��na gelior
    dosyaOku.read((char*)&siradakiMusteri, sizeof(ypMusteriVerileri)); //yap� uzunlugu kadar okuyup yap�ya at�or

    dosyaOku.close();
    return siradakiMusteri;
}

void SnfMusteri::VeriGoster(ypMusteriVerileri veriler)
{
    Etiket("VERI GOSTERME EKRANI");
    gotoxy(43, 7);
    cout << veriler.musteriNo;
    gotoxy(43, 8);
    cout << veriler.musteriAd;
    gotoxy(43, 9);
    cout << veriler.telNo;
    
    
}

void SnfMusteri::VeriListele()
{
    int y = 8;
    int bekle;
    ypMusteriVerileri listeMusteri = { 0,"","" };
    fstream dosya;
    dosya.open("musteri.dat", ios::binary | ios::in);  
    gotoxy(30, 4);
    cout << " V E R I   L I S T E L E M E   E K R A N I";
    gotoxy(30,6 );
    cout << "M. NO     AD SOYAD                 TEL NO"<<endl;
    gotoxy(30, 7);
    cout << "------     --------------------     -----------";

    
    while (dosya.peek() != EOF) //dosyan�n sonuna gelene kadar
    {
        // listeMusteri yap�s�na dosyadan 1 yap�(kay�t)uzunlu�unda veriyi at�p onu ekrana yazd�r�yor
        dosya.read((char*)&listeMusteri, sizeof(listeMusteri));
        gotoxy(30, y);
        cout <<setw(6)<<  listeMusteri.musteriNo<<"     "<<setiosflags(ios::left) << setw(20) << listeMusteri.musteriAd << resetiosflags(ios::left)<<"     "<< setw(11) << listeMusteri.telNo;
        y++;
        

    }
    dosya.close();
    gotoxy(30, y + 1);
    cout << "[ENTER]";
    VeriAl(bekle);
}

ypMusteriVerileri SnfMusteri::KayitArama(int arananNo)
{
    // noya g�re musteri ar�yoruz
    ypMusteriVerileri bulunan = { 0,"","" };
    
    ifstream dosya;
    dosya.open("musteri.dat", ios::binary | ios::in);
    
    while (dosya.peek() != EOF) //dosya sonuna gelene kadar 

    {
        dosya.read((char*)&bulunan, sizeof(bulunan)); // 1 kay�t okunur 
        if (bulunan.musteriNo == arananNo)            //kayd�n nosu aranan noya e�itse
        {
            dosya.close();
            return bulunan; //bulunan� d�nd�r (fonksiyondan ��k�or)
            
        }

    }
    bulunan = { -1,"","" }; //de�ilse bunu d�nd�r (bulunamad�)
    return bulunan;

}


void SnfMusteri::KayitIncele()
{
    // no ile kay�t inceliyoruz
    ypMusteriVerileri incelenecek;
    int arananNo = 0;
    gotoxy(30, 5);
    cout <<"KAYIT INCELEME EKRANI";
    gotoxy(30, 6);
    cout << "Aranacak numaray� girin (iptal icin 0 girin): ";
    VeriAl(arananNo); // aranacak noyu al�yoruz
    if (arananNo == 0) return ; // 0 girilirse i�lem iptal

    incelenecek = KayitArama(arananNo); // no ile kay�t ar�yoruz
    
    if (incelenecek.musteriNo == -1) // kayitarama ile d�nen de�er -1 ise bulunamam��t�r
    {
        gotoxy(30, 8);
        cout << "Bulunamadi.[enter]";
        VeriAl(arananNo); //sadece bekletmek icin
    }
    else
    {
     // bulunursa ekranda g�sterilir   
        VeriGoster(incelenecek);
        gotoxy(30, 11);
        cout << "Bulundu.[enter]";
        VeriAl(arananNo);
    }

    
}

void SnfMusteri::MusteriIslemleri()
{
    //fonksiyonlari tercihe gore cagirmacalar
    int secim;
    int temp = 0;
    do
    {
        system("cls");
        gotoxy(30, 4);
        cout << "MUSTERI ISLEMLERI";
        gotoxy(30, 5);
        cout << "1- Musteri Ekle";
        gotoxy(30, 6);
        cout << "2- Musteri Listele";
        gotoxy(30, 7);
        cout << "3- Musteri Incele";
        gotoxy(30, 8);
        cout << "4- Musteri Sil";
        gotoxy(30, 9);
        cout << "5-Musteri Guncelle ";
        gotoxy(30, 10);
        cout << "SECIMINIZ: ";
        VeriAl(secim);

        switch (secim)
        {
        case 1:
            system("cls");
            MusteriEkle();
            break;
        case 2:
            system("cls");
            VeriListele();
            break;
        case 3:
            system("cls");
            KayitIncele();
            break;
        case 4:
            system("cls");
            MusteriSil();
            break;
        case 5:
            system("cls");
            MusteriGuncelle();
            break;

        }
    } while (secim != 6);
}

void SnfMusteri::DosyadanSil(int silNo)
{
    fstream dosya;   //orijinal dosyam�z
    ypMusteriVerileri musteri = { 0,"","" };
    dosya.open("musteri.dat", ios::binary | ios::in);

    ofstream gecici; // silerken kullanaca��m�z ge�ici dosya
    gecici.open("gecici.dat", ios::binary | ios::out);

    while (dosya.peek() != EOF) // dosya sonuna gelene kadar
    {
        dosya.read((char*)&musteri, sizeof(ypMusteriVerileri)); // yap� b�yk. veri oku,musteri verisine at

        if (silNo != musteri.musteriNo) // musteri numarasi gelen noya esit degilse
        {
            // yani silinecek veriye daha gelmemissek
            gecici.write((char*)&musteri, sizeof(ypMusteriVerileri));  // verileri gecici dosyaya at
        }
    }
    dosya.close();
    gecici.close();
    remove("musteri.dat"); //orijinali sil
    rename("gecici.dat", "musteri.dat");// geciciyi orijinalin ad�yla degistir
}

void SnfMusteri::MusteriSil()
{
    // burada silme arayuzu saglaniyo sadece, dosyadansil fonks cagiriyoruz bi de

    // no ile kay�t inceliyoruz
    ypMusteriVerileri incelenecek;
    int arananNo = 0;
    string kySil;
    gotoxy(30, 5);
    cout << "KAYIT SILME EKRANI";
    gotoxy(30, 6);
    cout << "Silinecek numarayi girin (iptal icin 0 girin): ";
    VeriAl(arananNo); // aranacak noyu al�yoruz
    if (arananNo == 0) return; // 0 girilirse i�lem iptal

    incelenecek = KayitArama(arananNo); // no ile kay�t ar�yoruz

    if (incelenecek.musteriNo == -1) // kayitarama ile d�nen de�er -1 ise bulunamam��t�r
    {
        gotoxy(30, 8);
        cout << "Bulunamadi.[enter]";
        VeriAl(arananNo); //sadece bekletmek icin
    }
    else
    {
        // bulunursa ekranda g�sterilir   
        VeriGoster(incelenecek);
        gotoxy(30, 11);
        cout << "Bu kaydi silmek istediginizden emin misiniz?(e/h)";
        VeriAl(kySil);
        if (kySil == "e")
        {
            DosyadanSil(incelenecek.musteriNo);
            gotoxy(30, 12);
            cout << "Silindi.[enter]";
            VeriAl(kySil);//bekletmek icin
            
        }
       
    }
}

void SnfMusteri::DosyadaGuncelle(int guncNo)
{
    
    fstream dosya;
    int gncAlan;
    int sira=0;
    char yeniAd[20]; // guncel veriyi alacagimiz degiskenler
    char yeniTel[11];
    ypMusteriVerileri musteri = { 0,"","" };
    dosya.open("musteri.dat", ios::binary | ios::in|ios::out);


    while (dosya.peek() != EOF) //dosya sonuna gelene kadar
    {
        dosya.read((char*)&musteri, sizeof(ypMusteriVerileri)); //yap� buyk.oku,musteriye at
        sira++; // (sira). musteri okundu

        if (musteri.musteriNo == guncNo) //nolar esitse
        {
            gotoxy(28, 8);
            cout << "1-";
            gotoxy(28, 9);
            cout << "2-";
            gotoxy(30, 12);
            cout << "Hangi alan guncellensin?";
            VeriAl(gncAlan); //guncellenecek alani secmeceler
            if (gncAlan == 1)
            {

                gotoxy(43, 8);
                cout << "                    ";
                gotoxy(43, 8);
                VeriAl(yeniAd,20);
                strcpy_s(musteri.musteriAd, yeniAd); //yeniada girileni musteri.ada kopyala
               

                dosya.seekp((sira-1) * sizeof(ypMusteriVerileri), ios::beg);// (sira). kayda gel              
                dosya.write((char*)&musteri, sizeof(ypMusteriVerileri)); // direkt musteri yapisini yaz cunku degistirmedigin yerler zaten ayni kaldi
                break; //donguden cikioz
            }
            else if (gncAlan == 2)
            {
                //yukardakini aynisi
                gotoxy(43, 9);
                cout << "                    ";
                gotoxy(43, 9);
                VeriAl(yeniTel, 11);
                strcpy_s(musteri.telNo, yeniTel);

                dosya.seekp((sira-1) * sizeof(ypMusteriVerileri), ios::beg);
                dosya.write((char*)&musteri, sizeof(ypMusteriVerileri));
                break;
            }


        }
    }
    dosya.close();
}

void SnfMusteri::MusteriGuncelle()
{
    // guncelleme arayuzu sagliyo
    // no ile kay�t inceliyoruz
    ypMusteriVerileri incelenecek;
    int arananNo = 0;
    string kyGncl;
    gotoxy(30, 5);
    cout << "KAYIT INCELEME EKRANI";
    gotoxy(30, 6);
    cout << "Guncellenecek numaray� girin (iptal icin 0 girin): ";
    VeriAl(arananNo); // aranacak noyu al�yoruz
    if (arananNo == 0) return; // 0 girilirse i�lem iptal

    incelenecek = KayitArama(arananNo); // no ile kay�t ar�yoruz

    if (incelenecek.musteriNo == -1) // kayitarama ile d�nen de�er -1 ise bulunamam��t�r
    {
        gotoxy(30, 8);
        cout << "Bulunamadi.[enter]";
        VeriAl(arananNo); //sadece bekletmek icin
    }
    else
    {
        // bulunursa ekranda g�sterilir   
        VeriGoster(incelenecek);
        gotoxy(30, 11);
        cout << "Bu kaydi guncellemek istediginizden emin misiniz?(e/h)";
        VeriAl(kyGncl);
        if (kyGncl == "e")
        {
            DosyadaGuncelle(incelenecek.musteriNo);
            gotoxy(30, 13);
            cout << "Guncellendi.[enter]";
            VeriAl(kyGncl);
            

        };
    }
}







