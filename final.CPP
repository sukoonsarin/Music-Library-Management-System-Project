/***************************
 Developers : Sukoon Sarin, Sahil Lamba
 Project Name : Music Library Management System
 ***************************/


#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
#include<string.h>

class music
{
public:
int cd_code;
char cd_name[30];
int no_of_copies;
float cost;


void inputdata();
void outputdata();
void writedata();
void search();
void readdata();
void searchdata();
void deletedata();
void insertdata();
void adddata();
void modifydata();
};

void music :: inputdata()
  {
  cout <<"\n\nEnter CD Code:";
  cin >> cd_code;
  cout <<"\nEnter CD name:";
gets(cd_name);
cout << "\nEnter number of copies: ";
cin >> no_of_copies;
cout << "\nEnter cost :Rs";
cin >> cost;
}

void music :: outputdata()
{
cout << "\n\n\tCD Code\t\t==>"<<cd_code;
cout << "\n\tCD Name\t\t:: "<< cd_name;
cout << "\n\tNumber of copies\t:" << no_of_copies;
cout <<"\n\tCost = Rs. " <<cost;
cout << "\n\n---------------------------------------------\n\n\n";
}

void music:: writedata()
{
clrscr();
music m[10];
ofstream onfile("music.dat", ios::binary | ios::app);
int n,i,f=0;
cout << "\t\t\t!!!!CD INFORMATION!!!!!";
cout << "\n\nEnter total number of enteries ::";
cin >> n;
for (i = 0; i<n; i++)
{
m[i].inputdata();

if(f==1)
cout << "\n\t\t\tNot Possible:";
else
onfile.write((char*)&m[i], sizeof(m[i]));
}
onfile.close();
}

void music :: readdata()
{
clrscr();
music m;
ifstream infile ("music.dat", ios::binary);
if(!infile)
cout << "\n\t\tFile does not exist";
else
{
infile.read ( (char*) & m, sizeof(m));
cout<<"\n\t\t!!!CD INFORMATION!!!";
while (infile)
{
m.outputdata();
infile.read ( (char*)&m, sizeof(m));
}// while
infile.close();
} // else
}

void music:: search()
{
clrscr();
music m;
int f=0;
char N[30];
ifstream infile("music.dat", ios::binary);
cout <<"\n\n\n\n\tEnter any CD name to be searched \t:";
gets(N);
if(!infile)
cout << "\n\t\t\tFile does not exist";
else
{
infile.read ((char*)&m, sizeof(music));
while (infile)
{
if(cd_code==m.cd_code)
f++;
infile.read( (char *)&m, sizeof(music) );
} // while
infile.close();
} //else
   }
void music :: searchdata()
{
clrscr();
music m;
int f=0;
char N[30];
ifstream infile ("music.dat", ios::binary);
cout << "\t\t\t!!!CD INFORMATION SEARCH!!!";
cout << "\n\n\n\n\tEnter any CD name to be searched\t:";
gets(N);
if(!infile)
cout<<"\n\t\t\tFile does not exist....";
else
{
infile.read ((char*)&m,sizeof(music));
while (infile)
{
if(strcmpi(N, m.cd_name) == 0)
{
m.outputdata();
f++;	
}// if
infile.read ((char*)&m, sizeof(music)); 
}// while
if (f==0)
cout<<"\n\n\tCD name does not exist."; 
}// else	
infile.close();
}

void music :: deletedata()
{clrscr();
music m;
int f=0;
char N[30];
ifstream infile ("music.dat", ios::binary); 
ofstream onfile ("temp. dat", ios::binary);
cout<<"t\t\t!!!CD INFORMATION DELETION!!!";
cout<<"\n\n\n\tEnter any CD name to be deleted\t:"; 
gets(N);
if (!infile)
cout<<"\n\n\tFile does not exist";
else
{
infile.read ((char*)&m, sizeof(music) );
while(infile)
{
if(strcmpi(N, m.cd_name)==0)
{
m.outputdata();
f++;
cout<<"\t\t\t\tlnformation deleted";
} // if
else
onfile.write ( (char*)&m, sizeof(music));
infile.read((char*)&m,sizeof(music));	
}// while
}// else 
if( f == 0)
cout << "\n\n\n\n\tCD Information does not exist….";
onfile.close();
infile.close();
remove("music.dat");
rename("temp.dat", "music.dat");
}

