#ifndef GHIVAOFILE_H
#define GHIVAOFILE_H

#include "program.h"
#include "cautrucdoituong.h"
#include "sinhvien.h"

// Ham ghi vao file nhi phan DSSV
void WriteBin_DSSV (DSSV &dssv);

// Ham ghi vao file text DSSV
void WriteTxt_DSSV (DSSV &dssv);

// Ham doc DDSV tu file nhi phan
DSSV ReadBin_DSSV (DSSV &dssv);

// Ham ghi vao file nhi phan DSHP
void WriteBin_DSHP (DSHP &dshp);

// Ham ghi vao file text DSHP
void WriteTxt_DSHP (DSHP &dshp);

// Ham doc DSHP tu file nhi phan
DSHP ReadBin_DSHP (DSHP &dshp);

// Ham ghi vao file nhi phan DS Diem Thi
void WriteBin_DSDiem (DSDiem &dsdiem);

// Ham ghi vao file text DS Diem Thi
void WriteTxt_DSDiem (DSDiem &dsdiem);

// Ham doc DS Diem Thi tu file nhi phan
DSDiem ReadBin_DSDiem (DSDiem &dsdiem);

// Ham ghi vao file nhi phan DS CPA cua SV
void WriteBin_DSCPA (DSSV &dssv);

// Ham ghi vao file text DS CPA cua SV
void WriteTxt_DSCPA (DSSV &dssv);


#endif
