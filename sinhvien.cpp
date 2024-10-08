#include "sinhvien.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

DSSV KhoiTaoDanhSachSV () {
	DSSV dssv;
	dssv.head = NULL;
	dssv.headCPA = NULL;
	return dssv;
}
// Tim kiem sinh vien trong danh sach theo MSSV
int TimKiemSV (DSSV &dssv, char mssv[20]) {
	int index = 0;
	NodeSV* p = dssv.head;
	while (p != NULL) {
		if (strcmp(mssv, p->data.MSSV) == 0)
			break;
		p = p->next;
		index++;
	}
	if (p == NULL)
		return -1;
	return index;
}


// Tao node Sinh Vien
NodeSV* TaoNodeSV (char mssv[20]) {
	NodeSV* NewSV = (NodeSV*)malloc(sizeof(NodeSV));
	strcpy (NewSV->data.MSSV,mssv);
	NewSV->next = NULL;
	return NewSV;
}

// Tao node CPA
NodeCPA* TaoNodeCPA (char mssv[20]) {
	NodeCPA* NewCPA = (NodeCPA*)malloc(sizeof(NodeCPA));
	strcpy (NewCPA->data.MSSV, mssv);
	NewCPA->next = NULL;
	return NewCPA;
}

// Hàm chuẩn hóa tên bằng cách viết hoa chữ cái đầu tiên của mỗi từ
void NormalizeName(char* name) {
    int len = strlen(name);
    if (len == 0) return;

    // Viết hoa chữ cái đầu tiên
    name[0] = toupper(name[0]);

    for (int i = 1; i < len; i++) {
        if (name[i] == ' ') {
            // Nếu ký tự hiện tại là khoảng trắng, hãy viết hoa chữ cái đầu tiên của từ tiếp theo
            if (i + 1 < len) {
                name[i + 1] = toupper(name[i + 1]);
                i++; // Bỏ qua ký tự tiếp theo vì nó đã được viết hoa

            }
        } else {
            //Chuyển các ký tự khác thành chữ thường
            name[i] = tolower(name[i]);
        }
    }
}

void ChuanHoaSV(SV* sv) {
    // Chuẩn hóa Ho
    NormalizeName(sv->Ho);

    // Chuẩn hóa Ten
    NormalizeName(sv->Ten);
}

// Ham lay Ten SV
const char* GetTen(char* Ten) {
    const char* lastSpace = strrchr(Ten, ' ');
    if (lastSpace != NULL)
        return lastSpace + 1; // con trỏ đến ký tự đầu tiên sau dấu cách
    else
        return Ten;
}

void SapXepSV(DSSV &dssv) {
    if (dssv.head == NULL || dssv.head->next == NULL) {
        return;
    }

    NodeSV* current;
    NodeCPA* currentCPA;
    int swapped;
    do {
        swapped = 0;
        current = dssv.head;
        currentCPA = dssv.headCPA;

        while (current->next != NULL) {
                if(strcmp(GetTen(current->data.Ten), GetTen(current->next->data.Ten))>0){
            //if (strcmp(current->data.Ten, current->next->data.Ten) > 0) {
                SV temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                TBTL tempCPA = currentCPA->data;
                currentCPA->data = currentCPA->next->data;
                currentCPA->next->data = tempCPA;

                swapped = 1;
            }
            current = current->next;
            currentCPA = currentCPA->next;
        }
    } while (swapped);
}


