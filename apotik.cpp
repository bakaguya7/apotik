#include <iostream>
#include <iomanip>

using namespace std;

// VARIABEL GLOBAL
int i, j, nm, space;
char q;

struct Obat {
    int indeks;
    char nama[20];
    char harga[20];
    char penyakit[20];
    char usia[20];
    char kadaluwarsa[20];
};
Obat *obat = new Obat[10];

// DEKLARASI FUNCTION
void bersih();
bool kosong();
void buat();
void daftar();
void cari();
void sorting();
void edit();
void hapus();
void hapus_semua();

int main(){
    obat->indeks = -1;
    do {
        cout << "=== SISTEM CRUD APOTIK ===" << endl;
        cout << "[MAIN MENU]" << endl;
        cout << "1. BUAT \t 2. DAFTAR \t 3. CARI \t 4. EDIT \t 5. HAPUS \t 6. HAPUS SEMUA \t 7. KELUAR" << endl;
        cout << "MASUKKAN NOMOR MENU : "; cin >> nm;
        switch(nm){
            case 1 : 
                bersih(); buat();
            break;
            case 2 :
                bersih(); daftar();
            break;
            case 3 :
                bersih(); cari();
            break;
            case 4 :
                bersih(); edit();
            break;
            case 5 :
                bersih(); hapus();
            break;
            case 6 :
                bersih(); hapus_semua();
            break;
            case 7 :
            break;
            default :
            break;
        }
    } while(nm != 7);
}

void bersih(void){
    system("clear || cls");
    return;
}

bool penuh(){
    if(obat->indeks == 10){
        return true;
    } else {
        return false;
    }
}

bool kosong(){
    if(obat->indeks == -1){
        return true;
    } else {
        return false;
    }
}

void buat(){
    cout << "[MAIN MENU/BUAT]" << endl;
    if(penuh() == true){
        cout << "DATA PENUH!" << endl;
    } else {
        do {
            obat->indeks++;
            cout << "MASUKKAN NAMA OBAT : "; cin.ignore(); cin.getline(obat[obat->indeks].nama, sizeof(obat->nama));
            cout << "MASUKKAN HARGA OBAT : "; cin.getline(obat[obat->indeks].harga, sizeof(obat->harga));
            cout << "MASUKKAN PENYAKIT OBAT : "; cin.getline(obat[obat->indeks].penyakit, sizeof(obat->penyakit));
            cout << "MASUKKAN USIA PENGGUNA : "; cin.getline(obat[obat->indeks].usia, sizeof(obat->usia));
            cout << "MASUKKAN KADALUWARSA OBAT : "; cin.getline(obat[obat->indeks].kadaluwarsa, sizeof(obat->kadaluwarsa));
            cout << endl;

            cout << "BUAT DATA LAGI? [y/n] : "; cin >> q;
            cout << endl;
        } while(q != 'n');
    }
}

void daftar(){
    cout << "[MAIN MENU/DAFTAR]" << endl;
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            sorting();
            cout << "=================================================================================" << endl;
            cout << "| NAMA \t\t| HARGA \t| PENYAKIT \t| USIA   \t| KADALUWARSA \t|" << endl;
            cout << "=================================================================================" << endl;
            for(i = 0; i <= obat->indeks; i++){
                cout << "| " << obat[i].nama << " \t| " << obat[i].harga << " \t| " << obat[i].penyakit
                << " \t| " << obat[i].usia << " \t| " << obat[i].kadaluwarsa << " \t|" << endl;
                cout << "=================================================================================" << endl;
            }
            cout << endl << "KEMBALI KE MAIN MENU? [y/n] : "; cin >> q;
            cout << endl;
        } while(q != 'y');
    }
}

