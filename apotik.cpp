#include <iostream>
#include <iomanip>

using namespace std;

// VARIABEL GLOBAL
int i, nm, space;
char q;

struct Obat {
    int indeks;
    char nama[20];
    char harga[20];
    char penyakit[20];
    char khusus[20];
    char kadaluwarsa[20];
};
Obat *obat = new Obat[space];

// DEKLARASI FUNCTION
void clear();
bool kosong();
void buat();
void daftar();

int main(){
    obat->indeks = -1;
    space = obat->indeks + 1;
    do {
        //clear();
        cout << "[MAIN MENU]" << endl;
        cout << "1. BUAT \t 2. DAFTAR \t 3. CARI" << endl;
        cout << "MASUKKAN NOMOR MENU : "; cin >> nm;
        switch(nm){
            case 1 : 
                clear(); buat();
            break;
            case 2 :
                clear(); daftar();
            break;
            case 3 :
            break;
            default :
            break;
        }
    } while(nm != 7);
}

void clear(void){
    system("clear || cls");
    return;
}
bool kosong(){
    if(space == -1){
        return true;
    } else {
        return false;
    }
}

void buat(){
    cout << "[MAIN MENU/BUAT]" << endl;
    do {
        obat->indeks++;
        cout << "MASUKKAN NAMA OBAT : "; cin.ignore(); cin.getline(obat[obat->indeks].nama, sizeof(obat->nama));
        cout << "MASUKKAN HARGA OBAT : "; cin.getline(obat[obat->indeks].harga, sizeof(obat->harga));
        cout << "MASUKKAN PENYAKIT OBAT : "; cin.getline(obat[obat->indeks].penyakit, sizeof(obat->penyakit));
        cout << "DEWASA ATAU ANAK : "; cin.getline(obat[obat->indeks].khusus, sizeof(obat->khusus));
        cout << "MASUKKAN KADALUWARSA : "; cin.getline(obat[obat->indeks].kadaluwarsa, sizeof(obat->kadaluwarsa));
        cout << endl;

        cout << "BUAT DATA LAGI? [y/n] : "; cin >> q;
        cout << endl;
    } while(q != 'n');
}

void daftar(){
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            cout << "=================================================================================" << endl;
            cout << "| NAMA \t\t| HARGA \t| PENYAKIT | KHUSUS \t| KADALUWARSA \t|" << endl;
            cout << "=================================================================================" << endl;
            for(i = 0; i <= obat->indeks; i++){
                cout << obat[i].nama << endl;
                cout << obat[i].harga << endl;
                cout << obat[i].penyakit << endl;
                cout << obat[i].khusus << endl;
                cout << obat[i].kadaluwarsa << endl;
            }
            cout << "KEMBALI KE MAIN MENU? [y/n] : "; cin >> q;
            cout << endl;
        } while(q != 'y');
    }
}