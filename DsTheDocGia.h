#pragma once
//#include <map>
//#include <time.h>
//#include <fstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "DSMuonTra.h"
const int _SIZE_DG=100;

struct TheDocGia{
	int MaThe;
	char Ho [25];
	char Ten [10];
	int Phai; // 0.Nam 1.Nu
	int TrangThai; // 0.Hoatdong, 1.Khoa
	short SLMuon;
	NodeMuonTra *first=NULL;
	TheDocGia(){
	}
};

struct NodeThe{
	TheDocGia member;
	NodeThe *L=NULL;
	NodeThe *R=NULL;
};
TheDocGia Cre_member(char ho[25], char ten[10], int phai, int tt, int mathe,short sl_sachmuon) {//std::cout<<"Toidaychua?";
	TheDocGia Member;
	Member.MaThe=mathe;	
	strcpy(Member.Ho, ho);	//std::cout<<"IN cho XEM \n";
	strcpy(Member.Ten, ten);	
	Member.Phai=phai;
	Member.TrangThai=tt;
	Member.SLMuon=sl_sachmuon;
	return Member;
}

NodeThe *CreDG(TheDocGia &member){
	NodeThe *NewNodeDG = new NodeThe();	
	NewNodeDG->member=member;
	NewNodeDG->L=NULL;
	NewNodeDG->R=NULL;
	return NewNodeDG;
}
NodeThe *CreID(int data){
	NodeThe* newID= new NodeThe();
	newID->member.MaThe=data;
	newID->L=NULL;
	newID->R=NULL;
	return newID;
}
NodeThe *RandomToBST(NodeThe *&root, int arr[], int start, int end) 
{ 											
    if (start > end)   return NULL; 
    int mid = (start + end)/2; 
    NodeThe *p;
    p = CreID(arr[mid]); 
    p->L = RandomToBST(root,arr, start, mid - 1); 
    p->R = RandomToBST(root,arr, mid + 1, end); 
    return p; 
} 
void DoCayVaoMang(NodeThe *&root, TheDocGia *mangThe,short int &n){
	if(root!=NULL ){	
   			DoCayVaoMang(root->L, mangThe, n);
			if(strcmp(root->member.Ho,"XOADOCGIA")!=0)	mangThe[n++]=root->member;	
		    DoCayVaoMang(root->R, mangThe, n);
   }
}
void DoCay(NodeThe *&root, TheDocGia *mangThe,short int &n){
	if(root!=NULL ){
		if(strcmp(root->member.Ho,"XOADOCGIA")!=0 && root->member.first!=NULL)	mangThe[n++]=root->member;
	  	DoCay(root->L, mangThe, n);
     	DoCay(root->R, mangThe, n);
	}
	
}

//void preOrder(TNode* node) 
//{ 
//    if (node == NULL) 
//        return; 
//    cout << node->data << " "; 
//    preOrder(node->left); 
//    preOrder(node->right); 
//} 
NodeThe *SearchDG(int MA_THE, NodeThe* &root ){
	NodeThe *runS = root;
	while(runS!=NULL ){ 
		if(MA_THE < runS->member.MaThe){
		    runS=runS->L;
		}
		else if(MA_THE > runS->member.MaThe){
	    	runS=runS->R;
	    }
	    else	return runS;
	}
	return 0;
}
void Sua_TDG(char ho[25], char ten[10], int phai, int tt, NodeThe *&root){
	int MA_THE;
	if(SearchDG(MA_THE,root)==0)	return;
	NodeThe *tmp = SearchDG(MA_THE, root);
	strcpy(tmp->member.Ho,ho);
	strcpy(tmp->member.Ten,ten);
	tmp->member.Phai=phai;
	tmp->member.TrangThai=tt;
}
//	char ho[25], char ten[10], int phai, int tt,int mathe,
void InsertDG(TheDocGia &member, NodeThe* &root){
	NodeThe *tmp= CreDG(member);
		if(root==NULL){
			root=tmp;	
			return;
		}		
		else{	
			NodeThe *nodechay=root;
			NodeThe *nodetruoc=root;
			while(nodechay!=NULL){
				nodetruoc=nodechay;
				if(tmp->member.MaThe < nodechay->member.MaThe){
					nodechay = nodechay->L;
				}
				else if(tmp->member.MaThe > nodechay->member.MaThe){
					nodechay = nodechay->R;
				}		
			}
			if(tmp->member.MaThe<nodetruoc->member.MaThe){
					nodetruoc->L=tmp;
				}
			else	nodetruoc->R=tmp;
		}	
}
short int DemNut(NodeThe *&root_tmp){
	if( root_tmp == NULL)	return 0;
	else{
	short int DemLeft = DemNut(root_tmp->L);
	short int DemRight = DemNut(root_tmp->R);	
	
		return DemLeft + DemRight+ 1;	
	}
}

