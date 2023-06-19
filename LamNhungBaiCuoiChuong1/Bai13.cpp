#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* link;
};
Node* first;
void init() {
	first = NULL;
}
void processList() {
	Node* p = first;
	if (first != NULL) {
		do {
			cout << p->info << " ";
			p = p->link;
		} while (p != first);
		cout << endl;
	}
}
void insert_first(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = first;
	Node* q = first;
	if (q != NULL) {
		while (q->link != first) {
			q = q->link;
		}
		q->link = p;
	}
	else
		p->link = p;
	first = p;
}
void insert_last(int x) {
	Node* p = new Node;
	p->info = x;
	p->link = first;
	Node* q = first;
	if (q != NULL) {
		while (q->link != first) {
			q = q->link;
		}
		q->link = p;
	}
	else
	{
		p->link = p;
		first = p;
	}
}
int delete_first() {
	Node* p = first;
	if (p != NULL) {
		Node* q = first;
		while (q->link != first)
			q = q->link;
		if (p != q) {
			first = first->link;
			q->link = first;
		}
		else {
			first = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

int delete_last() {
	Node* p = first;
	if (first != NULL) {
		Node* q = p;
		while (p->link != first) {
			q = p;
			p = p->link;
		}
		if (p != q) {
			q->link = first;
		}
		else {
			first = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

int find_and_delete(int x) {
	if (first != NULL) {
		Node* p = first;
		while (p->link != first && p->info != x) {
			p = p->link;
		}
		if (p->info == x) {
			Node* q = first;
			while (q->link != p) {
				q = q->link;
			}
			if (q != p) {
				q->link = p->link;
			}
			else
			{
				first = NULL;
			}
			delete p;
			return 1;
		}
		else {
			return 0;
		}
	}
	return 0;
}
int main1() {
	int x, chon, t;
	init();
	while (true) {
		cout << endl;
		cout << "0.Thoat chuong trinh \n";
		cout << "1.Them dau dslk vong \n";
		cout << "2.Them cuoi dslk vong \n";
		cout << "3.Xoa dau dslk vong \n";
		cout << "4.Xoa cuoi dslk vong \n";
		cout << "5. Xem danh sach \n";
		cout << "6. Tim thay va xoa \n";
		cout << "Xin moi chon:";
		cin >> chon;
		switch (chon) {
		case 0:
			return 0;
		case 1:
			cout << "xin moi nhap gia tri can them dau:";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them :";
			processList();
			break;
		case 2:
			cout << "xin moi nhap gia tri can them cuoi:";
			cin >> x;
			insert_last(x);
			cout << "Danh sach sau khi them :";
			processList();
			break;
		case 3:
			t = delete_first();
			if (t != 1) {
				cout << "Xoa that bai! \n";
			}
			else {
				cout << "Xoa thanh cong \n";
				cout << "Danh sach sau khi xoa :";
				processList();
			}
			break;
		case 4:
			t = delete_last();
			if (t != 1) {
				cout << "Xoa that bai! \n";
			}
			else {
				cout << "Xoa thanh cong \n";
				cout << "Danh sach sau khi xoa :";
				processList();
			}
			break;
		case 5:
			processList();
			break;
		case 6:
			cout << "Nhap gia tri phan tu ma ban muon xoa:";
			cin >> x;
			t = find_and_delete(x);
			if (t != 1) {
				cout << "Xoa that bai vi danh sach rong hoac khong tim thay duoc phan tu! \n";
			}
			else {
				cout << "Xoa thanh cong \n";
				cout << "Danh sach sau khi xoa :";
				processList();
			}
			break;
		}
	}
}