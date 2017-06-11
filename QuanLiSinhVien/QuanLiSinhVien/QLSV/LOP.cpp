#include "LOP.h"

LOP::LOP()
{
	First = NULL;
}

void LOP::suaSVTheoMaSo(char _MASO[])
{
	//veKhungNhapTTSinhVien();
}

void LOP::suaSVtheoConTro(PTRNODESV p)
{
	SINHVIEN SVIEN = p->SV;
	hienThiTTSV(p);
	char maSV[constMASV], hoSV[constHO], tenSV[constTENSV], phai[constPHAI], sdt[constSDT];
	maSV[0] = '\0';
	hoSV[0] = '\0';
	tenSV[0] = '\0';
	phai[0] = '\0';
	sdt[0] = '\0';
	
	//gan gia tri
	strcpy(maSV, p->SV.getMASV());
	strcpy(hoSV, p->SV.getHO());
	strcpy(tenSV, p->SV.getTEN());
	strcpy(phai, p->SV.getPHAI());
	strcpy(sdt, p->SV.getSDT());

	//Cho biết nếu bấm F2 sẽ vào cột nào để chỉnh sửa (nếu nhấn F5 sẽ giảm 1, F6 sẽ tăng 1)
	int viTriChinhSua = 1;
	int y = MINY_BSV + 4;
	gotoxy(MINX_BSV + 1 + strlen(maSV), y);

	int kiTu = 0;
	do{
		kiTu = 0;
		char temp = getch();
		if (temp == -32 || temp == 0)
		{
			temp = getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		switch (kiTu)
		{
		case ESC:
			return;
			break;
		case Left:
		{
					 if (viTriChinhSua >1)
					 {
						 viTriChinhSua--;
						 if (viTriChinhSua == 1)
						 {
							 gotoxy(MINX_BSV + strlen(maSV) + 1,y);
						 }
						 else if (viTriChinhSua == 2)
						 {
							 gotoxy(svCot1 + strlen(hoSV) + 2,y);
						 }
						 else if (viTriChinhSua == 3)
						 {
							 gotoxy(svCot2 + strlen(tenSV) + 2, y);
						 }
						 else if (viTriChinhSua == 4)
						 {
							 gotoxy(svCot3 + strlen(phai) + 1, y);
						 }
					 }
					 break;
		}
		case Right:
		{
					  if (viTriChinhSua < 5)
					  {
						  viTriChinhSua++;
						  if (viTriChinhSua == 5)
						  {
							  gotoxy(svCot4 + strlen(sdt) + 1, y);
						  }
						  else if (viTriChinhSua == 4)
						  {
							  gotoxy(svCot3 + strlen(phai) + 1, y);
						  }
						  else if (viTriChinhSua == 3)
						  {
							  gotoxy(svCot2 + strlen(tenSV) + 2, y);
						  }
						  else if (viTriChinhSua == 2)
						  {
							  gotoxy(svCot1 + strlen(hoSV) + 2, y);
						  }

					  }
					  break;
		}
		case F2:
			if (viTriChinhSua == 1){
				do
				{
					int kiTu = NhapChuoiVaChuSo(maSV, constMASV, MINX_BSV + 1, y);
					//Chuỗi mã Sinh viên trả về bị rỗng
					if (kiTu == fail)
					{
						char title[] = "THONG BAO";
						char message[] = "Ma SV khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							maSV[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							gotoxy(MINX_XSV + 1, y);
							for (int i = 0; i < widthBANG_XLOP - 2; ++i)
							{
								cout << " ";
							}
						//	inSVTheoHang(k, y, viTri + 1);
							break;
						}


					}
					else if (strcmp(maSV, p->SV.getMASV()) == 0)
					{
						break;
					}
					else if (searchSV(maSV) == NULL && kiTu == 0)
					{
						p->SV.setMASV(maSV);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua MASV";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						gotoxy(MINX_BSV +1 + strlen(maSV), y);
						break;

					}
					
					//Mã sinh viên bị trùng
					else if (searchSV(maSV) != NULL && kiTu == 0)
					{
						char title[] = "THONG BAO";
						char message[] = "Ma sinh vien bi trung!";
						char td[2][10] = { "Chinh sua", "Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							gotoxy(MINX_XSV + 1, y);
							for (int i = 0; i < widthBANG_XSV - 2; i++)
							{
								cout << " ";
							}
							//inSVTheoHang(k, y, viTri + 1);
							break;

						}
					}
				} while (1);
			}
			else if (viTriChinhSua == 2){
				do
				{
					int kiTu = NhapChuoi(hoSV, constHO, svCot1 + 2, y);
					//Chuỗi ho Sinh viên trả về bị rỗng
					if (kiTu == -1)
					{
						char title[] = "THONG BAO";
						char message[] = "Ho SV khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							hoSV[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							return;
							
						}
					}
					else if (strcmp(hoSV, p->SV.getHO()) == 0)
					{
						break;
					}
					else 
					{
						p->SV.setHO(hoSV);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua Ho";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						gotoxy(MINX_BSV + 1 + strlen(hoSV), y);
						break;

					}

					
				} while (1);
			}
			else if (viTriChinhSua == 3){
				do{
					int kiTu = NhapChuoi(tenSV, constTENSV, svCot2 + 2, y);
					if (tenSV[0]=='/0')
					{
						char title[] = "THONG BAO";
						char message[] = "TEN SV khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							tenSV[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							return;
						}

					}
					else if (strcmp(tenSV, p->SV.getTEN()) == 0) {
						break;
					}
					else {

						p->SV.setTEN(tenSV);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua Ten SV";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						strcpy(tenSV, p->SV.getTEN());
						gotoxy(svCot2 + 2 + strlen(tenSV), y);
						break;

					}
				} while (1);
			}
			else if (viTriChinhSua == 4){
				do{
					int kiTu = NhapChuoi(phai, constPHAI, svCot3 + 1, y);
					if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
					{
						char title[] = "THONG BAO";
						char message[] = "Phai NAM/NU!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							return;
						}


					}
					else {
						p->SV.setPHAI(phai);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da chinh sua PHAI";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						strcpy(phai, p->SV.getPHAI());
						gotoxy(svCot3 + 1 + strlen(phai), y);
						break;
					}
				} while (1);
			}
			else if (viTriChinhSua == 5){
				do{
					int kiTu = NhapSo(sdt, constSDT, svCot4 + 1,y);
					if (strlen(sdt)<10)
					{
						char title[] = "THONG BAO";
						char message[] = "SDT khong hop le!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{

							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							return;
						}


					}
					else {
						p->SV.setSDT(sdt);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua sdt";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						strcpy(sdt, p->SV.getSDT());
						gotoxy(svCot4 + 1 + strlen(sdt), y);
						break;
					}
				} while (1);
			}
			break;
		default:
			break;
		}
	} while (1);
}

