#include <iostream>
using namespace std;

int main() {

    string nama;
    string password;
    string passBenar = "123"; // ganti dengan 3 digit terakhir NIM kamu

    int percobaan = 0;
    bool login = false;

    // ======================
    // LOGIN
    // ======================

    cout << "====================================\n";
    cout << "      PROGRAM KONVERSI WAKTU        \n";
    cout << "====================================\n\n";

    while (percobaan < 3) {

        cout << "Login terlebih dahulu\n";
        cout << "Nama     : ";
        cin >> nama;

        cout << "Password : ";
        cin >> password;

        if (password == passBenar) {
            login = true;
            break;
        } else {
            percobaan++;
            cout << "\nPassword salah!\n";
            cout << "Sisa kesempatan : " << 3 - percobaan << endl;
            cout << "--------------------------\n";
        }
    }

    if (!login) {
        cout << "\nAnda gagal login 3 kali!\n";
        cout << "Program berhenti.\n";
        return 0;
    }

    // ======================
    // MENU
    // ======================

    int pilihan;

    do {

        cout << "\n====================================\n";
        cout << "            MENU UTAMA              \n";
        cout << "====================================\n";
        cout << "1. Konversi Jam -> Menit & Detik\n";
        cout << "2. Konversi Menit -> Jam & Detik\n";
        cout << "3. Konversi Detik -> Jam & Menit\n";
        cout << "4. Keluar\n";
        cout << "====================================\n";

        cout << "Pilih menu : ";
        cin >> pilihan;

        if (pilihan == 1) {

            int jam;
            cout << "\nMasukkan Jam : ";
            cin >> jam;

            int menit = jam * 60;
            int detik = jam * 3600;

            cout << "\nHasil Konversi\n";
            cout << jam << " Jam = "
                 << menit << " Menit dan "
                 << detik << " Detik\n";

        }

        else if (pilihan == 2) {

            int menit;
            cout << "\nMasukkan Menit : ";
            cin >> menit;

            int jam = menit / 60;
            int detik = menit * 60;

            cout << "\nHasil Konversi\n";
            cout << menit << " Menit = "
                 << jam << " Jam dan "
                 << detik << " Detik\n";

        }

        else if (pilihan == 3) {

            int detik;
            cout << "\nMasukkan Detik : ";
            cin >> detik;

            int jam = detik / 3600;
            int menit = detik / 60;

            cout << "\nHasil Konversi\n";
            cout << detik << " Detik = "
                 << jam << " Jam dan "
                 << menit << " Menit\n";

        }

        else if (pilihan == 4) {

            cout << "\nTerima kasih!\n";
            cout << "Program selesai.\n";

        }

        else {

            cout << "\nPilihan tidak tersedia!\n";

        }

    } while (pilihan != 4);

}