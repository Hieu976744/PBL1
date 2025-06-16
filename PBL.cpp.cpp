#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

// Lớp Dịch vụ chăm sóc cây cảnh
class DichVuChamSocCayCanh {
private:
    string Vi_tri;
    string Loai_cay_canh = "Khong co";
    int Ma_dich_vu;
    string Yeu_cau_dich_vu;
    string Tinh_trang;
    int Gia_dich_vu;
    string Yeu_cau_dac_biet;
    float Dien_tich_vuon;
    float Gio_dich_vu;
    int Thoi_luong;
    float Khoang_cach;
    float Muc_phu_thu_theo_thoi_diem = 0;
    float Muc_phu_thu_theo_thoi_luong = 0;
    float Muc_phu_thu_theo_khoang_cach = 0;
    float Muc_phu_thu_theo_ngay_trong_tuan = 0;
    float Muc_phu_thu;
    int Gia_phu_thu;
    int Ngay_trong_tuan;
    int gia_cham_soc_cay_don_le = 170000;
    int gia_tu_van_cay = 110000;
    int gia_cham_soc_vuon_base = 300000;
    int gia_cham_soc_vuon_25_80 = 10000;
    int gia_cham_soc_vuon_tren_80 = 8000;
    int gia_tu_van_vuon_base = 200000;
    int gia_tu_van_vuon_25_80 = 7000;
    int gia_tu_van_vuon_tren_80 = 6000;
    float phu_thu_thoi_diem = 0.05;
    float phu_thu_thoi_luong = 0.05;
    float phu_thu_khoang_cach = 0.01;
    float phu_thu_chu_nhat = 0.05;

public:
    DichVuChamSocCayCanh(){
    docGiaDichVuTuFile();
    docGiaPhuThuTuFile();
    }
    void menuDichVu() {
        int choice;
        do {
            cout << "\n===== QUAN LY DICH VU =====\n";
            cout << "1. Hien thi muc gia tung loai dich vu\n";
            cout << "2. Sua gia tung loai dich vu\n";
            cout << "3. Hien thi muc gia tung loai phu thu\n";
            cout << "4. Sua muc gia tung loai phu thu\n";
            cout << "0. Thoat\n";
            cout << "Lua chon cua ban: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1: Hien_thi_gia_dich_vu(); break;
            case 2: Sua_gia_dich_vu(); break;
            case 3: Hien_thi_phu_thu(); break;
            case 4: Sua_gia_phu_thu(); break;
            case 0: cout << "Thoat chuong trinh.\n"; break;
            default: cout << "Lua chon khong hop le.\n";
            }
        } while (choice != 0);
    }
    void luuGiaDichVuVaoFile() {
        ofstream fout("giadichvu.txt");
        if (!fout) {
            cout << "LOI KHONG THE MO FILE!\n";
            return;
        }
        fout << gia_cham_soc_cay_don_le << "|" << gia_tu_van_cay << "|"
            << gia_cham_soc_vuon_base << "|" << gia_cham_soc_vuon_25_80 << "|"
            << gia_cham_soc_vuon_tren_80 << "|" << gia_tu_van_vuon_base << "|"
            << gia_tu_van_vuon_25_80 << "|" << gia_tu_van_vuon_tren_80 << "|";
        fout.close();
    }

    void docGiaDichVuTuFile() {
        ifstream fin("giadichvu.txt");
        if (!fin) {
            cout << "LOI KHONG THE MO FILE! \n";
            return;
        }
            string dulieufile;
            int gia[8];
            for(int i=0; i<=7; i++) {
                getline(fin, dulieufile,'|'); //đọc giá trị cho đến khi gặp dấu '|' thì dừng
                gia[i]=stoi(dulieufile);// stoi chuyển từ kiểu chuỗi sang kiểu số nguyên int
            }
            gia_cham_soc_cay_don_le = gia[0];
            gia_tu_van_cay = gia[1];
            gia_cham_soc_vuon_base = gia[2];
            gia_cham_soc_vuon_25_80 = gia[3];
            gia_cham_soc_vuon_tren_80 = gia[4];
            gia_tu_van_vuon_base = gia[5];
            gia_tu_van_vuon_25_80 = gia[6];
            gia_tu_van_vuon_tren_80 = gia[7];
        fin.close();
    }
   void Hien_thi_gia_dich_vu() const {
        cout << "\n===== GIA CAC LOAI DICH VU =====\n";
        cout << "1. Cham soc cay canh don le: " << gia_cham_soc_cay_don_le << " dong\n";
        cout << "2. Tu van cham soc cay: " << gia_tu_van_cay << " dong\n";
        cout << "3. Cham soc khu vuon:\n"
            << "   - Co ban (duoi 25m2): " << gia_cham_soc_vuon_base << " dong\n"
            << "   - 25-80m2: +" << gia_cham_soc_vuon_25_80 << " dong/m2 (tu m2 thu 26)\n"
            << "   - Tren 80m2: +" << gia_cham_soc_vuon_tren_80 << " dong/m2 (tu m2 thu 26)\n";
        cout << "4. Tu van cham soc vuon:\n"
            << "   - Co ban (duoi 25m2): " << gia_tu_van_vuon_base << " dong\n"
            << "   - 25-80m2: +" << gia_tu_van_vuon_25_80 << " dong/m2 (tu m2 thu 26)\n"
            << "   - Tren 80m2: +" << gia_tu_van_vuon_tren_80 << " dong/m2 (tu m2 thu 26)\n";
        cout << "=============================\n";
    }
  void Sua_gia_dich_vu() {
        int choice;
        do{
            cout << "\n===== SUA GIA DICH VU =====\n";
            cout << "1. Cham soc cay canh don le: " << gia_cham_soc_cay_don_le << " dong\n";
            cout << "2. Tu van cham soc cay: " << gia_tu_van_cay << " dong\n";
            cout << "3. Cham soc khu vuon (Base: " << gia_cham_soc_vuon_base
                << ", 25-80m2: " << gia_cham_soc_vuon_25_80 << "/m2, >80m2: "
                << gia_cham_soc_vuon_tren_80 << "/m2)\n";
            cout << "4. Tu van cham soc vuon (Base: " << gia_tu_van_vuon_base
                << ", 25-80m2: " << gia_tu_van_vuon_25_80 << "/m2, >80m2: "
                << gia_tu_van_vuon_tren_80 << "/m2)\n";
            cout << "0. Hoan tat\n";
            cout << "Chon dich vu de sua gia: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                cout << "Nhap gia moi cho cham soc cay canh don le: ";
                cin >> gia_cham_soc_cay_don_le;
                while (gia_cham_soc_cay_don_le <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_cham_soc_cay_don_le;
                }
                cin.ignore();
                break;
            case 2:
                cout << "Nhap gia moi cho tu van cham soc cay: ";
                cin >> gia_tu_van_cay;
                while (gia_tu_van_cay <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_tu_van_cay;
                }
                cin.ignore();
                break;
            case 3:
                cout << "Nhap gia co ban moi cho cham soc khu vuon: ";
                cin >> gia_cham_soc_vuon_base;
                while (gia_cham_soc_vuon_base <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_cham_soc_vuon_base;
                }
                cout << "Nhap gia moi cho moi m2 (25-80m2): ";
                cin >> gia_cham_soc_vuon_25_80;
                while (gia_cham_soc_vuon_25_80 <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_cham_soc_vuon_25_80;
                }
                cout << "Nhap gia moi cho moi m2 (>80m2): ";
                cin >> gia_cham_soc_vuon_tren_80;
                while (gia_cham_soc_vuon_tren_80 <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_cham_soc_vuon_tren_80;
                }
                cin.ignore();
                break;
            case 4:
                cout << "Nhap gia co ban moi cho tu van cham soc vuon: ";
                cin >> gia_tu_van_vuon_base;
                while (gia_tu_van_vuon_base <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_tu_van_vuon_base;
                }
                cout << "Nhap gia moi cho moi m2 (25-80m2): ";
                cin >> gia_tu_van_vuon_25_80;
                while (gia_tu_van_vuon_25_80 <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_tu_van_vuon_25_80;
                }
                cout << "Nhap gia moi cho moi m2 (>80m2): ";
                cin >> gia_tu_van_vuon_tren_80;
                while (gia_tu_van_vuon_tren_80 <= 0) {
                    cout << "Gia phai lon hon 0, nhap lai: ";
                    cin >> gia_tu_van_vuon_tren_80;
                }
                cin.ignore();
                break;
            case 0:
                luuGiaDichVuVaoFile();
                cout << "Da luu gia dich vu.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
            }
        } while (choice != 0);
    }

    void luuGiaPhuThuVaoFile() {
        ofstream fout("phuthu.txt");
        if (!fout) {
            cout << "LOI KHONG THE MO FILE!\n";
            return;
        }
        fout << phu_thu_thoi_diem << "|" << phu_thu_thoi_luong << "|"
            << phu_thu_khoang_cach << "|" << phu_thu_chu_nhat << "|";
        fout.close();
    }

    void docGiaPhuThuTuFile() {
        ifstream fin("phuthu.txt");
        if (!fin) {
            cout << "LOI KHONG THE MO FILE! \n";
            return;
        }
            string dulieufile;
            float phuThu[4];
            for(int i=0;i<=3;i++){
                getline(fin, dulieufile, '|'); //đọc dữ liệu trong file cho đến khi gặp kí tự '|' thì dừng
                phuThu[i]=stof(dulieufile); //stof chuyển từ kiểu chuỗi sang kiểu số thực float
            }
            phu_thu_thoi_diem = phuThu[0];
            phu_thu_thoi_luong = phuThu[1];
            phu_thu_khoang_cach = phuThu[2];
            phu_thu_chu_nhat = phuThu[3];
        fin.close();
    }


    void Hien_thi_phu_thu() const {
        cout << "\n===== MUC PHU THU =====\n";
        cout << "1. Phu thu gio cao diem (6-8h, 15-17h): " << phu_thu_thoi_diem * 100 << "%\n";
        cout << "2. Phu thu thoi luong (moi 30p qua 90p): " << phu_thu_thoi_luong * 100 << "%\n";
        cout << "3. Phu thu khoang cach (moi km qua 10km): " << phu_thu_khoang_cach * 100 << "%\n";
        cout << "4. Phu thu ngay Chu Nhat: " << phu_thu_chu_nhat * 100 << "%\n";
        cout << "======================\n";
    }


    void Sua_gia_phu_thu() {
        int choice;
        do {
            cout << "\n===== SUA GIA PHU THU =====\n";
            cout << "1. Phu thu gio cao diem (6-8h, 15-17h): " << phu_thu_thoi_diem * 100 << "%\n";
            cout << "2. Phu thu thoi luong (moi 30p qua 90p): " << phu_thu_thoi_luong * 100 << "%\n";
            cout << "3. Phu thu khoang cach (moi km qua 10km): " << phu_thu_khoang_cach * 100 << "%\n";
            cout << "4. Phu thu ngay Chu Nhat: " << phu_thu_chu_nhat * 100 << "%\n";
            cout << "0. Hoan tat\n";
            cout << "Chon muc phu thu de sua: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                cout << "Nhap phu thu gio cao diem moi (vi du: 0.05 = 5%): ";
                cin >> phu_thu_thoi_diem;
                while (phu_thu_thoi_diem < 0) {
                    cout << "Phu thu phai >= 0, nhap lai: ";
                    cin >> phu_thu_thoi_diem;
                }
                cin.ignore();
                break;
            case 2:
                cout << "Nhap phu thu thoi luong moi (vi du: 0.05 = 5%): ";
                cin >> phu_thu_thoi_luong;
                while (phu_thu_thoi_luong < 0) {
                    cout << "Phu thu phai >= 0, nhap lai: ";
                    cin >> phu_thu_thoi_luong;
                }
                cin.ignore();
                break;
            case 3:
                cout << "Nhap phu thu khoang cach moi (vi du: 0.01 = 1%): ";
                cin >> phu_thu_khoang_cach;
                while (phu_thu_khoang_cach < 0) {
                    cout << "Phu thu phai >= 0, nhap lai: ";
                    cin >> phu_thu_khoang_cach;
                }
                cin.ignore();
                break;
            case 4:
                cout << "Nhap phu thu ngay Chu Nhat moi (vi du: 0.05 = 5%): ";
                cin >> phu_thu_chu_nhat;
                while (phu_thu_chu_nhat < 0) {
                    cout << "Phu thu phai >= 0, nhap lai: ";
                    cin >> phu_thu_chu_nhat;
                }
                cin.ignore();
                break;
            case 0:
                luuGiaPhuThuVaoFile();
                cout << "Da luu gia phu thu.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
            }
        } while (choice != 0);
    }

    void Chon_loai_dich_vu() {
        int xacnhan = 0;
        while (xacnhan != 1) {
            cout << "1. Dich vu cham soc cay canh don le\n"
                << "2. Dich vu cham soc khu vuon\n"
                << "3. Dich vu tu van cham soc cay canh\n"
                << "4. Dich vu tu van cham soc vuon cay\n"
                << "Vui long chon loai dich vu: ";
            cin >> Ma_dich_vu;
            cin.ignore();
            while (Ma_dich_vu < 1 || Ma_dich_vu > 4) {
                cout << "Ma dich vu khong hop le, vui long nhap lai: ";
                cin >> Ma_dich_vu;
                cin.ignore();
            }
             switch (Ma_dich_vu) {
        case 1: Cham_soc_cay_canh_don_le(); break;
        case 2: Cham_soc_vuon_cay(); break;
        case 3: Tu_van_cham_soc_cay(); break;
        case 4: Tu_van_cham_soc_vuon_cay(); break;
        }
            cout << "Xac nhan dich vu? Chon 1 de xac nhan, chon so bat ki de chon lai dich vu\n";
            cin >> xacnhan;
            cin.ignore();
        }
    }
    void Cham_soc_cay_canh_don_le() {
        Gia_dich_vu = gia_cham_soc_cay_don_le;
        Yeu_cau_dich_vu = "Dich vu cham soc cay canh don le";
        cout << "Dich vu se bao gom cac cong viec cham soc tren:\n"
            << "1. Tuoi nuoc cho cay\n"
            << "2. Nho co dai\n"
            << "3. Bon phan cho cay\n"
            << "4. Cat tia canh la\n"
            << "5. Kiem tra suc khoe cua cay va phong ngua sau benh\n"
            << "6. Nho co dai xung quanh cay canh\n"
            << "7. Thay dat cho cay canh\n"
            << "Phi co ban cua dich vu: " << Gia_dich_vu << " dong\n";
        cout << "Nhap loai cay canh: ";
        getline(cin, Loai_cay_canh);
        cout << "Nhap dia chi cua vuon cay hoac dia chi cua nha noi chua cay: ";
        getline(cin, Vi_tri);
        cout << "Tinh trang hien tai cua cay: ";
        getline(cin, Tinh_trang);
        cout << "Yeu cau dac biet: ";
        getline(cin, Yeu_cau_dac_biet);
    }

    void Cham_soc_vuon_cay() {
        Yeu_cau_dich_vu = "Dich vu cham soc khu vuon";
        cout << "Dich vu se bao gom cac cong viec cham soc tren:\n"
            << "1. Tuoi nuoc cho vuon cay\n"
            << "2. Nho co dai trong vuon cay\n"
            << "3. Bon phan cho vuon cay\n"
            << "4. Cat tia canh la\n"
            << "5. Thay dat cho vuon\n"
            << "6. Don dep vuon cay\n"
            << "7. Kiem tra suc khoe cua toan bo cay trong vuon va phong ngua sau benh\n"
            << "Phi co ban doi voi vuon co dien tich duoi 25m2: " << gia_cham_soc_vuon_base << "\n"
            << "Neu vuon co dien tich nam trong khoang tu 25-80m2: tinh them " << gia_cham_soc_vuon_25_80 << " moi m2 tinh tu m2 thu 26\n"
            << "Neu vuon co dien tich tren 80m2: tinh them " << gia_cham_soc_vuon_tren_80 << " moi m2 tinh tu m2 thu 26\n";
        cout << "Nhap dia chi vuon cay: ";
        getline(cin, Vi_tri);
        cout << "Nhap tinh trang vuon cay: ";
        getline(cin, Tinh_trang);
        cout << "Nhap yeu cau dac biet: ";
        getline(cin, Yeu_cau_dac_biet);
        cout << "Nhap dien tich vuon cay (m2): ";
        cin >> Dien_tich_vuon;
        cin.ignore();
        while (Dien_tich_vuon < 0) {
            cout << "Dien tich vuon khong hop le, vui long nhap lai: ";
            cin >> Dien_tich_vuon;
            cin.ignore();
        }
        if (Dien_tich_vuon <= 25) {
            Gia_dich_vu = gia_cham_soc_vuon_base;
        }
        else if (Dien_tich_vuon > 25 && Dien_tich_vuon <= 80) {
            Gia_dich_vu = gia_cham_soc_vuon_base + (Dien_tich_vuon - 25) * gia_cham_soc_vuon_25_80;
        }
        else {
            Gia_dich_vu = gia_cham_soc_vuon_base + (Dien_tich_vuon - 25) * gia_cham_soc_vuon_tren_80;
        }
        cout << "Phi co ban cua dich vu: " << Gia_dich_vu << " dong\n";
    }

    void Tu_van_cham_soc_cay() {
        Yeu_cau_dich_vu="Dich vu tu van cham soc cay";
        cout << "Dich vu se bao gom nhung cong viec sau:\n"
            << "1. Xac dinh tinh trang cua cay\n"
            << "2. Kiem tra moi truong song\n"
            << "3. Tu van cach tuoi nuoc, luong nuoc phu hop\n"
            << "4. Tu van loai phan can bon cho cay\n"
            << "5. Tu van cach phong benh, ngan ngua sau benh cho cay\n"
            << "6. Tu van cach cat tia, tao dang cho cay canh\n";
        Gia_dich_vu = gia_tu_van_cay;
        cout << "Phi co ban cua dich vu: " << Gia_dich_vu << " dong\n";
        cout << "Nhap loai cay: ";
        getline(cin, Loai_cay_canh);
        cout << "Nhap dia chi hoac vi tri cua khu vuon noi chua cay: ";
        getline(cin, Vi_tri);
    }

    void Tu_van_cham_soc_vuon_cay() {
        Yeu_cau_dich_vu="Dich vu tu van cham soc vuon cay";
        cout << "Dich vu se bao gom nhung cong viec sau:\n"
            << "1. Xac dinh tinh trang vuon cay\n"
            << "2. Kiem tra moi truong song trong vuon\n"
            << "3. Tu van cach tuoi nuoc, luong nuoc phu hop cho tung loai cay\n"
            << "4. Tu van loai phan bon cho vuon cay\n"
            << "5. Tu van cach phong benh, ngan ngua sau benh cho vuon\n"
            << "6. Tu van cach cat tia, tao dang cho vuon cay\n"
            << "Phi co ban doi voi dien tich vuon duoi 25m2: " << gia_tu_van_vuon_base << "\n"
            << "Neu vuon co dien tich nam trong khoang tu 25-80m2: tinh them " << gia_tu_van_vuon_25_80 << " moi m2 tinh tu m2 thu 26\n"
            << "Neu vuon co dien tich tren 80m2: tinh them " << gia_tu_van_vuon_tren_80 << " moi m2 tinh tu m2 thu 26\n";
        cout << "Nhap vi tri vuon cay: ";
        getline(cin, Vi_tri);
        cout << "Nhap dien tich vuon cay (m2): ";
        cin >> Dien_tich_vuon;
        cin.ignore();
        while (Dien_tich_vuon < 0) {
            cout << "Dien tich vuon khong hop le, vui long nhap lai: ";
            cin >> Dien_tich_vuon;
            cin.ignore();
        }
        if (Dien_tich_vuon <= 25) {
            Gia_dich_vu = gia_tu_van_vuon_base;
        }
        else if (Dien_tich_vuon > 25 && Dien_tich_vuon <= 80) {
            Gia_dich_vu = gia_tu_van_vuon_base + (Dien_tich_vuon - 25) * gia_tu_van_vuon_25_80;
        }
        else {
            Gia_dich_vu = gia_tu_van_vuon_base + (Dien_tich_vuon - 25) * gia_tu_van_vuon_tren_80;
        }
        cout << "Phi co ban cua dich vu: " << Gia_dich_vu << " dong\n";
    }

    void Tinh_phu_thu() {
        int xac_nhan = 0;
        while (xac_nhan != 1) {
            Muc_phu_thu = 0;
            cout << "Gio lam viec cua dich vu: 6-17h vao tat ca cac ngay, tru cac ngay le\n";
            cout << "Phu thu se bao gom:\n"
                << "1. Phu thu " << phu_thu_thoi_diem * 100 << "% so voi muc phi co ban vao gio cao diem (6h-8h hoac 15h-17h)\n"
                << "2. Thoi luong thuc hien dich vu keo dai 90p, moi 30p thuc hien dich vu se tinh phi them "
                << phu_thu_thoi_luong * 100
                << "% so voi muc gia co ban, thoi luong phai la boi so cua 30 phut va khong duoc it hon 90 phut. Thoi luong toi da la 3 tieng\n"
                << "3. Neu khoang cach tu trung tam dich vu den noi thuc hien dich vu it hon 10km thi phu thu 0%, phu thu "
                << phu_thu_khoang_cach * 100 << "% moi 1km, toi da la 30km\n"
                << "4. Phu thu them " << phu_thu_chu_nhat * 100 << "% vao ngay chu nhat\n";
            cout << "Nhap thoi diem thuc hien dich vu: ";
            cin >> Gio_dich_vu;
            while (Gio_dich_vu < 6 || Gio_dich_vu > 17) {
                cout << "Thoi diem thuc hien dich vu ngoai thoi gian lam viec, vui long nhap lai: ";
                cin >> Gio_dich_vu;
            }
            if ((Gio_dich_vu >= 6 && Gio_dich_vu <= 8) || (Gio_dich_vu >= 15 && Gio_dich_vu <= 17)) {
                Muc_phu_thu_theo_thoi_diem = phu_thu_thoi_diem;
            }
            else {
                Muc_phu_thu_theo_thoi_diem = 0;
            }
            cout << "Nhap thoi luong thuc hien dich vu (phut): ";
            cin >> Thoi_luong;
            while (Thoi_luong % 30 != 0 || Thoi_luong < 90 || Thoi_luong > 180) {
                cout << "Thoi luong thuc hien dich vu khong hop le, vui long nhap lai: ";
                cin >> Thoi_luong;
            }
            if (Thoi_luong > 90) {
                Muc_phu_thu_theo_thoi_luong = (Thoi_luong - 90) / 30 * phu_thu_thoi_luong;
            }
            else {
                Muc_phu_thu_theo_thoi_luong = 0;
            }
            int Khoang_cach_lam_tron;
            cout << "Nhap khoang cach tu trung tam dich vu den noi thuc hien dich vu: ";
            cin >> Khoang_cach;
            while (Khoang_cach < 1 || Khoang_cach > 30) {
                cout << "Khoang cach khong hop le, vui long nhap lai: ";
                cin >> Khoang_cach;
            }
            if (Khoang_cach > 10) {
                Khoang_cach_lam_tron = round(Khoang_cach);
                Muc_phu_thu_theo_khoang_cach = (Khoang_cach_lam_tron - 10) * phu_thu_khoang_cach;
            }
            else {
                Muc_phu_thu_theo_khoang_cach = 0;
            }
            cout << "Nhap ngay thuc hien dich vu trong tuan (vi du: thu hai thi nhap 1): ";
            cin >> Ngay_trong_tuan;
            while (Ngay_trong_tuan < 1 || Ngay_trong_tuan > 7) {
                cout << "Ngay thuc hien dich vu khong hop le, vui long nhap lai: ";
                cin >> Ngay_trong_tuan;
            }
            if (Ngay_trong_tuan == 7) {
                Muc_phu_thu_theo_ngay_trong_tuan = phu_thu_chu_nhat;
            }
            else {
                Muc_phu_thu_theo_ngay_trong_tuan = 0;
            }
            Muc_phu_thu = Muc_phu_thu_theo_khoang_cach + Muc_phu_thu_theo_ngay_trong_tuan + Muc_phu_thu_theo_thoi_diem
                          + Muc_phu_thu_theo_thoi_luong;
            Gia_phu_thu = Muc_phu_thu * Gia_dich_vu;
            cout << "Muc phu thu theo thoi diem thuc hien dich vu: " << Muc_phu_thu_theo_thoi_diem * 100 << "%\n"
                << "Muc phu thu theo thoi luong thuc hien dich vu: " << Muc_phu_thu_theo_thoi_luong * 100 << "%\n"
                << "Muc phu thu theo khoang cach: " << Muc_phu_thu_theo_khoang_cach * 100 << "%\n"
                << "Muc phu thu theo ngay thuc hien dich vu trong tuan: " << Muc_phu_thu_theo_ngay_trong_tuan * 100 << "%\n"
                << "Tong muc phu thu: " << Muc_phu_thu * 100 << "%\n"
                << "Tong tien phu thu: " << Gia_phu_thu << " dong\n";
            cout << "Xac nhan? Chon 1 de xac nhan, chon so bat ki de thuc hien lai\n";
            cin >> xac_nhan;
            cin.ignore();
        }
    }

    string getthongtindichvu() const {
        return Yeu_cau_dich_vu;
    }

    int getgiadichvu() const {
        return Gia_dich_vu;
    }

    int getgiaphuthu() const {
        return Gia_phu_thu;
    }

    void setthongtintichvu(const string& yeuCau, int giaDV, int giaPT) {
        Yeu_cau_dich_vu = yeuCau;
        Gia_dich_vu = giaDV;
        Gia_phu_thu = giaPT;
    }
};