void LOP::nhapLOP(char MLOP[], char TENL[], int NH)
{
	strcpy(MALOP, MLOP);
	strcpy(TENLOP, TENL);
	NAMHOC = NH;
}

void LOP::xuatLOP()
{

}

void LOP::setNH(int nh)
{
	NAMHOC = nh;
}

void LOP::setMLOP(char ML[])
{
	strcpy(MALOP, ML);
}

void LOP::setTENL(char TL[])
{
	strcpy(TENLOP, TL);
}

void LOP::getMALOP(char ML[])
{
	strcpy(ML, MALOP);
}

void LOP::getTENLOP(char TENL[])
{
	strcpy(TENL, TENLOP);
}

int LOP::getNH()
{
	return NAMHOC;
}

void LOP::xuatDiemTheoHang(PTRDIEM_SV pDiemSV, int y, int stt)
{

	SINHVIEN sv = pDiemSV->nodeSV->SV;
	gotoxy(MINX_BNMH2 + 1, y);
	cout << stt;
	gotoxy(XCOT1_BNMH2 + 1, y);
	cout << sv.getMASV();
	gotoxy(XCOT2_BNMH2 + 1, y);
	cout << sv.getHO();
	gotoxy(XCOT3_BNMH2 + 1, y);
	cout << sv.getTEN();
	if (pDiemSV->diemSV != NULL)
	{
		float diemSV = pDiemSV->diemSV->diem.getDiem();
		gotoxy(XCOT4_BNMH2 + 1, y);
		cout << diemSV;
	}
}

