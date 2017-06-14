#include "DSLOP.h"

DSLOP::DSLOP()
{
	SL = 0;
}

void DSLOP::nhapDSLOP()
{
	gotoxy(71, 2);
	setGreenText();
	cout << "NHAP DANH SACH LOP";
	for (int i = 0; i < 100; ++i)
	{
		char MLOP[constMALOP];
		char TENL[constTENLOP];
		int NH;
		//Lưu năm học dạng chuỗi
		char c_NH[5];
		/*Khỏi tạo tất cả các chuỗi ban đầu là rỗng*/
		MLOP[0] = '\0';
		TENL[0] = '\0';
		c_NH[0] = '\0';
		setNormallText();

		//Xoa thong tin lop vua nhap
		for (int i = 0; i < 70; ++i)
		{
			SetColor(0);
			gotoxy(MINX_BLOP + i, MINY_BLOP + 4);
			cout << " ";
		}

		setNormallText();
		veKhungNhapTTLop();

	NHAPTTLOP:
		//Nếu MLOP rỗng thì trả về 0 nếu lớp hợp lệ, -1 nếu chuỗi rỗng
		int checkMALOP = NhapChuoiVaChuSo(MLOP, constMALOP, MINX_BLOP + 2, MINY_BLOP + 4);
		if (checkMALOP == successfull)
		{
			//Kiểm tra lớp có tồn tại không, nếu không tồn tại trả về -1
			if (searchLOP(MLOP) == fail)
			{
			NHAPTENLOP: 
				//Nhập tên lớp, không cho phép rỗng
				int checkTENLOP = NhapChuoi(TENL, constTENLOP, xCot1 + 2, MINY_BLOP + 4);
				if (checkTENLOP == ESC)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ban co muon thoat?";
					char td[2][10] = { "    Co", "    Khong" };
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					int checkTHONGBAO = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon Thoat
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Nguoi dung chon tiep tuc
					else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
					{
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						goto NHAPTENLOP;
					} 
				}

				//Get năm hiện tại
				int namHienTai = getNamHienTai();
				//Nhập năm học
				NHAPNAMHOC:
					int checkNH = NhapSo(c_NH, 5, xCot2 + 3, MINY_BLOP + 4);
					if (checkNH == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int checkEXit = veKhungThongBao(title, message, td);
						setNormallText();
						if (checkEXit == 0)
						{
							normal();
							return;
						}
						else if (checkEXit == 1 || checkEXit == ESC)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							goto NHAPNAMHOC;
						}
					}
					NH = atoi(c_NH);
					/*
						năm học phải <= năm hiện tại và > 1900
						Nếu năm học lớn hơn năm hiện tại hiện bảng thông báo cho người dùng
						cho họ chọn sửa lại hoặc thoát khỏi chức năng

					*/

					if (NH > namHienTai || NH < 1900)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Nam hoc khong hop le!";
						char td[2][10] = { "Chinh sua", "    Thoat" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int checkNAMHOC = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon chinh sua noi dung bi trung
						if (checkNAMHOC == 0 || checkNAMHOC == ESC)
						{
							//Xóa bảng thông báo vừa in ra
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							goto NHAPNAMHOC;
						}
						else if (checkNAMHOC == 1)
						{
							return;
						}
					}

				DANHSACHLOP[SL].nhapLOP(MLOP, TENL, NH);
				SL++;
			}
			else
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ma lop ban nhap bi trung?";
				char td[2][10] = { "Chinh sua", "    Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check2 = veKhungThongBao(title, message, td);
				setNormallText();
				//Nguoi dung chon chinh sua noi dung bi trung
				if (check2 == 0 || check2 == ESC)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					//Quay lại cho người dung chỉnh sửa thông tin bị trùng
					goto NHAPTTLOP;
				}
				else if (check2 == 1)
				{
					break;
				}
			}
		}
		else if (checkMALOP == ESC || checkMALOP == -1)
		{
			char title[10] = "THONG BAO";
			char message[30] = "Ban co muon thoat?";
			char td[2][10] = { "    Co", "    Khong" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int check2 = veKhungThongBao(title, message, td);
			setNormallText();
			if (check2 == 0)
			{
				return;
			}
			else if (check2 == 1 || check2 == ESC)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPTTLOP;
			}

		}
	}
}

void DSLOP::inLOPTheoHang(LOP lop, int y, int stt)
{
	char MAL[constMALOP];
	char TENL[constTENLOP];
	lop.getMALOP(MAL);
	lop.getTENLOP(TENL);

	gotoxy(MINX_XLOP + 3, y);
	cout << stt;
	gotoxy(X_XLOP_COT1 + 2, y);
	cout << MAL;
	gotoxy(X_XLOP_COT2 + 3, y);
	cout << TENL;
	gotoxy(X_XLOP_COT3 + 2, y);
	cout << lop.getNH();
}

void DSLOP::pushBackChiSoDSLOP(int *& a, int & n, int i)
{
	int m = n + 1;
	int* aNew = (int*)realloc(a, m * sizeof(int));
	if (aNew != NULL)
	{
		aNew[n] = i;
		n++;
		a = aNew;
	}
}