//void preOrder(NodeThe *node) //NLR
//{ 
//    if (node == NULL) 
//        return; 
//    std:: cout << node->member.MaThe << std::endl; 
//    preOrder(node->L); 
//    preOrder(node->R); 
//} 
// duyet cay bang pp khong de quy
//void Pretrav(TheDocGia &member,NodeThe *&root){	
//	NodeThe *Stack[STACKSIZE];
//	int sp= -1;
//	NodeThe *p= root;
//	while(p!=NULL){
//		if(p->R!=NULL){
//			Stack[++sp]=p->R;
//		}
//		if(p->L!=NULL){
//			Stack[++sp]=p->L;
//		}
//		else if(sp==-1){
//			break;
//		}
//		else	Stack[sp--];
//	}
//}

void xoaNutGoc(int MA_THE, NodeThe *&root){
	//Xoa goc co khong con
	if(root->R==NULL && root->L==NULL){
		delete root;
		root=NULL;
	}
	//xoa goc co 1 con
	else if(root->R==NULL || root->L==NULL){
		NodeThe *nodeCanXoa = root;
		if(root->L==NULL){
			root=root->R;
		}
		else if(root->R==NULL){
			root=root->L;
		}
		delete nodeCanXoa;
	}
	//xoa goc hai con
	else if(root->L!=NULL && root->R!=NULL){
		NodeThe *nodeThayThe = root->R;
		NodeThe *nodeTruocThayThe = root;
		
		while(nodeThayThe->L!=NULL){
			nodeTruocThayThe=nodeThayThe;
			nodeThayThe=nodeThayThe->L;
		}
		
		TheDocGia tmp = root->member;
		root->member=nodeThayThe->member;
		nodeThayThe->member=tmp;
		
		if(nodeTruocThayThe==root){
			if(nodeThayThe->R!=NULL){
				nodeTruocThayThe->R=nodeThayThe->R;	// cap nhat lai lien ket cua 
			}												// goc phai voi node thay the phai ( la node vua xoa )
			else{
				nodeTruocThayThe->R=NULL;
			}
		}
		else{
			if(nodeThayThe->R!=NULL){					// * Dung node trai nhat cua cay con Phai thay the
				nodeTruocThayThe->L=nodeThayThe->R;	// Vi vay neu node Truoc Thay The khong phai goc
															// thi phai cap nhat lai lk cua no (vi luc nay node Thay the bi xoa roi)
			}
			else{
				nodeTruocThayThe->L=NULL;
			}
		}
		
		delete nodeThayThe;
	}
}
void xoaNodeKhongPhaiGoc(int MA_THE, NodeThe *&root){
	NodeThe* nodeCanXoa = root;
	NodeThe* nodeTruocXoa = NULL;
	while(nodeCanXoa!=NULL){
		//tim node Truoc Xoa va node Can Xoa
		nodeTruocXoa=nodeCanXoa;
		if(nodeCanXoa->member.MaThe<MA_THE){
			nodeCanXoa=nodeCanXoa->R;
		}
		else if(nodeCanXoa->member.MaThe>MA_THE){
			nodeCanXoa=nodeCanXoa->L;
		}
		
		//tim xong nodeTruocXoa va nodeCanXoa
		
		if(nodeCanXoa->member.MaThe==MA_THE){
			//thuc Hien xoa
			//xoa node khong con
			if(nodeCanXoa->R==NULL && nodeCanXoa->L==NULL){
				if(nodeCanXoa->member.MaThe<nodeTruocXoa->member.MaThe){
					nodeTruocXoa->L=NULL;
				}
				else if(nodeCanXoa->member.MaThe>nodeTruocXoa->member.MaThe){
					nodeTruocXoa->R=NULL;
				}
				delete nodeCanXoa;
				return;
			}
			//xoa node 1 con
			else if(nodeCanXoa->R==NULL || nodeCanXoa->L==NULL){
				//nodeCanXoa nam ben trai nodeTruocXoa
				if(nodeCanXoa->member.MaThe < nodeTruocXoa->member.MaThe){
					if(nodeCanXoa->L==NULL){
						nodeTruocXoa->L = nodeCanXoa->R;
					}
					else if(nodeCanXoa->R==NULL){
						nodeTruocXoa->L = nodeCanXoa->L;
					}
				}
				//nodeCanXoa nam ben phai nodeTruocXoa
				else if(nodeCanXoa->member.MaThe > nodeTruocXoa->member.MaThe){
					if(nodeCanXoa->L==NULL){
						nodeTruocXoa->R = nodeCanXoa->R;
					}
					else if(nodeCanXoa->R==NULL){
						nodeTruocXoa->R = nodeCanXoa->L;
					}
				}
				delete nodeCanXoa;
				return;
			}
			//xoa node 2 con
			else if(nodeCanXoa->R!=NULL && nodeCanXoa->L!=NULL){
				NodeThe *nodeThayThe = nodeCanXoa->R;
				NodeThe *nodeTruocThayThe = nodeCanXoa;
				
				while(nodeThayThe->L!=NULL){
					nodeTruocThayThe=nodeThayThe;
					nodeThayThe=nodeThayThe->L;
				}
				
				TheDocGia tmp = nodeCanXoa->member;
				nodeCanXoa->member=nodeThayThe->member;
				nodeThayThe->member=tmp;
				
				
				if(nodeTruocThayThe==nodeCanXoa){
					if(nodeThayThe->R!=NULL){
						nodeTruocThayThe->R=nodeThayThe->R;
					}
					else{
						nodeTruocThayThe->R=NULL;
					}
				}
				else{
					if(nodeThayThe->R!=NULL){
						nodeTruocThayThe->L=nodeThayThe->R;
					}
					else{
						nodeTruocThayThe->L=NULL;
					}
				}
				
				delete nodeThayThe;
				return;
			}
		}
		
	}
	std::cout<<"Khong tim thay de xoa";
}
void xoaNodeKhoiCay(int MA_THE, NodeThe* &root){
	if(root!=NULL){
		if(root->member.MaThe==MA_THE){
			xoaNutGoc(MA_THE,root);
		}
		else{
			xoaNodeKhongPhaiGoc(MA_THE,root);
		}
	}
	else{
		std::	cout<<"Danh Sach Rong"<<std::endl;
	}
}
// delete vung nho
void DeleteMemoryDocGia(NodeThe *&root){
	if(root != NULL){
		DeleteMemoryDocGia(root->L);
		DeleteMemoryDocGia(root->R);
		GiaiPhongVungNhoMuonTra(root->member.first);
		delete root;
		
	}
}
void swap(TheDocGia *a, TheDocGia *b){
	TheDocGia c= *a;
	*a=*b;
	*b=c;	
}
int Partition(TheDocGia *Arr,int low, int high){
	TheDocGia pivot = Arr[high];
	int i= low-1; // bien i co tac dung nam vi tri
	for (int j = low; j <= high - 1; j++)  
    {  // khi j bat dau chay tu 0-> pivot -1
        if (strcmp(Arr[j].Ten,pivot.Ten)<0)  
        {  // neu gtri tai j < pivot
            i++; 
            swap(&Arr[i], &Arr[j]); // thi doi gia tri tai j va gia tri tai i (i luc nay = 0) 
        } // muc tieu la sap xep cac gia tri < pivot sang ben trai.
		else if(strcmp(Arr[j].Ten,pivot.Ten)==0){
			if(strcmp(Arr[j].Ten,pivot.Ho)<=0);{
				i++; 
            	swap(&Arr[i], &Arr[j]);	
			}
		}  
    }  
	swap(&Arr[i + 1], &Arr[high]);  // sau cung la dua gtri pivot ve dung vi tri la i+1
    return (i + 1);
}
void quickSort(TheDocGia *Arr,int low, int high)  
{  	

    if (low < high)  
    {  
        int pi = Partition(Arr,low, high);  
        quickSort(Arr,low, pi - 1);  
        quickSort(Arr,pi + 1, high);  
    }  
}  
int Partition_ID(TheDocGia *Arr,int low, int high){
	TheDocGia pivot = Arr[high];
	int i= low-1;
	for (int j = low; j <= high - 1; j++)  
    {  
        if (Arr[j].MaThe < pivot.MaThe)  
        {  
            i++; 
            swap(&Arr[i], &Arr[j]);  
        }
    }  
	swap(&Arr[i + 1], &Arr[high]);  
    return (i + 1);
}
void quickSort_ID(TheDocGia *Arr,int low, int high)  
{  	

    if (low < high)  
    {  
        int pi = Partition_ID(Arr,low, high);  
        quickSort_ID(Arr,low, pi - 1);  
        quickSort_ID(Arr,pi + 1, high);  
    }  
}  

