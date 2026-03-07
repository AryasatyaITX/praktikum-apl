#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_LIGHTNOVEL 100

struct login{
    string username;
    string password;
};

struct detail{
    string genre;
    int volume;
    string status;
};

struct Lightnovel{
    int id;
    string judul;
    string author;
    detail detailNovel;
};

Lightnovel novel[MAX_LIGHTNOVEL] = {
    {1,"Sword Art Online","Reki Kawahara",{"Fantasy",27,"Ongoing"}},
    {2,"Overlord","Kugane Maruyama",{"Isekai",16,"Ongoing"}},
    {3,"Classroom of the Elite","Syougo Kinugasa",{"School",14,"Ongoing"}}
};

int jumlahNovel = 3;

int main(){
    login user = {"Arya","066"}; 
    string username,password;
    int kesempatan = 0;
    int pilih;
    cout<<"========================================\n";
    cout<<"|     SISTEM INFORMASI LIGHT NOVEL     |\n";
    cout<<"|        PROGRAM CRUD SEDERHANA        |\n";
    cout<<"========================================\n"<<endl;

    while(kesempatan < 3){
        cout<<"Masukkan username : ";
        cin>>username;
        cout<<"Masukkan password : ";
        cin>>password;
        if(username == user.username && password == user.password){
            cout<<"\n=====================================\n";
            cout<<"|           Login Berhasil!         |\n";
            cout<<"|     Selamat datang "<<username<<"           |\n";
            cout<<"=====================================\n"<<endl;
            break;
        }
        else{
            kesempatan++;
            cout<<"\nLogin gagal! Percobaan ke "<<kesempatan<<" dari 3\n"<<endl;
            if(kesempatan == 3){
                cout<<"=====================================\n";
                cout<<"| Kesempatan login anda sudah habis |\n";
                cout<<"=====================================\n";
                cout<<"Program dihentikan.\n";
                return 0;
            }
        }
    }

    do{
        cout<<"========================================\n";
        cout<<"|   MENU CRUD INFORMASI LIGHT NOVEL    |\n";
        cout<<"========================================\n";
        cout<<"|1. Lihat Light Novel                  |\n";
        cout<<"|2. Tambah Light Novel                 |\n";
        cout<<"|3. Perbarui Light Novel               |\n";
        cout<<"|4. Hapus Light Novel                  |\n";
        cout<<"|5. Keluar                             |\n";
        cout<<"========================================\n";
        cout<<"Pilih menu : ";
        cin>>pilih;
        switch(pilih){
        case 1:
            system("cls");
            if(jumlahNovel == 0){
                cout<<"Belum ada data Light Novel.\n"<<endl;
            }
            else{
                cout<<"================================================================================================\n";
                cout<<"|";
                cout<<setw(4)<<"ID"<<" | ";
                cout<<setw(25)<<"Judul"<<" | ";
                cout<<setw(20)<<"Author"<<" | ";
                cout<<setw(12)<<"Genre"<<" | ";
                cout<<setw(6)<<"Vol"<<" | ";
                cout<<setw(12)<<"Status"<<" |\n";
                cout<<"================================================================================================\n";

                for(int i=0;i<jumlahNovel;i++){
                    cout<<"|";
                    cout <<setw(4)<<novel[i].id<<" | ";
                    cout <<setw(25)<<novel[i].judul<<" | ";
                    cout <<setw(20)<<novel[i].author<<" | ";
                    cout <<setw(12)<<novel[i].detailNovel.genre<<" | ";
                    cout <<setw(6)<<novel[i].detailNovel.volume<<" | ";
                    cout <<setw(12)<<novel[i].detailNovel.status<<" |\n";
                }
                cout<<"================================================================================================\n\n";
            }
            break;

        case 2:
            system("cls");
            if(jumlahNovel >= MAX_LIGHTNOVEL){
                cout<<"Daftar Light Novel sudah penuh.\n"<<endl;
            }
            else{
                Lightnovel Novelbaru;
                Novelbaru.id = jumlahNovel + 1;
                cin.ignore(1000,'\n');
                cout<<"\nMasukkan Judul Light Novel : ";
                getline(cin,Novelbaru.judul);
                cout<<"Masukkan Author : ";
                getline(cin,Novelbaru.author);
                cout<<"Masukkan Genre : ";
                getline(cin,Novelbaru.detailNovel.genre);
                cout<<"Masukkan Volume : ";
                cin>>Novelbaru.detailNovel.volume;
                cin.ignore(1000,'\n');
                cout<<"Masukkan Status (Ongoing/Completed) : ";
                getline(cin,Novelbaru.detailNovel.status);
                novel[jumlahNovel] = Novelbaru;
                jumlahNovel++;
                cout<<"\nData berhasil ditambahkan.\n"<<endl;
            }
            break;

        case 3:
            system("cls");
            if(jumlahNovel == 0){
                cout<<"\nBelum ada data Light Novel untuk diupdate.\n"<<endl;
            }
            else{
                int id;
                cout<<"Daftar Light Novel:\n";
                cout<<"================================================================================================\n";
                cout<<"|";
                cout<<setw(4)<<"ID"<<" | ";
                cout<<setw(25)<<"Judul"<<" | ";
                cout<<setw(20)<<"Author"<<" | ";
                cout<<setw(12)<<"Genre"<<" | ";
                cout<<setw(6)<<"Vol"<<" | ";
                cout<<setw(12)<<"Status"<<" |\n";
                cout<<"================================================================================================\n";

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
                    int field;
                    cout<<"\nField yang ingin diupdate\n";
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
                        getline(cin,novel[index].judul);
                        cout<<"Data berhasil diupdate.\n"<<endl;
                    }
                    else if(field == 2){
                        cout<<"Masukkan Author Baru : ";
                        getline(cin,novel[index].author);
                        cout<<"Data berhasil diupdate.\n"<<endl;
                    }
                    else if(field == 3){
                        cout<<"Masukkan Genre Baru : ";
                        getline(cin,novel[index].detailNovel.genre);
                        cout<<"Data berhasil diupdate.\n"<<endl;
                    }
                    else if(field == 4){
                        cout<<"Masukkan Volume Baru : ";
                        cin>>novel[index].detailNovel.volume;
                        cout<<"Data berhasil diupdate.\n"<<endl;                        
                    }
                    else if(field == 5){
                        cout<<"Masukkan Status Baru : ";
                        getline(cin,novel[index].detailNovel.status);
                        cout<<"Data berhasil diupdate.\n"<<endl;
                    }
                    else{
                        cout<<"Pilihan field tidak tersedia. Update dibatalkan.\n";
                    }
                }
            }
            break;

        case 4:
            system("cls");
            if(jumlahNovel == 0){
                cout<<"\nBelum ada data Light Novel untuk dihapus.\n"<<endl;
            }
            else{
                cout<<"Daftar Light Novel:\n";
                cout<<"================================================================================================\n";
                cout<<"|";
                cout<<setw(4)<<"ID"<<" | ";
                cout<<setw(25)<<"Judul"<<" | ";
                cout<<setw(20)<<"Author"<<" | ";
                cout<<setw(12)<<"Genre"<<" | ";
                cout<<setw(6)<<"Vol"<<" | ";
                cout<<setw(12)<<"Status"<<" |\n";
                cout<<"================================================================================================\n";

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

                int id;
                cout<<"Masukkan ID yang ingin dihapus : ";
                cin>>id;
                int index = id - 1;
                if(index < 0 || index >= jumlahNovel){
                    cout<<"ID tidak ditemukan.\n"<<endl;
                }
                else{
                    int alasan;
                    cout<<"\nAlasan penghapusan:\n";
                    cout<<"1. Seri tidak dilanjutkan (Axed)\n";
                    cout<<"2. Author sedang ada masalah\n";
                    cout<<"Pilih alasan : ";
                    cin>>alasan;

                    for(int i=index;i<jumlahNovel-1;i++){
                        novel[i] = novel[i+1];
                        novel[i].id = i+1;
                    }
                    jumlahNovel--;
                    cout<<"\nData berhasil dihapus.\n\n"<<endl;
                }
            }
            break;
        case 5:
            system("cls");
            cout<<"================================\n";
            cout<<"|         TERIMA KASIH!        |\n";
            cout<<"|     Program selesai          |\n";
            cout<<"================================\n"<<endl;
            break;
        default:
            cout<<"Pilihan Menu tidak tersedia.\n"<<endl;
        }
    }while(pilih != 5);
    return 0;
}