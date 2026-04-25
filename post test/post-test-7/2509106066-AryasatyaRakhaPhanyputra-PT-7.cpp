#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

#define MAX_LIGHTNOVEL 100

struct login {
    string username;
    string password;
};

struct detail {
    string genre;
    int volume;
    string status;
};

struct Lightnovel {
    int id;
    string judul;
    string author;
    detail detailNovel;
};

Lightnovel novel[MAX_LIGHTNOVEL] = {
    {1, "Sword Art Online", "Reki Kawahara", {"Fantasy", 27, "Ongoing"}},
    {2, "Overlord", "Kugane Maruyama", {"Isekai", 17, "Ongoing"}},
    {3, "Classroom of the Elite", "Syougo Kinugasa", {"School", 31, "Ongoing"}}
};

int jumlahNovel = 3;

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Overloading
string Pesan(string nama) {
    string tx = "Selamat datang " + nama + " di Sistem Informasi Light Novel.\n";
    cout << tx;
    return tx;
}

string Pesan(string nama, string status) {
    string tx = "Halo " + nama + ", " + status;
    cout << tx;
    return tx;
}

void Header(string judul) {
    cout << "\n" << judul << "\n";
    cout << "================================================================================================\n";
    cout << "|" << setw(4) << "ID" << " | ";
    cout << setw(25) << "Judul" << " | ";
    cout << setw(20) << "Author" << " | ";
    cout << setw(12) << "Genre" << " | ";
    cout << setw(6) << "Vol" << " | ";
    cout << setw(12) << "Status" << " |\n";
    cout << "================================================================================================\n";
}

void tukarnovel(Lightnovel* a, Lightnovel* b) {
    Lightnovel temp = *a;
    *a = *b;
    *b = temp;
}

// Rekursif
int rekursifread(Lightnovel novelArr[], int n) {
    if (n == 0) return 0;
    rekursifread(novelArr, n - 1);
    cout << "|" << setw(4) << novelArr[n - 1].id << " | ";
    cout << setw(25) << novelArr[n - 1].judul << " | ";
    cout << setw(20) << novelArr[n - 1].author << " | ";
    cout << setw(12) << novelArr[n - 1].detailNovel.genre << " | ";
    cout << setw(6) << novelArr[n - 1].detailNovel.volume << " | ";
    cout << setw(12) << novelArr[n - 1].detailNovel.status << " |\n";
    return n;
}

void lihatNovel(Lightnovel *novelArr, int jml, bool clear = true) {
    if (clear) system("cls");
    if (jml == 0) {
        cout << "Belum ada data novel.\n";
        return;
    }
    Header(" Daftar Light Novel :\n");
    rekursifread(novelArr, jml);
    cout << "================================================================================================\n\n";
}

int tambahNovel(Lightnovel novelArr[], int &jml) {
    system("cls");
    if (jml >= MAX_LIGHTNOVEL) {
        throw length_error("Data novel penuh! Tidak bisa menambah lebih dari 100 data.");
    }
    Lightnovel Novelbaru;
    Lightnovel *novelPtr = &Novelbaru;
    novelPtr->id = jml + 1;
    cout << "Masukkan Judul Light Novel : ";
    getline(cin, novelPtr->judul);
    if (novelPtr->judul.empty()) {
        throw length_error("Judul tidak boleh kosong!");
    }
    if ((int)novelPtr->judul.length() > 25) {
        throw length_error("Judul terlalu panjang! Maksimal 25 karakter.");
    }
    cout << "Masukkan Author            : ";
    getline(cin, novelPtr->author);
    cout << "Masukkan Genre             : ";
    getline(cin, novelPtr->detailNovel.genre);
    cout << "Masukkan Volume            : ";
    cin >> novelPtr->detailNovel.volume;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input Volume harus berupa angka!");
    }
    if (novelPtr->detailNovel.volume <= 0) {
        clearBuffer();
        throw out_of_range("Volume harus lebih dari 0!");
    }
    clearBuffer();
    cout << "Masukkan Status (Ongoing/Completed) : ";
    getline(cin, novelPtr->detailNovel.status);
    if (novelPtr->detailNovel.status != "Ongoing" &&
        novelPtr->detailNovel.status != "Completed") {
        throw invalid_argument("Status harus 'Ongoing' atau 'Completed'!");
    }
    novelArr[jml] = Novelbaru;
    jml++;
    return 1;
}

