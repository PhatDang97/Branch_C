#include <iostream>
#include <math.h>

#include <conio.h>
#include <stdio.h>

using namespace std;
class SoPhuc
{ 
private:
float PhanThuc;
float PhanAo;
public:
SoPhuc();
SoPhuc(float thuc, float ao);
float getPhanThuc();
float getPhanAo();
void NhapSoPhuc();
void XuatSoPhuc();
SoPhuc CongSoPhuc(SoPhuc);
SoPhuc TruSoPhuc(SoPhuc);
SoPhuc NhanSoPhuc(SoPhuc);
SoPhuc ChiaSoPhuc(SoPhuc);
float GTTD();
void SoSanhSP(SoPhuc);
~SoPhuc();

};
SoPhuc::SoPhuc()
{
PhanThuc = 0;
PhanAo = 0;
}
SoPhuc::SoPhuc(float thuc, float ao)
{
PhanThuc = thuc;
PhanAo = ao;
}
float SoPhuc::getPhanThuc()
{
return PhanThuc;
}
float SoPhuc::getPhanAo()
{
return PhanAo;
}
void SoPhuc::NhapSoPhuc()
{
cout << "Nhap phan thuc: "; cin >> PhanThuc;
cout << "Nhap phan ao: "; cin >> PhanAo;
}
void SoPhuc::XuatSoPhuc()
{
if(PhanAo >= 0)
{
cout << PhanThuc << "+" << PhanAo << "i" << endl;

}
else
{
cout << PhanThuc << PhanAo << "i" << endl;
}
}
SoPhuc SoPhuc::CongSoPhuc(SoPhuc sp2)
{
SoPhuc cong;
cong.PhanThuc = PhanThuc + sp2.PhanThuc;
cong.PhanAo = PhanAo + sp2.PhanAo;
return cong;
}
SoPhuc SoPhuc::TruSoPhuc(SoPhuc sp2)
{
SoPhuc tru;
tru.PhanThuc = PhanThuc - sp2.PhanThuc;
tru.PhanAo = PhanAo - sp2.PhanAo;
return tru;
}
SoPhuc SoPhuc::NhanSoPhuc(SoPhuc sp2)
{
SoPhuc nhan;
nhan.PhanThuc = PhanThuc * sp2.PhanThuc - PhanAo * sp2.PhanAo;
nhan.PhanAo = PhanThuc * sp2.PhanAo + PhanAo * sp2.PhanThuc;
return nhan;
}

SoPhuc SoPhuc::ChiaSoPhuc(SoPhuc sp2)
{
SoPhuc chia;
chia.PhanThuc = (PhanThuc * sp2.PhanThuc + PhanAo * sp2.PhanAo) /
(sp2.PhanThuc * sp2.PhanThuc + sp2.PhanAo * sp2.PhanAo);
chia.PhanAo = (PhanAo * sp2.PhanThuc - PhanThuc * sp2.PhanAo);
return chia;
}
float SoPhuc::GTTD()
{
return sqrt(this->getPhanThuc() * this->getPhanThuc()
+ this->getPhanAo() * this->getPhanAo());
}
void SoPhuc::SoSanhSP(SoPhuc sp2)
{
if(this->GTTD() > sp2.GTTD())
{
cout << "So phuc thu 1 lon hon so phuc thu 2." << endl;
}
else if(this->GTTD() < sp2.GTTD())
{
cout << "So Phuc thu 1 be hon so phuc thu 2." << endl;
}
else
{
cout << "Hai so phuc bang nhau." << endl;
}
}

SoPhuc::~SoPhuc()
{

}
int main()
{
SoPhuc sp1, sp2, tong, hieu, tich, thuong;
cout << "Nhap cac so phuc vua nhap: " << endl;
sp1.NhapSoPhuc();
sp2.NhapSoPhuc();

cout << "Cac so phuc vua nhap: " << endl;
sp1.XuatSoPhuc();
sp2.XuatSoPhuc();

tong = sp1.CongSoPhuc(sp2);
cout << "Tong 2 so phuc vua nhap: "; tong.XuatSoPhuc();

hieu = sp1.TruSoPhuc(sp2);
cout << "Hieu 2 so phuc vua nhap: "; hieu.XuatSoPhuc();

tich = sp1.NhanSoPhuc(sp2);
cout << "Tich 2 so phuc vua nhap: "; tich.XuatSoPhuc();

thuong = sp1.ChiaSoPhuc(sp2);
cout << "Thuong 2 so phuc vua nhap: "; thuong.XuatSoPhuc();

cout << "Gia tri tuyet doi |a+bi| cac so phuc vua nhap: " << endl;

cout << "Gia tri tuyet doi so phuc thu 1: " << sp1.GTTD() << endl;
cout << "Gia tri tuyet doi so phuc thu 2: " << sp2.GTTD() << endl;

cout << "So sanh 2 so phuc vua nhap: " << endl; sp1.SoSanhSP(sp2);
system("pause");
return 0;
}
