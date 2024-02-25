// Eksik olduğunu düşündüğünüz include ifadelerini ekleyebilirsiniz.
#include<string>
#include "urun.cpp"
#include<vector>
using namespace std;
/**
 * @brief AlisVerisSepeti sınıfı bir çevrimiçi alışveriş uygulamasını simüle etmek
 * için oluşturulmuştur.
 *
 * AlisVerisSepeti sınıfı, yapıcı metot(constructor), urun_ekle ve toplam_tutar metotlarının
 * adlarını ve imzalarını değiştirmeden gövdelerini yazmanız istenmektedir. İhtiyacınıza
 * göre sınıfa üye elemanlar ve metotlar ekleyebilirsiniz.
 *
 * AlisVerisSepeti sınıfının urun_ekle metodunda kullanılan Urun sınıfı, urun.cpp dosyası
 * içinde verilmiştir. test.cpp dosyasında da Urun ve AlisVerisSepeti sınıflarının örnek
 * kullanımı gösterilmiştir. Bilmoodle sistemindeki testler daha karmaşık ve rastgele
 * oluşturulmaktadır.
 *
 * Bilmoodle sisteminde iki tür test bulunmaktadır:
 * - Rastgele oluşturulan bütün ürünler sepete eklenir ve en son tutar hesaplanır
 * - Rastgele oluşturulan ürünler birer birer sepete eklenir ve her eklemeden sonra
 *   tutar hesaplanır
 * Eğer beklenen tutar ile hesaplanan tutar arasında fark varsa test başarısız olur.
 *
 * Bu ödevde sizden bir main fonksiyonu yazmanız beklenmemektedir. Projenin test kodlarında
 * sizlerin görmediği bir main fonksiyonu bulunmaktadır. Ödevde sadece AlisVerisSepeti
 * sınıfını belirtilen biçimde çalıştıracak kodları yazmanız beklenmektedir.
 *
 */
class AlisVerisSepeti {
    public:// public değişken ve metotlarınızı bu bloğun altına ekleyebilirsiniz
    /**
     * @brief Bir AlisVerisSepeti nesnesi oluştur(Constructor)
     *
     */
    AlisVerisSepeti() {
        // Constructor gövdesini yazın
        price = 0;
    }

    /**
     * @brief Sepete ürün ekler
     *
     * @param urun Ürün nesnesi
     * @param adet Ürün adeti
     */
    void urun_ekle(Urun urun, int adet) {
        // urun_ekle metodunu yazın
        price += (urun.urun_fiyati * adet);
    }

    /**
     * @brief Alışveriş sepetindeki ürünlerin toplam tutarını hesaplayıp döndürür
     *
     * @return double Sepet tutarı
     */
    double toplam_tutar_hesapla() {
        // toplam_tutar_hesapla metodunu yazın
        return price;
    }
    private: // private değişkenlerinizi bu satırın altına ekleyebilirsiniz
        double price;
};
