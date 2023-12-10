#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

#define ppn 0.05

int main() {
    char nama[50];
    char menuMakanan[7][50] = {"Nasi Orak-Arik Telur", "Magelangan", "Nasi Omelet", "Mie Dokdok", "Nasi Nugget", "Nasi Campur", "Indomie Goreng/Kuah"}; //Tambahkan menu makanan sesuai keinginan untuk ditampilkan. 
    char menuMinuman[5][50] = {"Teh Manis", "Es Jeruk", "Air Mineral", "Kopi Hitam", "Jus Alpukat"}; //Tambahkan menu minuman disini sesuai keinginan untuk ditampilkan.
    int jumlah, makanan, minuman, totalMakanan, totalMinuman, totalKeseluruhan, bayar, kurang, pajak, kembalian, diskon;
    int hargaMakanan[7] = {11000, 13000, 10000, 14000, 12000, 9000, 8000}; //ubah varisasi harga menu makanan disini
    int hargaMinuman[5] = {5000, 7000, 4000, 6000, 10000}; //ubah variasi harga menu minuman disisni

    vector<string> daftarPesanan;

    do {
        system("CLS");
        cout << "=====================================RM======================================" << endl;
        cout << "=================================BURJO FAWWAZ=================================" << endl;
        cout << endl;

        // Validasi nama pelanggan
        do {
            cout << "Masukkan Nama Pelanggan (minimal 2 karakter): ";
            cin.ignore();
            cin.getline(nama, sizeof(nama));
        } while (strlen(nama) < 2);

        cout << "Pilihan menu makanan yang tersedia:" << endl;
        cout << "---------------------------------" << endl;
        for (int i = 0; i < 7; ++i) {
            cout << "| [" << i + 1 << "] " << setw(30) << left << menuMakanan[i] << "= Rp" << setw(7) << right << hargaMakanan[i] << " |" << endl;
        }
        cout << "---------------------------------" << endl;

        cout << "Silahkan Pilih Makanan Anda: ";
        cin >> makanan;

        // Validasi pilihan makanan
        while (makanan < 1 || makanan > 7) {
            cout << "Pilihan makanan tidak valid. Silahkan pilih lagi: ";
            cin >> makanan;
        }

        cout << "\nPilihan menu minuman yang tersedia:" << endl;
        cout << "---------------------------------" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "| [" << i + 1 << "] " << setw(30) << left << menuMinuman[i] << "= Rp" << setw(7) << right << hargaMinuman[i] << " |" << endl;
        }
        cout << "---------------------------------" << endl;

        cout << "Silahkan Pilih Minuman Anda: ";
        cin >> minuman;

        // Validasi pilihan minuman
        while (minuman < 1 || minuman > 5) {
            cout << "Pilihan minuman tidak valid. Silahkan pilih lagi: ";
            cin >> minuman;
        }

        cout << "\nAnda memilih " << menuMakanan[makanan - 1] << " dan " << menuMinuman[minuman - 1] << endl;

        cout << "\nJumlah makanan yang dibeli: ";
        cin >> jumlah;

        totalMakanan = jumlah * hargaMakanan[makanan - 1];
        totalMinuman = jumlah * hargaMinuman[minuman - 1];
        totalKeseluruhan = totalMakanan + totalMinuman;

        pajak = totalKeseluruhan * ppn;

        // ... (hitung diskon jika diperlukan)

        // Tampilkan struk pembayaran
        cout << "\n--------------------------------------------------------------" << endl;
        cout << "|                BURJO FAWWAZ CABANG SETURAN                  |" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "  Nama Pelanggan           : " << nama << endl;
        cout << "  Menu Makanan             : " << menuMakanan[makanan - 1] << endl;
        cout << "  Menu Minuman             : " << menuMinuman[minuman - 1] << endl;
        cout << "  Jumlah Makanan           : " << jumlah << " porsi" << endl;
        cout << "  Harga Makanan            : Rp " << hargaMakanan[makanan - 1] << " * " << jumlah << endl;
        cout << "  Harga Minuman            : Rp " << hargaMinuman[minuman - 1] << " * " << jumlah << endl;
        cout << "  Pajak Rumah Makan        : Rp " << pajak << endl;
        cout << "  Total Pembayaran         : Rp " << totalKeseluruhan + pajak << endl;

        cout << "\nMetode Pembayaran:" << endl;
        cout << "---------------------------------" << endl;
        cout << "| [1] Tunai                   |" << endl;
        cout << "| [2] Kartu Kredit            |" << endl;
        cout << "---------------------------------" << endl;
        cout << "Silahkan Pilih Metode Pembayaran: ";
        int metodePembayaran;
        cin >> metodePembayaran;

        // Validasi metode pembayaran
        while (metodePembayaran < 1 || metodePembayaran > 2) {
            cout << "Pilihan metode pembayaran tidak valid. Silahkan pilih lagi: ";
            cin >> metodePembayaran;
        }

        cout << "Masukkan biaya yang harus dibayarkan: ";
        cin >> bayar;

        // Validasi pembayaran
        while (bayar < totalKeseluruhan + pajak) {
            cout << "Pembayaran kurang. Silahkan masukkan jumlah yang cukup: ";
            cin >> kurang;
            bayar += kurang;
        }

        kembalian = bayar - (totalKeseluruhan + pajak);

        cout << "\n--------------------------------------------------------------" << endl;
        cout << "  TERIMA KASIH TELAH MEMESAN DI FAWWAZ  " << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "  Kembalian                 : Rp " << kembalian << endl;

        // Tanyakan apakah ingin memesan lagi
        cout << "\nIngin memesan lagi? (1: Ya, 0: Tidak): ";
        int pesanLagi;
        cin >> pesanLagi;

        if (pesanLagi != 1) {
            break;  // Keluar dari loop jika tidak ingin memesan lagi
        }

    } while (true);

    return 0;
}
