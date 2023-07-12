#pragma once
#include "DoHoa.h"
#include "DauSach.h"
#include "DsTheDocGia.h"
#include "DSMuonTra.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void GhiFile_DauSach(List &DSDS){
	ofstream outF;
	outF.open("Data_DauSachh.txt", ios::out);
	for(int i=0; i<DSDS.n; i++){
		outF<<"\n\n";
		outF<<DSDS.node[i]->SoTrang<<"\n";
		outF<<DSDS.node[i]->soluong<<"\n";
		outF<<DSDS.node[i]->NXB<<"\n";
		outF<<DSDS.node[i]->soluotmuon<<"\n";
		outF<<DSDS.node[i]->ISBN<<"\n";
		outF<<DSDS.node[i]->TenSach<<"\n";
		outF<<DSDS.node[i]->TacGia<<"\n";
		outF<<DSDS.node[i]->TheLoai;
	}
	outF.close();
}
void GhiFile_DMS(List &DSDS){
	NodeSach *chay;
	ofstream outF_DMS;	
	outF_DMS.open("Data_DanhMucSach.txt",ios:: out);
	short dem;
	for(int i=0; i<DSDS.n; i++){	
		dem=0;
		for(chay=DSDS.node[i]->first; dem<DSDS.node[i]->soluong;chay=chay->next ){
			outF_DMS<<chay->sach.MaSach<<",";
			outF_DMS<<chay->sach.ViTri<<",";
			outF_DMS<<chay->sach.TrangThai<<"\n";
			dem++;
		}
		outF_DMS<<"\n";
	}
	outF_DMS.close();
}
void DocFile_Sach(fstream &Inp, Sach &sach){
	string data_tmp;
	getline(Inp, data_tmp,',');
		strcpy(sach.MaSach,data_tmp.c_str());
	getline(Inp,data_tmp,',');
		strcpy(sach.ViTri,data_tmp.c_str());
	Inp>>sach.TrangThai;	getline(Inp,data_tmp,'\n');
}
void DocFile_DMS(List &DSDS){
	fstream inp_DMS;
	inp_DMS.open("Data_DanhMucSach.txt",ios::in);
	if(inp_DMS.fail()){
			std::cout<<"Loi File DauSach";
			return ;
		}
	if(DSDS.n==0){
		BaoLoi("DS trong!");
		return;
	}
	string data_tmp;
	while(!inp_DMS.eof()){	
		for(int i=0; i<DSDS.n; i++){
			for(int dem=0; dem<DSDS.node[i]->soluong;dem++){
				Sach sach;
				DocFile_Sach(inp_DMS,sach);
				themcuoi(sach,DSDS.node[i]->first);
			}
			getline(inp_DMS,data_tmp,'\n');		
		}
		
	}
	inp_DMS.close();
}
void DocFile_DauSach(List &DSDS){
	fstream ds;
	ds.open("Data_DauSachh.txt", ios::in);
		if(ds.fail()){
			std::cout<<"Loi File DauSachh";
			return ;
		}
		string datads;	
		getline(ds,datads, '\n');
		getline(ds,datads, '\n');
		while(!ds.eof()){	
				//	getline(ds,datads, '\n');
						
				DSDS.node[DSDS.n]=new DauSach;	ds>> DSDS.node[DSDS.n]->SoTrang; 	
					getline(ds,datads, '\n');
				ds>> DSDS.node[DSDS.n]->soluong;	
					getline(ds,datads, '\n');
				ds>> DSDS.node[DSDS.n]->NXB; 
					getline(ds,datads, '\n');
				ds>> DSDS.node[DSDS.n]->soluotmuon;
					getline(ds,datads, '\n');
					getline(ds,datads,'\n');				
				strcpy(DSDS.node[DSDS.n]->ISBN,datads.c_str());	
					getline(ds,datads, '\n');
				strcpy(DSDS.node[DSDS.n]->TenSach,datads.c_str());
					getline(ds,datads, '\n');		
				strcpy(DSDS.node[DSDS.n]->TacGia,datads.c_str());	
					getline(ds,datads, '\n');
				strcpy(DSDS.node[DSDS.n]->TheLoai,datads.c_str());
			//	std::cout<<datads<<"<<+++data==="<<std::endl;
			DSDS.n++;
		}
		ds.close();
}

void Find_DS(List &DSDS, char *tensach){
	int f= timkiem(DSDS,tensach);
	char s[10], x[10];
	if(f==-1 || strcmp(tensach,"")==0 )	{
		BaoLoi("Khong tim thay");
		return;
	}
	else{	
		outtextxy(623,22,DSDS.node[f]->ISBN);
		outtextxy(509,82,itoa(DSDS.node[f]->SoTrang,x,10));
		outtextxy(500,52,DSDS.node[f]->TacGia);
		outtextxy(834,82,itoa(DSDS.node[f]->NXB,s,10));
		outtextxy(1024,22,DSDS.node[f]->TenSach);
		outtextxy(1024,52,DSDS.node[f]->TheLoai);
		vehinh2(700,112,800,140,10,10,0,174,"HUY");
	}	
}
void Scan_DMS( List &DSDS,char *tensach, short trang){ 
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	unsigned int ten_DS=timkiem(DSDS,tensach);	
	if(ten_DS!=-1){
		NodeSach *chay=DSDS.node[ten_DS]->first;
		int i;
		char s[2];
		short j=0;
		while(j<=trang){
			DrawTable_DMS(j);
			delay(0.00001);
			for(i=0 ; i<10 && i<(DSDS.node[ten_DS]->soluong)-j*10;chay!=NULL){	
				setfillstyle(1,15);
				setcolor(0);
				outtextxy(380,200+40*i,chay->sach.MaSach);	
				if(chay->sach.TrangThai==0 ){
					setfillstyle(1,15);
					setcolor(0);
					outtextxy(1155,200+40*i,"Co the muon"); 
					}
				else if(chay->sach.TrangThai==1){
					setfillstyle(1,15);
					setcolor(1);
					outtextxy(1155,200+40*i,"Da cho muon");
					}
				else if(chay->sach.TrangThai==2){
					setfillstyle(1,15);
					setcolor(0);
					outtextxy(1155,200+40*i,"Da thanh ly");
					}
				outtextxy(875,200+40*i,chay->sach.ViTri);
				chay=chay->next;
				i++;
			}
			j++;
		}
	}
}
void swap_dausach(DauSach *a, DauSach *b){
	DauSach c=*a;
	*a=*b;
	*b=c;
}
int Partition_ds(List &DSDS,int low, int high){
	DauSach *pivot = DSDS.node[high];
	int i= low-1;
	for (int j = low; j <= high - 1; j++)  
    {
        if (strcmp(DSDS.node[j]->TheLoai , pivot->TheLoai)<0)  
        {  
            i++; 
            swap_dausach(DSDS.node[i],DSDS.node[j]);  
        }
		else if(strcmp(DSDS.node[j]->TheLoai , pivot->TheLoai)==0){
			if(strcmp(DSDS.node[j]->TenSach,pivot->TenSach)<0){
				i++; 
            	swap_dausach(DSDS.node[i],DSDS.node[j]);	
			}
		}  
    }  
	swap_dausach(DSDS.node[i+1],DSDS.node[high]);  
    return (i + 1);
}
void quickSort_ds(List &DSDS,int low, int high)  
{  	

    if (low < high)  
    {  
        int pi = Partition_ds(DSDS,low, high);  
        quickSort_ds(DSDS,low, pi - 1);  
        quickSort_ds(DSDS,pi + 1, high);  
    }  
}  
void scanDSDS(List &DSDS, short &trang){
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	char s[10]="";
	short j=0;
	quickSort_ds(DSDS,0,DSDS.n-1);
	while(j<=(trang)){	
		DrawTable_DS(j);
		delay(0.00001);
		for(int i=0; i<10 && i<DSDS.n-j*10; i++){			
			outtextxy(1355,200+40*(i),itoa(DSDS.node[j*10+i]->NXB,s,10));
			outtextxy(380,200+40*(i),DSDS.node[j*10+i]->ISBN);
			outtextxy(540,200+40*(i),DSDS.node[j*10+i]->TenSach);
			outtextxy(860,200+40*(i),DSDS.node[j*10+i]->TacGia);
			outtextxy(1130,200+40*(i),DSDS.node[j*10+i]->TheLoai);	
					
		}		
		j++; 
	}
}
void XoaNodeDauSach(List &DSDS, char *tensach){
	int i=timkiem(DSDS,tensach); 
	if(i!=-1){
		NodeSach *chay;
		for(chay=DSDS.node[i]->first;chay!=NULL;chay=chay->next){
			if(chay->sach.TrangThai==1)	{
				BaoLoi("Sach da co nguoi muon");
				break;
			}
			else{ 
				Yes_No("Ban da chac chan?");
				vehinh2(30,470,130,500,12,12,15,1740,"YES");
				vehinh2(180,470,280,500,12,12,15,1741," NO");
				setbkcolor(15);
				setcolor(0);
				settextstyle(6,0,1);
			}
		}
	}
}
void Sure_XoaDauSach(List &DSDS, char *tensach){
	int i=timkiem(DSDS,tensach);
	delete DSDS.node[i];
	for(int j=i+1; j<DSDS.n; j++){
		DSDS.node[j-1]=DSDS.node[j];
	}
	DSDS.n--;
}
int Partition_dsTOP(List &DSDS,int low, int high){
	DauSach *pivot = DSDS.node[high];
	int i= low-1;
	for (int j = low; j <= high - 1; j++)  
    {
        if (DSDS.node[j]->soluotmuon > pivot->soluotmuon)  
        {  
            i++; 
            swap_dausach(DSDS.node[i],DSDS.node[j]);  
        }
		else if(DSDS.node[j]->soluotmuon == pivot->soluotmuon){
			if(strcmp(DSDS.node[j]->TenSach,pivot->TenSach)<0){
				i++; 
            	swap_dausach(DSDS.node[i],DSDS.node[j]);	
			}
		}  
    }  
	swap_dausach(DSDS.node[i+1],DSDS.node[high]);  
    return (i + 1);
}
void quickSort_dsTOP(List &DSDS,int low, int high)  
{  	

    if (low < high)  
    {  
        int pi = Partition_dsTOP(DSDS,low, high);  
        quickSort_dsTOP(DSDS,low, pi - 1);  
        quickSort_dsTOP(DSDS,pi + 1, high);  
    }  
}  
void Top_10Sach(List &DSDS){
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	char s[10]="";	
	quickSort_dsTOP(DSDS,0,DSDS.n-1);
	for(int i=0; i<10 && i<DSDS.n ; i++){	
		outtextxy(1355,200+40*(i),itoa(DSDS.node[i]->NXB,s,10));
		outtextxy(380,200+40*(i),itoa(DSDS.node[i]->soluotmuon,s,10));
		outtextxy(505,200+40*(i),DSDS.node[i]->TenSach);
		outtextxy(860,200+40*(i),DSDS.node[i]->TacGia);
		outtextxy(1130,200+40*(i),DSDS.node[i]->TheLoai);				
	}		
}
//============================================================================================================
//============================================================================================================
void leveltrav(int minN, NodeThe *&root,Queue &q ){	
	NodeThe *p=root;
	ofstream ghiso;
	ghiso.open("sinhSoNgauNhien.txt");
	q.Front=NULL; 
	q.Rear=NULL;
	if(root!=NULL){
		Insert_queue(q,root);
	}
	while(q.Front!=NULL){
		p=Delete_queue(q); 
		ghiso<<p->member.MaThe<<" ";
		if(p->L!=NULL){
			Insert_queue(q,p->L);
		}	
		if(p->R!=NULL){		
			Insert_queue(q,p->R);
		}			
	}
	ghiso.close();
}

