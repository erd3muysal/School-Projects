#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*************************************************************************
Bu projede kullanılan log dosyasını
http://ita.ee.lbl.gov/html/contrib/NASA-HTTP.html linkinden indirebilirsiniz.

char *strtok(char *str, const char *delim) fonksiyonu delimiter yardımıyla
string (str) 'i  parçalara ayırır.
Vector uzunluğu olmayan bir dizi gibi çalışır.
Vector'e yeni eleman eklemek için push_back metodu kullanılır.
Vector'ün içerisinde o anda kaç eleman bulunduğu size metodu ile öğrenilebilir.
Vector'ün her bir elemanına bir dizinin her bir elemanına erişiyor gibi []
parantezleri kullanılarak erişilebilir.
***************************************************************************/
vector<string> ayir(string satir) {
  /*okunan string char'a cast ediliyor.Yani string
  char dizisine dönüştürülüyor.*/
  char* cstr = const_cast<char*>(satir.c_str());
  char* ayrilmisSatirElemani;
  vector<string> ayrilmisSatirDizisi;
  /*strtok ile char dizisi parçalanıyor*/
  ayrilmisSatirElemani = strtok(cstr, " ");
  while (ayrilmisSatirElemani != NULL) {
    ayrilmisSatirDizisi.push_back(ayrilmisSatirElemani);
    ayrilmisSatirElemani = strtok(NULL, " ");

  }
  return ayrilmisSatirDizisi;
}
int main() {

  ifstream okunacakDosya("/home/kars/Downloads/deneme.txt");
  ofstream sonucDosyasi("/home/kars/Desktop/output.txt");
  string satir;
  vector<string> ayrilmisSatirDizisi;

  while (getline(okunacakDosya, satir)) {
    /*ayir() fonksiyonu burada çağrılıyor.*/
    ayrilmisSatirDizisi = ayir(satir);
    sonucDosyasi << ayrilmisSatirDizisi[0] + " " +
        ayrilmisSatirDizisi[6].substr(0, ayrilmisSatirDizisi[6].size() - 1) << endl;
  }

  okunacakDosya.close();

  sonucDosyasi.close();
  cout<<"Dosya okundu ve basarili bir sekilde parcalandi"<<endl;
  return 0;
}
