#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

FILE *Dosya;
FILE *bireysel;
FILE *ticari;

struct musteri
{
char ad[50];
char soyad[50];
char Adres[100];
double TCKimlikNo[11];
int Telefon[11];
char ePosta[100];
int Sifre[4];
int HesapNo;
int Bakiye;

};

struct musteri Bilgi={"","","",0,0,0};
struct musteri Yedek={"","","",0,0,0};

void ParaYatirma();
void ParaCekme();
void Havale(int);
void BakiyeGoruntuleme(int);
void BakiyeGuncelle();
void BakiyeHavale();
void HavaleTutar(int);
void HavaleGuncel(int);
void HavaleGuncelle();
void BakiyeBak(int);
void HesapKapatma();
void hesapactirma();
void hesapozeti();



int main()
{
    printf("\t\t\t\tKuTuBuHANE BANKASINA HOSGELDINIZ\n\n\t\t\t");
    printf("LUTFEN GERCEKLESTIRMEK ISTEDIGINIZ ISLEMI SECINIZ.\t\t\n\n\t\t1)YENI MUSTERI\t\t\t2)HESAP GIRIS");
    switch(getch())
    {
        case '1':
        {
            system("CLS");
            printf("\n\n\t\t\t\tOLUSTURMAK ISTEDIGINIZ HESAP TURUNU SECINIZ.\n\n\t\t\t\t1)TICARI HESAP\t\t\t\t2)BIREYSEL HESAP");
            switch(getch())
            {
                case '1':
                {
                    Ticari();
                    Islemler();
                    break;
                }
                case '2':
                {
                    Bireysel();
                    Islemler();
                    break;
                }
                default:
                {
                    printf("HATALI GIRIS!");
                    break;
               }
            }
        }
        case '2':
        {
            Islemler();
            break;
        }
        default:
        {
            printf("HATALI GIRIS!");
            break;
        }
        return 0;
}

}
void AraMenu()
{
    printf("LUTFEN GERCEKLESTIRMEK ISTEDIGINIZ ISLEMI SECINIZ.\t\t\n\n1)ANA MENUYE DON\t\t\t\t2)RAPOR AL\t\t\t\n\n3)HESAP OZETI");
    switch (getch())
    {
        case '1':
        {
            system("cls");
            main();
            getch();
            break;
        }
        case '2':
        {
            system("cls");
            rapor();
            getch();
            break;
        }
        case '3':
        {
            system("cls");
            hesapozeti();
            getch();
            break;
        }
        default:
        {
            printf("HATALI GIRIS!\n");
            break;
        }
    }
}
void Islemler()
{
    printf("\n\t\tLUTFEN GERCEKLESTIRMEK ISTEDIGINIZ ISLEMI SECINIZ.\n\t1)HESAP ACTIRMA\t\t\t2)PARA CEKME\t\t\t\n\n\t3)PARA YATIRMA\t\t\t4)HAVALE ISLEMLERI\t\t\n\n\t5)HESAP KAPATMA ISLEMLERI\t\t\n\n");
    switch (getch())
    {
        case '1':
        {
            hesapactirma();
            printf("\n\n\t\t\t\tDEVAM ET\n\n");
            getch();
            system("cls");
            AraMenu();
            system("cls");
            break;
        }
        case '2':
        {
            ParaCekme();
            printf("\n\n\t\t\t\tDEVAM ET\n\n");
            getch();
            system("cls");
            AraMenu();
            system("cls");
            break;
        }
        case '3':
        {
            ParaYatirma();
            printf("\n\n\t\t\t\tDEVAM ET\n\n");
            getch();
            system("cls");
            AraMenu();
            system("cls");
            break;
        }
        case '4':
        {
            HesabaHavale();
            printf("\n\n\t\t\t\tDEVAM ET\n\n");
            getch();
            system("cls");
            AraMenu();
            system("cls");
            break;
        }
        case '5':
        {
            HesapKapatma();
            printf("\n\n\t\t\t\tDEVAM ET\n\n");
            getch();
            system("cls");
            AraMenu();
            system("cls");
            break;
        }
        default:
        {
            printf("\nHATALI GIRIS!\n");
        }
    }
    getch();
}

