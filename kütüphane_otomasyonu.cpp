/************************************************************************************************************************************************************************************************
**                                                                 SAKARYA �N�VERS�TES� 
**                                                       B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                                                              B�LG�SAYAR M�HEND�SL��� B�L�M�
**                                                               PROGRAMLAMAYA G�R�� DERS�
**
**                                                                  �DEV NUMARASI: PROJE1
**                                                                  ��RENC� ADI: �LAYDA YILMAZ 
**                                                                  ��RENC� NUMARASI:B201210057
**                                                                  DERS GRUBU:1B GRUBU
**************************************************************************************************************************************************************************************************/
#include<iostream>                //gerekli olan k�t�phaneleri ekledim.
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<ctime>
#include<chrono>
using namespace std;
int main()
{
	auto start = chrono::system_clock::now();                             //kullan�c�n�n programa giris saatini yazd�rd�m.
	auto simdi = chrono::system_clock::to_time_t(start);
	char giris_saat[30];
	ctime_s(giris_saat, sizeof(giris_saat),& simdi);
	cout << "GIRIS SAATI:" << giris_saat << endl;
	int secim;
	string Kullanici_adi;
	string Sifre;
	string Tc_No;
	string ad;
	string soyad�;
	string uye_no;
	string telefon;
	string dogum_tarihi;
	string gorevi;
	string alabilecegi_kitap_sayisi;
	string Okuyucu_Tc_No;
	string Kitap_�sbn;
	string Kitap_ismi;
	string Yazar_adi;
	string Yazar_soyadi;
	string Konu;
	string Tur;
	string Sayfa_sayisi;
	string odunc_tarihi;
	string donus_tarihi;


	ifstream Dosya1;    //okuyucu isimli dosya olu�turdum.
	Dosya1.open("okuyucu.txt", ios::app);
	if (Dosya1.is_open() == true)
	{
		string Okuyucu_Tc_No;                          //okuyucu dosyas�nda olmas� gereken bilgileri yazd�m ve okuyucu dosyas�na tan�mlad�m.
		string Ad;
		string Soyadi;
		string �ye_No;
		string Telefon;
		string Dogum_Tarihi;
		string Gorevi;
		string Alabilecegi_kitap_sayisi;
		Dosya1 >> Okuyucu_Tc_No;
		Dosya1 >> Ad;
		Dosya1 >> Soyadi;
		Dosya1 >> �ye_No;
		Dosya1 >> Telefon;
		Dosya1 >> Dogum_Tarihi;
		Dosya1 >> Gorevi;
		Dosya1 >> Alabilecegi_kitap_sayisi;

	}
	Dosya1.close();

	ifstream Dosya2;    //kitaplar isimli bir dosya olu�turdum
	Dosya2.open("kitaplar.txt", ios::app);
	if (Dosya2.is_open() == true)
	{
		string Kitap_�sbn;                           //kitaplar dosyas�nda olmas� gereken bilgileri yazd�m ve kitaplar dosyas�na tan�mlad�m.
		string Kitap_ismi;
		string Yazar_adi;
		string Yazar_soyadi;
		string Konu;
		string Tur;
		string Sayfa_sayisi;
		Dosya2 >> Kitap_�sbn;
		Dosya2 >> Kitap_ismi;
		Dosya2 >> Yazar_adi;
		Dosya2 >> Yazar_soyadi;
		Dosya2 >> Konu;
		Dosya2 >> Tur;
		Dosya2 >> Sayfa_sayisi;
	}
	Dosya2.close();

	ifstream Dosya3;       //odunc isimli bir dosya olusturdum.
	Dosya3.open("odunc.txt", ios::app);
	if (Dosya3.is_open() == true)
	{
		string �SBN;      //odunc dosyas�nda olmas� gereken bilgileri yazd�m ve odunc dosyas�na tan�mlad�m.
		string TC_NO;
		string Odunc_tarihi;
		string Donus_tarihi;
		Dosya3 >> �SBN;
		Dosya3 >> TC_NO;
		Dosya3 >> Odunc_tarihi;
		Dosya3 >> Donus_tarihi;
	}
	Dosya3.close();

	ifstream Dosya4;    //kullanicilar isimli bir dosya olu�turdum.
	Dosya4.open("kullanicilar.txt");
	if (Dosya4.is_open() == true)
	{
		string Kullanici_adi;              //dosyada olmas� gereken bilgileri yazd�rd�m.
		string Sifre;
		Dosya4 >> Kullanici_adi >> Sifre;
	}

	ofstream Dosya4Yaz;    //kullanicilar dosyas�na kullanici kaydettim.
	Dosya4Yaz.open("kullanicilar.txt");
	Dosya4Yaz << Kullanici_adi << "1234" << endl << Sifre << "1234" << endl;
	Dosya4Yaz << Kullanici_adi << "aaa" << endl << Sifre << "aaa" << endl;
	Dosya4Yaz.close();        //kaydetme islemi bitti�i i�in dosyay� kapatt�m.


	ifstream Dosya4Oku("kullanici.txt");            //kullanicilar dosyas�n� okuttum.
	while (!Dosya4Oku.eof())
	{
		string kullanici_adi;
		string sifre;
		cout << "kullanici adi giriniz:";      //kullanici adi girilmesini istedim.
		cin >> kullanici_adi;
		cout << "sifre giriniz:";
		cin >> sifre;
		Dosya4Oku >> Kullanici_adi >> Sifre;
		if ((kullanici_adi=="1234"&&sifre=="1234") || (kullanici_adi=="aaa"&& sifre=="aaa") )      //�ifre ya da kullanici adi hatali ise �al��maz.
		{
			Dosya4Oku.close();
			do
			{
				cout << "YAPMAK ISTEDIGINIZ ISLEMI SECINIZ:" << endl;          //giris ba�ar�l� bir �ekilde gercekle�tiyse se�enekler kullan�c�n�n kar��s�na ��kar.
				cout << "1-Okuyucu kaydi" << endl;
				cout << "2-Okuyucu kaydi g�ncelleme" << endl;
				cout << "3-Okuyucu kaydi silme" << endl;
				cout << "4-Okuyucu �zerindeki kitaplar listesi" << endl;
				cout << "5-Okuyucu kitap odunc alma" << endl;
				cout << "6-Okuyucu kitap geri dondurme" << endl;
				cout << "7-Kitap ekleme" << endl;
				cout << "8-Kitap silme" << endl;
				cout << "9-Kitap duzeltme" << endl;
				cout << "Secim:";
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
			char cevap;
			if (secim == 1)       //1.secenek secildigi zaman cal�s�r.
			{
				cout << ".....Secilen islem 1-okuyucu kaydi.....";
				ofstream Dosya1Yaz;
				Dosya1Yaz.open("okuyucu.txt", ios::app);            //okuyucu dosyas�n� ekleme modunda a�t�m.
				do
				{
					cout << "\n TC NO:";
					cin >> Okuyucu_Tc_No;
					cout << "\n Ad:";
					cin >> ad;
					cout << "\n Soyadi:";
					cin >> soyad�;
					cout << "\n Uye no:";
					cin >> uye_no;
					cout << "\n Telefon:";
					cin >> telefon;
					cout << "\n Dogum tarihi:";
					cin >> dogum_tarihi;
					cout << "\n Gorevi:";
					cin >> gorevi;
					cout << "\n Alabilecegi kitap sayisi:";
					cin >> alabilecegi_kitap_sayisi;
					//d��ar�dan girilen bilgileri okuyucu dosyas�na yazd�rd�m.
					Dosya1Yaz << Okuyucu_Tc_No << " " << endl << ad << " " << endl << soyad� << " " << endl << uye_no << " " << endl << dogum_tarihi << " " << endl << gorevi << " " << endl << alabilecegi_kitap_sayisi << endl;
					cout << "\n Baska kayit yapacak misin? (e/h)";
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya1Yaz.close();             //yaz�lan bilgileri kaydedip dosyay� kapatt�m.
				cout << "\n okuyucu kaydi tamamlandi." << endl;               //kay�t�n tamamland�g�n� belirtim bitirdim.
			}

			if (secim == 2)                //2 numaral� secenek se�ildi�i zaman cal���r.
			{
				cout << ".....Secilen islem 2-kayit guncelleme.....";
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku("okuyucu.txt");
				ofstream Dosya_okuyucu("okuyucu.tmp");
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //okuyucu tc no ile girilen tc no ayn� ise �al���r.
					{
						ofstream Dosya_okuyucuYaz;
						Dosya_okuyucu.open("okuyucu.tmp", ios::out);      //gecici dosyaya duzeltilen bilgileri kaydettim.
						cout << "\n Okuyucu_Tc_No:";
						cin >> Okuyucu_Tc_No;
						cout << "\n Ad:";
						cin >> ad;
						cout << "\n Soyadi:";
						cin >> soyad�;
						cout << "\n Uye no:";
						cin >> uye_no;
						cout << "\n Telefon:";
						cin >> telefon;
						cout << "\n Dogum tarihi:";
						cin >> dogum_tarihi;
						cout << "\n Gorevi:";
						cin >> gorevi;
						cout << "\n Alabilecegi kitap sayisi:";
						cin >> alabilecegi_kitap_sayisi;
						Dosya_okuyucuYaz.close();     //gecici dosyaya yazma islemini tamamlad�m.
						cout << "\n Kitap duzeltme islemi tamamlanm�st�r.";
					}
					else
						cout << "Yanl�s TC NO girdiniz.";    //yanl�� tc no girildi�i zaman �al���r.
				}
				Dosya1Oku.close();     //okuyucu dosyas�n� kapatt�m.
				Dosya_okuyucu.close();
				remove("okuyucu.txt");       //okuyucu dosyas�n� sildim
				rename("okuyucu.tmp", "okuyucu.txt");     //dosyalar�n ismini de�i�tirdim.
			}

			if (secim == 3)                 //3.secenek se�ildi�i zaman cal���r.
			{
				cout << ".....Secilen islem 3- okuyucu silme....." << endl;
				ifstream Dosya1Oku;                         //okuyucu dosyas�n� a�t�m.
				Dosya1Oku.open("okuyucu.txt");
				ofstream Dosya_okuyucu;
				Dosya_okuyucu.open("okuyucu.tmp", ios::app);             //okuyucu isimli gecici bir dosya olu�turdum ve ekleme modunda a�t�rd�m.
				cout << "\n TC NO:";
				cin >> Tc_No;
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //d��ar�dan girilen tc no ile sistemdeki tc no ayn� ise �al���r.
					{
						ofstream Dosya1Yaz;
						Dosya1Yaz.open("okuyucu.txt", ios::out);      //sistemde varolan bilgilerin yerine "" karakterini yazd�rd�m.
						Tc_No == "";
						ad == "";
						soyad� == "";
						uye_no == "";
						telefon == "";
						dogum_tarihi == "";
						gorevi == "";
						alabilecegi_kitap_sayisi == "";
						Dosya1Yaz.close();                      //yazma islemini tamamlad�g�m icin dosyay� kapatt�m.
						cout << "\n Kayit silme tamamlanm�st�r.";                 //silme isleminin bittigini belirttim ve sonland�rd�m.
					}
				}
				Dosya1Oku.close();           //okuyucu dosyays�n� kapatt�m.
				Dosya_okuyucu.close();            //gecici olan okuyucu dosyas�n� kapatt�m. 
				remove("okuyucu.txt");            //okuyucu isimli dosyay� sildim.
				rename("okuyucu.tmp", "okuyucu.txt");                 //gecici dosyan�n ismini de�i�tirdim.
			}

			if (secim == 4)               //4numaral� secim yap�ld�g� zaman �al���r.
			{
				cout << ".....Secilen islem 4- okuyucu uzerindeki kitap listesi....." << endl;
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt");
				while (!Dosya1Oku.eof())           //ba�lant� kurmak i�in okuyucu dosyas�n� okuttum.
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)            //d��ar�dan girilen tc no ile okuyucu tc no ayn� ise �al���r.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						Dosya3Oku.open("odunc.txt");          //odunc dosyas�n� okuttum.
						while (!Dosya3Oku.eof())
						{
							Dosya3Oku >> Kitap_�sbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())             //dosya3 okumas� tamamland�g� zaman cal���r.
							{
								Dosya3Oku.close();
								cout << "\n okuyucu uzerindeki kitaplar:" << endl;           //okuyucunun odunc ald��� kitaplar� listeledim.
								cout << Kitap_�sbn << "Isbn numarali kitap" << endl << Okuyucu_Tc_No << "Okuyucu tc no" << endl << odunc_tarihi << "Odunc tarihi" << endl << donus_tarihi << "Donus tarihi" << endl;
							}
						}
					}
					else
						cout << "\n Hatali TC NO girilmistir.";       //okuyucu tc no ile d��ar�dan girilen tc no ayn� de�il ise �al���r.
				}
			}

			if (secim == 5)          //5 numaral� secim yap�ld�g� zaman �al���r.
			{
				string �sbn;
				cout << ".....Secilen islem 5-okuyucu kitap odunc alma....." << endl;
				cout << "tc no:";
				cin >> Tc_No;
				ifstream Dosya1Oku;           //okuyucu isimli dosyay� a�t�m.
				Dosya1Oku.open("okuyucu.txt", ios::in);
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					Dosya1Oku.close();                            //okuyucu dosyas�ndaki verileri okuttum.
					ofstream Dosya3;
					Dosya3.open("odunc.txt", ios::app);
					if (Tc_No == Okuyucu_Tc_No)               //okuycu tc'si ile d��ar�dan girilen tc'nin ayn� oldu�u zaman �al���r.
					{
						cout << "\n Odunc almak istediginiz kitab�n �SBN numaras�n�  giriniz:";
						cin >> �sbn;
						ifstream Dosya2Oku;
						Dosya2Oku.open("kitaplar.txt", ios::in);                //d��ar�dan girilen isbn numaras�na sahip kitap olup olmad���n� kontrol etmek i�in kitaplar dosyas�n� okumaya a�t�m.
						while (!Dosya2Oku.eof())
						{
							Dosya2Oku >> Kitap_�sbn >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
							if (�sbn == Kitap_�sbn)                    //d��ar�dan girilen isbn ile kitap isbn uyumlu ise �al���r.
							{
								Dosya2Oku.close();
								ofstream Dosya3Yaz;
								Dosya3Yaz.open("odunc.txt", ios::app);               //odunc dosyas�n� yazmak i�in a�t�m.
								cout << "�sbn:";
								cin >> Kitap_�sbn;
								cout << "Tc No:";
								cin >> Okuyucu_Tc_No;
								cout << "odunc tarihi:";
								cin >> odunc_tarihi;
								cout << "donus tarihi:";
								cin >> donus_tarihi;
								Dosya3Yaz << Kitap_�sbn << "" << endl << Okuyucu_Tc_No << "" << endl << odunc_tarihi << "" << endl << donus_tarihi << endl;   //odunc bilgilerini odunc isimli dosyaya yazd�rd�m.
								Dosya3Yaz.close();
								cout << Kitap_�sbn << "�SBN numarali kitabi odunc aldiniz.";
							}
							else
								cout << "hatali �SBN girilmistir.";            //d��ar�dan girilen isbn ile kitap isbn uyumlu de�il ise �al���r.
						}
					}
					else
						cout << "hatal� TC NO girilmistir.";              //d��ar�dan girilen tc ile okuyucu tc uyu�muyorsa �al���r.
				}

			}

			if (secim == 6)       //6 numaral� secenek secildi�i zaman �al���r.
			{
				string �sbn;
				string Tc_No;
				cout << ".....Secim 6-okuyucu kitap geri dondurme....." << endl;
				cout << "TC NO:";       //ba�lant� kurmak i�in kullanicidan tc no girmesini istedim.
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt", ios::in);     //okuyucu dosyas�n� a�t�rd�m.
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyad� >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;  //okuyucu dosyas�ndaki verileri dosyadan okudum.
					if (Tc_No == Okuyucu_Tc_No)          //d��ar�dan girilen tc no ile okuyucu tc no ayn� ise �al���r.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						ofstream Dosya_odunc;
						Dosya3Oku.open("odunc.txt", ios::in);
						while (!Dosya3Oku.eof())       //odunc dosyas�n� okuttum.
						{
							Dosya3Oku >> Kitap_�sbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())        //odunc dosyas�n�n okumas� tamamland�ysa �al���r.
							{
								Dosya3Oku.close();
								cout << "geri verilecek olan kitap isbn:";  //kullan�c�dan okuyucunun iade edece�i kitab�n isbn numaras�n� girmesini istedim.
								cin >> �sbn;
								if (�sbn == Kitap_�sbn)           //okuyucunun odunc ald��� kitap isbn numaras� ile d��ar�dan girilen isbn numaras� ayn� ise �al���r.
								{
									ofstream Dosya3Yaz;
									Dosya3Yaz.open("odunc.txt", ios::out);      //odunc dosyas�ndaki bilgileri ""karakteri ile de�i�tirdim ve kitab�n odunc dosyas�ndan silinmesini sa�lad�m.
									Kitap_�sbn == "";
									Okuyucu_Tc_No == "";
									odunc_tarihi == "";
									donus_tarihi == "";
									Dosya3Yaz.close();      //odunc dosyas�na yazma islemini tamamlad�m.
									cout << "kitap iade islemi tamamlanm�st�r.";       //kullaniciya iade i�leminin ba�ar�yla gercekle�ti�ini belirttim.
								}
							}
						}
						Dosya3Oku.close();      //dosya3'�n okuma modunu kapatt�m.
						Dosya_odunc.close();      //gecici dosyay� kapatt�m.
						remove("odunc.txt");     //odunc dosyas�n� sildim.
						rename("odunc.tmp", "odunc.txt");      //dosyalar�n ismini de�i�tirdim.
					}
				}
			}

			if (secim == 7)           //7numaral� secenek se�ildi�i zaman �al���r.
			{
				cout << ".....Secilen islem 7-kitap ekleme....." << endl;
				ofstream Dosya2Yaz;            //kitaplar dosyas�n� yazma modunda a�t�m.
				Dosya2Yaz.open("kitaplar.txt", ios::app);        // app modunda a�t�m.
				do
				{
					cout << "�SBN:";             //kitaplar dosyas�nda istenen bilgileri kullanc�dan kaydedece�i kitaba uygun bir �ekilde girmesini istedim.
					cin >> Kitap_�sbn;
					cout << "kitap ismi:";
					cin >> Kitap_ismi;
					cout << "yazar adi:";
					cin >> Yazar_adi;
					cout << "yazar soyadi:";
					cin >> Yazar_soyadi;
					cout << "konu:";
					cin >> Konu;
					cout << "tur:";
					cin >> Tur;
					cout << "sayfa sayisi:";
					cin >> Sayfa_sayisi;
					Dosya2Yaz << Kitap_�sbn << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi; //girilen bilgileri dosyaya yazd�rd�m.
					cout << "baska kitap ekleyecek misiniz(e/h):";    //kitap eklemeye devam edip edilmeyece�ini sordum.
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya2Yaz.close();       //dosyay� kapatt�m.
				cout << "kitap ekleme islemi tamamlanm�st�r.";         //kitap ekleme isleminin bitti�ini kullaniciya bildirdim.
			}

			if (secim == 8)                    //8.secenek secildi�i zaman cal���r.
			{
				string �sbn;
				cout << ".....Secilen islem 8-kitap silme.....";
				ifstream Dosya2Oku;                              //kitaplar dosyas�n�n verilerinin okuma modunu a�t�m.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "�SBN:";               //silinmek istenen kitab�n isbn numaras�n� istedim.
				cin >> �sbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_�sbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;   //kitaplar dosyas�ndaki verileri okuttum.
					if (�sbn == Kitap_�sbn)        //d��ar�dan girilen isbn ile sistemde kay�tl� olan isbn ayn�ysa �al���r.
					{
						ofstream Dosya2Yaz;
						Dosya2Yaz.open("kitaplar.txt", ios::out);
						Kitap_�sbn == "";                    //kay�tl� olan verilerin yerine "" karakterini yazd�rd�m.
						Kitap_ismi == "";
						Yazar_adi == "";
						Yazar_soyadi == "";
						Konu == "";
						Tur == "";
						Sayfa_sayisi == "";
						Dosya2Yaz.close();
						cout << "\n Kitap silme islemi tamamlanm�st�r.";        // silme isleminin bitti�ini kullan�c�ya belirttim.
					}
				}
				Dosya2Oku.close();
				Dosya_kitap.close();
				remove("kitaplar.txt");               //kitaplar dosyas�n� sildim.
				rename("kitaplar.tmp", "kitaplar.txt");               //dosyan�n ad�n� de�i�tirdim.
			}

			if (secim == 9)           //9 numaral� secenek se�ildi�i zaman �al���r.
			{
				string �sbn;
				cout << ".....secilen islem 9-kitap duzeltme....." << endl;
				ifstream Dosya2Oku;              //kitaplar dosyas�n� okudum.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "kitap isbn:";         //kullanicidan duzeltilecek kitap isbn numaras�n� girmesini istedim.
				cin >> �sbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_�sbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;  //kitaplardosyas�ndaki verileri okudum.
					if (�sbn == Kitap_�sbn)     //girilen isbn ile uyumlu kitap varsa �al���r.
					{
						ofstream Dosya_kitap;         //gecici dosyaya veri yazd�rd�m.
						Dosya_kitap.open("kitaplar.tmp", ios::out);
						cout << "kitap isbn:";
						cin >> Kitap_�sbn;
						cout << "kitap ismi:";
						cin >> Kitap_ismi;
						cout << "yazar adi:";
						cin >> Yazar_adi;
						cout << "yazar soyadi:";
						cin >> Yazar_soyadi;
						cout << "konu:";
						cin >> Konu;
						cout << "sayfa_sayisi:";
						cin >> Sayfa_sayisi;
						Dosya_kitap.close();
						cout << "\n Kitap duzeltme islemi tamamlanm�st�r.";    //duzeltme isleminin bitti�ini kullan�c�ya belirttim.
					}
					else
						cout << "\n Hatali �SBN girildi.";   //girilen isbn ile uyumlu kitap olmad�g� zaman �al���r.
				}
				Dosya2Oku.close();      //dosyalar� kapatt�m.
				Dosya_kitap.close();
				remove("kitaplar.txt"); //kitaplar dosyas�n� sildim.
				rename("kitaplar.tmp", "kitaplar.txt");     //dosyan�n ad�n� de�i�tirdim.
			}
		}
		else
		cout << "hatali giris.";
		exit(1);
	}
}
