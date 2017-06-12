#include "DSMONHOC.h"

DSMONHOC::DSMONHOC()
{
	root = NULL;
}

void DSMONHOC::createDSMONHOC()
{
	MONHOC monHoc;

	char maMH[constMAMON];
	char tenMH[constTENMH];
	char c_STCLT[constcSTCLT];
	char c_STCTH[constcSTCTH];
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
	int checkMH = NhapChuoiVaChuSo(maMH, constMAMON, MINX_NDSMH + 1, MINY_NDSMH + 4);
	//Nhập mã môn học thành công
	if (checkMH == 0)
	{
		//Mã môn học  bị trùng
		if (kiemTraMH(maMH) != NULL) {
			char titleTB[] = "THONG BAO";
			char message[] = "Ma Mon hoc bi trung";
			char td[2][10] = { "Chinh sua", "    Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int checkTHONGBAO = veKhungThongBao(titleTB, message, td);
			//Người dùng chọn chinh sua
			if (checkTHONGBAO == 0 || checkTHONGBAO == ESC )
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPMAMH;
			}
			//Người dùng chọn thoát
			else
			{
				return;
			}
		} 
		else if (kiemTraMH(maMH) == NULL) {

		NHAPTENMH:

			/*
				Hàm nhập tên môn học => gồm kí tự và chứa khoảng trắng
				=> hàm trả về
				ESC nếu đang nhập người dùng bấm ESC kết thúc việc nhập chuỗi
			*/
			int checkTENMH = NhapChuoi(tenMH, constTENMH, XCOT1_NDSMH + 2, MINY_NDSMH + 4);
			//Người dùng muốn kết thúc việc nhập chuỗi
			if (checkTENMH == ESC)
			{
				char titleExit[] = "THONG BAO";
				char message[] = "Ban co muon thoat khong?";
				char td[2][10] = { "    Co", "    Khong" };
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int checkTHONGBAO = veKhungThongBao(titleExit, message, td);
				//Người dùng chọn thoát
				if (checkTHONGBAO == 0)
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
				int checkSTCLT = NhapSo(c_STCLT, constcSTCLT, XCOT2_NDSMH + 2, MINY_NDSMH + 4);

				// Nhập thành công
				if (checkSTCLT != ESC) 
				{
				NHAPSOTCTH:
					//Nhập số lượng tín chỉ thực hành => chỉ nhập số
					//=> hàm trả về ESC nếu đang nhập người dùng bấm ESC
					int checkSTCTH = NhapSo(c_STCTH, constcSTCTH, XCOT3_NDSMH + 2, MINY_NDSMH + 4);

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
						int checkTHONGBAO = veKhungThongBao(titleExit, message, td);
						//Người dùng chọn thoát
						if (checkTHONGBAO == 0)
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
					int checkTHONGBAO = veKhungThongBao(titleExit, message, td);
					//Người dùng chọn thoát
					if (checkTHONGBAO == 0)
					{
						return;
					}
					//Người dùng chọn tiếp tục => ESC va 1
					else
					{
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						goto NHAPSOTCLT;
					}
				}
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

void DSMONHOC::xuatDSMON()
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
		PTRNODEMH *conTro = NULL;

		PTRNODEMH p = root;
		duyetMAMHtang(p, conTro, size);

		//xep danh sách tăng dần theo tên môn học
		xepDSTangTheoTenMH(conTro, 0, size - 1);

		//in 10 phần tử đầu tiên
		if (size >= 10) {
			for(int i=0;i<10;i++)
			{	
				stt = i+1;
				inMonHocTheoHang(conTro[i], Y_FIST_MON + stt-1 , stt);
				
			}
		}
		else {
			for (int i = 0; i<size; i++)
			{
				stt = i + 1;
				inMonHocTheoHang(conTro[i], Y_FIST_MON + stt - 1, stt);

			}
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

				case Enter:
					//highlight môn học đầu tiên của trang
					firstItem = (trangHT - 1) * 10;
					PTRNODEMH k = conTro[firstItem];
					gotoxy(MINX_XDSMH + 1, Y_FIST_MON);
					SetBGColor(green_Dark);
					for (int i = 0; i < widthBANG_XMON - 2; i++)
					{
						cout << " ";
					}
					inMonHocTheoHang(k, Y_FIST_MON, firstItem + 1);

					//đưa con trỏ về sau mã môn của dòng môn học đang chọn
					gotoxy(XCOT1_XDSMH + strlen(k->MH.getMAMH()) + 2, Y_FIST_MON);
					int kiTu;
					int viTri = firstItem;
					do
					{
						
						char _MAMH[constMAMON];
						char _TENMH[constTENMH];
						char c_STCLT[constcSTCLT], c_STCTH[constcSTCTH];
						int _STCLT;
						int _STCTH;
						_MAMH[0] = '\0';
						_TENMH[0] = '\0';
						c_STCLT[0] = '\0';
						c_STCTH[0] = '\0';
						strcpy(_MAMH, k->MH.getMAMH());
						strcpy(_TENMH, k->MH.getTENMH());

						_STCLT = k->MH.getLT();
						_STCTH = k->MH.getTH();
						sprintf(c_STCLT, "%d", _STCLT);
						sprintf(c_STCTH, "%d", _STCTH);
						MONHOC mon;
					//	mon.nhapMH(_MAMH, _TENMH, _STCLT, _STCTH);
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
							if (viTri < firstItem + 9 && viTri < stt - 1) {
								k = conTro[viTri];
								viTriChinhSua = 1;
								//sua noi dung tại dòng cũ
								int y = wherey();
								gotoxy(MINX_XDSMH + 1, y);
								SetBGColor(black);
								for (int i = MINX_XSV + 1; i <= MAXX_XSV; ++i)
								{
									if (i == XCOT1_XDSMH || i == XCOT2_XDSMH || i == XCOT3_XDSMH || i == XCOT4_XDSMH || i == MAXX_XDSMH) {
										cout << (char)179;
									}
									else
										cout << " ";

								}

								inMonHocTheoHang(k, y, viTri + 1);
								//Hight light dòng mới
								//k lúc này sẽ chứa chỉ số dòng mới
								k = conTro[++viTri];

								SetBGColor(green_Dark);
								gotoxy(MINX_XLOP + 1, wherey() + 1);
								for (int i = 0; i < widthBANG_XMON - 2; ++i)
								{
									cout << " ";
								}
								inMonHocTheoHang(k, wherey(), viTri + 1);
								gotoxy(XCOT1_XDSMH + strlen(k->MH.getMAMH()) + 2, wherey());

							}
							else if (trangHT < TSTrang)
							{

								viTriChinhSua = 1;
								xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
								trangHT++;
								gotoxy(XCOT4_XDSMH - 10, MINY_XDSMH - 1);
								cout << "Trang: " << trangHT << " / " << TSTrang;
								veKhungXuatMonHoc();
								firstItem = (trangHT - 1) * 10;
								viTri = firstItem;
								//viTri = 1;
								for (int i = 0; i < 10; ++i)
								{
									if (viTri < stt)
									{
										k = conTro[viTri++];
										inMonHocTheoHang(k, Y_FIST_MON + i, viTri);
									}
								}

								//hightLight dong dau tien trang moi
								viTri = firstItem;
								if (viTri < (firstItem + 9) && viTri < stt - 1)
								{
									int y = Y_FIST_SV;
									k = conTro[viTri];
									gotoxy(MINX_XDSMH + 1, y);
									SetBGColor(green_Dark);
									for (int i = 0; i < widthBANG_XMON - 2; ++i)
									{
										cout << " ";
									}
									inMonHocTheoHang(k, y, viTri + 1);
									gotoxy(XCOT1_XDSMH + strlen(k->MH.getMAMH()) + 2, y);
								}
							}
							break;//kết thúc lệnh trong case pagedown

						case PageUp:
							if (viTri > 0 && viTri > firstItem)
							{
								viTriChinhSua = 1;
								//sua noi dung tại dòng cũ
								int y = wherey();
								k = conTro[viTri];
								gotoxy(MINX_XDSMH + 1, y);
								SetBGColor(black);
								for (int i = MINX_XDSMH + 1; i <= MAXX_XDSMH; ++i)
								{
									if (i == XCOT1_XDSMH || i == XCOT2_XDSMH || i == XCOT3_XDSMH || i == XCOT4_XDSMH || i == MAXX_XDSMH) {
										cout << (char)179;
									}
									else
										cout << " ";

								}
								inMonHocTheoHang(k, y, viTri + 1);

								//Hight light dòng mới
								k = conTro[--viTri];
								SetBGColor(green_Dark);
								gotoxy(MINX_XDSMH + 1, wherey() - 1);
								for (int i = 0; i < widthBANG_XMON - 2; ++i)
								{
									cout << " ";
								}
								inMonHocTheoHang(k, wherey(), viTri + 1);
								gotoxy(XCOT1_XDSMH + strlen(k->MH.getMAMH()) + 2, wherey());

							}
							else if (trangHT > 0 && viTri > 0)
							{
								viTriChinhSua = 1;
								xoaNoiDungVe(MINX_XSV - 1, MINY_XSV - 1, widthBANG_XSV + 1, heightBANG_XSV + 1);
								trangHT--;
								gotoxy(XCOT4_XDSMH - 10, MINY_XSV - 1);
								cout << "Trang: " << trangHT << " / " << TSTrang;
								veKhungXuatMonHoc();
								firstItem = (trangHT - 1) * 10;
								viTri = firstItem;
								for (int i = 0; i < 10; ++i)
								{
									if (viTri < stt)
									{
										k = conTro[viTri++];
										inMonHocTheoHang(k, Y_FIST_MON + i, viTri);
									}
								}
								viTri = firstItem + 9;
								if (viTri > 0)
								{
									int y = Y_FIST_MON + 9;
									k = conTro[viTri];
									gotoxy(MINX_XDSMH + 1, y);
									SetBGColor(green_Dark);
									for (int i = 0; i < widthBANG_XMON - 2; ++i)
									{
										cout << " ";
									}

									inMonHocTheoHang(k, y, viTri + 1);
									gotoxy(XCOT1_XDSMH + strlen(k->MH.getMAMH()) + 2, y);
								}
							}

						break;//kết thúc lệnh pageup
						case ESC:
						{
							return;
						}
						case F2:
						{
							int y = Y_FIST_MON + viTri - (trangHT - 1) * 10;
							if (viTriChinhSua == 1)
							{
								do
								{

									SetBGColor(green_Dark);
									int kiTu = NhapChuoiVaChuSo(_MAMH, 15, XCOT1_XDSMH + 2, y);
									//Chuỗi mã môn học trả về bị rỗng
									if (kiTu == -1)
									{

										char title[] = "THONG BAO";
										char message[] = "MAMH khong duoc rong!";
										char td[2][10] = { "Chinh sua", "    Huy" };
										normal();
										gotoxy(MINX_ALERTTB, MINY_ALERTTB);
										int select = veKhungThongBao(title, message, td);
										//chọn chỉnh sửa
										if (select == 0)
										{
											_MAMH[0] = '\0';
											xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
											continue;
										}
										//chọn hủy
										else if (select == 1)
										{
											xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);

											k = conTro[viTri];
											SetBGColor(green_Dark);
											gotoxy(MINX_XDSMH + 1, y);
											for (int i = 0; i < widthBANG_XMON - 2; ++i)
											{
												cout << " ";
											}
											inMonHocTheoHang(k, y, viTri + 1);
											break;
										}


									}
									else if (kiemTraMH(_MAMH) == NULL && kiTu == 0)
									{
										//Xóa node mã MH cũ
										XoaNODEMonHoc(root, k->MH.getMAMH());
										mon.nhapMH(_MAMH, _TENMH, _STCLT, _STCTH);
										//thêm node có mã MH mới
										insertNodeMH(root, mon);
									
										gotoxy(MINX_ALERTTB, 24);
										cout << "da sua MAMH";
										Sleep(1000);
										xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
										gotoxy(XCOT1_XDSMH + 2 + strlen(_MAMH), y);
										break;
									}
									else if (strcmp(_MAMH, k->MH.getMAMH()) == 0)
									{
										break;
									}
									//Mã môn học bị trùng
									else if (kiemTraMH(_MAMH) != NULL && kiTu == 0)
									{
										char title[] = "THONG BAO";
										char message[] = "MAMH bi trung!";
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
											int y = Y_FIST_MON + viTri;
											k = conTro[viTri];
											SetBGColor(green_Dark);
											gotoxy(MINX_XDSMH + 1, y);
											for (int i = 0; i < widthBANG_XSV - 2; i++)
											{
												cout << " ";
											}
											inMonHocTheoHang(k, y, viTri + 1);
											break;
										}
									}
								} while (true);
							}
							else if (viTriChinhSua == 2)
							{
								SetBGColor(green_Dark);
								int kiTu = NhapChuoi(_TENMH, 40, XCOT2_XDSMH + 2, y);
								k->MH.setTENMH(_TENMH);
								gotoxy(MINX_ALERTTB, 24);
								cout << " Da sua Ten MH ";
								Sleep(1000);
								xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
								gotoxy(XCOT2_XDSMH + 2 + strlen(_TENMH), y);
							}
							else if (viTriChinhSua == 3)
							{

								SetBGColor(green_Dark);
								int checkSTCLT = NhapSo(c_STCLT, 3, XCOT3_XDSMH + 2,y);

								//Nhập thành công
								if (checkSTCLT != ESC)
								{

									_STCLT = atoi(c_STCLT);
									k->MH.setLT(_STCLT);
									gotoxy(MINX_ALERTTB, 24);
									cout << " Da sua STCLT ";
									Sleep(1000);
									xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
									gotoxy(XCOT3_XDSMH + 2 + strlen(c_STCLT), y);

								}
							}
							else if (viTriChinhSua == 4)
							{
								SetBGColor(green_Dark);
								int checkSTCTH = NhapSo(c_STCTH, 3, XCOT4_XDSMH + 2, y);

								//Nhập thành công
								if (checkSTCTH != ESC)
								{
									_STCTH = atoi(c_STCTH);
									k->MH.setTH(_STCTH);
									gotoxy(MINX_ALERTTB, 24);
									cout << " Da sua STCTH";
									Sleep(1000);
									xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
									gotoxy(XCOT4_XDSMH + 2 + strlen(c_STCTH), y);

								}
								
							}
							
							break;
						}
						case Left:
						{
							int y = Y_FIST_MON + viTri - (trangHT - 1) * 10;
							if (viTriChinhSua >1)
							{
								viTriChinhSua--;
								if (viTriChinhSua == 1)
								{
									gotoxy(XCOT1_XDSMH + strlen(_MAMH) + 2, y);
								}
								else if (viTriChinhSua == 2)
								{
									gotoxy(XCOT2_XDSMH + strlen(_TENMH) + 2, y);
								}
								else if (viTriChinhSua == 3)
								{
									gotoxy(XCOT3_XDSMH + strlen(c_STCLT) + 1, y);
								}
								
							}
							break;
						} //hết lệnh left
						case Right:
						{
							int y = Y_FIST_MON + viTri - (trangHT - 1) * 10;
							if (viTriChinhSua <4)
							{
								viTriChinhSua++;
								}
								else if (viTriChinhSua == 4)
								{
									gotoxy(XCOT4_XDSMH + strlen(c_STCTH) + 1, y);
								}
								else if (viTriChinhSua == 3)
								{
									gotoxy(XCOT3_XDSMH + strlen(c_STCLT) + 1, y);
								}
								else if (viTriChinhSua == 2)
								{
									gotoxy(XCOT2_XDSMH + strlen(_TENMH) + 1, y);
								}

							}
							break;
						
						}
					} while (1);
					break;//hết lệnh f2
				}

			} while (1);

			//delete[] conTro;
		getch();
	}
}