// Them node Sinh Vien va node CPA di kem vao danh sach
DSSV ThemNodeSV (DSSV &dssv) {
	char mssv [20];
	printf("\nNhap MSSV ma ban muon bo sung: ");
	fprintf(f, "\nNhap MSSV ma ban muon bo sung: ");
	scanf("%s", &mssv); fprintf(f, "%s\n", mssv);
	if (TimKiemSV(dssv, mssv) != -1) {
		printf("\nDa ton tai MSSV %s", mssv);
		fprintf(f, "\nDa ton tai MSSV %s", mssv);
		return dssv;
	}
	printf("Nhap thong tin cua sinh vien moi:"); fprintf(f, "Nhap thong tin cua sinh vien moi:");
	// Tao va them node Sinh Vien, Sinh Vien CPA;
	NodeSV* NewSV = TaoNodeSV(mssv);
	NodeCPA* NewCPA= TaoNodeCPA(mssv);
	printf("\nNhap ho dem: "); fprintf(f, "\nNhap ho: "); fflush(stdin); gets(NewSV->data.Ho);
	fprintf(f, "%s\n", NewSV->data.Ho);
	printf("Nhap ten: "); fprintf(f, "Nhap ten: "); fflush(stdin); gets(NewSV->data.Ten);
	fprintf(f, "%s\n", NewSV->data.Ten);
	printf("Nhap gioi tinh: "); fprintf(f, "Nhap gioi tinh: "); scanf("%s",&NewSV->data.GioiTinh);
	fprintf(f, "%s\n", NewSV->data.GioiTinh);
	printf("Nhap ngay sinh: "); fprintf(f, "Nhap ngay sinh: "); scanf("%s",&NewSV->data.NgaySinh.Ngay);
	fprintf(f, "%s\n", NewSV->data.NgaySinh.Ngay);
	printf("Nhap thang sinh: "); fprintf(f, "Nhap thang sinh: "); scanf("%s",&NewSV->data.NgaySinh.Thang);
	fprintf(f, "%s\n", NewSV->data.NgaySinh.Thang);
	printf("Nhap nam sinh: "); fprintf(f, "Nhap nam sinh: "); scanf("%s",&NewSV->data.NgaySinh.Nam);
	fprintf(f, "%s\n", NewSV->data.NgaySinh.Nam);
	NewCPA->data.cpa = 0.00; NewCPA->data.TC_tich_luy = 0;
	ChuanHoaSV(&NewSV->data);
    NodeSV* prev = NULL;
    NodeCPA* prevCPA = NULL;
    NodeSV* current = dssv.head;
    NodeCPA* currentCPA = dssv.headCPA;
    while (true) {
        if (current == NULL) break;
        else {
            //int cmpTen = strcmp(NewSV->data.Ten, current->data.Ten);
            int cmpTen = strcmp(GetTen(NewSV->data.Ten), GetTen(current->data.Ten));
            // int cmpHo = strcmp(NewSV->data.Ho, current->data.Ho);
            if (cmpTen < 0) break;
           // else if (cmpTen == 0)
                //if (cmpHo < 0) break;
            //
        }
        prev = current;
        prevCPA = currentCPA;
        current = current->next;
        currentCPA = currentCPA->next;
    }
    if (prev == NULL) {
        // Them vao dau danh sach
        NewSV->next = dssv.head;
        NewCPA->next = dssv.headCPA;
        dssv.head = NewSV;
        dssv.headCPA = NewCPA;
    } else {
        prev->next = NewSV;
        prevCPA->next = NewCPA;
        NewSV->next = current;
        NewCPA->next = currentCPA;
    }
	printf("Da them MSSV %s vao danh sach", mssv); fprintf(f, "Da them MSSV %s vao danh sach", mssv);
	return dssv;
}

