void printall (string nama[], int ID[], int harga[], int BanyakData, int i) {
    if (i==BanyakData-1) {
        cout << "   " << ID[i] << "\t|" << harga[i] << "\t\t|" << nama[i] << endl;
        cout << "=================================================" << endl;
    } else if (i==0) {
        cout << "Daftar seluruh data yang tersedia" << endl << endl;
        cout << "=================================================" << endl;
        cout << "No.ID\t|Harga(Rp.)\t|\tNama Barang" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "   " << ID[i] << "\t|" << harga[i] << "\t\t|" << nama[i] << endl;
        printall(nama, ID, harga, BanyakData, i+1);
    } else {
        cout << "   " << ID[i] << "\t|" << harga[i] << "\t\t|" << nama[i] << endl;
        printall(nama, ID, harga, BanyakData, i+1);
    }
}

void print (string nama[], int ID[], int harga[], int BanyakData, int i) {
    if (i>=0 && i<BanyakData) {
        cout << endl;
        cout << "Nama produk : ";
        cout << nama[i] << endl;
        cout << "Nomor ID : ";
        cout << ID[i] << endl;
        cout << "Harga : ";
        cout << harga[i] << endl << endl;
    } else {
        cout << endl;
        cout << "Barang yang dicari tidak ditemukan" << endl;
    }
}

void printbelanja (string nama[], int ID[], int harga[], int BanyakData, int indek[], int JumlahBarang[], int i) {
    int j, sum=0;

    system("cls");

    cout << "Perkiraan struk belanja" << endl << endl;

    for (j=0; j<i; j++) {
        cout << endl;
        cout << nama[indek[j]] << endl;
        cout << harga[indek[j]] << "\tx " << JumlahBarang[j] << "\t ";
        sum=sum+(harga[indek[j]]*JumlahBarang[j]);
        cout << harga[indek[j]]*JumlahBarang[j] << endl;
    }

    cout << endl;
    cout << "Total belanjaan : " << sum << endl << endl;

}
