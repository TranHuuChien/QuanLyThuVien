#include <winbgim.h> 
//#include <mylib.h>
//#include <string.h>
//#include <time.h>
#include "DauSach.h"
#include "DsTheDocGia.h"
#include "DsMuonTra.h"
//#include "DoHoa.h"
#include "XuLy.h"

int main(){
	
	initwindow(1500, 700);			// init window graphics
	setbkcolor(3);			// set background
	cleardevice();
	List DSDS;
	TheDocGia member;
	NodeThe *root=NULL;
	Sach sach;
	NodeSach *first=NULL;
	MuonTra mt;
	XuLyNut(DSDS, root, member,sach,first,mt);
    NodeMuonTra *firstMT=NULL;
	return 0;

}
