#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeaderPerpustakaan.h"

void cetakDataBuku(dbuku *data)
{
    while (data != NULL)
    {
        printf("ISBN\t: %s\nJudul\t: %s\nJenis\t: %s\nAuthor\t: %s\nJumlah\t: %d\nNIDN\t: %s\n\n", data->ISBN, data->judul_buku, data->jenis_buku, data->author, data->jumlah, data->NIDN);
        data = data->alamat;
    }
}

void cetakDataDosen(ddosen *data)
{
    while (data != NULL)
    {
        printf("NIDN\t\t: %s\nNama Dosen\t: %s\nNomor Telepon\t: %s\n\n", data->NIDN, data->nama, data->no_telp);
        data = data->alamat;
    }
}

void searchBuku(dbuku *data, char *cari)
{
    while (data != NULL)
    {
        if (strcmp(data->ISBN, cari) == 0)
        {
            printf("ISBN\t: %s\nJudul\t: %s\nJenis\t: %s\nAuthor\t: %s\nJumlah\t: %d\nNIDN\t: %s\n", data->ISBN, data->judul_buku, data->jenis_buku, data->author, data->jumlah, data->NIDN);
            data = data->alamat;
        }
        data = data->alamat;
    }
}

void searchNIDN(ddosen *data, dbuku *isi, char *cari)
{
    while (data != NULL)
    {
        if (strcmp(data->NIDN, cari) == 0)
        {
            printf("NIDN\t\t: %s\nNama Dosen: %s\nNomor Telepon: %s\n\n", data->NIDN, data->nama, data->no_telp);
            printf("Jumlah buku hibah\t: %d\n", isi->jumlah);
        }
        data = data->alamat;
    }
}

ddosen *AddNewDataDosen(ddosen **nodeRef, ddosen *data)
{
    ddosen *DataDosen = (ddosen *)malloc(sizeof(ddosen) * 1);
    strcpy(DataDosen->NIDN, data->NIDN);
    strcpy(DataDosen->nama, data->nama);
    strcpy(DataDosen->no_telp, data->no_telp);

    DataDosen->alamat = (*nodeRef);
    (*nodeRef) = DataDosen;
    return DataDosen;
}

ddosen *AddNextDataDosen(ddosen **nodeRef, ddosen *data)
{
    ddosen *nextData = (ddosen *)malloc(sizeof(ddosen) * 1);
    ddosen *last = *nodeRef;

    nextData->alamat = NULL;

    strcpy(nextData->NIDN, data->NIDN);
    strcpy(nextData->nama, data->nama);
    strcpy(nextData->no_telp, data->no_telp);

    if (*nodeRef == NULL)
    {
        *nodeRef = nextData;
        return 0;
    }

    while (last->alamat != NULL)
    {
        last = last->alamat;
    }

    last->alamat = nextData;
}

dbuku *AddNewDataBuku(dbuku **nodeRef, dbuku *data)
{
    dbuku *DataBuku = (dbuku *)malloc(sizeof(dbuku) * 1);
    strcpy(DataBuku->ISBN, data->ISBN);
    strcpy(DataBuku->judul_buku, data->judul_buku);
    strcpy(DataBuku->jenis_buku, data->jenis_buku);
    strcpy(DataBuku->author, data->author);
    strcpy(DataBuku->NIDN, data->NIDN);
    DataBuku->jumlah = data->jumlah;

    DataBuku->alamat = (*nodeRef);
    (*nodeRef) = DataBuku;
    return DataBuku;
}

dbuku *AddNextDataBuku(dbuku **nodeRef, dbuku *data)
{
    dbuku *next_node = malloc(sizeof(dbuku) * 1);
    dbuku *last = *nodeRef;

    next_node->alamat = NULL;

    strcpy(next_node->ISBN, data->ISBN);
    strcpy(next_node->judul_buku, data->judul_buku);
    strcpy(next_node->jenis_buku, data->jenis_buku);
    strcpy(next_node->author, data->author);
    strcpy(next_node->NIDN, data->NIDN);
    next_node->jumlah = data->jumlah;

    if (*nodeRef == NULL)
    {
        *nodeRef = next_node;
        return 0;
    }

    while (last->alamat != NULL)
    {
        last = last->alamat;
    }

    last->alamat = next_node;
}

char *getNIDN(ddosen *data, int pilihan)
{
    int i = 1;
    char NIDN[10];
    while (data != NULL)
    {
        if (i == pilihan)
        {
            return data->NIDN;
        }
        else
        {
            printf("NIDN tidak ditemukan!");
            return 0;
        }
        i++;
        data = data->alamat;
    }
}