void music :: insertdata()
{ 
clrscr();
music m1,m2;
int f=0;
ifstream infile ("music.dat",ios::binary);
ofstream onfile ("temp.dat", ios::binary);
if(!infile)
cout<<"\n\n\t\t\tFile does not exist……..";
else
{
cout <<"\t\t\t! ! !CD INFORMATION INSERTION!!!";
infile.read((char*)&m1,sizeof(m1));
m1.inputdata();
while((infile)&& f==0)
{
if(m1.cd_code < m2.cd_code)
{
onfile.write ((char*)&m1, sizeof(music));
f = 1;
}//if
else
{
onfile.write ((char*)&m2, sizeof(music));
infile.read ((char*)&m2, sizeof(music));
} // else
}// while
if (f == 1)
{
while (infile)
{
onfile.write ((char*)&m2 , sizeof(music));
infile.read ((char*)&m2, sizeof(music));
}// while
}// if
else	
onfile.write ((char*)&m1, sizeof(music)); 
}// else
infile.close();
onfile.close();
remove("music.dat");
rename("temp.dat", "music.dat");
}


void music::adddata()
{
clrscr();
ofstream onfile ("music.dat", ios::binary | ios::app); 
music m;
char c;
cout <<"\t\t\t!!!CD INFORMATION ADDITION!!!"; 
m.inputdata();
onfile.write ((char*)&m, sizeof(music));
onfile.close();
}
void music :: modifydata()
{
clrscr();
music m;
int f = 0;
char N[30];
ifstream infile ("music.dat",ios::binary);
ofstream onfile ("temp.dat", ios::binary); 
if(!infile)
cout<<"\n\t\t\tFile does not exist"; 
else
{
cout <<"\t\t\t!!! CD INFORMATION MODIFICATION!!!";
cout <<"\n\n\n\tEnter any CD name to be modified\t:";
gets(N);
infile.read((char*)&m, sizeof(music));
while (infile)
{
if(strcmpi(N,m.cd_name)==0)
{
f=1;
m.outputdata();
m.inputdata();
}// if
onfile.write ((char*)&m, sizeof(music));
infile.read ((char*)&m, sizeof(music)); 
} // while
if(f == 0)
cout <<"\n\n\n\n\tCD name does not exist "; 
onfile.close();
infile.close();
remove("music.dat");
rename("temp.dat", "music.dat");
} // else
}

class customer
	{
	public:
		 int cust_code;
		 char cust_name[30];
		 char cust_sex[30];
		 char address[30];
		 char ph_no[16];

		 void inputdata();
		 void outputdata();
		 void writedata();
		 void readdata();
		 void searchdata();
		 void deletedata();
		 void insertdata();
		 void adddata();
		 void search();
		 void modifydata();
		 void cal_bill();

	};

void customer :: inputdata()
	{
	cout<<"\n\n\tEnter customer code\t:";
	cin>>cust_code;
	cout<<"\n\tEnter customer name\t:";
	gets(cust_name);
	cout<<"\n\tEnter sex\t\t:";
	gets(cust_sex);
	cout<<"\n\tEnter address\t\t:";
	gets(address);
	cout<<"\n\tEnter phone number\t:";
	gets(ph_no);
	}

void customer :: outputdata()
	{
	cout<<"\n\n\tCustomer code\t--"<<cust_code;
	cout<<"\n\tCustomer name\t::"<<cust_name;
	cout<<"\nSex\t\t::"<<cust_sex;
	cout<<"\n\tAddress\t::"<<address;
	cout<<"\n\tPhone number\t-->"<<ph_no;
	}

void customer::writedata()
	{
	clrscr();
	customer c[10];
	ofstream onfile("customer.dat",ios::binary);
	int n,i;
	cout<<"\t\t\t!!!CUSTOMER INFORMATION!!!";
	cout<<"\n\n\tEnter total number of entries\t::";
	cin>>n;
	for(i=0;i<n;++i)
		{
	c[i].inputdata();
	int f=0;
	if(f==1)
		cout<<"\t\tNot possible";
	else
		onfile.write((char*)&c[i],sizeof(c[i]));
		}//for
	onfile.close();
	}

void customer::readdata()
	{
	clrscr();
	customer c;
	ifstream infile("customer.dat",ios::binary);
	if(!infile)
		cout<<"\n\n\t\t\tFile does not exist";
	else
		{
		cout<<"\t\t\t!!!CUSTOMER INFORMATION!!!";
		infile.read((char*)&c,sizeof(customer));
		while(infile)
	{
	c.outputdata();
	infile.read((char*)&c,sizeof(customer));
	}// while
		infile.close();
		}// else
	}

