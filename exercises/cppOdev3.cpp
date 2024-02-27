#include <iostream>
using namespace std;

/**
 * @brief Gri seviye resimleri temsil etmek için aşağıda verilen
 * Image sınıfını yazmanız istenmektedir.
 *
 * Image sınıfı satır ve sütunlardan oluşan pikselleri barındırmaktadır.
 * Her bir piksel [0-255] aralığında gri seviye değerler alabilmektedir.
 * Image sınıfındaki pikselleri temsil etmesi için iki boyutlu bir dizi
 * yapısını sınıfın içine yerleştirmeniz gerekmektedir.
 *
 * Image nesneleri başlangıçta boş olarak oluşturulur ve cin komutunu
 * ve >> operatörünü kullanarak kullanıcıdan alınır. Kullanıcıdan önce
 * satır sayısı, sütun sayısı ve daha sonrasında piksel değerleri alınır.
 * Örn: Image i1; cin >> i1;
 * Örnek girdi:
 * 2 2
 * 0 123
 * 255 64
 *
 * Image nesneleri + operatörü aşırı yüklenerek piksel değerleri
 * toplanabilir. İki resmin toplanabilmesi için satır ve sütun sayıları
 * eşit olmalıdır. İki resim toplandığında aynı konumdaki piksellerin
 * değerleri toplanır, eğer bu değer 255'ten fazla ise değer 255 olarak
 * belirlenir. Testlerde verilen toplanacak resimlerin boyutları aynıdır.
 * Toplama işlemi yeni bir Image nesnesi döndürmelidir.
 * img1:
 * 2 2
 * 0 123
 * 255 64
 * img2:
 * 2 2
 * 11 213
 * 255 128
 * img1+img2
 * 2 2
 * 11 255
 * 255 192
 *
 * Image nesneleri cout fonksiyonu ile ekrana yazdırılabilmelidir. Yazdırma
 * biçimi girdi biçimi ile aynıdır. Satır sayısı, sütun sayısı ve piksel
 * değerleri ekrana yazdırılır.
 * Örn: Image i1; cin >> i1; cout << i1;
 *
 * Programın main fonksiyonu ayrıca verilen main.cpp içerisindedir. Sadece
 * Image sınıfını yazmanız beklenmektedir. main fonksiyonunda kullanıcıdan
 * iki adet Image nesnesi alınır, bu nesneler toplanır ve toplam ekrana
 * yazdırılır.
 *
 * Bahsedilen işlevleri gerçekleştiren Image sınıfını yazınız. Sınıfın
 * ilgili metotlarını yazdığınızda ve operatör aşırı yüklemelerini
 * gerçekleştirdiğinizde kodunuz derlenecektir.
 *
 * main.cpp dosyasındaki kod aşağıda bilgi amaçlı olarak verilmiştir,
 * lütfen açıklamanın içinden çıkartmayın.
 *
 * #include "Ogrenci.cpp"
 * int main(int argc, char const *argv[])
 * {
 *     Image image1; // 1. resmi oluştur
 *     Image image2; // 2. resmi oluştur
 *     cin >> image1; // Kullanıcıdan 1. resmi al
 *     cin >> image2; // Kullanıcıdan 2. resmi al
 *     Image image3 = image1 + image2; // resimleri topla
 *     cout << image3; // 3. resmi yazdır
 *     return 0;
 * }

 */

// Image sınıfını belirtilen yönergelere göre yazınız.
class Image {
private:
    int satirSayisi = 0, sutunSayisi = 0,** pikseller = nullptr;
public:
    Image() {}
    ~Image(){}
    friend istream& operator>>(istream& girdi, Image& resim) {
        girdi >> resim.satirSayisi >> resim.sutunSayisi;
        resim.pikseller = new int*[resim.satirSayisi];

        for (int i = 0; i < resim.satirSayisi; i++) {
            resim.pikseller[i] = new int[resim.sutunSayisi];
            for (int j = 0; j < resim.sutunSayisi; j++) {
                girdi >> resim.pikseller[i][j];
            }
        }
        return girdi;
    }

    friend ostream& operator<<(ostream& cikti, Image& resim) {
        cikti << resim.satirSayisi << " " << resim.sutunSayisi << endl;
        for (int i = 0; i < resim.satirSayisi; i++) {
            for (int j = 0; j < resim.sutunSayisi; j++) {
                cikti << resim.pikseller[i][j] << " ";
            }
            cikti << endl;
        }
        return cikti;
    }
    Image operator+(Image& toplanacak){
        Image gecici;
        if(sutunSayisi != toplanacak.sutunSayisi || satirSayisi != toplanacak.satirSayisi) return Image();
        else{
            gecici.satirSayisi = satirSayisi;
            gecici.sutunSayisi = sutunSayisi;
            gecici.pikseller = new int*[satirSayisi];

            for (int i = 0; i < gecici.satirSayisi; i++) {
                gecici.pikseller[i] = new int[sutunSayisi];
                for (int j = 0; j < gecici.sutunSayisi; j++) {
                    gecici.pikseller[i][j] = pikseller[i][j] + toplanacak.pikseller[i][j];
                    if(gecici.pikseller[i][j] > 255) gecici.pikseller[i][j] = 255;
                }
            }
        }
        return gecici;
    }
};


int main(int argc, char const *argv[])
{
    Image image1; // 1. resmi oluştur
    Image image2; // 2. resmi oluştur
    cin >> image1; // Kullanıcıdan 1. resmi al
    cin >> image2; // Kullanıcıdan 2. resmi al
    Image image3 = image1 + image2; // resimleri topla
    cout << image3; // 3. resmi yazdır */
    return 0;
}
