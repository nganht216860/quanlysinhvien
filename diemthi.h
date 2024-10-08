#ifndef DIEMTHI_H
#define DIEMTHI_H

#include "program.h"
#include "cautrucdoituong.h"
#include "truyvan.h"
#include "sinhvien.h"
#include "hocphan.h"

// #include "diemthi.h"

//Tao danh sach Diem Thi
DSDiem KhoiTaoDanhSachDiem ();

// Tim kiem Diem Thi trong danh sach theo MSSV va MaHP
int TimKiemDiem (DSDiem &dsdiem, char mssv[20], char mahp[20]);

// Tao node Diem
NodeDiem* TaoNodeDiem (char mssv[20], char mahp[20]);

// Them node Diem vao danh sach
DSDiem AddNodeDiem (DSDiem &dsdiem, DSSV &dssv, DSHP &dshp);

// Ham duyet danh sach diem thi
void DuyetDSDiem (DSDiem &dsdiem);

// Ham cap nhat MSSV moi cho danh sach diem thi
// Ham nay duoc goi ngay sau ham UpdateSV
DSDiem UpdateDiemMSSV (DSDiem &dsdiem, char mssv[20], char NewMSSV[20]);

// Ham xoa cac ban ghi diem thi sau khi co mot MSSV bi xoa di
// Ham nay duoc goi ngay sau ham DeleteSV
DSDiem DeleteDiemMSSV (DSDiem &dsdiem, char mssv[20]);

// Ham cap nhat MaHP moi cho danh sach diem thi
// Ham nay duoc goi ngay sau ham UpdateHP
DSDiem UpdateDiemMaHP (DSDiem &dsdiem, char mahp[20], char NewMaHP[20]);

// Ham xoa cac ban ghi diem thi sau khi co mot MaHP bi xoa di
// Ham nay duoc goi ngay sau ham DeleteHP
DSDiem DeleteDiemMaHP (DSDiem &dsdiem, char mahp[20]);

// Ham cap nhat thong tin cho diem thi (chi cap nhat diem thi)
DSDiem UpdateDiemThi (DSDiem &dsdiem, char mssv[20], char mahp[20], float diem);

// Ham xoa ban ghi diem thi
DSDiem DeleteDiemThi (DSDiem &dsdiem, char mssv[20], char mahp[20]);

#endif
