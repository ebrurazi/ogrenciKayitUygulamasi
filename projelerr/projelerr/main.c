#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

struct Ogrenci {
    int numara;
    char ad[20];
    int vize;
    int final;
};

//Menüdeki seçenekler için Fonksiyonlar oluşturuldu. İçlerin struct yapıları ve kayıt edilecek öğrenci parametre olarak gönderildi
void kayıtListele(struct Ogrenci *,int);
void kayitGuncelleme(struct Ogrenci *,int);
void ortalamaHesapla(struct Ogrenci *,int);
void enBaşarılıÖğrenciBul(struct Ogrenci *,int);
int menu(void);
void yeniKayit(struct Ogrenci *,int);

int main(void){
    int n;
    int secim;
    
    printf("Kaç öğrenci kayıt etmek istersiniz : ");
    scanf("%d",&n);
    //Menu fonksiyonundan secilen rakama göre (1-5 arasında) if yapısına girer ve fonksiyonu çalıştırır
    secim=menu();
    //*ogrPtr yerler * ptr kopyalanır
    struct Ogrenci *ogrPtr= (struct Ogrenci * ) malloc(n *sizeof(struct Ogrenci));
    struct Ogrenci *ptr=ogrPtr;
    
    while (secim != 0) {
        if(secim==1){
            yeniKayit(ptr,n);
        }
        else if (secim == 2){
            kayıtListele(ptr,n);
        }
        else if (secim == 3){
            kayitGuncelleme(ptr,n);
        }
        else if (secim == 4){
            ortalamaHesapla(ptr,n);
        }
        else if (secim == 5){
            enBaşarılıÖğrenciBul(ptr,n);
        }
        else{
            printf("Hatalı giriş yaptınız\n");
        }
        secim=menu();
    }
    printf("\n\n");
    return 0;
}
int menu(void){
    int secim;
    
    printf("\n1-Yeni Kayıt Ekleme\n");
    printf("2-Kayıt Listeleme\n");
    printf("3-Kayıt Güncelleme\n");
    printf("4-Sınıf Ortalaması Hesapla\n");
    printf("5-Ortalmaya Göre En başarılı Öğrenci Bilgisini Göster\n");
    printf("0-Çıkış\n");
    
    printf("Seçiniz : ");
    scanf("%d",&secim);
    
    return secim;
}
void yeniKayit(struct Ogrenci * ptr, int n){
    int numara;
    char ad[20];
    int vize;
    int final;
    int i=0;
    //Kayıt edilecek yeni öğrenciler için bilgiler alınır
    printf("Yeni kayıt edilecek öğrenci Bilgilerini giriniz : \n");
    
    while (i<n) {
        printf("%d. öğrenci bilgilerini giriniz : \n",i+1);
        printf("Numara : ");
        scanf("%d",&numara);
        printf("Ad     : ");
        scanf("%s",ad);
        printf("Vize   : ");
        scanf("%d",&vize);
        printf("Final  : ");
        scanf(" %d",&final);
        
        ptr->numara=numara;
        strcpy(ptr->ad,ad);
        ptr->vize=vize;
        ptr->final=final;
        
        i++;
        ptr++;
        
    }
    printf("Kayıt işlemi tamamlandı\n");
    
}
void kayıtListele(struct Ogrenci *ptr ,int n){
    int i=0;
    //Kayıt edilen öğrencilerin bilgilerini listeler
    while (i<n) {
        printf("%d. numaralı öğrenci bilgileri: \n",ptr->numara);
        printf("Ad     : %s\n",ptr->ad);
        printf("Vize   : %d\n",ptr->vize);
        printf("Final  : %d\n",ptr->final);
        printf("***********************\n");
        
        
        i++;
        ptr++;
        
    }
    printf("Listeleme işlemi tamamalandı \n");
}
void kayitGuncelleme(struct Ogrenci *ptr,int n){
    int numara;
    char ad[20];
    int vize;
    int final;
    int i=0;
    int sonuc=0;
    //Herhangi bir değişikli yapmak istediğinizde numarasını girmenz yeterli olacaktır
    printf("Kaydı guncellenecek ogrenci numarası : ");
    scanf("%d",&numara);

    while (i<n) {
        if(numara == ptr->numara){
            printf("%d. numaralı öğrenci bilgilerini giriniz : \n",numara);
            printf("Numara : ");
            scanf("%d",&numara);
            printf("Ad     : ");
            scanf("%s",ad);
            printf("Vize   : ");
            scanf("%d",&vize);
            printf("Final  : ");
            scanf(" %d",&final);
            //Girilen yeni değerleri bellekte ayırdığımız yere kopyalar
            ptr->numara=numara;
            strcpy(ptr->ad,ad);
            ptr->vize=vize;
            ptr->final=final;
            sonuc=1;
            break;
        }
        if(sonuc ==0){
            printf("%d numaralı öğrenci listede yok\n",numara);
        }
        
        i++;
        ptr++;
        
    }
    
}
void ortalamaHesapla(struct Ogrenci *ptr,int n){
    int i=0;
    int ort;
    int sonOrt;
    int toplam=0;
    //Notların genel ortalmasını hesaplar
    while (i<n) {
        ort=ptr->vize*0.4 +ptr->final*0.6;
        toplam+=ort;
        i++;
        ptr++;
    }
    sonOrt=toplam/n;
    printf("Sınıf ortalaması : %d\n",sonOrt);
}
void enBaşarılıÖğrenciBul(struct Ogrenci *ptr,int n){
    int i=0;
    int buyuk=0;
    int ort = 0;

    int numara=0;
    char ad[20];
    int vize;
    int final;
    //En yüksek ortalamaya sahip öğrenciyi bulur
    while (i<n) {
        ort=ptr->vize*0.4 +ptr->final*0.6;
        if (buyuk<ort) {
            buyuk=ort;
            numara=ptr->numara;
            strcpy(ad,ptr->ad);
            ort=buyuk;
        }
        
        i++;
        ptr++;
    }
    printf("En başarılı öğrenci bilgileri : \n");
    printf("Numara   : %d\n",numara);
    printf("Ad       : %s\n",ad);
    printf("Ortalama : %d\n",buyuk);
    printf("***********************\n");
    
}
