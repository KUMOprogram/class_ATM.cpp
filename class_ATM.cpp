#include <iostream>
#include <cstdlib>
using namespace std;

class Account
{
	private:
  		int account_balance;
	public:
		Account(int initial_balance);
		int getbalance() const;
		int credit(int initial_balance);
		int debit(int initial_balance);
};

Account::Account(int initial_balance)
{
	if (initial_balance>=0)
	{
        account_balance=initial_balance;
	}else{
		cout<<" BALANCE NUMBER INVALID"<<endl;
		account_balance=0;
	}
}

int Account::getbalance() const
{
	return account_balance;
}

int Account::credit(int initial_balance)
{
	if (initial_balance>=0)
	{
        	account_balance+=initial_balance;
	}else if (initial_balance<0){
		cout<<" BALANCE NUMBER INVALID"<<endl;
	}
}

int Account::debit(int initial_balance)
{
	if ((initial_balance<=account_balance)&&(initial_balance>=0))
	{
        account_balance-=initial_balance;
		cout<<" ****** SUCCESS ******"<<endl;
	}else if (initial_balance<0){
		cout<<" BALANCE NUMBER INVALID"<<endl;
	}else{
		cout<<" THE DEBIT AMOUNT EXCEEDS THE ACCOUNT'S BALANCE"<<endl;
	}
}

void menu(){
	system("cls");
	cout<<" SHOW CURRENT BALANCE -------- 1"<<endl;
	cout<<" ADD MONEY ------------------- 2"<<endl;
	cout<<" WITHDRAW MONEY -------------- 3"<<endl;
	cout<<" TRANSFER MONEY -------------- 4"<<endl;
	cout<<" CLOSE ----------------------- 0"<<endl;
}

int main()
{
system("color f1");

Account myacc1(20000);
Account myacc2(10000);

while (true)
{
	int select,initial_balance;
	menu();
	cout<<" CHOICE: ";
	cin>>select;
	
	if (select==1)
	{
		cout<<" CURRENT BALANCE: "<<myacc1.getbalance()<<endl;
	}
	
    if (select==2)
	{
		cout<<" HOW MANY MONEY YOU WANT TO ADD: ";
		cin>>initial_balance;
		myacc1.credit(initial_balance);
		cout<<endl;
		cout<<" CURRENT BALANCE: "<<myacc1.getbalance()<<endl;
	}
	
	if (select==3)
	{
		cout<<" HOW MANY MONEY YOU WANT TO WITHDRAW: ";
		cin>>initial_balance;
		myacc1.debit(initial_balance);
		cout<<endl;
		cout<<" CURRENT BALANCE: "<<myacc1.getbalance()<<endl;
	}
	
	if (select==4)
	{
		cout<<" CURRENT BALANCE ACCOUNT 1: "<<myacc1.getbalance()<<endl;
		cout<<" CURRENT BALANCE ACCOUNT 2: "<<myacc2.getbalance()<<endl;
		cout<<endl;
		cout<<" TRANSFER MONEY FROM ACCOUNT1 TO ACCOUNT2: ";
		cin>>initial_balance;
		
		myacc1.debit(initial_balance);
		
		if (myacc1.getbalance()>initial_balance)
		{
			myacc2.credit(initial_balance);
		}
		
		cout<<" CURRENT BALANCE ACCOUNT1: "<<myacc1.getbalance()<<endl;
		cout<<" CURRENT BALANCE ACCOUNT2: "<<myacc2.getbalance()<<endl;
		cout<<endl;
	}
	
	if (select==0)
	{
		cout<<" LOGGOUT SUCCESSFULL"<<endl;
		break;
	}

	if ((select!=0) && (select!=1) && (select!=2) && (select!=3) && (select!=4))
	{
		cout<<" ERROR: WRONG CHOICE"<<endl;
	}
system("pause");
}
system("pause");
}