void customer::search()
	{
	clrscr();
	customer c;
	int f=0;
	char N[30];
	ifstream infile("cutomer.dat", ios::binary);
	cout<<"\t\t\t!!!CUSTOMER INFORMATION SEARCH!!!";
	cout<<"\n\nEnter any customer name to be searched:";
	gets(N);
	if(!infile)
		cout<<"\n\t\tFile does not exist";
	else
	{
	infile.read((char*)&c,sizeof(customer));
	while(infile)
	{
	if(cust_code==c.cust_code)
	f++;
	infile.read((char*)&c,sizeof(customer));
	}// while

		}// else
	infile.close();
	}

void customer :: searchdata()
	{
	clrscr();
	customer c;
	int f = 0;
	char N[30];
	ifstream infile ("customer.dat",ios::binary);
	cout<< "\t\t\t!!!CUSTOMER INFORMATION SEARCH!!!";
	cout<< "\nEnter any customer name to be searched : ";
	gets(N);
	if (! infile)
		   cout << "\n\n\t\t\tFile does not exist.";
	else
		   {
		    infile.read((char*)&c, sizeof(customer));
		    while (infile)
	{
	if (strcmpi (N, c.cust_name) ==0)
	           {
	            c.outputdata();
	             f++;
	             } // if
	infile.read( (char*) & c, sizeof(customer) );
	} // while
 	            if(f == 0)
	cout<<"\n\t\t\tCustomer name does not exist.";
	           } // else
	infile.close();
	}

void customer :: deletedata()
	{
	clrscr();
	customer c;
	int f = 0;
	char N[30];
	ifstream infile ("customer.dat",ios::binary);
	ofstream onfile ("temp.dat", ios::binary);
	cout<<"\t\t\t!!!CUSTOMER INFORMATION DELETION!!!";
	cout<<"\nEnter any customer name to be deleted :";
	gets(N);
	if (!infile)
	         cout << "\t\tFile does not exist.";
	else
	         {
	         infile.read( (char*) & c, sizeof(customer) );
	         while (infile)
	{
	if (strcmpi (N,c.cust_name) == 0)
	         {
	         c.outputdata();
	         f++;
	         cout<<"\n\nInformation deleted";
	         } // if
	else
	         onfile.write( (char*) & c, sizeof(customer) );
	infile.read( (char*) & c, sizeof(customer) );
	} // while
	         } // else
	if (f == 0)
	          cout<<"\n\t\t\tCustomer name does not exist";
	onfile.close();
	infile.close();
	remove("customer.dat");
	rename("temp.dat", "customer.dat");
	}

void customer :: insertdata()
	{
	clrscr();
	customer c1,c2;
	int f = 0;
	ifstream infile ("customer.dat", ios::binary);
	ofstream onfile ("temp.dat", ios::binary);
	if (!infile)
	          cout<<"\t\t\tFile does not exist";
	else
	          {
	          cout << "\t\t\t!!!CUSTOMER INFORMATION INSERTION!!!";
	          infile.read( (char*) & c2,sizeof(customer) );
	          c1.inputdata();
	          while ((infile)&&(f == 0))
	{
	if (c1.cust_code < c2.cust_code)
	          {
	          onfile.write((char*) & c1,sizeof(customer));
	          f = 1;
	          } // if
	else
	          {
	          onfile.write( (char*) & c2, sizeof(customer) );
	          infile.read( (char*) & c2, sizeof(customer) );
	          } // else
	} // while
	         if ( f == 1)
	while (infile)
	        {
	        infile.read( (char*) & c2, sizeof(customer) );
	        } // while
	        onfile.write( (char*) & c1, sizeof(customer) );
	        } // else
	infile.close();
	onfile.close();
	remove ("customer.dat");
	rename ("temp.dat", "customer.dat");
	}

void customer :: adddata()
	{
	clrscr();
	ofstream onfile ("customer.dat", ios::binary | ios::app);
	customer c;
	char c1;
	cout << "\t\t\t!!!CUSTOMER INFORMATION ADDITION!!!";
	c.inputdata();
	onfile.write( (char*) & c, sizeof(customer) );
	onfile.close();
	}

