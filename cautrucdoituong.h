#ifndef CAUTRUCDOITUONG_H
#define CAUTRUCDOITUONG_H

typedef struct NgayThangNam {
	char Ngay [5];
	char Thang [5];
	char Nam [7];
} DDMMYYYY;

// Cau truc du lieu Sinh Vien
typedef struct SinhVien {
	char MSSV [20];
	char Ho [30];
	char Ten [30];
	char GioiTinh [20];
	DDMMYYYY NgaySinh;
} SV;

// Node SV
typedef struct NodeSinhVien {
	SV data;
	struct NodeSinhVien* next;
} NodeSV;

// Cau truc du lieu CPA
typedef struct TrungBinhTichLuy {
	char MSSV [20];
	unsigned int TC_tich_luy;
	float cpa;
} TBTL;

// Node CPA
typedef struct NodeTBTL {
	TBTL data;
	struct NodeTBTL* next;
} NodeCPA;

// Cau truc du lieu danh sach sinh vien
typedef struct DanhSachSinhVien {
	NodeSV* head;
	NodeCPA* headCPA;
} DSSV;

// Cau truc du lieu Hoc Phan
typedef struct HocPhan {
	char MaHP [20];
	char TenHP [50];
	unsigned int SoTC;
} HP;

// Node HP
typedef struct NodeHocPhan {
	HP data;
	struct NodeHocPhan* next;
} NodeHP;

// Cau truc du lieu danh sach hoc phan
typedef struct DanhSachHocPhan {
	NodeHP* head;
} DSHP;

// Cau truc du lieu Diem Thi
typedef struct DiemThi {
	char MaHP [20];
	char MSSV [20];
	float DiemHP;
} Diem;

// Node Diem Thi
typedef struct NodeDiemThi {
	Diem data;
	struct NodeDiemThi* next;
} NodeDiem;

// Cau truc du lieu danh sach diem thi
typedef struct DanhSachDiemThi {
	NodeDiem* head;
} DSDiem;
#endif
