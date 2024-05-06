#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
const int MAX = 10000;
 
struct SinhVien {
    char masv[15];
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemGiaitich;
    float diemVatly;
    float diemLaptrinh;
    float diemTB;
    char hocluc[10];
};
 
struct SinhVien *sinhVien;
 
// Phong dao tao --------------------------------
// Hàm tao sinh vien
struct SinhVien taoSinhVien(char masv[], char ten[], char gioiTinh[], int tuoi, float diemGiaitich, float diemVatly, float diemLaptrinh) {
    struct SinhVien sv;
    strcpy(sv.masv, masv);
    strcpy(sv.ten, ten);
    strcpy(sv.gioiTinh, gioiTinh);
    sv.tuoi = tuoi;
    sv.diemGiaitich = diemGiaitich;
    sv.diemVatly = diemVatly;
    sv.diemLaptrinh = diemLaptrinh;
    sv.diemTB = (diemGiaitich + diemVatly + diemLaptrinh) / 3;
    if (sv.diemTB >= 8) {
        strcpy(sv.hocluc, "Gioi");
    }
    else if (sv.diemTB >= 6.5) {
        strcpy(sv.hocluc, "Kha");
    }
    else if (sv.diemTB >= 5) {
        strcpy(sv.hocluc, "Trung binh");
    }
    else {
        strcpy(sv.hocluc, "Yeu");
    }
    return sv;
}
 
int nhapDanhSachSinhVien(char filename[]) {
    FILE *f;
    int tuoi;
    char masv[15], ten[30], gioiTinh[5];
    float diemGiaiTich, diemVatLy, diemLapTrinh;
    int size = 0;
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("File khong ton tai, thoat chuong trinh\n");
        exit(0);
    }
    printf("Chuan bi doc file: \n");
    puts(filename);
    fscanf(f, "%d", &size);
    for (int i = 0; i < size; ++i) {
        fscanf(f, "%s", masv);
        fscanf(f, " %[^\n]s", ten);
        fscanf(f, "%s", gioiTinh);
        fscanf(f, "%d", &tuoi);
        fscanf(f, "%f", &diemGiaiTich);
        fscanf(f, "%f", &diemVatLy);
        fscanf(f, "%f", &diemLapTrinh);
        sinhVien[i] = taoSinhVien(masv, ten, gioiTinh, tuoi, diemGiaiTich, diemVatLy, diemLapTrinh);
    }
    printf("So luong sinh vien trong file là: %d\nCac sinh vien da duoc ghi la: \n", size);
    for (int i = 0; i < size; ++i) {
        printf("%d. %s\n", i + 1, sinhVien[i].ten);
    }
    fclose(f);
    return size;
}
 
// Hàm in thông tin sinh viên
void xemThongTinSinhVien(struct SinhVien sv) {
    printf("Ma sinh vien: %s\n", sv.masv);
    printf("Ten: %s\n", sv.ten);
    printf("Gioi tinh: %s\n", sv.gioiTinh);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Ðiem gioi tich: %.2f\n", sv.diemGiaitich);
    printf("Ðiem vat ly: %.2f\n", sv.diemVatly);
    printf("Ðiem lap trinh: %.2f\n", sv.diemLaptrinh);
    printf("Ðiem trung binh: %.2f\n", sv.diemTB);
    printf("Hoc luc: %s\n", sv.hocluc);
}
// ----------------------------------------------------------------
 
 
// Giang viên ----------------------------------------------------------------
 
// Hàm sua thông tin sinh viên
void suaThongTinSinhVien(struct SinhVien *sv, char ten[], char gioiTinh[], int tuoi, float diemGiaitich, float diemVatly, float diemLaptrinh) {
    if (strcmp(ten, "-1") != 0) strcpy(sv->ten, ten);
    if (strcmp(gioiTinh, "-1") != 0) strcpy(sv->gioiTinh, gioiTinh);
    if (tuoi != -1) sv->tuoi = tuoi;
    if (diemGiaitich != -1) sv->diemGiaitich = diemGiaitich;
    if (diemVatly != -1) sv->diemVatly = diemVatly;
    if (diemLaptrinh != -1) sv->diemLaptrinh = diemLaptrinh;
    sv->diemTB = (diemGiaitich + diemVatly + diemLaptrinh) / 3;
    if (sv->diemTB >= 8) {
        strcpy(sv->hocluc, "Gioi");
    }
    else if (sv->diemTB >= 6.5) {
        strcpy(sv->hocluc, "Kha");
    }
    else if (sv->diemTB >= 5) {
        strcpy(sv->hocluc, "Trung binh");
    }
    else {
        strcpy(sv->hocluc, "Yeu");
    }
}
 