void Ticari()
{
    int HesapNo;
    HesapNo=rand();
    srand(time(0));
    struct musteri musteri,*pmusteri;
    pmusteri=&musteri;
    system("CLS");
    printf("ADINIZI GIRINIZ:");
    scanf("%s", &pmusteri->ad);
    printf("\nSOYADINIZI GIRINIZ:");
    scanf("%s",&pmusteri->soyad);
    printf("\nTC KIMLIK NUMARANIZI GIRINIZ :");
    scanf("%lf", &pmusteri->TCKimlikNo);
    printf("\nTELEFON NUMARANIZI GIRINIZ :");
    scanf("%d", &pmusteri->Telefon);
    printf("\nEPOSTA ADRESINIZI GIRINIZ :");
    scanf("%s", &pmusteri->ePosta);
    printf("\nADRESINIZI GIRINIZ :");
    scanf("%s", &pmusteri->Adres);
    printf("\nHESAP NUMARANIZ : %d ",HesapNo);

    FILE *fticari;
    fticari = fopen("ticari.txt","ab+");
    if(fticari==NULL)
    {
        printf("ticari.txt dosyasi acilamadi!\n");
        exit(1);
    }
    fwrite(&musteri, sizeof(musteri), 1, fticari);
    fclose(fticari);
    main();
    return 0;
}

void Bireysel()
{
    int HesapNo;
    HesapNo=rand();
    srand(time(0));
    struct musteri musteri,*pmusteri;
    pmusteri=&musteri;
    system("CLS");
    printf("ADINIZI GIRINIZ:");
    scanf("%s", &pmusteri->ad);
    printf("\nSOYADINIZI GIRINIZ:");
    scanf("%s",&pmusteri->soyad);
    printf("\nTC KIMLIK NUMARANIZI GIRINIZ :");
    scanf("%ld", &pmusteri->TCKimlikNo);
    printf("\nTELEFON NUMARANIZI GIRINIZ :");
    scanf("%ld", &pmusteri->Telefon);
    printf("\nEPOSTA ADRESINIZI GIRINIZ :");
    scanf("%s", &pmusteri->ePosta);
    printf("\nADRESINIZI GIRINIZ :");
    scanf("%s", &pmusteri->Adres);
    printf("\nHESAP NUMARANIZ : %d ",HesapNo);

    FILE *fbireysel;
    fbireysel = fopen("bireysel.txt","ab+");
    if(fbireysel== NULL)
    {
        printf("bireysel.txt dosyasi acilamadi ! \n");
        exit(1);
    }
    fwrite(&musteri, sizeof(musteri), 1, fbireysel);
    fclose(fbireysel);
    main();
    return 0;
}

void hesapactirma()
{
    int ekhesap;
    printf("\t\t\nEK HESAP ACTIRMA EKRANINA HOSGELDINIZ\n");
    ekhesap=rand();
    srand(time(0));
    printf("\n\n\t\tEK HESAP NUMARANIZ %d",ekhesap);
}

