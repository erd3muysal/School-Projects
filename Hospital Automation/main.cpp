#include <iostream>
#include <fstream> // file input output
#include <iomanip> // setw fonk
#include <stdlib.h> // srand fonk
#include <time.h> // srand(time(0)) fonk
using namespace std;
// girilen bilgilere sahip hastayi direk kaydeder
void hastaEkle();
// girilen hasta numarasina sahip hastayi taburcu ederken kaydedilsin mi diye sorar
void hastaTaburcu();
// hastaliste adli textten okuyup cout ile ekrana yazar
void ekranaYazdir(short, char[] , char[] , short, char[] );
// hasta listesini ekrana yazdirir ayrica hasta taburcunun icinde de calisir, hasta no girmeye yardimci olur
void listeYazdir();
// temp dosyasini ana dosyaya yazdirir
void listeGuncelle();
// temp dosyasina cikti alir
void taburcuOlanHasta(short , char[] , char[] , short , char[] );

int main() {

	int islem=0;
	char secim;
	do {
		do {
			cout << "Islem seciniz.\n1-Hasta ekleme   2-Hasta taburcu   3-Hasta listeleme";
			cout << endl << "Seciminiz: ";
			cin >> islem;
		} while(islem!=1&&islem!=2&&islem!=3); // kullaniciyi kisitlar

		cout << endl;

		switch(islem) {
			case 1:
				hastaEkle();
				break;
			case 2:
				hastaTaburcu();
				break;
			case 3:
				listeYazdir();
				break;
		}

		cin.clear(); // cin ile yasanan sorunlari cozer

		cout << endl << "Baska islem yapacak misiniz? (y/any) Seciminiz: ";
		cin >> secim;
		cout << endl;

	} while(secim=='y'||secim=='Y'); // y veya Y girilmediginde program kapanir

	return 0;
}

void hastaEkle(void) {

	ofstream hastaCikti("hastaListe.txt", ios::app); // ios::app sona eklemek icin; ios::out sifirdan yazmak icin

	cout << "Hasta girisi yapiniz. Cikis yapmak icin Ctrl+Z kombinasyonunu kullaniniz." << endl;
	cout << "Gerekenler: adSoyad, kan, yas, telNo." << endl;
	cout << "Ornek giris: AliAtaBAK AB+ 40 0000000000";

	srand(time(0));

	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo=rand()%1000;

	cout << endl << hastaNo << " ";
   cin >> adSoyad >> kan >> yas >> telNo;
   hastaCikti << endl << hastaNo << " " << adSoyad << " " << kan << " " << yas << " " << telNo;
	hastaCikti.close();
}

void hastaTaburcu(void) {

	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo, sorgu;
	bool kontrol=0;

	listeYazdir();
	ifstream hastaGirdi("hastaListe.txt", ios::in);
	ofstream taburcuCikti("temp.txt", ios::trunc); // tempi bosaltir

	cout << "\nTaburcu edilecek hastaNo'yu giriniz: ";
	cin >> sorgu;
	cout << endl;

	while(hastaGirdi >> hastaNo >> adSoyad >> kan >> yas >> telNo) {

		if(hastaNo==sorgu) {
			cout << adSoyad << " isimli hasta bulundu." << endl;
			kontrol=1;
		} else {
			taburcuOlanHasta(hastaNo, adSoyad, kan, yas, telNo);
		}
	}

	if(!kontrol)
		cout << "\a" << "Taburcu edilmek istenen hasta bulunamadi." << endl;
	else
		listeGuncelle();

	hastaGirdi.close();

}

void ekranaYazdir(short h, char a[] , char k[] , short y, char t[]) {
	cout << setw(3) << h << setw(15) << a << setw(6) << k << setw(6) << y << setw(15) << t << endl;
}

void listeYazdir(void) {

	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo, sorgu;

	ifstream hastaGirdi("hastaListe.txt", ios::in);

	while(!hastaGirdi.eof()) {
		hastaGirdi >> hastaNo >> adSoyad >> kan >> yas >> telNo;
		ekranaYazdir(hastaNo, adSoyad, kan, yas, telNo);
	}

	hastaGirdi.close();

}

void listeGuncelle(void) {

	char kaydet;
	cout << "Hasta taburcu edilsin mi? (y/any) Seciminiz: ";
	cin >> kaydet;

	if(kaydet=='y'||kaydet=='Y') {

		ifstream stream1("temp.txt"); //kaynak dosya
		ofstream stream2("hastaListe.txt"); //hedef dosya

		stream2 << stream1.rdbuf(); // kaynagi hedefe kopyaladi
	}
}

void taburcuOlanHasta(short h, char a[] , char k[] , short y, char t[]) {

	ofstream taburcuCikti("temp.txt", ios::app);
	taburcuCikti << endl << h << " " << a << " " << k << " " << y << " " << t;
	taburcuCikti.close();

}