void DSLOP::xuatDSLOPNK()
{
	int TSTrang;
	int trangHT = 1;
	// Luu nam hoc dạng chuỗi
	char c_NH[constNAMHOC];

	c_NH[0] = '\0';
	// Lưu  năm học dạng số
	int NH;

	gotoxy(72, 2);
	setGreenText();
	cout << "IN DANH SACH LOP";
	normal();
	char title[] = "THONG BAO";
	char message[] = "Nhap nam hoc de in danh sach";
	//Lấy năm hiện tại
	int namHT = getNamHienTai();
	bool flat = false;
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		int checkNH = veTextFieldNhapNamHoc(c_NH, title, message);
		//Người dùng bấm ESC khi đang nhập năm học
		if (checkNH == ESC)
		{
			return;
		}
		gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
		for (int i = 0; i < widthAlert - 4; ++i)
		{
			cout << " ";
		}
		//Chuyển chuỗi năm học sang dạng số
		NH = atoi(c_NH);

		if (NH > namHT)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << " Nam hoc khong hop le!";
			continue;
		}

		flat = false;
		//Duyệt qua danh sách lớp kiểm tra xem có lớp nào có năm học
		// trùng với năm người dùng nhập không
		for (int i = 0; i < SL; ++i)
		{
			if (NH == DANHSACHLOP[i].getNH())
			{
				flat = true;
				break;
			}
		}

		if (flat == false)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << " Khong tim duoc lop!";
		}
	} while (NH > namHT || flat == false);
	Sleep(100);

	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	gotoxy(73, 3);
	cout << "NAM HOC: " << c_NH;
	veKhungXuatLopTheoNK();

	//-----------------------------------THỰC HIỆN CHỨC NĂNG------------------------------------------

	//Luu tong so LOP thoa dieu kien
	int stt = 0;
	//Mảng chiSo dùng để lưu chỉ số các phan tu trong mang DANHSACHLOP có năm nhap hoc = nam do do nguoi dung nhap
	int *chiSo = NULL;
	for (int i = 0; i < SL; ++i)
	{
		if (NH == DANHSACHLOP[i].NAMHOC)
		{
			pushBackChiSoDSLOP(chiSo, stt, i);
			if (stt <= 10)
			{
				inLOPTheoHang(DANHSACHLOP[i], Y_FIST_LOP + stt - 1, stt);
			}
		}
	}

	//tinh tong so trang va in ra mang hinh
	if (stt % 10 == 0)
	{
		TSTrang = stt / 10;
	}
	else
	{
		TSTrang = stt / 10 + 1;
	}

	//Chỉ số trong mang chiSo của phần tử đầu tiên trang đang hiển thị
	int firstItem;

	//In trang hien tai / Tong so trang
	gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
	cout << "Trang: " << trangHT << " / " << TSTrang;

	//Cho biết nếu bấm F2 sẽ vào cột nào để chỉnh sửa (nếu nhấn F5 sẽ giảm 1, F6 sẽ tăng 1)
	int viTriChinhSua = 1;

	int kiTu;
	do {
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
		case PageUp:
		{
			if (trangHT > 1)
			{
				xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP, heightBANG_XLOP);
				trangHT--;
				gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;
				veKhungXuatLopTheoNK();
				firstItem = (trangHT - 1) * 10;
				for (int i = 0; i < 10; ++i)
				{
					int k = chiSo[firstItem++];
					inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, firstItem);
				}
			}
			break;
		}
		case PageDown:
		{
			if (trangHT < TSTrang)
			{
				xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
				trangHT++;
				gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
				cout << "Trang: " << trangHT << " / " << TSTrang;
				veKhungXuatLopTheoNK();
				firstItem = (trangHT - 1) * 10;
				for (int i = 0; i < 10; ++i)
				{
					if (firstItem < stt)
					{
						int k = chiSo[firstItem++];
						inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, firstItem);
					}
				}
			}
			break;
		}
		case Enter:
		{
			firstItem = (trangHT - 1) * 10;
			//K lưu giá trị trong mảng chiSo tại vị trí FirstItem
			int k = chiSo[firstItem];

			gotoxy(MINX_XLOP + 1, Y_FIST_LOP);
			SetBGColor(green_Dark);
			for (int i = 0; i < widthBANG_XLOP - 2; ++i)
			{
				cout << " ";
			}

			inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP, firstItem + 1);

			//Dua con tro ve cuoi MALOP tai vi tri dang chon
			gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, Y_FIST_LOP);

			int kiTu;
			//Vi tri dang hien thi
			int currentIndex = firstItem;
			do
			{
				k = chiSo[currentIndex];

				char ML[constMALOP];
				char TENL[constTENLOP];
				char namhoc[constNAMHOC];

				ML[0] = '\0';
				TENL[0] = '\0';
				namhoc[0] = '\0';

				DANHSACHLOP[k].getMALOP(ML);
				DANHSACHLOP[k].getTENLOP(TENL);
				itoa(DANHSACHLOP[k].NAMHOC, namhoc, 10);

				kiTu = 0;
				fflush(stdin);
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
					//currentIndex đang ở trong trang đang hiển thị và nhỏ hơn tổng số lớp
					if (currentIndex < (firstItem + 9) && currentIndex < stt - 1)
					{
						k = chiSo[currentIndex];
						viTriChinhSua = 1;
						// y lưu tọa độ y hiện tại
						int y = wherey();
						gotoxy(MINX_XLOP + 1, y);
						SetBGColor(black);
						for (int i = MINX_XLOP+1; i <= MAXX_XLOP ; ++i)
						{
							if (i == X_XLOP_COT1 || i == X_XLOP_COT2 || i == X_XLOP_COT3 || i == MAXX_XLOP) {
								cout << (char)179;
							}
							else
								cout << " ";
						}
						
						inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);

						//-------------------HIGHLIGHT DÒNG MỚI--------------------------------
						//k chứa chỉ số dòng mới
						k = chiSo[++currentIndex];
						
						SetBGColor(green_Dark);
						gotoxy(MINX_XLOP + 1, wherey() + 1);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						inLOPTheoHang(DANHSACHLOP[k], wherey(), currentIndex + 1);
						gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, wherey());
						break;
					}
					else if (trangHT < TSTrang)
					{
						xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
						trangHT++;
						gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;
						veKhungXuatLopTheoNK();
						firstItem = (trangHT - 1) * 10;
						currentIndex = firstItem;
						for (int i = 0; i < 10; ++i)
						{
							if (currentIndex < stt)
							{
								k = chiSo[currentIndex++];
								inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, currentIndex);
							}
						}

						//-----------HIGHLIGHT DÒNG ĐẦU TIÊN CỦA TRANG MỚI--------------
						currentIndex = firstItem;
						if (currentIndex < (firstItem + 9) && currentIndex < stt )
						{

							k = chiSo[currentIndex];
							gotoxy(MINX_XLOP + 1, Y_FIST_LOP);
							SetBGColor(green_Dark);
							for (int i = 0; i < widthBANG_XLOP - 2; ++i)
							{
								cout << " ";
							}
							inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP, currentIndex + 1);
						}
					}
					break;
				}
				case PageUp:
				{
					if (currentIndex > 0 && currentIndex > firstItem)
					{
						viTriChinhSua = 1;
						//sua noi dung tại dòng cũ
						int y = wherey();
						k = chiSo[currentIndex];
						gotoxy(MINX_XLOP + 1, y);
						SetBGColor(black);
						for (int i = MINX_XLOP + 1; i <= MAXX_XLOP; ++i)
						{
							if (i == X_XLOP_COT1 || i == X_XLOP_COT2 || i == X_XLOP_COT3 || i == MAXX_XLOP) {
								cout << (char)179;
							}
							else
								cout << " ";
						}
						inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);

						//Hight light dòng mới
						k = chiSo[--currentIndex];
						SetBGColor(green_Dark);
						gotoxy(MINX_XLOP + 1, wherey() - 1);
						for (int i = 0; i < widthBANG_XLOP - 2; ++i)
						{
							cout << " ";
						}
						inLOPTheoHang(DANHSACHLOP[k], wherey(), currentIndex + 1);
						gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, wherey());
					}
					else if (trangHT > 0 && currentIndex > 0)
					{
						viTriChinhSua = 1;
						xoaNoiDungVe(MINX_XLOP - 1, MINY_XLOP - 1, widthBANG_XLOP + 1, heightBANG_XLOP + 1);
						trangHT--;
						gotoxy(X_XLOP_COT3 - 10, MINY_XLOP - 1);
						cout << "Trang: " << trangHT << " / " << TSTrang;
						veKhungXuatLopTheoNK();
						firstItem = (trangHT - 1) * 10;
						currentIndex = firstItem;
						for (int i = 0; i < 10; ++i)
						{
							if (currentIndex < stt)
							{
								k = chiSo[currentIndex++];
								inLOPTheoHang(DANHSACHLOP[k], Y_FIST_LOP + i, currentIndex);
							}
						}
						currentIndex = firstItem + 9;
						if (currentIndex > 0)
						{
							int y = Y_FIST_LOP + 9;
							k = chiSo[currentIndex];
							gotoxy(MINX_XLOP + 1, y);
							SetBGColor(green_Dark);
							for (int i = 0; i < widthBANG_XLOP - 2; ++i)
							{
								cout << " ";
							}

							inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);
							gotoxy(X_XLOP_COT1 + strlen(DANHSACHLOP[k].MALOP) + 2, y);
						}
					}
					break;
				}
				case F2:
				{
					int y = Y_FIST_LOP + currentIndex - (trangHT - 1) * 10;
					if (viTriChinhSua == 1)
					{
						do
						{
							SetBGColor(green_Dark);
							int kiTu = NhapChuoiVaChuSo(ML, constMALOP, X_XLOP_COT1 + 2, y);
							//Chuỗi mã lớp trả về bị rỗng
							if (kiTu == -1)
							{

								char title[] = "THONG BAO";
								char message[] = "Ma lop khong duoc rong!";
								char td[2][10] = { "Chinh sua", "    Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								setNormallText();
								if (select == 0)
								{
									//Cho biet chuoi dang rong
									ML[0] = '\0';
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + currentIndex;
									k = chiSo[currentIndex];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);
									break;
								}


							}
							else if (searchLOP(ML) == -1 && kiTu == 0)
							{
								DANHSACHLOP[k].setMLOP(ML);
								break;
							}
							else if (strcmp(ML, DANHSACHLOP[k].MALOP) == 0)
							{
								break;
							}
							//Mã lớp bị trùng
							else if (searchLOP(ML) != -1 && kiTu == 0)
							{
								char title[] = "THONG BAO";
								char message[] = "Ma lop bi trung!";
								char td[2][10] = { "Chinh sua", "Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								setNormallText();
								if (select == 0)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + currentIndex;
									k = chiSo[currentIndex];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);
									break;
								}
							}
						} while (true);
					}
					else if (viTriChinhSua == 2)
					{
						SetBGColor(green_Dark);
						int kiTu = NhapChuoi(TENL, constTENLOP, X_XLOP_COT2 + 3, y);
						DANHSACHLOP[k].setTENL(TENL);
					}
					else if (viTriChinhSua == 3)
					{
						int NHOC;
						do
						{
							NhapSo(namhoc, constNAMHOC, X_XLOP_COT3 + 2, y);
							NHOC = atoi(namhoc);
							if (NHOC > namHT)
							{
								char title[] = "THONG BAO";
								char message[] = " Nam hoc khong hop le!";
								char td[2][10] = { "Chinh sua", "   Huy" };
								normal();
								gotoxy(MINX_ALERTTB, MINY_ALERTTB);
								int select = veKhungThongBao(title, message, td);
								setNormallText();
								if (select == 0)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									continue;
								}
								else if (select == 1)
								{
									xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
									int y = Y_FIST_LOP + currentIndex;
									k = chiSo[currentIndex];
									SetBGColor(green_Dark);
									gotoxy(MINX_XLOP + 1, y);
									for (int i = 0; i < widthBANG_XLOP - 2; ++i)
									{
										cout << " ";
									}
									inLOPTheoHang(DANHSACHLOP[k], y, currentIndex + 1);
									break;
								}
							}
						} while (NHOC >= namHT);
						DANHSACHLOP[k].setNH(NHOC);
					}
					break;
				}
				case Left:
				{
					if (viTriChinhSua >= 2)
					{
						viTriChinhSua--;
						if (viTriChinhSua == 1)
						{
							gotoxy(X_XLOP_COT1 + strlen(ML) + 2, wherey());
						}
						else if (viTriChinhSua == 2)
						{
							gotoxy(X_XLOP_COT2 + strlen(TENL) + 3, wherey());
						}
					}
					break;
				}
				case Right:
				{
					if (viTriChinhSua <= 2)
					{
						viTriChinhSua++;
						if (viTriChinhSua == 3)
						{
							gotoxy(X_XLOP_COT3 + strlen(namhoc) + 2, wherey());
						}
						else if (viTriChinhSua == 2)
						{
							gotoxy(X_XLOP_COT2+ strlen(TENL) + 3, wherey());
						}
					}
					break;
				}
				case ESC:
				{
					return;
				}
				}
			} while (true);
			normal();
			break;
		}
		case ESC:
		{
			return;
		}
		}
	} while (true);
}

