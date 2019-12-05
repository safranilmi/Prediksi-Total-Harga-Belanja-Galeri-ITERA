void SortingHarga (string nama[], int ID[], int harga[], int BanyakData) {
    int i, j, tmpID, tmpHarga;
    string tmpNama;
    for (i=0; i<BanyakData; i++){
        for (j=i+1;j<BanyakData; j++){
            if (harga[j] < harga[i]){
                tmpNama=nama[i];
                nama[i]=nama[j];
                nama[j]=tmpNama;

                tmpID=ID[i];
                ID[i]=ID[j];
                ID[j]=tmpID;

                tmpHarga=harga[i];
                harga[i]=harga[j];
                harga[j]=tmpHarga;
            }
        }
    }
    printall(nama, ID, harga, BanyakData, i=0);
}
