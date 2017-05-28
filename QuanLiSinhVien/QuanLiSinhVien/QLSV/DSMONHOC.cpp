#include "DSMONHOC.h"

DSMONHOC::DSMONHOC()
{
	root = NULL;
}

void DSMONHOC::createDSMONHOC()
{
	MONHOC monHoc;

	char maMH[15];
	char tenMH[40];
	char c_STCLT[3];
	char c_STCTH[3];
	int sTCLT;
	int sTCTH;

	//tiêu đề chức năng nhập danh scahs môn học
	char titleNhapDSMH[] = "NHAP DANH SACH MON HOC";
	
	//x tọa độ bắt đầu in tiêu đề
	int x = MINX_NDSMH + (MAXX_NDSMH - MINX_NDSMH) / 2 - strlen(titleNhapDSMH) / 2 + 1;

	setGreenText();
	gotoxy(x, 2);
	cout << titleNhapDSMH;
	normal();

NHAPDSMONHOC:
	maMH[0] = '\0';
	tenMH[0] = '\0';
	c_STCLT[0] = '\0';
	c_STCTH[0] = '\0';
	sTCLT = 0;
	sTCTH = 0;

	//Tô đen phần thông tin Môn học vừa nhập
	normal();
	for (int i = MINX_NDSMH; i < MAXX_NDSMH; ++i)
	{
		gotoxy(i, MINY_NDSMH + 4);
		cout << " ";
	}
	//Vẽ khung nhập thông tin môn học
	veKhungNhapDSMONHOC();

NHAPMAMH:
	
	/*
		Hàm nhập mã môn học => gồm kí tự và chữ số không chứa khoảng tắng
		=> Hàm trả về
			0 nếu nhập thành công
			-1 nếu chuỗi rỗng và người dùng muốn kết thúc việc nhập chuỗi
			ESC nếu đang nhập người dùng bấm ESC để thoát ra
	*/
	int checkMH = NhapChuoiVaChuSo(maMH, 15, MINX_NDSMH + 1, MINY_NDSMH + 4);
	//Nhập mã môn học thành công
	if (checkMH == 0)
	{
		//Mã môn học  bị trùng
		if (kiemTraMH(maMH) != NULL) {
			char titleTB[] = "THONG BAO";
			char message[] = "Ma Mon hoc bi trung";
			char td[2][10] = { "Chinh sua", "    Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int check7 = veKhungThongBao(titleTB, message, td);
			//Người dùng chọn chinh sua
			if (check7 == 0)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPMAMH;
			}
			//Người dùng chọn thoát
			else
			{
				return;
			}
		} else 
		if (kiemTraMH(maMH) == NULL)
		{

		NHAPTENMH:

			/*
				Hàm nhập tên môn học => gồm kí tự và chứa khoảng trắng
				=> hàm trả về
				ESC nếu đang nhập người dùng bấm ESC kết thúc việc nhập chuỗi
			*/
			int checkTENMH = NhapChuoi(tenMH, 40, XCOT1_NDSMH + 2, MINY_NDSMH + 4);
			//Người dùng muốn kết thúc việc nhập chuỗi
			if (checkTENMH == ESC)
			{
				char titleExit[] = "THONG BAO";
				char message[] = "Ban co muon thoat khong?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check2 = veKhungThongBao(titleExit, message, td);
				//Người dùng chọn thoát
				if (check2 == 0)
				{
					return;
				}
				//Người dùng chọn tiếp tục
				else
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAPTENMH;
				}
			}
			// Nhập chuỗi thành công
			else
			{
			NHAPSOTCLT:

					//Nhập số lượng tín chỉ lí thuyết => chỉ nhập số
					//=> hàm trả về ESC nếu đang nhập người dùng bấm ESC
				int checkSTCLT = NhapSo(c_STCLT, 3, XCOT2_NDSMH + 2, MINY_NDSMH + 4);

				// Nhập thành công
				if (checkSTCLT != ESC) 
				{
				NHAPSOTCTH:
					//Nhập số lượng tín chỉ thực hành => chỉ nhập số
					//=> hàm trả về ESC nếu đang nhập người dùng bấm ESC
					int checkSTCTH = NhapSo(c_STCTH, 3, XCOT3_NDSMH + 2, MINY_NDSMH + 4);

					//Nhập thành công
					if (checkSTCTH != ESC)
					{
						sTCLT = atoi(c_STCLT);
						sTCTH = atoi(c_STCTH);
						monHoc.nhapMH(maMH, tenMH, sTCLT, sTCTH);
						insertNodeMH(root, monHoc);

						goto NHAPDSMONHOC;
					}
					//Người dùng bấm ESC
					else
					{
						char titleExit[] = "THONG BAO";
						char message[] = "Ban co muon thoat khong?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int check2 = veKhungThongBao(titleExit, message, td);
						//Người dùng chọn thoát
						if (check2 == 0)
						{
							return;
						}
						//Người dùng chọn tiếp tục
						else
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							goto NHAPSOTCTH;
						}
					}
				}
				// người dùng bấm ESC
				else 
				{
					char titleExit[] = "THONG BAO";
					char message[] = "Ban co muon thoat khong?";
					char td[2][10] = { "    Co", "    Khong" };
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					int check2 = veKhungThongBao(titleExit, message, td);
					//Người dùng chọn thoát
					if (check2 == 0)
					{
						return;
					}
					//Người dùng chọn tiếp tục
					else
					{
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						goto NHAPSOTCLT;
					}
				}
			}
		}
		// Mã môn học bị trùng
		else
		{
			char titleExit[] = "THONG BAO";
			char message[] = "Ma mon hoc bi trung?";
			char td[2][10] = { "Chinh sua", "  Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int check2 = veKhungThongBao(titleExit, message, td);
			//Người dùng chọn thoát
			if (check2 == 1)
			{
				return;
			}
			//Người dùng chọn tiếp tục
			else
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPMAMH;
			}
		}
	}
	else if (checkMH == ESC || checkMH == -1)
	{
		char titleExit[] = "THONG BAO";
		char message[] = "Ban co muon thoat khong?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int check2 = veKhungThongBao(titleExit, message, td);
		//Người dùng chọn thoát
		if (check2 == 0)
		{
			return;
		}
		//Người dùng chọn tiếp tục
		else
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			goto NHAPMAMH;
		}
	
	}
}

