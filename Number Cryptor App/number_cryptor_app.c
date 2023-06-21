#include <stdio.h>

int main() {
    int sayi, birler, onlar, yuzler, binler, onbinler, gecici, gecici2;
    int sifrelenmis_birler, sifrelenmis_onlar, sifrelenmis_yuzler, sifrelenmis_binler, sifrelenmis_onbinler, sifreli_sayi;
    char secim;

    // Burada kullanıcıdan sayı alınıyor.
    do {
        printf("Lutfen bes basamakli bir sayi giriniz: ");
        scanf("%d", &sayi);
    } while (sayi < 10000 || sayi > 99999);

    // Alınan sayının şifrelenmesi için veya programdan çıkış yapılması için soru soruluyor.
    do {
        printf("Sifrelemek icin 'P', cikmak icin 'E' tuslayiniz: ");
        scanf(" %c", &secim);

        // Sayılar basamaklara atanıyor.
        birler = sayi % 10;
        onlar = (sayi / 10) % 10;
        yuzler = (sayi / 100) % 10;
        binler = (sayi / 1000) % 10;
        onbinler = (sayi / 10000) % 10;

        // Sayılar şifreleniyor.
        sifrelenmis_birler = (birler + 9) % 10;
        sifrelenmis_onlar = (onlar + 9) % 10;
        sifrelenmis_yuzler = (yuzler + 9) % 10;
        sifrelenmis_binler = (binler + 9) % 10;
        sifrelenmis_onbinler = (onbinler + 9) % 10;

        gecici = sifrelenmis_onbinler;
        sifrelenmis_onbinler = sifrelenmis_yuzler;
        sifrelenmis_yuzler = gecici;

        gecici2 = sifrelenmis_binler;
        sifrelenmis_binler = sifrelenmis_onlar;
        sifrelenmis_onlar = gecici2;

        // Sayıların yerleri değişiyor.
        sifreli_sayi = sifrelenmis_onbinler * 10000 + sifrelenmis_binler * 1000 + sifrelenmis_yuzler * 100 + sifrelenmis_onlar * 10 + sifrelenmis_birler;

        if (secim == 'P') {
            printf("Sifrelenmis sayiniz: %d\n", sifreli_sayi);
            sayi = sifreli_sayi;
        }
    } while (secim != 'E');

    // Programdan çıkış yapılıyor.
    printf("Programdan cikiliyor...\n");
    return 0;
}

