#include<iostream>
using namespace std;

struct serviceLaptop{
    string MerekLaptop, KodeLaptop, keluhan, status;
    int biaya;
};

struct RegisterUser{
    string nama, nohp, password;
    serviceLaptop service[100];
    int JumlahService = 0;
};

RegisterUser user[100];
int JumlahUser = 0;
int role, USER, ADMIN, MenuUser, YangLogin, menuAdmin;
string username, password;

bool LoginAdmin(string namaadmin, string passwordadmin){
    int login = 0;

    cout << "LOGIN ADMIN (MAKSIMAL 3 KALI)" << endl;

    while(login < 3){
        cout << "Username : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        if(username == namaadmin && password == passwordadmin){
            cout << "BERHASIL MASUK" << endl;
            return true;
        }

        cout << "USERNAME ATAU PASSWORD SALAH" << endl;
        login++;
    }

    return false;
}

void DaftarUser(){
    cout << endl << "SILAHKAN DAFTAR" << endl;

    cin.ignore();
    cout << "Nama : ";
    getline(cin, user[JumlahUser].nama);

    cout << "NoHp : ";
    cin >> user[JumlahUser].nohp;

    cout << "Password : ";
    cin >> user[JumlahUser].password;

    JumlahUser++;
}

void tambahBiaya(int userIndex, int serviceIndex){
    cout << "Masukkan Biaya : ";
    cin >> user[userIndex].service[serviceIndex].biaya;
}

void tambahBiaya(int userIndex, int serviceIndex, int tambahan){
    int biaya;
    cout << "Masukkan Biaya : ";
    cin >> biaya;

    user[userIndex].service[serviceIndex].biaya = biaya + tambahan;
}

void tampilServiceRekursif(int userIndex, int i){

    if(i >= user[userIndex].JumlahService){
        return;
    }
    cout << endl;
    cout << "Service ke-" << i+1 << endl;
    cout << "Merek Laptop : " << user[userIndex].service[i].MerekLaptop << endl;
    cout << "Kode Laptop  : " << user[userIndex].service[i].KodeLaptop << endl;
    cout << "Keluhan      : " << user[userIndex].service[i].keluhan << endl;
    cout << "Status       : " << user[userIndex].service[i].status << endl;
    cout << "Biaya        : Rp " << user[userIndex].service[i].biaya << endl;

    tampilServiceRekursif(userIndex, i+1);
}

void EditNamaUser(RegisterUser *u){
    cin.ignore();
    cout << "Nama Baru BOSS : ";
    getline(cin, (*u).nama);
}

void tambahServicePointer(RegisterUser *u){
    cin.ignore();

    cout << "Merek Laptop : ";
    getline(cin, u->service[u->JumlahService].MerekLaptop);

    cout << "Kode Laptop  : ";
    getline(cin, u->service[u->JumlahService].KodeLaptop);

    cout << "Keluhan      : ";
    getline(cin, u->service[u->JumlahService].keluhan);

    u->service[u->JumlahService].status = "MENUNGGU";
    u->service[u->JumlahService].biaya = 0;

    u->JumlahService++;
}

// soal untuk descending pengurutan huruf
void sortingNamaDescending(){
    for(int i = 0; i < JumlahUser - 1; i++){
        for(int j = 0; j < JumlahUser - i - 1; j++){
            if(user[j].nama < user[j+1].nama){
                swap(user[j], user[j+1]);
            }
        }
    }
}

// soal ascending pengurutan angka
void sortingBiayaAscending(int userIndex){
    for(int i = 0; i < user[userIndex].JumlahService - 1; i++){
        for(int j = 0; j < user[userIndex].JumlahService - i - 1; j++){
            if(user[userIndex].service[j].biaya > user[userIndex].service[j+1].biaya){
                swap(user[userIndex].service[j], user[userIndex].service[j+1]);
            }
        }
    }
}

