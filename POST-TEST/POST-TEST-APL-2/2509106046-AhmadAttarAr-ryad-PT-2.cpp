#include<iostream>
using namespace std;

struct serviceLaptop{
    string MerekLaptop, KodeLaptop, keluhan, status;
    int biaya;
};


struct RegisterUser{
    string nama, nohp, password;
    serviceLaptop service [100];
    int JumlahService = 0;
};

RegisterUser user[100];
int JumlahUser = 0;
int role, USER, ADMIN, MenuUser, YangLogin;
string namaadmin = "admin";
string passwordadmin = "123";
string username, password;
bool loginadmin = false;
int adminmasuk = 0;

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

                        case 1:{
                            cout << endl;
                            cout << "SILAHKAN DAFTAR DAHULU" << endl;

                            cin.ignore();
                            cout << "Nama : ";
                            getline(cin, user[JumlahUser].nama);

                            cout << "NoHp : ";
                            cin >> user[JumlahUser].nohp;

                            cout << "Password : ";
                            cin >> user[JumlahUser].password;

                            JumlahUser++;
                            break;
                        }

                        case 2:{
                            string namaLogin, passwordLogin;
                            bool sesuai = false;
                            int LOGIN = 0;

                            while(LOGIN < 3){

                                cin.ignore();

                                cout << "Nama : ";
                                getline(cin, namaLogin);

                                cout << "Password : ";
                                cin >> passwordLogin;

                                for(int i = 0; i < JumlahUser; i++){
                                    if(namaLogin == user[i].nama && passwordLogin == user[i].password){
                                        YangLogin = i;
                                        sesuai = true;
                                        break;
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
                                        switch (MenuUser){
                                            case 1:{
                                                cin.ignore();
                                                cout << endl << "MEREK LAPTOP : ";
                                                getline(cin, user[YangLogin].service[user[YangLogin].JumlahService].MerekLaptop);
                                                
                                                cout << "KODE LAPTOP  : ";
                                                getline(cin, user[YangLogin].service[user[YangLogin].JumlahService].KodeLaptop);

                                                cout << "KELUHAN      : ";
                                                getline(cin, user[YangLogin].service[user[YangLogin].JumlahService].keluhan);

                                                user[YangLogin].service[user[YangLogin].JumlahService].status = "MENUNGGU";
                                                user[YangLogin].service[user[YangLogin].JumlahService].biaya = 0;
                                                user[YangLogin].JumlahService++;

                                                cout << "SERVICE BERHASIL DITAMBAHKAN\n" << endl;
                                                break;
                                            }

                                            case 2:{
                                                cout << "====BIODATA USER====" << endl;
                                                cout << "Nama : " << user[YangLogin].nama << endl;
                                                cout << "NoHp : " << user[YangLogin].nohp << endl;

                                                if(user[YangLogin].JumlahService == 0){
                                                    cout << "BELUM ADA RIWAYAT SERVICE" << endl;
                                                }else{
                                                    cout << "=====RIWAYAT SERVICE=====" << endl;
                                                    for(int i = 0; i < user[YangLogin].JumlahService; i++){
                                                        cout << "Service ke-" << i+1 << endl;
                                                        cout << "Merek Laptop : " << user[YangLogin].service[i].MerekLaptop << endl;
                                                        cout << "Kode Laptop  : " << user[YangLogin].service[i].KodeLaptop << endl;
                                                        cout << "Keluhan      : " << user[YangLogin].service[i].keluhan << endl;
                                                        cout << "Status       : " << user[YangLogin].service[i].status << endl;
                                                        cout << "Biaya        : Rp " << user[YangLogin].service[i].biaya << endl;
                                                    }
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

                                                switch(editBiodata){

                                                    case 1:{
                                                        cout << "Nama Baru : ";
                                                        getline(cin, user[YangLogin].nama);
                                                        cout << "Nama berhasil diubah" << endl;
                                                        break;
                                                    }

                                                    case 2:{
                                                        cout << "NoHp Baru : ";
                                                        cin >> user[YangLogin].nohp;
                                                        cout << "NoHp berhasil diubah" << endl;
                                                        break;
                                                    }

                                                    case 3:{
                                                        cout << "Password Baru : ";
                                                        cin >> user[YangLogin].password;
                                                        cout << "Password berhasil diubah" << endl;
                                                        break;
                                                    }

                                                    default:{
                                                        cout << "Menu tidak ada" << endl;
                                                    }
                                                }
                                                break;
                                            }

                                            case 4:{
                                                int hapus;
                                                if(user[YangLogin].JumlahService == 0){
                                                    cout << "BELUM ADA SERVICE" <<  endl;
                                                }else{
                                                    cout << "=====DATA SERVICE=====" << endl;

                                                    for(int i = 0; i < user[YangLogin].JumlahService; i++){
                                                        cout << i+1 << ". " << user[YangLogin].service[i].MerekLaptop << " - " << user[YangLogin].service[i].keluhan << endl;
                                                    }   
                                                    cout << "SERVICE MANA YANG INGIN DIHAPUS : ";
                                                    cin >> hapus;
                                                    hapus--;

                                                    if(hapus >= 0 && hapus < user[YangLogin].JumlahService){
                                                        for(int i = hapus; i < user[YangLogin].JumlahService - 1; i++){
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
                                    break;
                                }
                                else{
                                    LOGIN++;
                                    cout << "NAMA ATAU PASSWORD SALAH" << endl;
                                }
                            }

                            if(!sesuai){
                                cout << "GAGAL LOGIN 3 KALI" << endl;
                            }

                            break;
                        }

                    }

                }while(USER != 3);

                break;
            }

            case 2:{
                while(adminmasuk < 3){
                    cout << "=== LOGIN ADMIN ===" << endl;
                    cout << "Username : ";
                    cin >> username;
                    cout << "Password : ";
                    cin >> password;

                    if(username == namaadmin && password == passwordadmin){
                        loginadmin = true;
                        break;
                    }
                    else{
                        cout << "USERNAME ATAU PASSWORD SALAH\n";
                        adminmasuk++;
                    }
                }
                if(loginadmin){
                int menuAdmin;
                do{
                    cout << endl;
                    cout << "|=======MENU ADMIN======|" << endl;
                    cout << "|1. Lihat Semua Service |" << endl;
                    cout << "|2. Ubah Status Service |" << endl;
                    cout << "|3. Tambah Biaya Service|" << endl;
                    cout << "|4. Keluar              |" << endl;
                    cout << "|=======================|" << endl;
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
                            cout << "Masukkan Biaya : ";
                            cin >> user[pilihUser-1].service[pilihService-1].biaya;
                            cout << "Biaya berhasil ditambahkan" << endl;
                            break;
                        }
                        case 4:{
                            cout << "Admin keluar dulu." << endl;
                            break;
                        }default:{
                            cout << "GAK ADA PILIHAN" << endl;
                        }
                    }
                }while(menuAdmin != 4);
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