#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct user
{
    string id;
    string norek;
    string pin;
    string nama;
    int saldo;
    string sebagai;
    string status;
    string hapus_user;

} user[10];

int i, k, id_user = 0, awalan = 0, k_masuk;
string user_input;

int main();

void tampil_data(int k)
{
    system("cls");
    if (k == 0)
    {
        cout << "Data Kosong";
        getch();
    }
    else
    {

        cout << "[No Id   Nama          No Rekening        PIN     Saldo           Status      ]" << endl;
        cout << "-----------------------------------------------------------------------------";
        int urut = 1;
        int j;
        for (j = 0; j <= k; j++)
        {

            if (user[j].hapus_user == "aktif")
            {
                gotoxy(1, j + 3);
                cout << urut++;
                gotoxy(5, j + 3);
                cout << user[j].id;
                gotoxy(9, j + 3);
                cout << user[j].nama;
                gotoxy(25, j + 3);
                cout << user[j].norek;
                gotoxy(41, j + 3);
                cout << user[j].pin;
                gotoxy(50, j + 3);
                cout << user[j].saldo;
                gotoxy(67, j + 3);
                cout << user[j].status;
            }
            cout << endl;
        }
        getch();
    }
}

void isi_saldo()
{
    system("cls");
    int v_isi_saldo;

    cout << "Masukan Nominal uang ada = ";
    cin >> v_isi_saldo;
    // getline(cin, v_isi_saldo);
    cout << endl;

    user[id_user].saldo = user[id_user].saldo + v_isi_saldo;

    getch();
}

void ubah_pin()
{
    system("cls");

    cout << "Masukan Masukan PIN Baru = ";
    getline(cin, user[id_user].pin);
    cout << endl;

    getch();
}

void keluar()
{
    id_user = 0;
    user_input = "";
    cout << "Ada logout akun" << endl;
    cout << "Tekan Enter Untuk login" << endl;
    main();
}

void tambah_user(int k)
{
    string ulang, v_tidak;
    ulang = "y";
    v_tidak = "y";
    int j;

    cout << "<<==++ Pendaftaran Nasabah Baru ++==>>" << endl;
    string in_norek;
    while (ulang == "y")
    {

        cout << "Masukan NoRek Anda :";
        getline(cin, in_norek);

        for (j = 1; j <= k; j++)
        {

            if (user[j].norek == in_norek)
            {
                cout << "NoRek yang ada masukan sudah ada" << endl;
                v_tidak = "t";
            }
            if (j == k && v_tidak == "y")
            {
                cout << "data i :" << j << "data j :" << k << endl;
                user[i].id = i;
                user[i].saldo = 1500000;
                user[i].hapus_user = "aktif";
                user[i].status = "aktif";

                cout << "Nama:";
                getline(cin, user[i].nama);
                user[i].norek = in_norek;
                cout << "Masukan PIN:";
                getline(cin, user[i].pin);
                cout << "Bank Untuk admin/nasabah:";
                getline(cin, user[i].sebagai);

                i++;
            }
        }
        v_tidak = "y";

        cout << endl;
        k = i;
        cout << "Lagi ya/tidak=";
        getline(cin, ulang);
    }
}

void hapus_user(int k)
{

    string v_hapus;
    system("cls");
    if (k == 0)
    {
        cout << "Data Kosong";
        getch();
    }
    else
    {

        cout << "[No Id   Nama          No Rekening        PIN     Saldo           Status      ]" << endl;
        cout << "-----------------------------------------------------------------------------";
        int urut = 1;
        int j;
        for (j = 0; j <= k; j++)
        {

            if (user[j].hapus_user == "aktif")
            {
                gotoxy(1, j + 3);
                cout << urut++;
                gotoxy(5, j + 3);
                cout << user[j].id;
                gotoxy(9, j + 3);
                cout << user[j].nama;
                gotoxy(25, j + 3);
                cout << user[j].norek;
                gotoxy(41, j + 3);
                cout << user[j].pin;
                gotoxy(50, j + 3);
                cout << user[j].saldo;
                gotoxy(67, j + 3);
                cout << user[j].status;
            }
            cout << endl;
        }

        cout << "Masukan No Rekening yang di hapus = ";
        cin >> v_hapus;
        cout << endl;

        for (i = 0; i < k; i++)
        {
            if (user[i].norek == v_hapus)
            {
                user[i].hapus_user = "hapus";
            }
        }
        getch();
    }
}

void transfer_uang(int k)
{
    int v_transfer = 0, v_id = 0;
    string v_norek;
    cout << "Masukan No Rekening yang akan di Transfer : ";
    cin >> v_norek;
    if (user[i].norek != v_norek)
    {
        string v_se_norek = "tidak_ditemukan";
        for (int j = 0; j <= k; j++)
        {

            if (user[j].norek == v_norek)
            {
                if (user[j].hapus_user == "aktif")
                {
                    if (user[j].status == "aktif")
                    {
                        v_se_norek = "ditemukan";
                        v_id = j;
                    }
                    else
                    {
                        v_se_norek = "blok";
                    }
                }
            }
        }

        if (v_se_norek == "ditemukan")
        {
            cout << "Masukan Nominal Yang akan Anda Transfer : ";
            cin >> v_transfer;
            if (v_transfer < user[id_user].saldo)
            {
                user[v_id].saldo = user[v_id].saldo + v_transfer;
                user[id_user].saldo = user[id_user].saldo - v_transfer;
            }
            else
            {
                cout << "Nominal Yang Anda Masukan lebih besar Dari Saldo" << endl;
            }
        }
        else if (v_se_norek == "tidak_ditemukan")
        {
            cout << "No Rekening Tidak Ditemukan" << endl;
        }
        else if (v_se_norek == "blok")
        {
            cout << "No Rekening Yang Anda Tujuh Sedang DI Blokir " << endl;
        }
    }
    else
    {
        cout << "Yang ada masukan PIN anda sendiri" << endl;
    }
    getch();
}