int LOP::nhapDiem(char MAMH[], int lanThi)
{
	char c_Diem[constDiemThi];
	c_Diem[0] = '/0';
	float f_Diem;

	PTRDIEM_SV *a = NULL;
	int n = 0;
	timSinhVienNhapDiem(MAMH, lanThi, a, n);
	if (a == NULL)
	{
		return fail;
	}
	
	//Trong mảng a lúc này chứa tất cả sinh viên có mã môn học thỏa điều kiện
	//Xóa bảng nhập điểm
	xoaNoiDungVe(MINX_NDIEM, 4, 70, 18);
	
	//In tiêu đề
	setGreenText();
	gotoxy(70, 2);
	cout << "NHAP DIEM LOP: " << MALOP;
	gotoxy(74, 3);
	cout << "Mon Hoc: " << MAMH;
	normal();
	gotoxy(75, 4);
	cout << "Lan thi: " << lanThi;
 
	//Cho biết tổng số trang
	int TSTrang;
	int trangHT = 1;

	if (n % 10 == 0)
	{
		TSTrang = n / 10;
	}
	else
	{
		TSTrang = n / 10 + 1;
	}

	//Lưu số thứ tự lớn nhất của dùng đang hiển thị
	int stt = 0;

	//Xoa bang nhap diem
	xoaNoiDungVe(MINX_BNMH2, MINY_BNMH2 - 1, 70, 15);
	//Ve khung nhap Diem
	veKhungNhapDiemTrenDSLop();

	gotoxy(XCOT3_BNMH2, MINY_BNMH2 - 1);
	cout << "Trang: " << trangHT << " / " << TSTrang;


	if (trangHT < TSTrang)
	{
		for (int i = 0; i < 10; ++i, stt++)
		{
			xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);
		}
	}
	else
	{
		for (int i = 0; i < (n % 10); ++i, stt++)
		{
			xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);

		}
	}

	//Highlight dòng đầu tiên
	SetBGColor(green_Dark);
	for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
	{
		gotoxy(i, Y_FIST_DIEM);
		cout << " ";
	}
	xuatDiemTheoHang(a[0], Y_FIST_DIEM , 1);

	gotoxy(XCOT4_BNMH2 + 3, Y_FIST_DIEM);

	//Cho biet toa do y con nhay dang dung
	int yHienTai = Y_FIST_DIEM;
	//Cho biết số thứ tự tại dòng conn nháy đang đứng
	int viTriHT = 1;

	//Người dùng bắt đầu nhập điểm
	int kiTu;

	do
	{
		kiTu = 0;
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		switch (kiTu)
		{
		case PageDown:
		{
			if (viTriHT < stt)
			{
				//In lại dòng cũ với BG đen
				SetBGColor(black);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}
				//Ve khung nhap Diem
				veKhungNhapDiemTrenDSLop();
				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);

				//Highlight dòng mới
				viTriHT++;
				yHienTai++;

				SetBGColor(green_Dark);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}

				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);

				gotoxy(XCOT4_BNMH2 + 3, yHienTai);
			}
			else if (trangHT < TSTrang)
			{
				xoaNoiDungVe(MINX_BNMH2, MINY_BNMH2 - 1, 70, 14);
				trangHT++;
				gotoxy(XCOT3_BNMH2, MINY_BNMH2 - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;

				yHienTai = Y_FIST_DIEM;
				viTriHT = (trangHT - 1) * 10 + 1;

				//In lại các dòng nhập điểm mới
				if (trangHT < TSTrang)
				{
					for (int i = 0; i < 10; ++i, stt++)
					{
						xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);
					}
				}
				else
				{
					for (int i = 0; i < (n % 10); ++i, stt++)
					{
						xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);
					}
				}
				//Ve khung nhap Diem
				veKhungNhapDiemTrenDSLop();

				//Highlight dong dau tien
				SetBGColor(green_Dark);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}

				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);
				gotoxy(XCOT4_BNMH2 + 3, yHienTai);
			}
			break;
		}
		case PageUp:
		{
			//Vị trí hiện tại bé hơn stt dòng đầu tiên đang in
			if (viTriHT > (trangHT - 1) * 10 + 1)
			{
				//In lại dòng cũ với BG đen
				SetBGColor(black);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}
				//Ve khung nhap Diem
				veKhungNhapDiemTrenDSLop();
				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);

				//Highlight dòng mới
				viTriHT--;
				yHienTai--;

				SetBGColor(green_Dark);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}

				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);

				gotoxy(XCOT4_BNMH2 + 3, yHienTai);
			}
			else if (trangHT > 1)
			{
				xoaNoiDungVe(MINX_BNMH2, MINY_BNMH2 - 1, 70, 14);
				trangHT--;
				gotoxy(XCOT3_BNMH2, MINY_BNMH2 - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;

				yHienTai = Y_FIST_DIEM + 9;
				viTriHT = trangHT * 10;
				stt = viTriHT - 10;

				//In lại các dòng nhập điểm mới
				if (trangHT < TSTrang)
				{
					for (int i = 0; i < 10; ++i, stt++)
					{
						xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);
					}
				}
				else
				{
					for (int i = 0; i < (n % 10); ++i, stt++)
					{
						xuatDiemTheoHang(a[stt], Y_FIST_DIEM + i, stt + 1);
					}
				}
				//Ve khung nhap Diem
				veKhungNhapDiemTrenDSLop();

				//Highlight dong dau tien
				SetBGColor(green_Dark);
				for (int i = MINX_BNMH2 + 1; i < MAXX_BNMH2; ++i)
				{
					gotoxy(i, yHienTai);
					cout << " ";
				}

				xuatDiemTheoHang(a[viTriHT - 1], yHienTai, viTriHT);
				gotoxy(XCOT4_BNMH2 + 3, yHienTai);
			}
			break;
		}
		case ESC:
		{
			SetBGColor(black);
			int currentX = wherex();
			int currentY = wherey();
			char title[10] = "THONG BAO";
			char message[30] = "Ban co muon thoat?";
			char td[2][10] = { "    Co", "    Khong" };
			gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			//Nguoi dung chon Thoat
			if (checkTHONGBAO == 0)
			{
				return successfull;
			}
			//Nguoi dung chon tiep tuc
			else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
			{
				xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
				gotoxy(currentX, currentY);
			}
			break;
		}
		default:
		{
			if (char(kiTu) >= '0' && char(kiTu) <= '9')
			{
				int currentX = wherex();
				int currentY = wherey();
				c_Diem[0] = char(kiTu);
				c_Diem[1] = '\0';
				cout << char(kiTu);
				gotoxy(currentX, currentY);
				NhapSoThuc(c_Diem, constDiemThi, currentX - 1, currentY);
				//Chuyển điểm từ chuỗi sang số
				f_Diem = atof(c_Diem);
				if (f_Diem >= 0.0 || f_Diem <= 10.0)
				{
					SINHVIEN sv = a[viTriHT - 1]->nodeSV->SV;
					sv.createDSDIEM();
				}
				//Điểm không hợp lệ
				else
				{

				}
			}
		}
		}
	} while (true);

	return successfull;
}

void LOP::inDiem(char MAMH[], int lanThi)
{
}

void LOP::nhapTTDiem()
{
	veKhungNhapTTDiem();
	char c = getch();
}

void LOP::PTRNODESVPushBack(PTRNODESV *&a, int &n, PTRNODESV sv)
{
	int m = n + 1;
	PTRNODESV* aNew = (PTRNODESV*)realloc(a, m * sizeof(PTRNODESV));
	if (aNew != NULL) {
		aNew[n] = new NODESV;
		aNew[n] = sv;
		n++;
		a = aNew;
	}
}

PTRNODESV LOP::newNODESV()
{
	PTRNODESV p;
	p = new NODESV();
	if (p == NULL)
	{
		gotoxy(MINX_BLOP, MINY_BLOP);
		cout << "Loi cap phat bo nho!";
	}
	return p;
}

