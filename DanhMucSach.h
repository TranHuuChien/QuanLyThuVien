#pragma once
#include <iostream>
#define MAXSIZE_DMS 30
struct Sach{
	char MaSach[16];
	short int TrangThai; // 0: cho muonn dc, 1: dã có nguoi muon, 2: sách dã thanh lý . 
	char ViTri [20];
	Sach(){
	}
	Sach(char masach[16], int tt, char vitri[20]){
		strcpy(MaSach, masach);
		TrangThai=tt;
		strcpy(ViTri, vitri);
		}
};
struct NodeSach{
	Sach sach;
	NodeSach *next=NULL ;
};


NodeSach *NewNode(Sach &sach){
	NodeSach *Newnode = new NodeSach;
	Newnode->sach=sach;
	Newnode->next=NULL;
	return Newnode;
}
NodeSach *TimKiem_theoTT(NodeSach *&first){
	NodeSach *chay ;
	for(chay=first; chay!=NULL; chay=chay->next){ 
		if(chay->sach.TrangThai==0){
			return chay;	//cho muon dc
			break;
		}	
	}
	std::cout<<"....."<<chay->sach.TrangThai<<"\n";
	return 0;	// mat/tl hoac da cho muon
}

void themdau(Sach &sach,NodeSach *first){
	NodeSach *temp= NewNode(sach);
	if(first==NULL){
		first = temp;
		return;
	}
	else{
		temp->next=first;
		first=temp;
	}
}

void themcuoi(Sach &sach,NodeSach *&first){
	NodeSach *tmp = NewNode(sach);
	if(first==NULL){
		first=tmp;
		return;
	}
	else{
		NodeSach *nodechay= first;
		while(nodechay->next!=NULL){
			nodechay=nodechay->next;
		}
		nodechay->next=tmp;
	}
}
void GiaiPhongVungNhoDMS(NodeSach *&first){
	NodeSach *k=NULL;
	while(k!=NULL){
		k=first;
		first=first->next;
		delete k;
	}
}
int Output_DS_sach(Sach sach, NodeSach *first){
	NodeSach *run = first;
	int dem=0;
	while(run->next!=NULL){
		run=run->next;
		dem++;
	}
	return dem;
}

//void XoaSach(char *masach, NodeSach *&first){
//	if(strcmp(first->sach.MaSach,masach)==0){
//		NodeSach *tmp=first;
//		first=first->next;
//		delete tmp;	
//	}
//	else{
//		NodeSach *run=first;
//		NodeSach *save=first;
//		while(strcmp(run->sach.MaSach,masach)!=0 && run->next!=NULL){
//			run=save;
//			run=run->next;
//		}
//		if(strcmp(run->sach.MaSach,masach)==0){
//			save->next=run->next;
//			delete run;
//		}
//		else{
//			return;
//		}	
//	}
//}




