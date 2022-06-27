#include <iostream>
#include <sstream> // ws
#include <iomanip>

using namespace std;

// Deklarasi variabel global
int nm; // nomor menu
char q; // QnA
int i;
int indeks = 10;
bool lock;

struct Produk {
    int id;
    char nama[20];
    char harga[20];
    char penyakit[20];
    char expired[20];
};

Produk *produk = new Produk[indeks];

// ========== DEKLARASI FUNCTION ==========
bool login();
bool empty();
void clear();
void create();
void alloc();
void read();
void search();
void deletep();
void deleteall();
// ========== END ==========

class Before {
    public :
        Before(){
            produk->id = -1;
        }
};

Before obj;

int main(){
    do {
        clear();
        cout << "[MAIN MENU]" << endl;
        cout << "1. CREATE \t 2. READ \t 3. UPDATE \t 4. DELETE \t 5. DELETE ALL \t 6. SEARCH" << endl;
        cout << "MASUKKAN NOMOR PILIHAN : "; cin >> nm;
        switch(nm){
            case 1 : 
                clear();
                do {
                    create();
                    cout << "BUAT DATA LAGI? [Y/N] "; cin >> q;
                } while(q != 'n');
            break;
            case 2 :
                clear(); read();
            break;
            case 3 :
                clear();
            break;
            case 4 :
                clear(); deletep();
            break;
            case 5 :
                clear(); deleteall();
            break;
            case 6 :
                clear(); search();
            break;
            case 7 :
                if(login() == true){
                    cout << "MEMATIKAN SISTEM..." << endl;
                } else {
                    cout << "PASSWORD SALAH!" << endl;
                    main();
                }
            break;
            default :
                cout << "NOMOR PILIHAN TIDAK TERSEDIA!" << endl;
            break;
        }
    } while(nm != 7);

    delete[] produk;
    // End
}

void clear(void){
    system("clear || cls");
    return;
}

bool login(){
    string pw = "admin";
    string t_pass;
    cout << "MASUKKAN PASSWORD : "; cin >> t_pass;
    if(t_pass == pw){
        return true;
    } else {
        return false;
    }
}

bool empty(){
    if(produk->id == -1){
        return true;
    } else {
        return false;
    }
}

bool full(){
    if(produk->id == 10){
        return true;
    } else {
        return false;
    }
}

void create(){
    cout << "[MAIN MENU/CREATE]" << endl;
    produk->id++;
    cout << "MASUKKAN NAMA PRODUK : "; cin.ignore(); cin.getline(produk[produk->id].nama, sizeof(produk->nama));
    cout << "MASUKKAN HARGA PRODUK : "; cin.getline(produk[produk->id].harga, sizeof(produk->harga));
    cout << "MASUKKAN JENIS PENYAKIT PRODUK : "; cin.getline(produk[produk->id].penyakit, sizeof(produk->penyakit));
    cout << "MASUKKAN EXPIRED PRODUK : "; cin.getline(produk[produk->id].expired, sizeof(produk->expired));
}

void read(){
    cout << "[MAIN MENU/READ]" << endl;
    do {
        if(empty() == true){
            cout << "DATA KOSONG!" << endl;
        } else {
            cout << "=================================================================" << endl;
            cout << "|NAMA \t\t|HARGA \t\t|PENYAKIT \t|EXPIRED \t|" << endl;
            cout << "=================================================================" << endl;
            for(i = 0; i <= produk->id; i++){
                cout << "|" << produk[i].nama << "\t\t|" << produk[i].harga << "\t\t|" << produk[i].penyakit << "\t\t|" << produk[i].expired << "\t|" <<endl;
                cout << "=================================================================" << endl;
            }
        }
        cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
    } while(q != 'y');
}

void search(){
    do {
        string cari;
        cout << "[MAIN MENU/SEARCH]" << endl;
        if(empty() == true){
            cout << "DATA KOSONG!" << endl;
        } else {
            cout << "MASUKKAN NAMA PRODUK : "; cin >> cari;
            for(i = 0; i <= produk->id; i++){
                if(produk[i].nama == cari){
                    lock = true;
                    break;
                } else {
                    lock = false;
                }
            }
            if(lock == true){
                cout << "=================================================================" << endl;
                cout << "|NAMA \t\t|HARGA \t\t|PENYAKIT \t|EXPIRED \t|" << endl;
                cout << "=================================================================" << endl;
                cout << "|" << produk[i].nama << "\t\t|" << produk[i].harga << "\t\t|" << produk[i].penyakit << "\t\t|" << produk[i].expired << "\t|" <<endl;
                cout << "=================================================================" << endl;  
             } else {
                cout << "DATA TIDAK DITEMUKAN!" << endl;
            }
        }
        cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
    } while(q != 'y');
}

void deletep(){
    do {
        if(empty() == true){
            cout << "DATA KOSONG!" << endl;
        } else {
            produk->id--;
            cout << "DATA TERAKHIR BERHASIL DIHAPUS!" << endl;
        }
        cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
    } while(q != 'n');
}

void deleteall(){
    do {
        if(empty() == true){
            cout << "DATA KOSONG!" << endl;
        } else {
            produk->id = -1;
            cout << "SEMUA DATA BERHASIL DIHAPUS!" << endl;
        }
        cout << "KEMBALI KE MAIN MENU? [y/n] "; cin >> q;
    } while(q != 'n');
}
//