// Hàm nhap diem hoc phan cua sinh viên
void nhapDiemHocPhan(struct SinhVien *sv, float diemGiaitich, float diemVatly, float diemLaptrinh) {
    if (diemGiaitich != -1) sv->diemGiaitich = diemGiaitich;
    if (diemVatly != -1) sv->diemVatly = diemVatly;
    if (diemLaptrinh != -1) sv->diemLaptrinh = diemLaptrinh;
    sv->diemTB = (diemGiaitich + diemVatly + diemLaptrinh) / 3;
    if (sv->diemTB >= 8) {
        strcpy(sv->hocluc, "Gioi");
    }
    else if (sv->diemTB >= 6.5) {
        strcpy(sv->hocluc, "Kha");
    }
    else if (sv->diemTB >= 5) {
        strcpy(sv->hocluc, "Trung binh");
    }
    else {
        strcpy(sv->hocluc, "Yeu");
    }
}
 
// ----------------------------------------------------------------
 
 
// Phu huynh --------------------------------
 
// Ham xem diem hoc phan cua sinh vien
void xemDiemHocPhan(struct SinhVien sv) {
    printf("Ðiem Giai Tich: %.2f\n", sv.diemGiaitich);
    printf("Ðiem Vat Li: %.2f\n", sv.diemVatly);
    printf("Ðiem Lap trinh: %.2f\n", sv.diemLaptrinh);
    printf("Ðiem trung binh: %.2f\n", sv.diemTB);
    printf("Hoc luc: %s\n\n", sv.hocluc);
}
 
// Hàm tìm kiem sinh viên theo mã sinh viên
struct SinhVien *timKiemSinhVien(struct SinhVien ds[], int soLuongSV, char masv[]) {
    for (int i = 0; i < soLuongSV; ++i) {
        if (strcmp(ds[i].masv, masv) == 0) {
            return &ds[i];
        }
    }
    return NULL;
}
// ----------------------------------------------------------------
 
 
// Sinh viên ----------------------------------------------------------------
 
// Hàm xem diem sinh vien
void xemDiem(struct SinhVien sv) {
    xemDiemHocPhan(sv);
}
 
// Hàm sua thông tin cá nhân
 
void suaThongTinCanhan(struct SinhVien *sv, char ten[], char gioiTinh[], int tuoi) {
    suaThongTinSinhVien(sv, ten, gioiTinh, tuoi, -1, -1, -1);
}
 
// Hàm xem thông tin cá nhân
 
void xemThongTinCanhan(struct SinhVien sv) {
    xemThongTinSinhVien(sv);
}
 
// Hàm ghi danh sách sinh viên
 
