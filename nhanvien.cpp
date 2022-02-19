#include <iostream>
#include <string.h>
#include<iomanip>

using namespace std;

class nhanvien
{
	protected: 
		char manv[50];
		char hoten[100];
		struct ngaysinh
		{
			int ngay, thang, nam;
		};
		ngaysinh ns;
		char quequan[50];
		char hokhau[50];
		char trinhdo_hocvan[50];
		char tinhtrang_honnhan[50];
		char phongban[50];
		char chucvu[50];
		struct ngayvaolam
		{
			int day, month, year;
		};
		ngayvaolam nvl;

	public:
		nhanvien(){
			strcpy(this->manv,"");
			strcpy(this->hoten,"");
			this->ns.ngay = 0;
			this->ns.thang = 0;
			this->ns.nam = 0;
			strcpy(this->quequan, "");
			strcpy(this->hokhau, "");
			strcpy(this->trinhdo_hocvan, "");
			strcpy(this->tinhtrang_honnhan, "");
			strcpy(this->phongban, "");
			strcpy(this->chucvu, "");
			this->nvl.day = 0;
			this->nvl.month = 0;
			this->nvl.year = 0;	
		}

		//ham khoi tao: ten ham == ten class
		nhanvien(char manv[], char hoten[], int ngay, int thang, int nam, 
		 char quequan[], char hokhau[], char trinhdo_hocvan[], char tinhtrang_honnhan[], 
		 char phongban[], char chucvu[], int day, int month, int year)
		{
		    strcpy(this->manv, manv);
			strcpy(this->hoten, hoten);
			this->ns.ngay = ngay;
			this->ns.thang = thang;
			this->ns.nam = nam;
			strcpy(this->quequan, quequan);
			strcpy(this->hokhau, hokhau);
			strcpy(this->trinhdo_hocvan, trinhdo_hocvan);
			strcpy(this->tinhtrang_honnhan, tinhtrang_honnhan);
			strcpy(this->phongban, phongban);
			strcpy(this->chucvu, chucvu);
			this->nvl.day = day;
			this->nvl.month = month;
			this->nvl.year = year;
		}

		~nhanvien(){
		}

		friend istream & operator>>(istream &is, nhanvien &nv)
		{
			is.ignore();
			cout<<"Ma NV: "; is.getline(nv.manv, 50);
			cout<<"Ho va ten: "; is.getline(nv.hoten, 50);
			cout<<"Ngay sinh: ";
			is>>nv.ns.ngay>>nv.ns.thang>>nv.ns.nam;
			cin.ignore();
			cout<<"Que quan: "; is.getline(nv.quequan, 50);;
			cout<<"Ho khau: "; is.getline(nv.hokhau, 50);;
			cout<<"Trinh do hoc van: "; is.getline(nv.trinhdo_hocvan, 50);
			cout<<"Tinh trang hon nhan: "; cin.getline(nv.tinhtrang_honnhan, 50);
			cout<<"Phong ban: "; is.getline(nv.phongban, 50);
			cout<<"Chuc vu: "; is.getline(nv.chucvu, 50);
			cout<<"Ngay vao lam: ";
			is>>nv.nvl.day>>nv.nvl.month>>nv.nvl.year;
			return is;
		}

		friend ostream & operator<<(ostream & os, nhanvien &nv)
		{
			os<<"\n<---------------| THONG TIN CA NHAN |---------------->"<<endl;
			os<<nv.manv<<setw(20)<<nv.hoten<<setw(20);
			os<<nv.ns.ngay<<"/"<<nv.ns.thang<<"/"<<nv.ns.nam<<setw(20);
			os<<nv.quequan<<setw(20)<<nv.hokhau<<setw(20)<<nv.trinhdo_hocvan<<setw(20);
			os<<nv.tinhtrang_honnhan<<setw(20)<<endl;
			os<<"\n<---------------| THONG TIN VIEC LAM |--------------->"<<endl;
			os<<nv.phongban<<setw(20)<<nv.chucvu<<setw(20);
			os<<nv.nvl.day<<"/"<<nv.nvl.month<<"/"<<nv.nvl.year<<endl;
			os<<endl;
			return os;
		}

		void nhapthongtincancapnhat(char ma[])
		{
			strcpy(manv,ma);
			cout<<"Ho va ten can cap nhat: "; 
			cin.getline(hoten, 100);
			cout<<"Ngay sinh can cap nhat: ";
			cin>>ns.ngay>>ns.thang>>ns.nam;
			cin.ignore();
			cout<<"Que quan can cap nhat: ";
			cin.getline(quequan, 50);
			cout<<"Ho khau can cap nhat: ";
			cin.getline(hokhau, 50);
			cout<<"Trinh do hoc van can cap nhat: ";
			cin.getline(trinhdo_hocvan, 50);
			cout<<"Tinh trang hon nhan can cap nhat: ";
			cin.getline(tinhtrang_honnhan, 50);
			cout<<"Phong ban can cap nhat: "; 
			cin.getline(phongban, 50);
			cout<<"Chuc vu can cap nhat: ";
			cin.getline(chucvu, 50);
			cout<<"Ngay vao lam can cap nhat: ";
			cin>>nvl.day>>nvl.month>>nvl.year;
		}

		char *get_phongban()
		{
			return phongban;
		}
		
		char *get_manv()
		{
			return manv;
		}
};
