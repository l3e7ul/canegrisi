/*Çan eğrisi için genel kullanılan hesaplama yöntemi ise şu şekildedir:

Ham başarı notu(zskoru)- Sınıfın ham başarı notu ortalaması / Standart sapma
Standart sapma genel olarak akademisyen tarafından belirlenen bir özellik olduğu için
net bir şekilde hesaplama yapmak maalesef pek mümkün değil.
Standart sapmayı 5 aldığımızı varsayalım ve sınıfın ortalamasını da 50 olarak alalım.
Bu şekilde sonuç aşağıdaki gibi olacaktır.

50 - 54,99 puan aralığı CC
55 - 55,99 puan aralığı CB
60 - 64,99 puan aralığı BB
65 - 69,99 puan aralığı BA
70 ve 70 puan üstü ise AA olarak değerlendirilecektir. */

#include <stdio.h>


double zSkoruHesapla(double notu, double ortalama, double std_sapma) {
    return (notu - ortalama) / std_sapma;
}


void harfNotuHesapla(double notu) {
    if (notu >= 70) {
        printf("AA\n");
    } else if (notu >= 65) {
        printf("BA\n");
    } else if (notu >= 60) {
        printf("BB\n");
    } else if (notu >= 55) {
        printf("CB\n");
    } else if (notu >= 50) {
        printf("CC\n");
    } else {
        printf("Geçmedi\n");
    }
}

int main() {
    double notlar[15];
    double ortalama = 0.0;
    double std_sapma = 5;
    double toplam = 0.0;

    printf("15 öğrencinin notlarını giriniz:\n");
    for (int i = 0; i < 15; i++) {
        printf("Öğrenci %d'nin notunu girin: ", i + 1);
        scanf("%lf", &notlar[i]);
        toplam += notlar[i];
    }

    ortalama = toplam / 15.0;

    printf("\nSınıf Ortalaması: %.2f\n", ortalama);
    printf("Standart Sapma: %.2f\n", std_sapma);
    printf("\n");


    for (int i = 0; i < 15; i++) {
        double zSkoru = zSkoruHesapla(notlar[i], ortalama, std_sapma);
        printf("Öğrenci %d - Not: %.2f - Z-Skoru: %.2f - Harf Notu: ", i + 1, notlar[i], zSkoru);
        harfNotuHesapla(notlar[i]);
    }

    return 0;
}
