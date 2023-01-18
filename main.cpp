#include <iostream>
#include <Windows.h>
using namespace std;

enum EnOptions{CheckAccount=1,WithDrawCash=2,DepositeCash=3,Quit=4};
enum EnBack{Back=1};
const unsigned short  ConstPIN = 1234;

//Line
void Line()
{
	for (int i = 0; i <= 41; i++)
	{
		cout << "*";
	}

}



//edit menu
void checkAccount(EnOptions Menu, float Balance)
{

	if (Menu == ::CheckAccount)
	{
		system("cls");
		EnBack Back;
		unsigned short choice;
		cout << "Your Currenty Balance: $" << Balance << endl<<endl;
		system("Pause");
	}
}

void withDraw(EnOptions Menu, float& Balance)
{
	float amount;
	if (Menu == ::WithDrawCash)
	{
		system("cls");
		EnBack Back;
		unsigned short choice;

		
		cout << "Enter the amount to withdraw: $";
		cin >> amount;

		Balance = Balance - amount;
		system("cls");
		cout << "Your current balance: $" << Balance << endl;
		system("Pause");
	}
}

void desposite(EnOptions Menu, float& Balance)
{
	float amount;
	if (Menu == ::DepositeCash)
	{
		system("cls");
		cout <<"Enter the amount to desposite: $";
		cin >> amount;

		Balance = Balance + amount;
		system("cls");
		cout << "Your current balance: $" << Balance << endl;
		system("Pause");
	}
}



//Options
void Options(EnOptions& Menu)
{

	unsigned short option;
	float Balance = 1000;
	while (Menu != ::Quit)
	{
		system("cls");

		cout << "1) Check Your Account" << endl;
		cout << "2) Withdraw Cash" << endl;
		cout << "3) Deposite Cash" << endl;
		cout << "4) Quit" << endl;

		cout << "Choose from the menu: ";
		cin >> option;

		Menu = (EnOptions)option;

		checkAccount(Menu, Balance);
		withDraw(Menu, Balance);
		desposite(Menu, Balance);
	}

	if (Menu == ::Quit)
	{
		system("cls");
		system("color 0F");
		Line();
		cout << " Thank you for using our service ";
		Line();
		cout << endl;
	}

}


//Enter pin
void PIN(unsigned short &Pin, EnOptions &Menu)
{
	cout << "Enter your PIN " << endl;
	cin >> Pin;
	unsigned short count = 0;
	while (Pin != :: ConstPIN)
	{
		Sleep(50);
		count++;
		system("cls");
		system("color 4F");
		system("color 0F");

		if (count == 4)
		{
			cout << "Your card have been locked....!" << endl;
			break;
		}

		cout <<"INVALID PIN.....";
		cout <<endl <<"Enter your PIN " << endl;
		cin >> Pin;
		
	}
	if (Pin == ::ConstPIN)
	{
		system("cls");
		system("color 2F");
		system("color 1F");
		Options(Menu);
	}
}



int main()
{
	unsigned short Pin;
	EnOptions Menu;

	Line();
	cout << " Welcome To Our Service ";
	Line();
	cout << endl;


	PIN(Pin,Menu);
}