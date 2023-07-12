#pragma once
//#include "DauSach.h"
#include "OutputData.h"

//const int MAX=100;
//const int MAXNUM=10;
//char key [50];
int MapID[1500][700];
void BaoLoi(char *er){	
	setbkcolor(11);
	setcolor(4);
	settextstyle(6,0,1);					
	outtextxy(30,350,er);
	delay(1000);
	outtextxy(30,350,"                                      ");
	setcolor(0);
	setbkcolor(15);
}

void ScannerCapslock(int px, int py, char s[], int limit){
	setcolor(0);
	setbkcolor(15);
	settextstyle(6,0,1);
	int l = strlen(s);
		
		s[l] ='|';
		s[l+1]='\0';
	outtextxy(px, py ,s);
	while(1)
	{
		delay(1);
	
		if(kbhit())
		{			
		char c = getch();
	std::	cout << (int) c<<std::endl;
	
			if(l<limit)
			{   
				if(c>='a'&& c<='z' || c>='A' && c<= 'Z' ){
					if(c>='a'&&c<='z'){
						c=c+'A'-'a';
					}
					s[l]=c;
					l++;
				}
				if(c>='0' && c<='9' || c=='_')
				{
					s[l] = c;
					l++;
				}
				if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
				if(c==13){
						s[l]='\0';
						break;
				}
				s[l+1]='\0';
				outtextxy(px,py,s);	
			}
			else{
		 	if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
		 	if(c==13){
						s[l]='\0';
						break;	
				}
		 }
				 
	}	
	 else{
			s[l]='|';
			delay(100);
			outtextxy(px,py,s);
			s[l]=' ';
			delay(100);
			outtextxy(px,py,s);	 
			}
		}	
				
}
void ScannerNums(int px, int py, char s[], int limit){
	setcolor(0);
	setbkcolor(15);
	settextstyle(6,0,1);
	int l = strlen(s);
		
		s[l] ='|';
		s[l+1]='\0';
	outtextxy(px, py ,s);
	char c;
	while(1)
	{
		delay(1);
		if(kbhit())
		{	
				
		 c = getch();
	std::	cout << (int) c<<std::endl;
	
			if(l<limit)
			{   
				
				if(c>='0' && c<='9')
				{
					if(l==0 && c=='0'){
						l--;
					}
					else{
						s[l] = c;
						l++;
					}
				}
				if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
				if(c==13){
						s[l]='\0';
						break;	
				}
					s[l+1]='\0';
					outtextxy(px,py,s);	
		 }
		 else{
		 	if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
		 	if(c==13){
						s[l]='\0';
						break;	
				}
		 }
		 
	}	
	 else{
			
			s[l]='|';
			delay(100);
			outtextxy(px,py,s);
			s[l]=' ';
			delay(100);
			outtextxy(px,py,s);	 
			}
	}
}
void ScannerString( int px, int py, char s[], int limit){
	setcolor(0);
	setbkcolor(15);
	settextstyle(6,0,1);
	
	int l = strlen(s);
		
		s[l] ='|';
		s[l+1]='\0';
	outtextxy(px, py ,s);
	
	while(1)
	{
		delay(1);
	
		if(kbhit())
		{			
		char c = getch();
	std::	cout << (int) c<<std::endl;
	
			if(l<limit)
			{   
				if((l==0))// viet hoa o dau cau
				{
					if(c<='z'&&c>='a') 
					c=c+'A'-'a';
					else
					c=c;
				}
				else if(c<='Z'&&c>='A')	
					c=c-'A'+'a';

				if(c>='a' && c<='z' || c>='A' && c<='Z' ||c>='0' && c<='9' || c=='_')
				{
					s[l] = c;
					l++;
				}
				if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
				if(c==13){
					if(s[l-1]==' ' ){ 
					l--;
					s[l]='\0';
					break;
					}
					else {
						s[l]='\0';
					break;
					}
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')	
				{ 
					s[l] = c;
					l++;
				}
				
					s[l+1]='\0';
					outtextxy(px,py,s);	
		 }	 
		 else{
		 	if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
		 	if(c==13){
						s[l]='\0';
						break;	
				}
		 }
	}	
	else{	
		s[l]='|';
		delay(100);
		outtextxy(px,py,s);
		s[l]=' ';
		delay(100);
		outtextxy(px,py,s);	 
		}
	}

}

void ScannerHoTen( int px, int py, char s[], int limit){
	setcolor(0);
	setbkcolor(15);
	settextstyle(6,0,1);
	int l = strlen(s);
		s[l] ='|';
		s[l+1]='\0';
	outtextxy(px, py ,s);
	
	while(1)
	{
		delay(1);
	
		if(kbhit())
		{			
		char c = getch();
	std::	cout << (int) c<<std::endl;
	
			if(l<limit)
			{   
				if((l==0)||s[l-1]==' ')// viet hoa o dau cau va sau khoang trang
				{
					if(c<='z'&&c>='a') 
					c=c+'A'-'a';
					else
					c=c;
				}
				else if(c<='Z'&&c>='A')	
					c=c-'A'+'a';

				if(c>='a' && c<='z' || c>='A' && c<='Z' )
				{
					s[l] = c;
					l++;
				}
				if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
				if(c==13){
					if(s[l-1]==' ' ){ 
					l--;
					s[l]='\0';
					break;
					}
					else {
						s[l]='\0';
					break;
					}
				}	
				if(l>0) if(s[l-1]!=' ' && c == ' ')	
				{
					s[l] = c;
					l++;
				}
					s[l+1]='\0';
					outtextxy(px,py,s);	
			 }
			 else{
		 	if(c==8){	
					s[l-1]=' ';
					if(l!=0){
						s[l-1]=' ';
						s[l]=' ';
						s[l+1]=' ';
						s[l+2]='\0';
						outtextxy(px,py,s);
						l--;
						}
					if(l==0){
						
						s[l]='|';
						delay(100);
						outtextxy(px,py,s);
						s[l]=' ';
						delay(100);
						outtextxy(px,py,s);
						}	
					}
		 	if(c==13){
						s[l]='\0';
						break;	
				}
		 	}
		}	 
	
	else{
			
		s[l]='|';
		delay(100);
		outtextxy(px,py,s);
		s[l]=' ';
		delay(100);
		outtextxy(px,py,s);	 
		}
	}

}
void setmapid(){
		for(int i=0; i<1500; i++){
			for(int j=0; j<700; j++){
				MapID[i][j]=0;
			}
		}
	}
void setidchovung(int x1, int y1, int x2, int y2, int id){
		for(int i=x1; i<x2; i++){
			for(int j=y1; j<y2; j++){
				MapID[i][j]=id;
			}
		}
	}
void vehinh(int x1, int y1, int x2, int y2, int maunen,int maunenchu, int mauchu, int id, char *nd){
	setfillstyle(1,maunenchu);
	bar(x1,y1,x2,y2);
	setidchovung(x1,y1,x2,y2,id);
	setcolor(mauchu);
	setbkcolor(maunen);
	outtextxy(x1+10, y1+20, nd);
}
void vehinh2(int x1, int y1, int x2, int y2, int maunen,int maunenchu, int mauchu, int id, char *nd){
	settextstyle(0,0,2);
	setfillstyle(1,maunenchu);
	bar(x1,y1,x2,y2);
	setidchovung(x1,y1,x2,y2,id);
	setcolor(mauchu);
	setbkcolor(maunen);
	outtextxy(x1+20, y1+6, nd);
}
void barcovien(int x1, int y1, int x2, int y2,int id){
	setfillstyle(1,15);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setidchovung(x1,y1,x2,y2,id);
}
void InSTT(short &page){	
	char s[5]="";
	for(int i=0; i<10; i++){
		setbkcolor(15);
		setcolor(0);
		settextstyle(0,0,2);
		outtextxy(322, 200+40*i, itoa(i+(page)*10+1,s,10));		
	}
}
void setIDTable(int x1,int y1, int x2, int y2, int id, short &page){
	setidchovung(x1,y1,x2,y2,id);
	barcovien(x1,y1,x2,y2,id);
	InSTT(page);
}
void Normal(){
	for(int i=0; i<11; i++){
		setcolor(0);
		setlinestyle(0,0,0);
		rectangle(315,150+40*i,1445,190+40*i);
	}
}
void Highlight(int y){
	setcolor(4);
	setlinestyle(0,0,2);
	rectangle(315,190+y*40,1445,230+40*y);
}
void DrawTable_DS(short &page){
	setfillstyle(1,3);
	barcovien(315,150,1445,190,-5);
	for(int i=1; i<11; i++){
		setIDTable(315, 150+40*i,1445,190+40*i, 1300+i+page*10,page);	// id: 130...
	   }
	setcolor(0);
	rectangle(315,150,370,590); //	STT
	rectangle(370,150,530,590);	//	ISBN
	rectangle(530,150,850,590);	// ten sach
	rectangle(850,150,1125,590);	// TEN TAC GIA
	rectangle(1125,150,1345,590);	// THE LOAI
	rectangle(1345,150,1445,590);	// NAM XUAT BAN
	setbkcolor(15);
	outtextxy(317,155, "STT");
	outtextxy(400,155, "ISBN");
	outtextxy(650,155, "TEN SACH");
	outtextxy(900,155, "TEN TAC GIA");
	outtextxy(1130,155, "THE LOAI");
	outtextxy(1350,155, "NXB");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}
void DrawTable_DMS(short &page){
	
	for(int i=0; i<11; i++){ 
		setIDTable(315, 150+40*i,1445,190+40*i, 1200+i+page*10,page);	// id: 130...
	   }
	setcolor(0);
	rectangle(315,150,370,590); //	STT
	rectangle(370,150,850,590);	//	MA SACH
	rectangle(850,150,1145,590);	// Vi tri
	rectangle(1145,150,1445,590);	// trang thai
	outtextxy(317,155, "STT");
	outtextxy(450,155, "MA SACH");
	outtextxy(870,155,"VI TRI");
	outtextxy(1250,155, "TRANG THAI");
	vehinh2(310,615,460,650,4,4,0,1020,"<< BACK");
	vehinh2(1300,615,1445,650,4,4,0,1021,"NEXT >>");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);	
}
void DrawTable_DG(short &page, short id){
	setfillstyle(1,3);
	barcovien(315,150,1445,190,-5);
	for(int i=1; i<11; i++){ 
		setIDTable(315, 150+40*i,1445,190+40*i, id+i+page*10,page);	
	   }
	setcolor(0);
	rectangle(315,150,370,590); //STT
	rectangle(370,150,600,590);	//ma the
	rectangle(600,150,950,590);	// ho va ten dem
	rectangle(950,150,1100,590);	// ten
	rectangle(1100,150,1200,590);	//phai
	rectangle(1200,150,1445,590);	// tinh trang
	setbkcolor(15);
	outtextxy(317,155, "STT");
	outtextxy(450,155, "MA THE");
	outtextxy(650,155, "HO VA TEN DEM");
	outtextxy(980,155, "TEN");
	outtextxy(1110,155, "PHAI");
	outtextxy(1250,155, "TINH TRANG");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}