// Ham duyet danh sach sinh vien
void DuyetDSSV (DSSV &dssv) {
	if (dssv.head == NULL) {
		printf("\nDanh sach rong"); fprintf(f, "\nDanh sach rong");
		return;
	}
	NodeSV* p = dssv.head;
	char Hoten [40];
	printf("\nDanh sach sinh vien:"); fprintf(f, "\nDanh sach sinh vien:");
	printf("\n------------------------------------------------------------------------------");
	fprintf(f, "\n------------------------------------------------------------------------------");
	printf("\n|  STT  |   MSSV   |             Ho ten             | Gioi tinh | Ngay sinh  |");
	fprintf(f, "\n|  STT  |   MSSV   |             Ho ten             | Gioi tinh | Ngay sinh  |");
	printf("\n|-------|----------|--------------------------------|-----------|------------|");
	fprintf(f, "\n|-------|----------|--------------------------------|-----------|------------|");
	int count = 0;
	while (p != NULL) {
		count ++;
		strcpy(Hoten, p->data.Ho);
		strcat(Hoten, " ");
		strcat(Hoten, p->data.Ten);
		printf("\n| %5d | %8s | %30s | %9s | %2s-%2s-%4s |", count,p->data.MSSV, Hoten, p->data.GioiTinh, p->data.NgaySinh.Ngay, p->data.NgaySinh.Thang, p->data.NgaySinh.Nam);
		fprintf(f, "\n| %5d | %8s | %30s | %9s | %2s-%2s-%4s |", count,p->data.MSSV, Hoten, p->data.GioiTinh, p->data.NgaySinh.Ngay, p->data.NgaySinh.Thang, p->data.NgaySinh.Nam);
		if (p->next == NULL) {
			printf("\n------------------------------------------------------------------------------");
			fprintf(f, "\n------------------------------------------------------------------------------");
		}
		else {
			printf("\n|-------|----------|--------------------------------|-----------|------------|");
			fprintf(f, "\n|-------|----------|--------------------------------|-----------|------------|");
		}
		p = p->next;
	}
}

// Ham doi diem thang 10 ve diem thang 4
float Convert4(float &diem) {
	float diemt4;
	if (diem >= 8.5){
		diemt4 = 4;
	}
	else if (diem >= 8) {
		diemt4 = 3.5;
	}
	else if (diem >= 7) {
		diemt4 = 3;
	}
	else if (diem >= 6.5){
		diemt4 = 2.5;
	}
	else if (diem >= 5.5){
		diemt4 = 2;
	}
	else if (diem >= 5) {
			diemt4 = 1.5;
	}
	else if (diem >= 4){
		diemt4 = 1;
	}
	else
		diemt4 = 0;
	return diemt4;
}

// Ham cap nhat CPA cho sinh vien
DSSV CapNhapCPA (DSSV &dssv, char mssv[20], DSDiem &dsdiem, DSHP &dshp) {
	NodeCPA* p = dssv.headCPA;
	if (p == NULL) {
		printf("\nDanh sach rong"); fprintf(f, "\nDanh sach rong");
		return dssv;
	}
	while (p != NULL) {
		if (strcmp(mssv, p->data.MSSV) == 0)
			break;
		p = p->next;
	}
	if (p == NULL) {
		printf("\nKhong ton tai MSSV %s", mssv);
		fprintf(f, "\nKhong ton tai MSSV %s", mssv);
		return dssv;
	}
	NodeDiem* q = dsdiem.head;
	float diemthi_nhan_sotc = 0.00;
	p->data.TC_tich_luy = 0;
	while (q != NULL) {
		if (strcmp(q->data.MSSV, mssv) == 0) {
			NodeHP* r = dshp.head;
			float diemthi = q->data.DiemHP;
			char mahp [20];
			strcpy(mahp,q->data.MaHP);
			while (r != NULL) {
				if (strcmp(r->data.MaHP, mahp) == 0)
					break;
				r = r->next;
			}
			diemthi = Convert4(diemthi);
			diemthi_nhan_sotc += (r->data.SoTC)*(diemthi);
			p->data.TC_tich_luy += r->data.SoTC;
		}
		q = q->next;
	}
	if (p->data.TC_tich_luy == 0)
		p->data.cpa = 0.00;
	else
		p->data.cpa = diemthi_nhan_sotc/(p->data.TC_tich_luy);
	p->data.cpa = round(100*(p->data.cpa))/100;
	printf ("\nCPA cua MSSV %s da duoc cap nhat", mssv);
	fprintf (f, "\nCPA cua MSSV %s da duoc cap nhat", mssv);
	return dssv;
}

