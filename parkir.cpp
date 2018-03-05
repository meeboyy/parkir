#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void cetak(int a, int b, char *teks){
	gotoxy(b,a); cout<<teks;
}
void cetakc(int a,char *teks){
	gotoxy(40-(strlen(teks)/2),a);cout<<teks;
}
char tanya(){
	char jw;
	cetak(5,2,"input data lagi[Y/T]? : "); 
	cin>>jw;
	cetak(5,2,"	");
	return(jw);
}
void judul(){
	cetakc(1, "PROGRAM PERHITUNGAN");
	cetakc(2, "PEMBAYARAN PARKIR");
	cetak(7,2,"===========================================================================");
	cetak(8,2, "|");
	cetak(8,5,"No");
	cetak(8,8,"|");
	cetak(8,12,"Kode");
	cetak(8,19,"|");
	cetak(8,25,"J E N I S");
	cetak(8,42,"|");
	cetak(8,44,"Masuk");
	cetak(8,52,"|");
	cetak(8,54,"Keluar");
	cetak(8,60,"|");
	cetak(8,62,"Lama");
	cetak(8,66,"|");
	cetak(8,68,"Bayar");
	cetak(8,74,"|");
	cetak(9,2,"===========================================================================");
}

void isi(){
	string kendaraan[3]={"Mobil", "Motor","Sepeda"};
	int harga[3]={5000,2000,1000};
	int tTambah[3]={1500,500,0};
	int jamMasuk,jamKeluar, totalTarif, totalJam;
	int j,n,x,posisi;
	char jawab;
	static int i =1;
	do{
		j=0;
		totalTarif=0;
		gotoxy(2,9+i); cout<<"|";
		gotoxy(5,9+i); cin>>i;
		gotoxy(8,9+i); cout<<"|";
		gotoxy(10,9+i); cin>>x;
		gotoxy(19,9+i); cout<<"|";	
		while(j<3 && j!=x){
			j++;
		}
		if(j!=x){
			gotoxy(21,9+i);cout<<"NULL";jawab=tanya();
		}
		else if(j==x){
			j=j-1;
			gotoxy(21,9+i); cout<<kendaraan[j];
			gotoxy(42,9+i); cout<<"|";
			gotoxy(44,9+i); cin>>jamMasuk;
			gotoxy(52,9+i); cout<<"|";
			gotoxy(54,9+i); cin>>jamKeluar;
			totalJam=jamKeluar-jamMasuk;
			gotoxy(60,9+i); cout<<"|";
			gotoxy(62,9+i); cout<<totalJam;
			gotoxy(66,9+i); cout<<"|";
			if(totalJam<=2&&totalJam>0){
				totalTarif=harga[j];
			}else if(totalJam>2){
				totalTarif=harga[j]+(tTambah[j]*totalJam);
			}else{
				gotoxy(67,9+i);cout<<"";
			}
			gotoxy(67,9+i);cout<<totalTarif; 
			gotoxy(74,9+i);cout<<"|"; 
			jawab=tanya();
			if(jawab=='t'){
				break;
			}
		}
		i++;
	}while(jawab!='t'||jawab!='T');
}

int main(){
	judul(); 
	isi();
	cout<<endl<<endl;
	cout<<"		Praktikum ASD";
	getch();
}
