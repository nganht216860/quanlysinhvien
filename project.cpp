#include "program.h"
#include "cautrucdoituong.h"
#include "diemthi.h"
#include "ghivaofile.h"
#include "hocphan.h"
#include "sinhvien.h"
#include "truyvan.h"

void TieuDe() {
	system("cls");
	printf("\n===========Chuong trinh quan li sinh vien Dai hoc Bach Khoa Ha Noi===========\n");
    printf("Date of Examination: 23/07/2023\n");
    printf("Student Name: Hoang Thi Ngan\n");
    printf("Student Number: 20216860\n");
	fprintf(f, "\n\n===========Chuong trinh quan li sinh vien Dai hoc Bach Khoa Ha Noi===========\n");
	fprintf(f, "Date of Examination: 23/07/2023\n");
    fprintf(f, "Student Name: Hoang Thi Ngan\n");
    fprintf(f, "Student Number: 20216860\n");

}
void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ThongBao () {
	printf("\n\nNhan phim bat ki de tiep tuc!");
	fprintf(f, "\n\nNhan phim bat ki de tiep tuc!");
	getch();
}

void Display_Menu(int n, char *options[], int choice) {
    for (int i = 0; i < n; i++) {
        if (i + 1 == choice) {
            color(159); // Set color for the selected option
        }
        printf("%d. %s\n", i + 1, options[i]);
        fprintf(f, "%d. %s\n", i + 1, options[i]);
        color(7); // Set the default color after printing the option
    }
}


