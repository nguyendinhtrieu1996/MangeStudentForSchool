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
	sTCLT = 0;
	sTCTH = 0;

	veKhungNhapDSMONHOC();

NHAPTENMONHOC:
	
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
		//Mã môn học không bị trùng
		if (kiemTraMH(maMH) == NULL)
		{
			/*
				Hàm nhập tên môn học => gồm kí tự và chứa khoảng trắng
				=> hàm trả về
				ESC nếu đang nhập người dùng bấm ESC kết thúc việc nhập chuỗi
			*/
			int checkTENMH = NhapChuoi(tenMH, 40, XCOT1_NDSMH + 2, MINY_NDSMH + 4);
			//Người dùng muốn kết thúc việc nhập chuỗi
			if (checkMH == ESC)
			{

			}
			else // Nhập chuỗi thành công
			{
				/*
					Nhập số lượng tín chỉ lí thuyết => chỉ nhập số
				*/
			}
		}
		else // Mã môn học bị trùng
		{

		}
	}
	else if (checkMH == ESC || checkMH == -1)
	{

	}
}

void DSMONHOC::insertNodeMH(MONHOC monHoc)
{

}

PTRNODEMH DSMONHOC::kiemTraMH(char maMH[])
{
	PTRNODEMH p;
	p = root;
	while (p != NULL && strcmp(maMH, p->MAMH) != 0)
	{
		//maMH nhỏ hơn khóa chính (MAMH) tại NODE đang xét
		if (strcmp(maMH, p->MAMH) < 0)
		{
			p = p->left;
		}
		else 
		{
			p = p->right;
		}
	}

	return p;
}

DSMONHOC::~DSMONHOC()
{
}