void ParaCekme()
{
    int Para;
    int GunlukPara;
    printf("\n\n\t\tBAKIYENIZ %d TL'DIR.",Bilgi.Bakiye);
    printf("\n\n\t\t\tCEKMEK ISTEDIGINIZ TUTAR: ");
    scanf("%d",&Para);
    while(Para<0)
    {
        printf("\n\n\t\t\tBAKIYENIZ YETERSIZDIR!\n\n\t\t\tEK HESABINIZI KULLANMAK ISTER MISINIZ?\n\n\t\t\t1)EVET\t\t\t\t\t2)HAYIR");
        switch(getchar())
        {
            case '1':
            {
                system("cls");
                printf("\n\n\t\t\tMUSTERI TIPINIZI SECINIZ:\n\n1)BIREYSEL\t\t\t\t\t2)TICARI");
                switch(getchar())
                {
                    case '1':
                    {
                        GunlukPara=750;
                        if(Para>=GunlukPara)
                        {
                            printf("\n\n\t\t\tGUNLUK MAKSIMUM PARA CEKME LIMITINIZ 750 TL'DIR!\n\n\t\t\tGUNLUK PARA CEKME LIMITINIZI ASTINIZ!\n\n\t\t\tLUTFEN TEKRAR DENEYINIZ!\n\n\t\t\tCEKMEK ISTEDIGINIZ TUTAR: ");
                            scanf("%d",&Para);
                        }
                        FILE *fbireysel;
                        fbireysel = fopen("bireysel.txt","ab+");
                        if(fbireysel== NULL)
                        {
                            printf("bireysel.txt dosyasi acilamadi ! \n");
                            exit(1);
                        }
                        fwrite(&bireysel, sizeof(bireysel), 1, fbireysel);
                        system("cls");
                        fclose(fbireysel);
                        break;
                    }
                    case '2':
                    {
                        GunlukPara=1500;
                        if(Para>=GunlukPara)
                        {
                            printf("\n\n\t\t\tGUNLUK MAKSIMUM PARA CEKME LIMITINIZ 1500 TL'DIR!\n\n\t\t\tGUNLUK PARA CEKME LIMITINIZI ASTINIZ!\n\n\t\t\tLUTFEN TEKRAR DENEYINIZ!\n\n\t\t\tCEKMEK ISTEDIGINIZ TUTAR: ");
                            scanf("%d",&Para);
                        }
                        FILE *fticari;
                        fticari = fopen("ticari.txt","ab+");
                        if(fticari== NULL)
                        {
                            printf("ticari.txt dosyasi acilamadi ! \n");
                            exit(1);
                        }
                        fwrite(&ticari, sizeof(ticari), 1, fticari);
                        system("cls");
                        fclose(fticari);
                        break;
                    }
                }
                FILE *Dosya=fopen(Bilgi.ad,"r");
                rewind(Dosya);
                fscanf(Dosya,"%d %s %s %d %s",&Bilgi.HesapNo,Bilgi.ad,Bilgi.soyad,&Bilgi.Bakiye,Bilgi.Adres);
                if(Para>Bilgi.Bakiye)
                {
                    printf("\n\n\t\t\tHESABINIZDA %d TL VAR!\n\n\t\t\tHESABINIZDAN %d TL CEKILECEK!",Bilgi.Bakiye,Bilgi.Bakiye);
                    return;
                }
                Bilgi.Bakiye=Bilgi.Bakiye-Para;
                if(Bilgi.Bakiye<0)
                {
                    printf("\n\n\t\t\tEK HESABINIZI KULLANDINIZ!");
                }
                else if(Bilgi.Bakiye==0)
                {
                    printf("\n\n\t\t\tHESABINIZDA PARA KALMAMISTIR!");
                }
                fclose(Dosya);
                remove(Bilgi.HesapNo);
                BakiyeGuncelle();
            }
            case '2':
            {
                system("cls");
                printf("\n\n\t\t\tISLEMINIZ GERCEKLESMEMEKTEDIR!");
                break;
            }
        }
    }
}
void ParaYatirma(int Numara)
{
    int Para;
    printf("\n\n\t\t\tYATIRMAK ISTEDIGINIZ TUTAR: ");
    scanf("%d",&Para);
    while(Para<0)
    {
        printf("\n\n\t\t\tNEGATIF BIR DEGER GIRDINIZ!\n\n\t\t\tLUTFEN TEKRAR DENEYINIZ!\n\n\t\t\tYATIRMAK ISTEDIGINIZ TUTAR:  ");
        scanf("%d",&Para);
    }
    FILE *Dosya=fopen(Bilgi.ad,"r");
    rewind(Dosya);
    fscanf(Dosya,"%d %s %s %d %s",&Bilgi.HesapNo,Bilgi.ad,Bilgi.soyad,&Bilgi.Bakiye,Bilgi.Adres);
    Bilgi.Bakiye=Bilgi.Bakiye+Para;
    fclose(Dosya);
    remove(Bilgi.HesapNo);
    BakiyeGuncelle();
}

