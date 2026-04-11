#include <iostream>
#include <iomanip>
#include <limits> 

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

//Overloading
string Pesan(string nama) {
    string tx = "Selamat datang " + nama + " di Sistem Informasi Light Novel.\n";
    cout << tx;
    return tx;
}

string Pesan(string nama, string status) {
    string tx = "Halo " + nama + ", " + status;
    cout<<tx;
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

//rekursif
int rekursifread(Lightnovel novel[], int n) {
    if (n == 0) return 0;
    rekursifread(novel, n - 1);
    cout << "|" << setw(4) << novel[n - 1].id << " | ";
    cout << setw(25) << novel[n - 1].judul << " | ";
    cout << setw(20) << novel[n - 1].author << " | ";
    cout << setw(12) << novel[n - 1].detailNovel.genre << " | ";
    cout << setw(6) << novel[n - 1].detailNovel.volume << " | ";
    cout << setw(12) << novel[n - 1].detailNovel.status << " |\n";
    return n; 
}

void lihatNovel(Lightnovel *novel, int jumlahNovel) {
    system("cls");
    if (jumlahNovel == 0) {
        cout << "Belum ada data novel.\n";
        return;
    }
    Header(" Daftar Light Novel :\n");
    rekursifread(novel, jumlahNovel);
    cout << "================================================================================================\n\n";
}

int tambahNovel(Lightnovel novel[], int &jumlahNovel) {
    system("cls");
    if (jumlahNovel >= MAX_LIGHTNOVEL) {
        cout << "Data novel penuh\n";
        return 0;
    }

    Lightnovel Novelbaru;
    Lightnovel *novelPtr = &Novelbaru;   
    novelPtr->id = jumlahNovel + 1;   
    cout<< "tekan Enter untuk lanjut...";
    clearBuffer();  
    cout << "Masukkan Judul Light Novel : ";
    getline(cin, novelPtr->judul);  
    cout << "Masukkan Author            : ";
    getline(cin, novelPtr->author);    
    cout << "Masukkan Genre             : ";
    getline(cin, novelPtr->detailNovel.genre);    
    cout << "Masukkan Volume            : ";
    cin >> novelPtr->detailNovel.volume;    
    clearBuffer();     
    cout << "Masukkan Status (Ongoing/Completed) : ";
    getline(cin, novelPtr->detailNovel.status);
    novel[jumlahNovel] = Novelbaru;
    jumlahNovel++;
    return 1;
}

void updateNovel(Lightnovel *novel, int jumlahNovel) {
    system("cls");
    if(jumlahNovel == 0){
        cout<<"\nBelum ada data Light Novel untuk diupdate.\n"<<endl;
    }
    else{
        int id;
        Header(" Daftar Light Novel :\n");
        for(int i=0;i<jumlahNovel;i++){
            cout<<"|";
            cout<<setw(4)<<novel[i].id<<" | ";
            cout<<setw(25)<<novel[i].judul<<" | ";
            cout<<setw(20)<<novel[i].author<<" | ";
            cout<<setw(12)<<novel[i].detailNovel.genre<<" | ";
            cout<<setw(6)<<novel[i].detailNovel.volume<<" | ";
            cout<<setw(12)<<novel[i].detailNovel.status<<" |\n";
        }
        cout<<"=================================================================================================\n";
        cout<<"\nMasukkan ID Light Novel yang ingin diupdate : ";
        cin>>id;
        int index = id - 1;
        if(index < 0 || index >= jumlahNovel){
            cout<<"ID tidak ditemukan.\n";
        }
        else{
            Lightnovel *targetNovel = &novel[index];
            int field;
            cout<<"Field yang ingin diupdate\n";
            cout<<"1. Judul\n";
            cout<<"2. Author\n";
            cout<<"3. Genre\n";
            cout<<"4. Volume\n";
            cout<<"5. Status\n";
            cout<<"Pilih : ";
            cin>>field;
            cin.ignore(1000,'\n');
            if(field == 1){
                cout<<"Masukkan Judul Baru : ";
                getline(cin, targetNovel->judul);
                cout<<"Data berhasil diupdate.\n"<<endl;
            }
            else if(field == 2){
                cout<<"Masukkan Author Baru : ";
                getline(cin, targetNovel->author);
                cout<<"Data berhasil diupdate.\n"<<endl;
            }
            else if(field == 3){
                cout<<"Masukkan Genre Baru : ";
                getline(cin, targetNovel->detailNovel.genre);
                cout<<"Data berhasil diupdate.\n"<<endl;
            }
            else if(field == 4){
                cout<<"Masukkan Volume Baru : ";
                cin>>targetNovel->detailNovel.volume;
                cout<<"Data berhasil diupdate.\n"<<endl;                        
            }
            else if(field == 5){
                cout<<"Masukkan Status Baru : ";
                getline(cin, targetNovel->detailNovel.status);
                cout<<"Data berhasil diupdate.\n"<<endl;
            }
            else{
                cout<<"Pilihan field tidak tersedia. Update dibatalkan.\n";
            }
        }
    }
}  

int hapusNovel(Lightnovel novel[], int *jumlahNovel) {
    system("cls");
    if(*jumlahNovel == 0){
        cout<<"\nBelum ada data Light Novel untuk dihapus.\n"<<endl;
        return 0;  
    }
    else{
        Header(" Daftar Light Novel :\n");
        for(int i=0;i<*jumlahNovel;i++){
            cout<<"|";
            cout<<setw(4)<<novel[i].id<<" | ";
            cout<<setw(25)<<novel[i].judul<<" | ";
            cout<<setw(20)<<novel[i].author<<" | ";
            cout<<setw(12)<<novel[i].detailNovel.genre<<" | ";
            cout<<setw(6)<<novel[i].detailNovel.volume<<" | ";
            cout<<setw(12)<<novel[i].detailNovel.status<<" |\n";
        }
        cout<<"=================================================================================================\n";

        int id;
        cout<<"Masukkan ID yang ingin dihapus : ";
        cin>>id;
        int index = id - 1;
        if(index < 0 || index >= *jumlahNovel){
            cout<<"ID tidak ditemukan.\n"<<endl;
            return 0;  
        }
        else{
            int alasan;
            cout<<"\nAlasan penghapusan:\n";
            cout<<"1. Seri tidak dilanjutkan (Axed)\n";
            cout<<"2. Author sedang ada masalah\n";
            cout<<"Pilih alasan : ";
            cin>>alasan;

            for(int i=index;i<*jumlahNovel-1;i++){
                novel[i] = novel[i+1];
                novel[i].id = i+1;
            }
            (*jumlahNovel)--;
            cout<<"\nData berhasil dihapus.\n\n"<<endl;
            return 1;  
        }
    }
}
void merge(Lightnovel* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Lightnovel* L = new Lightnovel[n1];
    Lightnovel* R = new Lightnovel[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->judul <= (R + j)->judul) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++; k++;
    }
    while (j < n2) {
        *(arr + k) = *(R + j);
        j++; k++;
    }
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
     //system("cls");
     if (jumlahNovel == 0) {
                    cout << "Belum ada data Light novel." << endl;
                    return;
                }
                cout << "Data sebelum diurutkan (berdasarkan nama Kereta)" << endl;
                lihatNovel(novel, jumlahNovel);
                mergeSort(novel, 0, jumlahNovel - 1);
                cout << "Data berhasil diurutkan berdasarkan Nama Kereta!" << endl;
                lihatNovel(novel, jumlahNovel);
}

