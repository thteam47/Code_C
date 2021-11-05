#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int choose;
int check_choose;

static int speed=0;
//xu li ma ca nhan
void info_person (){
	string info;
	string pass = "12345678";
	do{
		cout <<"NHAP MA SO CA NHAN: ";
		cin >> info;
		if (info.compare(pass)!=0) 
			 cout <<"MA SO CA NHAN KHONG DUNG. VUI LONG NHAP LAI."<<endl;
	} while (info.compare(pass)!=0);
}
//menu lua chon
void menu(){
	cout <<"XIN MOI LUA CHON:"<<endl;
	cout <<"1. P"<<endl;
	cout <<"2. R"<<endl;
	cout <<"3. N"<<endl;
	cout <<"4. D"<<endl;
	cout <<"5. POWER OFF"<<endl;
	cout <<" >> ";
	
	}
//xu li lua chon menu
void chooseMenu(){
	do {
		menu();
		cin >>choose;
		if (choose<1||choose>5) 
		cout <<"LUA CHON KHONG HOP LE. NHAP LAI."<<endl;
	} while (choose<1||choose>5);
	
}	
//menu lua chon toc do
void menuSpeed (){
	cout <<"MOT LUA CHON:"<<endl;
	cout <<"1. TANG TOC" <<endl;
	cout <<"2. GIAM TOC"<<endl;
	cout <<"3. PHANH" <<endl;
	cout <<"4. TRO VE MENU"<< endl;
	cout <<" >> ";
}
//xu li lua chon toc do
void chooseMenuSpeed(){
	do {
		menuSpeed();
		cin >>choose;
		if (choose<1||choose>4) 
		cout <<"LUA CHON KHONG HOP LE. NHAP LAI."<<endl;
	} while (choose<1||choose>4);
	
}
//hien thi toc do
void viewSpeed (int speed){
	cout <<"------TOC DO HIEN TAI: "<<speed <<" km/h ------"<<endl;
}

int main(int argc, char** argv) {
	info_person();
	system("cls");
	cout <<"XIN CHAO 12345678"<<endl;
	
	choose=0;
	
	//tro ve menu
	
	menuGoto:
	chooseMenu();

	if (choose==0){
			check_choose=choose;
			}
	switch (choose){
		case 3: {
			if (speed==0) {
				system("cls");
			cout <<"DA VE SO N"<<endl;
			cout <<"HAY SU DUNG PHANH TAY DE DAM BAO AN TOAN"<<endl;
			}
			else {
				system("cls");
				cout<<"HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H"<<endl;
				cout <<"HAY DUNG PHANH DE DUNG"<<endl;
			}
			check_choose=3;
			goto menuGoto;
			break;
		}
		//lui xe R
		case 2:{
			system("cls");
			speed=7;
			viewSpeed(speed);
			if (speed!=0&&check_choose==4){
				system("cls");
				cout<<"KHONG THE LUI XE. SU DUNG PHAN DE GIAM TOC DO VE 0 KM/H"<<endl;
				goto upGoto;
			}
			//tro ve menuspeed
			downGoto:
			
			cout<<"BAN DANG O CHE DO R"<<endl;
			//menu
			chooseMenuSpeed();
			if (speed==0) speed=7;
			if (speed>20&&choose==1){
				system("cls");
				viewSpeed(speed);
				cout<<"TOC DO NGUY HIEM. KHONG DUOC TANG TOC. VUI LONG LUA CHON LAI"<<endl;
				goto downGoto;
			}
			
			if (speed<=0&&choose==2){
				system("cls");
				viewSpeed(speed);
				cout<<"KHONG THE GIAM TOC DO. VUI LONG LUA CHON LAI"<<endl;
				goto downGoto;
			}
			switch (choose){
				//tang toc
				case 1: {
					speed+=5;
					if (speed>20){
						system("cls");
						viewSpeed(speed);
						cout <<"TOC DO NGUY HIEM. BAN NEN GIAM TOC DO"<<endl;
					}	
					else {
						system("cls");
						viewSpeed(speed);
					}
					goto downGoto;									
					break;
				}
				//giam toc
				case 2: {
					speed-=5;
					if (speed<0){
						cout<< 
						system("cls");
						speed=0;
						viewSpeed(speed);
					}	
					else {
						system("cls");
						viewSpeed(speed);
					}
					goto downGoto;
					break;
				}
				//phanh
				case 3:{
					speed=0;
					system("cls");
					cout <<"BAN DA PHANH"<<endl;
					viewSpeed(speed);
					goto downGoto;
					break;
				}
				case 4: {
					system("cls");
					check_choose=2;
					goto menuGoto;
					break;
				}
			}
			
			break;
		}
			
		case 1: {
			if (speed==0) {
				system("cls");
			cout <<"DA VE SO P"<<endl;
			}
			else {
				system("cls");
				cout<<"HAY CHAC CHAN XE TAM DUNG VA VAN TOC LA 0 KM/H"<<endl;
				cout <<"HAY DUNG PHANH DE DUNG"<<endl;
			}
			check_choose=1;
			goto menuGoto;
			break;
		}
		//tang toc D	
		case 4: {
			system("cls");
			speed=7;
			viewSpeed(speed);
			//tro ve menuspeed
			if (speed!=0&&check_choose==2){
				system("cls");
				cout<<"KHONG THE TIEN XE. SU DUNG PHAN DE GIAM TOC DO VE 0 KM/H"<<endl;
				goto downGoto;
			}
			upGoto:
			
			cout <<"BAN DANG O CHE DO D"<<endl;
			//menu
			chooseMenuSpeed();
			if (speed==0) speed=7;
			if (speed>60&&choose==1){
				system("cls");
				viewSpeed(speed);
				cout<<"TOC DO NGUY HIEM. KHONG DUOC TANG TOC. VUI LONG LUA CHON LAI"<<endl;
				goto upGoto;
			}
			
			if (speed<0&&choose==2){
				system("cls");
				viewSpeed(speed);
				cout<<"KHONG THE GIAM DUOC TOC DO. VUI LONG LUA CHON LAI"<<endl;
				goto upGoto;
			}
			
			switch (choose){
				//tang toc
				case 1: {
					speed+=5;
					if (speed>20){
						system("cls");
						viewSpeed(speed);
						cout <<"TOC DO NGUY HIEM. BAN NEN GIAM TOC DO"<<endl;
					}	
					else {
						system("cls");
						viewSpeed(speed);
					}
					goto upGoto;									
					break;
				}
				//giam toc
				case 2: {
					speed-=5;
					if (speed<0){
						cout<< 
						system("cls");
						speed=0;
						viewSpeed(speed);
					}	
					else {
						system("cls");
						viewSpeed(speed);
					}
					goto upGoto;
					break;
				}
				//phanh
				case 3:{
					speed=0;
					system("cls");
					cout <<"BAN DA PHANH"<<endl;
					viewSpeed(speed);
					goto upGoto;
					break;
				}
				case 4: {
					system("cls");
					check_choose=4;
					goto menuGoto;
					break;
				}
			}
			break;
		}
		
		case 5:{
			system("cls");
			cout <<"TAM BIET"<<endl;
			exit(0);
			break;
		}
	}
	
	
	
}