void Create_ID( NodeThe *&root, int minN){
	int arr[_SIZE_DG];
	int i;
	for(i=0; i< _SIZE_DG; i++){
		arr[i]=minN+i+1;
	}
	NodeThe *p = RandomToBST(root,arr, 0, _SIZE_DG-1); 
	Queue q;
	leveltrav(minN,p,q);
}
int ID(int dem){		
	char mathe[10]="";
	int n;
	ifstream FileIn;
	FileIn.open("sinhSoNgauNhien.txt", ios_base::in);
	FileIn.seekg(dem*7,ios_base::beg);
	FileIn>>n;
	outtextxy(490,22,itoa(n,mathe,10));
	return n;	
}
void GioiTinh(int phai){
	if(phai==0){	// 0 la con trai
		vehinh2(485, 80, 560, 110,9,9,0,9,"NAM");
		delay(100);	
		vehinh2(565, 80, 640, 110,14,14,0,11,"NU");
		}
	if(phai==1)	{		// 1 la con gai
		vehinh2(565, 80, 640, 110,9,9,0,11,"NU");
		delay(100);
		vehinh2(485, 80, 560, 110,14,14,0,9,"NAM");
		}
}
void TrangThai(int tt){
	if(tt==0){		
		vehinh2(1110,80,1240,110,9,9,0,14,"Enable");
		delay(100);
		vehinh2(1250,80,1350,110,14,14,0,13,"Lock");
	}
	if(tt==1){
		vehinh2(1250,80,1350,110,9,9,0,13,"Lock");
		delay(100);
		vehinh2(1110,80,1240,110,14,14,0,14,"Enable");
	}
}

void SapXep_TheoID(NodeThe *&root_tmp,short &trangg){
	setbkcolor(15);
	setcolor(0);
	setlinestyle(0,0,1);
	settextstyle(6,0,1);
	TheDocGia *mangThe=new TheDocGia[DemNut(root_tmp)]; 
	short int n=0;
	char s[10]="";
	short j=0;
	DoCayVaoMang(root_tmp,mangThe,n);
	while(j<=trangg){
		DrawTable_DG(j,1400);		
		delay(0.00001);
		for(int i=0; i<10 && i< n-j*10; i++){
			outtextxy(380,200+40*i,"            ");
			outtextxy(610,200+40*i,"                                                ");
			outtextxy(960,200+40*i,"                   ");
			outtextxy(1110,200+40*i,"           ");
			outtextxy(1210,200+40*i,"                   ");
			
			outtextxy(380,200+40*i,itoa(mangThe[j*10+i].MaThe,s,10));		
			outtextxy(610,200+40*i,mangThe[j*10+i].Ho);			
			outtextxy(960,200+40*i,mangThe[j*10+i].Ten);			
			if(mangThe[j*10+i].Phai==0)		outtextxy(1110,200+40*i,"Nam");
			else if(mangThe[j*10+i].Phai==1)		outtextxy(1110,200+40*i,"Nu");
			if(mangThe[j*10+i].TrangThai==0)		outtextxy(1210,200+40*i,"Hoat dong");
			else if(mangThe[j*10+i].TrangThai==1)
				{	setfillstyle(1,15);
					setcolor(4);
					settextstyle(6,0,2);
					outtextxy(1210,200+40*i,"Khoa");
					setfillstyle(1,15);
					setcolor(0);
					settextstyle(6,0,1);
				}
		}
		j++;	
	}
	delete mangThe;
	mangThe=NULL;
}
void SapXep_TheoTen(NodeThe *&root_tmp,short &trang){
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	TheDocGia *mangThe=new TheDocGia[DemNut(root_tmp)];
	short int n=0;
	char s[10]="";
	short j=0;
	DoCayVaoMang(root_tmp,mangThe,n);
	quickSort(mangThe,0,n-1);
	while(j<=trang){
		DrawTable_DG(j,1600);
		delay(0.00001);
		for(int i=0; i<10 && i< n-j*10; i++){
//			if(mangThe[j*10+i].Ho!="XOADOCGIA"){
				outtextxy(380,200+40*i,"            ");
				outtextxy(610,200+40*i,"                                                ");
				outtextxy(960,200+40*i,"                   ");
				outtextxy(1110,200+40*i,"           ");
				outtextxy(1210,200+40*i,"                   ");
				outtextxy(380,200+40*i,itoa(mangThe[j*10+i].MaThe,s,10));		
				outtextxy(610,200+40*i,mangThe[j*10+i].Ho);			
				outtextxy(960,200+40*i,mangThe[j*10+i].Ten);			
				if(mangThe[j*10+i].Phai==0)		outtextxy(1110,200+40*i,"Nam");
				else if(mangThe[j*10+i].Phai==1)		outtextxy(1110,200+40*i,"Nu");
				if(mangThe[j*10+i].TrangThai==0)		outtextxy(1210,200+40*i,"Hoat dong");
				else if(mangThe[j*10+i].TrangThai==1)
					{	setfillstyle(1,15);
						setcolor(4);
						settextstyle(6,0,2);
						outtextxy(1210,200+40*i,"Khoa");
						setfillstyle(1,15);
						setcolor(0);
						settextstyle(6,0,1);
					}
//			}
		}
		j++;	
	}
	delete mangThe;
	mangThe=NULL;
}
void ScanTree(short int &flag, NodeThe *&root_tmp,short &trang){
	
	if(flag%2==0){
		SapXep_TheoTen(root_tmp,trang);	
	}
	else{
		SapXep_TheoID(root_tmp,trang);
	}
}
void DocFile_DG( NodeThe* &root){	
	fstream dg;	
//	int demfile=0;
	dg.open("Data_DocGia.txt",ios::in);
		if(dg.fail()){
			
			return ;
		}
		string luutam;				
		while(!dg.eof()){	
			TheDocGia member;
			dg>>member.MaThe;	getline(dg,luutam,'\n');	
			dg>>member.TrangThai;	getline(dg,luutam,'\n');
			dg>>member.SLMuon;	getline(dg,luutam,'\n');		
			dg>>member.Phai;	getline(dg,luutam,'\n');	
			getline(dg,luutam,'\n');						
			strcpy(member.Ho, luutam.c_str());	getline(dg,luutam,'\n');	
			strcpy(member.Ten,luutam.c_str()); 							
			InsertDG(member,root);
		}
		dg.close();
}
void GhiFile_DocGia(NodeThe *&node_temp) {
	ofstream outfile("Data_DocGia.txt",ios::app);
	outfile<<"\n"<<node_temp->member.MaThe<<"\n";
	outfile<<node_temp->member.TrangThai<<"\n";
	outfile<<node_temp->member.SLMuon<<"\n";
	outfile<<node_temp->member.Phai<<"\n";
	outfile<<node_temp->member.Ho<<"\n";
	outfile<<node_temp->member.Ten;
	outfile.close();
}