void updateNovel(Lightnovel *novelArr, int jml) {
    system("cls");
    if (jml == 0) {
        cout << "\nBelum ada data Light Novel untuk diupdate.\n\n";
        return;
    }

    int id;
    Header(" Daftar Light Novel :\n");
    for (int i = 0; i < jml; i++) {
        cout << "|";
        cout << setw(4) << novelArr[i].id << " | ";
        cout << setw(25) << novelArr[i].judul << " | ";
        cout << setw(20) << novelArr[i].author << " | ";
        cout << setw(12) << novelArr[i].detailNovel.genre << " | ";
        cout << setw(6) << novelArr[i].detailNovel.volume << " | ";
        cout << setw(12) << novelArr[i].detailNovel.status << " |\n";
    }
    cout << "=================================================================================================\n";

    cout << "\nMasukkan ID Light Novel yang ingin diupdate : ";
    cin >> id;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input ID harus berupa angka!");
    }
    int index = id - 1;
    if (index < 0 || index >= jml) {
        cout << "ID tidak ditemukan.\n";
        return;
    }
    Lightnovel *targetNovel = &novelArr[index];
    int field;
    cout << "\nField yang ingin diupdate\n";
    cout << "1. Judul\n";
    cout << "2. Author\n";
    cout << "3. Genre\n";
    cout << "4. Volume\n";
    cout << "5. Status\n";
    cout << "Pilih : ";
    cin >> field;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input field harus berupa angka!");
    }
    if (field < 1 || field > 5) {
        clearBuffer();
        throw out_of_range("Pilihan field tidak tersedia.");
    }
    clearBuffer();
    if (field == 1) {
        cout << "Masukkan Judul Baru : ";
        getline(cin, targetNovel->judul);
    } else if (field == 2) {
        cout << "Masukkan Author Baru : ";
        getline(cin, targetNovel->author);
    } else if (field == 3) {
        cout << "Masukkan Genre Baru : ";
        getline(cin, targetNovel->detailNovel.genre);
    } else if (field == 4) {
        cout << "Masukkan Volume Baru : ";
        cin >> targetNovel->detailNovel.volume;
        if (cin.fail()) {
            clearBuffer();
            throw invalid_argument("Input Volume harus berupa angka!");
        }
        if (targetNovel->detailNovel.volume <= 0) {
            clearBuffer();
            throw out_of_range("Volume harus lebih dari 0!");
        }
        clearBuffer();
    } else if (field == 5) {
        cout << "Masukkan Status Baru : ";
        getline(cin, targetNovel->detailNovel.status);
        if (targetNovel->detailNovel.status != "Ongoing" &&
            targetNovel->detailNovel.status != "Completed") {
            throw invalid_argument("Status harus 'Ongoing' atau 'Completed'!");
        }
    }
    cout << "\nData berhasil diupdate.\n\n";
}

int hapusNovel(Lightnovel novelArr[], int *jml) {
    system("cls");
    if (*jml == 0) {
        cout << "\nBelum ada data Light Novel untuk dihapus.\n\n";
        return 0;
    }
    Header(" Daftar Light Novel :\n");
    for (int i = 0; i < *jml; i++) {
        cout << "|";
        cout << setw(4) << novelArr[i].id << " | ";
        cout << setw(25) << novelArr[i].judul << " | ";
        cout << setw(20) << novelArr[i].author << " | ";
        cout << setw(12) << novelArr[i].detailNovel.genre << " | ";
        cout << setw(6) << novelArr[i].detailNovel.volume << " | ";
        cout << setw(12) << novelArr[i].detailNovel.status << " |\n";
    }
    cout << "=================================================================================================\n";

    int id;
    cout << "Masukkan ID yang ingin dihapus : ";
    cin >> id;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input ID harus berupa angka!");
    }
    int index = id - 1;
    if (index < 0 || index >= *jml) {
        cout << "ID tidak ditemukan.\n\n";
        return 0;
    }

    int alasan;
    cout << "\nAlasan penghapusan:\n";
    cout << "1. Seri tidak dilanjutkan (Axed)\n";
    cout << "2. Author sedang ada masalah\n";
    cout << "Pilih alasan : ";
    cin >> alasan;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input alasan harus berupa angka!");
    }
    if (alasan < 1 || alasan > 2) {
        clearBuffer();
        throw out_of_range("Pilihan alasan tidak tersedia.");
    }
    for (int i = index; i < *jml - 1; i++) {
        novelArr[i] = novelArr[i + 1];
        novelArr[i].id = i + 1;
    }
    (*jml)--;
    cout << "\nData berhasil dihapus.\n\n";
    return 1;
}

