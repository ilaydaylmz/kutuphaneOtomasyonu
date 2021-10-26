/************************************************************************************************************************************************************************************************
**                                                                 SAKARYA ÜNİVERSİTESİ 
**                                                       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                                                              BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                                               PROGRAMLAMAYA GİRİŞ DERSİ
**                                                                       PROJE1
**                                                                   İLAYDA YILMAZ 
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
	auto start = chrono::system_clock::now();                             //kullanıcının programa giris saatini yazdırdım.
	auto simdi = chrono::system_clock::to_time_t(start);
	char giris_saat[30];
	ctime_s(giris_saat, sizeof(giris_saat),& simdi);
	cout << "GIRIS SAATI:" << giris_saat << endl;
	int secim;
	string Kullanici_adi;
	string Sifre;
	string Tc_No;
	string ad;
	string soyadı;
	string uye_no;
	string telefon;
	string dogum_tarihi;
	string gorevi;
	string alabilecegi_kitap_sayisi;
	string Okuyucu_Tc_No;
	string Kitap_İsbn;
	string Kitap_ismi;
	string Yazar_adi;
	string Yazar_soyadi;
	string Konu;
	string Tur;
	string Sayfa_sayisi;
	string odunc_tarihi;
	string donus_tarihi;


	ifstream Dosya1;    //okuyucu isimli dosya oluşturdum.
	Dosya1.open("okuyucu.txt", ios::app);
	if (Dosya1.is_open() == true)
	{
		string Okuyucu_Tc_No;                          //okuyucu dosyasında olması gereken bilgileri yazdım ve okuyucu dosyasına tanımladım.
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

	ifstream Dosya2;    //kitaplar isimli bir dosya oluşturdum
	Dosya2.open("kitaplar.txt", ios::app);
	if (Dosya2.is_open() == true)
	{
		string Kitap_İsbn;                           //kitaplar dosyasında olması gereken bilgileri yazdım ve kitaplar dosyasına tanımladım.
		string Kitap_ismi;
		string Yazar_adi;
		string Yazar_soyadi;
		string Konu;
		string Tur;
		string Sayfa_sayisi;
		Dosya2 >> Kitap_İsbn;
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
		string İSBN;      //odunc dosyasında olması gereken bilgileri yazdım ve odunc dosyasına tanımladım.
		string TC_NO;
		string Odunc_tarihi;
		string Donus_tarihi;
		Dosya3 >> İSBN;
		Dosya3 >> TC_NO;
		Dosya3 >> Odunc_tarihi;
		Dosya3 >> Donus_tarihi;
	}
	Dosya3.close();

	ifstream Dosya4;    //kullanicilar isimli bir dosya oluşturdum.
	Dosya4.open("kullanicilar.txt");
	if (Dosya4.is_open() == true)
	{
		string Kullanici_adi;              //dosyada olması gereken bilgileri yazdırdım.
		string Sifre;
		Dosya4 >> Kullanici_adi >> Sifre;
	}

	ofstream Dosya4Yaz;    //kullanicilar dosyasına kullanici kaydettim.
	Dosya4Yaz.open("kullanicilar.txt");
	Dosya4Yaz << Kullanici_adi << "1234" << endl << Sifre << "1234" << endl;
	Dosya4Yaz << Kullanici_adi << "aaa" << endl << Sifre << "aaa" << endl;
	Dosya4Yaz.close();        //kaydetme islemi bittiği için dosyayı kapattım.


	ifstream Dosya4Oku("kullanici.txt");            //kullanicilar dosyasını okuttum.
	while (!Dosya4Oku.eof())
	{
		string kullanici_adi;
		string sifre;
		cout << "kullanici adi giriniz:";      //kullanici adi girilmesini istedim.
		cin >> kullanici_adi;
		cout << "sifre giriniz:";
		cin >> sifre;
		Dosya4Oku >> Kullanici_adi >> Sifre;
		if ((kullanici_adi=="1234"&&sifre=="1234") || (kullanici_adi=="aaa"&& sifre=="aaa") )      //şifre ya da kullanici adi hatali ise çalışmaz.
		{
			Dosya4Oku.close();
			do
			{
				cout << "YAPMAK ISTEDIGINIZ ISLEMI SECINIZ:" << endl;          //giris başarılı bir şekilde gercekleştiyse seçenekler kullanıcının karşısına çıkar.
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
			if (secim == 1)       //1.secenek secildigi zaman calısır.
			{
				cout << ".....Secilen islem 1-okuyucu kaydi.....";
				ofstream Dosya1Yaz;
				Dosya1Yaz.open("okuyucu.txt", ios::app);            //okuyucu dosyasını ekleme modunda açtım.
				do
				{
					cout << "\n TC NO:";
					cin >> Okuyucu_Tc_No;
					cout << "\n Ad:";
					cin >> ad;
					cout << "\n Soyadi:";
					cin >> soyadı;
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
					//dışarıdan girilen bilgileri okuyucu dosyasına yazdırdım.
					Dosya1Yaz << Okuyucu_Tc_No << " " << endl << ad << " " << endl << soyadı << " " << endl << uye_no << " " << endl << dogum_tarihi << " " << endl << gorevi << " " << endl << alabilecegi_kitap_sayisi << endl;
					cout << "\n Baska kayit yapacak misin? (e/h)";
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya1Yaz.close();             //yazılan bilgileri kaydedip dosyayı kapattım.
				cout << "\n okuyucu kaydi tamamlandi." << endl;               //kayıtın tamamlandıgını belirtim bitirdim.
			}

			if (secim == 2)                //2 numaralı secenek seçildiği zaman calışır.
			{
				cout << ".....Secilen islem 2-kayit guncelleme.....";
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku("okuyucu.txt");
				ofstream Dosya_okuyucu("okuyucu.tmp");
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //okuyucu tc no ile girilen tc no aynı ise çalışır.
					{
						ofstream Dosya_okuyucuYaz;
						Dosya_okuyucu.open("okuyucu.tmp", ios::out);      //gecici dosyaya duzeltilen bilgileri kaydettim.
						cout << "\n Okuyucu_Tc_No:";
						cin >> Okuyucu_Tc_No;
						cout << "\n Ad:";
						cin >> ad;
						cout << "\n Soyadi:";
						cin >> soyadı;
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
						Dosya_okuyucuYaz.close();     //gecici dosyaya yazma islemini tamamladım.
						cout << "\n Kitap duzeltme islemi tamamlanmıstır.";
					}
					else
						cout << "Yanlıs TC NO girdiniz.";    //yanlış tc no girildiği zaman çalışır.
				}
				Dosya1Oku.close();     //okuyucu dosyasını kapattım.
				Dosya_okuyucu.close();
				remove("okuyucu.txt");       //okuyucu dosyasını sildim
				rename("okuyucu.tmp", "okuyucu.txt");     //dosyaların ismini değiştirdim.
			}

			if (secim == 3)                 //3.secenek seçildiği zaman calışır.
			{
				cout << ".....Secilen islem 3- okuyucu silme....." << endl;
				ifstream Dosya1Oku;                         //okuyucu dosyasını açtım.
				Dosya1Oku.open("okuyucu.txt");
				ofstream Dosya_okuyucu;
				Dosya_okuyucu.open("okuyucu.tmp", ios::app);             //okuyucu isimli gecici bir dosya oluşturdum ve ekleme modunda açtırdım.
				cout << "\n TC NO:";
				cin >> Tc_No;
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)     //dışarıdan girilen tc no ile sistemdeki tc no aynı ise çalışır.
					{
						ofstream Dosya1Yaz;
						Dosya1Yaz.open("okuyucu.txt", ios::out);      //sistemde varolan bilgilerin yerine "" karakterini yazdırdım.
						Tc_No == "";
						ad == "";
						soyadı == "";
						uye_no == "";
						telefon == "";
						dogum_tarihi == "";
						gorevi == "";
						alabilecegi_kitap_sayisi == "";
						Dosya1Yaz.close();                      //yazma islemini tamamladıgım icin dosyayı kapattım.
						cout << "\n Kayit silme tamamlanmıstır.";                 //silme isleminin bittigini belirttim ve sonlandırdım.
					}
				}
				Dosya1Oku.close();           //okuyucu dosyaysını kapattım.
				Dosya_okuyucu.close();            //gecici olan okuyucu dosyasını kapattım. 
				remove("okuyucu.txt");            //okuyucu isimli dosyayı sildim.
				rename("okuyucu.tmp", "okuyucu.txt");                 //gecici dosyanın ismini değiştirdim.
			}

			if (secim == 4)               //4numaralı secim yapıldıgı zaman çalışır.
			{
				cout << ".....Secilen islem 4- okuyucu uzerindeki kitap listesi....." << endl;
				cout << "\n TC NO:";
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt");
				while (!Dosya1Oku.eof())           //bağlantı kurmak için okuyucu dosyasını okuttum.
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					if (Tc_No == Okuyucu_Tc_No)            //dışarıdan girilen tc no ile okuyucu tc no aynı ise çalışır.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						Dosya3Oku.open("odunc.txt");          //odunc dosyasını okuttum.
						while (!Dosya3Oku.eof())
						{
							Dosya3Oku >> Kitap_İsbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())             //dosya3 okuması tamamlandıgı zaman calışır.
							{
								Dosya3Oku.close();
								cout << "\n okuyucu uzerindeki kitaplar:" << endl;           //okuyucunun odunc aldığı kitapları listeledim.
								cout << Kitap_İsbn << "Isbn numarali kitap" << endl << Okuyucu_Tc_No << "Okuyucu tc no" << endl << odunc_tarihi << "Odunc tarihi" << endl << donus_tarihi << "Donus tarihi" << endl;
							}
						}
					}
					else
						cout << "\n Hatali TC NO girilmistir.";       //okuyucu tc no ile dışarıdan girilen tc no aynı değil ise çalışır.
				}
			}

			if (secim == 5)          //5 numaralı secim yapıldıgı zaman çalışır.
			{
				string İsbn;
				cout << ".....Secilen islem 5-okuyucu kitap odunc alma....." << endl;
				cout << "tc no:";
				cin >> Tc_No;
				ifstream Dosya1Oku;           //okuyucu isimli dosyayı açtım.
				Dosya1Oku.open("okuyucu.txt", ios::in);
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
					Dosya1Oku.close();                            //okuyucu dosyasındaki verileri okuttum.
					ofstream Dosya3;
					Dosya3.open("odunc.txt", ios::app);
					if (Tc_No == Okuyucu_Tc_No)               //okuycu tc'si ile dışarıdan girilen tc'nin aynı olduğu zaman çalışır.
					{
						cout << "\n Odunc almak istediginiz kitabın İSBN numarasını  giriniz:";
						cin >> İsbn;
						ifstream Dosya2Oku;
						Dosya2Oku.open("kitaplar.txt", ios::in);                //dışarıdan girilen isbn numarasına sahip kitap olup olmadığını kontrol etmek için kitaplar dosyasını okumaya açtım.
						while (!Dosya2Oku.eof())
						{
							Dosya2Oku >> Kitap_İsbn >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;
							if (İsbn == Kitap_İsbn)                    //dışarıdan girilen isbn ile kitap isbn uyumlu ise çalışır.
							{
								Dosya2Oku.close();
								ofstream Dosya3Yaz;
								Dosya3Yaz.open("odunc.txt", ios::app);               //odunc dosyasını yazmak için açtım.
								cout << "İsbn:";
								cin >> Kitap_İsbn;
								cout << "Tc No:";
								cin >> Okuyucu_Tc_No;
								cout << "odunc tarihi:";
								cin >> odunc_tarihi;
								cout << "donus tarihi:";
								cin >> donus_tarihi;
								Dosya3Yaz << Kitap_İsbn << "" << endl << Okuyucu_Tc_No << "" << endl << odunc_tarihi << "" << endl << donus_tarihi << endl;   //odunc bilgilerini odunc isimli dosyaya yazdırdım.
								Dosya3Yaz.close();
								cout << Kitap_İsbn << "İSBN numarali kitabi odunc aldiniz.";
							}
							else
								cout << "hatali İSBN girilmistir.";            //dışarıdan girilen isbn ile kitap isbn uyumlu değil ise çalışır.
						}
					}
					else
						cout << "hatalı TC NO girilmistir.";              //dışarıdan girilen tc ile okuyucu tc uyuşmuyorsa çalışır.
				}

			}

			if (secim == 6)       //6 numaralı secenek secildiği zaman çalışır.
			{
				string İsbn;
				string Tc_No;
				cout << ".....Secim 6-okuyucu kitap geri dondurme....." << endl;
				cout << "TC NO:";       //bağlantı kurmak için kullanicidan tc no girmesini istedim.
				cin >> Tc_No;
				ifstream Dosya1Oku;
				Dosya1Oku.open("okuyucu.txt", ios::in);     //okuyucu dosyasını açtırdım.
				while (!Dosya1Oku.eof())
				{
					Dosya1Oku >> Okuyucu_Tc_No >> ad >> soyadı >> uye_no >> telefon >> dogum_tarihi >> gorevi >> alabilecegi_kitap_sayisi;  //okuyucu dosyasındaki verileri dosyadan okudum.
					if (Tc_No == Okuyucu_Tc_No)          //dışarıdan girilen tc no ile okuyucu tc no aynı ise çalışır.
					{
						Dosya1Oku.close();
						ifstream Dosya3Oku;
						ofstream Dosya_odunc;
						Dosya3Oku.open("odunc.txt", ios::in);
						while (!Dosya3Oku.eof())       //odunc dosyasını okuttum.
						{
							Dosya3Oku >> Kitap_İsbn >> Okuyucu_Tc_No >> odunc_tarihi >> donus_tarihi;
							if (Dosya3Oku.eof())        //odunc dosyasının okuması tamamlandıysa çalışır.
							{
								Dosya3Oku.close();
								cout << "geri verilecek olan kitap isbn:";  //kullanıcıdan okuyucunun iade edeceği kitabın isbn numarasını girmesini istedim.
								cin >> İsbn;
								if (İsbn == Kitap_İsbn)           //okuyucunun odunc aldığı kitap isbn numarası ile dışarıdan girilen isbn numarası aynı ise çalışır.
								{
									ofstream Dosya3Yaz;
									Dosya3Yaz.open("odunc.txt", ios::out);      //odunc dosyasındaki bilgileri ""karakteri ile değiştirdim ve kitabın odunc dosyasından silinmesini sağladım.
									Kitap_İsbn == "";
									Okuyucu_Tc_No == "";
									odunc_tarihi == "";
									donus_tarihi == "";
									Dosya3Yaz.close();      //odunc dosyasına yazma islemini tamamladım.
									cout << "kitap iade islemi tamamlanmıstır.";       //kullaniciya iade işleminin başarıyla gercekleştiğini belirttim.
								}
							}
						}
						Dosya3Oku.close();      //dosya3'ün okuma modunu kapattım.
						Dosya_odunc.close();      //gecici dosyayı kapattım.
						remove("odunc.txt");     //odunc dosyasını sildim.
						rename("odunc.tmp", "odunc.txt");      //dosyaların ismini değiştirdim.
					}
				}
			}

			if (secim == 7)           //7numaralı secenek seçildiği zaman çalışır.
			{
				cout << ".....Secilen islem 7-kitap ekleme....." << endl;
				ofstream Dosya2Yaz;            //kitaplar dosyasını yazma modunda açtım.
				Dosya2Yaz.open("kitaplar.txt", ios::app);        // app modunda açtım.
				do
				{
					cout << "İSBN:";             //kitaplar dosyasında istenen bilgileri kullancıdan kaydedeceği kitaba uygun bir şekilde girmesini istedim.
					cin >> Kitap_İsbn;
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
					Dosya2Yaz << Kitap_İsbn << " " << Kitap_ismi << " " << Yazar_adi << " " << Yazar_soyadi << " " << Konu << " " << Tur << " " << Sayfa_sayisi; //girilen bilgileri dosyaya yazdırdım.
					cout << "baska kitap ekleyecek misiniz(e/h):";    //kitap eklemeye devam edip edilmeyeceğini sordum.
					cin >> cevap;
				} while (!(cevap == 'h'));
				Dosya2Yaz.close();       //dosyayı kapattım.
				cout << "kitap ekleme islemi tamamlanmıstır.";         //kitap ekleme isleminin bittiğini kullaniciya bildirdim.
			}

			if (secim == 8)                    //8.secenek secildiği zaman calışır.
			{
				string İsbn;
				cout << ".....Secilen islem 8-kitap silme.....";
				ifstream Dosya2Oku;                              //kitaplar dosyasının verilerinin okuma modunu açtım.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "İSBN:";               //silinmek istenen kitabın isbn numarasını istedim.
				cin >> İsbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_İsbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;   //kitaplar dosyasındaki verileri okuttum.
					if (İsbn == Kitap_İsbn)        //dışarıdan girilen isbn ile sistemde kayıtlı olan isbn aynıysa çalışır.
					{
						ofstream Dosya2Yaz;
						Dosya2Yaz.open("kitaplar.txt", ios::out);
						Kitap_İsbn == "";                    //kayıtlı olan verilerin yerine "" karakterini yazdırdım.
						Kitap_ismi == "";
						Yazar_adi == "";
						Yazar_soyadi == "";
						Konu == "";
						Tur == "";
						Sayfa_sayisi == "";
						Dosya2Yaz.close();
						cout << "\n Kitap silme islemi tamamlanmıstır.";        // silme isleminin bittiğini kullanıcıya belirttim.
					}
				}
				Dosya2Oku.close();
				Dosya_kitap.close();
				remove("kitaplar.txt");               //kitaplar dosyasını sildim.
				rename("kitaplar.tmp", "kitaplar.txt");               //dosyanın adını değiştirdim.
			}

			if (secim == 9)           //9 numaralı secenek seçildiği zaman çalışır.
			{
				string İsbn;
				cout << ".....secilen islem 9-kitap duzeltme....." << endl;
				ifstream Dosya2Oku;              //kitaplar dosyasını okudum.
				Dosya2Oku.open("kitaplar.txt");
				ofstream Dosya_kitap;
				cout << "kitap isbn:";         //kullanicidan duzeltilecek kitap isbn numarasını girmesini istedim.
				cin >> İsbn;
				while (!Dosya2Oku.eof())
				{
					Dosya2Oku >> Kitap_İsbn >> Kitap_ismi >> Yazar_adi >> Yazar_soyadi >> Konu >> Tur >> Sayfa_sayisi;  //kitaplardosyasındaki verileri okudum.
					if (İsbn == Kitap_İsbn)     //girilen isbn ile uyumlu kitap varsa çalışır.
					{
						ofstream Dosya_kitap;         //gecici dosyaya veri yazdırdım.
						Dosya_kitap.open("kitaplar.tmp", ios::out);
						cout << "kitap isbn:";
						cin >> Kitap_İsbn;
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
						cout << "\n Kitap duzeltme islemi tamamlanmıstır.";    //duzeltme isleminin bittiğini kullanıcıya belirttim.
					}
					else
						cout << "\n Hatali İSBN girildi.";   //girilen isbn ile uyumlu kitap olmadıgı zaman çalışır.
				}
				Dosya2Oku.close();      //dosyaları kapattım.
				Dosya_kitap.close();
				remove("kitaplar.txt"); //kitaplar dosyasını sildim.
				rename("kitaplar.tmp", "kitaplar.txt");     //dosyanın adını değiştirdim.
			}
		}
		else
		cout << "hatali giris.";
		exit(1);
	}
}