void DSLOP::chinhSuaTTLOP()
{
	int x;
	char TENL[constTENLOP];
	char c_NH[constNAMHOC];
	int NAMHOC;
	char MLOP[constMALOP];
	MLOP[0] = '\0';
	gotoxy(72, 2);
	setGreenText();
	cout << "SUA THONG TIN LOP";
	normal();
	char title[] = "THONG BAO";
	char message[] = "  Nhap ma lop can chinh sua";
	do
	{
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		int kiTu = veTextFieldNhapKituSo(MLOP, constMALOP, title, message);
		if (kiTu == ESC)
		{
			return;
		}
		gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
		for (int i = 0; i < widthAlert - 4; ++i)
		{
			cout << " ";
		}
		x = searchLOP(MLOP);
		if (x == -1)
		{
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			SetColor(red_hightlight);
			cout << "  Ma lop khong hop le!";
			continue;
		}
		else
		{
			break;
		}
	} while (true);

	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	DANHSACHLOP[x].getTENLOP(TENL);
	NAMHOC = DANHSACHLOP[x].getNH();
	itoa(NAMHOC, c_NH, 10);

	veKhungNhapTTLop();
	
	gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
	cout << MLOP;
	gotoxy(xCot1 + 2, MINY_BLOP + 4);
	cout << TENL;
	gotoxy(xCot2 + 3, MINY_BLOP + 4);
	cout << NAMHOC;

	int viTri = 1;
	gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);

	int kiTu;
	do
	{
		DANHSACHLOP[x].getMALOP(MLOP);
		DANHSACHLOP[x].getTENLOP(TENL);
		NAMHOC = DANHSACHLOP[x].getNH();
		itoa(NAMHOC, c_NH, 10);

		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == 0 || temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}

		if (kiTu == ESC)
		{
			return;
		}
		else if (kiTu == Right)
		{
			if (viTri == 1)
			{
				viTri++;
				gotoxy(xCot1 + strlen(TENL) + 2, MINY_BLOP + 4);
			}
			else if (viTri == 2)
			{
				viTri++;
				gotoxy(xCot2 + 7, MINY_BLOP + 4);
			}
		}
		else if (kiTu == Left)
		{
			if (viTri == 3)
			{
				viTri--;
				gotoxy(xCot1 + strlen(TENL) + 2, MINY_BLOP + 4);
			}
			else if (viTri == 2)
			{
				viTri--;
				gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);
			}
		}
		else if (kiTu == F2)
		{
			if (viTri == 1)
			{
				do
				{
					int check = NhapChuoiVaChuSo(MLOP, constMALOP, MINX_BLOP + 2, MINY_BLOP + 4);
					if (check == -1)
					{

						char title[] = "THONG BAO";
						char message[] = "Ma lop khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						setNormallText();
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							MLOP[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							veKhungNhapTTLop();

							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;
							break;
						}
					}
					else if (check == ESC)
					{
						xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
						veKhungNhapTTLop();

						DANHSACHLOP[x].getMALOP(MLOP);
						gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
						cout << MLOP;
						gotoxy(xCot1 + 2, MINY_BLOP + 4);
						cout << TENL;
						gotoxy(xCot2 + 3, MINY_BLOP + 4);
						cout << NAMHOC;

						gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);

						break;
					}
					else if (searchLOP(MLOP) == -1 && check == 0)
					{
						DANHSACHLOP[x].setMLOP(MLOP);
						break;
					}
					else if (strcmp(MLOP, DANHSACHLOP[x].MALOP) == 0)
					{
						break;
					}
					//Mã lớp bị trùng
					else if (searchLOP(MLOP) != -1 && check == 0)
					{
						char title[] = "THONG BAO";
						char message[] = "Ma lop bi trung!";
						char td[2][10] = { "Chinh sua", "Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						setNormallText();
						if (select == 0)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							
							xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
							veKhungNhapTTLop();

							DANHSACHLOP[x].getMALOP(MLOP);

							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;

							gotoxy(MINX_BLOP + strlen(MLOP) + 2, MINY_BLOP + 4);
						}
					}
				} while (true);
				
			}
			else if (viTri == 2)
			{
				do
				{
					int check = NhapChuoi(TENL, constTENLOP, xCot1 + 2, MINY_BLOP + 4);
					if (check == ESC)
					{
						
						TENL[0] = '\0';
						DANHSACHLOP[x].getTENLOP(TENL);
						gotoxy(xCot1 + 2, MINY_BLOP + 4);
						cout << TENL;
						continue;
					}
					else
					{
						DANHSACHLOP[x].setTENL(TENL);
						break;
					}
				} while (true);
			}
			else if (viTri == 3)
			{
				do
				{
					int check = NhapSo(c_NH, constNAMHOC, xCot2 + 3, MINY_BLOP + 4);
					NAMHOC = atoi(c_NH);
					int namHT = getNamHienTai();

					if (strlen(c_NH) < 4)
					{
						
						continue;
					}
					else if (NAMHOC > namHT)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Nam hoc khong hop le!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						gotoxy(MINX_ALERTTB, MINY_ALERTNL);
						int check2 = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon chinh sua noi dung bi trung
						if (check2 == 0)
						{
							//Xóa bảng thông báo vừa in ra
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							continue;
						}
						else if (check2 == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
							
							xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
							veKhungNhapTTLop();

							NAMHOC = DANHSACHLOP[x].getNH();
							gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
							cout << MLOP;
							gotoxy(xCot1 + 2, MINY_BLOP + 4);
							cout << TENL;
							gotoxy(xCot2 + 3, MINY_BLOP + 4);
							cout << NAMHOC;

							gotoxy(xCot2 + 7, MINY_BLOP + 4);

							break;
						}
					}
					else
					{
						break;
					}
				} while (true);
			}
		}
	} while (true);


}

