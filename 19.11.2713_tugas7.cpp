#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#define MAX 5

using namespace std;

struct queue{
int data[MAX];
int awal,akhir;
}antri;


void init(){
antri.awal = -1;
antri.akhir = -1;
}


bool full(){
if(antri.akhir == MAX-1){
    return true;
}
else{
    return false;
}
}


bool empty(){
if(antri.akhir == -1){
    return true;
}
else{
    return false;
}
}


void tampil(){
int a;
if(!empty()){
    for(a=antri.awal; a<antri.akhir; a++){
        cout<<antri.data[a]<<" | ";
        //untuk tampil data dobel karna saya memanggilnya dua kali memang.eheheh.
        //satu dalam int main dan satunya di dalam function tampil.
    }
}
cout<<"\n";
}


void inqueue(){
tampil();
int elemen;

if(!full()){
    cout<<"data yang anda masukan : ";cin>>elemen;
    cout<<"data berhasil ditambahkan | "<<endl;
    antri.data[antri.akhir]=elemen;
    antri.akhir++;
}
else{
  cout<<"queue sudah penuh | ";
}
getchar();
}


void dequeue(){
int a;
tampil();
if(!empty()){
    cout<<"\nmengambil data \" "<<antri.data[antri.awal]<<" \"..."<<endl;
    for(a=antri.awal; a < antri.akhir; a++){
    antri.data[a]=antri.data[a+1];
}
antri.akhir--;
}
else{
    cout<<"antrian kosong";
}getchar();
}


void bersih(){
antri.awal = -1;
antri.akhir = -1;
}
void garis(){
cout<<"---------------"<<endl;
}


void cari(){
     int bil,i,ketemu=0;
     cout<<"nilai yang akan dicari : ";cin >>bil;
     for(i=-1; i<antri.akhir; i++){
        if(antri.data[i]==bil){
            ketemu=1;
            cout<<"data berapa pada index ke-"<<i+1<<endl;
            //dimulai dari index ke-0.
        }
     }
     if(ketemu==0){
        cout<<"data tidak ditemukan"<<endl;
     }
}


void Count (){
        int i, min=0, max=0;
        float total=0 ,avg;
        min = max = antri.data[0];

        for (i = antri.awal; i< antri.akhir; i++ ){
            total += antri.data[i];

        if( i == antri.awal){

            max = antri.data[i];
            min = antri.data[i];
        }
        else if (max < antri.data[i])
        {
            max = antri.data[i];
        }
        else if (min > antri.data[i])
        {
            min = antri.data[i];
        }
        else{}
        }
        avg = total / (antri.akhir+1);

        cout<<endl;
        cout<<" Nilai Total       : " << total <<endl;
        cout<<" Nilai Rata - rata : " << avg <<endl;
        cout<<" Nilai Maximum     : " << max <<endl;
        cout<<" Nilai Minimum    : " << min <<endl;
        getchar();
    }


int main()
{
    int pilihan,elemen;
    init();
    cout<<"demo queue dengan linear array"<<endl;
    do{
    tampil();
    cout << "|menu utama   |"<<endl;
    garis();
    cout << "|1=>init      |"<<endl;
    cout << "|2=>inqueue   |"<<endl;
    cout << "|3=>dequeue   |"<<endl;
    cout << "|4=>tampil    |"<<endl;
    cout << "|5=>bersih    |"<<endl;
    cout << "|6=>cari index|"<<endl;
    cout << "|7=>count     |"<<endl;
    garis();
    cout << "masukan pilihan anda : ";cin>>pilihan;

    switch(pilihan){
case 1:
    init();
    break;
case 2:
    inqueue();
    break;
case 3:
    dequeue();
    break;
case 4:
    tampil();
    break;
case 5:
    bersih();
    break;
case 6 :
    cari();
    break;
case 7 :
    Count();
    }
}
    while (pilihan!=0);
    return 0;
}
