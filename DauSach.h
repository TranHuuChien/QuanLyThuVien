#pragma once
#include "DanhMucSach.h"
#include <string.h>
#include <iostream>
//#include "DoHoa.h"
//#include "OutputData.h"
const int _SIZE_DS=100;
const int MAX_SIZE_DAUSACH=20;

struct DauSach{
	char ISBN[13];
	char TenSach[20];
	int SoTrang;
	char TacGia[20];
	int NXB;
	char TheLoai[20];
	short int soluotmuon;
	short int soluong;
	NodeSach *first=NULL;	
};


DauSach dausach(char isbn[], char tensach[], int sotrang, char tacgia[], int NXB, char theloai[], short int sl){
	DauSach dauSach;
		strcpy(dauSach.ISBN, isbn);
		strcpy(dauSach.TenSach, tensach);
		dauSach.SoTrang=sotrang;
		strcpy(dauSach.TacGia, tacgia);
		dauSach.NXB=NXB;
		strcpy(dauSach.TheLoai, theloai);
		dauSach.soluong=sl;
		dauSach.soluotmuon=0;
	//	dauSach.first=first_tmp;
		return dauSach;
	}
struct List{
	int n;
	DauSach *node[_SIZE_DS];
	List(){
		n=0;
	}
};



int listIndexDauSachSearch[MAX_SIZE_DAUSACH];

short int timkiem(List &DSDS, char *tensach){	
	if(DSDS.n==0)	return -1;
	else{
		for(int i=0; i<DSDS.n; i++){
			if(	strcmp(DSDS.node[i]->TenSach, tensach)==0){
				return i;
			}	
		}
		return -1;
	}
}

void Them_Nodesach(List &DSDS, char *vitri)
{
	char s[3];
	NodeSach *chay;	
	char luutam[16];
	short int dem ;
	for(short int j=0; j<DSDS.n; j++){							
		for(dem=1; dem <= DSDS.node[j]->soluong; dem++)
		{
			Sach sach;
							strcpy(luutam,DSDS.node[j]->ISBN);
				strcpy(sach.MaSach,strcat(DSDS.node[j]->ISBN,itoa(dem,s,10)));
							strcpy(DSDS.node[j]->ISBN,luutam);
				sach.TrangThai=0;	
				strcpy(sach.ViTri,vitri); 
				themcuoi(sach,DSDS.node[j]->first);
		}
	}	
}
void InsertDauSach(List &DSDS, DauSach dausach, int pos){
	if(DSDS.n==_SIZE_DS){
//	std::	cout<<"Vi tri them khong hop le";		
	}
	else{	
		DSDS.n++;
		for(int i=DSDS.n-1; i>pos; i--){		// Them dau sach vao vi tri pos
			DSDS.node[i]=DSDS.node[i-1]; // doi cac phan tu sau pos len 1 don vi
		}
		DSDS.node[pos] = new DauSach(dausach);
	}	
}
void InsertLastDauSach(List &DSDS, DauSach dausach){
	if(DSDS.n > _SIZE_DS)
		std::	cout<<"full";
	else{
		DSDS.node[DSDS.n] = new DauSach(dausach);
		DSDS.n++;
	}
}

void AddDauSach(List &DSDS, DauSach dausach,char *vitri){ 
		if(DSDS.n<=_SIZE_DS){
			for(int i=0; i<DSDS.n; i++){
				if(strcmp(dausach.TheLoai, DSDS.node[i]->TheLoai)<0){
					InsertDauSach(DSDS, dausach, i); 
					Them_Nodesach(DSDS,vitri);
					return;
				}
				if(strcmp(dausach.TheLoai, DSDS.node[i]->TheLoai) >= 0){
					if(strcmp(dausach.TenSach,DSDS.node[i]->TenSach) <=0){
						InsertDauSach(DSDS,dausach,i);
						Them_Nodesach(DSDS,vitri);
						return;
					}
				}
			}
			DSDS.node[DSDS.n++]=new DauSach(dausach);
			
		}
}

void Delete_DS(List &DSDS, char *isbn){
	int i=timkiem(DSDS,isbn);
	if(i=!-1){
		delete DSDS.node[i];
		for(int j=i+1;j<DSDS.n;j++){
			DSDS.node[j-1]=DSDS.node[j];
			}
		DSDS.n--;
	}
	else {
		//Warning("Khong tim thay!");
		return;
	}
}
//---------------------------

void ThayTTSach(List &DSDS,char *tensach, char *masach){
	if(DSDS.n==0)	return ;	
	else{
		short f = timkiem(DSDS,tensach);
		if(f==-1){
			
			return ;
		}
		else{
			short i=0;
			NodeSach *chay;
			for(chay=DSDS.node[f]->first; i<DSDS.node[f]->soluong; chay=chay->next){
				if(strcmp(chay->sach.MaSach, masach)==0){
					chay->sach.TrangThai=1;	
				//	std::cout<<"Sach thay doi tt: "<<DSDS.node[f]->TenSach<<"-"<<chay->sach.TrangThai;
					break;	
				}
				i++;
			}
			return ;
		}
	}
	
}
short TimKiemSach(char *maSach, List &DSDS){
	NodeSach *chay;
	for(int i=0; i<DSDS.n; i++){
		for(chay=DSDS.node[i]->first; chay!=NULL; chay=chay->next){
			if(strcmp(maSach,chay->sach.MaSach)==0){
				return i;
				break;
			}
		}
	}
	return -1;
}

void DeleteAllDauSach(List &DSDS){
	if(DSDS.n!=0){
		for(int i=0; i<DSDS.n; i++){
			GiaiPhongVungNhoDMS(DSDS.node[i]->first);
			delete DSDS.node[i];
		}
	}
}





