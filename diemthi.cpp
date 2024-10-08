#include "diemthi.h"
#include "hocphan.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//Tao danh sach Diem Thi
DSDiem KhoiTaoDanhSachDiem () {
	DSDiem dsdiem;
	dsdiem.head = NULL;
	return dsdiem;
}

// Tim kiem Diem Thi trong danh sach theo MSSV va MaHP
int TimKiemDiem (DSDiem &dsdiem, char mssv[20], char mahp[20]) {
	int index = 0;
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		if (strcmp(mahp, p->data.MaHP) == 0 && strcmp(mssv, p->data.MSSV) == 0)
			break;
		p = p->next;
		index++;
	}
	if (p == NULL)
		return -1;
	return index;
}

// Tao node Diem
NodeDiem* TaoNodeDiem (char mssv[20], char mahp[20]) {
	NodeDiem* NewDiem = (NodeDiem*)malloc(sizeof(NodeDiem));
	strcpy (NewDiem->data.MaHP, mahp);
	strcpy (NewDiem->data.MSSV, mssv);
	NewDiem->next = NULL;
	return NewDiem;
}

// Them node Diem vao danh sach
DSDiem AddNodeDiem (DSDiem &dsdiem, DSSV &dssv, DSHP &dshp) {
	char mssv [20], mahp [20];
	printf("\nNhap MSSV: "); fprintf(f, "\nNhap MSSV: "); scanf("%s", &mssv);
	fprintf(f, "%s\n", mssv);
	printf("Nhap MaHP: "); fprintf(f, "Nhap MaHP: "); scanf("%s", &mahp);
	fprintf(f, "%s\n", mahp);
	if (TimKiemSV(dssv, mssv) == -1) {
		printf("\nKhong ton tai MSSV %s", mssv);
		fprintf(f, "\nKhong ton tai MSSV %s", mssv);
		return dsdiem;
	}
	if (TimKiemHP(dshp, mahp) == -1) {
		printf("Khong ton tai MaHP %s", mahp);
		fprintf(f, "Khong ton tai MaHP %s", mahp);
		return dsdiem;
	}
	if (TimKiemDiem (dsdiem, mssv, mahp) != -1) {
		printf("\n Da ton tai diem hoc phan %s cua sinh vien %s", mahp, mssv);
		fprintf(f, "\n Da ton tai diem hoc phan %s cua sinh vien %s", mahp, mssv);
		return dsdiem;
	}
	NodeDiem* NewDiem = TaoNodeDiem(mssv, mahp);
	float diem = -1.00;
	printf("\nNhap thong tin cua diem thi: ");
	fprintf(f, "\nNhap thong tin cua diem thi: ");
	do {
		scanf("%f", &diem); fprintf(f, "%f\n", diem);
		if (diem < 0 || diem > 10)
			printf("Diem phai >= 0 hoac <= 10. Hay nhap lai diem: ");
			fprintf(f, "Diem phai >= 0 hoac <= 10. Hay nhap lai diem: ");
	} while (diem < 0 || diem > 10);
	diem = round(2*diem)/2; // Lam tron a den le 0.5
	NewDiem->data.DiemHP = diem;
	if (dsdiem.head == NULL)
		dsdiem.head = NewDiem;
	else {
		NewDiem->next = dsdiem.head;
		dsdiem.head = NewDiem;
	}
	printf("\nDa them diem thi vao danh sach, mssv %s, hoc phan %s", mssv, mahp);
	fprintf(f, "\nDa them diem thi vao danh sach, mssv %s, hoc phan %s", mssv, mahp);
	return dsdiem;
}

// Ham duyet danh sach diem thi
void DuyetDSDiem (DSDiem &dsdiem) {
	if (dsdiem.head == NULL) {
		printf("\nDanh sach rong");
		fprintf(f, "\nDanh sach rong");
		return;
	}
	NodeDiem* p = dsdiem.head;
	printf("\nDanh sach diem thi:"); printf("\nDanh sach diem thi:");
	printf("\n-----------------------------------------");
	fprintf(f, "\n-----------------------------------------");
	printf("\n|  STT  | Ma hoc phan |   MSSV   | Diem |");
	fprintf(f, "\n|  STT  | Ma hoc phan |   MSSV   | Diem |");
	printf("\n|-------|-------------|----------|------|");
	fprintf(f, "\n|-------|-------------|----------|------|");
	int count = 0;
	while (p != NULL) {
		count++;
		printf("\n| %5d |  %9s  | %8s | %4.1f |", count, p->data.MaHP, p->data.MSSV, p->data.DiemHP);
		fprintf(f, "\n| %5d |  %9s  | %8s | %4.1f |", count, p->data.MaHP, p->data.MSSV, p->data.DiemHP);
		if (p->next == NULL) {
			printf("\n-----------------------------------------");
			fprintf(f, "\n-----------------------------------------");
		}
		else {
			printf("\n|-------|-------------|----------|------|");
			fprintf(f, "\n|-------|-------------|----------|------|");
		}
		p = p->next;
	}
}

// Ham cap nhat MSSV moi cho danh sach diem thi
// Ham nay duoc goi ngay sau ham UpdateSV
DSDiem UpdateDiemMSSV (DSDiem &dsdiem, char mssv[20], char NewMSSV[20]) {
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		if (strcmp(p->data.MSSV, mssv) == 0){
			strcpy(p->data.MSSV, NewMSSV);
		}
		p = p->next;
	}
	printf("\nDanh sach diem thi cua sinh vien %s da duoc cap nhat MSSV moi: %s", mssv, NewMSSV); fprintf(f, "\nDanh sach diem thi cua sinh vien %s da duoc cap nhat MSSV moi: %s", mssv, NewMSSV);
	return dsdiem;
}

