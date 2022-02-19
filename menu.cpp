#include<iostream>
#include <string.h>
#include <iomanip>
#include "nhanvien.cpp"
#include "tienluong.cpp"

using namespace std;

class menu
{
    private:
		nhanvien nv[100];
		int n = 0;
		
		tienluong tl[100];
		int m = 0;

    public:
		menu(){
		}

		~menu(){
		}

		// xoa thong tin nhan vien theo vi tri
        void xoa_nhanvien(int vt)
        {
            for (int i = vt + 1; i < n; i++)
            {
                nv[i - 1] = nv[i];
            }
            n = n - 1;
        }

		// tra cuu thong tin nhan vien
		void tim_nhanvien()
		{
			char maNV[50];
			int j = 0;
			cout<<"\tTim kiem nhan vien"<<endl;
			cin.ignore();
			cout<<"Nhap ma Nhan vien can tim: "; cin.getline(maNV, 50);
			for(int i = 0; i < n; i++)
			{
				if(strcmp(nv[i].get_manv(), maNV) == 0)
				{
					cout<<nv[i];
					j = i;
				}
			}
			if(j == 0) 
			{
				cout<<"Khong tim thay nhan vien!"<<endl;
			}
		}

		// them thong tin luong cho nhan vien
        void capnhat_luong()
		{
			char ma[50];
			tienluong x;
			int j = 0;
			cout<<"\tCap nhat luong"<<endl;
			cin.ignore();
			cout<<"Nhap ma Nhan vien: "; cin.getline(ma, 50);
			for(int i = 0; i < n; i++)
			{
				if(strcmp(nv[i].get_manv(), ma) == 0) //strcmp : ham so sanh 2 ki tu- ss ma nv trong ds vs ma nv tim kiem
				{
					x.set_manv(ma);
					cin>>x;
					cout<<x;
					tl[j] = x;
			        j++;
				}
			}
			if(j == 0)
			{
				cout<<"Khong tim thay nhan vien!"<<endl;
				cout<<endl;
			}	
		}

