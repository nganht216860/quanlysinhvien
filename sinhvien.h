#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "program.h"
#include "cautrucdoituong.h"

DSSV KhoiTaoDanhSachSV ();

// Tim kiem sinh vien trong danh sach theo MSSV
int TimKiemSV (DSSV &dssv, char mssv[20]);

// Tao node Sinh Vien
NodeSV* TaoNodeSV (char mssv[20]);

// Tao node CPA
NodeCPA* TaoNodeCPA (char mssv[20]);

void NormalizeName(char* name);

void ChuanHoaSV(SinhVien *sv);

const char* GetTen(char* Ten);

void SapXepSV(DSSV &dssv);

DSSV ThemNodeSV (DSSV &dssv);

void DuyetDSSV (DSSV &dssv);

float Convert4(float &diem);

DSSV CapNhapCPA (DSSV &dssv, char mssv[20], DSDiem &dsdiem, DSHP &dshp);

DSSV CapNhapSV (DSSV &dssv, char mssv[20], char NewMSSV[20]);

DSSV XoaSV (DSSV &dssv, char mssv[20]);

#endif
