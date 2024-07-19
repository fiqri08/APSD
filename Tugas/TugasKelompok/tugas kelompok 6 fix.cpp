#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> // Menyertakan header sstream untuk mengonversi string ke double

using namespace std;

struct Pelanggan {
    string nama;
    string alamat;
    string no_telepon;
    double iuran;
};

// Fungsi untuk menyimpan data pelanggan ke file
void simpanKeFile(const vector<Pelanggan>& pelangganList) {
    ofstream file("data_pelanggan.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < pelangganList.size(); ++i) {
            file << pelangganList[i].nama << "|"
                 << pelangganList[i].alamat << "|"
                 << pelangganList[i].no_telepon << "|"
                 << pelangganList[i].iuran << endl;
        }
    }
}

// Fungsi untuk memuat data pelanggan dari file
void muatDariFile(vector<Pelanggan>& pelangganList) {
    ifstream file("data_pelanggan.txt");
    if (file.is_open()) {
        Pelanggan pelanggan;
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            pelanggan.nama = line.substr(0, pos1);
            pelanggan.alamat = line.substr(pos1 + 1, pos2 - pos1 - 1);
            pelanggan.no_telepon = line.substr(pos2 + 1, pos3 - pos2 - 1);

            // Menggunakan stringstream untuk mengonversi string ke double
            string iuranStr = line.substr(pos3 + 1);
            stringstream ss(iuranStr);
            ss >> pelanggan.iuran;

            pelangganList.push_back(pelanggan);
        }
    }
}

void tambahPelanggan(vector<Pelanggan>& pelangganList) {
    Pelanggan pelangganBaru;
    cout << "Masukkan nama pelanggan: ";
    cin >> pelangganBaru.nama;
    cout << "Masukkan alamat pelanggan: ";
    cin.ignore(); // Mengabaikan karakter newline yang tersisa
    getline(cin, pelangganBaru.alamat);
    cout << "Masukkan nomor telepon pelanggan: ";
    getline(cin, pelangganBaru.no_telepon);
    cout << "Masukkan iuran bulanan: ";
    cin >> pelangganBaru.iuran;
    pelangganList.push_back(pelangganBaru);
    simpanKeFile(pelangganList); // Simpan perubahan ke file
    cout << "Pelanggan berhasil ditambahkan.\n";
}

void hapusPelanggan(vector<Pelanggan>& pelangganList) {
    string nama;
    cout << "Masukkan nama pelanggan yang akan dihapus: ";
    cin >> nama;

    for (size_t i = 0; i < pelangganList.size(); ++i) {
        if (pelangganList[i].nama == nama) {
            pelangganList.erase(pelangganList.begin() + i);
            simpanKeFile(pelangganList); // Simpan perubahan ke file
            cout << "Pelanggan berhasil dihapus.\n";
            return;
        }
    }
    cout << "Pelanggan tidak ditemukan.\n";
}

void editPelanggan(vector<Pelanggan>& pelangganList) {
    string nama;
    cout << "Masukkan nama pelanggan yang akan diedit: ";
    cin >> nama;

    for (size_t i = 0; i < pelangganList.size(); ++i) {
        if (pelangganList[i].nama == nama) {
            cout << "Masukkan alamat baru: ";
            cin.ignore(); // Mengabaikan karakter newline yang tersisa
            getline(cin, pelangganList[i].alamat);
            cout << "Masukkan nomor telepon baru: ";
            getline(cin, pelangganList[i].no_telepon);
            cout << "Masukkan iuran bulanan baru: ";
            cin >> pelangganList[i].iuran;
            simpanKeFile(pelangganList); // Simpan perubahan ke file
            cout << "Data pelanggan berhasil diperbarui.\n";
            return;
        }
    }
    cout << "Pelanggan tidak ditemukan.\n";
}

void hitungPendapatanBulanan(const vector<Pelanggan>& pelangganList) {
    double totalPendapatan = 0;
    for (size_t i = 0; i < pelangganList.size(); ++i) {
        totalPendapatan += pelangganList[i].iuran;
    }
    cout << "Total pendapatan bulanan: " << totalPendapatan << endl;
}

void tampilkanDaftarPelanggan(const vector<Pelanggan>& pelangganList) {
    cout << "\nDaftar Pelanggan:\n";
    for (size_t i = 0; i < pelangganList.size(); ++i) {
        cout << "Nama: " << pelangganList[i].nama << endl;
        cout << "Alamat: " << pelangganList[i].alamat << endl;
        cout << "No. Telepon: " << pelangganList[i].no_telepon << endl;
        cout << "Iuran: " << pelangganList[i].iuran << endl;
        cout << " " << endl;
    }
}

void tampilkanMenu() {
    cout << "\nAplikasi Pengelolaan Data Pelanggan\n";
    cout << "1. Tambah pelanggan\n";
    cout << "2. Hapus pelanggan\n";
    cout << "3. Edit pelanggan\n";
    cout << "4. Hitung total pendapatan bulanan\n";
    cout << "5. Tampilkan daftar pelanggan\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    vector<Pelanggan> pelangganList;
    muatDariFile(pelangganList); // Muat data pelanggan dari file saat program dimulai
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPelanggan(pelangganList);
                break;
            case 2:
                hapusPelanggan(pelangganList);
                break;
            case 3:
                editPelanggan(pelangganList);
                break;
            case 4:
                hitungPendapatanBulanan(pelangganList);
                break;
            case 5:
                tampilkanDaftarPelanggan(pelangganList);
                break;
            case 6:
                cout << "Keluar dari aplikasi.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