void customer :: modifydata()
	{
	clrscr();
	customer c;
	int f = 0;
	char N[30];
	ofstream onfile ("temp.dat",ios::binary);
	ifstream infile ("customer.dat", ios::binary);
	if (!infile)
	          cout << "\n\t\t\tFile does not exist";
	else
	          {
	          cout << "\t\t\t!!!CUSTOMER INFORMATION MODIFICATION!!!";
	          cout << "\n\n\tEnter the customer name to be modified\t:: ";
	          gets(N);
	          infile.read( (char*) & c,sizeof(customer) );
	          while (infile)
	{
	if (strcmpi (N, c.cust_name) == 0)
	          {
	          f = 1;
	          c.outputdata();
	          c.inputdata();
	         } // if
	onfile.write ( (char*) & c,sizeof(customer) );
	infile.read ( (char*) & c,sizeof(customer) );
	} // while
	         if ( f==0)
	cout << "\n\t\t\tCustomer name does not exist";
	         onfile.close();
	          infile.close();
	          remove ("customer.dat");
	          rename ("temp.dat", "customer.dat");
	          } // else
	}

void welcome_screen()
	{
	cout << endl<< endl<< endl << endl;
	cout << "\t	SARAMBA  MUSIC STORE\t\t\t\t\n\n";
	cout << "\t                WHERE MUSIC COMES ALIVE.........";
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t DEVELOPED BY :: \n";
	cout <<"\t\t\t\t\t\t\tSUKOON SARIN\n\t\t\t\t\t\t\tSAHIL LAMBA";
	cout << "\n----------------------------------------------------\n";
	cout << "\n\n\t\t\t\t\t\t\tContinue..................";
	getch();
	clrscr();
	} // welcome_screen()

void end_screen()
	{
	clrscr();
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\tSARAMBA MUSIC STORE\n\n\n";
	cout << "\t\t\tTHANK YOU FOR VISITING....!!!!\n\n\n\n";
	cout << "\t\t\t\tHAVE A NICE DAY.....!!!\n\n";
	cout << "\n----------------------------------------------------\n";
	exit(0);
	} // end_screen()

void u_want()
	{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\tSARAMBA MUSIC STORE\n\n\n";
	cout << "\t\tWHAT DO YOU WANT???\n";
	cout << "\t\t\t1.CD INFORMATION\n";
	cout << "\t\t\t2.CUSTOMER INFORMATION\n";
	cout << "\t\t\t3.BILLING INFORMATION\n";
	cout << "\t\t\t4.EXIT THE PROGRAME\n\n";
	cout << "\n----------------------------------------------------\n";
	} // u_want()

void customer :: cal_bill()
	{
	char cname[20];
	int f = 0, f1 = 0, i, n;
	float cost[20];
	char a[20][30];
	customer C,c1;
	music M;
	clrscr();
	L11 : cout <<"\n\t\t\t\t!!!BILLING!!!";
	cout <<"\n\n\n\t\tEnter Customer Name\t::";
	gets(cname);
	ifstream infile1 ("Customer.dat",ios::binary);
	if(!infile1)
		  cout << "\n\t\t\tCustomer file does not exist!!";
	else
		  {
	while ((infile1)&&(f == 0))
		  {
		  infile1.read( (char*) & c1,sizeof(c1) );
		  if (strcmpi(cname,c1.cust_name) == 0)
		{
		  C =c1;
		  f =1;
		} // if
		  } // while
	if ( f == 0)
		 {
		 cout << "\n\n\t Customer does not exist";
		  goto L11;
		  } // if
		   } // else
	infile1.close();
	ifstream infile2("music.dat", ios::binary | ios::in);
	if (!infile2)
		  cout<<"\n\n\t\t\tCD File does not exist";
	else
		   {
		   cout <<"\n\n\n\tEnter the number of CDs you want to buy : ";
		   cin >> n;
		   cout <<"\n\tEnter all the records one by one : ";
		   for (int i = 0; i < n; ++i)
	{
	L1:cout <<"\n\n\t Enter CD's name : ";
	cin >> a[i];
	f1 = 0;
	infile2.seekg(0, ios::beg);
	infile2.read( (char*)&M, sizeof(M) );
	while ((infile2)&&(f1 == 0))
		    {
		    if (strcmpi (a[i], M.cd_name)==0)
		    {
		   strcpy (a[i], M.cd_name);
		   cost[i] = M.cost;
		   f1 = 1;
		   } // if
		      infile2.read( (char*) & M, sizeof(M) );
		      } // while
	if ( f1==0)
		     {
		     cout << "\n\t\t\tCD does not exist";
		      goto L1;
		     } // if
	} // for
		     clrscr();
		      float total = 0;
		     cout <<"\n----------------------------------------------------------------\n";
		     cout <<"\n\n\n\n\t\tSARAMBA MUSIC STORE\n\n";
		     cout <<"\n----------------------------------------------------------------\n";
		     cout <<"\tCustomer Name : " << C.cust_name;
		     cout <<"\tCustomer Address : " << C.address;
		     cout <<"\n----------------------------------------------------------------\n";
		     for (i = 0; i < n; ++i)
	{
	cout <<"\n\tSerial Number : " <<(i + 1);
	cout <<"\n\tCD Name : " << a[i];
	cout <<" \n\tCD Cost => Rs. " << cost[i];
	total += cost[i];
	cout <<"\n\n-----------------------------------------------------------------\n";
	cout <<" \n\tTotal Cost ==> RS. " << total;
	cout <<"\n-----------------------------------------------------------------\n";
	} // for
		      cout <<"\n\n\n\t\t\tPRESS ENTER TO CONTINUE........";
		      getch();
		      end_screen();

		     } // else
	} // cal_bill()

