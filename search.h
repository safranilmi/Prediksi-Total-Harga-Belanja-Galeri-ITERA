int CariNama (string nama[], int ID[], int harga[], int BanyakData, string cari) {
    int j=0;
    bool ketemu=false;

    while (j<=BanyakData && (!(ketemu))) {
        if (cari == nama[j]) {
            ketemu=true;
        } else {
            j++;
        }
    }

    return j;
}

void CariID (string nama[], int ID[], int harga[], int BanyakData) {
    int dicari;

    cout << "Masukkan ID barang yang dicari (" << 0 << "-"  << BanyakData-1 << ") : ";
    cin >> dicari;

    print(nama, ID, harga, BanyakData, dicari);
}

void belanja (string nama[], int ID[], int harga[], int BanyakData) {
    char yt;
    int i=0,  dicari, Indek[BatasData], JumlahBarang[BatasData], sum=0, j, k;
    bool BerentiMencari=false;
    cari:
    do {
        int dicari;

        cout << "Masukkan ID barang (" << 0 << "-"  << BanyakData-1 << ") : ";
        cin >> dicari;

        if (dicari<0 || dicari>BanyakData-1) {
            goto akhirmencari;
        } else {
            Indek[i]=dicari;
        }

        print(nama, ID, harga, BanyakData, dicari);

        do {
            cout << "Apakah Anda mau menambahkan barang tesebut ke belanjaan (y/t) : ";
            cin >> yt;
        }while (yt!='y' && yt!='t');

        if (yt=='y') {
            cout << "Jumlah barang : ";
            cin >> JumlahBarang[i];
            cout << endl;
        } else {
            cout << endl;
            goto cari;
        }
        i++;

    } while (i<BanyakData && (!(BerentiMencari)));
    akhirmencari:

    printbelanja(nama, ID, harga, BanyakData, Indek, JumlahBarang, i);
}
