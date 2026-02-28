#include <iostream>
using namespace std;

int main(){
    string username;
    string password;
    int kesempatan;
    int pilih;
    kesempatan = 0;

    while(kesempatan < 3) {
        cout << "Masukkan username : ";
        cin >> username;
        cout << "Masukkan password : ";
        cin >> password;
        if(username == "Arya" && password == "066") {
            cout << "=====================================\n";
            cout << "|           Login Berhasil!         |\n";
            cout << "|       Selamat datang " << username << "!        |\n";
            cout << "=====================================\n" << endl;
            break;
        } else {
            kesempatan++;
            cout << "Login Gagal! username atau password anda salah, silahkan coba lagi!. Percobaan ke " << kesempatan << " dari 3\n" << endl;
        }
        if (kesempatan == 3){
            cout << "=====================================\n";
            cout << "| Kesempatan login anda sudah habis.|\n";
            cout << "=====================================\n";
            cout << "Program dihentikan.\n"<< endl;
            return 0;
        }
    }

    do {
        cout << "====================================\n";
        cout << "|         MENU KONVERSI WAKTU      |\n";
        cout << "====================================\n";
        cout << "|1. Jam -> Menit & Detik           |\n";
        cout << "|2. Menit -> Jam & Detik           |\n";
        cout << "|3. Detik -> Jam & Menit           |\n";
        cout << "|4. Keluar                         |\n";
        cout << "====================================\n";
        cout << "Pilih menu konversi waktu yang diinginkan : "<< endl;
        cin >> pilih;

        if(pilih == 1){
            float jam;
            cout << "Masukkan Jam : ";
            cin >> jam;
            cout << "Hasil Konversi:\n";
            cout << jam << " Jam = ";
            cout << jam * 60 << " Menit";
            cout << " dan ";
            cout << jam * 3600 << " Detik\n";
            cout << "Konversi selesai kembali ke menu\n"<< endl;            
        }
        else if(pilih == 2){
            int menit;
            int sisaMenit;
            cout << "Masukkan Menit : ";
            cin >> menit;
            cout << "Hasil Konversi:\n";
            cout << menit << " Menit = ";
            cout << menit / 60 << " Jam";
            cout << " ";
            sisaMenit = menit % 60;
            cout << sisaMenit << " Menit";
            cout << " dan ";
            cout << menit * 60 << " Detik\n";
            cout << "Konversi selesai kembali ke menu\n"<< endl;
        }
        else if(pilih == 3){
            int detik;
            int sisaDetik;
            int SisaMenit;
            cout << "Masukkan Detik : ";
            cin >> detik;
            cout << "Hasil Konversi:\n";
            cout << detik << " Detik = ";
            cout << detik / 3600 << " Jam ";
            SisaMenit = detik % 3600;
            cout << SisaMenit / 60 << " Menit dan "; // sisa menit dari konversi detik ke jam
            cout << detik / 60 << " Menit , "; 
            sisaDetik = detik % 60;
            cout << sisaDetik << " Detik\n"; 
            cout << "Konversi selesai kembali ke menu\n"<< endl;
        }
        else if(pilih == 4){
            cout << "================================\n";
            cout << "|         TERIMA KASIH!        |\n";
            cout << "|program selesai, sampai jumpa!|\n";
            cout << "================================\n";
        }
        else{
            cout << "Pilihan menu tidak tersedia!\n"<< endl;
        }
    } while(pilih != 4);
    return 0;
}
