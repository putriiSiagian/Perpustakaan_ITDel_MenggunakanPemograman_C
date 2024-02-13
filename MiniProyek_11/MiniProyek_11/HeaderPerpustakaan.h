typedef struct DataBuku dbuku;
struct DataBuku
{
    char ISBN[10];
    char judul_buku[100];
    char jenis_buku[50];
    char author[50];
    char NIDN[20];
    int jumlah;
    dbuku *alamat;
};

typedef struct DataDosen ddosen;
struct DataDosen
{
    char NIDN[20];
    char nama[50];
    char no_telp[15];
    ddosen *alamat;
};

void cetakDataBuku(dbuku *data);
void cetakDataDosen(ddosen *data);
void searchBuku(dbuku *data, char *cari);
void searchNIDN(ddosen *data, dbuku *isi, char *cari);
ddosen *AddNewDataDosen(ddosen **nodeRef, ddosen *data);
ddosen *AddNextDataDosen(ddosen **nodeRef, ddosen *data);
dbuku *AddNewDataBuku(dbuku **nodeRef, dbuku *data);
dbuku *AddNextDataBuku(dbuku **nodeRef, dbuku *data);
char *getNIDN(ddosen *data, int pilihan);
