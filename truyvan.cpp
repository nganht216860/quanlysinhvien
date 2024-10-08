#include "truyvan.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
DSSV DHBK_SV = KhoiTaoDanhSachSV();
DSHP DHBK_HP = KhoiTaoDanhSachHP();
DSDiem DHBK_Diem = KhoiTaoDanhSachDiem();

// Ham cap nhat thong tin sinh vien
void CapNhatSV (DSSV &dssv, DSDiem &dsdiem) {
	char mssv [20];
	char NewMSSV [20];
	printf("\nNhap MSSV ma ban muon cap nhat: ");
	fprintf(f, "\nNhap MSSV ma ban muon cap nhat: ");
	scanf("%s", &mssv); fprintf(f, "%s\n", mssv);
	if (TimKiemSV(dssv, mssv) == -1) {
		printf("\nKhong ton tai MSSV: %s", mssv);
		fprintf(f, "\nKhong ton tai MSSV: %s", mssv);
		return;
	}
	printf("Nhap MSSV moi. Neu khong thay doi hay nhap MSSV cu: ");
	fprintf(f, "Nhap MSSV moi. Neu khong thay doi hay nhap MSSV cu: ");
	scanf("%s", &NewMSSV); fprintf(f, "%s\n", NewMSSV);
	if (TimKiemSV(dssv, NewMSSV) != -1 && strcmp(mssv, NewMSSV) != 0) {
		printf("\nMSSV moi ma ban nhap da ton tai");
		fprintf(f, "\nMSSV moi ma ban nhap da ton tai");
		return;
	}
	if (TimKiemSV(dssv,NewMSSV) == -1) {
		dssv = CapNhapSV(dssv, mssv, NewMSSV);
		dsdiem = UpdateDiemMSSV(dsdiem, mssv, NewMSSV);
		return;
	}
	dssv = CapNhapSV(dssv, mssv, NewMSSV);
}
// Ham cap nhat thong tin hoc phan
void CapNhatHP (DSHP &dshp, DSDiem &dsdiem) {
	char mahp [20];
	char NewMaHP [20];
	printf("\nNhap MaHP ma ban muon cap nhat: ");
	fprintf(f, "\nNhap MaHP ma ban muon cap nhat: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemHP(dshp, mahp) == -1) {
		printf("\nKhong ton tai MaHP: %s", mahp);
		fprintf(f, "\nKhong ton tai MaHP: %s", mahp);
		return;
	}
	printf("Nhap MaHP moi. Neu khong thay doi hay nhap MaHP cu: ");
	fprintf(f, "Nhap MaHP moi. Neu khong thay doi hay nhap MaHP cu: ");
	scanf("%s", &NewMaHP); fprintf(f, "%s\n", NewMaHP);
	if (TimKiemHP(dshp, NewMaHP) != -1 && strcmp(mahp, NewMaHP) != 0) {
		printf("\nMaHP moi ma ban nhap da ton tai");
		fprintf(f, "\nMaHP moi ma ban nhap da ton tai");
		return;
	}
	if (TimKiemHP(dshp, NewMaHP) == -1) {
		dshp = CapNhapHP(dshp, mahp, NewMaHP);
		dsdiem = UpdateDiemMaHP(dsdiem, mahp, NewMaHP);
		return;
	}
	dshp = CapNhapHP(dshp, mahp, NewMaHP);
}
// Ham cap nhat diem thi
void CapNhatDiem (DSDiem &dsdiem) {
	float diem;
	char mssv [20];
	char mahp [20];
	printf("\nNhap MSSV ma ban muon cap nhat diem: "); fprintf(f, "\nNhap MSSV ma ban muon cap nhat diem: ");
	scanf("%s", &mssv); fprintf(f, "%s\n", mssv);
	printf("Nhap MaHP ma ban muon cap nhat diem: "); fprintf(f, "Nhap MaHP ma ban muon cap nhat diem: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemDiem(dsdiem, mssv, mahp) == -1) {
		printf("Ban ghi diem thi khong ton tai"); fprintf(f, "Ban ghi diem thi khong ton tai");
		return;
	}
	printf("Nhap diem moi: "); fprintf(f, "Nhap diem moi: ");
	do {
		scanf("%f", &diem); fprintf(f, "%f\n", diem);
		if (diem < 0 || diem > 10)
			printf("Diem phai >= 0 hoac <= 10. Hay nhap lai diem: "); fprintf(f, "Diem phai >= 0 hoac <= 10. Hay nhap lai diem: ");
	} while (diem < 0 || diem > 10);
	dsdiem = UpdateDiemThi(dsdiem, mssv, mahp, diem);
}
// Ham xoa sinh vien
void XoaSV (DSSV &dssv, DSDiem &dsdiem) {
	char mssv [20];
	printf("\nNhap MSSV ma ban muon xoa: "); fprintf(f, "\nNhap MSSV ma ban muon xoa: ");
	scanf("%s", &mssv); fprintf(f, "%s\n", mssv);
	if (TimKiemSV(dssv, mssv) == -1) {
		printf("\nKhong ton tai MSSV %s", mssv); fprintf(f, "\nKhong ton tai MSSV %s", mssv);
		return;
	}
	dssv = XoaSV(dssv, mssv);
	dsdiem = DeleteDiemMSSV(dsdiem, mssv);
}
// Ham xoa hoc phan
void XoaHP (DSHP &dshp, DSDiem &dsdiem) {
	char mahp [20];
	printf("\nNhap MaHP ma ban muon xoa: "); fprintf(f, "\nNhap MaHP ma ban muon xoa: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemHP(dshp, mahp) == -1) {
		printf("\nKhong ton tai MaHP %s", mahp); fprintf(f, "\nKhong ton tai MaHP %s", mahp);
		return;
	}
	dshp = XoaHP(dshp, mahp);
	dsdiem = DeleteDiemMaHP(dsdiem, mahp);
}
// Ham xoa ban ghi diem thi
void XoaDiem (DSDiem &dsdiem) {
	char mssv [20];
	char mahp [20];
	printf("\nNhap MSSV ma ban muon xoa diem: "); fprintf(f, "\nNhap MSSV ma ban muon xoa diem: ");
	scanf("%s", &mssv); fprintf(f, "%s\n", mssv);
	printf("Nhap MaHP ma ban muon xoa diem: "); fprintf(f, "Nhap MaHP ma ban muon xoa diem: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemDiem(dsdiem, mssv, mahp) == -1) {
		printf("Ban ghi diem thi khong ton tai"); fprintf(f, "Ban ghi diem thi khong ton tai");
		return;
	}
	dsdiem = DeleteDiemThi(dsdiem, mssv, mahp);
}
// Ham ghi CPA cua sinh vien ra file .bin va .txt
void File_CPA_SV(DSSV &dssv, DSDiem &dsdiem, DSHP &dshp) {
	NodeCPA* p = dssv.headCPA;
	while (p != NULL) {
		CapNhapCPA(dssv, p->data.MSSV, dsdiem, dshp);
		p = p->next;
	}
	WriteBin_DSCPA(dssv);
	WriteTxt_DSCPA(dssv);
	printf("\nDa ghi danh sach CPA cua sinh vien ra file DSCPA.bin va DSCPA.txt");
	fprintf(f, "\nDa ghi danh sach CPA cua sinh vien ra file DSCPA.bin va DSCPA.txt");
}
// Ham hien thi nhung sinh vien khong dat hoc phan duoc nhap vao
void n_SV_ko_dat_hoc_phan(DSSV &dssv, DSHP &dshp, DSDiem &dsdiem) {
	char mahp [20];
	printf("\nNhap MaHP: "); fprintf(f, "\nNhap MaHP: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemHP(dshp, mahp) == -1) {
		printf("\nKhong ton tai MaHP %s", mahp); fprintf(f, "\nKhong ton tai MaHP %s", mahp);
		return;
	}
	NodeDiem* p = dsdiem.head;
	int count = 0;
	while (p != NULL) {
		if (strcmp(p->data.MaHP, mahp) == 0 && p->data.DiemHP < 4) {
			if (count == 0)
				printf("\nDanh sach nhung sinh vien khong dat hoc phan %s la:\n", mahp);
				fprintf(f, "\nDanh sach nhung sinh vien khong dat hoc phan %s la:\n", mahp);
			count++;
			NodeSV* q = dssv.head;
			while (1) {
				if (strcmp(q->data.MSSV, p->data.MSSV) == 0)
					break;
				q = q->next;
			}
			printf("\n	%d %s %s, MSSV %s", count, q->data.Ho, q->data.Ten, p->data.MSSV);
			fprintf(f, "\n	%d %s %s, MSSV %s", count, q->data.Ho, q->data.Ten, p->data.MSSV);
			p = p->next;
		}
		else
			p = p->next;
	}
	if (count == 0)
		printf("\nDanh sach rong");
		fprintf(f, "\nDanh sach rong");
}
// Ham hien thi nhung hoc phan ma sinh vien duoc nhap vao khong dat
void SV_ko_dat_n_hoc_phan(DSSV &dssv, DSHP &dshp, DSDiem &dsdiem) {
	char mssv [20];
	printf("\nNhap MSSV: "); fprintf(f, "\nNhap MSSV: ");
	scanf("%s", &mssv);
	fprintf(f, "%s\n", mssv);
	if (TimKiemSV(dssv, mssv) == -1) {
		printf("\nKhong ton tai MSSV %s", mssv);
		fprintf(f, "\nKhong ton tai MSSV %s", mssv);
		return;
	}
	NodeDiem* p = dsdiem.head;
	int count = 0;
	while (p != NULL) {
		if (strcmp(p->data.MSSV, mssv) == 0 && p->data.DiemHP < 4) {
			if (count == 0)
				printf("\nDanh sach nhung hoc phan ma sinh vien %s khong dat la:\n", mssv);
				fprintf(f, "\nDanh sach nhung hoc phan ma sinh vien %s khong dat la:\n", mssv);
			count++;
			NodeHP* q = dshp.head;
			while (1) {
				if (strcmp(q->data.MaHP, p->data.MaHP) == 0)
					break;
				q = q->next;
			}
			printf("\n	%d %s, MaHP %s", count, q->data.TenHP, p->data.MaHP);
			fprintf(f, "\n	%d %s, MaHP %s", count, q->data.TenHP, p->data.MaHP);
			p = p->next;
		}
		else
			p = p->next;
	}
	if (count == 0)
		printf("\nDanh sach rong");
		fprintf(f, "\nDanh sach rong");
}
// Ham hien thi CPA cua sinh vien duoc nhap vao
void Display_CPA (DSSV &dssv, DSHP &dshp, DSDiem &dsdiem) {
	char mssv [20];
	printf("\nNhap MSSV: ");
	fprintf(f, "\nNhap MSSV: ");
	scanf("%s", &mssv);
	fprintf(f, "%s\n", mssv);
	if (TimKiemSV(dssv, mssv) == -1) {
		printf("\nKhong ton tai MSSV %s", mssv);
		fprintf(f, "\nKhong ton tai MSSV %s", mssv);
		return;
	}
	CapNhapCPA(dssv, mssv, dsdiem, dshp);
	NodeCPA* p = dssv.headCPA;
	while (p != NULL) {
		if (strcmp(p->data.MSSV, mssv) == 0)
			break;
		p = p->next;
	}
	printf("\nDiem trung binh tich luy cua sinh vien %s la %2.2f", mssv, p->data.cpa);
	fprintf(f, "\nDiem trung binh tich luy cua sinh vien %s la %2.2f", mssv, p->data.cpa);
}