		// Nhap lua chon theo menu de thuc hien
        void INPUT()
		{
			int luachon;
			do
			{
				cout<<"\n ============== HE THONG QUAN LY NHAN SU =============="<<endl;
				cout<<" | 1. Quan li ho so nhan vien                         |"<<endl;
				cout<<" | 	11. Nhap, xuat thong tin tung nhan vien       |"<<endl;
				cout<<" | 	12. Xuat nhan vien theo phong ban             |"<<endl;
				cout<<" | 	13. Xoa nhan vien ra khoi danh sach           |"<<endl;
				cout<<" | 	14. Cap nhat lai thong tin cua nhan vien      |"<<endl;
				cout<<" | 2. Quan li luong                                   |"<<endl;
				cout<<" | 	21. Cap nhat thong tin ve luong               |"<<endl;
				cout<<" | 	22. Sua thong tin ve luong                    |"<<endl;
				cout<<" | 3. Tim kiem                                        |"<<endl;
				cout<<" | 4. Hien thi toan bo thong tin nhan vien            |"<<endl;
				cout<<" | 5. Xoa toan bo thong tin                           |"<<endl;
				cout<<" | 6. Thoat chuong trinh                              |"<<endl;
				cout<<" ======================================================"<<endl;
        	    cout<<"Nhap lua chon: "; cin>>luachon;

        	    switch(luachon)
        	    {
        	    	case 11:
        	    		{
							cout<<"Nhap so luong nhan vien: ";
							cin>>n;
							for(int i = 0;i < n; i++){
								cout<<"\tNhap nhan vien thu "<<i+1<<endl;
								cin>>nv[i];
								cout<<nv[i];
							}
        	    			break;
						}
        	    	case 12:
        	    		{
                            char pb[50];
							cin.ignore();
                            cout<<"Nhap phong ban can xuat thong tin: ";
                            cin.getline(pb, sizeof(pb));
                            int dem = 0;
                            for(int i = 0; i < n; i++)
							{
                                if(strcmp(nv[i].get_phongban(),pb) == 0)
								{
									dem++;
                                    cout<<"\tNhan vien thu "<<dem<<endl;
                                    cout<<nv[i];
                                }
                            }
                            if(dem == 0)
							{
								cout<<"Khong co thong tin phong ban "<<pb<<" can tim trong danh sach\n";
							} 
        	    			break;
						}	
					case 13:
						{
                            char mnv[50];
							cin.ignore();
                            cout<<"Nhap ma nhan vien can xoa trong danh sach: ";
                            cin.getline(mnv, sizeof(mnv));
                            int dem = 0;
                            for(int i=0;i<n;i++)
							{
                                if(strcmp(nv[i].get_manv(),mnv) == 0)
								{
                                    xoa_nhanvien(i);
                                    i--;
                                    dem++;
                                }
                            }
                            if(dem == 0)
							{
								cout<<"Khong co nhan vien can xoa co ma "<<mnv<<" trong danh sach\n";
							}
                            else
							{
								cout<<"Da xoa xong nhan vien co ma "<<mnv<<" trong danh sach\n";
							}  
							break;                      
						}
					case 14:
						{
							char mnv[50];
							cin.ignore();
                            cout<<"Nhap ma nhan vien can cap nhat trong danh sach: ";
                            cin.getline(mnv, sizeof(mnv));
                            int dem = 0;
                            nhanvien nvcapnhat;
                            for(int i = 0; i < n; i++)
							{
                                if(strcmp(nv[i].get_manv(),mnv) == 0)
								{
                                    nvcapnhat.nhapthongtincancapnhat(mnv);
                                    nv[i] = nvcapnhat;
                                    dem++;
                                }
                            }
                            if(dem == 0)
							{
								cout<<"Khong co nhan vien can cap nhat co ma "<<mnv<<" trong danh sach\n";
							}
                            else
							{
								cout<<"Da cap nhat xong nhan vien co ma "<<mnv<<" trong danh sach\n";
							}
							break;
						}	
					case 21:
						{
							capnhat_luong();
							break;
						}
					case 22:
						{
							char mnv[50];
							cin.ignore();
                            cout<<"Nhap ma nhan vien can sua thong tin luong: ";
                            cin.getline(mnv, sizeof(mnv));
                            int dem = 0;
                            tienluong tlcapnhat;
                            for(int i = 0; i < n; i++)
							{
                                if(strcmp(tl[i].get_manv(),mnv) == 0)
								{
                                    tlcapnhat.nhapthongtincancapnhat(mnv);
                                    tl[i] = tlcapnhat;
                                    dem++;
                                }
                            }
                            if(dem == 0)
							{
								cout<<"Khong co nhan vien can cap nhat co ma "<<mnv<<" trong danh sach\n";
							}
                            else
							{
								cout<<"Da cap nhat xong nhan vien co ma "<<mnv<<" trong danh sach\n";
							}
							break;
						}                    				
					case 3:
					    {
					    	tim_nhanvien();
					    	break;
						}					
                    case 4:
						{
							if (n == 0)
							{
								cout<<"Khong ton tai nhan vien nao!"<<endl;
							}
							else
							{
								cout<<"\t\tThong vien tat ca nhan vien\n";
								for(int i=0;i<n;i++){
									cout<<"\tNhan vien thu "<<i+1<<endl;
									cout<<nv[i];
									for(int j = 0; j < n; j++)
									{
										if(strcmp(tl[j].get_manv(), nv[i].get_manv()) == 0) //strcmp : ham so sanh 2 ki tu- ss ma nv trong ds vs ma nv tim kiem
										{
											cout<<tl[j];
										}
									}
								}
							}
							break;
						}
                    case 5:
                        {
                            n = 0;
                            m = 0;
							cout << "Da xoa toan bo thong tin trong danh sach!" << endl;
                            break;
                        }
					case 6:
					    {
					    	cout << "Thoat chuong trinh!!!\n";
                            exit(1);
						}	
                    default :
                        {
                            cout << "Ban chon menu khong dung. Vui long chon lai!" << endl;
                        }
				}
			}
			while(luachon!=6);
		}
};