void BakiyeGuncelle()
{
    FILE *Dosya=fopen(Bilgi.ad,"w");
    fprintf(Dosya,"%d %s %s  %d %s",Bilgi.HesapNo,Bilgi.ad,Bilgi.soyad,Bilgi.Bakiye,Bilgi.Adres);
    printf("\n\n\t\t\tGUNCELLENMIS BAKIYENIZ %d TL",Bilgi.Bakiye);
    fclose(Dosya);
}
void hesapozeti()
{
    int girenparalar;
    int cikanparalar;
    girenparalar=Bilgi.Bakiye;
    cikanparalar=Bilgi.Bakiye;

    printf("\n\n\t\t\tHESAP OZETI\n\n");
    printf("\n\n\t\t%d NUMARALI HESABA GELEN PARALAR %d TL'DIR.",Bilgi.HesapNo,girenparalar);
    printf("\n\n\t\t%d NUMARALI HESAPTAN CIKAN PARALAR %d TL'DIR.",Bilgi.HesapNo,cikanparalar);

    AraMenu();
}
void rapor()
{
    struct musteri musteri;
    FILE *ticari,*bireysel,*rapor;
    ticari=fopen("ticari.txt","r");
    bireysel=fopen("bireysel.txt","r");
    rapor=fopen("rapor.txt","w");
    while(!feof(ticari))
    {
        fscanf(ticari," %s %s",musteri.ad,musteri.soyad);
        while(!feof(bireysel))
        {
            fscanf(bireysel,"%s %s",musteri.ad,musteri.soyad);
            printf("AD\t\tSOYAD\t\tTC KIMLIK\t\tHESAP NO\t\tBAKIYE\t\tSIFRE\t\tADRES\t\t\n");
            printf("%s\t\t|%s\t\t|%d\t\t|%d\t\t|%d\t\t|%s\t\t|",musteri.ad,musteri.soyad,&musteri.TCKimlikNo,&musteri.HesapNo,&musteri.Bakiye,&musteri.Sifre,musteri.Adres);
        }
    }
    fclose(ticari);
    fclose(bireysel);
    fclose(rapor);
    AraMenu();
    getch();
}