void DSLOP::xoaLOP()
{
	int x;
	char TENL[constTENLOP];
	char c_NH[constNAMHOC];
	int NAMHOC;
	char MLOP[constMALOP];

	gotoxy(77, 2);
	setGreenText();
	cout << "XOA LOP";
	normal();
	do
	{
		MLOP[0] = '\0';
		char title[] = "THONG BAO";
		char message[] = "     Nhap ma lop can xoa  ";
		do
		{
			gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
			int kiTu = veTextFieldNhapKituSo(MLOP, constMALOP, title, message);
			if (kiTu == ESC)
			{
				return;
			}
			gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
			for (int i = 0; i < widthAlert - 4; ++i)
			{
				cout << " ";
			}
			x = searchLOP(MLOP);
			if (x == -1)
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "  Ma lop khong hop le!";
				continue;
			}
			else
			{
				break;
			}
		} while (true);

		xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

		DANHSACHLOP[x].getTENLOP(TENL);
		NAMHOC = DANHSACHLOP[x].getNH();
		itoa(NAMHOC, c_NH, 10);

		veKhungNhapTTLop();

		gotoxy(MINX_BLOP + 2, MINY_BLOP + 4);
		cout << MLOP;
		gotoxy(xCot1 + 2, MINY_BLOP + 4);
		cout << TENL;
		gotoxy(xCot2 + 3, MINY_BLOP + 4);
		cout << NAMHOC;

		char message1[] = "Ban co chac chan xoa lop?";
		char td[2][10] = { "  Co", "   Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int select = veKhungThongBao(title, message1, td);
		setNormallText();
		if (select == 0)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			if (DANHSACHLOP[x].First != NULL)
			{
				char title[] = "THONG BAO";
				char message[] = "    Lop khong the xoa!";
				char td[2][10] = { "Nhap lai", "  Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int select = veKhungThongBao(title, message, td);
				setNormallText();
				if (select == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					xoaNoiDungVe(MINX_BLOP, MINY_BLOP, 70, 10);
				}
				else
				{
					return;
				}
			}
			else
			{
				xoaPhanTu(DANHSACHLOP, SL, x);
				char title[] = "THONG BAO";
				char message[] = "    Xoa thanh cong";
				char td[2][10] = { "Tiep tuc", "  Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int select = veKhungThongBao(title, message, td);
				setNormallText();
				if (select == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					xoaNoiDungVe(MINX_BLOP, MINY_BLOP, 70, 10);
				}
				else
				{
					return;
				}
			}
		}
		else
		{
			return;
		}
		
	} while (true);
}

void DSLOP::nhapDSSVLOP()
{
	char labelTb[20] = "NHAP SINH VIEN LOP";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap Ma Lop de them sinh vien";
	char maLop[constMALOP];
	// i lưu chỉ số lớp khi sreach trả về
	int i = -1;
	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, 9);

		switch (veTextFieldNhapKituSo(maLop, constMALOP, title, message))
		{
		case ESC:
			return;
		
		//hàm vẽ textfield return 0 đã nhận được kết quả
		case 0:
			i = searchLOP(maLop);
			//Tại sao malopp[0] != '\0' khi veTextField trả về không đã nhận được mã lớp rồi
			//=> kiểm tra lại
			
			if (i == -1)
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Ma lop khong ton tai ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 4, MINY_ALERTNL + 3, 25, 1);
			}
			break;
		default:
			break;
		}
		
	} while (i == -1);
	Sleep(100);
	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	DANHSACHLOP[i].createDSSV();
}

void DSLOP::xuatDSSVLOP()
{
	char labelTb[20] = "NHAP SINH VIEN LOP";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap Ma Lop xem sinh vien";
	char maLop[constMALOP];
	//i la vi tri cua lop trong dsLop
	int i = -1;

	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		switch (veTextFieldNhapKituSo(maLop, constMALOP, title, message)) 
		{
		case ESC:
			return;
			break;
		case 0:
			if (maLop[0] == '/0'){

			}
			else{
				i = searchLOP(maLop);
				if (i == -1 )
				{
					gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
					SetColor(red_hightlight);
					cout << "Ma lop khong ton tai";

				} 
			}
			
			break;
		default:
			break;
		}
		
	} while (i == -1);
	Sleep(100);
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);
	DANHSACHLOP[i].xuatDSSV();
	return;
}

