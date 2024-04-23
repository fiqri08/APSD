#include <iostream>
#include <conio.h>
#include <string> // Untuk getch() dan clrscr()

using namespace std;

// Fungsi untuk menghitung nilai akhir
float hitung_ratarata_siswa(float Nilaipertandingan1, float Nilaipertandingan2, float Nilaipertandingan3) {
    float nilai_murni_pertandingan1 = Nilaipertandingan1;
    float nilai_murni_pertandingan2 = Nilaipertandingan2;
    float nilai_murni_pertandingan3 = Nilaipertandingan3;

    return (nilai_murni_pertandingan1 + nilai_murni_pertandingan2 + nilai_murni_pertandingan3)/3;
}

int main() {
    string nama_siswa;
    float Nilaipertandingan1, Nilaipertandingan2, Nilaipertandingan3;

    cout << "PROGRAM MENGHITUNG NILAI RATA RATA SISWA" << endl;
    cout << "Nama Siswa : ";
    getline(cin, nama_siswa);
    cout << "Nilai Pertandingan I : ";
    cin >> Nilaipertandingan1;
    cout << "Nilai Pertandingan II : ";
    cin >> Nilaipertandingan2;
    cout << "Nilai Pertandingan III : ";
    cin >> Nilaipertandingan3;

    float nilai_ratarata = hitung_ratarata_siswa( Nilaipertandingan1, Nilaipertandingan2, Nilaipertandingan3);
    char grade;
    if (nilai_ratarata > 80) {
        grade = 'Juara 1';
    } else if (nilai_ratarata > 75 < 81 ) {
        grade = 'Juara 2';
    } else if (nilai_ratarata > 65 < 76) {
        grade = 'Juara 3';
    } else {
        grade = 'Tidak Juara';
    }


    system("cls"); // Menghapus layar

    cout << "Siswa yang bernama " << nama_siswa << endl;
    cout << "Memperoleh nilai rata-rata ";
    cout << nilai_ratarata;
    cout << " dan menjadi juara ke- " << grade;
    cout << " dari hasil perlombaan yang diikutinya." << endl;

    getch(); // Menahan layar keluaran
    return 0;
}
