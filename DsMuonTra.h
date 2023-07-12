#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define TIME_QH 604800

struct MuonTra{
	char MaSach[16] ;
	char NgayMuon[20];
	char NgayTra[20];
	int TrangThai; // 0,1,2
		// 0 chua tra
		// 1 da tra
		// 2 lam mat
		// 3 qua han
	unsigned long Time_Muon;
	unsigned long Time_Tra;
};
struct NodeMuonTra{
	MuonTra muontra;
	NodeMuonTra *next;
};
//struct DS_MuonTra{
//	int Muon; // Muon chua tra;
//	int Tra_TL; // Da Tra hoac thanh ly roi
//	NodeMuonTra *cont;
//};
MuonTra ThemNguoiMuon(char masach[],char ngaymuon[],char ngaytra[], int tt){
	MuonTra mt;
	strcpy(mt.MaSach,masach);
	strcpy(mt.NgayMuon,ngaymuon);
	strcpy(mt.NgayTra,ngaytra);
	mt.TrangThai=tt;
	return mt;
}
NodeMuonTra *NewMuonTra(MuonTra &mt){
	NodeMuonTra *CreMuonTra = new NodeMuonTra;
	CreMuonTra->muontra = mt;
	CreMuonTra->next=NULL;
	return CreMuonTra;
}
//struct DS_MuonTra{
//	NodeMuonTra *first=NULL;
//	int total;
//	int chuatra;
//	DS_MuonTra(){
//		first = NULL;
//		total=0;
//		chuatra=0;
//	}
//	~DS_MuonTra(){
//	}
//};
// ---------------------------------------------------------------- Ham lay thoi gian

unsigned long Time_FromTo(){
	time_t baygio = time(0);
	unsigned int now=baygio;
 // std:: cout << "So giay ke tu 1/1/1970 la: " <<now << std::endl;
    return now;
}
void NgayMuon(MuonTra &mt){
	time_t baygio=time(0);
	tm *ltm = localtime(&baygio);
	int day=ltm->tm_mday;
	char tmp[10];
	char ngay[10];
	char thang[10];
	char nam[10];
	strcpy(ngay , strcat(itoa(day,tmp,10),"/"))	;
	strcpy(thang,strcat(ngay,itoa(ltm->tm_mon+1,tmp,10)));
	strcpy(nam,strcat(thang,"/"));
	strcpy(mt.NgayMuon, strcat(nam,itoa(1900+ltm->tm_year,tmp,10)));
	strcpy(mt.NgayTra,"--/--/--");
}
void NgayTra(MuonTra &mt){
	time_t baygio=time(0);
	tm *ltm = localtime(&baygio);
//	std::cout<<"Thang : "<<ltm->tm_mon<<"\n";
	int day=ltm->tm_mday;
//	char ngaymuontra[20];
	char tmp[10];
	char ngay[10];
	char thang[10];
	char nam[10];
	strcpy(ngay , strcat(itoa(day,tmp,10),"/"))	;
	strcpy(thang,strcat(ngay,itoa(ltm->tm_mon+1,tmp,10)));
	strcpy(nam,strcat(thang,"/"));
	strcpy(mt.NgayTra, strcat(nam,itoa(1900+ltm->tm_year,tmp,10)));
//		std::cout<<"Ngay Tra : "<<mt.NgayTra<<"\n";
//		std::cout<<"Ngay muon : "<<ngay<<"\n";
//		std::cout<<"Ngay muon : "<<nam<<"\n";
//	return ngaymuontra;
}

//-------------------------------------------------------------------------------
void InsertHeadMuonTra(MuonTra &mt, NodeMuonTra *first){
	NodeMuonTra *tmp=  NewMuonTra(mt);
	if(first==NULL)	tmp=first;
	else{
		tmp->next=first;
		first=tmp;
	}
	
}
void InsertTailMuonTra(MuonTra &mt, NodeMuonTra *&first){
	NodeMuonTra *tmp =NewMuonTra(mt);
	if(first==NULL){
		first=tmp;
		return;
	}
	else{
		NodeMuonTra *run = first;
		while(run->next!=NULL){
			run=run->next;	
		}
		run->next=tmp;
		
	}
	
}
void Insert_theoMS(MuonTra &mt, NodeMuonTra *&first){
	NodeMuonTra *tmp= NewMuonTra(mt);
	if(first==NULL)	{
		first=tmp;		
	}	
	else{	
		NodeMuonTra *run = first;
		while(run!=NULL){
			if(strcmp(tmp->muontra.MaSach,run->muontra.MaSach)<0){
				tmp->next=run;
				first=tmp;	
			}
			else if(strcmp(tmp->muontra.MaSach,run->muontra.MaSach)>0){
				tmp->next=run->next;
				run->next=tmp;
			}
			run=run->next;
		}
		run->next=tmp;	
	}
}
//void Delete_NodeMT( NodeMuonTra *&first,char* MS){
//	if(strcmp(masach,first->muontra.MaSach)==0){
//			NodeMuonTra *run=first;
//			first=first->next;
//			delete run;
//		}
//	while(run->next!=NULL && strcmp(run->muontra.MaSach,masach)!=0){
//			truoc_run=run;
//			run=run->next;
//		}
//		if(strcmp(run->muontra.MaSach,masach)!=0){
//			truoc_run->next=run->next;
//			delete run;
//		}
//		else{
//			return;
//		}		
//}
//void removeAtHead(NodeMuonTra *&first){
//    if (first == NULL) return;
//    NodeMuonTra* temp = first;
//    first = first->next;
//    delete temp;
//}
//void removeAfter(NodeMuonTra* q){
//    NodeMuonTra* temp = q->next;
//    q->next = temp->next;
//    delete temp;
//}
void GiaiPhongVungNhoMuonTra(NodeMuonTra *&first){
	NodeMuonTra *k=NULL;
	while(k!=NULL){
		k=first;
		first=first->next;
		delete k;
	}
}
//int Search_MT(NodeMuonTra *first, int MS){
//	bool TonTai=false;
//	NodeMuonTra *run=first;
//		while(run->next!=NULL ){
//			if(run->muontra.MaSach==MS){
//				TonTai=true;
//			}
//			run=run->next;
//		}
//	if(TonTai==false){
//		std::cout<<"Khong tim thay!!!";
//		return -1;
//	}
//	else return 1;
//}







