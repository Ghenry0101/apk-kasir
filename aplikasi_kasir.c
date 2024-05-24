#include<stdio.h>
#include<conio.h>

int main() {
    int banyakJenis, banyakPotong, i;
    char jenisPotong;
    int totalHarga = 0, jumlahBayar, pajak, totalBayar;

    printf("GEROBAK FRIED CHICKEN\n");
    printf("---------------------\n");
    printf("Kode Jenis Harga\n");
    printf("--------------------------\n");
    printf("D Dada Rp. 2500\n");
    printf("P Paha Rp. 2000\n");
    printf("S Sayap Rp. 1500\n");
    printf("--------------------------\n");

    printf("Banyak Jenis : ");
    scanf("%d", &banyakJenis);

    int orders[banyakJenis][3]; // Array buat nyimpen kode jenis (buat integer), banyak potong, dan harga total per jenis2

    for (i = 0; i < banyakJenis; i++) {
        printf("Jenis ke - %d\n", i + 1);
        printf("Jenis Potong [D/P/S] : ");
        scanf(" %c", &jenisPotong);
        printf("Banyak Potong : ");
        scanf("%d", &banyakPotong);

        int harga;
        switch (jenisPotong) {
            case 'D':
            case 'd':
                harga = 2500;
                orders[i][0] = 'D';
                break;
            case 'P':
            case 'p':
                harga = 2000;
                orders[i][0] = 'P';
                break;
            case 'S':
            case 's':
                harga = 1500;
                orders[i][0] = 'S';
                break;
            default:
                printf("Kode jenis tidak valid\n");
                continue;
        }

        orders[i][1] = banyakPotong;
        orders[i][2] = harga * banyakPotong;
        totalHarga += orders[i][2];
    }

    printf("------------------------------------------------------------------------------------\n");
    printf("No. Jenis Harga Banyak Jumlah\n");
    printf("Potong Satuan Beli Harga\n");
    for (i = 0; i < banyakJenis; i++) {
        printf("%d %c Rp %d %d Rp %d\n", i + 1, orders[i][0], orders[i][2] / orders[i][1], orders[i][1], orders[i][2]);
    }

    jumlahBayar = totalHarga;
    pajak = jumlahBayar * 10 / 100;
    totalBayar = jumlahBayar + pajak;

    printf("------------------------------------------------------------------------------------\n");
    printf("Jumlah Bayar Rp %d\n", jumlahBayar);
    printf("Pajak 10%% Rp %d\n", pajak);
    printf("Total Bayar Rp %d\n", totalBayar);

    getch();
    return 0;
}