int DSLOP::searchLOP(char MLOP[])
{
	for (int i = 0; i < SL; ++i)
	{
		if (strcmp(MLOP, DANHSACHLOP[i].MALOP) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DSLOP::nhapDiemLOP(DSMONHOC root)
{
	char MaLop[constMALOP];
	char MaMonHoc[constMAMON];
	char c_LanThi[constLanThi];
	int lanthi;

	MaLop[0] = '\0';
	MaMonHoc[0] = '\0';
	c_LanThi[0] = '\0';

	// tiêu đề bảng
	gotoxy(MINX_BNMH1 + 12, MINY_BNMH1 - 2);
	SetColor(green);
	cout << "NHAP DIEM CHO LOP";
	setNormallText();

	//vẽ bảng nhập gồm MALOP,MAMH, LAN
	veKhungNhapDiemChoLop();

	/*NHAP MLop tại (XCOT1_BNMH1 +2,MINY_BNMH1+2)
	MMON tại (XCOT1_BNMH1 +2,YDONG1_BNMH1+2)
	LAN thi tại (XCOT1_BNMH1 +2,YDONG2_BNMH1+2
	*/

NHAPMALOP:
	int checkMALOP = NhapChuoiVaChuSo(MaLop, constMALOP, XCOT1_BNMH1 + 2, MINY_BNMH1 + 2);
	if (checkMALOP == fail || checkMALOP == ESC)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Ban co muon thoat?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		setNormallText();
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
			goto NHAPMALOP;
		}
	}
	else if (checkMALOP == successfull)
	{
		//KIểm tra mã lớp có tồn tại hay không
		int checkLop = searchLOP(MaLop);

		//Mã lớp = -1 không tồn tại lớp
		if (checkLop == -1) {
			char title[10] = "THONG BAO";
			char message[30] = "Ma lop khong ton tai";
			char td[2][10] = { "   Thoat", "Tiep tuc" };
			gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			setNormallText();
			//Nguoi dung chon Thoat
			if (checkTHONGBAO == 0)
			{
				return;
			}
			//Nguoi dung chon tiep tuc
			else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
			{
				xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
				goto NHAPMALOP;
			}
		} 
		//Mã lớp tồn tại
		else
		{
		NHAPMAMONHOC:
			int checkMAMONHOC = NhapChuoiVaChuSo(MaMonHoc, constMAMON, XCOT1_BNMH1 + 2, YDONG1_BNMH1 + 2);
			//Nhập mã môn học không thành công hoặc người dùng chọn thoát
			if (checkMAMONHOC == fail || checkMAMONHOC == ESC)
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ban co muon thoat?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
				int checkTHONGBAO = veKhungThongBao(title, message, td);
				setNormallText();
				//Nguoi dung chon Thoat
				if (checkTHONGBAO == 0)
				{
					return;
				}
				//Nguoi dung chon tiep tuc
				else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
				{
					xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
					goto NHAPMAMONHOC;
				}
			}
			//Nhập mã môn học thành công
			else
			{
				PTRNODEMH p_CheckMonHoc = root.kiemTraMH(MaMonHoc);
				//Môn học không tồn tại
				if (p_CheckMonHoc == NULL)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ma Mon hoc khong ton tai";
					char td[2][10] = { "   Thoat", "Chinh sua" };
					gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
					int checkTHONGBAO = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon Thoat
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Nguoi dung chon tiep tuc
					else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
					{
						xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
						goto NHAPMAMONHOC;
					}
				}
				//MÔn học có tồn tại
				else
				{
				NHAPLANTHI:
					int checkLanThi = NhapSo(c_LanThi, constLanThi, XCOT1_BNMH1 + 2, YDONG2_BNMH1 + 2);
					
					//Nguời dùng chọn bấm ESC để thoát
					if (checkLanThi == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
						int checkTHONGBAO = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon Thoat
						if (checkTHONGBAO == 0)
						{
							return;
						}
						//Nguoi dung chon tiep tuc
						else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
						{
							xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
							goto NHAPLANTHI;
						}
					}
					//Người dùng chọn tiếp tục
					else
					{
						lanthi = atoi(c_LanThi);

						//Giới hạn lần thi > 0 và <= 10
						if (lanthi <= 0 || lanthi > 10)
						{
							char title[10] = "THONG BAO";
							char message[30] = "Lan thi khong hop le";
							char td[2][10] = { "   Thoat", "Chinh sua" };
							gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
							int checkTHONGBAO = veKhungThongBao(title, message, td);
							setNormallText();
							//Nguoi dung chon Thoat
							if (checkTHONGBAO == 0)
							{
								return;
							}
							//Nguoi dung chon tiep tuc
							else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
							{
								xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
								goto NHAPLANTHI;
							}
						}
						//Nhập Mã lớp, Mã môn học và lần thi thành công
						else
						{
							//Gọi hàm nhập điểm trong lớp
							int checkNhapDiem = DANHSACHLOP[checkLop].nhapDiem(MaMonHoc, lanthi);
							if (checkNhapDiem == fail)
							{
								char title[10] = "THONG BAO";
								char message[30] = "Khong tim duoc sinh vien";
								char td[2][10] = { "   Thoat", "Nhap lai" };
								gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
								int checkTHONGBAO = veKhungThongBao(title, message, td);
								setNormallText();
								//Nguoi dung chon Thoat
								if (checkTHONGBAO == 0)
								{
									return;
								}
								//Nguoi dung chon tiep tuc
								else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
								{
									xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
									goto NHAPMALOP;
								}
							}
						}
					}
				}
			}
		}
	}
}

bool DSLOP::inBangDiemTheoLanThi(DSMONHOC ds, char MLOP[], char MAMH[], int lanThi)
{
	return false;
}

void DSLOP::inDiemTrungBinh(DSMONHOC root)
{
	SetColor(green);
	char labelTitle[50] = "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
	gotoxy(62, 2);
	cout << labelTitle;

	char title[] = "THONG BAO";
	char message[] = "Nhap Ma Lop de in diem TB";
	char maLop[constMALOP];

	NHAPMALOP:
	// i lưu chỉ số lớp khi sreach trả về
	int i = -1;
	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, 9);

		int checkMALOP = veTextFieldNhapKituSo(maLop, constMALOP, title, message);

		switch (checkMALOP)
		{
		case ESC:
			return;

			//hàm vẽ textfield return 0 đã nhận được kết quả
		case 0:
			i = searchLOP(maLop);
			//Tại sao malopp[0] != '\0' khi veTextField trả về không đã nhận được mã lớp rồi
			//=> kiểm tra lại

			if (i == -1)
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Ma lop khong ton tai ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 4, MINY_ALERTNL + 3, 25, 1);
			}
			break;
		default:
			break;
		}

	} while (i == -1);
	Sleep(100);
	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	int checkInDiemTB = DANHSACHLOP[i].inDiemTBLOP(root);
	
	if (checkInDiemTB == fail)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Khong tim duoc sinh vien";
		char td[2][10] = { "    Thoat", "Tiep tuc" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			goto NHAPMALOP;
		}
	}
}

