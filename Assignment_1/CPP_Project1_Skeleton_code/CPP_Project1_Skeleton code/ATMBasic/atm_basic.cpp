#include <iostream>
#include <string>
using namespace std;

string account_number;
int menu_option;
int withdraw_option;
float deposit_amount;
char welcome_option;
float balance_amount = 5000000;

// Function declarations
void Welcome();
void ShowMenu();
void CheckBalance();
void Withdraw();
void Deposit();
void Eject();

int main()
{
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "--Vui long dua the ATM vao--" << endl;
	system("pause");
	cout.precision(9);
	Welcome();
	system("pause");
	return 0;
}

// Hien thi thong diep welcome va
// yeu cau nguoi dung nhap vao tai khoan giao dich
void Welcome() {
	system("cls");
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "Da nhan duoc the, vui long nhap tai khoan giao dich:" << endl;

	cin >> account_number;
	cout << "Tai khoan: " << account_number << endl;
	cout << "Ban co muon nhap lai tai khoan khong (y/n)" << endl;
	cin >> welcome_option;
	system("cls");


	while (1) {
		if (welcome_option != 'n' && welcome_option != 'y'){	
			system("cls");
			cout << "Ban co muon nhap lai tai khoan khong. Vui long nhap 'y' hoac 'n'" << endl;
			cin >> welcome_option;
			continue;
		}
		if (welcome_option == 'y') {
			system("cls");
			cout << "So tai khoan da nhap: " << account_number <<endl;
			cout << "Vui long nhap lai" << endl;
			cin >> account_number;
			cout << "Tai khoan: " << account_number << endl;
			break;
		} else {
			break;
		}
	}

	ShowMenu();
}

// Hien thi menu voi 4 chuc nang
void ShowMenu() {
	do {
		system("cls");
		cout << "1. Tra cuu so du" << endl;
		cout << "2. Rut tien" << endl;
		cout << "3. Nap tien" << endl;
		cout << "4. Ngung gia dich" << endl;
		cout << "Vui long chon menu(tu 1 den 4):" << endl;

		cin >> menu_option;
	} while (menu_option < 1 || menu_option>4);

	switch (menu_option) {
	case 1:
		CheckBalance();
		break;
	case 2:
		Withdraw();
		break;
	case 3:
		Deposit();
		break;
	case 4:
		Eject();
	}
}

// Tra cuu so du
void CheckBalance()
{
	system("cls");
	cout << "Tai khoan: " << account_number << endl;
	cout << "So du: " << balance_amount << endl;
	system("pause");
	ShowMenu();
}

// Rut tien trong tai khoan
void Withdraw()
{
	system("cls");
	do {
		cout << "--RUT TIEN--" << endl;
		cout << "1. 50000 (nam muoi nghin dong)\n" << endl;
		cout << "2. 100000 (mot tram nghin dong)\n" << endl;
		cout << "3. 200000 (hai tram nghin dong)\n" << endl;
		cout << "4. 500000 (nam tram nghin dong)\n" << endl;
		cout << "5. 1000000 (mot trieu dong)\n" << endl;
		cout << "6. 2000000 (hai trieu dong)\n" << endl;
		cout << "7. Thoat ve man hinh chinh" << endl;
		cin >> withdraw_option;
		cout << endl;
	} while (withdraw_option < 1 || withdraw_option>7);


	int withdraw_amount = 0; // So tien muon rut
	switch (withdraw_option) {
		case 1:
			withdraw_amount = 50000;
			break;
		case 2:
			withdraw_amount = 100000;
			break;
		case 3:
			withdraw_amount = 200000;
			break;
		case 4:
			withdraw_amount = 500000;
			break;
		case 5:
			withdraw_amount = 1000000;
			break;
		case 6:
			withdraw_amount = 2000000;
			break;
		case 7:
			cout << "\nVe man hinh chinh..." << endl;
			system("pause");
			ShowMenu();
			return;
	}
	if (balance_amount < withdraw_amount) {
		cout << "So du khong du, giao dich khong the tiep tuc" << endl;;
	} else {
		balance_amount -= withdraw_amount;
		cout << "Rut " << withdraw_amount << " tu:" << endl;
		cout << "So tai khoan: " << account_number << endl;
		cout << "So du hien tai :" << balance_amount << endl;

		cout << "Vui long nhan lai the ATM va kiem tra tien truoc khi di" << endl;
	}


	system("pause");
	ShowMenu();
}


// Nap tien vao tai khoan
void Deposit()
{
	system("cls");
	cout << "Nap tien" << endl;
	float charged = 0;
	cin >> charged;
	balance_amount += charged;
	cout << "\nNap: " << charged << " vao tai khoan: " << account_number << endl;
	cout << "\nSo du hien tai: " << balance_amount << endl << endl;
	cout << endl;
	system("pause");
	ShowMenu();
}

// Ngung giao dich
void Eject()
{
	system("cls");
	cout << "--ATM C++--" << endl;
	cout << "\nKet thuc..." << endl;
	cout << "\nVui long nhan the va tien o khe cam" << endl;
	cout << "\nCam on quy khach da su dung dich vu tai ATM C++" << endl;
}