void merge(Lightnovel* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Lightnovel* L = new Lightnovel[n1];
    Lightnovel* R = new Lightnovel[n2];

    for (int i = 0; i < n1; i++) *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->judul <= (R + j)->judul) *(arr + k++) = *(L + i++);
        else *(arr + k++) = *(R + j++);
    }
    while (i < n1) *(arr + k++) = *(L + i++);
    while (j < n2) *(arr + k++) = *(R + j++);

    delete[] L;
    delete[] R;
}

void mergeSort(Lightnovel* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void tampilmerge(Lightnovel* arr, int left, int right) {
    (void)arr; (void)left; (void)right;
    system("cls");
    if (jumlahNovel == 0) {
        cout << "Belum ada data Light novel.\n";
        return;
    }
    cout << "Data sebelum diurutkan berdasarkan judul (A-Z)\n";
    lihatNovel(novel, jumlahNovel, false);
    mergeSort(novel, 0, jumlahNovel - 1);
    cout << "Data berhasil diurutkan berdasarkan judul (A-Z)!\n";
    lihatNovel(novel, jumlahNovel, false);
}

void selectionSortVolume(Lightnovel* arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data Light novel.\n";
        return;
    }
    cout << "Data sebelum diurutkan berdasarkan Volume (Terdikit)\n";
    lihatNovel(novel, jumlahNovel, false);

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->detailNovel.volume < (arr + minIdx)->detailNovel.volume) {
                minIdx = j;
            }
        }
        if (minIdx != i) tukarnovel(arr + i, arr + minIdx);
    }

    cout << "Data berhasil diurutkan berdasarkan Volume (Terdikit)!\n";
    lihatNovel(arr, n, false);
}

void bubbleSort(Lightnovel *arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data Light novel.\n";
        return;
    }
    cout << "Data sebelum diurutkan berdasarkan Author (Z-A)\n";
    lihatNovel(novel, jumlahNovel, false);

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->author < (arr + j + 1)->author) {
                tukarnovel(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "Data berhasil diurutkan berdasarkan Author (Z-A)!\n";
    lihatNovel(arr, n, false);
}

int binarysearch(Lightnovel* arr, int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->id > (arr + j + 1)->id) {
                tukarnovel(arr + j, arr + j + 1);
            }
        }
    }
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((arr + mid)->id == target) return mid;
        else if ((arr + mid)->id < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int linearsearch(Lightnovel* arr, int n, string target) {
    for (int i = 0; i < n; i++) {
        if ((arr + i)->judul == target) return i;
    }
    return -1;
}

void Fitursearch(Lightnovel* arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data Light Novel.\n";
        system("pause");
        return;
    }

    int pilih;
    cout << "========================================================\n";
    cout << "|             MENU SEARCHING LIGHT NOVEL               |\n";
    cout << "========================================================\n";
    cout << "|1. Cari berdasarkan ID Light novel (Binary Search)    |\n";
    cout << "|2. Cari berdasarkan Judul Light novel (Linear Search) |\n";
    cout << "========================================================\n";
    cout << "Pilih : ";
    cin >> pilih;
    if (cin.fail()) {
        clearBuffer();
        throw invalid_argument("Input menu searching harus berupa angka!");
    }
    if (pilih < 1 || pilih > 2) {
        clearBuffer();
        throw out_of_range("Menu searching tidak tersedia.");
    }
    clearBuffer();
    if (pilih == 1) {
        int cariID;
        cout << "Masukkan ID yang dicari : ";
        cin >> cariID;
        if (cin.fail()) {
            clearBuffer();
            throw invalid_argument("Input ID yang dicari harus berupa angka!");
        }
        int hasil = binarysearch(arr, n, cariID);
        if (hasil != -1) {
            Header(" Hasil Pencarian ");
            cout << "|" << setw(4) << (arr + hasil)->id << " | "
                 << setw(25) << (arr + hasil)->judul << " | "
                 << setw(20) << (arr + hasil)->author << " | "
                 << setw(12) << (arr + hasil)->detailNovel.genre << " | "
                 << setw(6) << (arr + hasil)->detailNovel.volume << " | "
                 << setw(12) << (arr + hasil)->detailNovel.status << " |\n";
            cout << "================================================================================================\n";
        } else {
            cout << "ID tidak ditemukan.\n";
        }
    } else {
        string cariJudul;
        cout << "Masukkan Judul yang dicari : ";
        getline(cin, cariJudul);
        int hasil = linearsearch(arr, n, cariJudul);
        if (hasil != -1) {
            Header(" Hasil Pencarian ");
            cout << "|" << setw(4) << (arr + hasil)->id << " | "
                 << setw(25) << (arr + hasil)->judul << " | "
                 << setw(20) << (arr + hasil)->author << " | "
                 << setw(12) << (arr + hasil)->detailNovel.genre << " | "
                 << setw(6) << (arr + hasil)->detailNovel.volume << " | "
                 << setw(12) << (arr + hasil)->detailNovel.status << " |\n";
            cout << "================================================================================================\n";
        } else {
            cout << "Judul tidak ditemukan.\n";
        }
    }
    system("pause");
}

