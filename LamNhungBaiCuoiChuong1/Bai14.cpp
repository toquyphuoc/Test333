#include <iostream>
using namespace std;
#define MAX 100
struct PhanTu {
	int bac;
	int heso;
};
PhanTu DaThuc[MAX];
int n;
void SelecttionSort(PhanTu a[], int n) {
	int min_pos;
	for (int i = 0;i < n;i++) {
		min_pos = i;
		for (int j = i + 1;j < n;j++) {
			if (a[j].bac < a[min_pos].bac) {
				min_pos = j;
			}
		}
		swap(a[min_pos], a[i]);
	}
}
void NhapDaThuc(PhanTu a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap phan tu thu " << i + 1 << " ! \n";
		cout << "Nhap he so:";
		cin >> a[i].heso;
		cout << "Nhap bac cua phan tu:";
		cin >> a[i].bac;
	}
	SelecttionSort(a, n);
}

void XuatDaThuc(PhanTu dathuc[], int n) {
	SelecttionSort(dathuc, n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << dathuc[i].heso << "x^" << dathuc[i].bac;
		}
		else {
			if (dathuc[i].heso >= 0) {
				cout << "+" << dathuc[i].heso << "x^" << dathuc[i].bac;
			}
			else
			{
				cout << dathuc[i].heso << "x^" << dathuc[i].bac;
			}
		}
	}
	cout << endl;

}
void swap(PhanTu a,PhanTu b) {
	PhanTu temp = a; 
	a = b; 
	b = temp;
}


void CongHaiDaThuc(PhanTu dt1[], PhanTu dt2[], int n, int m) {
	PhanTu dtkq[MAX];
	int dem = 0;
	for (int i = dem; i < n; i++) {
		for (int j = dem;j < m;j++) {
			if (dt1[i].bac == dt2[j].bac) {

				dtkq[dem].bac = dt1[i].bac;
				dtkq[dem].heso = dt1[i].heso + dt2[j].heso;

				dem++;
				break;
				
			}

			dtkq[dem].bac = dt1[i].bac;
			dtkq[dem].heso = dt1[i].heso;
			dem++;
			dtkq[dem].bac = dt2[j].bac;
			dtkq[dem].heso = dt2[j].heso;
			dem++;
			
		}
		


	}
	XuatDaThuc(dtkq, dem);
}
void TruHaiDaThuc(PhanTu dt1[], PhanTu dt2[], int n, int m) {
	PhanTu dtkq[MAX];
	int dem = 0;
	if (n > m) {
		for (int i = dem; i < n; i++) {
			for (int j = dem;j < m;j++) {
				if (dt1[i].bac == dt2[j].bac) {

					dtkq[dem].bac = dt1[i].bac;
					dtkq[dem].heso = dt1[i].heso - dt2[j].heso;

					dem++;
					break;

				}

				dtkq[dem].bac = dt1[i].bac;
				dtkq[dem].heso = dt1[i].heso;
				dem++;
				dtkq[dem].bac = dt2[j].bac;
				dtkq[dem].heso = dt2[j].heso;
				dem++;

			}
		}
	}
	else {
		for (int i = dem; i < n; i++) {
			for (int j = dem;j < m;j++) {
				if (dt1[j].bac == dt2[i].bac) {

					dtkq[dem].bac = dt1[j].bac;
					dtkq[dem].heso = dt1[j].heso - dt2[i].heso;

					dem++;
					break;

				}

				dtkq[dem].bac = dt1[j].bac;
				dtkq[dem].heso = dt1[j].heso;
				dem++;
				dtkq[dem].bac = dt2[i].bac;
				dtkq[dem].heso = dt2[i].heso;
				dem++;

			}
		}
	}
		



	
	XuatDaThuc(dtkq, dem);
}
void NhanHaiDaThuc(PhanTu dt1[], PhanTu dt2[], int n, int m) {
	PhanTu dtkq[MAX];
	int tongbac = 0;
	int tongheso = 0;
	int temp = n + m;
	for (int i = 0;i < temp;i++) {
		tongbac =tongbac* dt1[i].bac*dt2[i].bac;
		tongheso =tongheso* dt1[i].heso * dt2[i].heso;
	}
	dtkq[0].bac = tongbac;
	dtkq[0].heso = tongheso;
	XuatDaThuc(dtkq, 1);
}
void ChiaHaiDaThuc(PhanTu dt1[], PhanTu dt2[], int n, int m) {
	PhanTu dtkq[MAX];
	int tongbac = 0;
	int tongheso = 0;
	int temp = n + m;
	for (int i = 0;i < temp;i++) {
		tongbac = tongbac / dt1[i].bac / dt2[i].bac;
		tongheso = tongheso / dt1[i].heso / dt2[i].heso;
	}
	dtkq[0].bac = tongbac;
	dtkq[0].heso = tongheso;
	XuatDaThuc(dtkq, 1);
}
int main() {
	PhanTu DaThuc1[MAX], DaThuc2[MAX];
	NhapDaThuc(DaThuc1, 3);
	NhapDaThuc(DaThuc2, 4);
	XuatDaThuc(DaThuc1, 3);
	XuatDaThuc(DaThuc2, 4);
	cout << "Ket qua cua cong 2 da thuc la:";
	CongHaiDaThuc(DaThuc1, DaThuc2, 3, 4);
	cout << "Ket qua cua tru 2 da thuc la:";
	TruHaiDaThuc(DaThuc1, DaThuc2, 3, 4);
	cout << "Ket qua cua nhan 2 da thuc la:";
	NhanHaiDaThuc(DaThuc1, DaThuc2, 3, 4);
	system("pause");
	return 0;
}