#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int BatasData = 10;

#include "print.h"
#include "sorting.h"
#include "search.h"
#include "record & data.h"

int main () {
    cout << "Selamat datang pada program yang kami buat" << endl << endl;

    awal:

    string temp, cari;
    fstream file;
    data x;
    char pilih, yt;
    int IndeksData, i, indek;

    //data
    file.open("Data.dat", ios::in | ios::out);
    IndeksData=0;

    //Membaca data
    while(getline(file,x.nama[IndeksData]) && x.nama[IndeksData] != "stop") {
        file >> x.ID[IndeksData];
        file >> x.harga[IndeksData];
        IndeksData++;
        file.ignore();
        getline(file,temp);
    }

    file.close();

    //pilihan
    cout << "Silahkan pilih menu yang di inginkan" << endl;
    cout << "1. Tampilkan seluruh data." << endl;
    cout << "2. Mencari barang berdasarkan nama." << endl;
    cout << "3. Mencari barang berdasarkan ID." << endl;
    cout << "4. Sorting berdasarkan harga barang." << endl;
    cout << "5. Menghitung total belanjaan." << endl;
    cout << "6. Keluar dari program" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    cout << endl;

    if (pilih!='5') {
        system("cls");
    }

    switch (pilih) {
        case '1' : //Tampilkan seluruh data
            printall(x.nama, x.ID, x.harga, IndeksData, i=0);
        break;
        case '2' : //Mencari barang berdasarkan nama
            cout << "Masukkan nama barang yang dicari : ";
            cin.ignore();
            getline(cin,cari);
            indek = CariNama(x.nama, x.ID, x.harga, IndeksData, cari);
            print(x.nama, x.ID, x.harga, IndeksData, indek);
        break;
        case '3' : //Mencari barang berdasarkan ID
            CariID(x.nama, x.ID, x.harga, IndeksData);
        break;
        case '4' : //Sorting berdasarkan harga barang
            SortingHarga(x.nama, x.ID, x.harga, IndeksData);
        break;
        case '5' : //Menghitung total belanjaan
            belanja(x.nama, x.ID, x.harga, IndeksData);
        break;
        case '6' : //Untuk keluar dari program
            goto akhir;
        break;
        case '+' : //Menambah data barang
            tambah(x.nama, x.ID, x.harga, IndeksData);
        break;
        case '=' : //Mengganti data barang
            ganti(x.nama, x.ID, x.harga, IndeksData);
        break;
        default: //Jika salah memasukkan pilihan
            do {
                cout << "Maaf, pilihan Anda tidak tersedia" << endl;
                cout << "Apakah Anda ingin mengulangnya (y/t) : ";
                cin >> yt;
            }while (yt!='y' && yt!='t');

            if (yt == 't') {
                system("cls");
                goto akhir;
            }
    }

    cout << endl << "Tekan apapun untuk melanjutkan" << endl << endl;
    system("pause>null");
    goto awal;

    akhir:

    cout << "Terimakasih telah menggunakan program yang kami buat" << endl;
    cout << "Pembuat : Liga Septian, Aurelia Intan Sabila, Safran Ilmi" << endl << endl;

    return 0;
}