void LOP::insertFirst(SINHVIEN SVIEN)
{
	PTRNODESV p = newNODESV();
	if (First == NULL)
	{
		p->next = NULL;
	}
	else
	{
		p->next = First;
	}
	p->SV = SVIEN;
	First = p;
}

void LOP::insertAfter(SINHVIEN SVIEN, PTRNODESV p)
{

	if (p == NULL)
		cout << "khong them phan tu vao danh sach duoc";
	else
	{
		PTRNODESV q = newNODESV();
		q->SV = SVIEN;
		q->next = p->next;
		p->next = q;
	}
}

void LOP::insertLast(SINHVIEN SVIEN)
{
	
	if (First == NULL)
	{
		insertFirst(SVIEN);
	}
	else
	{
		PTRNODESV p = newNODESV();
		p = First;
		while (p->next != NULL){
			p = p->next;	
		}
		// them sinh vien vao cuoi danh sach
		insertAfter(SVIEN, p);
	}	
}

PTRNODESV LOP::searchSV(char maSV[])
{

	PTRNODESV p;
	p = First;
	while (p != NULL && strcmp(p->SV.getMASV(), maSV) != 0)
	{
		p = p->next;
	}
	return p;
}

void LOP::createDSSV()
{
	char title[10] = "THONG BAO";
	char message[30] = "Ban co muon thoat?";
	char td[2][10] = { "    Co", "    Khong" };
	char labelTb[30] = "NHAP SINH VIEN LOP ";
	labelTable(strcat(labelTb, MALOP));
	bool flag = true;
	for (int i = 0; i < 100; ++i	){
		for (int j = 0; j < 70; ++j)
		{
			SetColor(0);
			gotoxy(MINX_BSV + j, MINY_BSV + 4);
			cout << " ";
		}
		SetColor(15);
	veKhungNhapTTSinhVien();
	
	char maSV[constMASV], hoSV[constHO], tenSV[constTENSV], phai[constPHAI], sdt[constSDT];
	maSV[0] = '\0';
	hoSV[0] = '\0';
	tenSV[0] = '\0';
	phai[0] = '\0';
	sdt[0] = '\0';

NHAPTTSV:
	//check nhận giá trị 0 nếu MASV nhập đúng chuẩn, -1 nếu chuỗi rỗng, ESC nếu người dùng bấm thoát
	int checkMASV = NhapChuoiVaChuSo(maSV, constMASV, MINX_BSV + 1, MINY_BSV + 4);
	if (checkMASV == 0)
	{
		//Kiểm tra mã sinh viên có tồn tại không, nếu không tồn tại trả về NULL
		if (searchSV(maSV) != NULL){ //mã sv đã tồn tại
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			char td2[2][10] = { "Chinh Sua", "    Thoat" };
			int check = veKhungThongBao(title, "Da ton tai Ma Sv ", td2);
			if (check == 1)
			{
				return;
			}
			else if (check == 0 || check == ESC)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPTTSV;
			}
		}
		//Ma  sv hop le
		else
		{
		NHAP_HOSV:
			//Nhập Ho sv, không cho phép rỗng
			int checkHO = NhapChuoi(hoSV, constHO, svCot1 + 1, MINY_BSV + 4);
			if (checkHO == ESC)
			{
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check2 = veKhungThongBao(title, message, td);
				if (check2 == 0)
				{
					return;
				}
				else if (check2 == 1 || check2 == ESC)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_HOSV;
				}
			}
		NHAP_TENSV:
			int checkTEN = NhapChuoi(tenSV, constTENSV, svCot2 + 1, MINY_BSV + 4);
			if (checkTEN == ESC)
			{

				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check3 = veKhungThongBao(title, message, td);
				if (check3 == 0)
				{
					return;
				}
				else if (check3 == 1 || check3 == ESC)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_TENSV;
				}
			}
		NHAP_PHAI:
			int checkPHAI = NhapChuoi(phai, constPHAI, svCot3 + 1, MINY_BSV + 4);
			if (checkPHAI == 0){
				if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
				{
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					cout << "Phai khong hop le!";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, 30, 1);
					goto NHAP_PHAI;
				}
			}
			else if (checkPHAI == ESC)
			{
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check4 = veKhungThongBao(title, message, td);
				if (check4 == 0)
				{
					return;
				}
				else if (check4 == 1 || check4 == ESC)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_PHAI;
				}
			}
		NHAP_SDT:
			int checkSDT = NhapSo(sdt, constSDT, svCot4 + 1, MINY_BSV + 4);
			if (checkSDT == 0){
				if (strlen(sdt)<10)
				{
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					cout << "sdt khong hop le!";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, 30, 1);
					goto NHAP_SDT;
				}
			}
			else if (checkSDT == ESC)
			{
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check5 = veKhungThongBao(title, message, td);
				if (check5 == 0)
				{
					return;
				}
				else if (check5 == 1 || check5 == ESC)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_SDT;
				}
			}
		}
		SINHVIEN sv(maSV, hoSV, tenSV, phai, sdt);
		insertLast(sv);
	}
	else if (checkMASV == ESC || checkMASV == -1)
	{
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int checkThongBao = veKhungThongBao(title, message, td);
		if (checkThongBao == 0)
		{
			return;
		}
		else if (checkThongBao == 1 || checkThongBao == ESC)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			goto NHAPTTSV;
		}

	}
}
}