void Pretrav(NodeThe *&root){	
	NodeThe *Stack[_SIZE_DG];
	int sp= -1;
	ofstream outfile("Data_DocGia.txt");
	outfile<<"";
	NodeThe* p= root;
	while(p!=NULL ){
		GhiFile_DocGia(p);
		if(p->R!=NULL){
			Stack[++sp]=p->R;
		}
		if(p->L!=NULL){
			p=p->L;
		}
		else if(sp==-1){
			break;
		}
		else	p=Stack[sp--];
	}
	outfile.close();
}


void TimKiemDG(int id_tk, NodeThe *&root_tmp, char ho[], char ten[]){
	TheDocGia member;
	New_BoxDG(member.Ho,member.Ten);
	NodeThe *p=SearchDG(id_tk,root_tmp);
	if(SearchDG(id_tk,root_tmp)==0 || strcmp(p->member.Ho,"XOADOCGIA")==0){
		BaoLoi("Khong tim thay!");
		return ;
	}
	else{
		NodeThe *p=SearchDG(id_tk,root_tmp);
		delay(0.0001);
		FixDel_DocGia();
		char s[7];
		short i;
		NodeMuonTra *chay=p->member.first; 
		if(p->member.TrangThai==0)	TrangThai(0);
		else if(p->member.TrangThai==1)	TrangThai(1);
		if(p->member.Phai==0)	GioiTinh(0);
		else if(p->member.Phai==1)	GioiTinh(1);
		vehinh2(575,112,690,140,3,3,0,-5,"");
		vehinh2(315,115,415,145,3,3,0,-5,"");
		vehinh2(310,615,460,650,3,3,0,-5,"");
		vehinh2(1300,615,1445,650,3,3,0,-5,"");
		vehinh2(740,20,840,48,3,3,0,-5,"");
		setidchovung(485, 80, 560, 110,-5);
		setidchovung(565, 80, 640, 110,-5);
		setidchovung(1250,80,1350,110,-5);
		setidchovung(1110,80,1240,110,-5);
		setbkcolor(15);
		setcolor(0);
		settextstyle(6,0,1);
		barcovien(481,20,735,48,-5);
		barcovien(481,50,840,78,-5);	// Khoang trang Ho
		barcovien(1000,50,1440,78,-5);		// ten
		outtextxy(484,52,p->member.Ho);	strcpy(ho,p->member.Ho);
		outtextxy(1003,52,p->member.Ten); strcpy(ten,p->member.Ten);
		outtextxy(490,22,itoa(p->member.MaThe,s,10));
		for(i=0;chay!=NULL; chay=chay->next){	
				if(chay->muontra.TrangThai==0){
					outtextxy(375,245+120*i,chay->muontra.MaSach);
					outtextxy(610,245+120*i,chay->muontra.NgayMuon);
					outtextxy(815,245+120*i,"Chua tra");
					i++;
				}
				else if(chay->muontra.TrangThai==3){
					outtextxy(375,245+120*i,chay->muontra.MaSach);
					outtextxy(610,245+120*i,chay->muontra.NgayMuon);
					outtextxy(815,245+120*i,"Qua han");
					i++;
				}			
		}
	}
}
void XoaNode(){
	Yes_No("Ban da chac chan?");	
	vehinh2(30,470,130,500,12,12,15,1820,"YES");
	vehinh2(180,470,280,500,12,12,15,1821," NO");
	vehinh(20,25,290,80,12,12,0,-5,"QUAN LY DOC GIA");
	vehinh(20,100,290,155,12,12,15,-5,"QUAN LY MUON TRA");
	vehinh(20,175,290,230,12,12,15,-5,"QUAN LY DAU SACH");
	setlinestyle(0,0,2);
	rectangle(1100,400,1325,455);
	setlinestyle(0,0,1);
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}
void Fix_DocGia(){
	vehinh2(1100,400,1325,455,4,4,0,1812,"LUU THAY DOI");
	vehinh2(1250,80,1350,110,14,14,0,1822,"Lock"); //id 13
	vehinh2(1110,80,1240,110,14,14,0,1823,"Enable");
	setidchovung(481,50,840,78,1813);
	setidchovung(1000,50,1440,78,1814);
	vehinh2(485, 80, 560, 110,14,14,0,1815,"NAM");
	vehinh2(565, 80, 640, 110,14,14,0,1816,"NU");
}
void LuuThayDoi(char ho[],char ten[],int &phai,int &trangthai,int mathe,NodeThe *&root_tmp){
	NodeThe *p=SearchDG(mathe,root_tmp);
	if(strcmp(ho,"")!=0 && strcmp(ten,"")!=0&&trangthai!=-1&&phai!=-1){
		strcpy(p->member.Ho,ho); 
		strcpy(p->member.Ten,ten);	
		p->member.Phai=phai;
		p->member.TrangThai=trangthai;
		BaoLoi("Thay doi xong");
	}
	else{
		BaoLoi("Con thieu thong tin");
		setidchovung(485, 80, 560, 110,-5);
		setidchovung(565, 80, 640, 110,-5);
		setidchovung(1250,80,1350,110,-5);
		setidchovung(1110,80,1240,110,-5);
		setidchovung(481,50,840,78,-5);
		setidchovung(1000,50,1440,78,-5);
		return;
	}

}
void Sure_XoaNode(int mathe,NodeThe *&root_tmp, short &flag_yesno){
	if(flag_yesno==0){
		NodeThe *p=SearchDG(mathe,root_tmp);
		if(p!=0){
			short count=0;
			if(p->member.first!=NULL){
				NodeMuonTra *chay;
				for(chay=p->member.first; chay!=NULL;chay=chay->next){
					if(chay->muontra.TrangThai==0) count++;
				}	
				if(count!=0){
					BaoLoi("Khong the xoa doc gia");
					return;
				}
				else{
					strcpy(p->member.Ho,"XOADOCGIA");
					p->member.TrangThai=-1; // Trang thai khong ton tai 
					BaoLoi("Xoa doc gia thanh cong");
					return;
				}
			}
			else{
				strcpy(p->member.Ho,"XOADOCGIA");
				p->member.TrangThai=-1; // Trang thai khong ton tai 
				BaoLoi("Xoa doc gia thanh cong");
				return;
			}
		}
	}
}
void DK_Nhap_NXB(int nxb){
	if(nxb>2021 ){
		BaoLoi("NXB khong hop le");
		return;
	}
}
void DK_Nhap_soluong(int soluong){
	if(soluong>MAXSIZE_DMS ){
		BaoLoi("So luong khong hop le");
		return;
	}
}
//============================================================================================================
//============================================================================================================