void DSMONHOC::duyetMAMHtang(PTRNODEMH p, PTRNODEMH *&a, int &size)
{
	if (p != NULL)
	{
		PTRNODEMHPushBack(a, size, p);
		duyetMAMHtang(p->left, a, size);
		duyetMAMHtang(p->right, a, size);
	}
}

//xếp qicksort :)) nhiều phần tử bị đứng ko biết sao hết :))
void DSMONHOC::xepDSTangTheoTenMH(PTRNODEMH *&a, int q, int r)
{
	PTRNODEMH temp;
	int i = q;
	int j = r;
	char x[constTENMH]; 
	strcpy(x, a[(q + r) / 2]->MH.getTENMH());
	do {
		while (strcmp(x, a[i]->MH.getTENMH()) > 0) i++;
		while (strcmp(x, a[j]->MH.getTENMH()) < 0) j--;
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
void DSMONHOC::xepDSTangTheoTenMHdemo(PTRNODEMH *&a, int size)
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

void DSMONHOC::XoaNODEMonHoc(PTRNODEMH &p,char maMH[])
{
	if (p == NULL){
	
	}
	else
	{
		if (strcmp(maMH, p->MH.getMAMH()) < 0) 
			XoaNODEMonHoc(p->left, maMH);
		else if (strcmp(maMH, p->MH.getMAMH()) > 0)
			XoaNODEMonHoc(p->right, maMH);
		else 
			// truong hop tim thay key can xoa
		{
			PTRNODEMH rp = p;
			if (rp->right == NULL)
				p = rp->left;
			else if (rp->left == NULL)
				p = rp->right;
			else {
				XoaTruongHop3(rp, rp->right);
			}
			delete rp;
			rp = NULL;
		}
	}
}



void DSMONHOC::XoaTruongHop3(PTRNODEMH &rp, PTRNODEMH &r)
{
	if (r->left == NULL)
	{
		strcpy(rp->MAMH, r->MAMH);
		rp->MH = r->MH;
		rp = r;
		r = rp->right;
	}
	else
	{
		XoaTruongHop3(rp, r);
	}
}

void DSMONHOC::xoaMON()
{
	PTRNODEMH mh;
	char _maMH[constMAMON];
	gotoxy(77, 2);
	setGreenText();
	cout << "XOA MON HOC";
	normal();
	do
	{
		_maMH[0] = '\0';
		char title[] = "THONG BAO";
		char message[] = "Nhap ma mon hoc can xoa  ";
		do
		{
			gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
			int kiTu = veTextFieldNhapKituSo(_maMH, constMAMON, title, message);
			if (kiTu == ESC)
			{
				return;
			}

			mh = kiemTraMH(_maMH);
			if (mh == NULL)
			{
				gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << " MAMON khong ton tai!";
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

		hienThiTTMON(mh);


		char message1[] = "Ban co chac chan xoa?";
		char td[2][10] = { "  Co", "   Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int select = veKhungThongBao(title, message1, td);
		if (select == 0)
		{
			xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);

			XoaNODEMonHoc(root,_maMH);
			

			//xoaNODEtheoConTro(mh);

			char title[] = "THONG BAO";
			char message[] = "    Xoa thanh cong";
			char td[2][10] = { "Tiep tuc", "  Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int select = veKhungThongBao(title, message, td);
			if (select == 0)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				xoaNoiDungVe(MINX_NDSMH, MINY_NDSMH, 70, 10);
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


void DSMONHOC::hienThiTTMON(PTRNODEMH p)
{
	veKhungNhapDSMONHOC();
	// xuat thong tin sinh vien	
	gotoxy(MINX_NDSMH + 1, MINY_NDSMH + 4);
	cout << p->MH.getMAMH();
	gotoxy(XCOT1_NDSMH + 2, MINY_NDSMH + 4);
	cout << p->MH.getTENMH();
	gotoxy(XCOT2_NDSMH + 2, MINY_NDSMH + 4);
	cout << p->MH.getLT();
	gotoxy(XCOT3_NDSMH + 1, MINY_NDSMH + 4);
	cout << p->MH.getTH();
}

void DSMONHOC::suaMON()
{
	char labelTb[20] = "SUA TT MON HOC";
	labelTable(labelTb);
	char title[] = "THONG BAO";
	char message[] = "Nhap MA MHOC can chinh sua";
	char _MAMH[constMAMON];
	PTRNODEMH i = NULL;
	_MAMH[0] = '\0';
	do {
		gotoxy(MINX_ALERTTB, MINY_ALERTNL - 3);
		switch (veTextFieldNhapKituSo(_MAMH, constMAMON, title, message))
		{
		case ESC:
			return;
			break;
		case 0:
			if (kiemTraMH(_MAMH) == NULL && _MAMH[0] != '\0')
			{
				gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 3);
				SetColor(red_hightlight);
				cout << "MA MHOC khong ton tai ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB + 2, MINY_ALERTNL + 2, 25, 1);

			}
			break;
		default:
			break;
		}
		i = kiemTraMH(_MAMH);
	} while (i == NULL);
	Sleep(100);
	xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL - 3, widthAlert, heightTextField);
	suaTTMON(_MAMH, i);
	
}

void DSMONHOC::suaTTMON(char cMAMH[], PTRNODEMH p)
{
	hienThiTTMON(p);

	MONHOC mon = p->MH;

	char _MAMH[constMAMON];
	char _TENMH[constTENMH];
	char c_STCLT[constcSTCLT], c_STCTH[constcSTCTH];
	int _STCLT;
	int _STCTH;
	_MAMH[0] = '\0';
	_TENMH[0] = '\0';
	c_STCLT[0] = '\0';
	c_STCTH[0] = '\0';
	strcpy(_MAMH, p->MH.getMAMH());
	strcpy(_TENMH, p->MH.getTENMH());

	_STCLT = p->MH.getLT();
	_STCTH = p->MH.getTH();
	sprintf(c_STCLT, "%d", _STCLT);
	sprintf(c_STCTH, "%d", _STCTH);

	int viTriChinhSua = 1;
	int y = MINY_NDSMH + 4;
	gotoxy(MINX_NDSMH + 1 + strlen(_MAMH), y);

	int kiTu = 0;
	do {
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
					gotoxy(MINX_NDSMH + strlen(_MAMH) + 1, y);
				}
				else if (viTriChinhSua == 2)
				{
					gotoxy(XCOT1_NDSMH + strlen(_TENMH) + 2, y);
				}
				else if (viTriChinhSua == 3)
				{
					gotoxy(XCOT2_NDSMH + strlen(c_STCLT) + 2, y);
				}
				
			}
			break;
		}
		case Right:
		{
			if (viTriChinhSua < 4)
			{
				viTriChinhSua++;
				 if (viTriChinhSua == 4)
				{
					 gotoxy(XCOT3_NDSMH + strlen(c_STCTH) + 1, y);
				}
				else if (viTriChinhSua == 3)
				{
					gotoxy(XCOT2_NDSMH + strlen(c_STCLT) + 2, y);
				}
				else if (viTriChinhSua == 2)
				{
					gotoxy(XCOT1_NDSMH + strlen(_TENMH) + 2, y);
				}

			}
			break;
		}
		case F2:
			if (viTriChinhSua == 1) {
				do
				{
					int kiTu = NhapChuoiVaChuSo(_MAMH, constMAMON, MINX_NDSMH + 1, y);
					//Chuỗi mã Sinh viên trả về bị rỗng
					if (kiTu == fail)
					{
						char title[] = "THONG BAO";
						char message[] = "Ma MH khong duoc rong!";
						char td[2][10] = { "Chinh sua", "    Huy" };
						normal();
						gotoxy(MINX_ALERTTB, MINY_ALERTTB);
						int select = veKhungThongBao(title, message, td);
						if (select == 0)
						{
							//Cho biet chuoi dang rong
							_MAMH[0] = '\0';
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							continue;
						}
						else if (select == 1)
						{
							xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTTB, widthAlert, heightAlert);
							gotoxy(MINX_NDSMH + 1, y);
							for (int i = 0; i < widthBANG_XMON - 2; ++i)
							{
								cout << " ";
							}
							break;
						}


					}
					else if (strcmp(_MAMH, p->MH.getMAMH()) == 0)
					{
						break;
					}
					else if (kiemTraMH(_MAMH) == NULL &&kiTu == 0)
					{
						//Xóa node mã MH cũ
						XoaNODEMonHoc(root, p->MH.getMAMH());
						mon.nhapMH(_MAMH, _TENMH, _STCLT, _STCTH);
						//thêm node có mã MH mới
						insertNodeMH(root, mon);

						gotoxy(MINX_ALERTTB, 24);
						cout << "da sua MAMH";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						gotoxy(MINX_NDSMH + 1 + strlen(_MAMH), y);
						break;
					}

					//Mã sinh viên bị trùng
					else if (kiemTraMH(_MAMH) != NULL && kiTu == 0)
					{
						char title[] = "THONG BAO";
						char message[] = "MAMH bi trung!";
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
							gotoxy(MINX_NDSMH + 1, y);
							for (int i = 0; i < widthBANG_XSV - 2; i++)
							{
								cout << " ";
							}
							break;

						}
					}
				} while (1);
			}
			else if (viTriChinhSua == 2) {
				int kiTu = NhapChuoi(_TENMH, 40, XCOT1_NDSMH + 2, y);
				p->MH.setTENMH(_TENMH);
				gotoxy(MINX_ALERTTB, 24);
				cout << " Da sua Ten MH ";
				Sleep(1000);
				xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
				gotoxy(XCOT1_NDSMH + 2 + strlen(_TENMH), y);
			}
			else if (viTriChinhSua == 3) {
				int checkSTCLT = NhapSo(c_STCLT, constcSTCLT, XCOT2_NDSMH + 2, y);

				//Nhập thành công
				if (checkSTCLT != ESC)
				{

					_STCLT = atoi(c_STCLT);
					p->MH.setLT(_STCLT);
					gotoxy(MINX_ALERTTB, 24);
					cout << " Da sua STCLT ";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
					gotoxy(XCOT2_NDSMH + 2 + strlen(c_STCLT), y);

				}
			}
			else if (viTriChinhSua == 4) {
				int checkSTCTH = NhapSo(c_STCTH, constcSTCTH, XCOT3_NDSMH + 1, y);

				//Nhập thành công
				if (checkSTCTH != ESC)
				{
					_STCTH = atoi(c_STCTH);
					p->MH.setTH(_STCTH);
					gotoxy(MINX_ALERTTB, 24);
					cout << " Da sua STCTH";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
					gotoxy(XCOT3_NDSMH + 1 + strlen(c_STCTH), y);

				}
			}
			
			break;
		default:
			break;
		}
	} while (1);


	char e = getch();
}