void Press(int x1, int y1, int x2, int y2){
	setlinestyle(0,0,2);
	setcolor(0);
	rectangle(x1-1,y1-1,x2+1,y2+1);
	delay(100);
	setlinestyle(0,0,2);
	setcolor(3);
	rectangle(x1-1,y1-1,x2+1,y2+1);
	setlinestyle(0,0,0);
	setcolor(0);
}
void BoxInput_DS(){
	barcovien(970,112,1300,140,410);	// find- id: 410
	barcovien(1021,20,1440,48,-5);	// TEN SACH
	barcovien(1021,50,1440,78,-5);	// THE LOAI
	barcovien(621,20,840,48,-5);	// dien isbn
	barcovien(496,50,840,78,-5);	// dien tac gia
	barcovien(506,80,675,110,-5);	//dien so trang
	barcovien(831,80,945,110,-5);	//dien nam xb
	barcovien(1031,80,1145,110,-5);	// dien sl
	barcovien(1271,80,1440,110,-5);	// dien vi tri
	setbkcolor(15);
	setfillstyle(1,15);
	setcolor(7);
	settextstyle(6,0,1);
	outtextxy(973,116,"Nhap Ten Sach");
	outtextxy(1034,82,"<= 30");
	outtextxy(834,82,"< 2021");
	setcolor(0);
}
void BoxInput_DG(){
	barcovien(481,20,735,48,50);	//Khoang trang Mathe
	barcovien(481,50,840,78,-5);	// Khoang trang Ho
	barcovien(1000,50,1440,78,-5);
	barcovien(1100,112,1280,140,411);	// find- id: 411
	setbkcolor(15);
	setfillstyle(1,15);
	setcolor(7);
	settextstyle(6,0,1);
	outtextxy(1110,114,"Nhap Ma The");
	outtextxy(484,52,"Nhap ho va ten dem");
	outtextxy(484,22,"Ma the tu dong");
	outtextxy(1003,52,"Nhap Ten");
	setcolor(0);
}
void New_BoxDG(char *ho, char *ten){
	vehinh2(485, 80, 560, 110,14,14,0,9,"NAM");
	vehinh2(565, 80, 640, 110,14,14,0,11,"NU");
	vehinh2(1250,80,1350,110,14,14,0,-5,"Lock"); //id 13
	vehinh2(1110,80,1240,110,9,9,0,-5,"Enable");
	strcpy(ho,"");
	strcpy(ten,"");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}