//----------------------------------------
struct node{
	NodeThe *diachi;
	node *next;
}; 
typedef node *Node_queue;
struct Queue{
	Node_queue Front, Rear;
};
void Insert_queue(Queue &q, NodeThe *x){
	Node_queue p;
	p=new node;
	p->diachi=x;
	p->next=NULL;
	if(q.Front==NULL){
		q.Front=p;
	}
	else q.Rear->next=p;
		q.Rear=p;
}
NodeThe *Delete_queue(Queue &q){
	
	Node_queue p;
	NodeThe *x;
	if(q.Front==NULL){	
		return 0;
	}
	else{
		p=q.Front;
		x=p->diachi;
		q.Front=p->next;
		delete p;
		return x;
	}
}

//void leveltrav(NodeThe *root,Queue &q ){	
//	NodeThe *p;
//	q.Front=NULL;
//	q.Rear=NULL;
//	if(root!=NULL){
//		Insert_queue(q,root);
//	}
//	while(q.Front!=NULL){
//		p=Delete_queue(q); 
//	//	std ::cout<<p->member.MaThe<<"-";
//		if(p->L!=NULL){
//			Insert_queue(q,p->L);
//		}	
//		if(p->R!=NULL){		
//			Insert_queue(q,p->R);
//		}			
//	}
//}