void HesabaHavale()
{
    int hesap;
    int tutar;
    printf("\n\n\t\t\t\tHavale yapmak istediginiz hesap numarasini girin : ");
    scanf("%d",&hesap);
    strcpy(Yedek.ad,Bilgi.ad);
    FILE *ortak=fopen("bireysel.txt","r");
    rewind(ortak);
    FILE *dosya=fopen(Yedek.ad,"r+");
    rewind(dosya);
    fscanf(dosya,"%d %s %s %d %s",&Yedek.HesapNo,Yedek.ad,Yedek.soyad,&Yedek.Bakiye,Yedek.Adres);
    printf("\n\n\t\t\t\tHavale yapmak istediginiz tutari girin : ");
    scanf("%d",&tutar);
    if(tutar>Yedek.Bakiye)
    {
        printf("\n\n\t\t\t\tHavale yapmak istediginiz tutar %d TL fazla! Hesabinizda %d TL var!",tutar-Yedek.Bakiye,Yedek.Bakiye);
        return;
    }
   else
    {
        printf("\n\n\t\t\t\t1)EVET\n\n\t\t\t\t2)HAYIR");
        switch(getch())
        {
            case '1':
            {
                Yedek.Bakiye=Yedek.Bakiye-tutar;
                printf("\n\n\t\t\t\t%d numarali hesaba %d TL gonderilecek, onayliyor musunuz?\n\n\t\t\t\t1)EVET\n\n\t\t\t\t2)HAYIR",hesap,tutar);
                switch(getch())
                {
                    case '1':
                    {
                        printf("\n\n\t\t\t\t%d numarali hesaba %d TL havale yapilmistir\n\n\t\t\t\tGuncel tutariniz %d TL",hesap,tutar,Yedek.Bakiye);
                        remove(Yedek.ad);
                        bakiye_havale();
                        break;
                    }
                    case '2':
                    {
                        return;
                        break;
                    }
                    default:
                    {
                        printf("\n\n\t\t\t\tHatali giris!");
                        break;
                    }
                }
                fclose(dosya);
                havale_guncel(tutar);
                break;

            }
        }
    }

}
void havale_tutar()
{
    int hesap;
    int tutar;
    FILE *dosya=fopen(Yedek.ad,"r+");
    rewind(dosya);
    fscanf(dosya,"%d %s %s %d %d %s",&Yedek.HesapNo,Yedek.ad,Yedek.soyad,&Yedek.Sifre,&Yedek.Bakiye,Yedek.Adres);
    printf("\n\n\t\t\t\tHavale yapmak istediginiz tutari girin : ");
    scanf("%d",&tutar);
    if(tutar>Yedek.Bakiye)
    {
        printf("\n\n\t\t\t\tHavale yapmak istediginiz tutar %d TL fazla! Hesabinizda %d TL var!",tutar-Yedek.Bakiye,Yedek.Bakiye);
        return;
    }
    else
    {
        printf("\n\n\t\t\t\t1)EVET\n\n\t\t\t\t2)HAYIR\n\n\t\t\t\t3)SIL");
        switch(getch())
        {
            case '1':
            {
                Yedek.Bakiye=Yedek.Bakiye-tutar;
                printf("\n\n\t\t\t\t%d numarali hesaba %d TL gonderilecek, onayliyor musunuz?\n\n\t\t\t\t1)EVET\n\n\t\t\t\t2)HAYIR",hesap,tutar);
                switch(getch())
                {
                    case '1':
                    {
                        printf("\n\n\t\t\t\t%d numarali hesaba %d TL havale yapilmistir\n\n\t\t\t\tGuncel tutariniz %d TL",hesap,tutar,Yedek.Bakiye);
                        remove(Yedek.ad);
                        bakiye_havale();
                        break;
                    }
                    case '2':
                    {
                        return;
                        break;
                    }
                    default:
                    {
                        printf("\n\n\t\t\t\tHatali giris!");
                        break;
                    }
                }
                break;
            }
            case '2':
            {
                return;
                break;
            }
            case '3':
            {
                havale_tutar(hesap);
                break;
            }
            default:
            {
                printf("\n\n\t\t\t\tHatali giris!");
                break;
            }
        }
    }
    fclose(dosya);
    havale_guncel(tutar);
}

void bakiye_havale()
{
    FILE *dosya=fopen(Yedek.ad,"w");
    fprintf(dosya,"%d %s %s %d %d %s",Yedek.HesapNo,Yedek.ad,Yedek.soyad,Yedek.Sifre,Yedek.Bakiye,Yedek.Adres);
    fclose(dosya);
}

void havale_guncel()
{
    int para;
    FILE *dosya=fopen(Bilgi.ad,"r");
    rewind(dosya);
    fscanf(dosya,"%d %s %s %d %d %s",&Bilgi.HesapNo,Bilgi.ad,Bilgi.soyad,&Bilgi.Sifre,&Bilgi.Bakiye,Bilgi.Adres);
    Bilgi.Bakiye=Bilgi.Bakiye+para;
    fclose(dosya);
    havale_guncelle();
}