void DSMONHOC::PTRNODEMHPushBack(PTRNODEMH *&a, int &n, PTRNODEMH p)
{
	int m = n + 1;
	PTRNODEMH* aNew = (PTRNODEMH*)realloc(a, m * sizeof(PTRNODEMH));
	//Cấp phát thành công
	if (aNew != NULL) {
		aNew[n] = new NODEMH;
		aNew[n] = p;
		n++;
		a = aNew;
	}
}

DSMONHOC::~DSMONHOC()
{

}

//ghi file

void DSMONHOC::ghiMon(PTRNODEMH p, ofstream &ofs)
{
	if (p != NULL)
	{
		MONHOC mh = p->MH;
		ofs.write(reinterpret_cast< const char *> (&mh), sizeof(MONHOC));
		ghiMon(p->left, ofs);
		ghiMon(p->right, ofs);
	}
}

void DSMONHOC::ghiFileMon()
{
	ofstream outFile("MON.DAT", ios::out);
	ghiMon(root, outFile);
	outFile.close();
}

void DSMONHOC::docFile()
{
	root = NULL;
	ifstream inFile("MON.DAT", ios::in);
	if (inFile.fail()) {

	} else 
	while(!inFile.eof()) {
		MONHOC mh;
		inFile.read(reinterpret_cast< char *> (&mh), sizeof(MONHOC));
		insertNodeMH(root, mh);
	}

}