void GhiFile_MuonTra(NodeThe *&root_tmp){	
	ofstream Fout;
	Fout.open("Data_MuonTra.txt", ios::out);
	TheDocGia *mangThe=new TheDocGia[DemNut(root_tmp)];
	short n=0;
	DoCay(root_tmp,mangThe,n);  
	NodeMuonTra *chay;
	for(int i=0; i<n; i++){	
		for(chay=mangThe[i].first; chay!=NULL; chay=chay->next){
			Fout<<"\n"<<mangThe[i].MaThe<<"\n";	
			Fout<<chay->muontra.TrangThai<<"\n";
			Fout<<chay->muontra.Time_Muon<<"\n";
			Fout<<chay->muontra.Time_Tra<<"\n";
			Fout<<chay->muontra.MaSach<<"\n";
			Fout<<chay->muontra.NgayMuon<<"\n";	
			Fout<<chay->muontra.NgayTra;
		}	
	}
	Fout.close();
	delete mangThe;
	mangThe=NULL;
}
void DocFile_MuonTra(NodeThe *&nodegoc,short &DemSach_mt){
	fstream Fin;
	Fin.open("Data_MuonTra.txt",ios::in);
	if(Fin.fail()){
		BaoLoi("Loi file MT");
		return;
	}
	NodeThe *tmp;
	string luutam;
	int mathe;
	DemSach_mt=0;
		while(!Fin.eof()){
			mathe=0;
			MuonTra mt;
			Fin>>mathe;	getline(Fin,luutam,'\n');	
					tmp=SearchDG(mathe,nodegoc);	
			Fin>>mt.TrangThai;	getline(Fin,luutam,'\n');
			Fin>>mt.Time_Muon;	getline(Fin,luutam,'\n');
			Fin>>mt.Time_Tra;	getline(Fin,luutam,'\n');
			getline(Fin,luutam,'\n');
			strcpy(mt.MaSach,luutam.c_str());	getline(Fin,luutam,'\n');
			strcpy(mt.NgayMuon,luutam.c_str());	getline(Fin,luutam,'\n');
			strcpy(mt.NgayTra,luutam.c_str());		
			InsertTailMuonTra(mt,tmp->member.first);
			DemSach_mt++;	
		}
	Fin.close();
}
int InMaThe(NodeThe *&root, char *masach_muon){
	TheDocGia *mang=new TheDocGia[DemNut(root)];
	short n=0;
	DoCay(root,mang,n);
	NodeMuonTra *chay;
	for(int i=0; i<n; i++){
		for(chay=mang[i].first; chay!=NULL; chay=chay->next){
			if(strcmp(chay->muontra.MaSach,masach_muon)==0&&chay->muontra.TrangThai!=1)	return mang[i].MaThe;
		}
	}
	return 0;
	delete mang;
	mang=NULL;
}
int InMaTheQH(NodeThe *&r, char *masach_muon){
	TheDocGia *mang=new TheDocGia[DemNut(r)];
	short n=0;
	DoCay(r,mang,n);
	NodeMuonTra *chay;
	for(int i=0; i<n; i++){
		for(chay=mang[i].first; chay!=NULL; chay=chay->next){
			if(strcmp(chay->muontra.MaSach,masach_muon)==0)	return mang[i].MaThe;
		}
	}
	return 0;
	delete mang;
	mang=NULL;
}
void List_mt(NodeThe *&root_tmp,MuonTra *arr,short &soluong){
	NodeMuonTra *chay;
	if(root_tmp==NULL)	return;
	else{
		if(root_tmp->member.first!=NULL && strcmp(root_tmp->member.Ho,"XOADOCGIA")!=0){
			for(chay=root_tmp->member.first; chay!=NULL; chay=chay->next){
				if(chay->muontra.TrangThai!=1) arr[soluong++]=chay->muontra;
			}	
		}
		List_mt(root_tmp->L,arr,soluong);
		List_mt(root_tmp->R,arr,soluong);
	}
}
void List_mt_QH(NodeThe *&root_tmp,MuonTra *arr,short &soluong){
	NodeMuonTra *chay;
	if(root_tmp==NULL)	return;
	else{
		if(root_tmp->member.first!=NULL && strcmp(root_tmp->member.Ho,"XOADOCGIA")!=0){
			for(chay=root_tmp->member.first; chay!=NULL; chay=chay->next){
				arr[soluong++]=chay->muontra;
			}	
		}
		List_mt_QH(root_tmp->L,arr,soluong);
		List_mt_QH(root_tmp->R,arr,soluong);
	}
}
void swapMuonTra(MuonTra* a, MuonTra *b){
	MuonTra c=*a;
	*a=*b;
	*b=c;
}
int Patition_DSMT(MuonTra *a, int l, int h){
	MuonTra Pi=a[h];
	int i=l-1;
	for(int j=l; j<=h-1;j++){
		if(a[j].Time_Muon<Pi.Time_Muon){
			i++;
			swapMuonTra(&a[i],&a[j]);
		}
	}
	swapMuonTra(&a[i+1],&a[h]);
	return i+1;
}
void Quicksort_DSMT(MuonTra *a, int l, int h){
	if(l<h){
		int pi=Patition_DSMT(a,l,h);
		Quicksort_DSMT(a,l,pi-1);
		Quicksort_DSMT(a,pi+1,h);
	}
}
void Scan_DSMT(NodeThe *&root_tmp,short &trang_mt,List &DSDS){
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	MuonTra *mangMT= new MuonTra[_SIZE_DG];
	short int n=0;
	char s[10]="";
	short j=0;
	short int m;
	short i=0;
	int mathe;
	short TKSach;
	List_mt(root_tmp,mangMT,n);
	Quicksort_DSMT(mangMT,0,n-1);
	while(j<=trang_mt){	
		DrawTable_MT(j);
		delay(0.00001);		
		for(m=0; m<10 && m< n-j*10&& i<n; m++){ 
				outtextxy(375,200+40*m, mangMT[i].MaSach);
				mathe=InMaThe(root_tmp,mangMT[i].MaSach);
				if(mathe!=0) outtextxy(520,200+40*m, itoa(mathe,s,10));
				mathe=0;
				TKSach=TimKiemSach(mangMT[i].MaSach,DSDS);
				if(TKSach !=-1)	outtextxy(653,200+40*m,DSDS.node[TKSach]->TenSach);
					outtextxy(1012,200+40*m, mangMT[i].NgayMuon);
					outtextxy(1177,200+40*m, mangMT[i].NgayTra);	
				if(mangMT[i].TrangThai==0){
					setfillstyle(1,15);
					setcolor(1);
					outtextxy(1337,200+40*m,"Chua tra");
				}
				else if(mangMT[i].TrangThai==2)	{ 
					setfillstyle(1,15);
					setcolor(8);
					outtextxy(1339,200+40*m,"Lam mat");				
				}
				else if(mangMT[i].TrangThai==3){
					setfillstyle(1,15);
					setcolor(4);
					outtextxy(1337,200+40*m,"Qua han");
				}
			setfillstyle(1,15);
			setcolor(0);
			i++;			
		}		
	j++;
	}
	delete mangMT;
	mangMT=NULL;		
}