void cari(){
    string t_nama; bool lock;
    cout << "[MAIN MENU/CARI]" << endl;
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            cout << "MASUKKAN NAMA OBAT YANG ANDA CARI : "; cin.ignore(); cin >> t_nama;
            for(i = 0; i <= obat->indeks; i++){
                if(obat[i].nama == t_nama){
                    lock = true;
                    break;
                } else {
                    lock = false;
                }
            }
            if(lock == true){
                cout << "=================================================================================" << endl;
                cout << "| NAMA \t\t| HARGA \t| PENYAKIT \t| USIA   \t| KADALUWARSA \t|" << endl;
                cout << "=================================================================================" << endl;
                cout << "| " << obat[i].nama << " \t| " << obat[i].harga << " \t| " << obat[i].penyakit
                << " \t| " << obat[i].usia << " \t| " << obat[i].kadaluwarsa << " \t|" << endl;
                cout << "=================================================================================" << endl;
            } else {
                cout << "DATA YANG ANDA CARI TIDAK DITEMUKAN!" << endl;
            }

            cout << endl << "KEMBALI KE MAIN MENU? [y/n] : "; cin >> q;
            cout << endl;
        } while(q != 'y');
    }
}

void sorting(){
    int x = 0;
    if(obat->indeks > 0){
        for(i = 0; i <= obat->indeks; i++){
            for(j = i + 1; j <= obat->indeks; j++){
                if(obat[i].nama[x] > obat[j].nama[x]){
                    swap(obat[i].nama, obat[j].nama);
                    swap(obat[i].harga, obat[j].harga);
                    swap(obat[i].penyakit, obat[j].penyakit);
                    swap(obat[i].usia, obat[j].usia);
                    swap(obat[i].kadaluwarsa, obat[j].kadaluwarsa);
                }
            }
        }
    }
}

void edit(){
    string t_nama; bool lock;
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        do {
            cout << "MASUKKAN NAMA OBAT YANG INGIN DIEDIT : "; cin >> t_nama;
            for(i = 0; i <= obat->indeks; i++){
                if(t_nama == obat[i].nama){
                    lock = true;
                    break;
                } else {
                    lock = false;
                }
            }
            if(lock == true){
                cout << "=================================================================================" << endl;
                cout << "| NAMA \t\t| HARGA \t| PENYAKIT \t| USIA   \t| KADALUWARSA \t|" << endl;
                cout << "=================================================================================" << endl;
                cout << "| " << obat[i].nama << " \t| " << obat[i].harga << " \t| " << obat[i].penyakit
                << " \t| " << obat[i].usia << " \t| " << obat[i].kadaluwarsa << " \t|" << endl;
                cout << "=================================================================================" << endl;

                cout << "MULAI MENGEDIT DATA" << endl;

                cout << "MASUKKAN NAMA OBAT : "; cin.ignore(); cin.getline(obat[i].nama, sizeof(obat->nama));
                cout << "MASUKKAN HARGA OBAT : "; cin.getline(obat[i].harga, sizeof(obat->harga));
                cout << "MASUKKAN PENYAKIT OBAT : "; cin.getline(obat[i].penyakit, sizeof(obat->penyakit));
                cout << "MASUKKAN USIA PENGGUNA : "; cin.getline(obat[i].usia, sizeof(obat->usia));
                cout << "MASUKKAN KADALUWARSA OBAT : "; cin.getline(obat[i].kadaluwarsa, sizeof(obat->kadaluwarsa));
                cout << endl;
            } else {
                cout << "DATA YANG ANDA CARI TIDAK DITEMUKAN!" << endl;
            }
            cout << endl << "KEMBALI KE MAIN MENU? [y/n] : "; cin >> q;
        } while(q != 'y');
    }
}

void hapus(){
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        obat->indeks--;
        cout << "DATA TERAKHIR BERHASIL DIHAPUS!" << endl;
    }
}

void hapus_semua(){
    if(kosong() == true){
        cout << "DATA KOSONG!" << endl;
    } else {
        obat->indeks = -1;
        cout << "SEMUA DATA BERHASIL DIHAPUS!" << endl;
    }
}