int Get_Key(int choice, int n) {
    int ch = getch(); // Doc phim mui
    int result = -1;
    switch(ch) {
    case 224: // La phim mui ten
        ch = getch();
        if (ch == 80) { // Mui ten xuong
            choice++;
            if (choice > n) choice = 1;
        } else if (ch == 72) { // Mui ten len
            choice--;
            if (choice < 1) choice = n;
        }
        result = choice;
        break;
    case 13: // La phim Enter
        result = 0;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

void Display_Main (int choice) {
	printf("Lua chon theo huong dan ben duoi de thuc hien chuc nang:\n");
    char *options[6] = {
        "Hien thi danh sach",
        "Bo sung vao danh sach",
        "Cap nhat ban ghi",
        "Xoa ban ghi",
        "Truy van mot so thong tin",
        "Thoat chuong trinh"
    };
    Display_Menu(6, options, choice);
}

void Display_Main_1 (int choice) {
	printf("Chon danh sach ban muon hien thi:\n");
    char *options[4] = {
        "Danh sach sinh vien",
        "Danh sach hoc phan",
        "Danh sach diem thi",
        "Quay tro lai menu truoc"
    };
	Display_Menu(4, options, choice);
}

void Display_Main_2 (int choice) {
	printf("Chon danh sach ban muon bo sung:\n");
    char *options[4] = {
        "Danh sach sinh vien",
        "Danh sach hoc phan",
        "Danh sach diem thi",
        "Quay tro lai menu truoc"
    };
	Display_Menu(4, options, choice);
}

void Display_Main_3 (int choice) {
	printf("Chon danh sach ban muon cap nhat:\n");
    char *options[4] = {
        "Danh sach sinh vien",
        "Danh sach hoc phan",
        "Danh sach diem thi (chi cap nhat diem)",
        "Quay tro lai menu truoc"
    };
	Display_Menu(4, options, choice);
}

void Display_Main_4 (int choice) {
	printf("Chon danh sach ban muon xoa:\n");
    char *options[4] = {
        "Danh sach sinh vien",
        "Danh sach hoc phan",
        "Danh sach diem thi",
        "Quay tro lai menu truoc"
    };
	Display_Menu(4, options, choice);
}

void Display_Main_5 (int choice) {
	printf("Chon thong tin ban muon truy van:\n");
    char *options[5] = {
        "Tinh diem CPA cua tung sinh vien va in ra file nhi phan (text)",
        "Hien thi danh sach nhung sinh vien khong dat hoc phan duoc nhap vao",
        "Hien thi danh sach nhung hoc phan ma sinh vien duoc nhap vao khong dat",
        "Hien thi diem CPA cua sinh vien duoc nhap vao",
        "Quay tro lai menu truoc"
    };
	Display_Menu(5, options, choice);
}
void Display_Main_6 (int choice) {
	printf("Ban co muon luu thay doi truoc khi thoat khong?\n");
    char *options[3] = {
        "Co",
        "Khong",
        "Quay tro lai menu truoc"
    };
	Display_Menu(3, options, choice);
}

void MainMenu () {

	int sM = 1, sM_1 = 1, sM_2 = 1, sM_3 = 1, sM_4 = 1, sM_5 = 1, sM_6 = 1;
	int kM, kM_1, kM_2, kM_3, kM_4, kM_5, kM_6;

	bool M = true;
	bool M_1, M_2, M_3, M_4, M_5, M_6;

	while (M == true) {
		TieuDe();
		Display_Main (sM);
        int kM = Get_Key(sM, 6);
        if (kM != 0) {
            if (kM > 0) sM = kM;
            continue;
        }
		switch (sM) {
			case 1: // main
				M_1 = true;
				while (M_1 == true) {
					TieuDe();
					Display_Main_1(sM_1);
					int kM_1 = Get_Key(sM_1, 4);
                    if (kM_1 != 0) {
                        if (kM_1 > 0) sM_1 = kM_1;
                        continue;
                    }
					switch (sM_1) {
						case 1: // menu 1
							DuyetDSSV(DHBK_SV);
							ThongBao();
							break;
						case 2: // menu 1
							DuyetDSHP(DHBK_HP);
							ThongBao();
							break;
						case 3: // menu 1
							DuyetDSDiem(DHBK_Diem);
							ThongBao();
							break;
						case 4: // menu 1
							M_1 = false;
							break;
					}
				}
				break; // menu 1
			case 2: // main
				M_2 = true;
				while (M_2 == true) {
					TieuDe();
					Display_Main_2(sM_2);
                    int kM_2 = Get_Key(sM_2, 4);
                    if (kM_2 != 0) {
                        if (kM_2 > 0) sM_2 = kM_2;
                        continue;
                    }
					switch (sM_2) {
						case 1: // menu 2
							DHBK_SV = ThemNodeSV(DHBK_SV);
							ThongBao();
							break;
						case 2: // menu 2
							DHBK_HP = ThemNodeHP(DHBK_HP);
							ThongBao();
							break;
						case 3: // menu 2
							DHBK_Diem = AddNodeDiem(DHBK_Diem, DHBK_SV, DHBK_HP);
							ThongBao();
							break;
						case 4: // menu 2
							M_2 = false;
							break;
					}
				}
				break;
			case 3:
				M_3 = true;
				while (M_3 == true) {
					TieuDe();
					Display_Main_3(sM_3);
					int kM_3 = Get_Key(sM_3, 4);
                    if (kM_3 != 0) {
                        if (kM_3 > 0) sM_3 = kM_3;
                        continue;
                    }
					switch (sM_3) {
						case 1: // menu 3
							CapNhatSV(DHBK_SV, DHBK_Diem);
							ThongBao();
							break;
						case 2: // menu 3
							CapNhatHP(DHBK_HP, DHBK_Diem);
							ThongBao();
							break;
						case 3: // menu 3
							CapNhatDiem(DHBK_Diem);
							ThongBao();
							break;
						case 4: // menu 3
							M_3 = false;
							break;
					}
				}
				break;
			case 4:
				M_4 = true;
				while (M_4 == true) {
					TieuDe();
					Display_Main_4(sM_4);
					int kM_4 = Get_Key(sM_4, 4);
                    if (kM_4 != 0) {
                        if (kM_4 > 0) sM_4 = kM_4;
                        continue;
                    }
					switch (sM_4) {
						case 1: // menu 4
							XoaSV(DHBK_SV, DHBK_Diem);
							ThongBao();
							break;
						case 2: // menu 4
							XoaHP(DHBK_HP, DHBK_Diem);
							ThongBao();
							break;
						case 3: // menu 4
							XoaDiem(DHBK_Diem);
							ThongBao();
							break;
						case 4: // menu 4
							M_4 = false;
							break;
					}
				}
				break;
			case 5:
				M_5 = true;
				while (M_5 == true) {
					TieuDe();
					Display_Main_5(sM_5);
					int kM_5 = Get_Key(sM_5, 5);
                    if (kM_5 != 0) {
                        if (kM_5 > 0) sM_5 = kM_5;
                        continue;
                    }
					switch (sM_5) {
						case 1: // menu 5
							File_CPA_SV(DHBK_SV, DHBK_Diem, DHBK_HP);
							ThongBao();
							break;
						case 2: // menu 5
							n_SV_ko_dat_hoc_phan(DHBK_SV, DHBK_HP, DHBK_Diem);
							ThongBao();
							break;
						case 3: // menu 5
							SV_ko_dat_n_hoc_phan(DHBK_SV, DHBK_HP, DHBK_Diem);
							ThongBao();
							break;
						case 4: // menu 5
							Display_CPA(DHBK_SV, DHBK_HP, DHBK_Diem);
							ThongBao();
							break;
						case 5: // menu 5
							M_5 = false;
							break;
					}
				}
				break;
			case 6: // main
				M_6 = true;
				while (M_6 == true) {
					TieuDe();
					Display_Main_6(sM_6);
					int kM_6 = Get_Key(sM_6, 3);
                    if (kM_6 != 0) {
                        if (kM_6 > 0) sM_6 = kM_6;
                        continue;
                    }
					switch (sM_6) {
						case 1: // menu 6
							WriteBin_DSDiem(DHBK_Diem);
							WriteBin_DSHP(DHBK_HP);
							WriteBin_DSSV(DHBK_SV);
							WriteTxt_DSDiem(DHBK_Diem);
							WriteTxt_DSHP(DHBK_HP);
							WriteTxt_DSSV(DHBK_SV);
							fclose (f);
							ThongBao();
							exit(0);
							break;
						case 2: // menu 6
							ThongBao();
							fclose (f);
							exit(0);
							break;
						case 3: // menu 6
							M_6 = false;
							break;
					}
				}
				break;
		}
	}
}
int main() {
    FILE *f = fopen("QT.txt","w");

	if (f == NULL) {
		printf("Khong the mo file QT.txt");
		return 1;
	}
	DHBK_SV = ReadBin_DSSV(DHBK_SV);
	DHBK_HP = ReadBin_DSHP(DHBK_HP);
	DHBK_Diem = ReadBin_DSDiem(DHBK_Diem);
	MainMenu();
	fclose(f);
	return 0;
}