int main()
{

    // input user awalan secara otomatis
    if (awalan == 0)
    {
        int id_isi = 1;
        string aw_norek;
        string aw_pin;
        string aw_saldo;
        string aw_nama;
        string aw_sebagai;
        string aw_status;
        string aw_hapus_user;

        aw_norek = "1112221";
        aw_pin = "11111";
        aw_nama = "argo";
        aw_sebagai = "admin";
        aw_status = "aktif";
        aw_hapus_user = "aktif";

        user[id_isi].norek = aw_norek;
        user[id_isi].pin = aw_pin;
        user[id_isi].saldo = 1500000;
        user[id_isi].nama = aw_nama;
        user[id_isi].sebagai = aw_sebagai;
        user[id_isi].status = aw_status;
        user[id_isi].hapus_user = aw_hapus_user;

        aw_norek = "3334443";
        aw_pin = "22222";
        aw_nama = "wilis";
        aw_sebagai = "nasabah";
        id_isi = 2;
        user[id_isi].norek = aw_norek;
        user[id_isi].pin = aw_pin;
        user[id_isi].saldo = 1500000;
        user[id_isi].nama = aw_nama;
        user[id_isi].sebagai = aw_sebagai;
        user[id_isi].status = aw_status;
        user[id_isi].hapus_user = aw_hapus_user;
        awalan++;
        i = 3;
    }

    // akhir input user

    string pilih;
    pilih = 'y';

    string login = "block";
    int i_blok,pin_input;
    i_blok = 1;

    char sensor, sensor_input[30];


        cout << "No Rekening : ";
        getline(cin, user_input);
        for (int j = 0; j <= i; j++)
        {
            if (user[j].norek == user_input)
            {
                id_user = j;
            }
        }

        if (user[id_user].norek == user_input && user[id_user].hapus_user == "aktif")
        {
            do
            {
                int i_pass;
                printf("Enter Password : ");
                while ((sensor = getch()) != 13)
                {
                    sensor_input[i_pass] = sensor;
                    i_pass++;
                    printf("*");
                }
                sensor_input[i_pass] = '\0';
                if (sensor_input == user[id_user].pin)
                {
                    string pilih_menu;
                    if (user[id_user].sebagai == "admin")
                    {
                        while (pilih != "8")
                        {
                            system("cls");
                            cout << "1. Lihat data" << endl;
                            cout << "2. isi saldo" << endl;
                            cout << "3. Hapus User" << endl;
                            cout << "4. Ubah PIN" << endl;
                            cout << "5. Transfer" << endl;
                            cout << "6. Tambah User" << endl;
                            cout << "7. Keluar akun" << endl;
                            cout << "Pilihan? = ";
                            getline(cin, pilih_menu);
                            if (pilih_menu == "1")
                                tampil_data(i);
                            if (pilih_menu == "2")
                                isi_saldo();
                            if (pilih_menu == "3")
                                hapus_user(i);
                            if (pilih_menu == "4")
                                ubah_pin();
                            if (pilih_menu == "5")
                                transfer_uang(i);
                            if (pilih_menu == "6")
                                tambah_user(i);
                            if (pilih_menu == "7")
                                keluar();
                        }
                    }
                    else if (user[id_user].sebagai == "nasabah")
                    {
                        while (pilih != "4")
                        {
                            system("cls");
                            cout << "1. Isi saldo" << endl;
                            cout << "2. Ubah PIN" << endl;
                            cout << "3. Transfer" << endl;
                            cout << "4. Keluar akun" << endl;
                            cout << "Pilihan? = ";
                            getline(cin, pilih_menu);
                            if (pilih_menu == "1")
                                isi_saldo();
                            if (pilih_menu == "2")
                                ubah_pin();
                            if (pilih_menu == "3")
                                transfer_uang(i);
                            if (pilih_menu == "4")
                                keluar();
                        }
                    }
                    i_blok = 4;
                    login = "berhasil";
                }
            } while (i_blok <= 3);

            if (login != "berhasil")
            {
                cout << "Anda telah 3x salah login.\n";
                cout << "Silahkan coba 40218 Hari lagi. Terima Kasih..\n\n";
            }

            login = "berhasil";
        }
        else
        {
            cout << "\n===========================\n";
            cout << "Username Salah! \n";
            cout << "=============================\n\n";
        }
        if (login != "berhasil")
        {
            cout << "Nomer Rekening Anda Salah\n";
            cout << "Silahkan coba. Terima Kasih..\n\n";
        }
        cout << "Lagi ya/tidak=";
        getline(cin, pilih);
        system("cls");

        if (pilih == "ya")
        {
            login = "berhasil";
            main();
        }else{
            exit(0);
        }

    return 0;
}