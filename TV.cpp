#include<iostream>
#include<string.h>

using namespace std;

class Television
{
	public:
	char model_number[10];
	float screen_s,price;
	friend ostream &operator >> (ostream &,Television &T);
	friend istream &operator << (istream &,Television &T);
	void display();
	Television()
	{
		strcpy(model_number,"\0");
		screen_s=price=0;
	}
void initzero()
	{
		strcpy(model_number,"0");
		screen_s=price=0;
	}
};
istream &operator >> (istream &get,Television &T)
	{
		cout<<"\n Enter the model number \n";
		cin>>T.model_number;
		cout<<"\n Enter the screen size \n";
		cin>>T.screen_s;
		cout<<"\n Enter the price of the television \n";
		cin>>T.price;
	}
ostream &operator << (ostream &put,Television &T)
	{
		int ls=strlen(T.model_number);
		try
			{
				if(1>4)
					throw 1;
				if(T.screen_s<12 || T.screen_s>70)
					throw 2;
				if(T.price<0 || T.price>5000)
					throw 3;
				else
					T.display();
			}
	catch(int i)
		{
			cout<<"\n EXCEPTION OCCURED";
			int flag=0;
			switch (i)
			{
				case 1:
		cout<<"MODEL NUMBER SHOULD BE ONLY FOUR DIGITS \n";
					flag=1;
					break;
				case 2:
		cout<<"SCREEN SIZE SHOULD BE BETWEEN 12 AND 70 INCHES \n";
					flag=1;
					break;

				case 3:
		cout<<"PRICE SHOULD BE POSITIVE AND LESS THAN 5000 \n";
					flag=1;
					break;
			}
		if(flag)
			{
				T.initzero();
				T.display();	
			}
		}
	}
void Television::display()
	{
		cout<<"**** TELEVISION DETAILS ****\n";
		cout<<"THE MODEL NUMBER IS \n"<<model_number<<"\n";
		cout<<"THE SCREEN SIZE IS \n"<<screen_s<<"\n";
		cout<<"THE PRICE IS \n"<<price<<"\n";
	}
int main()
	{
		char ch;
		Television T;
		do
		{
			cin>>T;
			cout<<T;
			cout<<"Enter Y or y to continue";
			cin>>ch;
		}while(ch=='Y' || ch=='y');
		return 0;
	}


********************OUTPUT*********************************
[dell@localhost ~]$ g++ TV.cpp
[dell@localhost ~]$ ./a.out

 Enter the model number 
QA41

 Enter the screen size 
32

 Enter the price of the television 
4500
**** TELEVISION DETAILS ****
THE MODEL NUMBER IS 
QA41
THE SCREEN SIZE IS 
32
THE PRICE IS 
4500
Enter Y or y to continuey

 Enter the model number 
QA42

 Enter the screen size 
50

 Enter the price of the television 
6000

 EXCEPTION OCCUREDPRICE SHOULD BE POSITIVE AND LESS THAN 5000 
**** TELEVISION DETAILS ****
THE MODEL NUMBER IS 
0
THE SCREEN SIZE IS 
0
THE PRICE IS 
0
Enter Y or y to continuey

 Enter the model number 
QA43

 Enter the screen size 
25

 Enter the price of the television 
3800
**** TELEVISION DETAILS ****
THE MODEL NUMBER IS 
QA43
THE SCREEN SIZE IS 
25
THE PRICE IS 
3800
Enter Y or y to continuey

 Enter the model number 
QA44

 Enter the screen size 
72

 Enter the price of the television 
2500 

 EXCEPTION OCCUREDSCREEN SIZE SHOULD BE BETWEEN 12 AND 70 INCHES 
**** TELEVISION DETAILS ****
THE MODEL NUMBER IS 
0
THE SCREEN SIZE IS 
0
THE PRICE IS 
0
Enter Y or y to continuey

 Enter the model number 
QA50

 Enter the screen size 
40

 Enter the price of the television 
5000
**** TELEVISION DETAILS ****
THE MODEL NUMBER IS 
QA50
THE SCREEN SIZE IS 
40
THE PRICE IS 
5000
Enter Y or y to continuey

 Enter the model number 