void DSLOP::inDiemTongKet()
{
	SetColor(green);
	char labelTitle[50] = "BANG TONG KET KHOA HOC";
	gotoxy(70, 2);
	cout << labelTitle;

	char title[] = "THONG BAO";
	char message[] = " Nhap MALOP in diem tong ket";
	char maLop[constMALOP];
	NHAPMALOP:
	// i lưu chỉ số lớp khi sreach trả về
	int i = -1;
	maLop[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, 9);

		int checkMALOP = veTextFieldNhapKituSo(maLop, constMALOP, title, message);

		switch (checkMALOP)
		{
		case ESC:
			return;

			//hàm vẽ textfield return 0 đã nhận được kết quả
		case 0:
			i = searchLOP(maLop);
			//Tại sao malopp[0] != '\0' khi veTextField trả về không đã nhận được mã lớp rồi
			//=> kiểm tra lại

			if (i == -1)
			{
				gotoxy(MINX_ALERTTB + 4, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Ma lop khong ton tai ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 4, MINY_ALERTNL + 3, 25, 1);
			}
			break;
		default:
			break;
		}

	} while (i == -1);
	Sleep(100);
	//Xóa TextField
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

	int checkInDiemTK = DANHSACHLOP[i].inDiemTongketLOP();

	if (checkInDiemTK == fail)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Khong tim duoc sinh vien";
		char td[2][10] = { "    Thoat", "Tiep tuc" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			goto NHAPMALOP;
		}
	}
}

void DSLOP::xuatDIEMTheoMon(DSMONHOC root)
{
	char MaLop[constMALOP];
	char MaMonHoc[constMAMON];
	char c_LanThi[constLanThi];
	int lanthi;

	MaLop[0] = '\0';
	MaMonHoc[0] = '\0';
	c_LanThi[0] = '\0';

	// tiêu đề bảng
	gotoxy(MINX_BNMH1 + 12, MINY_BNMH1 - 2);
	SetColor(green);
	cout << "NHAP DIEM CHO LOP";
	setNormallText();

	//vẽ bảng nhập gồm MALOP,MAMH, LAN
	veKhungNhapDiemChoLop();

	/*NHAP MLop tại (XCOT1_BNMH1 +2,MINY_BNMH1+2)
	MMON tại (XCOT1_BNMH1 +2,YDONG1_BNMH1+2)
	LAN thi tại (XCOT1_BNMH1 +2,YDONG2_BNMH1+2
	*/

NHAPMALOP:
	int checkMALOP = NhapChuoiVaChuSo(MaLop, constMALOP, XCOT1_BNMH1 + 2, MINY_BNMH1 + 2);
	if (checkMALOP == fail || checkMALOP == ESC)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Ban co muon thoat?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		setNormallText();
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
			goto NHAPMALOP;
		}
	}
	else if (checkMALOP == successfull)
	{
		//KIểm tra mã lớp có tồn tại hay không
		int checkLop = searchLOP(MaLop);

		//Mã lớp = -1 không tồn tại lớp
		if (checkLop == -1) {
			char title[10] = "THONG BAO";
			char message[30] = "Ma lop khong ton tai";
			char td[2][10] = { "   Thoat", "Tiep tuc" };
			gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			setNormallText();
			//Nguoi dung chon Thoat
			if (checkTHONGBAO == 0)
			{
				return;
			}
			//Nguoi dung chon tiep tuc
			else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
			{
				xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
				goto NHAPMALOP;
			}
		}
		//Mã lớp tồn tại
		else
		{
		NHAPMAMONHOC:
			int checkMAMONHOC = NhapChuoiVaChuSo(MaMonHoc, constMAMON, XCOT1_BNMH1 + 2, YDONG1_BNMH1 + 2);
			//Nhập mã môn học không thành công hoặc người dùng chọn thoát
			if (checkMAMONHOC == fail || checkMAMONHOC == ESC)
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ban co muon thoat?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
				int checkTHONGBAO = veKhungThongBao(title, message, td);
				setNormallText();
				//Nguoi dung chon Thoat
				if (checkTHONGBAO == 0)
				{
					return;
				}
				//Nguoi dung chon tiep tuc
				else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
				{
					xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
					goto NHAPMAMONHOC;
				}
			}
			//Nhập mã môn học thành công
			else
			{
				PTRNODEMH p_CheckMonHoc = root.kiemTraMH(MaMonHoc);
				//Môn học không tồn tại
				if (p_CheckMonHoc == NULL)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ma Mon hoc khong ton tai";
					char td[2][10] = { "   Thoat", "Chinh sua" };
					gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
					int checkTHONGBAO = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon Thoat
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Nguoi dung chon tiep tuc
					else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
					{
						xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
						goto NHAPMAMONHOC;
					}
				}
				//MÔn học có tồn tại
				else
				{
				NHAPLANTHI:
					int checkLanThi = NhapSo(c_LanThi, constLanThi, XCOT1_BNMH1 + 2, YDONG2_BNMH1 + 2);

					//Nguời dùng chọn bấm ESC để thoát
					if (checkLanThi == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
						int checkTHONGBAO = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon Thoat
						if (checkTHONGBAO == 0)
						{
							return;
						}
						//Nguoi dung chon tiep tuc
						else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
						{
							xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
							goto NHAPLANTHI;
						}
					}
					//Người dùng chọn tiếp tục
					else
					{
						lanthi = atoi(c_LanThi);

						//Giới hạn lần thi > 0 và <= 10
						if (lanthi <= 0 || lanthi > 10)
						{
							char title[10] = "THONG BAO";
							char message[30] = "Lan thi khong hop le";
							char td[2][10] = { "   Thoat", "Chinh sua" };
							gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
							int checkTHONGBAO = veKhungThongBao(title, message, td);
							setNormallText();
							//Nguoi dung chon Thoat
							if (checkTHONGBAO == 0)
							{
								return;
							}
							//Nguoi dung chon tiep tuc
							else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
							{
								xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
								goto NHAPLANTHI;
							}
						}
						//Nhập Mã lớp, Mã môn học và lần thi thành công
						else
						{
							//Gọi xuat điểm trong lớp
							int checkNhapDiem = DANHSACHLOP[checkLop].inDiemTheoMON(MaMonHoc, lanthi);
							if (checkNhapDiem == fail)
							{
								char title[10] = "THONG BAO";
								char message[30] = "Khong tim duoc sinh vien";
								char td[2][10] = { "   Thoat", "Nhap lai" };
								gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
								int checkTHONGBAO = veKhungThongBao(title, message, td);
								setNormallText();
								//Nguoi dung chon Thoat
								if (checkTHONGBAO == 0)
								{
									return;
								}
								//Nguoi dung chon tiep tuc
								else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
								{
									xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
									goto NHAPMALOP;
								}
							}
						}
					}
				}
			}
		}
	}
}

