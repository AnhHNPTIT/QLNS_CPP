#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class tienluong 
{
	protected:
		char manv[50];
		int chamcong;
		float baohiem;
		float phucap;
		float luong_cung;
		float luong;
		float luong_thucte;

	public:
		tienluong(){
			strcpy(this->manv,"");
		 	this->chamcong = 0;
		 	this->phucap = 0;
		 	this->luong_cung = 0;
		 	this->baohiem = 0;
		 	this->luong = 0;
		 	this->luong_thucte = 0;
		}

		tienluong(char manv[], int chamcong = 0, float luong_cung = 0, float phucap = 0, float baohiem = 0, float luong = 0, float luong_thucte = 0)
		{
			strcpy(this->manv, manv);
		 	this->chamcong = chamcong;
		 	this->phucap = phucap;
		 	this->luong_cung = luong_cung;
		 	this->baohiem = baohiem;
		 	this->luong = luong;
		 	this->luong_thucte = luong_thucte;
		}

		~tienluong(){
		}

		float luongthang()
		{
			luong_thucte = (((luong_cung + phucap)/26)*chamcong);
			baohiem = luong_thucte*0.105;
			luong = luong_thucte - baohiem;
			return luong;
		}

		friend istream & operator>>(istream &is, tienluong &tl)
		{
			cout<<"Cham cong: "; is>>tl.chamcong;
			cout<<"Phu cap: "; is>>tl.phucap;
			cout<<"Luong cung: "; is>>tl.luong_cung;
			cout<<endl;
			return is;
		}

		friend ostream & operator<<(ostream &os, tienluong &tl)
		{
			os<<"\n<================| THONG TIN LUONG |================>"<<endl;
			os<<tl.manv<<setw(20);
			os<<tl.luong_cung<<".000"<<setw(10)<<tl.phucap<<".000"<<setw(10);
			os<<tl.chamcong<<setw(5)<<tl.luong_thucte<<".000"<<setw(10);
			os<<tl.baohiem<<".000"<<setw(20)<<tl.luongthang()<<".000"<<endl;
			os<<endl;
			return os;
		}

		void nhapthongtincancapnhat(char ma[])
		{
			strcpy(manv,ma);
			cout<<"Cham cong can cap nhat: "; 
			cin>>chamcong;
			cout<<"Phu cap can cap nhat: ";
			cin>>phucap;
			cout<<"Luong cung can cap nhat: ";
			cin>>luong_cung;
		}
		
		char *get_manv()
		{
			return manv;
		}

		void set_manv(char mnv[])
		{
			strcpy(this->manv,mnv);
		}
};
