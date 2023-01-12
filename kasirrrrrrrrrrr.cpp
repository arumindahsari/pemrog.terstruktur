#include <iostream>
#include "helper.h"
using namespace std;

//deklarasi array dan index
string nama_barang [20];
int harga_barang [20];
int stok_barang [20];
int index = -1;

void view_header(){
    println("-----------------------------");
    println("PROGRAM KASIR SEDERHANA 2022");
    println("-----------------------------");
}

void view_menu(){
	println("");
    println("MENU PROGRAM");
    println("1. view all BARANG");
    println("2. tambah BARANG");
    println("3. delete BARANG");
    println("4. update stok BARANG");
    println("5. EXIT");
}

void tambah_barang(){
    index ++;
    print("masukkan nama barang : ");
    cin>>nama_barang[index];
    print("masukkan harga barang : ");
    cin>>harga_barang[index];
    print("masukkan stok awal : ");
    cin>>stok_barang[index];
    println("input success");
}


void tambah_barang_static(string nama, int harga, int stok){
    index ++;
    nama_barang[index] = nama;
    harga_barang[index] = harga;
    stok_barang[index] = stok;
}
void view_barang(){
    cout<<"\t"<<"list barang"<<endl;
    cout<<"nama barang\tharga barang\tstok barang"<<endl;
    for(int i=0 ;i<=index;i++){
        cout<<nama_barang[i]<<"\t"<<"\t"<<harga_barang[i]<<"\t"<<"\t"<<stok_barang[i]<<endl;
    }
}
void data_barang_static(){
    //data input static barang
    tambah_barang_static("odol",5000,10);
    tambah_barang_static("sabun",3000,5);
    tambah_barang_static("shampo",18000,8);
    tambah_barang_static("sikat",10000,4);
    tambah_barang_static("rinso",5500,3);
}
int search_by_name(string name){
    int temp_index = -1;
    for (int i = 0 ; i <= index ; i++){
        if (name == nama_barang[i]){
            temp_index = i;
        }
    }
    return temp_index;
}

void delete_barang() {
	print("masukkan nama barang yang akan di delete : ");
	string nama;
	cin >> nama;
	int temp_index = search_by_name(nama);
	if (temp_index == -1){
		println("barang tidak tersedia");
	}
	else if(temp_index == index){
		index--;
	}
	else {
		for (int j = temp_index; j < index; j++){
			nama_barang[j] = nama_barang[j + 1];
			harga_barang[j] = harga_barang[j + 1];
			stok_barang[j] = stok_barang[j + 1];
		}
		cout<<"Delete Barang Success";
		cout<<endl;
		index--;
	}
}

void update_barang(){
    println("masukkan nama barang yang akan di update : ");
    string nama;
    cin>>nama;
    int temp_index = search_by_name(nama);
    if (temp_index == -1){
		println("barang yang di inputkan tidak ada");
	}else {
    	cout<<"masukkan stok baru : ";
    	cin>>stok_barang[temp_index];
	}
}

//void transaksi_barang(){
//	print("masukkan nama barang : ");
//	string nama;
//	cin>>nama;
//	println("masukkan jumlah barang : ");
//	int jumlah;
//	cin>>jumlah;
//	int subtotal = jumlah * harga_barang[j];
//}

int main() {
    view_header();
    data_barang_static();

    int pilih;
    while (pilih != 5){
        view_menu();
        print("masukkan pilihan menu : ");
        cin>>pilih;
        cout<<endl;
        switch (pilih) {
            case 1:
                println("menu view barang");
                view_barang();
                cout<<endl;
                break;
            case 2:
                println("menu insert barang");
                tambah_barang();
                break;
            case 3:
                println("menu delete barang");
                delete_barang();
                break;
            case 4:
                println("menu update barang");
                update_barang();
                break;
            case 5:
                println("menu EXIT");
                break;
        }
    }
    return 0;
}