bool loginProgram(login user) {
    string username, password;
    int kesempatan = 0;
    while (kesempatan < 3) {
        cout << "Username : "; cin >> username;
        cout << "Password : "; cin >> password;
        if (username == user.username && password == user.password) {
            clearBuffer();
            Pesan(username, "Login berhasil ");
            system("pause");
            return true;
        }
        kesempatan++;
        cout << "Login gagal (" << kesempatan << "/3)\n";
    }
    return false;
}

void menuCRUD(Lightnovel novelArr[], int &jml) {
    int pilih;
    do {
        system("cls");
        cout << "========================================\n";
        cout << "|    MENU CRUD INFORMASI LIGHT NOVEL   |\n";
        cout << "========================================\n";
        cout << "|1. Lihat Light Novel                  |\n";
        cout << "|2. Tambah Light Novel                 |\n";
        cout << "|3. Perbarui Light Novel               |\n";
        cout << "|4. Hapus Light Novel                  |\n";
        cout << "|5. Urut Judul Light Novel(A-Z)        |\n";
        cout << "|6. Urut Volume Light Novel(Terdikit)  |\n";
        cout << "|7. Urut Author Light novel(Z-A)       |\n";
        cout << "|8. Searching Light Novel              |\n";
        cout << "|9. Keluar                             |\n";
        cout << "========================================\n";
        cout << "Pilih menu : ";

        try {
            cin >> pilih;
            if (cin.fail()) {
                clearBuffer();
                throw invalid_argument("Input menu harus berupa angka!");
            }
            if (pilih < 1 || pilih > 9) {
                clearBuffer();
                throw out_of_range("Menu tidak tersedia!");
            }
            clearBuffer();

            switch (pilih) {
                case 1:
                    lihatNovel(novelArr, jml);
                    system("pause");
                    break;
                case 2:
                    if (tambahNovel(novelArr, jml)) {
                        cout << "Data berhasil ditambahkan!\n";
                    }
                    system("pause");
                    break;
                case 3:
                    updateNovel(novelArr, jml);
                    system("pause");
                    break;
                case 4:
                    if (hapusNovel(novelArr, &jml)) {
                        cout << "Data berhasil dihapus!\n";
                    }
                    system("pause");
                    break;
                case 5:
                    tampilmerge(novelArr, 0, jml - 1);
                    system("pause");
                    break;
                case 6:
                    selectionSortVolume(novelArr, jml);
                    system("pause");
                    break;
                case 7:
                    bubbleSort(novelArr, jml);
                    system("pause");
                    break;
                case 8:
                    Fitursearch(novelArr, jml);
                    break;
                case 9:
                    system("cls");
                    cout << "================================\n";
                    cout << "|         TERIMA KASIH!        |\n";
                    cout << "|        Program selesai       |\n";
                    cout << "================================\n\n";
                    break;
            }
        }
        catch (const length_error& e) {
            cout << "\n[LENGTH ERROR] " << e.what() << "\n";
            system("pause");
            pilih = 0;
        }
        catch (const invalid_argument& e) {
            cout << "\n[INPUT ERROR] " << e.what() << "\n";
            system("pause");
            pilih = 0;
        }
        catch (const out_of_range& e) {
            cout << "\n[RANGE ERROR] " << e.what() << "\n";
            system("pause");
            pilih = 0;
        }
        catch (const exception& e) {
            cout << "\n[ERROR] " << e.what() << "\n";
            system("pause");
            pilih = 0;
        }
    } while (pilih != 9);
}

int main() {
    login user = {"Arya", "066"};
    cout << "====================================\n";
    cout << "|   SISTEM INFORMASI LIGHT NOVEL   |\n";
    cout << "|      PROGRAM CRUD SEDERHANA      |\n";
    cout << "====================================\n\n";
    Pesan("Arya");
    if (loginProgram(user)) {
        menuCRUD(novel, jumlahNovel);
    }
    return 0;
}