void havale_guncelle()
{
    FILE *dosya=fopen(Bilgi.ad,"w");
    fprintf(dosya,"%d %s %s %d %d %s",Bilgi.HesapNo,Bilgi.ad,Bilgi.soyad,Bilgi.Sifre,Bilgi.Bakiye,Bilgi.Adres);
    fclose(dosya);
}
void HesapKapatma()
{
    printf("KAPATMAK ISTEDIGINIZ HESAP TURUNU SECINIZ. \n\n 1)TICARI HESAP \t\t 2)BIREYSEL\n");
    switch (getch())
    {
        case '1':
        {
            system("CLS");
            struct musteri musteri,boskayit= {"",0,0};
            long int TC;
            int sayac=0;
            FILE *fticari;
            if((fticari=fopen("ticari.txt","rb+"))==NULL)
            {
                printf("Dosya acilamadi");
            }
            printf("\n\n\n");
            printf("Kayit Sil\n");
            printf("Silinecek musterinin TC numarasini Giriniz: \n");
            scanf("%ld",&TC);
            printf("\n");
            while(fread(&musteri,sizeof(musteri),1,fticari))
            {
                sayac++;
                if(musteri.TCKimlikNo==TC)
                {
                    printf("Konum:%d",sayac);
                    printf("\nAd   : %s",musteri.ad);
                    printf("\nTC kimlik numarasi   : %ld",musteri.TCKimlikNo);
                    printf("\n telefon numarasi : %ld",musteri.Telefon);
                    printf("\nE Posta   : %s",musteri.ePosta);
                    printf("\nAdres   : %s",musteri.Adres);
                    fseek(fticari,(sayac-1)*sizeof(ticari),SEEK_SET);
                    fwrite(&boskayit,sizeof(ticari),1,fticari);
                    printf("\nKayit Silindi..!\n");
                    break;
                }
            }
            if(musteri.TCKimlikNo!=TC)
            {
                printf("Kayit Bulunamadi..!\n");
                printf("Tekrar Arama Yapmak ister misiniz? (E/H)-(e/h)\n");
                char ch=getch();
                if(ch=='E' || ch=='e')
                {
                    HesapKapatma();
                }
                else
                {
                    printf("Arama yapilamadi \n");
                    main();
                }
            }
            fclose(fticari);
        }
        case '2':
        {
            system("CLS");
            struct musteri musteri,boskayit= {"",0,0};
            long int TC;
            int sayac=0;
            FILE *fbireysel;
            if((fbireysel=fopen("bireysel.txt","rb+"))==NULL)
            {
                printf("Dosya acilmadi");
            }
            printf("\n\n\n");
            printf("Kayit Sil\n");
            printf("Silinecek musterinin TC kimlik numarasini  giriniz: \n");
            scanf("%ld",&TC);
            printf("\n");
            while(fread(&musteri,sizeof(musteri),1,fbireysel))
            {
                sayac++;
                if(musteri.TCKimlikNo==TC)
                {
                    printf("Konum:%d",sayac);
                    printf("\nAd: %s",musteri.ad);
                    printf("\nTC kimlik numarasi   : %ld",musteri.TCKimlikNo);
                    printf("\ntelefon numarasi: %ld",musteri.Telefon);
                    printf("\nE Posta   : %s",musteri.ePosta);
                    printf("\nAdres   : %s",musteri.Adres);
                    fseek(fbireysel,(sayac-1)*sizeof(musteri),SEEK_SET);
                    fwrite(&boskayit,sizeof(bireysel),1,fbireysel);
                    printf("\nKayit Silindi..!\n");
                    break;
                }
            }
            if(musteri.TCKimlikNo!=TC)
            {
                printf("Kayit Bulunamadi..!\n");
                printf("Tekrar Arama Yapmak ister misiniz? (E/H)-(e/h)\n");
                char ch=getch();
                if(ch=='E' || ch=='e')
                {
                    HesapKapatma();
                }
                else
                {
                    printf("Arama yapilamadi..!\n\n");
                    main();
                }
            }
            fclose(fbireysel);
        }
    }
}
