#include<iostream>
using namespace std;

int main(){
    int login = 0;
    string nama, password;
    int pilih;
    double jam, menit, detik;

    cout << "===============================" << endl;
    cout << "|    SISTEM KONVERSI WAKTU    |" << endl;
    cout << "===============================" << endl;
    cout << "LOGIN" ;
    while (login < 3){
        cout << "\nMasukkan Nama Anda     : "; 
        cin >> nama;
        cout << "Masukkan Password Anda : ";
        cin >> password;
        if (nama == "Attar" && password == "046"){
            while(true){
                cout << endl;
                cout << "===============================" << endl;
                cout << "|        MENU KONVERSI        |" << endl ;
                cout << "|  1. JAM KE MENIT DAN DETIK  |" << endl ;
                cout << "|  2. MENIT KE JAM DAN DETIK  |" << endl ;
                cout << "|  3. DETIK KE JAM DAN MENIT  |" << endl ; 
                cout << "|  4. KELUAR                  |" << endl ;
                cout << "===============================" ;
                cout << "\nMASUKKAN PILIHAN ANDA (1/2/3/4) : ";
                cin >> pilih;
                if (pilih == 1){
                    cout << "\nJAM KE MENIT DAN DETIK" << endl;
                    cout << "MASUKKAN JAM : ";
                    cin >> jam;
                    menit = jam * 60;
                    detik = jam * 3600;
                    cout << jam << " JAM = " << menit << " MENIT DAN " << detik << " DETIK" << endl;
                }

                else if (pilih == 2){
                    cout << "\nMENIT KE JAM DAN DETIK" << endl;
                    cout << "MASUKKAN MENIT : ";
                    cin >> menit;
                    jam = menit / 60;
                    detik = menit * 60;
                    cout << menit << " MENIT = " << jam << " JAM DAN " << detik << " DETIK" << endl;
                }

                else if (pilih == 3){
                    cout << "\nDETIK KE JAM DAN MENIT" << endl;
                    cout << "MASUKKAN DETIK : ";
                    cin >> detik;
                    jam = detik / 3600;
                    menit = detik / 60;
                    cout << detik << " DETIK = " << jam << " JAM DAN " << menit << " MENIT" << endl;
                }

                else if (pilih == 4){
                    cout << endl;
                    cout << "===============================" << endl;
                    cout << "|         TERIMA KASIH        |" << endl;
                    cout << "===============================" << endl;
                    break;
                }

                else{
                    cout << endl;
                    cout << "===============================" << endl;
                    cout << "|      TIDAK ADA PILIHAN      |" << endl;
                    cout << "===============================" << endl;
                }
            }
            break;
        }

        else{
            login++;
            cout << "===============================" << endl;
            cout << "|   NAMA ATAU PASSWORD SALAH  |" << endl;
            cout << "===============================" << endl;
        }
    }
    if (login == 3){
        cout << "===============================" << endl;
        cout << "|         GAGAL LOGIN         |" << endl;
        cout << "===============================" << endl;
    }
    return 0;
}