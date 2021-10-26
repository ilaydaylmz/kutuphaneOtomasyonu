/************************************************************************************************************************************************************************************************
**                                                                 SAKARYA ÜNÝVERSÝTESÝ 
**                                                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                                                              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                                                               PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**                                                                  ÖDEV NUMARASI: PROJE1
**                                                                  ÖÐRENCÝ ADI: ÝLAYDA YILMAZ 
**                                                                  ÖÐRENCÝ NUMARASI:B201210057
**                                                                  DERS GRUBU:1B GRUBU
**************************************************************************************************************************************************************************************************/
#include<iostream>                //gerekli olan kütüphaneleri ekledim.
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
	auto start = chrono::system_clock::now();                             //kullanýcýnýn programa giris saatini yazdýrdým.
	auto simdi = chrono::system_clock::to_time_t(start);
	char giris_saat[30];
	ctime_s(giris_saat, sizeof(giris_saat),& simdi);
	cout << "GIRIS SAATI:" << giris_saat << endl;
	int secim;
	string Kullanici_adi;
	string Sifre;
	string Tc_No;
	string ad;
	string soyadý;
	string uye_no;
	string telefon;
	string dogum_tarihi;
	string gorevi;
	string alabilecegi_kitap_sayisi;
	string Okuyucu_Tc_No;
	string Kitap_Ýsbn;
	string Kitap_ismi;
	string Yazar_adi;
	string Yazar_soyadi;
	string Konu;
	string Tur;
	string Sayfa_sayisi;
	string odunc_tarihi;
	string donus_tarihi;


	ifstream Dosya1;    //okuyucu isimli dosya oluþturdum.
	Dosya1.open("okuyucu.txt", ios::app);
	if (Dosya1.is_open() == true)
	{
		string Okuyucu_Tc_No;                          //okuyucu dosyasýnda olmasý gereken bilgileri yazdým ve okuyucu dosyasýna tanýmladým.
		string Ad;
		string Soyadi;
		string Üye_No;
		string Telefon;
		string Dogum_Tarihi;
		string Gorevi;
		string Alabilecegi_kitap_sayisi;
		Dosya1 >> Okuyucu_Tc_No;
		Dosya1 >> Ad;
		Dosya1 >> Soyadi;
		Dosya1 >> Üye_No;
		Dosya1 >> Telefon;
		Dosya1 >> Dogum_Tarihi;
		Dosya1 >> Gorevi;
		Dosya1 >> Alabilecegi_kitap_sayisi;

	}
	Dosya1.close();

	ifstream Dosya2;    //kitaplar isimli bir dosya oluþturdum
	Dosya2.open("kitaplar.txt", ios::app);
	if (Dosya2.is_open() == true)
	{
		string Kitap_Ýsbn;                           //kitaplar dosyasýnda olmasý gereken bilgileri yazdým ve kitaplar dosyasýna tanýmladým.
		string Kitap_ismi;
		string Yazar_adi;
		string Yazar_soyadi;
		string Konu;
		string Tur;
		string Sayfa_sayisi;
		Dosya2 >> Kitap_Ýsbn;
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
		string ÝSBN;      //odunc dosyasýnda olmasý gereken bilgileri yazdým ve odunc dosyasýna tanýmladým.
		string TC_NO;
		string Odunc_tarihi;
		string Donus_tarihi;
		Dosya3 >> ÝSBN;
		Dosya3 >> TC_NO;
		Dosya3 >> Odunc_tarihi;
		Dosya3 >> Donus_tarihi;
	}
	Dosya3.close();

	ifstream Dosya4;    //kullanicilar isimli bir dosya oluþturdum.
	Dosya4.open("kullanicilar.txt");
	if (Dosya4.is_open() == true)
	{
		string Kullanici_adi;              //dosyada olmasý gereken bilgileri yazdýrdým.
		string Sifre;
		Dosya4 >> Kullanici_adi >> Sifre;
	}

	ofstream Dosya4Yaz;    //kullanicilar dosyasýna kullanici kaydettim.
	Dosya4Yaz.open("kullanicilar.txt");
	Dosya4Yaz << Kullanici_adi << "1234" << endl << Sifre << "1234" << endl;
	Dosya4Yaz << Kullanici_adi << "aaa" << endl << Sifre << "aaa" << endl;
	Dosya4Yaz.close();        //kaydetme islemi bittiði için dosyayý kapattým.


	ifstream Dosya4Oku("kullanici.txt");            //kullanicilar dosyasýný okuttum.
	while (!Dosya4Oku.eof())
	{
		string kullanici_adi;
		string sifre;
		cout << "kullanici adi giriniz:";      //kullanici adi girilmesini istedim.
		cin >> kullanici_adi;
		cout << "sifre giriniz:";
		cin >> sifre;
		Dosya4Oku >> Kullanici_adi >> Sifre;
		if ((kullanici_adi=="1234"&&sifre=="1234") || (kullanici_adi=="aaa"&& sifre=="aaa") )      //þifre ya da kullanici adi hatali ise çalýþmaz.
		{
			Dosya4Oku.close();
			do
			{
				cout << "YAPMAK ISTEDIGINIZ ISLEMI SECINIZ:" << endl;          //giris baþarýlý bir þekilde gercekleþtiyse seçenekler kullanýcýnýn karþýsýna çýkar.
				cout << "1-Okuyucu kaydi" << endl;
				cout << "2-Okuyucu kaydi güncelleme" << endl;
				cout << "3-Okuyucu kaydi silme" << endl;
				cout << "4-Okuyucu üzerindeki kitaplar listesi" << endl;
				cout << "5-Okuyucu kitap odunc alma" << endl;
				cout << "6-Okuyucu kitap geri dondurme" << endl;
				cout << "7-Kitap ekleme" << endl;
				cout << "8-Kitap silme" << endl;
				cout << "9-Kitap duzeltme" << endl;
				cout << "Secim:";
				cin >> secim;
			} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
			char cevap;
			if (secim == 1)       //1.secenek secildigi zaman calýsýr.
			{
				cout << ".....Secilen islem 1-okuyucu kaydi.....";
				ofstream Dosya1Yaz;
				Dosya1Yaz.open("okuyucu.txt", ios::app);            //okuyucu dosyasýný ekleme modunda açtým.
				do
				{
					cout << "\n TC NO:";
					cin >> Okuyucu_Tc_No;
					cout << "\n Ad:";
					cin >> ad;
					cout << "\n Soyadi:";
					cin >> soyadý;
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
					//dýþarýdan girilen bilgileri okuyucu dosyasýna yazdýrdým.
					Dosya1Yaz << Okuyucu_Tc_No << " " << endl << ad << " " << endl << soyadý << " " << endl << uye_no << " " << endl << dogum_tarihi << " " << endl << gorevi << " " << endl << alabilecegi_kitap_sayisi << endl;
					cout << "\n Baska kayit yapacak misin? (e/h)";
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya1Yaz.close();             //yazýlan bilgileri kaydedip dosyayý kapattým.
				cout << "\n okuyucu kaydi tamamlandi." << endl;               //kayýtýn tamamlandýgýný belirtim bitirdim.
			}

			if (secim == 2)                //2 numaralý secenek seçildiði zaman calýþýr.
			{
				cout << ".....Secilen islem 2-kayit guncelleme.....";
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku("okuyucu.txt");
				ofstream Dosya_okuyucu("okuyucu.tmp");
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //okuyucu tc no ile girilen tc no ayný ise çalýþýr.
					{
						ofstream Dosya_okuyucuYaz;
						Dosya_okuyucu.open("okuyucu.tmp", ios::out);      //gecici dosyaya duzeltilen bilgileri kaydettim.
						cout << "\n Okuyucu_Tc_No:";
						cin >> Okuyucu_Tc_No;
						cout << "\n Ad:";
						cin >> ad;
						cout << "\n Soyadi:";
						cin >> soyadý;
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
						Dosya_okuyucuYaz.close();     //gecici dosyaya yazma islemini tamamladým.
						cout << "\n Kitap duzeltme islemi tamamlanmýstýr.";
					}
					else
						cout << "Yanlýs TC NO girdiniz.";    //yanlýþ tc no girildiði zaman çalýþýr.
				}
				Dosya1Oku.close();     //okuyucu dosyasýný kapattým.
				Dosya_okuyucu.close();
				remove("okuyucu.txt");       //okuyucu dosyasýný sildim
				rename("okuyucu.tmp", "okuyucu.txt");     //dosyalarýn ismini deðiþtirdim.
			}

			if (secim == 3)                 //3.secenek seçildiði zaman calýþýr.
			{
				cout << ".....Secilen islem 3- okuyucu silme....." << endl;
				ifstream Dosya1Oku;                         //okuyucu dosyasýný açtým.
				Dosya1Oku.open("okuyucu.txt");
				ofstream Dosya_okuyucu;
				Dosya_okuyucu.open("okuyucu.tmp", ios::app);             //okuyucu isimli gecici bir dosya oluþturdum ve ekleme modunda açtýrdým.
				cout << "\n TC NO:";
				cin >> Tc_No;
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //dýþarýdan girilen tc no ile sistemdeki tc no ayný ise çalýþýr.
					{
						ofstream Dosya1Yaz;
						Dosya1Yaz.open("okuyucu.txt", ios::out);      //sistemde varolan bilgilerin yerine "" karakterini yazdýrdým.
						Tc_No == "";
						ad == "";
						soyadý == "";
						uye_no == "";
						telefon == "";
						dogum_tarihi == "";
						gorevi == "";
						alabilecegi_kitap_sayisi == "";
						Dosya1Yaz.close();                      //yazma islemini tamamladýgým icin dosyayý kapattým.
						cout << "\n Kayit silme tamamlanmýstýr.";                 //silme isleminin bittigini belirttim ve sonlandýrdým.
					}
				}
				Dosya1Oku.close();           //okuyucu dosyaysýný kapattým.
				Dosya_okuyucu.close();            //gecici olan okuyucu dosyasýný kapattým. 
				remove("okuyucu.txt");            //okuyucu isimli dosyayý sildim.
				rename("okuyucu.tmp", "okuyucu.txt");                 //gecici dosyanýn ismini deðiþtirdim.
			}

			if (secim == 4)               //4numaralý secim yapýldýgý zaman çalýþýr.
			{
				cout << ".....Secilen islem 4- okuyucu uzerindeki kitap listesi....." << endl;
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt");
				while (!Dosya1Oku.eof())           //baðlantý kurmak için okuyucu dosyasýný okuttum.
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)            //dýþarýdan girilen tc no ile okuyucu tc no ayný ise çalýþýr.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						Dosya3Oku.open("odunc.txt");          //odunc dosyasýný okuttum.
						while (!Dosya3Oku.eof())
						{
							Dosya3Oku >> Kitap_Ýsbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())             //dosya3 okumasý tamamlandýgý zaman calýþýr.
							{
								Dosya3Oku.close();
								cout << "\n okuyucu uzerindeki kitaplar:" << endl;           //okuyucunun odunc aldýðý kitaplarý listeledim.
								cout << Kitap_Ýsbn << "Isbn numarali kitap" << endl << Okuyucu_Tc_No << "Okuyucu tc no" << endl << odunc_tarihi << "Odunc tarihi" << endl << donus_tarihi << "Donus tarihi" << endl;
							}
						}
					}
					else
						cout << "\n Hatali TC NO girilmistir.";       //okuyucu tc no ile dýþarýdan girilen tc no ayný deðil ise çalýþýr.
				}
			}

			if (secim == 5)          //5 numaralý secim yapýldýgý zaman çalýþýr.
			{
				string Ýsbn;
				cout << ".....Secilen islem 5-okuyucu kitap odunc alma....." << endl;
				cout << "tc no:";
				cin >> Tc_No;
				ifstream Dosya1Oku;           //okuyucu isimli dosyayý açtým.
				Dosya1Oku.open("okuyucu.txt", ios::in);
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					Dosya1Oku.close();                            //okuyucu dosyasýndaki verileri okuttum.
					ofstream Dosya3;
					Dosya3.open("odunc.txt", ios::app);
					if (Tc_No == Okuyucu_Tc_No)               //okuycu tc'si ile dýþarýdan girilen tc'nin ayný olduðu zaman çalýþýr.
					{
						cout << "\n Odunc almak istediginiz kitabýn ÝSBN numarasýný  giriniz:";
						cin >> Ýsbn;
						ifstream Dosya2Oku;
						Dosya2Oku.open("kitaplar.txt", ios::in);                //dýþarýdan girilen isbn numarasýna sahip kitap olup olmadýðýný kontrol etmek için kitaplar dosyasýný okumaya açtým.
						while (!Dosya2Oku.eof())
						{
							Dosya2Oku >> Kitap_Ýsbn >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
							if (Ýsbn == Kitap_Ýsbn)                    //dýþarýdan girilen isbn ile kitap isbn uyumlu ise çalýþýr.
							{
								Dosya2Oku.close();
								ofstream Dosya3Yaz;
								Dosya3Yaz.open("odunc.txt", ios::app);               //odunc dosyasýný yazmak için açtým.
								cout << "Ýsbn:";
								cin >> Kitap_Ýsbn;
								cout << "Tc No:";
								cin >> Okuyucu_Tc_No;
								cout << "odunc tarihi:";
								cin >> odunc_tarihi;
								cout << "donus tarihi:";
								cin >> donus_tarihi;
								Dosya3Yaz << Kitap_Ýsbn << "" << endl << Okuyucu_Tc_No << "" << endl << odunc_tarihi << "" << endl << donus_tarihi << endl;   //odunc bilgilerini odunc isimli dosyaya yazdýrdým.
								Dosya3Yaz.close();
								cout << Kitap_Ýsbn << "ÝSBN numarali kitabi odunc aldiniz.";
							}
							else
								cout << "hatali ÝSBN girilmistir.";            //dýþarýdan girilen isbn ile kitap isbn uyumlu deðil ise çalýþýr.
						}
					}
					else
						cout << "hatalý TC NO girilmistir.";              //dýþarýdan girilen tc ile okuyucu tc uyuþmuyorsa çalýþýr.
				}

			}

			if (secim == 6)       //6 numaralý secenek secildiði zaman çalýþýr.
			{
				string Ýsbn;
				string Tc_No;
				cout << ".....Secim 6-okuyucu kitap geri dondurme....." << endl;
				cout << "TC NO:";       //baðlantý kurmak için kullanicidan tc no girmesini istedim.
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt", ios::in);     //okuyucu dosyasýný açtýrdým.
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadý >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;  //okuyucu dosyasýndaki verileri dosyadan okudum.
					if (Tc_No == Okuyucu_Tc_No)          //dýþarýdan girilen tc no ile okuyucu tc no ayný ise çalýþýr.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						ofstream Dosya_odunc;
						Dosya3Oku.open("odunc.txt", ios::in);
						while (!Dosya3Oku.eof())       //odunc dosyasýný okuttum.
						{
							Dosya3Oku >> Kitap_Ýsbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())        //odunc dosyasýnýn okumasý tamamlandýysa çalýþýr.
							{
								Dosya3Oku.close();
								cout << "geri verilecek olan kitap isbn:";  //kullanýcýdan okuyucunun iade edeceði kitabýn isbn numarasýný girmesini istedim.
								cin >> Ýsbn;
								if (Ýsbn == Kitap_Ýsbn)           //okuyucunun odunc aldýðý kitap isbn numarasý ile dýþarýdan girilen isbn numarasý ayný ise çalýþýr.
								{
									ofstream Dosya3Yaz;
									Dosya3Yaz.open("odunc.txt", ios::out);      //odunc dosyasýndaki bilgileri ""karakteri ile deðiþtirdim ve kitabýn odunc dosyasýndan silinmesini saðladým.
									Kitap_Ýsbn == "";
									Okuyucu_Tc_No == "";
									odunc_tarihi == "";
									donus_tarihi == "";
									Dosya3Yaz.close();      //odunc dosyasýna yazma islemini tamamladým.
									cout << "kitap iade islemi tamamlanmýstýr.";       //kullaniciya iade iþleminin baþarýyla gercekleþtiðini belirttim.
								}
							}
						}
						Dosya3Oku.close();      //dosya3'ün okuma modunu kapattým.
						Dosya_odunc.close();      //gecici dosyayý kapattým.
						remove("odunc.txt");     //odunc dosyasýný sildim.
						rename("odunc.tmp", "odunc.txt");      //dosyalarýn ismini deðiþtirdim.
					}
				}
			}

			if (secim == 7)           //7numaralý secenek seçildiði zaman çalýþýr.
			{
				cout << ".....Secilen islem 7-kitap ekleme....." << endl;
				ofstream Dosya2Yaz;            //kitaplar dosyasýný yazma modunda açtým.
				Dosya2Yaz.open("kitaplar.txt", ios::app);        // app modunda açtým.
				do
				{
					cout << "ÝSBN:";             //kitaplar dosyasýnda istenen bilgileri kullancýdan kaydedeceði kitaba uygun bir þekilde girmesini istedim.
					cin >> Kitap_Ýsbn;
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
					Dosya2Yaz << Kitap_Ýsbn << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi; //girilen bilgileri dosyaya yazdýrdým.
					cout << "baska kitap ekleyecek misiniz(e/h):";    //kitap eklemeye devam edip edilmeyeceðini sordum.
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya2Yaz.close();       //dosyayý kapattým.
				cout << "kitap ekleme islemi tamamlanmýstýr.";         //kitap ekleme isleminin bittiðini kullaniciya bildirdim.
			}

			if (secim == 8)                    //8.secenek secildiði zaman calýþýr.
			{
				string Ýsbn;
				cout << ".....Secilen islem 8-kitap silme.....";
				ifstream Dosya2Oku;                              //kitaplar dosyasýnýn verilerinin okuma modunu açtým.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "ÝSBN:";               //silinmek istenen kitabýn isbn numarasýný istedim.
				cin >> Ýsbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_Ýsbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;   //kitaplar dosyasýndaki verileri okuttum.
					if (Ýsbn == Kitap_Ýsbn)        //dýþarýdan girilen isbn ile sistemde kayýtlý olan isbn aynýysa çalýþýr.
					{
						ofstream Dosya2Yaz;
						Dosya2Yaz.open("kitaplar.txt", ios::out);
						Kitap_Ýsbn == "";                    //kayýtlý olan verilerin yerine "" karakterini yazdýrdým.
						Kitap_ismi == "";
						Yazar_adi == "";
						Yazar_soyadi == "";
						Konu == "";
						Tur == "";
						Sayfa_sayisi == "";
						Dosya2Yaz.close();
						cout << "\n Kitap silme islemi tamamlanmýstýr.";        // silme isleminin bittiðini kullanýcýya belirttim.
					}
				}
				Dosya2Oku.close();
				Dosya_kitap.close();
				remove("kitaplar.txt");               //kitaplar dosyasýný sildim.
				rename("kitaplar.tmp", "kitaplar.txt");               //dosyanýn adýný deðiþtirdim.
			}

			if (secim == 9)           //9 numaralý secenek seçildiði zaman çalýþýr.
			{
				string Ýsbn;
				cout << ".....secilen islem 9-kitap duzeltme....." << endl;
				ifstream Dosya2Oku;              //kitaplar dosyasýný okudum.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "kitap isbn:";         //kullanicidan duzeltilecek kitap isbn numarasýný girmesini istedim.
				cin >> Ýsbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_Ýsbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;  //kitaplardosyasýndaki verileri okudum.
					if (Ýsbn == Kitap_Ýsbn)     //girilen isbn ile uyumlu kitap varsa çalýþýr.
					{
						ofstream Dosya_kitap;         //gecici dosyaya veri yazdýrdým.
						Dosya_kitap.open("kitaplar.tmp", ios::out);
						cout << "kitap isbn:";
						cin >> Kitap_Ýsbn;
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
						cout << "\n Kitap duzeltme islemi tamamlanmýstýr.";    //duzeltme isleminin bittiðini kullanýcýya belirttim.
					}
					else
						cout << "\n Hatali ÝSBN girildi.";   //girilen isbn ile uyumlu kitap olmadýgý zaman çalýþýr.
				}
				Dosya2Oku.close();      //dosyalarý kapattým.
				Dosya_kitap.close();
				remove("kitaplar.txt"); //kitaplar dosyasýný sildim.
				rename("kitaplar.tmp", "kitaplar.txt");     //dosyanýn adýný deðiþtirdim.
			}
		}
		else
		cout << "hatali giris.";
		exit(1);
	}
}