// Ham cap nhat node SV
DSSV CapNhapSV (DSSV &dssv, char mssv[20], char NewMSSV[20]) {
	NodeSV* p = dssv.head;
	NodeCPA* q = dssv.headCPA;
	while (p != NULL) {
		if (strcmp(p->data.MSSV, mssv) == 0)
			break;
		p = p->next; q = q->next;
	}
	printf("\nNhap thong tin moi cua SV:");
	fprintf(f, "\nNhap thong tin moi cua SV:");
	printf("\nNhap ho: "); fprintf(f, "\nNhap ho: "); fflush(stdin); gets(p->data.Ho);
	fprintf(f, "%s\n", p->data.Ho);
	printf("Nhap ten: "); fprintf(f, "Nhap ten: "); fflush(stdin); gets(p->data.Ten);
	fprintf(f, "%s\n", p->data.Ten);
	printf("Nhap gioi tinh: "); fprintf(f, "Nhap gioi tinh: "); scanf("%s",&p->data.GioiTinh);
	fprintf(f, "%s\n", p->data.GioiTinh);
	printf("Nhap ngay sinh: "); fprintf(f, "Nhap ngay sinh: "); scanf("%s",&p->data.NgaySinh.Ngay);
	fprintf(f, "%s\n", p->data.NgaySinh.Ngay);
	printf("Nhap thang sinh: "); fprintf(f, "Nhap thang sinh: "); scanf("%s",&p->data.NgaySinh.Thang);
	fprintf(f, "%s\n", p->data.NgaySinh.Thang);
	printf("Nhap nam sinh: "); fprintf(f, "Nhap nam sinh: "); scanf("%s",&p->data.NgaySinh.Nam);
	fprintf(f, "%s\n", p->data.NgaySinh.Nam);
	strcpy(p->data.MSSV, NewMSSV); // Sinh vien
	strcpy(q->data.MSSV, NewMSSV); // CPA sinh vien


	printf("\nSinh vien %s da duoc cap nhat, MSSV moi: %s", mssv, p->data.MSSV);
	fprintf(f, "\nSinh vien %s da duoc cap nhat, MSSV moi: %s", mssv, p->data.MSSV);
	SapXepSV(dssv);
	return dssv;
}

// Ham xoa sinh vien va xoa CPA sinh vien di kem
DSSV XoaSV (DSSV &dssv, char mssv[20]) {
	NodeSV* p = dssv.head;
	NodeSV* p1 = dssv.head;
	NodeCPA* q = dssv.headCPA;
	NodeCPA* q1 = dssv.headCPA;
	int index = TimKiemSV(dssv, mssv);
	int index1 = index;
	while (index1 > 0) {
		p = p->next;
		q = q->next;
		index1--;
	}
	if (index == 0) {
		dssv.head = p->next;
		dssv.headCPA = q->next;
		free (p);
		free (q);
		printf("\nDa xoa MSSV %s", mssv); fprintf(f, "\nDa xoa MSSV %s", mssv);
		return dssv;
	}
	if (p->next == NULL) {
		while (p1->next != p)
			p1 = p1->next;
		while (q1->next != q)
			q1 = q1->next;
		p1->next = NULL;
		q1->next = NULL;
		free (p);
		free (q);
		printf("\nDa xoa MSSV %s", mssv);
		fprintf(f, "\nDa xoa MSSV %s", mssv);
		return dssv;
	}
	while (p1->next != p)
		p1 = p1->next;
	while (q1->next != q)
		q1 = q1->next;
	p1->next = p->next;
	q1->next = q->next;
	free (p);
	free (q);
	printf("\nDa xoa MSSV %s", mssv);
	fprintf(f, "\nDa xoa MSSV %s", mssv);
	SapXepSV(dssv);
	return dssv;
}