void DSLOP::suaDIEMSVTheoMon(DSMONHOC root)
{
	// tiêu đề bảng
	gotoxy(MINX_BNMH1 + 12, MINY_BNMH1 - 2);
	SetColor(green);
	cout << "SUA DIEM CUA SINH VIEN";
	setNormallText();

	veKhungSuaDiemChoSV();

	char MaSV[constMASV];
	char MaMonHoc[constMAMON];
	char c_LanThi[constLanThi];
	int lanthi;

	MaSV[0] = '\0';
	MaMonHoc[0] = '\0';
	c_LanThi[0] = '\0';

NHAPMASV:
	int checkMASV = NhapChuoiVaChuSo(MaSV, constMASV, XCOT1_BNMH1 + 2, MINY_BNMH1 + 2);
	if (checkMASV == fail || checkMASV == ESC)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Ban co muon thoat?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		setNormallText();
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
			goto NHAPMASV;
		}
	}
	else if (checkMASV == successfull)
	{
		int k = -1;//lưu stt lớp
		//KIểm tra mã SV có tồn tại hay không
		//sv chứa địa chỉ sinh viên có MASV=maSV
		PTRNODESV sv = searchAllSV(MaSV, k);
		if (sv == NULL) {
			char title[10] = "THONG BAO";
			char message[30] = "Ma SV khong ton tai";
			char td[2][10] = { "   Thoat", "Tiep tuc" };
			gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			setNormallText();
			//Nguoi dung chon Thoat
			if (checkTHONGBAO == 0)
			{
				return;
			}
			//Nguoi dung chon tiep tuc
			else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
			{
				xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
				goto NHAPMASV;
			}
		}
		//tìm đc sinh viên
		else
		{
		NHAPMAMONHOC:
			int checkMAMONHOC = NhapChuoiVaChuSo(MaMonHoc, constMAMON, XCOT1_BNMH1 + 2, YDONG1_BNMH1 + 2);
			//Nhập mã môn học không thành công hoặc người dùng chọn thoát
			if (checkMAMONHOC == fail || checkMAMONHOC == ESC)
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ban co muon thoat?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
				int checkTHONGBAO = veKhungThongBao(title, message, td);
				setNormallText();
				//Nguoi dung chon Thoat
				if (checkTHONGBAO == 0)
				{
					return;
				}
				//Nguoi dung chon tiep tuc
				else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
				{
					xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
					goto NHAPMAMONHOC;
				}
			}
			//Nhập mã môn học thành công
			else
			{
				PTRNODEMH p_CheckMonHoc = root.kiemTraMH(MaMonHoc);
				//Môn học không tồn tại
				if (p_CheckMonHoc == NULL)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ma Mon hoc khong ton tai";
					char td[2][10] = { "   Thoat", "Chinh sua" };
					gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
					int checkTHONGBAO = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon Thoat
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Nguoi dung chon tiep tuc
					else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
					{
						xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
						goto NHAPMAMONHOC;
					}
				}
				//MÔn học có tồn tại
				else
				{
				NHAPLANTHI:
					int checkLanThi = NhapSo(c_LanThi, constLanThi, XCOT1_BNMH1 + 2, YDONG2_BNMH1 + 2);

					//Nguời dùng chọn bấm ESC để thoát
					if (checkLanThi == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
						int checkTHONGBAO = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon Thoat
						if (checkTHONGBAO == 0)
						{
							return;
						}
						//Nguoi dung chon tiep tuc
						else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
						{
							xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
							goto NHAPLANTHI;
						}
					}
					//Người dùng chọn tiếp tục
					else
					{
						lanthi = atoi(c_LanThi);

						//Giới hạn lần thi > 0 và <= 10
						if (lanthi <= 0 || lanthi > 10)
						{
							char title[10] = "THONG BAO";
							char message[30] = "Lan thi khong hop le";
							char td[2][10] = { "   Thoat", "Chinh sua" };
							gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
							int checkTHONGBAO = veKhungThongBao(title, message, td);
							setNormallText();
							//Nguoi dung chon Thoat
							if (checkTHONGBAO == 0)
							{
								return;
							}
							//Nguoi dung chon tiep tuc
							else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
							{
								xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
								goto NHAPLANTHI;
							}
						}
						//Nhập Mã lớp, Mã môn học và lần thi thành công
						else
						{
							//Gọi hàm nhập điểm trong lớp
							
							int checkSuaDiem = sv->SV.suaDiem(MaMonHoc, lanthi);
							if (checkSuaDiem == fail)
							{
								char title[10] = "THONG BAO";
								char message[30] = "Khong tim duoc thong tin";
								char td[2][10] = { "   Thoat", "Nhap lai" };
								gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
								int checkTHONGBAO = veKhungThongBao(title, message, td);
								setNormallText();

								//Nguoi dung chon Thoat
								if (checkTHONGBAO == 0)
								{
									return;
								}
								//Nguoi dung chon tiep tuc
								else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
								{
									xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
									goto NHAPMASV;
								}
							}
						}
					}
				}
			}
		}
	}
}

