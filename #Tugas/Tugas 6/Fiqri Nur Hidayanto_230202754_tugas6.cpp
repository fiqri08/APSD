#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    char nilai_huruf;
};

// Fungsi untuk menghitung nilai akhir dan nilai huruf
void hitungNilai(Mahasiswa &mhs) {
    mhs.nilai_akhir = (mhs.nilai_uas * 0.4) + (mhs.nilai_uts * 0.6);
    if (mhs.nilai_akhir >= 80)
        mhs.nilai_huruf = 'A';
    else if (mhs.nilai_akhir >= 70)
        mhs.nilai_huruf = 'B';
    else if (mhs.nilai_akhir >= 56)
        mhs.nilai_huruf = 'C';
    else if (mhs.nilai_akhir >= 47)
        mhs.nilai_huruf = 'D';
    else
        mhs.nilai_huruf = 'E';
}

// Fungsi untuk menampilkan tabel data mahasiswa
void tampilkanTabel(vector<Mahasiswa> &data) {
    cout << setw(4) << "No" << setw(20) << "Nama Mahasiswa" << setw(10) << "Nilai UTS" << setw(10) << "Nilai UAS" << setw(12) << "Nilai Akhir" << setw(12) << "Nilai Huruf" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < data.size(); ++i) {
        cout << setw(4) << i + 1 << setw(20) << data[i].nama << setw(10) << data[i].nilai_uts << setw(10) << data[i].nilai_uas << setw(12) << fixed << setprecision(1) << data[i].nilai_akhir << setw(12) << data[i].nilai_huruf << endl;
    }
}

int main() {
    int banyak_data;
    cout << "Masukkan banyak data mahasiswa: ";
    cin >> banyak_data;

    vector<Mahasiswa> data_mahasiswa(banyak_data);

    for (int i = 0; i < banyak_data; ++i) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama Mahasiswa: ";
        cin >> data_mahasiswa[i].nama;
        cout << "Nilai UTS: ";
        cin >> data_mahasiswa[i].nilai_uts;
        cout << "Nilai UAS: ";
        cin >> data_mahasiswa[i].nilai_uas;

        // Hitung nilai akhir dan nilai huruf
        hitungNilai(data_mahasiswa[i]);
    }

    // Tampilkan tabel data mahasiswa
    cout << "\nTabel Nilai Mahasiswa\n";
    tampilkanTabel(data_mahasiswa);

    return 0;
}