// Lớp Quản lý khách hàng
class Quanlykhachhang {
private:
    string CCCD[100];
    string ten[100];
    string sdt[100];
    string diachi[100];
    string yeucaudichvu[100];
    int giadichvu[100];
    int giaphuthu[100];
    int SLkhachhang;
    DichVuChamSocCayCanh dichvu;

public:
    Quanlykhachhang() {
        SLkhachhang = 0;
        docTuFile();
    }

    void themKhachHang() {
        if (SLkhachhang >= 10000) {
            cout << "Danh sach khach hang da day!\n";
            return;
        }

        string cccd, tenKH, sdtKH, diachiKH;
        cout << "\nNhap thong tin khach hang moi:\n";

        // Nhập CCCD với kiểm tra độ dài
        while (true) {
            cout << "Nhap CCCD (12 so): ";
            getline(cin, cccd);
            if (cccd.length() == 12) {
                break;
            }
            cout << "CCCD phai co dung 12 so, vui long nhap lai.\n";
        }

        cout << "Nhap ho ten: ";
        getline(cin, tenKH);

        // Nhập số điện thoại với kiểm tra độ dài
        while (true) {
            cout << "Nhap so dien thoai (10 so): ";
            getline(cin, sdtKH);
            if (sdtKH.length() == 10) {
                break;
            }
            cout << "So dien thoai phai co dung 10 so! Vui long nhap lai.\n";
        }

        cout << "Nhap dia chi: ";
        getline(cin, diachiKH);

        for (int i = 0; i < SLkhachhang; i++) {
            if (CCCD[i] == cccd) {
                cout << "CCCD da ton tai! Vui long nhap lai.\n";
                return;
            }
        }

        CCCD[SLkhachhang] = cccd;
        ten[SLkhachhang] = tenKH;
        sdt[SLkhachhang] = sdtKH;
        diachi[SLkhachhang] = diachiKH;
        yeucaudichvu[SLkhachhang] = "Chua dang ky dich vu";
        giadichvu[SLkhachhang] = 0;
        giaphuthu[SLkhachhang] = 0;

        cout << "Ban co muon dang ky dich vu? (1: Co, 0: Khong): ";
        int chon;
        cin >> chon;
        cin.ignore();
        if (chon == 1) {
            dichvu.Chon_loai_dich_vu();
            dichvu.Tinh_phu_thu();
            yeucaudichvu[SLkhachhang] = dichvu.getthongtindichvu();
            giadichvu[SLkhachhang] = dichvu.getgiadichvu();
            giaphuthu[SLkhachhang] = dichvu.getgiaphuthu();
        }

        SLkhachhang++;
        luuVaoFile();
        cout << "Them khach hang thanh cong!\n";
    }

