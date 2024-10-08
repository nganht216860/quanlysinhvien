#ifndef HOCPHAN_H
#define HOCPHAN_H

#include "program.h"
#include "cautrucdoituong.h"

DSHP KhoiTaoDanhSachHP();

int TimKiemHP(DSHP &dshp, char mahp[20]);

NodeHP* TaoNodeHP(char mahp[20]);

DSHP ThemNodeHP(DSHP &dshp);

void DuyetDSHP(DSHP &dshp);

DSHP CapNhapHP(DSHP &dshp, char mahp[20], char NewMaHP[20]);

DSHP XoaHP(DSHP &dshp, char mshp[20]);

#endif
