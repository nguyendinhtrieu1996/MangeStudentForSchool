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
	char maSV[10], hoSV[20], tenSV[10], phai[4], sdt[12];
	maSV[0] = '\0';
	hoSV[0] = '\0';
	tenSV[0] = '\0';
	phai[0] = '\0';
	sdt[0] = '\0';
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
					  if (viTriChinhSua <5)
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
					int kiTu = NhapChuoiVaChuSo(maSV, 15, MINX_BSV + 1, y);
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
						cout << "da sua ma sv";
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
				do{
					int kiTu = NhapChuoi(hoSV, 20, svCot1 + 2, y);
					if (hoSV[0] == '/0')
					{
						gotoxy(MINX_ALERTTB, 24);
						cout << "Ho khong hop le!";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);

					}
					else {
						p->SV.setHO(hoSV);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua Ho SV";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						strcpy(hoSV, p->SV.getHO());
						gotoxy(svCot1 + 2 + strlen(hoSV), y);
						break;

					}
				} while (1);
			}
			else if (viTriChinhSua == 3){
				do{
					int kiTu = NhapChuoi(tenSV, 10, svCot2 + 2, y);
					if (tenSV[0]=='/0')
					{
						gotoxy(MINX_ALERTTB, 24);
						cout << "Ten khong hop le!";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);

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
					int kiTu = NhapChuoi(phai, 4, svCot3 + 1, y);
					if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
					{
						gotoxy(MINX_ALERTTB, 24);
						cout << "GT khong hop le!";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);


					}
					else {
						p->SV.setPHAI(phai);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da chinh sua gioi tinh";
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
					int kiTu = NhapSo(sdt, 12, svCot4 + 1,y);
					if (strlen(sdt)<10)
					{
						gotoxy(MINX_ALERTTB, 24);
						cout << "sdt khong hop le!";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);

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

void LOP::nhapDiem(char MAMH[], int lanThi)
{
}

void LOP::inDiem(char MAMH[], int lanThi)
{
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
		printf("khong them phan tu vao danh sach duoc");
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
		// theem sinh vien vao cuoi danh sach
		insertAfter(SVIEN, p);
	}
	
}

PTRNODESV LOP::searchSV(char maSV[])
{

	PTRNODESV p;
	p = First;
	while (p != NULL&& strcmp(p->SV.getMASV(), maSV) != 0)
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
	
	char maSV[11], hoSV[20], tenSV[10], phai[4], sdt[12];
	maSV[0] = '\0';
	hoSV[0] = '\0';
	tenSV[0] = '\0';
	phai[0] = '\0';
	sdt[0] = '\0';
NHAPTTSV:
	//Nếu MASV rỗng thì trả về 0 nếu lớp hợp lệ, -1 nếu chuỗi rỗng
	int check1 = NhapChuoiVaChuSo(maSV, 11, MINX_BSV + 1, MINY_BSV + 4);
	if (check1 == 0)
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
			else if (check == 0)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				goto NHAPTTSV;
			}
		}
		//if (searchSV(maSV) == NULL)
		else
		{
		NHAP_HOSV:
			//Nhập Ho sv, không cho phép rỗng
			int check2 = NhapChuoi(hoSV, 20, svCot1 + 1, MINY_BSV + 4);
			if (check2 == ESC)
			{

				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check2 = veKhungThongBao(title, message, td);
				if (check2 == 0)
				{
					return;
				}
				else if (check2 == 1)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_HOSV;
				}
			}
		NHAP_TENSV:
			int check3 = NhapChuoi(tenSV, 10, svCot2 + 1, MINY_BSV + 4);
			if (check3 == ESC)
			{

				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check3 = veKhungThongBao(title, message, td);
				if (check3 == 0)
				{
					return;
				}
				else if (check3 == 1)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_TENSV;
				}
			}
		NHAP_PHAI:
			int check4 = NhapChuoi(phai, 3, svCot3 + 1, MINY_BSV + 4);
			if (check4 == 0){
				if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
				{
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					cout << "Phai khong hop le!";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, 30, 1);
					goto NHAP_PHAI;
				}
				else {

				}
			}
			else
			if (check4 == ESC)
			{
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check4 = veKhungThongBao(title, message, td);
				if (check4 == 0)
				{
					return;
				}
				else if (check4 == 1)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_PHAI;
				}
			}
		NHAP_SDT:
			int check5 = NhapSo(sdt, 11, svCot4 + 1, MINY_BSV + 4);
			if (check5 == 0){
				if (strlen(sdt)<10)
				{
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					cout << "sdt khong hop le!";
					Sleep(1000);
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, 30, 1);
					goto NHAP_SDT;
				}
				else {

				}
			}
			else
			if (check5 == ESC)
			{
				gotoxy(MINX_ALERTTB, MINY_ALERTNL);
				int check5 = veKhungThongBao(title, message, td);
				if (check5 == 0)
				{
					return;
				}
				else if (check5 == 1)
				{
					xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
					goto NHAP_SDT;
				}
			}
		}
		SINHVIEN sv(maSV, hoSV, tenSV, phai, sdt);
		insertLast(sv);
		

	}
	else if (check1 == ESC || check1 == -1)
	{
		char title[10] = "THONG BAO";
		char message[30] = "Ban co muon thoat?";
		char td[2][10] = { "    Co", "    Khong" };
		gotoxy(MINX_ALERTTB, MINY_ALERTNL);
		int check2 = veKhungThongBao(title, message, td);
		if (check2 == 0)
		{
			return;
		}
		else if (check2 == 1)
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
			//inSVTheoHang(p, MINY_XSV + 3 + stt, stt);
			//cout << p->SV.getMASV() << p->SV.getHO() << p->SV.getPHAI() << p->SV.getSDT();
			//stt++;
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
					char maSV[11], hoSV[20], tenSV[10], phai[4], sdt[12];
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
								if (i == X_XSV_COT1 || i == X_XSV_COT2 || i == X_XSV_COT3 || i == X_XSV_COT4 || i == X_XSV_COT5 || i == MAXX_XSV){
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
							if (viTri < (firstItem + 9) && viTri < stt - 1)
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
									   gotoxy(X_XSV_COT1 + strlen(k->SV.getMASV()) + 2, wherey());// Y_FIST_LOP + viTri);

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
									   int kiTu = NhapChuoiVaChuSo(maSV, 15, X_XSV_COT1 + 2,y); //Y_FIST_SV + viTri);
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
								   int kiTu = NhapChuoi(hoSV, 39, X_XSV_COT2 + 2,y);
								   k->SV.setHO(hoSV);
								   gotoxy(MINX_ALERTTB, 24);
								   cout << " Da sua ho sv ";
								   Sleep(1000);
								   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
								   gotoxy(X_XSV_COT2 + 2 + strlen(hoSV),y);
							   }
							   else if (viTriChinhSua == 3)
							   {
								  
								   SetBGColor(green_Dark);
								   int kiTu = NhapChuoi(tenSV, 10, X_XSV_COT3 + 2,y);
								   k->SV.setTEN(tenSV);
								   gotoxy(MINX_ALERTTB, 24);
								   cout << " Da sua ten SV ";
								   Sleep(1000);
								   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
								   gotoxy(X_XSV_COT3 + 2 + strlen(tenSV), y);
							   }
							   else if (viTriChinhSua == 4)
							   {
								   do{

								   
								   SetBGColor(green_Dark);
								   int kiTu = NhapChuoi(phai, 4, X_XSV_COT4 + 2,y);
								   if (strcmp(phai, "NAM") != 0 && strcmp(phai, "NU") != 0)
								   {
									   gotoxy(MINX_ALERTTB, 24);
									   cout << "Phai khong hop le!";
									   Sleep(1000);
									   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
									   
									  
								   }
								   else {
									 k->SV.setPHAI(phai);
									 gotoxy(MINX_ALERTTB, 24);
									 cout << "Đã sửa Phái";
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
									   int kiTu = NhapSo(sdt, 12, X_XSV_COT5 + 2,y);
									   if (strlen(sdt)<10)
									   {
										   gotoxy(MINX_ALERTTB, 24);
										   cout << "sdt khong hop le!";
										   Sleep(1000);
										   xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
										   
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