void selectionSortVolume(Lightnovel* arr, int n) {
    //system("cls");
    if (n == 0) {
        cout << "Belum ada data Light novel." << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->detailNovel.volume < (arr + minIdx)->detailNovel.volume) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            tukarnovel(arr + i, arr + minIdx);
        }
    }
    cout << "============================================================\n";
    cout << "Data berhasil diurutkan berdasarkan Volume (Terdikit)!" << endl;
    lihatNovel(arr, n);
}

void bubbleSort(Lightnovel *arr, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->author < (arr + j + 1)->author) {
                tukarnovel(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    cout << "Data berhasil diurutkan berdasarkan Author (Z-A)!" << endl;
    lihatNovel(arr, n);
}
bool loginProgram(login user) {
    string username, password;
    int kesempatan = 0;
    while (kesempatan < 3) {
        cout << "Username : "; cin >> username;
        cout << "Password : "; cin >> password;
        if (username == user.username && password == user.password) {
            Pesan(username, "Login berhasil ");
            system("pause");
            return true;
        }
        kesempatan++;
        cout << "Login gagal (" << kesempatan << "/3)\n";
    }
    return false;
}

void menuCRUD(Lightnovel novel[], int &jumlahNovel) {
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
        cout << "|8. Keluar                             |\n";
        cout << "========================================\n";
        cout << "Pilih menu : ";
        
        cin >> pilih;  
        clearBuffer();
        
        switch (pilih) {
            case 1:
                lihatNovel(novel, jumlahNovel);
                system("pause");
                break;
            case 2:
                if (tambahNovel(novel, jumlahNovel)) {
                    Pesan("Admin", "Data berhasil ditambahkan ");
                }
                system("pause");
                break;
            case 3:
                updateNovel(novel, jumlahNovel);
                system("pause");
                break;
            case 4:
                if (hapusNovel(novel, &jumlahNovel)) {
                    Pesan("Admin", "Data berhasil dihapus ");
                }
                system("pause");
                break;
            case 5:
                cout << "Data berhasil diurutkan berdasarkan Nama Judul(A-Z)!" << endl;
                tampilmerge(novel, 0, jumlahNovel - 1);
                system("pause");
                break;
            case 6:
                cout << "Data berhasil diurutkan berdasarkan Volume terdikit!" << endl;
                selectionSortVolume(novel, jumlahNovel);
                system("pause");
                break;
            case 7:
                cout << "Data berhasil diurutkan berdasarkan Author(Z-A)!" << endl;
                bubbleSort(novel, jumlahNovel);
                system("pause");
                break;   
            case 8:
                system("cls");
                cout << "================================\n";
                cout << "|         TERIMA KASIH!        |\n";
                cout << "|        Program selesai       |\n";
                cout << "================================\n" << endl;
                break;
            default:
                cout << "Menu tidak tersedia\n";
                system("pause");
        }
    } while (pilih != 8);
}

int main(){
    login user = {"Arya","066"};
    cout<<"====================================\n";
    cout<<"|   SISTEM INFORMASI LIGHT NOVEL   |\n";
    cout<<"|      PROGRAM CRUD SEDERHANA      |\n";
    cout<<"====================================\n"<<endl;
    Pesan("Arya");
    if(loginProgram(user)){
        menuCRUD(novel,jumlahNovel);
    }
    return 0;
}