    void suaKhachHang() {
        string cccd;
        cout << "\nNhap CCCD cua khach hang can sua: ";
        getline(cin, cccd);

        for (int i = 0; i < SLkhachhang; i++) {
            if (CCCD[i] == cccd) {
                cout << "Nhap thong tin moi:\n";
                cout << "Ho ten: ";
                getline(cin, ten[i]);
                // Nhập số điện thoại mới với kiểm tra độ dài
                while (true) {
                    cout << "So dien thoai (10 so): ";
                    getline(cin, sdt[i]);
                    if (sdt[i].length() == 10) {
                        break;
                    }
                    cout << "So dien thoai phai co dung 10 so, vui long nhap lai.\n";
                }

                cout << "Dia chi: ";
                getline(cin, diachi[i]);
                luuVaoFile();
                cout << "Sua thong tin khach hang thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay khach hang voi CCCD: " << cccd << endl;
    }
    void xoaKhachHang() {
        string cccd;
        cout << "\nNhap CCCD cua khach hang can xoa: ";
        getline(cin, cccd);

        for (int i = 0; i < SLkhachhang; i++) {
            if (CCCD[i] == cccd) {
                for (int j = i; j < SLkhachhang - 1; j++) {
                    CCCD[j] = CCCD[j + 1];
                    ten[j] = ten[j + 1];
                    sdt[j] = sdt[j + 1];
                    diachi[j] = diachi[j + 1];
                    yeucaudichvu[j] = yeucaudichvu[j + 1];
                    giadichvu[j] = giadichvu[j + 1];
                    giaphuthu[j] = giaphuthu[j + 1];
                }
                SLkhachhang--;
                luuVaoFile();
                cout << "Xoa khach hang thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay khach hang voi CCCD: " << cccd << endl;
    }

    void hienThiDanhSachKhachHang() {
        if (SLkhachhang == 0) {
            cout << "\n=======================\n";
            cout << "| Danh sach khach hang trong! |\n";
            cout << "=======================\n";
            return;
        }

        cout << "\n=====================================\n";
        cout << "|       DANH SACH KHACH HANG        |\n";
        cout << "=====================================\n";
        cout << "| Tong so khach hang: " << SLkhachhang << " |\n";
        cout << "=====================================\n";

        for (int i = 0; i < SLkhachhang; i++) {
            int stt = i + 1;
            cout << "| KHACH HANG THU " << stt << ":\n";
            cout << "|-------------------------------\n";
            cout << "| CCCD          " << CCCD[i] << "\n";
            cout << "| Ho ten        " << ten[i] << "\n";
            cout << "| So dien thoai " << sdt[i] << "\n";
            cout << "| Dia chi       " << diachi[i] << "\n";
            cout << "| Dich vu       " << yeucaudichvu[i] << "\n";
            cout << "| Gia dich vu   " << giadichvu[i] << " dong\n";
            cout << "| Gia phu thu   " << giaphuthu[i] << " dong\n";
            cout << "| Tong so tien  " << (giadichvu[i] + giaphuthu[i]) << " dong\n";
            cout << "=====================================\n";
        }
    }

    void dangKyDichVu() {
        string cccd;
        cout << "\nNhap CCCD cua khach hang can dang ky dich vu: ";
        getline(cin, cccd);

        for (int i = 0; i < SLkhachhang; i++) {
            if (CCCD[i] == cccd) {
                dichvu.Chon_loai_dich_vu();
                dichvu.Tinh_phu_thu();
                yeucaudichvu[i] = dichvu.getthongtindichvu();
                giadichvu[i] = dichvu.getgiadichvu();
                giaphuthu[i] = dichvu.getgiaphuthu();
                luuVaoFile();
                cout << "Dang ky dich vu thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay khach hang voi CCCD: " << cccd << endl;
    }

    void luuVaoFile() {
        ofstream fout("khachhang.txt");
        if (!fout) {
            cout << "LOI KHONG THE MO FILE\n";
            return;
        }
        for (int i = 0; i < SLkhachhang; i++) {
            fout << CCCD[i] << "|" << ten[i] << "|" << sdt[i] << "|" << diachi[i] << "|"
                << yeucaudichvu[i] << "|" << giadichvu[i] << "|" << giaphuthu[i] << endl;
        }
        fout.close();
    }

    void docTuFile() {
        ifstream fin("khachhang.txt");
        if (!fin) {
            cout << "LOI KHONG THE MO FILE\n";
            return;
        }
        SLkhachhang = 0;
        string cccd, tenKH, sdtKH, diaChiKH, yeuCauDV;
        int giaDV, giaPT;
        while (SLkhachhang < 100) {
            if (!getline(fin, cccd, '|')) break;
            if (!getline(fin, tenKH, '|')) break;
            if (!getline(fin, sdtKH, '|')) break;
            if (!getline(fin, diaChiKH, '|')) break;
            if (!getline(fin, yeuCauDV, '|')) break;
            fin >> giaDV;
            fin.ignore(1); // Bỏ dấu |
            fin >> giaPT;
            fin.ignore(); // Bỏ ký tự xuống dòng

            CCCD[SLkhachhang] = cccd;
            ten[SLkhachhang] = tenKH;
            sdt[SLkhachhang] = sdtKH;
            diachi[SLkhachhang] = diaChiKH;
            yeucaudichvu[SLkhachhang] = yeuCauDV;
            giadichvu[SLkhachhang] = giaDV;
            giaphuthu[SLkhachhang] = giaPT;
            SLkhachhang++;
        }
        fin.close();
    }

    void menuQuanLyKhachHang() {
        int choice;
        do {
            cout << "\n===== QUAN LY KHACH HANG =====\n";
            cout << "1. Them khach hang\n";
            cout << "2. Sua thong tin khach hang\n";
            cout << "3. Xoa khach hang\n";
            cout << "4. Hien thi tat ca khach hang\n";
            cout << "5. Dang ky dich vu cho khach hang\n";
            cout << "0. Thoat\n";
            cout << "Lua chon cua ban: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1: themKhachHang(); break;
            case 2: suaKhachHang(); break;
            case 3: xoaKhachHang(); break;
            case 4: hienThiDanhSachKhachHang(); break;
            case 5: dangKyDichVu(); break;
            case 0: cout << "Thoat quan ly khach hang.\n"; break;
            default: cout << "Lua chon khong hop le!\n";
            }
        } while (choice != 0);
    }
};

// Hàm giới thiệu chương trình
void Intro() {
    cout << "\t ______________________________________________________________________________________________\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|                                 DO AN PBL1: LAP TRINH                                        |\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|                       DE TAI: QUAN LI DICH VU CHAM SOC CAY CANH                              |\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|                                        Giao vien huong dan: Dao Duy Tuan                     |\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|         Sinh vien thuc hien:  Phan Van Minh Hieu                                             |\n";
    cout << "\t|                               Nguyen Thi Ngoc Huyen                                          |\n";
    cout << "\t|                                                                                              |\n";
    cout << "\t|______________________________________________________________________________________________|\n";
}
int main() {
    Intro();
    DichVuChamSocCayCanh dv1;
    Quanlykhachhang qlkh;
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "|         MENU QUAN LI CAY CANH       |\n";
        cout << "========================================\n";
        cout << "| 1. Quan li khach hang               |\n";
        cout << "| 2. Quan li dich vu                  |\n";
        cout << "| 0. Thoat                            |\n";
        cout << "========================================\n";
        cout << "| Lua chon cua ban: ";
        cin >> choice;
        cin.ignore();
        cout << "========================================\n";

        switch (choice) {
        case 1:
            qlkh.menuQuanLyKhachHang();
            break;
        case 2:
            dv1.menuDichVu();
            break;
        case 0:
            cout << "| Thoat chuong trinh.                 |\n";
            cout << "========================================\n";
            break;
        default:
            cout << "| Lua chon khong hop le!              |\n";
            cout << "========================================\n";
        }
    } while (choice != 0);
    return 0;
}



