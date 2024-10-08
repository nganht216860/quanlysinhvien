#include "hocphan.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Tao danh sach Hoc Phan
DSHP KhoiTaoDanhSachHP () {
	DSHP dshp;
	dshp.head = NULL;
	return dshp;
}

// Tim kiem hoc phan trong danh sach theo MaHP
int TimKiemHP (DSHP &dshp, char mahp[20]) {
	int index = 0;
	NodeHP* p = dshp.head;
	while (p != NULL) {
		if (strcmp(mahp, p->data.MaHP) == 0)
			break;
		p = p->next;
		index++;
	}
	if (p == NULL)
		return -1;
	return index;
}

// Tao node Hoc Phan
NodeHP* TaoNodeHP (char mahp[20]) {
	NodeHP* NewHP = (NodeHP*)malloc(sizeof(NodeHP));
	strcpy (NewHP->data.MaHP,mahp);
	NewHP->next = NULL;
	return NewHP;
}

// Them node Hoc Phan vao danh sach
DSHP ThemNodeHP (DSHP &dshp) {
	char mahp [20];
	printf("\nNhap Ma hoc phan ma ban muon bo sung: ");
	fprintf(f, "\nNhap Ma hoc phan ma ban muon bo sung: ");
	scanf("%s", &mahp); fprintf(f, "%s\n", mahp);
	if (TimKiemHP(dshp, mahp) != -1) {
		printf("\nDa ton tai MaHP %s", mahp);
		fprintf(f, "\nDa ton tai MaHP %s", mahp);
		return dshp;
	}
	printf("Nhap thong tin cua hoc phan moi: ");
	fprintf(f, "Nhap thong tin cua hoc phan moi: ");
	NodeHP* NewHP = TaoNodeHP(mahp);
	printf("\nNhap ten hoc phan: "); fflush(stdin);
	fprintf(f, "\nNhap ten hoc phan: "); fflush(stdin); gets(NewHP->data.TenHP);
	fprintf(f, "%s\n", NewHP->data.TenHP);
	printf("Nhap so tin chi: "); fprintf(f, "Nhap so tin chi: ");
	do {
		scanf("%d",&NewHP->data.SoTC);
		fprintf(f, "%d\n", NewHP->data.SoTC);
		if (NewHP->data.SoTC < 0)
			printf("Nhap sai, moi nhap lai: ");
			fprintf(f, "Nhap sai, moi nhap lai: ");
	} while (NewHP->data.SoTC < 0);
	if (dshp.head == NULL)
		dshp.head = NewHP;
	else {
		NewHP->next = dshp.head;
		dshp.head = NewHP;
	}
	printf("Da them hoc phan %s vao danh sach", mahp);
	fprintf(f, "Da them hoc phan %s vao danh sach", mahp);
	return dshp;
}

// Ham duyet danh sach Hoc Phan
void DuyetDSHP (DSHP &dshp) {
	if (dshp.head == NULL) {
		printf("\nDanh sach rong"); fprintf(f, "\nDanh sach rong");
		return;
	}
	NodeHP* p = dshp.head;
	printf("\nDanh sach hoc phan:"); fprintf(f, "\nDanh sach hoc phan:");
	printf("\n---------------------------------------------------------------");
	fprintf(f, "\n---------------------------------------------------------------");
	printf("\n|  STT  |   MaHP   |           Ten hoc phan           | So TC |");
	fprintf(f, "\n|  STT  |   MaHP   |           Ten hoc phan           | So TC |");
	printf("\n|-------|----------|----------------------------------|-------|");
	fprintf(f, "\n|-------|----------|----------------------------------|-------|");
	int count = 0;
	while (p != NULL) {
		count++;
		printf("\n| %5d | %8s | %32s | %5d |", count, p->data.MaHP, p->data.TenHP, p->data.SoTC);
		fprintf(f, "\n| %5d | %8s | %32s | %5d |", count, p->data.MaHP, p->data.TenHP, p->data.SoTC);
		if (p->next == NULL) {
			printf("\n---------------------------------------------------------------");
			fprintf(f, "\n---------------------------------------------------------------");
		}
		else {
			printf("\n|-------|----------|----------------------------------|-------|");
			fprintf(f, "\n|-------|----------|----------------------------------|-------|");
		}
		p = p->next;
	}
}

// Ham cap nhat node Hoc Phan
DSHP CapNhapHP (DSHP &dshp, char mahp[20], char NewMaHP[20]) {
	NodeHP* p = dshp.head;
	while (p != NULL) {
		if (strcmp(p->data.MaHP, mahp) == 0);
			break;
		p = p->next;
	}
	printf("\nNhap thong tin moi cua hoc phan:");
	fprintf(f, "\nNhap thong tin moi cua hoc phan:");
	printf("\nNhap ten hoc phan: "); fflush(stdin); gets(p->data.TenHP);
	fprintf(f, "%s\n", p->data.TenHP);
	printf("Nhap so tin chi: ");
	fprintf(f, "Nhap so tin chi: ");
	do {
		scanf("%d",&p->data.SoTC);
		fprintf(f, "%d\n",&p->data.SoTC);
		if (p->data.SoTC < 0)
			printf("Nhap sai, moi nhap lai: ");
			fprintf(f, "Nhap sai, moi nhap lai: ");
	} while (p->data.SoTC < 0);
	strcpy(p->data.MaHP, NewMaHP);
	printf("\nHoc phan %s da duoc cap nhat, MaHP moi: %s", mahp, p->data.MaHP);
	fprintf(f, "\nHoc phan %s da duoc cap nhat, MaHP moi: %s", mahp, p->data.MaHP);
	return dshp;
}

// Ham xoa node Hoc Phan
DSHP XoaHP (DSHP &dshp, char mshp[20]) {
	NodeHP* p = dshp.head;
	NodeHP* p1 = dshp.head;
	int index = TimKiemHP(dshp, mshp);
	int index1 = index;
	while (index1 > 0) {
		p = p->next;
		index1--;
	}
	if (index == 0) {
		dshp.head = p->next;
		free (p);
		printf("\nDa xoa MSHP %s", mshp);
		fprintf(f, "\nDa xoa MSHP %s", mshp);
		return dshp;
	}
	if (p->next == NULL) {
		while (p1->next != p)
			p1 = p1->next;
		p1->next = NULL;
		free (p);
		printf("\nDa xoa MSHP %s", mshp);
		fprintf(f, "\nDa xoa MSHP %s", mshp);
		return dshp;
	}
	while (p1->next != p)
		p1 = p1->next;
	p1->next = p->next;
	free (p);
	printf("\nDa xoa MSHP %s", mshp);
	fprintf(f, "\nDa xoa MSHP %s", mshp);
	return dshp;
}