void ghiDanhSachSinhVien(char filename[], int size) {
    FILE *f = fopen(filename, "w");
    char t[15];
    sprintf(t, "%d", size);
    fputs(t, f);
    fputs("\n", f);
    for (int i = 0; i < size; ++i) {
        char temp[15];
        fputs(sinhVien[i].masv, f);
        fputs("\n", f);
        fputs(sinhVien[i].ten, f);
        fputs("\n", f);
        fputs(sinhVien[i].gioiTinh, f);
        fputs("\n", f);
        sprintf(temp, "%d", sinhVien[i].tuoi);
        fputs(temp, f);
        fputs("\n", f);
        sprintf(temp, "%.2f", sinhVien[i].diemGiaitich);
        fputs(temp, f);
        fputs("\n", f);
        sprintf(temp, "%.2f", sinhVien[i].diemVatly);
        fputs(temp, f);
        fputs("\n", f);
        sprintf(temp, "%.2f", sinhVien[i].diemLaptrinh);
        fputs(temp, f);
        fputs("\n", f);
    }
    fclose(f);
}
 
 
int main() {
    sinhVien = (struct SinhVien *) malloc(MAX * sizeof(struct SinhVien));
    int size = nhapDanhSachSinhVien("data.txt");
    int key, cmd, running = 1;
    int tuoi;
    char masv[15], ten[30], gioiTinh[5];
    float diemGiaiTich, diemVatLy, diemLapTrinh;
 
    while (running) {
        printf("Chuong trinh quan li sinh vien.\n\n");
        printf("Ban dang nhap voi tu cach: \n");
        printf("> 1. Phong dao tao.\n");
        printf("> 2. Giang vien.\n");
        printf("> 3. Phu huynh.\n");
        printf("> 4. Sinh vien.\n");
        printf("> 0. Thoat.\n");
        printf("Chon: ");
        scanf("%d", &key);
        switch (key) {
            // Phòng dào tao
            case 1:
                printf("Ban da dang nhap thao tac voi tu cach phong dao tao.\nCac thao tac ban co the thuc hien\n");
                printf("> 1. Tao tai khoan cua sinh vien.\n");
                printf("> 2. Xem thong tin cua sinh vien.\n");
                printf("> 0. Thoat.\n");
                printf("Ban chon thao tac: ");
                scanf("%d", &cmd);
                switch (cmd) {
                    case 1:
                        getchar();
                        printf("> Nhap ma sinh vien: ");
                        scanf("%s", masv);
                        printf("> Nhap ten sinh vien: ");
                        getchar();
                        scanf("%[^\n]s", ten);
                        printf("> Nhap tuoi sinh vien: ");
                        getchar();
                        scanf("%d", &tuoi);
                        printf("> Nhap gioi tính sinh vien: ");
                        getchar();
                        scanf("%s", gioiTinh);
                        printf("> Nhap diem Giai Tich: ");
                        getchar();
                        scanf("%f", &diemGiaiTich);
                        printf("> Nhap diem Vat Li: ");
                        getchar();
                        scanf("%f", &diemVatLy);
                        printf("> Nhap diem Lap Trinh: ");
                        getchar();
                        scanf("%f", &diemLapTrinh);
                        sinhVien[size] = taoSinhVien(masv, ten, gioiTinh, tuoi, diemGiaiTich, diemVatLy, diemLapTrinh);
                        size++;
                        printf("\nTao sinh vien moi thanh cong!!");
                        running = 0;
                        break;
                    case 2:
                        printf("> Nhap ma sinh vien can xem thong tin: ");
                        getchar();
                        scanf("%s", masv);
                        xemThongTinSinhVien(*timKiemSinhVien(sinhVien, size, masv));
                        running = 0;
                        break;
                    case 0:
                        printf("Ban da thoat chuong trinh!");
                        running = 0;
                        break;
                    default:
                        printf("\nÐau vao khong hop le");
                        running = 0;
                        break;
                }
                break;
                // Gi?ng viên
            case 2:
                printf("Ban da dang nhap thao tac voi tu cach giang viên.\nCac thao tac ban co the thuc hien:\n");
                printf("> 1. Nhap va sua thong tin sinh vien.\n");
                printf("> 2. Xem thong tin sinh vien.\n");
                printf("> 3. Nhap diem hoc phan cua sinh vien.\n");
                printf("> 0. Thoat.\n");
                printf("Ban chon thao tac: ");
                scanf(" %d", &cmd);
                switch (cmd) {
                    case 1:
                        printf("> Nhap ma sinh vien can chinh sua thong tin: ");
                        getchar();
                        scanf("%s", masv);
                        printf("> Nhap ten sinh vien (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%[^\n]s", ten);
                        printf("> Nhap tuoi sinh viên(nhap -1 neu khong can phai chinh sua phan nay)  : ");
                        getchar();
                        scanf("%d", &tuoi);
                        printf("> Nhap gioi tính sinh viên (nhap -1 neu khong can phai chinh sua phan nay) : ");
                        getchar();
                        scanf("%s", gioiTinh);
                        printf("> Nhap diem Giai Tích (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%f", &diemGiaiTich);
                        printf("> Nhap diem Vat Lý (nhap -1 neu khong can phai chinh sua phan nay) : ");
                        getchar();
                        scanf("%f", &diemVatLy);
                        printf("> Nhap diem Lap Trình (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%f", &diemLapTrinh);
                        suaThongTinSinhVien(timKiemSinhVien(sinhVien, size, masv), ten, gioiTinh, tuoi, diemGiaiTich, diemVatLy, diemLapTrinh);
                        printf("Sua thong tin thanh cong!!\n");
                        running = 0;
                        break;
                    case 2:
                        printf("> Nhap ma. sinh vien can xem thong tin: ");
                        getchar();
                        scanf("%s", masv);
                        xemThongTinSinhVien(*timKiemSinhVien(sinhVien, size, masv));
                        running = 0;
                        break;
                    case 3:
                        printf("> Nhap diem Giai Tích (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%f", &diemGiaiTich);
                        printf("> Nhap diem Vat Lý (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%f", &diemVatLy);
                        printf("> Nhap diem Lap Trình (nhap -1 neu khong can phai chinh sua phan nay): ");
                        getchar();
                        scanf("%f", &diemLapTrinh);
                        nhapDiemHocPhan(timKiemSinhVien(sinhVien, size, masv), diemGiaiTich, diemVatLy, diemLapTrinh);
                        running = 0;
                        break;
                    case 0:
                        printf("Ban da thoat chuong trinh!");
                        running = 0;
                        break;
                    default:
                        printf("\nÐau vao khong hop le");
                        running = 0;
                        break;
                }
                break;
                // Phu huynh
            case 3:
                printf("Ban da dang nhap thao tac voi tu cach phu huynh.\nCac thao tac ban co the thuc hien\n");
                printf("> 1. Xem diem hoc phan cua sinh vien.\n");
                printf("> 2. Tim kiem thong tin theo MSSV.\n");
                printf("> 0. Thoat.\n");
                printf("Ban chon thao tac: ");
                scanf(" %d", &cmd);
                switch (cmd) {
                    case 1:
                        printf("> Nhap ma sinh vien can xem diem hoc phan: ");
                        getchar();
                        scanf("%s", masv);
                        xemDiemHocPhan(*timKiemSinhVien(sinhVien, size, masv));
                        running = 0;
                        break;
                    case 2:
                        printf("> Nhap ma sinh vien can thong tin : ");
                        getchar();
                        scanf("%s", masv);
                        struct SinhVien *sv = timKiemSinhVien(sinhVien, size, masv);
                        xemThongTinSinhVien(*sv);
                        printf("Sua thong tin thanh cong!!\n");
                        running = 0;
                        break;
                    case 0:
                        printf("Ban da thoat chuong trinh!");
                        running = 0;
                        break;
                    default:
                        printf("\nÐau vao khong hop li");
                        running = 0;
                        break;
                }
                break;
                // Sinh viên
            case 4:
                printf("Ban da dang nhap thao tac voi tu cach sinh vien.\nCac thao tac ban co the thuc hien\n");
                printf("> 1. Xem diem hoc phan cua ban.\n");
                printf("> 2.Sua thong tin cua ban.\n");
                printf("> 3.Xem thong tin cua ban.\n");
                printf("> 0. Thoat.\n");
                printf("Ban chon thao tac: ");
                scanf(" %d", &cmd);
                printf("Nhap ma sinh vien cua ban: ");
                scanf("%s", masv);
                struct SinhVien *current = timKiemSinhVien(sinhVien, size, masv);
                switch (cmd) {
                    case 1:
                        xemDiem(*current);
                        break;
                    case 2:
                        printf("> Nhap tên sinh viên moi (nhap -1 neu không con phai chinh sua phan này): ");
                        getchar();
                        scanf("%[^\n]s", ten);
                        printf("> Nhap tuoi sinh viên moi (nhap -1 neu không con phai chinh sua phan này): ");
                        getchar();
                        scanf("%d", &tuoi);
                        printf("> Nhap gioi tính sinh viên moi (nhap -1 neu không con phai chinh sua phan này): ");
                        getchar();
                        scanf("%s", gioiTinh);
                        suaThongTinCanhan(current, ten, gioiTinh, tuoi);
                        printf("Sua thong tin thanh cong!!\n");
                        running = 0;
                        break;
                    case 3:
                        xemThongTinCanhan(*current);
                        running = 0;
                        break;
                    default:
                        printf("\nÐau vao khong hop le");
                        running = 0;
                        break;
                }
                break;
            case 0:
                printf("Ban da thoat chuong trinh!");
                running = 0;
                break;
            default:
                printf("Ðau vao khong hop le\n");
                running = 0;
                break;
        }
    }
    ghiDanhSachSinhVien("output.txt", size);
    ghiDanhSachSinhVien("data.txt", size);
    free(sinhVien);
    return 0;
}
 
