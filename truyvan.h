#ifndef TRUYVAN_H
#define TRUYVAN_H

#include "program.h"

#include "hocphan.h"
#include "sinhvien.h"
#include "diemthi.h"
#include "ghivaofile.h"

extern DSSV DHBK_SV;
extern DSHP DHBK_HP;
extern DSDiem DHBK_Diem;

// Ham cap nhat thong tin sinh vien
void CapNhatSV (DSSV &dssv, DSDiem &dsdiem);

// Ham cap nhat thong tin hoc phan
void CapNhatHP (DSHP &dshp, DSDiem &dsdiem);

// Ham cap nhat diem thi
void CapNhatDiem (DSDiem &dsdiem);

// Ham xoa sinh vien
void XoaSV (DSSV &dssv, DSDiem &dsdiem);

// Ham xoa hoc phan
void XoaHP (DSHP &dshp, DSDiem &dsdiem);

// Ham xoa ban ghi diem thi
void XoaDiem (DSDiem &dsdiem);

// Ham ghi CPA cua sinh vien ra file .bin va .txt
void File_CPA_SV(DSSV &dssv, DSDiem &dsdiem, DSHP &dshp);

// Ham hien thi nhung sinh vien khong dat hoc phan duoc nhap vao
void n_SV_ko_dat_hoc_phan(DSSV &dssv, DSHP &dshp, DSDiem &dsdiem);

// Ham hien thi nhung hoc phan ma sinh vien duoc nhap vao khong dat
void SV_ko_dat_n_hoc_phan(DSSV &dssv, DSHP &dshp, DSDiem &dsdiem);

// Ham hien thi CPA cua sinh vien duoc nhap vao
void Display_CPA (DSSV &dssv, DSHP &dshp, DSDiem &dsdiem);

#endif