int main(){

    do{
        cout << "|================|" << endl;
        cout << "| SERVICE LAPTOP |" << endl;
        cout << "|================|" << endl;

        cout << "1. USER" << endl;
        cout << "2. ADMIN" << endl;
        cout << "3. KELUAR" << endl;
        cout << "PILIH (1/2/3) : ";
        cin >> role;

        switch(role){

        case 1:{
            do{
                cout << endl;
                cout << "|=====USER=====|" << endl;
                cout << "|  1. DAFTAR   |" << endl;
                cout << "|  2. LOGIN    |" << endl;
                cout << "|  3. KELUAR   |" << endl;
                cout << "|==============|" << endl;
                cout << "PILIH (1/2/3) : ";
                cin >> USER;

                switch(USER){

                case 1:
                    DaftarUser();
                    break;

                case 2:{
                    if(JumlahUser == 0){
                        cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                        break;
                    }
                    string namaLogin, passwordLogin;
                    bool sesuai = false;
                    int LOGIN = 0;
                    bool USER = false;

                    while(LOGIN < 3){

                        cin.ignore();
                        cout << "Nama : ";
                        getline(cin, namaLogin);

                        cout << "Password : ";
                        cin >> passwordLogin;

                        for(int i=0;i<JumlahUser;i++){
                            if(namaLogin == user[i].nama && passwordLogin == user[i].password){
                                YangLogin = i;
                                sesuai = true;
                                break;
                            }
                        }

                        if(sesuai){
                            break;
                        }
                        else{
                            LOGIN++;
                            cout << "NAMA ATAU PASSWORD SALAH" << endl;
                        }
                    }

                    if(sesuai){
                        cout << "======LOGIN BERHASIL=======" << endl;

                        do{
                            cout << "|========MENU USER========|" << endl;
                            cout << "|1. SERVICE LAPTOP        |" << endl;
                            cout << "|2. RIWAYAT SERVICE LAPTOP|" << endl;
                            cout << "|3. EDIT BIODATA          |" << endl;
                            cout << "|4. BATALKAN SERVICE      |" << endl;
                            cout << "|5. KELUAR                |" << endl;
                            cout << "|=========================|" << endl;
                            cout << "PILIH MENU (1/2/3/4/5) : ";
                            cin >> MenuUser;

                            switch(MenuUser){

                            case 1:{
                                tambahServicePointer(&user[YangLogin]);

                                cout << "SERVICE BERHASIL DITAMBAHKAN\n";
                                break;
                            }

                            case 2:{
                                cout << "====BIODATA USER====" << endl;
                                cout << "Nama : " << user[YangLogin].nama << endl;
                                cout << "NoHp : " << user[YangLogin].nohp << endl;

                                if(user[YangLogin].JumlahService == 0){
                                    cout << "BELUM ADA SERVICE" << endl;
                                }else{
                                    tampilServiceRekursif(YangLogin,0);
                                }
                                break;
                            }

                            case 3:{
                                int editBiodata;
                                cout << "|====EDIT BIODATA====|" << endl;
                                cout << "| 1. Ganti Nama      |" << endl;
                                cout << "| 2. Ganti NoHp      |" << endl;
                                cout << "| 3. Ganti Password  |" << endl;
                                cout << "|====================|" << endl;
                                cout << "Pilih : ";
                                cin >> editBiodata;

                                cin.ignore();
                                if(editBiodata == 1){
                                    EditNamaUser(&user[YangLogin]);
                                }
                                else if(editBiodata == 2){
                                    cout << "NoHp Baru : ";
                                    cin >> user[YangLogin].nohp;
                                }
                                else if(editBiodata == 3){
                                    cout << "Password Baru : ";
                                    cin >> user[YangLogin].password;
                                }
                                else{
                                    cout << "Menu tidak ada" << endl;
                                }
                                break;

                            }

                            case 4:{
                                int hapus;

                                if(user[YangLogin].JumlahService == 0){
                                    cout << "BELUM ADA SERVICE" <<  endl;
                                }else{
                                    cout << "=====DATA SERVICE=====" << endl;

                                    for(int i = 0; i < user[YangLogin].JumlahService;i++){
                                        cout << i + 1 << ". " << user[YangLogin].service[i].MerekLaptop << " - " << user[YangLogin].service[i].keluhan << endl;
                                    }

                                    cout << "SERVICE MANA YANG INGIN DIHAPUS : ";
                                    cin >> hapus;
                                    hapus--;

                                    if(hapus >=0 && hapus < user[YangLogin].JumlahService){

                                        for(int i=hapus;i<user[YangLogin].JumlahService-1;i++){
                                            user[YangLogin].service[i] =
                                            user[YangLogin].service[i+1];
                                        }

                                        user[YangLogin].JumlahService--;
                                        cout << "SERVICE BERHASIL DIBATALKAN" << endl;
                                    }
                                    else{
                                        cout << "PILIHAN TIDAK VALID" << endl;
                                    }
                                }
                                break;
                            }

                            }

                        }while(MenuUser != 5);
                    }
                    else{
                        cout << "GAGAL LOGIN 3 KALI" << endl;
                    }

                    break;
                }

                }

            }while(USER != 3);
            break;
        }

        case 2:{
            if(LoginAdmin("admin","123")){

                do{
                    cout << "|===========MENU ADMIN=========|" << endl;
                    cout << "|1. Lihat Semua Service        |" << endl;
                    cout << "|2. Ubah Status Service        |" << endl;
                    cout << "|3. Tambah Biaya Service       |" << endl;
                    cout << "|4. Urutan Nama User (Z-A)     |" << endl;
                    cout << "|5. Biaya Service dari Terendah|" << endl;
                    cout << "|6. Keluar                     |" << endl;
                    cout << "|==============================|" << endl;
                    cout << "admin pilih yang mana : "; 
                    cin >> menuAdmin;

                    switch(menuAdmin){
                        case 1:{
                            cout << endl << "====DATA SERVICE USER====" << endl;

                            if(JumlahUser == 0){
                                cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                                break;
                            }
                            bool adaservice = false;
                            for(int i = 0; i < JumlahUser; i++){
                                if(user[i].JumlahService > 0){
                                    adaservice = true;
                                    break;
                                }
                            }

                            if(!adaservice){
                                cout << "BELUM ADA SERVICE YANG MASUK" <<  endl;
                                break;
                            }

                            for(int i = 0; i < JumlahUser; i++){
                                for(int j = 0; j < user[i].JumlahService; j++){
                                    cout << endl;
                                    cout << "User : " << user[i].nama << endl;
                                    cout << "NoHp : " << user[i].nohp << endl;
                                    cout << "Service ke-" << j+1 << endl;
                                    cout << "Merek Laptop : " << user[i].service[j].MerekLaptop << endl;
                                    cout << "Kode Laptop  : " << user[i].service[j].KodeLaptop << endl;
                                    cout << "Keluhan      : " << user[i].service[j].keluhan << endl;
                                    cout << "Status       : " << user[i].service[j].status << endl;
                                    cout << "Biaya        : Rp " << user[i].service[j].biaya << endl;
                                }
                            }
                            break; 
                        }

                        case 2:{
                            if(JumlahUser == 0){
                                cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                                break;
                            }
                            bool adaservice = false;

                            for(int i = 0; i < JumlahUser; i++){
                                if(user[i].JumlahService > 0){
                                    adaservice = true;
                                    break;
                                }
                            }
                            if(!adaservice){
                                cout << "BELUM ADA SERVICE" <<  endl;
                                break;
                            } 
                            cout << "=== DAFTAR USER ===" << endl;
                            for(int i = 0; i < JumlahUser; i++){
                                cout << i+1 << ". " << user[i].nama << endl;
                            }
                            int pilihUser, pilihService;
                            cout << "Pilih User : ";
                            cin >> pilihUser;
                            cout << "Pilih Service ke- : ";
                            cin >> pilihService;
                            cin.ignore();
                            cout << "Status Baru : ";
                            getline(cin, user[pilihUser-1].service[pilihService-1].status);

                            cout << "Status berhasil diubah" << endl;
                            break;
                        }

                        case 3:{
                            if(JumlahUser == 0){
                                cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                                break;
                            }
                            bool adaservice = false;

                            for(int i = 0; i < JumlahUser; i++){
                                if(user[i].JumlahService > 0){
                                    adaservice = true;
                                    break;
                                }
                            }
                            if(!adaservice){
                                cout << "BELUM ADA SERVICE" <<  endl;
                                break;
                            } 
                            cout << "=== DAFTAR USER ===" << endl;
                            for(int i = 0; i < JumlahUser; i++){
                                cout << i+1 << ". " << user[i].nama << endl;
                            }
                            int pilihUser, pilihService;
                            cout << "Pilih User : ";
                            cin >> pilihUser;
                            cout << "Pilih Service ke- : ";
                            cin >> pilihService;
                            tambahBiaya(pilihUser-1, pilihService-1, 10000);
                            cout << "Biaya yang tercantum termasuk harga sparepart dan jasa sebesar Rp 10.000" << endl;
                            cout << "Biaya berhasil ditambahkan" << endl;
                            break;
                        }

                        case 4:{
                            if(JumlahUser == 0){
                                cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                                break;
                            }
                            bool adaservice = false;

                            sortingNamaDescending();
                            cout << "Nama user berhasil diurutkan (Z-A)" << endl;

                            cout << "=== HASIL SORTING USER ===" << endl;
                            for(int i = 0; i < JumlahUser; i++){
                                cout << i+1 << ". " << user[i].nama << endl;
                            }

                            break;
                        }

                        case 5:{
                            if(JumlahUser == 0){
                                cout << "BELUM ADA USER YANG TERDAFTAR" << endl;
                                break;
                            }
                            bool adaservice = false;

                            int pilihUser;
                            cout << "Pilih User : ";
                            cin >> pilihUser;

                            sortingBiayaAscending(pilihUser-1);
                            cout << "Biaya service berhasil diurutkan (kecil ke besar)" << endl;

                            cout << "=== HASIL SORTING BIAYA ===" << endl;
                            for(int i = 0; i < user[pilihUser-1].JumlahService; i++){
                                cout << i+1 << ". "
                                    << user[pilihUser-1].service[i].MerekLaptop
                                    << " - Rp " 
                                    << user[pilihUser-1].service[i].biaya << endl;
                            }
                            break;
                        }

                        case 6:{
                            cout << "Admin keluar dulu." << endl;
                            break;
                        }default:{
                            cout << "GAK ADA PILIHAN" << endl;
                        }
                    }
                }while(menuAdmin != 6);

            }
            else{
                cout << "GAGAL LOGIN ADMIN 3 KALI" << endl;
            }
            break;
        }

        case 3:{
            cout << "KELUAR" << endl;
            break;
        }

        }

    }while(role != 3);

    return 0;
}