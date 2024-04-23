#include <iostream>
#include <conio.h>
#include <string> // Untuk getch() dan clrscr()

using namespace std;

// Fungsi untuk menghitung nilai akhir
float hitung_nilai_akhir(float NilaiKeaktifan, float NilaiTugas, float NilaiUjian) {
    float nilai_murni_keaktifan = NilaiKeaktifan * 0.20;
    float nilai_murni_tugas = NilaiTugas * 0.50;
    float nilai_murni_ujian = NilaiUjian * 0.30;

    return nilai_murni_keaktifan + nilai_murni_tugas + nilai_murni_ujian;
}

int main() {
    string nama_siswa;
    float NilaiKeaktifan, NilaiTugas, NilaiUjian;

    // Layar masukkan
    cout << "PROGRAM MENGHITUNG NILAI AKHIR" << endl;
    cout << "Nama Siswa: ";
    getline(cin, nama_siswa);
    cout << "Nilai Keaktifan: ";
    cin >> NilaiKeaktifan;
    cout << "Nilai Tugas: ";
    cin >> NilaiTugas;
    cout << "Nilai Ujian: ";
    cin >> NilaiUjian;

    // Hitung nilai akhir
    float nilai_akhir = hitung_nilai_akhir(NilaiKeaktifan, NilaiTugas, NilaiUjian);
    char grade;
    if (nilai_akhir > 80) {
        grade = 'A';
    } else if (nilai_akhir > 70 < 81 ) {
        grade = 'B';
    } else if (nilai_akhir > 56 < 71) {
        grade = 'C';
    } else if (nilai_akhir > 46 < 57) {
        grade = 'D';
    } else {
        grade = 'E';
    }

    // Layar keluaran
    system("cls"); // Menghapus layar

    cout << "Siswa yang bernama " << nama_siswa << endl;
    cout << "Dengan Nilai Persentasi Yang dihasilkan." << endl;
    cout << "Nilai Keaktifan * 20%: " << NilaiKeaktifan * 0.20 << endl;
    cout << "Nilai Tugas * 30%: " << NilaiTugas * 0.30 << endl;
    cout << "Nilai Ujian * 50%: " << NilaiUjian * 0.50 << endl;
    cout << "Jadi siswa yang bernama " << nama_siswa;
    cout << " memperoleh nilai akhir sebesar " << nilai_akhir;
    cout << " dengan grade " << grade << endl;

    getch(); // Menahan layar keluaran
    return 0;
}