void Box_MuonTra(){
	settextstyle(0,0,2);
	setcolor(0);
//	barcovien(1000,20,1440,49,53);	// hoten
	barcovien(481,20,840,48,54);	//mathe
//	barcovien(501,50,840,78,55);	// masach
	barcovien(1000,50,1440,78,56);		// ten sach
	setfillstyle(1,3);
	bar(1000,19,1442,50);
	bar(500,49,842,80);
	setbkcolor(15);
	setfillstyle(1,15);  // khoang mau TRANG
	setcolor(7);
	settextstyle(6,0,1);
	outtextxy(484,22,"Nhap Ma The");
	outtextxy(1003,52,"Nhap ten sach");
}
void PageDocGia(){
	setfillstyle(1,3);
	settextstyle(0,0,2);
	bar(312,12,1448,590);
	vehinh(20,25,290,80,12,12,0,1,"QUAN LY DOC GIA");
	vehinh(20,100,290,155,12,12,15,2,"QUAN LY MUON TRA");
	vehinh(20,175,290,230,12,12,15,3,"QUAN LY DAU SACH");
	setfillstyle(1,15);
	
	setfillstyle(1,3);
	bar(315,20,1445,150);
	bar(310,615,500,650); // che quay lai
	bar(999,19,1444,50);
	bar(1070,112,1280,140);	// khoang xanh gan CHI TIET
	setidchovung(315,20,1445,145,-5);
	setidchovung(1070,112,1280,140,-5);
	setidchovung(700,112,800,140,-5);
	setidchovung(310,615,500,650,-5); // che nut quay lai
	vehinh2(350,20,480,48,14,14,0,6,"MA THE");
	vehinh2(350,50,480,78,14,14,0,7," HO");
//	vehinh2(350,80,480,110,14,14,0,8,"PHAI");
	vehinh2(485, 80, 560, 110,14,14,0,-5,"NAM");
	vehinh2(565, 80, 640, 110,14,14,0,-5,"NU");
	vehinh2(1250,80,1350,110,14,14,0,-5,"Lock");
	vehinh2(1110,80,1240,110,14,14,0,-5,"Enable");
	vehinh2(850,80,1050,110,14,14,0,15,"TRANG THAI:");
	vehinh2(850,50,1000,78,14,14,0,16,"TEN: ");
	vehinh2(575,112,690,140,10,10,0,-5,"THEM");
//	vehinh2(700,112,835,140,10,10,0,18,"DELETE");
	vehinh2(740,20,840,48,10,10,0,19,"NEW");
//	vehinh2(845,20,1020,48,10,10,0,600,"Upgrade");	// upgrade mathe
	vehinh2(315,115,415,145,10,10,0,180,"Loc");
	vehinh2(1283,112,1440,140,10,10,0,181,"Chi tiet");
	setfillstyle(1,10);
	setbkcolor(13);
	setcolor(0);
	settextstyle(0,0,2);
	vehinh2(310,615,460,650,4,4,0,1022,"<< BACK");
	vehinh2(1300,615,1445,650,4,4,0,1033,"NEXT >>");
	
	BoxInput_DG();
}
void FixDel_DocGia(){
	setcolor(3);
	setfillstyle(1,3);
	bar(315,150,1446,596); // che table doc gia
	setidchovung(315,150,1446,596,-5);
	setidchovung(310,615,500,650,-5); // che nut quay lai
	vehinh2(1100,400,1325,455,4,4,0,-5,"LUU THAY DOI"); //1812
	vehinh2(1100,200,1325,255,15,15,12,1810,"HIEU CHINH");
	vehinh2(1100,300,1325,355,15,15,12,1811,"XOA DOC GIA");
	setlinestyle(0,0,2);
	rectangle(1100,400,1325,455);
	rectangle(1100,200,1325,255);
	rectangle(1100,300,1325,355);
	setlinestyle(0,0,0);
	for(int i=0; i<3; i++){
		setcolor(0);
		barcovien(315,190+120*i,980,310+120*i,-1);	//id: 150...
	   }
	bar(315,150,980,190);
	setcolor(0);
	rectangle(315,150,980,190);
	rectangle(315,150,370,550); //STT
	rectangle(370,150,600,550);	//ma sach
	rectangle(600,150,800,550);	// NGAY MUON
	rectangle(800,150,980,550);	//TT
	outtextxy(317,155, "STT");
	outtextxy(317,255, " 1");
	outtextxy(317,375, " 2");
	outtextxy(317,495, " 3");
	outtextxy(380,155, "MS DANG MUON");
	outtextxy(610,155, "NGAY MUON");
	outtextxy(810,155, "TINH TRANG");
	setcolor(12);
	outtextxy(317,555,"*Note: ");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}