void LOP::inSVTheoHang(PTRNODESV sv, int y, int stt)
{


	gotoxy(MINX_XSV + 1, y);
	cout << setw(3) << left << stt;
	gotoxy(X_XSV_COT1 + 2, y);
	cout << sv->SV.getMASV();
	gotoxy(X_XSV_COT2 + 2, y);
	cout << sv->SV.getHO();
	gotoxy(X_XSV_COT3 + 2, y);
	cout << sv->SV.getTEN();
	gotoxy(X_XSV_COT4 + 2, y);
	cout << sv->SV.getPHAI();
	gotoxy(X_XSV_COT5 + 2, y);
	cout << sv->SV.getSDT();
}

void LOP::xuatDSSV(){

	labelTable("DANH SACH SINH VIEN");

	gotoxy(76, 3);

	cout << "LOP: " << MALOP;
	PTRNODESV p = First;
	if (p == NULL)
	{
		gotoxy(70, 5);
		cout << "Chua co Sinh vien";
		//return;
		getch();
	}
	else {

		veKhungXuatSVTheoLop();
		int stt = 0;
		PTRNODESV conTro[50];
		for (p = First; p != NULL; p = p->next){
			conTro[stt++] = p;
			if (stt <= 10)
			{
				inSVTheoHang(p, Y_FIST_SV + stt - 1, stt);
			}
		}
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
		int firstItem=1;
		//Cho biết nếu bấm F2 sẽ vào cột nào để chỉnh sửa (nếu nhấn F5 sẽ giảm 1, F6 sẽ tăng 1)
		int viTriChinhSua = 1;

		//Hiển thị dòng trang hien tai / Tong so trang
		gotoxy(X_XSV_COT4 - 10, MINY_XSV - 1);
		cout << "Trang: " << trangHT << " / " << TSTrang;
		//char kytu = getch();
		int kytu = 0;
		do{
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
					xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV, heightBANG_XSV);
					trangHT--;
					//hiển thị trang
					gotoxy(X_XSV_COT4 - 10, MINY_XSV - 1);
					cout << "Trang: " << trangHT << " / " << TSTrang;
					veKhungXuatSVTheoLop();
					firstItem = (trangHT - 1) * 10;
					for (int i = 0; i < 10; i++)
					{
						PTRNODESV k = conTro[firstItem++];
						inSVTheoHang(k, Y_FIST_SV + i, firstItem);
					}
				}
				break;
			case PageDown:
				if (trangHT < TSTrang)
				{
					xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
					trangHT++;
					//hiển thị trang
					gotoxy(X_XSV_COT4 - 10, MINY_XSV - 1);
					cout << "Trang: " << trangHT << " / " << TSTrang;

					veKhungXuatSVTheoLop();
					firstItem = (trangHT - 1) * 10;
					for (int i = 0; i < 10;i++)
					{
						if (firstItem < stt)
						{
							PTRNODESV k = conTro[firstItem++];
							inSVTheoHang(k, Y_FIST_SV + i, firstItem);
						}
					}
				}
				break;
			case Enter:
				
				//highlight sinh viên đầu tiên của trang
				firstItem = (trangHT - 1) * 10;
				PTRNODESV k = conTro[firstItem];
				gotoxy(MINX_XSV + 1, Y_FIST_SV);
				SetBGColor(green_Dark);
				for (int i = 0; i < widthBANG_XSV - 2; i++)
				{
					cout << " ";
				}
				inSVTheoHang(k, Y_FIST_SV, firstItem + 1);

				//đưa con trỏ về sau masv của dòng SV đang chọn
				gotoxy(X_XSV_COT1 + strlen(k->SV.getMASV()) + 2, Y_FIST_SV);
				int kiTu;
				int viTri = firstItem;
				do
				{
					k = conTro[viTri]; 

					char maSV[constMASV], hoSV[constHO], tenSV[constTENSV], phai[constPHAI], sdt[constSDT];
					maSV[0] = '\0';
					hoSV[0] = '\0';
					tenSV[0] = '\0';
					phai[0] = '\0';
					sdt[0] = '\0';

					//gán giá trị 
					strcpy(maSV, k->SV.getMASV());
					strcpy(hoSV, k->SV.getHO());
					strcpy(tenSV, k->SV.getTEN());
					strcpy(phai, k->SV.getPHAI());
					strcpy(sdt, k->SV.getSDT());

					kiTu = 0;
					fflush(stdin);
					char temp = getch();
					if (temp == -32 || temp == 0)
					{
						temp = getch();
						kiTu = temp + 1000;
					}
					else
					{
						kiTu = temp;
					}
					switch (kiTu)
					{
					case PageDown:
						if (viTri < firstItem + 9 && viTri < stt - 1){
							k = conTro[viTri];
							viTriChinhSua = 1;
							//sua noi dung tại dòng cũ
							int y = wherey();
							gotoxy(MINX_XLOP + 1, y);
							SetBGColor(black);
							for (int i = MINX_XSV + 1; i <=MAXX_XSV; ++i)
							{
								if (i == X_XSV_COT1 || i == X_XSV_COT2 || i == X_XSV_COT3 || i == X_XSV_COT4 || i == X_XSV_COT5 || i == MAXX_XSV) {
									cout << (char)179;
								}
								else
									cout << " ";

							}
							
							inSVTheoHang(k, y, viTri + 1);
							//Hight light dòng mới
							//k lúc này sẽ chứa chỉ số dòng mới
							k = conTro[++viTri];
							
							SetBGColor(green_Dark);
							gotoxy(MINX_XLOP + 1, wherey() + 1);
							for (int i = 0; i < widthBANG_XSV - 2; ++i)
							{
								cout << " ";
							}
							inSVTheoHang(k, wherey(), viTri + 1);
							gotoxy(X_XSV_COT1 + strlen(k->SV.getMASV()) + 2, wherey());

						}
						else if (trangHT < TSTrang)
						{
							
							viTriChinhSua = 1;
							xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
							trangHT++;
							gotoxy(X_XSV_COT4 - 10, MINY_XSV - 1);
							cout << "Trang: " << trangHT << " / " << TSTrang;
							veKhungXuatSVTheoLop();
							firstItem = (trangHT - 1) * 10;
							viTri = firstItem;
							//viTri = 1;
							for (int i = 0; i < 10; ++i)
							{
								if (viTri < stt)
								{
									k = conTro[viTri++];
									inSVTheoHang(k, Y_FIST_SV + i, viTri);
								}
							}

							//hightLight dong dau tien trang moi
							viTri = firstItem;
							if (viTri < (firstItem + 9) && viTri < stt)
							{
								int y = Y_FIST_SV;
								k = conTro[viTri];
								gotoxy(MINX_XLOP + 1, y);
								
								SetBGColor(green_Dark);
								
								for (int i = 0; i < widthBANG_XSV - 2; ++i)
								{
									cout << " ";
								}
								inSVTheoHang(k, y, viTri + 1);
								gotoxy(X_XSV_COT1 + strlen(k->SV.getMASV()) + 2,y);
							}
						}
						break;//kết thúc lệnh trong case pagedown

					case PageUp:
					{
								   if (viTri > 0 && viTri > firstItem)
								   {
									   viTriChinhSua = 1;
									   //sua noi dung tại dòng cũ
									   int y = wherey();
									   k = conTro[viTri];
									   gotoxy(MINX_XSV + 1, y);
									   SetBGColor(black);
									   for (int i = MINX_XSV + 1; i <= MAXX_XSV; ++i)
									   {
										   if (i == X_XSV_COT1 || i == X_XSV_COT2 || i == X_XSV_COT3 || i == X_XSV_COT4 || i == X_XSV_COT5 || i == MAXX_XSV){
											   cout << (char)179;
										   }
										   else
											   cout << " ";

									   }

									   inSVTheoHang(k, y, viTri + 1);

									   //Hight light dòng mới
									   k = conTro[--viTri];
									   SetBGColor(green_Dark);
									   gotoxy(MINX_XLOP + 1, wherey() - 1);
									   for (int i = 0; i < widthBANG_XSV - 2; ++i)
									   {
										   cout << " ";
									   }
									   inSVTheoHang(k, wherey(), viTri + 1);
									   gotoxy(X_XSV_COT1 + strlen(k->SV.getMASV()) + 2, wherey());

								   }
								   else if (trangHT > 0 && viTri > 0)
								   {
									   viTriChinhSua = 1;
									   xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
									   trangHT--;
									   gotoxy(X_XSV_COT4 - 10, MINY_XSV - 1);
									   cout << "Trang: " << trangHT << " / " << TSTrang;
									   veKhungXuatSVTheoLop();
									   firstItem = (trangHT - 1) * 10;
									   viTri = firstItem;
									   for (int i = 0; i < 10; ++i)
									   {
										   if (viTri < stt)
										   {
											   k = conTro[viTri++];
											   inSVTheoHang(k, Y_FIST_SV + i, viTri);
										   }
									   }
									   viTri = firstItem + 9;
									   if (viTri > 0)
									   {
										   int y = Y_FIST_SV + 9;
										   k = conTro[viTri];
										   gotoxy(MINX_XLOP + 1, y);
										   SetBGColor(green_Dark);
										   for (int i = 0; i < widthBANG_XLOP - 2; ++i)
										   {
											   cout << " ";
										   }

										   inSVTheoHang(k, y, viTri + 1);
										   gotoxy(X_XLOP_COT1 + strlen(k->SV.getMASV()) + 2, y);// Y_FIST_SV + viTri);
									   }
								   }
								   break;
					}//kết thúc lệnh trong case pageup
					case ESC:
					{
								return;
					}
					case F2:
					{
							   int y = Y_FIST_SV + viTri - (trangHT-1) * 10;
							   if (viTriChinhSua == 1)
							   {
								   do
								   {
									   SetBGColor(green_Dark);
									   int kiTu = NhapChuoiVaChuSo(maSV, constMASV, X_XSV_COT1 + 2,y); 
									   //Chuỗi mã Sinh viên trả về bị rỗng
									   if (kiTu == -1)
									   {

										   char title[] = "THONG BAO";
										   char message[] = "Ma SV khong duoc rong!";
										   char td[2][10] = { "Chinh sua", "    Huy" };
										   normal();
										   gotoxy(MINX_ALERTTB, MINY_ALERTTB);
										   int select = veKhungThongBao(title, message, td);
										   if (select == 0)
										   {
											   //Cho biet chuoi dang rong
											   maSV[0] = '\0';
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   continue;
										   }
										   else if (select == 1)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											 
											   k = conTro[viTri];
											   SetBGColor(green_Dark);
											   gotoxy(MINX_XSV + 1, y);
											   for (int i = 0; i < widthBANG_XLOP - 2; ++i)
											   {
												   cout << " ";
											   }
											   inSVTheoHang(k, y, viTri + 1);
											   break;
										   }


									   }
									   else if (searchSV(maSV) == NULL && kiTu == 0)
									   {
										  k->SV.setMASV(maSV);
										  gotoxy(MINX_ALERTTB, 24);
										  cout << "da sua ma sv";
										  Sleep(1000);
										  xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
										  gotoxy(X_XSV_COT1 + 2+strlen(maSV), y);
										   break;
									   }
									   else if (strcmp(maSV, k->SV.getMASV()) == 0)
									   {
										   break;
									   }
									   //Mã sinh viên bị trùng
									   else if (searchSV(maSV) != NULL && kiTu == 0)
									   {
										   char title[] = "THONG BAO";
										   char message[] = "Ma sinh vien bi trung!";
										   char td[2][10] = { "Chinh sua", "Huy" };
										   normal();
										   gotoxy(MINX_ALERTTB, MINY_ALERTTB);
										   int select = veKhungThongBao(title, message, td);
										   if (select == 0)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   continue;
										   }
										   else if (select == 1)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   int y = Y_FIST_SV + viTri;
											   k = conTro[viTri];
											   SetBGColor(green_Dark);
											   gotoxy(MINX_XSV + 1, y);
											   for (int i = 0; i < widthBANG_XSV - 2;i++)
											   {
												   cout << " ";
											   }
											   inSVTheoHang(k, y, viTri + 1);
											   break;
										   }
									   }
								   } while (true);
							   }
							   else if (viTriChinhSua == 2)
							   {
								   SetBGColor(green_Dark);
								   int kiTu = NhapChuoi(hoSV, constHO, X_XSV_COT2 + 2,y);
								   if (strcmp(hoSV, k->SV.getHO())==0) {
									   break;
								   } 
								   else {
										k->SV.setHO(hoSV);
									   gotoxy(MINX_ALERTTB, 24);
									   cout << " Da sua ho sv ";
									   Sleep(1000);
									   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
									   gotoxy(X_XSV_COT2 + 2 + strlen(hoSV),y);
								   }
								  
							   }
							   else if (viTriChinhSua == 3)
							   {
								  
								   SetBGColor(green_Dark);
								   int kiTu = NhapChuoi(tenSV, constTENSV, X_XSV_COT3 + 2,y);

								   if (strcmp(tenSV, k->SV.getTEN()) == 0) {

									   break;
								   }
								   else {
								   
								   k -> SV.setTEN(tenSV);
								   gotoxy(MINX_ALERTTB, 24);
								   cout << " Da sua ten SV ";
								   Sleep(1000);
								   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
								   gotoxy(X_XSV_COT3 + 2 + strlen(tenSV), y);
								   }
							   }

							   else if (viTriChinhSua == 4)
							   {
								   do{

								   SetBGColor(green_Dark);
								   int kiTu = NhapChuoi(phai, constPHAI, X_XSV_COT4 + 2,y);
								   if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
								   {
										   char title[] = "THONG BAO";
										   char message[] = "Phai NAM/NU!";
										   char td[2][10] = { "Chinh sua", "    Huy" };
										   normal();
										   gotoxy(MINX_ALERTTB, MINY_ALERTTB);
										   int select = veKhungThongBao(title, message, td);
										   if (select == 0)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   continue;
										   }
										   else if (select == 1)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   
											   xoaNoiDungVe(X_XSV_COT4 + 1, y, 3, 0);
											   gotoxy(X_XSV_COT4+1 , y);
											   strcpy(phai, k->SV.getPHAI());
											   SetBGColor(green_Dark);
											   for (int i = 0; i < 4; i++) {
												   cout << " ";
											   }
											   gotoxy(X_XSV_COT4 + 2, y);
											   cout << phai;
											   break;
										   }
									   
								   }
								   else {
									 k->SV.setPHAI(phai);
									 gotoxy(MINX_ALERTTB, 24);
									 cout << " Da sua Phai ";
									 Sleep(1000);
									 xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
									 gotoxy(X_XSV_COT4 + 2 + strlen(phai), y);
									 break;
								   }
								   } while (true);
							   }
							   else if (viTriChinhSua ==5)
							   {
								   do{

									   SetBGColor(green_Dark);

									   int kiTu = NhapSo(sdt, constSDT, X_XSV_COT5 + 2,y);

									   if (strlen(sdt)<10)
									   {
										   char title[] = "THONG BAO";
										   char message[] = "SDT khong hop le!";
										   char td[2][10] = { "Chinh sua", "    Huy" };
										   normal();
										   gotoxy(MINX_ALERTTB, MINY_ALERTTB);
										   int select = veKhungThongBao(title, message, td);
										   if (select == 0)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   continue;
										   }
										   else if (select == 1)
										   {
											   xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											   
											   xoaNoiDungVe(X_XSV_COT5 + 1, y, 11, 0);
											   gotoxy(X_XSV_COT5 + 1, y);
											   strcpy(sdt, k->SV.getSDT());
											   SetBGColor(green_Dark);
											   cout << " " << sdt;
											   break;
										   }
										   
									   }
									   else {
										   k->SV.setSDT(sdt);
										   gotoxy(MINX_ALERTTB, 24);
										   cout << "Da sua sdt";
										   Sleep(1000);
										   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
										   gotoxy(X_XSV_COT5 + 2 + strlen(sdt),y);
										   break;
									   }
								   } while (true);
							   }
							   break;
					}
					case Left:
					{
								 int y = Y_FIST_SV + viTri - (trangHT - 1) * 10;
								 if (viTriChinhSua >1)
								 {
									 viTriChinhSua--;
									 if (viTriChinhSua == 1)
									 {
										 gotoxy(X_XSV_COT1 + strlen(maSV) + 2,y);
									 }
									 else if (viTriChinhSua == 2)
									 {
										 gotoxy(X_XSV_COT2 + strlen(hoSV) + 2,y);
									 }
									 else if (viTriChinhSua == 3)
									 {
										 gotoxy(X_XSV_COT3 + strlen(tenSV) + 2,y);
									 }
									 else if (viTriChinhSua == 4)
									 {
										 gotoxy(X_XSV_COT4 + strlen(phai) + 2,y);
									 }
								 }
								 break;
					}
					case Right:
					{
								  int y = Y_FIST_SV + viTri - (trangHT - 1) * 10;
								  if (viTriChinhSua <5)
								  {
									  viTriChinhSua++;
									  if (viTriChinhSua == 5)
									  {
										  gotoxy(X_XSV_COT5 + strlen(sdt) + 2, y);
									  }
									  else if (viTriChinhSua == 4)
									  {
										  gotoxy(X_XSV_COT4 + strlen(phai) + 2,y);
									  }
									  else if (viTriChinhSua == 3)
									  {
										  gotoxy(X_XSV_COT3 + strlen(tenSV) + 2, y);
									  }
									  else if (viTriChinhSua == 2)
									  {
										  gotoxy(X_XSV_COT2 + strlen(hoSV) + 2,y);
									  }
									 
								  }
								  break;
					}
						
					}

				} while (true);
				break;
			}

		} while (true);
	}
}