void ScanDSDG_QUAHAN(NodeThe *&root_tmp,short &trang_dgqh,short &k,List &DSDS){
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
	MuonTra *mangMT= new MuonTra[_SIZE_DG];
	k=0;
	short n=0;
	char s[10]="";
	short int m,i;
	i=0;
	int mathe;
	NodeThe *p;
	short TKSach;
	char luutam[20]="";
	List_mt_QH(root_tmp,mangMT,n);
	MuonTra *QH = new MuonTra[n];		 
	for(int j=0; j<n; j++){	
		if(mangMT[j].TrangThai==3){	
			QH[k++]=mangMT[j];
			QH[k].Time_Tra=Time_FromTo(); 
		}
		else if(mangMT[j].TrangThai==1 &&mangMT[j].Time_Tra-mangMT[j].Time_Muon > TIME_QH){
			QH[k++]=mangMT[j];	
			QH[k].Time_Tra=mangMT[j].Time_Tra;
		}	
	}
	for(int x=0; x<k; x++){
		for(int y=x+1;y<k;y++){
			if(Time_FromTo()-QH[x].Time_Muon <Time_FromTo()-QH[y].Time_Muon){ 
				swapMuonTra(&QH[x],&QH[y]);
			}
		}
	}
	short h=0;	
	while(h<=trang_dgqh){	
		Draw_DSDG_QUAHAN(h); 
		delay(0.00001);	
		for(m=0; m<10 && m<k-h*10 && i<k; m++){
				if(QH[i].TrangThai==1){
					setcolor(2);
					outtextxy(375,200+40*m, QH[i].MaSach);
					mathe=InMaTheQH(root_tmp,QH[i].MaSach);
					if(mathe!=0) outtextxy(520,200+40*m, itoa(mathe,s,10));	
					TKSach=TimKiemSach(QH[i].MaSach,DSDS);
					if(TKSach !=-1)	outtextxy(653,200+40*m,DSDS.node[TKSach]->TenSach);
					outtextxy(1012,200+40*m, QH[i].NgayMuon);
					p=SearchDG(mathe,root_tmp); mathe=0;
					strcpy(luutam,p->member.Ho);
					outtextxy(1168,200+40*m, strcat(strcat(p->member.Ho," "),p->member.Ten));	
					strcpy(p->member.Ho,luutam); p=NULL;
					i++;
				}
				else{
					setcolor(0);
					outtextxy(375,200+40*m, QH[i].MaSach);
					mathe=InMaTheQH(root_tmp,QH[i].MaSach);
					if(mathe!=0) outtextxy(520,200+40*m, itoa(mathe,s,10));	
					TKSach=TimKiemSach(QH[i].MaSach,DSDS);
					if(TKSach !=-1)	outtextxy(653,200+40*m,DSDS.node[TKSach]->TenSach);
					outtextxy(1012,200+40*m, QH[i].NgayMuon);
					p=SearchDG(mathe,root_tmp); mathe=0;
					strcpy(luutam,p->member.Ho);
					outtextxy(1168,200+40*m, strcat(strcat(p->member.Ho," "),p->member.Ten));	
					strcpy(p->member.Ho,luutam); p=NULL;
					i++;
				}
			}
			h++;
		}
	delete mangMT;
	mangMT=NULL;
	delete QH;
	QH=NULL;
}

void InDG_theoMT(int id_mt,NodeThe *&root_tmp){
	char luutam[20];
	NodeThe *p=SearchDG(id_mt,root_tmp);
	if(SearchDG(id_mt,root_tmp)==0 || strcmp(p->member.Ho,"XOADOCGIA")==0){
		BaoLoi("Khong tim thay!");
		id_mt=0;
		return ;
	}
	else{
		if(p->member.TrangThai==1){
			BaoLoi("The dang bi khoa!");
			return;
		}
		else if(p->member.TrangThai==0){
			if(p->member.SLMuon>=3){
				BaoLoi("Muon toi da 3 cuon");
				return;
			}
			else{
				barcovien(1000,20,1440,48,-5);
				strcpy(luutam,p->member.Ho);
				outtextxy(1003,22,strcat(strcat(p->member.Ho," "),p->member.Ten));
				strcpy(p->member.Ho,luutam);
			}
		}
	}
}
void InMS_theoTen(List &DSDS, char *tensach_inMS,char *masach_mt){
	short find_ds = timkiem(DSDS,tensach_inMS); 
	if(find_ds== -1 ){
		BaoLoi("Khong tim thay!");	
		return;
	}
	else{	
		NodeSach *tmp=TimKiem_theoTT(DSDS.node[find_ds]->first); 
		if(tmp==0)	{
			BaoLoi("Khong tim thay!");
			return;
		}
		else{	
			barcovien(501,50,840,78,-5);
			outtextxy(505,52,tmp->sach.MaSach);	
			if(strcmp(tmp->sach.MaSach,"")!=0) strcpy(masach_mt ,tmp->sach.MaSach);
			else{
				BaoLoi("Da het sach trong");
				strcpy(tensach_inMS,"");
				return;
			}	
		}
		
	}
}

void ThemSach_muon(NodeThe *&root_tmp,char *tensach, int mathe,List &DSDS, short &DemSach_mt){
	if(SearchDG(mathe,root_tmp)==0){
		BaoLoi("Khong the muon");
		return;
	}
	else{
		NodeThe *tmp = SearchDG(mathe,root_tmp);	
		if(strcmp(tmp->member.Ho,"XOADOCGIA")==0){
			BaoLoi("DG khong ton tai");
			return;
		}
		else{
			if(tmp->member.SLMuon<3){
				short find_ds = timkiem(DSDS,tensach);
				NodeSach *temp=TimKiem_theoTT(DSDS.node[find_ds]->first);
				MuonTra mt;
				NgayMuon(mt);
				strcpy(mt.MaSach,temp->sach.MaSach);
				mt.TrangThai=0;
				mt.Time_Muon=Time_FromTo(); 
				mt.Time_Tra=Time_FromTo();
				InsertTailMuonTra(mt,tmp->member.first);		
				ThayTTSach(DSDS,tensach,temp->sach.MaSach);	
				DemSach_mt++;	
				tmp->member.SLMuon++;
				DSDS.node[find_ds]->soluotmuon++;
				BaoLoi("Muon thanh cong!");
			}
		}
	}
}
void TraSach(NodeThe *&nodegoc, int matheTra, char *masachTra,List &DSDS){
	NodeThe* tmp=SearchDG(matheTra,nodegoc);
	if(SearchDG(matheTra,nodegoc)==0 || strcmp(tmp->member.Ho,"XOADOCGIA")==0 ){
		BaoLoi("Sai ma the doc gia");
		return;
	}
	else{
		MuonTra mt;
		NgayTra(mt);
		NodeMuonTra *chay;    
		for(chay=tmp->member.first; chay!=NULL; chay=chay->next){   
			if(strcmp(masachTra, chay->muontra.MaSach)==0 && chay->muontra.TrangThai!=2 &&chay->muontra.TrangThai!=1){ 
				chay->muontra.TrangThai=1;	
				strcpy(chay->muontra.NgayTra,mt.NgayTra);
				chay->muontra.Time_Tra=Time_FromTo();
				tmp->member.SLMuon--; 
				short f=TimKiemSach(masachTra,DSDS);
				if(f!=-1){
					NodeSach *run;
					for(run=DSDS.node[f]->first; run!=NULL; run=run->next){
						if(strcmp(run->sach.MaSach,masachTra)==0){
							run->sach.TrangThai=0;
							break;
						}
					}
				}
				BaoLoi("Tra sach xong!");
				return;
			}
		}
				BaoLoi("Khong the tra sach");
				return;
	}
}
void MatSach(NodeThe *&nodegoc, int matheTra, char *masachTra,List &DSDS){
	NodeThe* tmp=SearchDG(matheTra,nodegoc);
	if(SearchDG(matheTra,nodegoc)==0 || strcmp(tmp->member.Ho,"XOADOCGIA")==0 ){
		BaoLoi("Sai ma the doc gia");
		return;
	}
	else{
		MuonTra mt;
		NgayTra(mt);
		NodeMuonTra *chay=tmp->member.first;
		while(chay!=NULL){
			if(strcmp(masachTra, chay->muontra.MaSach)==0&&chay->muontra.TrangThai==0){ 
				chay->muontra.TrangThai=2;	 // mat
				strcpy(chay->muontra.NgayTra,mt.NgayTra);
				chay->muontra.Time_Tra=Time_FromTo();
				tmp->member.SLMuon--;
				short f=TimKiemSach(masachTra,DSDS);
				if(f!=-1){
					NodeSach *run;
					for(run=DSDS.node[f]->first; run!=NULL; run=run->next){
						if(strcmp(run->sach.MaSach,masachTra)==0){
							run->sach.TrangThai=2; // thanh ly
							break;
						}
					}
				}
				BaoLoi("Xong!");
				return;
			}
		chay=chay->next;
		}
				BaoLoi("Thao tac that bai!");
				return;
	}
}
void DocGiaQuaHan(unsigned long Auto_time, NodeThe *root_tmp){
	if(root_tmp !=NULL && strcmp(root_tmp->member.Ho,"XOADOCGIA")!=0){
		NodeMuonTra *chay;
		for(chay=root_tmp->member.first;chay!=NULL; chay=chay->next){
			if(Auto_time - chay->muontra.Time_Muon> TIME_QH){
				if(chay->muontra.TrangThai==0){
					chay->muontra.TrangThai=3;
					root_tmp->member.TrangThai=1;
				}
			}
		}
		DocGiaQuaHan(Auto_time,root_tmp->L);
		DocGiaQuaHan(Auto_time,root_tmp->R);	
	}
}


