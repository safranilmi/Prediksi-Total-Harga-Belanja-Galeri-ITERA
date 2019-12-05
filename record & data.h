struct  data{
    string nama[20];
    int ID[20];
    int harga[20];
};

void simpan (string nama[], int ID[], int harga[], int BanyakData) {
    fstream file;
    int j;

    file.open("Data.dat", ios::in | ios::out | ios::trunc);

    for (j=0; j<=BanyakData; j++) {
        file << nama[j] << endl;
        file << ID[j] << endl;
        file << harga[j] << endl << endl;
    }

    file.close();
}

void tambah (string nama[], int ID[], int harga[], int BanyakData) {
    fstream file;
    int j;
    bool stop=false;

     while (BanyakData<BatasData && !stop) {
        cout << "Data ke-" << BanyakData+1 << endl;
        cout << "Masukkan nama produk : ";
        cin.ignore();
        getline(cin,nama[BanyakData]);

        if (nama[BanyakData] == "stop") {
            stop=!stop;
        } else {
            ID[BanyakData] = BanyakData;
            cout << "Masukkan harga : ";
            cin >> harga[BanyakData];
            cout << endl;
            BanyakData++;
        }
    }

    if (BanyakData==BatasData) {
        cout << "Data yang dimasukkan telah mencapai batas. Mohon ubah batas data." << endl << endl;
        nama[BanyakData]="stop";
    }

    simpan(nama, ID, harga, BanyakData);
}

void ganti (string nama[], int ID[], int harga[], int BanyakData) {
    fstream file;
    char yt;
    int j=0;
    int dicari;

    do {
        cout << "Masukkan ID barang (" << 0 << "-"  << BanyakData-1 << ") : ";
        cin >> dicari;

        print(nama, ID, harga, BanyakData, dicari);

    }while (dicari<0 || dicari>BanyakData-1);

    do {
        cout << "Apakah Anda mau mengganti data barang tesebut (y/t) : ";
        cin >> yt;
    }while (yt!='y' && yt!='t');

    if (yt=='y') {
        cout << "Data ke-" << dicari+1 << endl;
        cout << "Masukkan nama produk : ";
        cin.ignore();
        getline(cin,nama[dicari]);
        ID[dicari] = dicari;
        cout << "Masukkan harga : ";
        cin >> harga[dicari];
        cout << endl;
    }

    simpan(nama, ID, harga, BanyakData);
}