void DSLOP::xoaDIEMSVTheoMon(DSMONHOC root)
{
NHAPTT:
	// tiêu đề bảng
	gotoxy(MINX_BNMH1 + 12, MINY_BNMH1 - 2);
	SetColor(green);
	cout << "XOA DIEM CUA SINH VIEN";
	setNormallText();

	veKhungSuaDiemChoSV();

	char MaSV[constMASV];
	char MaMonHoc[constMAMON];
	char c_LanThi[constLanThi];
	int lanthi;

	MaSV[0] = '\0';
	MaMonHoc[0] = '\0';
	c_LanThi[0] = '\0';

NHAPMASV:
	int checkMASV = NhapChuoiVaChuSo(MaSV, constMASV, XCOT1_BNMH1 + 2, MINY_BNMH1 + 2);
	if (checkMASV == fail || checkMASV == ESC)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Ban co muon thoat?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
		int checkTHONGBAO = veKhungThongBao(title, message, td);
		setNormallText();
		//Nguoi dung chon Thoat
		if (checkTHONGBAO == 0)
		{
			return;
		}
		//Nguoi dung chon tiep tuc
		else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
		{
			xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
			goto NHAPMASV;
		}
	}
	else if (checkMASV == successfull)
	{
		int k = -1;//lưu stt lớp
				   //KIểm tra mã SV có tồn tại hay không
				   //sv chứa địa chỉ sinh viên có MASV=maSV
		PTRNODESV sv = searchAllSV(MaSV, k);
		if (sv == NULL) {
			char title[10] = "THONG BAO";
			char message[30] = "Ma SV khong ton tai";
			char td[2][10] = { "   Thoat", "Tiep tuc" };
			gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			setNormallText();
			//Nguoi dung chon Thoat
			if (checkTHONGBAO == 0)
			{
				return;
			}
			//Nguoi dung chon tiep tuc
			else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
			{
				xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
				goto NHAPMASV;
			}
		}
		//tìm đc sinh viên
		else
		{
		NHAPMAMONHOC:
			int checkMAMONHOC = NhapChuoiVaChuSo(MaMonHoc, constMAMON, XCOT1_BNMH1 + 2, YDONG1_BNMH1 + 2);
			//Nhập mã môn học không thành công hoặc người dùng chọn thoát
			if (checkMAMONHOC == fail || checkMAMONHOC == ESC)
			{
				char title[10] = "THONG BAO";
				char message[30] = "Ban co muon thoat?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
				int checkTHONGBAO = veKhungThongBao(title, message, td);
				setNormallText();
				//Nguoi dung chon Thoat
				if (checkTHONGBAO == 0)
				{
					return;
				}
				//Nguoi dung chon tiep tuc
				else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
				{
					xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
					goto NHAPMAMONHOC;
				}
			}
			//Nhập mã môn học thành công
			else
			{
				PTRNODEMH p_CheckMonHoc = root.kiemTraMH(MaMonHoc);
				//Môn học không tồn tại
				if (p_CheckMonHoc == NULL)
				{
					char title[10] = "THONG BAO";
					char message[30] = "Ma Mon hoc khong ton tai";
					char td[2][10] = { "   Thoat", "Chinh sua" };
					gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
					int checkTHONGBAO = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon Thoat
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Nguoi dung chon tiep tuc
					else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
					{
						xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
						goto NHAPMAMONHOC;
					}
				}
				//MÔn học có tồn tại
				else
				{
				NHAPLANTHI:
					int checkLanThi = NhapSo(c_LanThi, constLanThi, XCOT1_BNMH1 + 2, YDONG2_BNMH1 + 2);

					//Nguời dùng chọn bấm ESC để thoát
					if (checkLanThi == ESC)
					{
						char title[10] = "THONG BAO";
						char message[30] = "Ban co muon thoat?";
						char td[2][10] = { "    Co", "    Khong" };
						gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
						int checkTHONGBAO = veKhungThongBao(title, message, td);
						setNormallText();
						//Nguoi dung chon Thoat
						if (checkTHONGBAO == 0)
						{
							return;
						}
						//Nguoi dung chon tiep tuc
						else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
						{
							xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
							goto NHAPLANTHI;
						}
					}
					//Người dùng chọn tiếp tục
					else
					{
						lanthi = atoi(c_LanThi);

						//Giới hạn lần thi > 0 và <= 10
						if (lanthi <= 0 || lanthi > 10)
						{
							char title[10] = "THONG BAO";
							char message[30] = "Lan thi khong hop le";
							char td[2][10] = { "   Thoat", "Chinh sua" };
							gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
							int checkTHONGBAO = veKhungThongBao(title, message, td);
							setNormallText();
							//Nguoi dung chon Thoat
							if (checkTHONGBAO == 0)
							{
								return;
							}
							//Nguoi dung chon tiep tuc
							else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
							{
								xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
								goto NHAPLANTHI;
							}
						}
						//Nhập Mã lớp, Mã môn học và lần thi thành công
						else
						{
							//Gọi hàm xóa điểm trong node SV

							int checkXoaDiem = sv->SV.xoaDiem(MaMonHoc, lanthi);
							if (checkXoaDiem == fail)
							{
								char title[10] = "THONG BAO";
								char message[30] = "Khong tim duoc thong tin";
								char td[2][10] = { "   Thoat", "Nhap lai" };
								gotoxy(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM);
								int checkTHONGBAO = veKhungThongBao(title, message, td);
								setNormallText();
								//Nguoi dung chon Thoat
								if (checkTHONGBAO == 0)
								{
									return;
								}
								//Nguoi dung chon tiep tuc
								else if (checkTHONGBAO == 1 || checkTHONGBAO == ESC)
								{
									xoaNoiDungVe(MINX_ALERT_TB_NHAPDIEM, MINY_ALERT_TB_NHAPDIEM, widthAlert, heightAlert);
									goto NHAPMASV;
								}
							}
							else if (checkXoaDiem == 0) goto NHAPTT;
						}
					}
				}
			}
		}
	}
}

void DSLOP::docfile()
{
	//nếu danh sách lớp không rỗng
	if (SL > 0) {

	}
	//nếu danh sách rỗng mới đọc file
	else 
	{
		
		ifstream inFile("VD.DAT", ios::in);// mở file
		if (inFile.fail()) {

		}
		else {
			inFile.read(reinterpret_cast< char *> (&SL), sizeof(int));//đọc số lượng lớp
			for (int i = 0; i < SL; i++) {
				//đọc từng phần tử của DSLOP
				DANHSACHLOP[i].docFile(inFile);
			}
		}
		
		inFile.close();
	}
	
}

void DSLOP::ghiFile()
{
	ofstream outFile("VD.DAT", ios::out);
	outFile.write(reinterpret_cast< const char *> (&SL), sizeof(int));
	for (int i = 0; i < SL; i++) {
		DANHSACHLOP[i].ghiFile(outFile);
	}
	outFile.close();
}

DSLOP::~DSLOP()
{
}

PTRNODESV DSLOP:: searchAllSV(char MSV[],int &k){
	for (int i = 0; i < SL; i++){
		if (DANHSACHLOP[i].searchSV(MSV) != NULL)
		{
			k = i;
			return DANHSACHLOP[i].searchSV(MSV);
		}

	}
	k = -1;
	return NULL;
}

int DSLOP::suaTTSinhVien(){
	char labelTb[20] = "SUA TT SINH VIEN";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap ma sinh vien chinh sua";
	char maSV[11];
	int k=-1;
	PTRNODESV i = NULL;
	maSV[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		switch (veTextFieldNhapKituSo(maSV, 11, title, message))
		{
		case ESC:
			return -1;
			break;
		case 0:
			if (searchAllSV(maSV,k) == NULL && maSV[0] != '\0')
			{
				gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "Ma sinh vien khong ton tai ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 2, MINY_ALERTNL + 2, 25, 1);
				//maSV[0] = '\0';

			}
			break;
		default:
			break;
		}
		i = searchAllSV(maSV,k);
	} while (i == NULL);
	Sleep(100);
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);
	DANHSACHLOP[k].suaSVtheoConTro(i);
	return -1;
}

void DSLOP::xoaSV(){
	int lop=0;
	PTRNODESV SV;
	char maSV[11];
	gotoxy(77, 2);
	setGreenText();
	cout << "XOA SINH VIEN";
	normal();
	do
	{
		maSV[0] = '\0';
		char title[] = "THONG BAO";
		char message[] = "Nhap ma sinh vien can xoa  ";
		do
		{
			gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
			int kiTu = veTextFieldNhapKituSo(maSV, 11, title, message);
			if (kiTu == ESC)
			{
				return;
			}

			SV = searchAllSV(maSV,lop);
			if (SV==NULL)
			{
				gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << " Ma sinh vien khong ton tai!";
				Sleep(1000);
				gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 3);
				for (int i = 0; i < widthAlert - 1; ++i)
				{
					cout << " ";
				}
				continue;
			}
			else
			{
				break;
			}
		} while (1);

		xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);

		DANHSACHLOP[lop].hienThiTTSV(SV);
		

		char message1[] = "Ban co chac chan xoa?";
		char td[2][10] = { "  Co", "   Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int select = veKhungThongBao(title, message1, td);
		setNormallText();
		if (select == 0)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
			
				DANHSACHLOP[lop].xoaSVtheoConTro(SV);
				char title[] = "THONG BAO";
				char message[] = "    Xoa thanh cong";
				char td[2][10] = { "Tiep tuc", "  Thoat" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int select = veKhungThongBao(title, message, td);
				setNormallText();
				if (select == 0)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					xoaNoiDungVe(MINX_BSV, MINY_BSV, 70, 10);
				}
				else
				{
					return;
				}
			
		}
		else
		{
			return;
		}

	} while (1);
}