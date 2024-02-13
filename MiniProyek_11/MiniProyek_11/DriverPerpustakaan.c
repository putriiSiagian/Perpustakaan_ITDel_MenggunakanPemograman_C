#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeaderPerpustakaan.h"

int main()
{
    dbuku *B1 = (dbuku *)malloc(sizeof(dbuku) * 1);
    dbuku *B2 = (dbuku *)malloc(sizeof(dbuku) * 1);
    ddosen *D1 = (ddosen *)malloc(sizeof(ddosen) * 1);
    ddosen *D2 = (ddosen *)malloc(sizeof(ddosen) * 1);
    int opsi, pilih_dosen, batas, i;
    char NIDN[20];

    strcpy(B1->ISBN, "G312544");
    strcpy(B1->judul_buku, "Web Development");
    strcpy(B1->jenis_buku, "Ilmu Pengetahuan");
    strcpy(B1->author, "Rangga Setiawan");
    strcpy(B1->NIDN, "A34584");
    B1->jumlah = 5;
    B1->alamat = B2;

    strcpy(B2->ISBN, "G245226");
    strcpy(B2->judul_buku, "Sibuta Dari Goa Hantu");
    strcpy(B2->jenis_buku, "Dongeng");
    strcpy(B2->author, "Hilmawan");
    strcpy(B1->NIDN, "A36442");
    B2->jumlah = 7;
    B2->alamat = NULL;

    strcpy(D1->NIDN, "G232758");
    strcpy(D1->nama, "Bagasditiro Simatupang");
    strcpy(D1->no_telp, "083357004344");
    D1->alamat = D2;

    strcpy(D2->NIDN, "G264327");
    strcpy(D2->nama, "Rihanna Pandiangan");
    strcpy(D2->no_telp, "082154688747");
    D2->alamat = NULL;

    printf("SELAMAT DATANG DI PERPUSTAKAAN IT DEL\n");
    printf("\tMenu\n");
    printf("1. Tampilkan Semua Buku\n");
    printf("2. Tampilkan Data Dosen\n");
    printf("3. Cari Buku Berdasarkan ISBN\n");
    printf("4. Cari Buku Berdasarkan NIDN\n");
    printf("5. Tambahkan Buku\n");
    printf("6. Keluar\n");

    do
    {
        printf("\nPILIH MENU\t: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            printf("\n\tDATA BUKU\n");
            cetakDataBuku(B1);
            printf("\n");
            break;
        case 2:
            printf("\n\tDATA DOSEN\n");
            cetakDataDosen(D1);
            printf("\n");
            break;
        case 3:
            printf("\n\tCARI BUKU BERDASARKAN ISBN\n");
            char cari[100];
            printf("Masukkan ISBN: ");
            scanf("%s", &cari);
            searchBuku(B1, cari);
            printf("\n");
            break;
        case 4:
            printf("\nCARI JUMLAH BUKU HIBAHAN DOSEN\n");
            char search[100];
            printf("Masukkan NIDN: ");
            scanf("%s", &search);
            searchNIDN(D1, B1, search);
            printf("\n");
            break;
        case 5:
            printf("\n\tTAMBAH DATA BUKU\n");
            printf("Data Dosen\n");
            cetakDataDosen(D1);
            if (D1 == NULL)
            {
                printf("Data Dosen masih kosong!\n");
                break;
            }
            else
            {
                printf("Pilih dosen yang ingin donasi buku: ");
                scanf("%i", &pilih_dosen);
                if (getNIDN(D1, pilih_dosen) == NULL)
                {
                    break;
                }
                else
                {
                    strcpy(NIDN, getNIDN(D1, pilih_dosen));
                }
            }
            printf("Masukkan Jumlah Data Buku(Sesuai Jumlah data buku realnya):");
            scanf(" %d", &batas);

            for (i = 1; i <= batas; i++)
            {
                dbuku *DataBuku = malloc(sizeof(dbuku) * 1);
                printf("Masukkan ISBN %d: ", i);
                scanf("%s", DataBuku->ISBN);
                getchar();
                printf("Masukkan Judul Buku %d: ", i);
                scanf("%24[^\n]s", DataBuku->judul_buku);
                getchar();
                printf("Masukkan Jenis Buku %d: ", i);
                scanf("%s", DataBuku->jenis_buku);
                getchar();
                printf("Masukkan Author %d: ", i);
                scanf("%s", DataBuku->author);
                getchar();
                strcpy(DataBuku->NIDN, NIDN);
                printf("Masukkan Jumlah %d: ", i);
                scanf("%d", &DataBuku->jumlah);

                if (B1 == NULL)
                {
                    AddNewDataBuku(&B1, DataBuku);
                }
                else
                {
                    AddNextDataBuku(&B1, DataBuku);
                }
            }
            printf("\n");
            cetakDataBuku(B1);
            break;
        default:
            break;
        }

    } while (opsi != 0);

    return 1;
}
