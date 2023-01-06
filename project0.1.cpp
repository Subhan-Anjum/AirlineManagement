#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<fstream>
#include <windows.h>
using namespace std;
int mainn();
int main();
int sec=0;
struct traces{
	int pass,gpass,cpass;
	string location;
	traces *next,*pre;
};
int account=0;
struct reservation{
	int seats,cnic,bill;
	string name,destination,classs,status;
	reservation *next,*pre;
};
struct quee{
	string fno;
	quee *next;
};
quee *qhead=NULL,*qtail=NULL;
void timer()
{
	int m=0,s=10;
    for(;;)
    {
    	if(m==0 && s==0){
    		break;
		}
        if (s == 0)
        {
            s = 60;
            m--;
        }
        system("cls");
        cout<<m<<":"<<s--;
        Sleep(1000);
    }
}
class airportL{
	private:
		quee *head,*tail;
	public:
		airportL(){
			head=NULL;
			tail=NULL;
		}
		void q(string l,string f){
			if(l=="Lahore"){
				quee *temp=new quee;
				temp->fno=f;
				temp->next=NULL;
				if(head==NULL){
					head=temp;
					tail=temp;
				}else{
					tail->next=temp;
					tail=temp;
				}
			}
		}
		void viewquee(){
			quee *temp=head;
			if(head==NULL){
				cout<<"Quee Empty\n";
			}
			while(temp!=NULL){
				cout<<"FN : "<<temp->fno<<endl;
				temp=temp->next;
			}
		}
		void out(string p){
			quee *temp=head;
			if(p==temp->fno && head!=NULL){
				head=temp->next;
				delete temp;
			}
		}
		int getq(){
			if(head!=NULL){
				quee *temp=head;
				if(temp->fno=="f1"){
					return 1;
				}else if(temp->fno=="f2"){
					return 2;
				}else if(temp->fno=="f3"){
					return 3;
				}else if(temp->fno=="f4"){
					return 4;
				}else{
					return 0;
				}	
			}else{
				return 0;
			}
		}
};
airportL air1;
class airplan{
	private:
		string fno,location;
		int seat[171];
		int seatg[27];
		int skip;
		traces *head,*tail;
		reservation *rhead,*rtail;
	public:
		fstream sd;
		airplan(string l,string f){
			for(int x=0;x<171;x++){
				seat[x]=0;
			}
			for(int x=0;x<27;x++){
				seatg[x]=0;
			}
			fno=f;
			location=l;
			skip=0;
			head=NULL;
			tail=NULL;
			rhead=NULL;
			rtail=NULL;
			air1.q(location,fno);
		}
		void msg(int c){
			if(c==1){
				system("CLS");
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                 Economy Reservation                 *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n";
			}else{
				system("CLS");
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                Business Reservation                 *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n";
			}
		}
		void acc(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                    ACCOUNT MENU                     *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
		}
		void srchmsg(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****              Search Reservation Menu                *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
		}
		void map(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                    Map Menu                         *****\n";
			cout<<"\t\t***************************************************************\n\n\n";
		}
		void cnclmsg(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****              Cancel Reservation Menu                *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
		}
		void rlist(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t*****                   RESERVATION LIST                  *****\n";
		    cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t***************************************************************\n\n";
		}
		void take(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t*****                    Takeoff Menu                     *****\n";
		    cout<<"\t\t***************************************************************\n";
		    cout<<"\t\t***************************************************************\n\n";
		}
		void traff(){
			system("CLS");
				cout<<"\t\t****************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                     TRAFFIC Menu                    *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n";
		}
		void rmenu(){
			system("CLS");
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t*****                 RESERVATION SYSTEM                  *****\n";
			cout<<"\t\t***************************************************************\n";
			cout<<"\t\t***************************************************************\n\n\n";
			cout<<"\t\t[1] For Economy Class \n\t\t[2] For Business Class \n\t\t[3] For Back Menu\n\n\t\t:=>";
		}
		void book(){
			reservation *temp=new reservation;
			int l,booking,classs,check=0,request,st=-1,book=0,bill=0,tex=0;
			rstart:
			rmenu();
			cin>>classs;
			if(classs==1){
				temp->classs="E";
			}else if(classs==2){
				temp->classs="G";
			}else if(classs==3){
				goto rend;
			}else{
				cout<<"\t\tEnter Right Option\n\t\t:=>";
				Sleep(1000);
				goto rstart;
			}
			msg(classs);
			cout<<"\t\tHow Many Seats You Want to Reserved\n\n\t\t:=>";
			cin>>booking;
			temp->seats=booking;
			msg(classs);
			cout<<"\t\tEnter Your CNIC NO\n\n\t\t:=>";
			cin>>temp->cnic;
			msg(classs);
			cout<<"\t\tEnter Your Name\n\n\t\t:=>";
			cin>>temp->name;
			msg(classs);
			cout<<"\t\tSelect Your Destination\n";
			cout<<"\t\t[1] For Karachi\n\t\t[2] For Islamabad\n\t\t[3] For Lahore\n\t\t[4] For Sialkot\n\n\t\t:=>";
			cin>>l;
			switch(l){
				case 1:
					temp->destination="Karachi";
					break;
				case 2:
					temp->destination="Islamabad";
					break;
				case 3:
					temp->destination="Lahore";
					break;
				case 4:
					temp->destination="Sialkot";
					break;
			}
			request=booking;
			temp->status="ACTIVE";
			if(classs==1){
				for(int x=0;x<171;x++){
					if(seat[x]==0){
						if(st<0){
							st=x;
						}
						request--;
					}else{
						st=-1;
						request=booking;
					}
					if(request==0){
						check=st+booking;
						for(int z=st;z<check;z++){
							seat[z]=temp->cnic;
						}
						book=1;
						break;
					}
				}
				temp->status="ACTIVE";
				bill=booking*5000;
				tex=(bill/100)*6;
				temp->bill=bill+tex;
				account=account+temp->bill;
				cout<<"\n\n\t\tPLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(300);
				}
				msg(classs);
				cout<<"\t\tTotal seats are : "<<booking<<" Charges per seat '5000'\n\t\t5 Persent tex "<<tex<<"\n\t\tTotal Bill is : "<<temp->bill<<endl;
			}else{
				for(int x=0;x<27;x++){
					if(seatg[x]==0){
						if(st<0){
							st=x;
						}
						request--;
					}else{
						st=-1;
						request=booking;
					}
					if(request==0){
						check=st+booking;
						for(int z=st;z<check;z++){
							seatg[z]=temp->cnic;
						}
						book=1;
						break;
					}
				}
				bill=booking*8000;
				tex=(bill/100)*10;
				temp->bill=bill+tex;
				account=account+temp->bill;
				system("CLS");
				cout<<"\n\n\t\tPLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(300);
				}
				msg(classs);
				cout<<"\t\tTotal seats are : "<<booking<<" Charges per seat '8000'\n\t\t10 Persent tex "<<tex<<"\n\t\tTotal Bill is : "<<temp->bill<<endl;
			}
			if(book!=0){
				cout<<"\t\tBooked\n\t\t";
			}else{
				cout<<"Seats not available\n\t\t";
			}
			temp->next=NULL;
			temp->pre=NULL;
			if(rhead==NULL){
				rhead=temp;
				rtail=temp;
			}else{
				rtail->next=temp;
				temp->pre=rtail;
				rtail=temp;
			}
			sd.open("Booking.txt",ios::app);
			sd<<"Cnic no \t:\t\t"<<temp->cnic<<endl;
			sd<<"Name is \t:\t\t"<<temp->name<<endl;
			sd<<"Seats is \t:\t\t"<<temp->seats<<endl;
			sd<<"Class :\t\t\t\t"<<temp->classs<<endl;
			sd<<"Payment Type\t:\t\t"<<temp->bill<<endl;
			sd<<"Destination is\t:\t\t"<<temp->destination<<endl;
			sd<<"Status :\t\t\t"<<temp->status<<endl;
			sd<<"***********************************************"<<endl;
			sd.close();
			getch();
			system("CLS");
			rend:cout<<"";
		}
		void dis(){
			map();
			cout<<"\n\n\t\tPLEASE WAIT.";
			for(int x=0;x<7;x++){
				cout<<".";
				Sleep(300);
			}
			map();
			int check=0;
			cout<<"\t\t\t    "<<"["<<seat[0]<<"]";
			for(int x=1;x<=170;x++){
				check++;
				if(x%9==0){
					cout<<endl;
					cout<<"\t\t\t";
					check=0;
				}
				if(check%3==0){
					cout<<"    ";
					check=0;
				}
				cout<<"["<<seat[x]<<"]";
			}
			cout<<"\n\n";
			check=0;
			cout<<"\t\t\t    "<<"["<<seatg[0]<<"]";
			for(int x=1;x<=26;x++){
				check++;
				if(x%9==0){
					cout<<endl;
					cout<<"\t\t\t";
					check=0;
				}
				if(check%3==0){
					cout<<"    ";
					check=0;
				}
				cout<<"["<<seatg[x]<<"]";
			}
			cout<<"\n\t\t";
			getch();
			system("CLS");
		}
		int cpcount(){
			int pass=0;
			for(int x=0;x<171;x++){
				if(seat[x]!=0){
					pass++;
				}
			}
			return pass;
		}
		int gpcount(){
			int pass=0;
			for(int x=0;x<27;x++){
				if(seatg[x]!=0){
					pass++;
				}
			}
			return pass;
		}
		int pcount(){
			int pass=0;
			for(int x=0;x<171;x++){
				if(seat[x]!=0){
					pass++;
				}
			}
			for(int x=0;x<27;x++){
				if(seatg[x]!=0){
					pass++;
				}
			}
			return pass;
		}
		void takeoff(){
			traces *temp=new traces;
			int l;
			if(location=="Lahore"){
				air1.out(fno);
			}
			cout<<"\nSET Destination\n";
			cout<<"[1] For Karachi\n[2] For Islamabad\n[3] For Lahore\n[4] For Sialkot\n";
			cin>>l;
			switch(l){
				case 1:
					location="Karachi";
					break;
				case 2:
					location="Islamabad";
					break;
				case 3:
					location="Lahore";
					break;
				case 4:
					location="Sialkot";
					break;
			}
			temp->location=location;
			temp->pass=pcount();
			temp->cpass=cpcount();
			temp->gpass=gpcount();
			temp->next=NULL;
			temp->pre=NULL;
			if(head==NULL){
				head=temp;
				tail=temp;
			}else{
				tail->next=temp;
				temp->pre=tail;
				tail=temp;
			}
			landing();
		}
		void takeoffauto(){
			traces *temp=new traces;
			int l;
			if(location=="Lahore"){
				air1.out(fno);
			}
			if(location=="Lahore"){
				location="Sialkot";
			}else if(location=="Sialkot"){
				location="Karachi";
			}else if(location=="Karachi"){
				location="Islamabad";
			}else if(location=="Islamabad"){
				location="Lahore";
			}
			temp->location=location;
			temp->pass=pcount();
			temp->cpass=cpcount();
			temp->gpass=gpcount();
			temp->next=NULL;
			temp->pre=NULL;
			if(head==NULL){
				head=temp;
				tail=temp;
			}else{
				tail->next=temp;
				temp->pre=tail;
				tail=temp;
			}
			landing();
		}
		void landing(){
			reservation *temp=rhead,*tempw=NULL;
			while(temp!=NULL){
				skip=0;
				if(location==temp->destination){
					temp->status="Completed";
					for(int x=0;x<170;x++){
						if(seat[x]==temp->cnic){
							seat[x]=0;
						}
					}
					for(int x=0;x<21;x++){
						if(seatg[x]==temp->cnic){
							seatg[x]=0;
						}
					}
					tempw=temp;
					if(tempw==rhead && tempw->next!=NULL){
						rhead=tempw->next;
						rhead->pre=NULL;
						delete tempw;
						temp=rhead;
						skip=1;
					}else if(tempw->next==NULL && tempw->pre!=NULL){
						temp=tempw->pre;
						rtail=temp;
						rtail->next=NULL;
						delete tempw;
					}else if(tempw->next==NULL && tempw->pre==NULL){
						rhead=NULL;
						rtail=NULL;
						delete tempw;
						break;
					}else{
						temp=tempw->pre;
						temp->next=tempw->next;
						temp=temp->next;
						temp->pre=tempw->pre;
						skip=1;
						delete tempw;
					}
				}
				if(skip==0){
					temp=temp->next;
				}
			}
			air1.q(location,fno);
		}
		void activereservation(){
			rlist();
			cout<<"\t\tPlease Wait.";
			for(int x=0;x<6;x++){
				cout<<".";
				Sleep(300);
			}
			rlist();
			reservation *temp=rhead;
			if(rhead==NULL){
				cout<<"\t\tNo Reservation Yet!\n";
			}else{
				while(temp!=NULL){
					cout<<"CNIC\t\t: "<<temp->cnic<<endl;
					cout<<"NAME\t\t: "<<temp->name<<endl;
					cout<<"Seats\t\t: "<<temp->seats<<endl;
					cout<<"Pay\t\t: "<<temp->bill<<endl;
					cout<<"CLASS\t\t: "<<temp->classs<<endl;
					cout<<"Status\t\t: "<<temp->status<<endl;
					cout<<"*****************************\n";
					temp=temp->next;
				}
			}
			cout<<"\t\t:=>";
			getch();
			system("CLS");
		}
		void viewtraces(){
			cout<<"\n\n\t\tPLEASE WAIT.";
			for(int x=0;x<5;x++){
				cout<<".";
				Sleep(250);
			}
			traff();
			traces *temp=head;
			if(head==NULL){
				cout<<"\t\tCurrent Loication "<<lo();
			}else{
				while(temp!=NULL){
					cout<<"Location is : "<<temp->location<<endl;;
					cout<<"Total Passengers is : "<<temp->pass<<endl;
					cout<<"Comm passengers : "<<temp->cpass<<endl;
					cout<<"Golden passengers : "<<temp->gpass<<endl;
					cout<<"*****************************\n";
					temp=temp->next;
				}
			}
			cout<<"\n\t\t";
			getch();
			system("CLS");
		}
		void stack(){
			cout<<"\n\n\t\tPLEASE WAIT.";
			cout<<"Deleting last Location\n";
			for(int x=0;x<5;x++){
				cout<<".";
				Sleep(250);
			}
			traff();
			if(head==NULL){
				cout<<"\t\tCurrent Loication "<<lo();
			}else{
				traces *temp=tail,*temp2=NULL;
				temp2=temp->pre;
				temp2->next=NULL;
				delete temp;
			}
			cout<<"\n\t\t";
			getch();
			system("CLS");
		}
		void find(){
			int check=0,temcnic=0,b=0;
			srchmsg();
			cout<<"\t\tEnter Your CNIC\n\t\t:=>";
			cin>>temcnic;
			reservation *temp=rhead;
			while(temp!=NULL){
				if(temp->cnic==temcnic){
					b=1;
					break;
				}
				temp=temp->next;
			}
			map();
			cout<<"\n\n\t\tPLEASE WAIT.";
			for(int x=0;x<5;x++){
				cout<<".";
				Sleep(300);
			}
			system("CLS");
			map();
			if(b==1){
				for(int x=0;x<=170;x++){
					check++;
					if(x%9==0){
						cout<<endl;
						cout<<"\t\t";
						check=0;
					}
					if(check%3==0){
						cout<<"    ";
						check=0;
					}
					if(temcnic==seat[x]){
						cout<<"[X]";
					}else{
						cout<<"[0]";	
					}
				}
				cout<<"\n\n";
				check=0;
				for(int x=0;x<=26;x++){
					check++;
					if(x%9==0){
						cout<<endl;
						cout<<"\t\t";
						check=0;
					}
					if(check%3==0){
						cout<<"    ";
						check=0;
					}
					if(temcnic==seatg[x]){
						cout<<"[X]";
					}else{
						cout<<"[0]";	
					}
				}
			}else{
				cout<<"\t\tFind No Seat Reservation against this CNIC\n\t\t";
			}
			getch();
			system("CLS");
		}
		void cancel(){
			int tempcnic=0,refund=0,b=0;
			cnclmsg();
			cout<<"\t\tEnter CNIC \n\n\t\t:=>";
			cin>>tempcnic;
			cnclmsg();
			cout<<"\n\n\t\tPLEASE WAIT.";
			for(int x=0;x<5;x++){
				cout<<".";
				Sleep(300);
			}
			cnclmsg();
			reservation *temp=rhead,*tempw=NULL;
			while(temp!=NULL){
				skip=0;
				if(tempcnic==temp->cnic){
					b=1;
					temp->status="Canceled";
					refund=temp->bill;
					if(temp->classs=="G"){
						for(int x=0;x<=26;x++){
							if(temp->cnic==seatg[x]){
								seatg[x]=0;
							}
						}
					}else{
						for(int x=0;x<=170;x++){
							if(temp->cnic==seatg[x]){
								seatg[x]=0;
							}
						}
					}
				}
				tempw=temp;
				if(tempw==rhead && tempw->next!=NULL){
					rhead=tempw->next;
					rhead->pre=NULL;
					delete tempw;
					temp=rhead;
					skip=1;
				}else if(tempw->next==NULL && tempw->pre!=NULL){
					temp=tempw->pre;
					rtail=temp;
					rtail->next=NULL;
					delete tempw;
				}else if(tempw->next==NULL && tempw->pre==NULL){
					rhead=NULL;
					rtail=NULL;
					delete tempw;
					break;
				}else{
					temp=tempw->pre;
					temp->next=tempw->next;
					temp=temp->next;
					temp->pre=tempw->pre;
					skip=1;
					delete tempw;
				}
				if(skip==0){
					temp=temp->next;
				}
			}
			if(b==1){
				cout<<"\t\tYour Tickets Has Been Canceled\n\t\tPrize You payed is\n\t\t"<<refund<<endl;
				refund=refund-(refund/100)*10;
				cout<<"\t\tRefund is : "<<refund<<endl;
				cout<<"\t\t";
				account-refund;
			}else{
				cout<<"\t\tFind no seat Reservation against this CNIC\n\t\t";
			}
			getch();
			system("CLS");
		}
		string lo(){
			//cout<<location<<endl;
			return location;
		}
};
class login{
	private:
		string pass,pass2;
	public:
		login():pass("spartans"),pass2("root"){};
		void logcheck(string p,string u){
			if(p==pass && u=="unknown"){
				cout<<"WELCOME SPARTANS\n";
				cout<<"PLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(500);
				}
				sec=1;
				mainn();
			}else if(pass2==p && u=="admin"){
				cout<<"\nWELCOME SPARTANS\n";
				cout<<"PLEASE WAIT.";
				for(int x=0;x<7;x++){
					cout<<".";
					Sleep(500);
				}
				sec=2;
				mainn();
			}else{
				cout<<"WRONG PASSWORD...!\n";
				cout<<"Going to Login Menu.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(300);
				}
				main();
			}
		}
};
int main()
{
	system("color 07");
	system("CLS");
	login l1;
	string user="",pas="";
	cout<<"Enter username :=> ";
	cin>>user;
	if(user=="unknown"){
		cout<<"Enter password :=> ";
		cin>>pas;
		l1.logcheck(pas,user);
	}else if(user=="admin"){
		cout<<"Enter password :=> ";
		cin>>pas;
		l1.logcheck(pas,user);
	}else{
		cout<<"WRONG UNSERNAME\nGoing Login Page.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(300);
				}
		main();
	}
	return 0;
}
int mainn()
{
	system("CLS");
	airplan a1("Lahore","f1"),a2("Sialkot","f2"),a3("Karachi","f3"),a4("Islamabad","f4");
	int a,f,ff,fff;
	f=air1.getq();
	system("color 70");
	if(f==0){
		cout<<"There is no plan\n";
	}
	start:
	cout<<"WELCOME!\n";
	cout<<"\t\t***************************************************************\n";
    cout<<"\t\t***************************************************************\n";
    cout<<"\t\t*****                      AIR LINES                      *****\n";  
    cout<<"\t\t*****REHAN MALIK   ABDULLAH TARIQ   HAMZA BUTT  Haider Mir*****\n";
    cout<<"\t\t***************************************************************\n";
    cout<<"\t\t***************************************************************\n\n";
    cout<<"\t\t[1] For Booking \n\t\t[2] For Find Seats\n\t\t[3] for Cancel Booking \n";
	if(sec==2){
		cout<<"\t\t[4] For Display All Seats\n\t\t[5] For Traces \n\t\t[6] For Active reservation\n\t\t[7] For Accounts \n\t\t[8] For TakeOff \n\t\t[9] For Quee View\n";
	}
	cout<<"\t\t[10] for Refuealing\n\t\t[11] for Lot Out \n\t\t[12] for Exit\n";
	cout<<"\n\n\t\t:=>";
	cin>>a;
	switch(a){
		case 1:
			if(f==1){
				a1.book();
			}else if(f==2){
				a2.book();
			}else if(f==3){
				a3.book();
			}else if(f==4){
				a4.book();
			}
			break;
		case 2:
			if(f==1){
				a1.find();
			}else if(f==2){
				a2.find();
			}else if(f==3){
				a3.find();
			}else if(f==4){
				a4.find();
			}
			break;
		case 3:
			if(f==1){
				a1.cancel();
			}else if(f==2){
				a2.cancel();
			}else if(f==3){
				a3.cancel();
			}else if(f==4){
				a4.cancel();
			}
			break;
		case 4:
			if(sec==2){
				system("CLS");
				cout<<"\t\t****************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                  RESERVATION Menu                   *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n";
				cout<<"\t\tSelect Plane no\n";
				cout<<"\t\t[1] For F1 \n\t\t[2] For F2 \n\t\t[3] For F3 \n\t\t[4] For F4 \n\n\t\t:=>";
				cin>>ff;
				if(ff==1){
					a1.dis();
				}else if(ff==2){
					a2.dis();
				}else if(ff==3){
					a3.dis();
				}else if(ff==4){
					a4.dis();
				}
			}else{
				cout<<"\t\tAccess Denied\n\t\t:=>";
				Sleep(600);
			}
			break;
		case 5:
			if(sec==2){
				system("CLS");
				cout<<"\t\t****************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                     TRAFFIC Menu                    *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n";
				cout<<"\t\tSelect Plane no\n";
				cout<<"\t\t[1] For F1 \n\t\t[2] For F2 \n\t\t[3] For F3 \n\t\t[4] For F4 \n\n\t\t:=>";
				cin>>ff;
				if(ff==1){
					a1.viewtraces();
				}else if(ff==2){
					a2.viewtraces();
				}else if(ff==3){
					a3.viewtraces();
				}else if(ff==4){
					a4.viewtraces();
				}else{
					cout<<"\t\tEnter Right Option\n";
					Sleep(1000);
					system("CLS");
				}
			}else{
				cout<<"\t\tAccess Denied\n\t\t:=>";
				Sleep(600);
			}
			break;
		case 6:
			if(sec==2){
				a1.activereservation();
			}else{
				cout<<"\t\tAccess Denied\n\t\t:=>";
				Sleep(600);
				Sleep(300);
			}
			break;
		case 7:
			if(sec==2){
				a1.acc();
				cout<<"Please Wait.";
				for(int x=0;x<6;x++){
					cout<<".";
					Sleep(150);
				}
				a1.acc();
				cout<<"\t\tCurrent balance is : "<<account<<endl;
				cout<<"\n\t\t:=>";
				getch();
				system("CLS");
			}else{
				cout<<"\t\tAccess Denied\n\t\t:=>";
				Sleep(600);
			}
			break;
		case 8:
			if(sec==2){
				a1.take();
				cout<<"\t\t[1] For All TakeOff \n\t\t[2] For Manual \n\n\t\t:=>";
				cin>>ff;
				switch(ff){
					case 1:
						a1.takeoffauto();
						a2.takeoffauto();
						a3.takeoffauto();
						a4.takeoffauto();
						break;
					case 2:
						cout<<"\t\tSelect Plane no\n";
						cout<<"\t\t[1] For F1 \n\t\t[2] For F2 \n\t\t[3] For F3 \n\t\t[4] For F4 \n\n\t\t:=>";
						cin>>fff;
						switch(fff){
							case 1:
								a1.takeoff();
								break;
							case 2:
								a2.takeoff();
								break;
							case 3:
								a3.takeoff();
								break;
							case 4:
								a4.takeoff();
								break;
							default:
								cout<<"\t\tPlease Select Right Option\n";
						}
						break;
					default:
						cout<<"\t\tPlease Select Right Option\n";
				}
				cout<<"\n\t\t:=>";
				getch();
				system("CLS");
			}else{
				cout<<"Access Denied\n\t\t:=>";
				Sleep(600);
			}
			break;
		case 9:
			if(sec==2){
				a1.map();
				air1.viewquee();
				cout<<"\t\t:=>";
				getch();
				system("CLS");
			}else{
				cout<<"\t\tAccess Denied\n\t\t:=>";
				Sleep(600);
			}
			break;
		case 10:
			system("CLS");
				cout<<"\t\t****************************************************************\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t*****                  Refuealing Menu                    *****\n";
				cout<<"\t\t***************************************************************\n";
				cout<<"\t\t***************************************************************\n\n\n:=>";
				cout<<"\t\tSelect Plane no\n";
						cout<<"\t\t[1] For F1 \n\t\t[2] For F2 \n\t\t[3] For F3 \n\t\t[4] For F4 \n\n\t\t:=>";
						cin>>fff;
						switch(fff){
							case 1:
								a1.stack();
								break;
							case 2:
								a2.stack();
								break;
							case 3:
								a3.stack();
								break;
							case 4:
								a4.stack();
								break;
							default:
								cout<<"\t\tPlease Select Right Option\n";
						}
			break;
		case 11:
			system("CLS");
			cout<<"LOGING OUT.";
			for(int x=0;x<6;x++){
				cout<<".";
				Sleep(300);
			}
			system("CLS");
			cout<<"\t\t**************************[LOG OUT]**************************\n";
			cout<<"\t\t*******************   [SPARTAN'S GROUP]    ******************\n";
			cout<<"\t\t*** REHAN MALIK(066), ABDULLAH TARIQ(088),HAMZA BUTT(060) ***\n";
			cout<<"\t\t*************************************************************\n";
			cout<<"\t\t*************************************************************\n\n\n";
			cout<<"\t\t:=>";
			getch();
			main();
			break;
		case 12:
			system("CLS");
			cout<<"LOGING OUT.";
			for(int x=0;x<6;x++){
				cout<<".";
				Sleep(300);
			}
			system("CLS");
			cout<<"\t\t**************************[EXIT]*****************************\n";
			cout<<"\t\t*******************   [SPARTAN'S GROUP]    ******************\n";
			cout<<"\t\t*** REHAN MALIK(066), ABDULLAH TARIQ(088),HAMZA BUTT(060) ***\n";
			cout<<"\t\t*************************************************************\n";
			cout<<"\t\t*************************************************************\n\n\n\t\t";
			getch();
			goto end;
		default:
			cout<<"Please Enter Right option\n";
	}
	if(sec==1){
		system("CLS");
	}
	goto start;
	end:
	return 0;
}