void LOP::timSinhVienNhapDiem(char MaMonHoc[], int lanThi, PTRDIEM_SV *& a, int & n)
{
	for (PTRNODESV p = First; p != NULL; p = p->next)
	{
		//Tìm lần thi lớn nhất đã có điểm ứng với môn hoc đó
		PTRNODEDIEM pNodeDiemThiSV = p->SV.timlanThiLonNhatCuaMH(MaMonHoc);
		//Không tìm được NODE nào
		if (pNodeDiemThiSV == NULL)
		{
			if (lanThi == 1)
			{
				pushBackPTRDIEM_SV(a, n, p, pNodeDiemThiSV);
			}
		}
		//Tìm được
		else
		{
			DIEM diemThi = pNodeDiemThiSV->diem;
			if (diemThi.getLanThi() == (lanThi - 1) && diemThi.getDiem() < 4)
			{
				pushBackPTRDIEM_SV(a, n, p, NULL);
			}
		}

	}
}

void LOP::pushBackPTRDIEM_SV(PTRDIEM_SV *& a, int & n, PTRNODESV pNodeSv, PTRNODEDIEM pNodeDiem)
{
	int m = n + 1;
	PTRDIEM_SV* anew = (PTRDIEM_SV*)realloc(a, m * sizeof(PTRDIEM_SV));
	if (anew != NULL)
	{
		anew[n] = new DIEM_SV;
		anew[n]->nodeSV = pNodeSv;
		anew[n]->diemSV = pNodeDiem;
		n++;
		a = anew;
	}
}