void DrawTable_MT(short &page){
	setfillstyle(1,3);
	barcovien(315,150,1445,190,-5);
	for(int i=1; i<11; i++){ 
		setIDTable(315, 150+40*i,1445,190+40*i, 1500+i+page*10,page);	//id: 150...
	   }
	rectangle(315,150,370,590); //	STT
	rectangle(370,150,515,590);	//	ma sach
	rectangle(515,150,650,590);	// ma the
	rectangle(650,150,1010,590);	// ten sach
	rectangle(1010,150,1175,590);	// ngay muon
	rectangle(1175,150,1335,590);	//ngay tra
	rectangle(1335,150,1445,590);	// tinh trang
	setbkcolor(15);   // dien chu trong bang
	setcolor(0);
	settextstyle(0,0,2);
	outtextxy(317,155, "STT");
	outtextxy(380,155, "MA SACH");
	outtextxy(518,155,"MA THE");
	outtextxy(750,155, "TEN SACH");
	outtextxy(1013,155, "NGAY MUON");
	outtextxy(1180,155, "NGAY TRA");
	outtextxy(1400,155, "TT");   
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}

void PageMuonTra(){
	setfillstyle(1,3);
	settextstyle(0,0,2);
	bar(312,12,1448,590);
	vehinh(20,25,290,80,12,12,15,1,"QUAN LY DOC GIA");
	vehinh(20,100,290,155,12,12,0,2,"QUAN LY MUON TRA");
	vehinh(20,175,290,230,12,12,15,3,"QUAN LY DAU SACH");
	setfillstyle(1,15);
	
	setfillstyle(1,3); // khoang mau XANH NHAT
	bar(850,80,1100, 110); //
	setidchovung(481,50,840,78,-5);
	setidchovung(315,20,1445,145,-5);
	setidchovung(310,615,500,650,-5); // che nut quay lai
	bar(1100,80,1200, 110);
	bar(315,20,1445,145);
	bar(310,615,500,650); //che quay lai
	vehinh2(350,20,480,48,14,14,0,20,"MA THE");	
	vehinh2(850,20,1000,48,14,14,0,21,"HO TEN");
	vehinh2(850,50,1000,78,14,14,0,22,"TEN SACH");
	vehinh2(350, 50, 500, 78,14,14,0,24,"MA SACH");
	vehinh2(310,615,460,650,4,4,0,187,"<< BACK");
	vehinh2(1300,615,1445,650,4,4,0,188,"NEXT >>");
	setbkcolor(10);
	settextstyle(0,0,2);
	vehinh2(1195,82,1430,110,10,10,0,189,"DS.DG QUA HAN");
	vehinh2(575,112,690,140,10,10,0,31,"MUON");
//	vehinh2(700,112,815,140,10,10,0,32,"HUY");
	vehinh2(1330,112,1430,140,10,10,0,183,"TRA");
	vehinh2(1225,112,1329,140,15,15,7,184,"MS");
	vehinh2(1187,112,1225,140,3,3,0,-5,"-");	
	vehinh2(1090,112,1205,140,15,15,7,185,"MT");
	vehinh2(990,112,1089,140,10,10,0,186,"MAT");//186
	Box_MuonTra();
}
void Draw_DSDG_QUAHAN(short &page_dgqh){
	for(int i=0; i<11; i++){ 
		setIDTable(315, 150+40*i,1445,190+40*i,-5,page_dgqh);	//id: 150...
	   }
	   
	rectangle(315,150,370,590); //	STT
	rectangle(370,150,515,590);	//	ma sach
	rectangle(515,150,650,590);	// ma the
	rectangle(650,150,1010,590);	// ten sach
	rectangle(1010,150,1165,590);	// ngay muon
	rectangle(1165,150,1445,590);	//ten doc gia
//	rectangle(1335,150,1445,590);	// tinh trang
	setfillstyle(1,3);
	bar(315,20,1445,145);	//che box nhap dausach
	bar(1300,615,1445,650);	//che next
	setidchovung(315,20,1445,145,-5);
	setidchovung(1300,615,1445,650,-5);
	setidchovung(310,615,500,650,-5); // che nut quay lai
	setbkcolor(15);   // dien chu trong bang
	setcolor(0);
	settextstyle(0,0,2);
	outtextxy(317,155, "STT");
	outtextxy(380,155, "MA SACH");
	outtextxy(518,155,"MA THE");
	outtextxy(750,155, "TEN SACH");
	outtextxy(1013,155, "NGAY MUON");
	outtextxy(1180,155, "TEN DOC GIA");
//	outtextxy(1400,155, "TT");   
	vehinh2(310,615,460,650,4,4,0,190,"<< BACK");
	vehinh2(1300,615,1445,650,4,4,0,191,"NEXT >>");
	setbkcolor(3);
	setcolor(0);
	settextstyle(0,0,5);
	outtextxy(500,25,"DANH SACH DOC GIA");
	outtextxy(650,75,"QUA HAN");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}