void XuLyNut(List& DSDS, NodeThe *&root,TheDocGia &member,Sach &sach,NodeSach *first,MuonTra &mt){
	DoHoaa();
	BaoLoi("           READY!");
//	VeXe();
	char isbn[13]="";
	 char tensach[25]="";
	  char sotrang[10]="";
	   char tacgia[22]="";
	    char nxb[10]="";
		 char theloai[20]="";
		  int slm=0;
		   char sl[5]="";	   
//	Create_ID(root,210500); Tao ra Mathe
	DocFile_DG(root);
	DocFile_DauSach(DSDS);
	DocFile_DMS(DSDS);
	short dem_muontra;
	DocFile_MuonTra(root,dem_muontra);
	DocGiaQuaHan(Time_FromTo(),root);
	short int up=0;
	short int dem=DemNut(root);
	strcpy(member.Ho,"");
	strcpy(member.Ten,"");
//	int Fix_TrangThai;
	member.MaThe=0;
	member.Phai=-1;
	member.SLMuon=0;
	char TimKiemID[12]="";
	char ho_fix[25]="";
	char ten_fix[10]="";
	int phai_fix=-1;
	int trangthai_fix=-1;
	NodeThe *ptmp;
	char vitri[20]="";
	char id_dg_mt[6]="";
	char tensach_mt[30]="";
	char masach_mt[14]="";
	char mathe_tra[6]="";
	char masach_tra[14]="";
	char temp_dg[7]="";
	short int phai;
	short int tt;	
//	int mathe;
	int size;
	int arr[20];
	int x=-1,y=-1;
	int id=-5;
	int pos=0;
	int FindTree;
	short int n_mangDG=0;
	short soluong_muon=0;
	short demDauSach=DSDS.n;
	short demDG_QH=0;
	TheDocGia *mang = new TheDocGia[_SIZE_DG];
	DoCayVaoMang(root,mang,n_mangDG); 
	MuonTra *arr_mt= new MuonTra[_SIZE_DG];
	short flag_YesNo=-1;
	short Ten_ID=1;
	short trang_ds=0;
	short trang_dg=0;
	trang_dg=(dem-1)/10;
	short trang_dms=0;
	short trang_mt=(dem_muontra-1)/10;
	short trang_dgqh=(demDG_QH-1)/10;	
	short tt_sach;
	char find_tensach[25]="";		
		while(true){
			delay(0.0001);
			id=0;
			if(kbhit()){
				char c=getch();
			}
			if (ismouseclick(WM_LBUTTONDOWN)){
 			getmouseclick(WM_LBUTTONDOWN, x, y);	
 			id =MapID[x][y];
 			std::cout<<"id: "<<id<<std::endl;
 			clearmouseclick(WM_LBUTTONDOWN);
 			}
 			if(MapID[x][y]==104){
 				Pretrav(root);
 				GhiFile_DauSach(DSDS);
 				GhiFile_DMS(DSDS);
 				GhiFile_MuonTra(root);
 				DeleteMemoryDocGia(root);
 				DeleteAllDauSach(DSDS);
 				break;
			}
				
 			switch(id){
			 	case 1:
			 		Press(20,25,290,80);
			 		PageDocGia();
			 		strcpy(TimKiemID,"");
			 		SapXep_TheoID(root,trang_dg);
			 		break;
			 	case 2:
			 		Press(20,100,290,155);
			 		PageMuonTra();
			 		strcpy(mathe_tra,"");strcpy(masach_tra,"");
			 		Scan_DSMT(root,trang_mt,DSDS);
					break;
				case 3:
					Press(20,175,290,230);
					PageDauSach();
					strcpy(find_tensach,"");
					scanDSDS(DSDS,trang_ds);
					break;
	 			case 4:
	 				Press(30,470,130,500);
	 				Che_YesNo();
	 				flag_YesNo=0;	// Yes
					break;
				case 5:
					Press(180,470,280,500);
					Che_YesNo();
					flag_YesNo=1;	//No
					break;
// ==============================================MUON TRA=====================================================		
				case 31: // Nut MUON
					Press(575,112,690,140);
					if(strlen(id_dg_mt)!=0 &&strlen(tensach_mt)!=0 &&atoi(id_dg_mt)!=0){
						ThemSach_muon(root,tensach_mt,atoi(id_dg_mt),DSDS,dem_muontra);
						soluong_muon=0;
						List_mt(root,arr_mt,soluong_muon);
						trang_mt=(dem_muontra-1)/10; 
						strcpy(masach_mt,"");
						strcpy(id_dg_mt,"");
						Box_MuonTra();
						Scan_DSMT(root,trang_mt,DSDS);
					}
					else BaoLoi("Thong tin chu du");
					break;
				case 187: //BACK MuonTra
					Press(310,615,460,650);
					if(trang_mt >0){
						trang_mt--;
						Scan_DSMT(root,trang_mt,DSDS);
					}
					break;
				case 188: // NEXT MuonTra
					Press(1300,615,1445,650);
					if((dem_muontra-1)/10 > trang_mt){
						trang_mt++; 
						Scan_DSMT(root,trang_mt,DSDS);
					} 
					break;
				case 189:
					Press(1195,82,1430,110);
					trang_dgqh=(demDG_QH-1)/10;
					ScanDSDG_QUAHAN(root,trang_dgqh,demDG_QH,DSDS);
					break;
				case 190: // Back DGQH
					Press(310,615,460,650);
					if(trang_dgqh>0){
						trang_dgqh--;
						ScanDSDG_QUAHAN(root,trang_dgqh,demDG_QH,DSDS);
					}
					break;
				case 191: // Next DGQH
					Press(1300,615,1445,650);
					if((demDG_QH-1)/10>trang_dgqh){
						trang_dgqh++;
						ScanDSDG_QUAHAN(root,trang_dgqh,demDG_QH,DSDS);
					}
					break;
				case 185:
					barcovien(1090,112,1205,140,185);
					strcpy(mathe_tra,"");
					KT_NhapNums(1092,114,mathe_tra,6);
					break;
				case 184:
					barcovien(1225,112,1329,140,184);
					strcpy(masach_tra,"");
					KT_NhapCaplocks(1227,114,masach_tra,7);
					break;
				
				case 183:
					Press(1330,112,1430,140);
					if(strlen(masach_tra)!=0 && strlen(mathe_tra)!=0){
						TraSach(root,atoi(mathe_tra),masach_tra,DSDS);
						Scan_DSMT(root,trang_mt,DSDS);
						vehinh2(1225,112,1329,140,15,15,7,184,"MS");
						vehinh2(1090,112,1205,140,15,15,7,185,"MT");
						strcpy(mathe_tra,"");
						strcpy(masach_tra,"");
						setbkcolor(15);
						setcolor(0);
						settextstyle(6,0,1);
					}
					else BaoLoi("Chua nhap MT va MS");
					break;
				case 186: 
						Press(990,112,1089,140);
						if(strlen(masach_tra)!=0 && strlen(mathe_tra)!=0){
							MatSach(root,atoi(mathe_tra),masach_tra,DSDS);
							Scan_DSMT(root,trang_mt,DSDS);
							vehinh2(1225,112,1329,140,15,15,7,184,"MS");
							vehinh2(1090,112,1205,140,15,15,7,185,"MT");
							strcpy(mathe_tra,"");
							strcpy(masach_tra,"");
							setbkcolor(15);
							setcolor(0);
							settextstyle(6,0,1);
						}
						else BaoLoi("Chua nhap MT va MS");
						break;
				case 54:
						setcolor(0);
						barcovien(481,20,840,48,54);
						barcovien(1000,20,1440,49,53);
						strcpy(id_dg_mt,"");
						KT_NhapNums(483,22,id_dg_mt,7);
						InDG_theoMT(atoi(id_dg_mt),root);
						break;
				case 56: // masach_DS muontra
						barcovien(1000,50,1440,78,56);
						barcovien(501,50,840,78,55);
						strcpy(tensach_mt,"");
						KT_NhapHoTen(1003,52,tensach_mt,30);
						InMS_theoTen(DSDS,tensach_mt,masach_mt);
						break;
// ===========================================DOC GIA====================================================
				case 9:	// Nam	
					GioiTinh(0);
					member.Phai=0;
					break;
				case 11:	//Nu
					GioiTinh(1);
					member.Phai=1;
					break;	
				case 12:	// chi tiet
				//	DrawTable_DG_Muon(trang_mt);
					break;
//					case 14: // Mo
//						TrangThai(0);
//						Fix_TrangThai=0;
//						break;
//					case 13:	//khoa
//						TrangThai(1);
//						Fix_TrangThai=1;
//						break;		
				case 19:
					vehinh2(575,112,690,140,10,10,0,17,"THEM");
					vehinh2(740,20,840,48,10,10,0,-5,"NEW");
					Press(740,20,840,48);
					BoxInput_DG();
					New_BoxDG(member.Ho,member.Ten);
					barcovien(481,50,840,78,51);	// Khoang trang Ho
					barcovien(1000,50,1440,78,52); // ten
					barcovien(481,20,735,48,50); // mathe
					member.MaThe=-1;
					member.Phai=-1;
					member.TrangThai=0;	
				 	member.MaThe = ID(dem);
					dem++;	
					if(dem-DemNut(root)>0) dem--;					
					break;
				case 51:
						KT_NhapHoTen(484,52,member.Ho,20);
							break;		
						
				case 52:
						
						KT_NhapHoTen(1003,52, member.Ten,10);
							break;
				
				case 17:		// HAM THEM DOC GIA VA IN RA
						Press(575,112,690,140);	
						if(strlen(member.Ho)!=0 && strlen(member.Ten)!=0 &&member.MaThe!=0&&member.Phai!=-1){									
							InsertDG(member,root);dem=DemNut(root);
							n_mangDG=0;	
							DoCayVaoMang(root,mang,n_mangDG); 					
							trang_dg=(dem-1)/10;		
							BoxInput_DG();
							ScanTree(Ten_ID, root,trang_dg);
							BaoLoi("Them thanh cong!");
							vehinh2(740,20,840,48,10,10,0,19,"NEW");
						}
						else BaoLoi("Thieu thong tin");
						break;
				case 180:	//Loc doc gia
						Press(315,115,415,145);
						Ten_ID++;	
						ScanTree(Ten_ID, root,trang_dg);
						if(Ten_ID%2==0)	quickSort(mang,0,n_mangDG-1);
						else if(Ten_ID%2!=0)	quickSort_ID(mang,0,n_mangDG-1);
						break;
				case 181:	
						Press(1283,112,1440,140);	
						TimKiemDG(atoi(TimKiemID),root,ho_fix,ten_fix);
					//	vehinh2(410,552,1400,590,3,3,3,-5,"");
						//strcpy(TimKiemID,"");
						break;
				case 411: 
						barcovien(1100,112,1280,140,411);
						strcpy(TimKiemID,"");
						ScannerNums(1102,114,TimKiemID,7);
						if(strlen(TimKiemID)==0){
							setidchovung(1283,112,1440,140,-5);
							BaoLoi("Ban can nhap ma the");
						}
						else setidchovung(1283,112,1440,140,181);
						break;
				case 1810:
						Press(1100,200,1325,255);
						vehinh2(410,552,1400,590,3,3,3,-5,"");
						vehinh2(410,552,450,590,3,3,12,-5,"Hieu chinh-> Luu thay doi-> In danh sach");
						Fix_DocGia();
						break;
				case 1822:
						Press(1250,80,1350,110);
						TrangThai(1);
						trangthai_fix=1;
						break;
				case 1823:
						Press(1110,80,1240,110);
				 		TrangThai(0);
				 		trangthai_fix=0;
						break;
				case 1811:
						Press(1100,300,1325,355);
						vehinh2(410,552,450,590,3,3,12,-5,"Xoa doc gia-> In danh sach (Khong the xoa DG dang muon sach)");
						vehinh2(1100,400,1325,455,4,4,0,-5,"IN DANH SACH");
						XoaNode();
						break;
				case 1813: // ho
						KT_NhapHoTen(484,52,ho_fix,25);
				//		break;
				case 1814: // ten
						KT_NhapHoTen(1003,52,ten_fix,10);
						break;
				case 1815: // nam
						GioiTinh(0);
						phai_fix=0;
					 	break;
				case 1816: // nu
						GioiTinh(1);
						phai_fix=1;
						break;
				case 1812:
						Press(1100,400,1325,455);
						LuuThayDoi(ho_fix,ten_fix,phai_fix,trangthai_fix,atoi(TimKiemID),root);
						setidchovung(20,25,290,80,-5);
						setidchovung(20,100,290,155,-5);
						setidchovung(20,175,290,230,-5);
						vehinh2(1100,400,1325,455,4,4,0,18120,"IN DANH SACH");
						break;
				case 18120:
						Press(1100,400,1325,455);
						PageDocGia();
						ScanTree(Ten_ID,root,trang_dg);
						break;
				case 1819:
						Press(1100,400,1325,455);
    					Sure_XoaNode(atoi(TimKiemID),root,flag_YesNo);
    					PageDocGia();
    					n_mangDG=0;	
						DoCayVaoMang(root,mang,n_mangDG); 
    					ScanTree(Ten_ID,root,trang_dg);
    					break;
    			case 1820:
    					Che_YesNo();
    					flag_YesNo=0;
    					vehinh2(1100,400,1325,455,4,4,0,1819,"IN DANH SACH");
						setlinestyle(0,0,2);
						rectangle(1100,400,1325,455);
						setlinestyle(0,0,1);
						setbkcolor(15);
						setcolor(0);
						settextstyle(6,0,1);
    					break;
    			case 1821:
    					Che_YesNo();
    					flag_YesNo=1;
    					setidchovung(20,25,290,80,1);
						setidchovung(20,100,290,155,2);
						setidchovung(20,175,290,230,3);
						vehinh2(1100,400,1325,455,4,4,0,18120,"IN DANH SACH");
    					break;
				case 1022: //Back ben DocGia
						Press(310,615,460,650);
						if(trang_dg>0){
							trang_dg--;
							ScanTree(Ten_ID, root,trang_dg);
						}	
						break;
				case 1033: //Next ben DocGia
						Press(1300,615,1445,650);
						if((DemNut(root)-1)/10 > trang_dg ){
							trang_dg++;
							ScanTree(Ten_ID, root,trang_dg);
						}
						break;
// =======================================DANH MUC SACH==============================================							
				case 1020:	// back trong dms
						Press(310,615,460,650);
						trang_dms--;
						if(trang_dms<0)	trang_dms++;
						Scan_DMS(DSDS,find_tensach,trang_dms);
						break;
				case 1021:	// next trong dms
						Press(1300,615,1445,650);
						trang_dms++;
						if(trang_dms>2)	trang_dms--;
						Scan_DMS(DSDS,find_tensach,trang_dms);
						break;
				
// =======================================DAU SACH=================================================	

				case 44:
						KT_NhapCaplocks(623,22,isbn,10);
						break;
				case 42:
						KT_NhapHoTen(1024,22,tensach,22);	//ten sach
						break;
				case 45:
						KT_NhapHoTen(499,52,tacgia,20);
						break;
				case 43:
						KT_NhapString(1024,52,theloai,13);	// the loai
						break;
				case 46:
						KT_NhapNums(509,82,sotrang,8);	//so trang
						break;						
				case 47:	
						barcovien(831,80,945,110,47);
						KT_NhapNums(834,82,nxb,4);	//nxb
						DK_Nhap_NXB(atoi(nxb));
						break;
				case 48:
						barcovien(1031,80,1145,110,48);
						KT_NhapNums(1034,82,sl,2);
						DK_Nhap_soluong(atoi(sl));
						break;	
				case 49:
						KT_NhapString(1274,82,vitri,19);	// vi tri
							break;	
				case 102: //Back DauSach
						Press(310,615,460,650);
						if(trang_ds>0){
							trang_ds--;
							scanDSDS(DSDS,trang_ds);
						}
						break;	
				case 103: //Next DauSach
						Press(1300,615,1445,650);
						if((DSDS.n-1)/10 > trang_ds){
							trang_ds++;
							scanDSDS(DSDS,trang_ds);
						}		
						break;						
				case 410: 
						barcovien(970,112,1300,140,410); // CHE find
						strcpy(find_tensach,"");
						ScannerHoTen(973,114,find_tensach,25);
						if(strlen(find_tensach)==0){
							setidchovung(1305,112,1440,140,-5);
							BaoLoi("Ban can nhap ten sach");
						}
						else	setidchovung(1305,112,1440,140,172);
						break;
				case 172:
						Press(1305,113,1440,140);		
						if(strlen(find_tensach)!=0){
							Find_DS(DSDS,find_tensach);
							BoxInput_DS();	
							Scan_DMS(DSDS,find_tensach,0);
						}
						break;
				case 173:// TOP
						Press(315,115,415,145);
						DrawTable_Top_MT();
						Top_10Sach(DSDS);
						break;
				case 174:
						Press(700,112,800,140);
						XoaNodeDauSach(DSDS,find_tensach);							
						break;
				case 1740: // Yes DauSach
						Che_YesNo();
						Sure_XoaDauSach(DSDS,find_tensach);
						scanDSDS(DSDS,trang_ds);
						break;
				case 1741: // No DauSach
						Che_YesNo();
						scanDSDS(DSDS,trang_ds);
						break;
				case 175: // Quay lai page dau sach
						Press(310,615,500,650);
						PageDauSach();
						scanDSDS(DSDS,trang_ds);
						break;
				case 176: // New Dau Sach
						Press(380,20,475,48);
						scanDSDS(DSDS,trang_ds);
						strcpy(isbn,"");
						strcpy(tensach,"");
						strcpy(sotrang,"");
						strcpy(tacgia,"");
						strcpy(nxb,"");
						strcpy(theloai,"");
						strcpy(find_tensach,"");
						barcovien(1021,20,1440,48,42);	// TEN SACH
						barcovien(1021,50,1440,78,43);	// THE LOAI
						barcovien(621,20,840,48,44);	// dien isbn
						barcovien(496,50,840,78,45);	// dien tac gia
						barcovien(506,80,675,110,46);	//dien so trang
						setidchovung(831,80,945,110,47);	//dien nam xb
						setidchovung(1031,80,1145,110,48);	// dien sl
						barcovien(1271,80,1440,110,49);	// dien vi tri
						break;
				case 171://Save
						Press(575,113,690,140);
						DauSach tmp=dausach(isbn,tensach,atoi(sotrang),tacgia,atoi(nxb),theloai,atoi(sl));							
						if(strlen(isbn)!=0 && strlen(tensach)!=0 && strlen(tacgia)!=0 && strlen(theloai) &&
						strlen(sotrang)!=0 && strlen(nxb)!=0 &&strlen(sl)!=0 && tmp.NXB<2021 && tmp.soluong<=MAXSIZE_DMS ){
							AddDauSach(DSDS,tmp,vitri);	demDauSach=DSDS.n;
							trang_ds=(DSDS.n-1)/10;
							scanDSDS(DSDS,trang_ds);
							BaoLoi("Them thanh cong!");
						}
						else BaoLoi("Kiem tra lai thong tin");															
						break;
						
				}
// ============================================IF HIGHLIGHT==============================================================				
				if(id<1500 && id>1400){
						BoxInput_DG();		
						short inds=1;
						if(id%1400<=n_mangDG){		
							ScanTree(inds,root,trang_dg);
							Highlight(id%(1400+trang_dg*10)-1);
							setlinestyle(0,0,1);
							if(mang[id%1400-1].TrangThai==0)	TrangThai(0);
							else if(mang[id%1400-1].TrangThai==1)	TrangThai(1);
							if(mang[id%1400-1].Phai==0)	GioiTinh(0);
							else if(mang[id%1400-1].Phai==1)	GioiTinh(1);
							setbkcolor(15);
							setcolor(0);
							settextstyle(6,0,1);
							outtextxy(484,52,mang[id%1400-1].Ho);
							outtextxy(1003,52,mang[id%1400-1].Ten);
							outtextxy(490,22,itoa(mang[id%1400-1].MaThe,temp_dg,10));
							barcovien(1100,112,1280,140,411);
							outtextxy(1102,114,itoa(mang[id%1400-1].MaThe,temp_dg,10));
							strcpy(TimKiemID,itoa(mang[id%1400-1].MaThe,temp_dg,10));
							TimKiemDG(atoi(TimKiemID),root,ho_fix,ten_fix);
						}
				}	
				else if(id<1700 && id>1600){	
						BoxInput_DG();	
						short inds=2;
						if(id%1600<=n_mangDG){ 
							ScanTree(inds,root,trang_dg);
							Highlight(id%(1600+trang_dg*10)-1);
							setlinestyle(0,0,1);
							if(mang[id%1600-1].TrangThai==0)	TrangThai(0);
							else if(mang[id%1600-1].TrangThai==1)	TrangThai(1);
							if(mang[id%1600-1].Phai==0)	GioiTinh(0);
							else if(mang[id%1600-1].Phai==1)	GioiTinh(1);
							setbkcolor(15);
							setcolor(0);
							settextstyle(6,0,1);
							outtextxy(484,52,mang[id%1600-1].Ho);
							outtextxy(1003,52,mang[id%1600-1].Ten);
							outtextxy(490,22,itoa(mang[id%1600-1].MaThe,temp_dg,10));
							barcovien(1100,112,1280,140,411);
							outtextxy(1102,114,itoa(mang[id%1600-1].MaThe,temp_dg,10));						
							strcpy(TimKiemID,itoa(mang[id%1600-1].MaThe,temp_dg,10));
							TimKiemDG(atoi(TimKiemID),root,ho_fix,ten_fix);
						}
				}
				else if(id<1600 && id>1500){
					Box_MuonTra();
					soluong_muon=0;
					List_mt(root,arr_mt,soluong_muon);
					Quicksort_DSMT(arr_mt,0,soluong_muon-1);	
					char s[10]="";
					dem_muontra=soluong_muon;
					if(id%1500<=dem_muontra){
						int mathe_mt=0;
						Scan_DSMT(root,trang_mt,DSDS);
						Highlight(id%(1500+trang_mt*10)-1);
						setlinestyle(0,0,1);
						vehinh2(1225,112,1329,140,15,15,7,184,"MS");
						setcolor(0);
						settextstyle(6,0,1);
						outtextxy(1227,114,arr_mt[id%1500-1].MaSach); 
						mathe_mt=InMaThe(root,arr_mt[id%1500-1].MaSach);
						outtextxy(1092,114,itoa(mathe_mt,s,10));
						strcpy(masach_tra,arr_mt[id%1500-1].MaSach);
						strcpy(mathe_tra,itoa(mathe_mt,s,10));
					}
					
				}
				else if(id<1400 && id>1300){
					BoxInput_DS();
					char s[10]="";
					if(id%1300<=demDauSach){ 
						scanDSDS(DSDS,trang_ds);
						Highlight(id%(1300+trang_ds*10)-1);	
						setlinestyle(0,0,1);
						setcolor(0);
						barcovien(831,80,945,110,-5);
						barcovien(1031,80,1145,110,-5);
						barcovien(970,112,1300,140,410);
						outtextxy(1024,22,DSDS.node[id%1300-1]->TenSach);
						outtextxy(973,114,DSDS.node[id%1300-1]->TenSach);
							strcpy(find_tensach,DSDS.node[id%1300-1]->TenSach);
						outtextxy(1024,52,DSDS.node[id%1300-1]->TheLoai);
						outtextxy(624,22,DSDS.node[id%1300-1]->ISBN);
						outtextxy(499,52,DSDS.node[id%1300-1]->TacGia);
						outtextxy(508,82,itoa(DSDS.node[id%1300-1]->SoTrang,s,10));
						outtextxy(833,82,itoa(DSDS.node[id%1300-1]->NXB,s,10));
						outtextxy(1033,82,itoa(DSDS.node[id%1300-1]->soluong,s,10));
						outtextxy(1274,82,DSDS.node[id%1300-1]->first->sach.ViTri);
						setidchovung(970,112,1300,140,410);	// find- id: 410
						vehinh2(700,112,800,140,10,10,0,174,"HUY");
						
					}
				}
			clearmouseclick(WM_LBUTTONDOWN);
		}					
	delete arr_mt;
	arr_mt=NULL;	
	delete mang;
	mang=NULL;		 		
}
