#include <stdio.h>

//1
#define MAKS 20

struct date {
    int month, day, year;
};

struct student {
    char name[30];
    struct date birthday;
};

//2
struct date {
    int day, month, year;
};

//3
#include <string.h>

struct datamenu {
    char kode;
    int jumlah;
};

int main() {

    //1
    struct student data_mhs[MAKS];
    int i = 0, jml;
    char lagi;

    do {
        printf("Name: ");
        scanf("%s", data_mhs[i].name);

        printf("Birthday (mm-dd-yyyy): ");
        scanf("%d-%d-%d", &data_mhs[i].birthday.month, &data_mhs[i].birthday.day, &data_mhs[i].birthday.year);

        while ((data_mhs[i].birthday.month < 1 || data_mhs[i].birthday.month > 12) ||
               (data_mhs[i].birthday.day < 1 || data_mhs[i].birthday.day > 31) ||
               (data_mhs[i].birthday.year < 1)) {
            printf("Invalid birthday. Please enter a valid date (mm-dd-yyyy): ");
            scanf("%d-%d-%d", &data_mhs[i].birthday.month, &data_mhs[i].birthday.day, &data_mhs[i].birthday.year);
        }

        i++;
        fflush(stdin);

        printf("\nMau masukkan data lagi? [Y/T]: ");
        scanf(" %c", &lagi);
        fflush(stdin);
    } while (lagi == 'Y' || lagi == 'y');

    jml = i;
    printf("\nDATA MAHASISWA\n");
    for (i = 0; i < jml; i++) {
        printf("%d. Name     : %s", i + 1, data_mhs[i].name);
        printf("\n   Birthday : %d-%d-%d\n\n", data_mhs[i].birthday.month, data_mhs[i].birthday.day, data_mhs[i].birthday.year);
    }


    //2
    struct date today, tomorrow;
    char lagi;
    int cariJumHari(int month, int year);
    do {
        printf("\nMasukkan tanggal hari ini (dd-mm-yyyy)\t: ");
        scanf("%d-%d-%d", &today.day, &today.month, &today.year);

        if (today.day + 1 > cariJumHari(today.month, today.year)) {
            if (today.month == 12) {
                tomorrow.day = 1;
                tomorrow.month = 1;
                tomorrow.year = today.year + 1;
            } else {
                tomorrow.day = 1;
                tomorrow.month = today.month + 1;
                tomorrow.year = today.year;
            }
        } else {
            tomorrow.day = today.day + 1;
            tomorrow.month = today.month;
            tomorrow.year = today.year;
        }

        printf("Maka tanggal besok adalah: %2d-%2d-%2d", tomorrow.day, tomorrow.month, tomorrow.year);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\n\nMau memasukkan tanggal lagi [Y/T] ? ");
        lagi = getchar();
    } while (lagi == 'Y' || lagi == 'y');


    //3
    struct datamenu keranjang[30];
    int i = 0, j, harga, total = 0;
    char jwb, jenis[6];

    printf("\t\t=== GEROBAK FRIED CHICKEN ====\n");
    printf("\nDAFTAR HARGA\n");
    printf("\nKode Jenis Harga Per Potong");
    printf("\n D Dada Rp. 5000.00");
    printf("\n P Paha Rp. 4000.00");
    printf("\n S Sayap Rp. 3000.00");
    printf("\n\nHarga belum termasuk pajak: 10 %%");

    do {
        printf("\n\nMasukkan Pesanan Anda");
        printf("\nPesanan ke-%d", i + 1);
        fflush(stdin);
        printf("\nJenis [D/P/S]\t: ");
        scanf(" %c", &keranjang[i].kode);
        fflush(stdin);
        printf("Jumlah \t\t: ");
        scanf("%d", &keranjang[i].jumlah);
        i++;
        fflush(stdin);
        printf("\nMau pesan lagi [Y/T] ");
        scanf(" %c", &jwb);
    } while (jwb == 'Y' || jwb == 'y');

    printf("\n\nNota Belanja Anda : \n");
    printf("\nGEROBAK FRIED CHICKEN\n");
    printf("\n===========================================================================");
    printf("\nNo\tJenis Potong\tHarga Satuan\tQty\tJumlah\tHarga");
    printf("\n===========================================================================");

    for (j = 0; j < i; j++) {
        switch (keranjang[j].kode) {
            case 'D': case 'd':
                strcpy(jenis, "DADA");
                harga = 5000;
                break;
            case 'P': case 'p':
                strcpy(jenis, "PAHA");
                harga = 4000;
                break;
            case 'S': case 's':
                strcpy(jenis, "SAYAP");
                harga = 3000;
                break;
        }
        printf("\n%d\t%s\t\tRp. %.2d\t%d\tRp. %6.2d", j + 1,
               jenis, harga,
               keranjang[j].jumlah, harga * keranjang[j].jumlah);
        total = total + harga * keranjang[j].jumlah;
    }

    printf("\n===========================================================================");
    printf("\nJumlah bayar\tRp. %6.2d", total);
    printf("\nPajak 10%%\tRp. %6.2d", total / 10);
    printf("\nTotal bayar\tRp. %6.2d", total - total / 10);
    printf("\n\nTERIMA KASIH ATAS KUNJUNGAN ANDA\n\n");

    return 0;
}

//2
int cariJumHari(int bulan, int tahun) {
    int daftarHari[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jumHari = daftarHari[bulan - 1];

    if (bulan == 2 && tahun % 4 == 0) {
        if (tahun % 100 != 0 || tahun % 400 == 0)
            jumHari = 29;
    }

    return jumHari;
}