void main()
	{
	welcome_screen();
	music M;
	customer C;
	int choice, c2, c3;
	L1 : do
		     {
		     u_want();
		     cout <<"\n\n Please Enter your choice---> ";
		     cin >> choice;
		     switch (choice)
	{
		    case 1:
		    L2:  do
			{
			clrscr();
			 cout <<"\n\n\n\n\tNOW YOU WANT TO\t :- ";
			cout <<"\n\t\t 1.WRITE INFORMATION IN THE FILE";
			cout <<"\n\t\t 2.READ INFORMATION FROM THE FILE";
			cout <<"\n\t\t 3.SEARCH INFORMATION";
			cout <<"\n\t\t 4.DELET INFORMATION";
			cout << "\n\t\t 5.INSERT INFORMATION";
			cout << "\n\t\t 6.ADD INFORMATION";
			cout << "\n\t\t7.MODIFY INFORMATION";
			cout << "\n\t\t 8.GO BACK TO MAIN MENU";
			cout << "\n\n\n\n\n\n\tENTER YOUR CHOICE ===>";
			cin >> c2;

		       switch (c2)
			{
			case 1:
				M.writedata();
				cout<<"\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 2:
				M.readdata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 3:
				M.searchdata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 4:
				M.deletedata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 5:
				M.insertdata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch;
				break;
			case 6:
				M.adddata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 7:
				M.modifydata();
				cout << "\n\n\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				goto L2;

			case 8:
				clrscr();
				goto L1;

			default:
				cout << "\n\n\n\n\n\t\t\tINVAID OPTION";
			} // switch
		       } // do
		while (c2 != 8);

		case 2:
			   do
			      {
			       clrscr();
			       cout << "\n\n\n\n\tDO YOU WANT TO :-";
			       cout << "\n\t\t 1.WRITE INFORMATION IN THE FILE";
			       cout << "\n\t\t 2.READ INFORMATION FROM THE FILE";
			       cout << "\n\t\t 3.SEARCH INFORMATION";
			       cout << "\n\t\t 4.DELETE INFORMATION";
			       cout << "\n\t\t 5.INSERT INFORMATION";
			       cout << "\n\t\t 6.ADD INFORMATION";
			       cout << "\n\t\t 7.MODIFY INFORMATION";
				       cout << "\n\t\t 8.GO BACK TO MAIN MENU";
			       cout << "\n\n\n\n\n\n\tENTER YOUR CHOICE--->>";
			       cin >> c3;

			       switch (c3)
			{
			case 1:
				C.writedata();
				cout<<"\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 2:
				C.readdata();
				cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 3:
				C.searchdata();
				cout<<"\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 4:
				C.deletedata();
				cout<<"\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 5:
				C.insertdata();
				cout<<"\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 6:
				C.adddata();
				cout<<"\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 7:
				C.modifydata();
				cout<<"\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE";
				getch();
				break;
			case 8:
				clrscr();
				goto L1;
			default:
				cout<<"\n\n\n\n\t\t\t\tINVALID OPTION";
				cout << "\t\tENTER ANY KEY TO CONTINUE....";
				getch();
				}// switch
				}//do
				while(c2 !=8);
				break;
			case 3:
				C.cal_bill();
				break;

			case 4:
				end_screen();

			} // switch
				 } // do
			while (choice > 5);
			} // main()


























































