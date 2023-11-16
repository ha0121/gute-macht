#include "Header.h"
#include "Source.cpp"

int main() {
    CongTy* danhSachCongTy = nullptr;

    int soCongTy;
    cout << "Nhap so cong ty: ";
    cin >> soCongTy;

    for (int i = 0; i < soCongTy; ++i) {
        CongTy* congTyMoi = NhapThongTinCongTy();
        int soTuyenXeBuyt;
        cout << "Nhap so tuyen xe buyt cua cong ty " << congTyMoi->tenCty << ": ";
        cin >> soTuyenXeBuyt;

        for (int j = 0; j < soTuyenXeBuyt; ++j) {
            TuyenXeBuyt* tuyenMoi = NhapThongTinTuyenXeBuyt();
            ThemTuyenXeBuyt(congTyMoi, tuyenMoi);
        }

        if (danhSachCongTy == nullptr) {
            danhSachCongTy = congTyMoi;
        }
        else {
            congTyMoi->nextCty = danhSachCongTy;
            danhSachCongTy = congTyMoi;
        }
    }

    // Thêm công ty 
    CongTy* congTyMoi = NhapThongTinCongTy();
    int viTri;
    cout << "Nhap vi tri muon them cong ty: ";
    cin >> viTri;

    if (viTri == 0) {
        congTyMoi->nextCty = danhSachCongTy;
        danhSachCongTy = congTyMoi;
    }
    else {
        CongTy* temp = danhSachCongTy;
        for (int i = 0; i < viTri - 1 && temp != nullptr; ++i) {
            temp = temp->nextCty;
        }

        if (temp != nullptr) {
            congTyMoi->nextCty = temp->nextCty;
            temp->nextCty = congTyMoi;
        }
        else {
            std::cout << "Vi tri khong hop le. Khong the them cong ty." << std::endl;
        }
    }

    // Xóa công ty khi biết Mã Cty hoặc tên Công ty
    int luaChon;
    cout << "Chon cach xoa cong ty (1: Ma Cty, 2: Ten Cong Ty): ";
    cin >> luaChon;

    if (luaChon == 1) {
        int maCtyCanXoa;
        cout << "Nhap Ma Cong Ty can xoa: ";
        cin >> maCtyCanXoa;
        XoaCongTy(danhSachCongTy, maCtyCanXoa);
    }
    else if (luaChon == 2) {
        string tenCtyCanXoa;
        cout << "Nhap Ten Cong Ty can xoa: ";
        cin.ignore();
        getline(cin, tenCtyCanXoa);
        XoaCongTy(danhSachCongTy, tenCtyCanXoa);
    }
    else {
        cout << "Lua chon khong hop le." << endl;
    }

    // Tìm tuyến xe buýt khi biết tên tuyến hoặc mã tuyến
    int luaChonTim;
    cout << "Chon cach tim tuyen xe buyt (1: Ma Tuyen, 2: Ten Tuyen): ";
    cin >> luaChonTim;

    if (luaChonTim == 1) {
        int maTuyenCanTim;
        cout << "Nhap Ma Tuyen can tim: ";
        cin >> maTuyenCanTim;
        TimTuyenXeBuyt(danhSachCongTy, maTuyenCanTim);
    }
    else if (luaChonTim == 2) {
        string tenTuyenCanTim;
        cout << "Nhap Ten Tuyen can tim: ";
        cin.ignore
                    ();
        getline(cin, tenTuyenCanTim);
        TimTuyenXeBuyt(danhSachCongTy, tenTuyenCanTim);
    } else {
        cout << "Lua chon khong hop le." << endl;
    }

    // Thêm một tuyến xe buýt vào một công ty khi biết mã Công ty
    int maCongTyThemTuyen;
    cout << "Nhap Ma Cong Ty muon them tuyen xe buyt: ";
    cin >> maCongTyThemTuyen;
    ThemTuyenChoCongTy(danhSachCongTy, maCongTyThemTuyen);

    // bonus giải phóng data
    CongTy* tempCongTy = danhSachCongTy;
    while (tempCongTy != nullptr) {
        CongTy* nextCongTy = tempCongTy->nextCty;
        TuyenXeBuyt* tempTuyen = tempCongTy->danhSachTuyen;
        while (tempTuyen != nullptr) {
            TuyenXeBuyt* nextTuyen = tempTuyen->nextTuyen;
            delete tempTuyen;
            tempTuyen = nextTuyen;
        }
        delete tempCongTy;
        tempCongTy = nextCongTy;
    }

    return 0;
}