void PageDauSach(){
	setfillstyle(1,3);
	settextstyle(0,0,2);
	bar(312,12,1448,590);
	vehinh(20,25,290,80,12,12,15,1,"QUAN LY DOC GIA");
	vehinh(20,100,290,155,12,12,15,2,"QUAN LY MUON TRA");
	vehinh(20,175,290,230,12,12,0,3,"QUAN LY DAU SACH");
	setfillstyle(1,3);
	bar(310,615,500,650);
	bar(310,615,500,650); // che quay lai
	setidchovung(310,615,500,650,-5);
	setfillstyle(1,15);
	vehinh2(380,20,475,48,10,10,0,176,"NEW");
	vehinh2(700,112,800,140,10,10,0,-5,"HUY");
	vehinh2(480,20,620,48,14,14,0,34," ISBN");
	vehinh2(350,50,495,78,14,14,0,35,"TAC GIA");
	vehinh2(350,80,505,110,14,14,0,36,"SO TRANG");
	vehinh2(680,80,830,110,14,14,0,37,"NAM XB");
	vehinh2(950,80,1030,110,14,14,0,38,"SL");
	vehinh2(1150,80,1270,110,14,14,0,39,"VI TRI");
	vehinh2(850,20,1020,48,14,14,0,40,"TEN SACH");
	vehinh2(850,50,1020,78,14,14,0,41,"THE LOAI");
	vehinh2(310,615,460,650,4,4,0,102,"<< BACK");
	vehinh2(1300,615,1445,650,4,4,0,103,"NEXT >>");
	vehinh2(575,112,690,140,10,10,0,171,"SAVE");
	vehinh2(1305,112,1440,140,10,10,0,172,"Find");
	vehinh2(315,115,415,145,10,10,0,173,"TOP");
	BoxInput_DS();
}
void DrawTable_Top_MT(){
	char s[2]="";
	bar(315,150,1445,590);
	setcolor(0);
	for(int i=0; i<11; i++){
		barcovien(315, 150+40*i,1445,190+40*i,-5);	
	}
	short p=0;
	InSTT(p);
	setcolor(0);
	rectangle(315,150,370,590); //	STT
	rectangle(370,150,500,590);	//	ISBN
	rectangle(500,150,850,590);	// ten sach
	rectangle(850,150,1125,590);	// TEN TAC GIA
	rectangle(1125,150,1345,590);	// THE LOAI
	rectangle(1345,150,1445,590);	// NAM XUAT BAN
	setbkcolor(15);
	outtextxy(317,155, "STT");
	outtextxy(380,155, "SO LUOT");
	outtextxy(650,155, "TEN SACH");
	outtextxy(900,155, "TEN TAC GIA");
	outtextxy(1130,155, "THE LOAI");
	outtextxy(1350,155, "NXB");
	setfillstyle(1,3);
	bar(315,20,1445,145);	//che box nhap dausach
	bar(1300,615,1445,650);	//che next
	setidchovung(315,20,1445,145,-5);
	setidchovung(1300,615,1445,650,-5);
	vehinh2(310,615,500,650,4,4,0,175,"<<QUAY LAI");
	setbkcolor(3);
	setcolor(0);
	settextstyle(0,0,5);
	outtextxy(470,25,"TOP 10 SACH DUOC MUON");
	outtextxy(620,75,"NHIEU NHAT");
	setbkcolor(15);
	setcolor(0);
	settextstyle(6,0,1);
}
void Xe(int &xe, int &bay){
	setbkcolor(3);
	setcolor(12);
	setfillstyle(1,12);
	settextstyle(0,0,2);
	outtextxy(xe,bay+27," o--o");
	outtextxy(xe,bay+15," |  |");
	outtextxy(xe,bay,"  --  ");
	delay(0.0001);
}
//void VeXe(){
////	rectangle(310,10,1450,600);
//	int xe=360;
//	int bay=560;
//	while(1){
//		if(kbhit()){
//		char c=getch();
//			if(c=='d'){
//				Xe(xe,bay);
//				xe=xe+5;
//			}
//			if(c=='a'){
//				Xe(xe,bay);
//				xe=xe-5;
//			}
//			if(c=='w'){
//				Xe(xe,bay);
//				bay=bay-5;
//			}
//			if(c=='s'){
//				Xe(xe,bay);
//				bay=bay+5;
//			}
//			if(c==13){
//				PageDocGia();
//				break;
//			}
//		}
//	}
//}
void Yes_No(char *question){
	setbkcolor(11);
	setcolor(4);
	settextstyle(6,0,1);
	outtextxy(30,420,"                                  ");				
	outtextxy(30,420,question);
	vehinh2(30,470,130,500,12,12,15,4,"YES");
	vehinh2(180,470,280,500,12,12,15,5," NO");
	setcolor(0);
	setbkcolor(15);
}
void Che_YesNo(){
	setfillstyle(1,11);
	bar(25,420,285,505);
	setfillstyle(1,15);
}
void KT_NhapHoTen(int  x,int y,char a[], int limit){
	short count=0;
	ScannerHoTen(x,y,a,limit);
	while(strlen(a)==0){
		BaoLoi("Khong duoc bo trong!");
		ScannerHoTen(x,y,a,limit);
		count++;
		if(count>1){
			Yes_No("Ban co muon thoat?");
			break;
		}
	}
	
}
void KT_NhapString(int  x,int y,char a[], int limit){
	short count=0;
	ScannerString(x,y,a,limit);
	while(strlen(a)==0){
		BaoLoi("Khong duoc bo trong!");
		ScannerString(x,y,a,limit);
		count++;
		if(count>1){
			Yes_No("Ban co muon thoat?");
			break;
		}
	}
		
}
void KT_NhapNums(int  x,int y,char a[], int limit){
	ScannerNums(x,y,a,limit);
	short count=0;
	while(strlen(a)==0){
		BaoLoi("Khong duoc bo trong!");
		ScannerNums(x,y,a,limit);
		count++;
		if(count>1){
			Yes_No("Ban co muon thoat?");
			break;
		}
	}
		
}
void KT_NhapCaplocks(int  x,int y,char a[], int limit){
	ScannerCapslock(x,y,a,limit);
	short count=0;
	while(strlen(a)==0){
		BaoLoi("Khong duoc bo trong!");
		ScannerCapslock(x,y,a,limit);
		count++;
		if(count>1){
			Yes_No("Ban co muon thoat?");		
			break;
		}
	}	
}
void DoHoaa(){
	// now, you can run project
	
	setcolor(0)	;		
	rectangle(10,10,300,250);
	setmapid();
	settextstyle(0,0,2); // CHU NAM NGANG VA X2 SIZE
	vehinh(20,25,290,80,12,12,15,1,"QUAN LY DOC GIA");
	vehinh(20,100,290,155,12,12,15,2,"QUAN LY MUON TRA");
	vehinh(20,175,290,230,12,12,15,3,"QUAN LY DAU SACH");
	vehinh(10,553,300,600,12,12,15,104,"      EXIT");
	vehinh2(10,655,300,700,3,3,0,-5,"(*) Nhan EXIT de thoat va luu du lieu");
//	vehinh(1335,550,1449,590,4,4,0,999,"Log in");
   	setfillstyle(0,0);
   	setbkcolor(11);
   	setfillstyle(1,11);
   	bar(10,270,300,550);
   	setcolor(0);
   	
	rectangle(10,270,300,550);	// khung canh bao
   	outtextxy(100,280, "THONG BAO");
   	setlinestyle(1,0,0);
   	rectangle(315,15,1445,135);
   	rectangle(315,140,1445,590);
   	setlinestyle(0,0,0);
   	rectangle(310,10,1450,600);
	setbkcolor(3);
	setcolor(12);
	settextstyle(0,0,4);
	
	outtextxy(480,60, "WELCOME TO THE LIBRARY");
	settextstyle(0,0,3);
	outtextxy(650,180, "			*** DEVELOPER ***");
	outtextxy(675,240, "					");
	delay(1000);
	outtextxy(750,340, "			PTIT HCM");
	outtextxy(750,280, "				  			");
	delay(700);
//	barcovien(500,280,1150,300,-5);
//	delay(100);
//	setfillstyle(1,4);
//	delay(300);
//	bar(501,282,601,299);
//	delay(300);
//	bar(501,282,651,299);
//	delay(300);
//	bar(551,282,701,299);
//	delay(300);
//	bar(501,282,801,299);
//	delay(300);
//	bar(501,282,851,299);
//	delay(300);
//	bar(501,282,901,299);
//	delay(300);
//	bar(501,282,951,299);
//	delay(300);
//	bar(501,282,1000,299);
//	delay(300);
//	bar(501,282,1100,299);
//	delay(300);
//	bar(501,282,1149,299);
//	setfillstyle(1,3);
//	bar(500,280,1151,301);
	
	outtextxy(500,280, "T				  			");
	delay(50);
	outtextxy(500,280, "TR				  			");
	delay(50);
	outtextxy(500,280, "TRA				  			");
	delay(50);
	outtextxy(500,280, "TRAN			  			");
	delay(50);
	outtextxy(500,280, "TRAN H			  			");
	delay(50);
	outtextxy(500,280, "TRAN HU						");
	delay(50);
	outtextxy(500,280, "TRAN HUU					");
	delay(50);
	outtextxy(500,280, "TRAN HUU C					");
	delay(50);
	outtextxy(500,280, "TRAN HUU CH					");
	delay(50);
	outtextxy(500,280, "TRAN HUU CHI				");
	delay(50);
	outtextxy(500,280, "TRAN HUU CHIE				");
	delay(50);
	outtextxy(500,280, "TRAN HUU CHIEN				");
	settextstyle(0,0,2);
	
	
}