// Ham xoa cac ban ghi diem thi sau khi co mot MSSV bi xoa di
// Ham nay duoc goi ngay sau ham DeleteSV
DSDiem DeleteDiemMSSV (DSDiem &dsdiem, char mssv[20]) {
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		if (strcmp(p->data.MSSV, mssv) == 0) {
			if (dsdiem.head == p) {
				NodeDiem* p1 = dsdiem.head;
				p = p->next;
				dsdiem.head = p;
				free (p1);
			}
			else if (p->next == NULL) {
				NodeDiem* p1 = dsdiem.head;
				while (p1->next != p)
					p1 = p1->next;
				p1->next = NULL;
				free (p);
				return dsdiem;
			}
			else {
				NodeDiem* p1 = dsdiem.head;
				NodeDiem* p2 = dsdiem.head;
				while (p1 != p)
					p1 = p1->next;
				while (p2->next != p1)
					p2 = p2->next;
				p = p->next;
				p2->next = p1->next;
				free (p1);
			}
		}
		else
			p = p->next;
	}
	printf("\nDa xoa tat ca cac ban ghi diem thi cua sinh vien %s", mssv);
	fprintf(f, "\nDa xoa tat ca cac ban ghi diem thi cua sinh vien %s", mssv);
	return dsdiem;
}

// Ham cap nhat MaHP moi cho danh sach diem thi
// Ham nay duoc goi ngay sau ham UpdateHP
DSDiem UpdateDiemMaHP (DSDiem &dsdiem, char mahp[20], char NewMaHP[20]) {
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		if (strcmp(p->data.MaHP, mahp) == 0){
			strcpy(p->data.MaHP, NewMaHP);
		}
		p = p->next;
	}
	printf("\nDanh sach diem thi cua Hoc Phan %s da duoc cap nhat MaHP moi: %s", mahp, NewMaHP);
	fprintf(f, "\nDanh sach diem thi cua Hoc Phan %s da duoc cap nhat MaHP moi: %s", mahp, NewMaHP);
	return dsdiem;
}

// Ham xoa cac ban ghi diem thi sau khi co mot MaHP bi xoa di
// Ham nay duoc goi ngay sau ham DeleteHP
DSDiem DeleteDiemMaHP (DSDiem &dsdiem, char mahp[20]) {
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		if (strcmp(p->data.MaHP, mahp) == 0) {
			if (dsdiem.head == p) {
				NodeDiem* p1 = dsdiem.head;
				p = p->next;
				dsdiem.head = p;
				free (p1);
			}
			else if (p->next == NULL) {
				NodeDiem* p1 = dsdiem.head;
				while (p1->next != p)
					p1 = p1->next;
				p1->next = NULL;
				free (p);
				return dsdiem;
			}
			else {
				NodeDiem* p1 = dsdiem.head;
				NodeDiem* p2 = dsdiem.head;
				while (p1 != p)
					p1 = p1->next;
				while (p2->next != p1)
					p2 = p2->next;
				p = p->next;
				p2->next = p1->next;
				free (p1);
			}
		}
		else
			p = p->next;
	}
	printf("\nDa xoa tat ca cac ban ghi diem thi cua hoc phan %s", mahp);
	fprintf(f, "\nDa xoa tat ca cac ban ghi diem thi cua hoc phan %s", mahp);
	return dsdiem;
}

// Ham cap nhat thong tin cho diem thi (chi cap nhat diem thi)
DSDiem UpdateDiemThi (DSDiem &dsdiem, char mssv[20], char mahp[20], float diem) {
	int index = TimKiemDiem(dsdiem, mssv, mahp);
	NodeDiem* p = dsdiem.head;
	while (index > 0) {
		p = p->next;
		index--;
	}
	diem = round(2*diem)/2; // Lam tron a den le 0.5
	p->data.DiemHP = diem;
	printf("\n Da cap nhat ban ghi diem thi MSSV %s MaHP %s", mssv, mahp);
	fprintf(f, "\n Da cap nhat ban ghi diem thi MSSV %s MaHP %s", mssv, mahp);
	return dsdiem;
}

// Ham xoa ban ghi diem thi
DSDiem DeleteDiemThi (DSDiem &dsdiem, char mssv[20], char mahp[20]) {
	int index = TimKiemDiem(dsdiem, mssv, mahp);
	int index1 = index;
	NodeDiem* p = dsdiem.head;
	NodeDiem* p1 = dsdiem.head;
	while (index > 0) {
		p = p->next;
		index--;
	}
	if (index1 == 0) {
		dsdiem.head = p->next;
		free (p);
		printf("\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
		fprintf(f, "\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
		return dsdiem;
	}
	if (p->next == NULL) {
		while (p1->next != p)
			p1 = p1->next;
		p1->next = NULL;
		free (p);
		printf("\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
		fprintf(f, "\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
		return dsdiem;
	}
	while (p1->next != p)
		p1 = p1->next;
	p1->next = p->next;
	free (p);
	printf("\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
	fprintf(f, "\nDa xoa ban ghi diem MSSV: %s, MaHP: %s", mssv, mahp);
	return dsdiem;
}