void DSMONHOC::insertNodeMH(PTRNODEMH &p, MONHOC monHoc)
{
	if (p == NULL)
	{
		p = new NODEMH;
		strcpy(p->MAMH, monHoc.MAMH);
		p->MH = monHoc;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (strcmp(monHoc.MAMH, p->MAMH) < 0)
		{
			insertNodeMH(p->left, monHoc);
		}
		else if (strcmp(monHoc.MAMH, p->MAMH) > 0)
		{
			insertNodeMH(p->right, monHoc);
		}
	}
}

PTRNODEMH DSMONHOC::kiemTraMH(char maMH[])
{
	PTRNODEMH p;
	
	p = root;
	while (p != NULL &&  strcmp(maMH, p->MAMH) != 0)
	{
		if (strcmp(maMH, p->MAMH) < 0)
			p = p->left;
		else
			p = p->right;
	}
	return p;

}

void DSMONHOC::xuatDSLMON()
{
	labelTable("DANH SACH MON HOC");

	if (root == NULL) {
		gotoxy(70, 5);
		cout << "Chua co mon hoc";
		getch();
	}
	else {
		veKhungXuatMonHoc();
		
		int stt = 0;
		int size = 0;
		//PTRNODEMH conTro[50];
		PTRNODEMH* conTro = new PTRNODEMH[50];

		
		PTRNODEMH p=root;
		duyetMAMHtang(p, conTro, size);

		//xep danh sách tăng dần theo tên môn học
		xepDSTangTheoTenMHdemo(conTro, size);

		//in 10 phần tử đầu tiên
			for(int i=0;i<10;i++)
			{	
				stt = i+1;
				inMonHocTheoHang(conTro[i], Y_FIST_MON + stt-1 , stt);
				
			}
			stt = size;
			int TSTrang;
			int trangHT = 1;
			//tinh tong so trang va in ra mang hinh
			if (stt % 10 == 0)
			{
				TSTrang = stt / 10;
			}
			else
			{
				TSTrang = stt / 10 + 1;
			}
			// chỉ số phần tử đầu của trang
			int firstItem = 1;
			//Cho biết nếu bấm F2 sẽ vào cột nào để chỉnh sửa (nếu nhấn F5 sẽ giảm 1, F6 sẽ tăng 1)
			int viTriChinhSua = 1;

			//Hiển thị dòng trang hien tai / Tong so trang
			gotoxy(XCOT4_XDSMH - 10, MINY_XDSMH - 1);
			cout << "Trang: " << trangHT << " / " << TSTrang;

			int kytu = 0;
			do {
				kytu = 0;
				char temp = getch();
				if (temp == -32 || temp == 0)
				{
					temp = getch();
					kytu = temp + 1000;
				}
				else
				{
					kytu = temp;
				}
				switch (kytu)
				{
				case ESC:
				{
					return;
				}
				case PageUp:
					if (trangHT > 1)
					{
						xoaNoiDungVe(MINX_XDSMH - 1, MINY_XDSMH - 1, widthBANG_XLOP, heightBANG_XLOP);
						trangHT--;
						//hiển thị trang
						gotoxy(XCOT4_XDSMH - 10, MINY_XDSMH - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;
						veKhungXuatMonHoc();
						firstItem = (trangHT - 1) * 10;
						for (int i = 0; i < 10; i++)
						{
							PTRNODEMH k = conTro[firstItem++];
							inMonHocTheoHang(k, Y_FIST_MON + i, firstItem);
						}
					}
					break;

				case PageDown:
					if (trangHT < TSTrang)
					{
						xoaNoiDungVe(MINX_XDSMH - 1, MINY_XDSMH - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
						trangHT++;
						//hiển thị trang
						gotoxy(XCOT4_XDSMH - 10, MINY_XSV - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;

						veKhungXuatMonHoc();
						firstItem = (trangHT - 1) * 10;
						for (int i = 0; i < 10; i++)
						{
							if (firstItem < stt)
							{
								PTRNODEMH k = conTro[firstItem++];
								inMonHocTheoHang(k, Y_FIST_SV + i, firstItem);
							}
						}
					}
					break;


				}

			} while (1);

			delete[] conTro;
		getch();
	}
}

void DSMONHOC::duyetMAMHtang(PTRNODEMH p, PTRNODEMH *a, int &size)
{
	if (p != NULL)
	{
		duyetMAMHtang(p->left, a,size);
		a[size++] = p;
		duyetMAMHtang(p->right, a,size);
	}
}

//xếp qicksort :)) nhiều phần tử bị đứng ko biết sao hết :))
void DSMONHOC::xepDSTangTheoTenMH(PTRNODEMH *a, int q,int r)
{
	PTRNODEMH temp;
	int i = q;
	int j = r;
	char x[40]; 
	strcpy(x, a[(q + r) / 2]->MH.getTENMH());
	do {
		while (strcmp(x, a[i]->MH.getTENMH())>0) i++;
		while (strcmp(x, a[i]->MH.getTENMH())<0) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;

		}
	} while (i <= j);
	if (q < j) xepDSTangTheoTenMH(a, q, j);
	if (i < r) xepDSTangTheoTenMH(a, i, r);


}

//cách xếp củ chuối :))) củ chuối nhưng chạy ổn định 
void DSMONHOC::xepDSTangTheoTenMHdemo(PTRNODEMH *a, int size)
{
	PTRNODEMH temp;
	
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(a[i]->MH.getTENMH(), a[j]->MH.getTENMH())>0) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}







void DSMONHOC::inMonHocTheoHang(PTRNODEMH p, int y, int stt)
{
	gotoxy(MINX_XDSMH + 1, y);
	cout << setw(3) << left << stt;
	gotoxy(XCOT1_XDSMH + 2, y);
	cout << p->MH.getMAMH();
	gotoxy(XCOT2_XDSMH + 2, y);
	cout << p->MH.getTENMH();
	gotoxy(XCOT3_XDSMH + 2, y);
	cout << p->MH.getLT();
	gotoxy(XCOT4_XDSMH + 2, y);
	cout << p->MH.getTH();
}

DSMONHOC::~DSMONHOC()
{
}
