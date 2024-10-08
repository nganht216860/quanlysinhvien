#include "ghivaofile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Ham ghi vao file nhi phan DSSV
void WriteBin_DSSV (DSSV &dssv) {
	FILE* fp = fopen ("DSSV.bin","wb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	NodeSV* p = dssv.head;
	while (p != NULL) {
		fwrite (&p->data, sizeof(SV), 1, fp);
		p = p->next;
	}
	fclose (fp);
}

// Ham ghi vao file text DSSV
void WriteTxt_DSSV (DSSV &dssv) {
	FILE* fp = fopen ("DSSV.txt","w");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	if (dssv.head == NULL) {
		fprintf(fp, "\nDanh sach rong");
		return;
	}
	NodeSV* p = dssv.head;
	char Hoten [40];
	fprintf(fp, "\nDanh sach sinh vien:");
	fprintf(fp, "\n------------------------------------------------------------------------------");
	fprintf(fp, "\n|  STT  |   MSSV   |             Ho ten             | Gioi tinh | Ngay sinh  |");
	fprintf(fp, "\n|-------|----------|--------------------------------|-----------|------------|");
	int count = 0;
	while (p != NULL) {
		count++;
		strcpy(Hoten, p->data.Ho);
		strcat(Hoten, " ");
		strcat(Hoten, p->data.Ten);
		fprintf(fp, "\n| %5d | %8s | %30s | %9s | %2s-%2s-%4s |", count,p->data.MSSV, Hoten, p->data.GioiTinh, p->data.NgaySinh.Ngay, p->data.NgaySinh.Thang, p->data.NgaySinh.Nam);
		if (p->next == NULL)
			fprintf(fp, "\n------------------------------------------------------------------------------");
		else
			fprintf(fp, "\n|-------|----------|--------------------------------|-----------|------------|");
		p = p->next;
	}
	fclose (fp);
}

// Ham doc DDSV tu file nhi phan
DSSV ReadBin_DSSV (DSSV &dssv) {
	FILE* fp = fopen ("DSSV.bin","rb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return dssv;
	}
	SV infor;
	while (fread (&infor, sizeof(SV), 1, fp) > 0) {
		NodeSV* p = (NodeSV*)malloc(sizeof(NodeSV));
		p->data = infor;
		p->next = NULL;
		if (dssv.head == NULL)
			dssv.head = p;
		else {
			p->next = dssv.head;
			dssv.head = p;
		}
		// Them node CPA di kem
		NodeCPA* q = TaoNodeCPA(p->data.MSSV);
		if (dssv.headCPA == NULL)
			dssv.headCPA = q;
		else {
			q->next = dssv.headCPA;
			dssv.headCPA = q;
		}
	}
	fclose (fp);
	return dssv;
}

// Ham ghi vao file nhi phan DSHP
void WriteBin_DSHP (DSHP &dshp) {
	FILE* fp = fopen ("DSHP.bin","wb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	NodeHP* p = dshp.head;
	while (p != NULL) {
		fwrite (&p->data, sizeof(HP), 1, fp);
		p = p->next;
	}
	fclose (fp);
}

// Ham ghi vao file text DSHP
void WriteTxt_DSHP (DSHP &dshp) {
	FILE* fp = fopen ("DSHP.txt","w");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	if (dshp.head == NULL) {
		fprintf(fp, "\nDanh sach rong");
		return;
	}
	NodeHP* p = dshp.head;
	fprintf(fp, "\nDanh sach hoc phan:");
	fprintf(fp, "\n---------------------------------------------------------------");
	fprintf(fp, "\n|  STT  |   MaHP   |           Ten hoc phan           | So TC |");
	fprintf(fp, "\n|-------|----------|----------------------------------|-------|");
	int count = 0;
	while (p != NULL) {
		count++;
		fprintf(fp, "\n| %5d | %8s | %32s | %5d |", count, p->data.MaHP, p->data.TenHP, p->data.SoTC);
		if (p->next == NULL)
			fprintf(fp, "\n---------------------------------------------------------------");
		else
			fprintf(fp, "\n|-------|----------|----------------------------------|-------|");
		p = p->next;
	}
	fclose (fp);
}

// Ham doc DSHP tu file nhi phan
DSHP ReadBin_DSHP (DSHP &dshp) {
	FILE* fp = fopen ("DSHP.bin","rb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return dshp;
	}
	HP infor;
	while (fread (&infor, sizeof(HP), 1, fp) > 0) {
		NodeHP* p = (NodeHP*)malloc(sizeof(NodeHP));
		p->data = infor;
		p->next = NULL;
		if (dshp.head == NULL)
			dshp.head = p;
		else {
			p->next = dshp.head;
			dshp.head = p;
		}
	}
	fclose (fp);
	return dshp;
}

// Ham ghi vao file nhi phan DS Diem Thi
void WriteBin_DSDiem (DSDiem &dsdiem) {
	FILE* fp = fopen ("DSDiem.bin","wb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	NodeDiem* p = dsdiem.head;
	while (p != NULL) {
		fwrite (&p->data, sizeof(Diem), 1, fp);
		p = p->next;
	}
	fclose (fp);
}

// Ham ghi vao file text DS Diem Thi
void WriteTxt_DSDiem (DSDiem &dsdiem) {
	FILE* fp = fopen ("DSDiem.txt","w");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	if (dsdiem.head == NULL) {
		fprintf(fp, "\nDanh sach rong");
		return;
	}
	NodeDiem* p = dsdiem.head;
	fprintf(fp, "\nDanh sach diem thi:");
	fprintf(fp, "\n-----------------------------------------");
	fprintf(fp, "\n|  STT  | Ma hoc phan |   MSSV   | Diem |");
	fprintf(fp, "\n|-------|-------------|----------|------|");
	int count = 0;
	while (p != NULL) {
		count++;
		fprintf(fp, "\n| %5d |  %9s  | %8s | %4.1f |", count, p->data.MaHP, p->data.MSSV, p->data.DiemHP);
		if (p->next == NULL)
			fprintf(fp, "\n-----------------------------------------");
		else
			fprintf(fp, "\n|-------|-------------|----------|------|");
		p = p->next;
	}
	fclose (fp);
}

// Ham doc DS Diem Thi tu file nhi phan
DSDiem ReadBin_DSDiem (DSDiem &dsdiem) {
	FILE* fp = fopen ("DSDiem.bin","rb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return dsdiem;
	}
	Diem infor;
	while (fread (&infor, sizeof(Diem), 1, fp) > 0) {
		NodeDiem* p = (NodeDiem*)malloc(sizeof(NodeDiem));
		p->data = infor;
		p->next = NULL;
		if (dsdiem.head == NULL)
			dsdiem.head = p;
		else {
			p->next = dsdiem.head;
			dsdiem.head = p;
		}
	}
	fclose (fp);
	return dsdiem;
}

// Ham ghi vao file nhi phan DS CPA cua SV
void WriteBin_DSCPA (DSSV &dssv) {
	FILE* fp = fopen ("DSCPA.bin","wb");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	NodeCPA* p = dssv.headCPA;
	while (p != NULL) {
		fwrite (&p->data, sizeof(TBTL), 1, fp);
		p = p->next;
	}
	fclose (fp);
}

// Ham ghi vao file text DS CPA cua SV
void WriteTxt_DSCPA (DSSV &dssv) {
	FILE* fp = fopen ("DSCPA.txt","w");
	if (fp == NULL) {
		printf("\nKhong the mo file");
		return;
	}
	if (dssv.headCPA == NULL) {
		fprintf(fp, "\nDanh sach rong");
		return;
	}
	NodeCPA* p = dssv.headCPA;
	fprintf(fp, "\nDanh sach CPA cua sinh vien:");
	fprintf(fp, "\n----------------------------------------------");
	fprintf(fp, "\n|  STT  |   MSSV   |So TC tich luy| Diem CPA |");
	fprintf(fp, "\n|-------|----------|--------------|----------|");
	int count = 0;
	while (p != NULL) {
		count++;
		fprintf(fp, "\n| %5d | %8s |     %4d     |   %2.2f   |", count, p->data.MSSV, p->data.TC_tich_luy, p->data.cpa);
		if (p->next == NULL)
			fprintf(fp, "\n----------------------------------------------");
		else
			fprintf(fp, "\n|-------|----------|--------------|----------|");
		p = p->next;
	}
	fclose (fp);
}