void LOP::ghiFile(ofstream &ofs)
{
		ofs.write(reinterpret_cast< const char *> (this), sizeof(LOP));
		ghiFileDSSV(ofs);
	
}

void LOP::docFile(ifstream &ifs)
{
	ifs.read(reinterpret_cast< char *> (this), sizeof(LOP));//lấy lớp
	docFileDSSV(ifs);
}

void LOP::ghiFileDSSV(ofstream &ofs)
{
	int sl = 0;
	if (First == NULL) {
		
		ofs.write(reinterpret_cast< const char *> (&sl), sizeof(int));
	}
	else {
		sl = demSVTrongLop();
		ofs.write(reinterpret_cast< const char *> (&sl), sizeof(int));
		for (PTRNODESV p = First; p != NULL; p = p->next)
		{
			SINHVIEN sv = p->SV;
			ofs.write(reinterpret_cast< const char *> (&sv), sizeof(SINHVIEN));
		}
	}
}

void LOP::docFileDSSV(ifstream &ifs)
{
	First = NULL;
	int dem = 0;//số sinh viên
	ifs.read(reinterpret_cast< char *> (&dem), sizeof(int));
	for(int i=0;i<dem;i++){
		SINHVIEN sv;
		ifs.read(reinterpret_cast< char *> (&sv), sizeof(SINHVIEN));
		insertLast(sv); 
	}		
}
	


LOP::~LOP()
{
}

void LOP::xoaSVtheoConTro(PTRNODESV p)
{
	if (First == p){
		
		First = p->next;
		delete p;
	}
	else{
		PTRNODESV q;
		for ( q = First; q->next != p; q = q->next){		}
		q->next = p->next;
		delete p;
	}
	
}

void LOP:: hienThiTTSV(PTRNODESV p){
	SINHVIEN SVIEN = p->SV;
	veKhungNhapTTSinhVien();
	// xuat thong tin sinh vien	
	gotoxy(MINX_BSV + 1, MINY_BSV + 4);
	cout << p->SV.getMASV();
	gotoxy(svCot1 + 2, MINY_BSV + 4);
	cout << p->SV.getHO();
	gotoxy(svCot2 + 2, MINY_BSV + 4);
	cout << p->SV.getTEN();
	gotoxy(svCot3 + 1, MINY_BSV + 4);
	cout << p->SV.getPHAI();
	gotoxy(svCot4 + 1, MINY_BSV + 4);
	cout << p->SV.getSDT();

}
int  LOP::demSVTrongLop() {
	int k = 0;
	for (PTRNODESV p = First; p != NULL; p = p->next) {
		k++;
	}
	return k;
}