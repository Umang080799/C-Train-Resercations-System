#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

COORD coord={0,0};
void gotoxy(int x,int y)
{

    coord.X=x;
    coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;


class admin
{
protected:
    int tno,c1,c2,fare1,fare2;
    char tname[30],st[4],en[4];
public:
    void input()
    {
        system("cls");
        gotoxy(5,1);
        cout<<endl<<"Enter the details as follows: ";
        gotoxy(5,4);
        cout<<"Train number: ";

        cin>>tno;
        gotoxy(5,6);
        cout<<"Train name: ";

        cin>>tname;
        gotoxy(5,8);
        fflush(stdin);
        cout<<"Journey starts from : ";
        cin>>st;
        gotoxy(5,10);
        cout<<"Journey ends in : ";
        cin>>en;
        gotoxy(5,12);
        cout<<"Number of seats in First class: ";

        cin>>c1;
        gotoxy(5,14);
        cout<<"Fare per ticket in first class: ";

        cin>>fare1;
        gotoxy(5,16);
        cout<<"Number of seats in second class: ";

        cin>>c2;
        gotoxy(5,18);
        cout<< "Fare per ticket in second class: ";

        cin>>fare2;

    }
    void output(int row)
    {
        gotoxy(2,row);
        cout<<tno;
        gotoxy(8,row);
         cout << tname;
         gotoxy(15,row);
         cout << st;
         gotoxy(21,row);
         cout<<en;
         gotoxy(29,row);
         cout << c1;
         gotoxy(41,row);
         cout<<fare1;
         gotoxy(52,row);
         cout << c2;
         gotoxy(66,row);
         cout <<fare2;

    }

    char *returntname()
    {

        return tname;
    }

    void dec_c1()
    {

        c1--;



    }

    int dec_c2()
    {
        c2--;
        return c2;
    }

    int returnfare1()
    {

        return fare1;
    }
    int returnfare2()
    {
        return fare2;
    }

};
    class user
    {
        char id[30],name[30],pass[30],t[30];
        int age;
    public:
        void input()
        {
            cout<<endl<<"Enter your details as follows: ";
            cout<<endl<<endl;
            cout<<endl << "Name: ";
            cin>>name;
            cout<<endl << "Age : ";
            cin>>age;
            cout<<endl << "ID: ";
            cin>>id;
            do
            {
                cout<<endl << "Enter a password: ";
                cin>>pass;
                cout<<endl<<"Re-enter your password: ";
                cin>>t;
                if(strcmp(pass,t)!=0)
                    cout<<endl<< "The passwords do not match!"<<endl;

            }while(strcmp(pass,t)!=0);

        }
        void output(int row)
        {
            gotoxy(1,row);
            cout<<name;
            gotoxy(13,row);
            cout << age;
            gotoxy(30,row);
            cout <<id;
            gotoxy(45,row);
            cout<<pass;
        }
        char* returnname()
        {
            return name;
        }
        char* returnid()
        {
            return id;
        }
        char* returnpass()
        {
            return pass;
        }

    };
class reserve : admin
{
        char p_name[30];
        int p_age,pnr,d,m,y,clas;
    public:
       void input(int i)
        {

            srand(time(NULL));
            pnr = rand()%10;
            cout<<endl<< "Enter the train Name: ";
            cin>>tname;
            cout<<endl << "Enter the class(1-first,2-second):  ";
            cin>>clas;
            do{
            cout<<endl << "Enter the date of travel(dd/mm/yyyy):  " <<endl;
            cout << "Enter the day" <<endl;
            cout<<" dd : ";
            cin>>d;
            if ((d < 1) || (d >31)) cout <<endl<<  "INVALID DAY,PLEASE ENTER AGAIN" << endl;
            } while (( d < 1) || (d > 31));

          do{
            cout << "Enter the month" <<endl;
            cout<<" mm : ";
            cin>>m;
            if ((m< 1) || (m >12)) cout <<endl<< "INVALID MONTH ,PLEASE ENTER AGAIN"<<endl;
           } while (( m < 1) || (m > 12));

            cout << "Enter the year " <<endl;
            cout<<"yyyy : ";

            cin>>y;

            cout<<"Enter the name of the passenger"<<i<<"  : ";
            cin>>p_name;
            cout<<"Enter the age of the passenger: "<<i<<"  : ";
            cin>>p_age;
        }
        void output(int row)
        {
            gotoxy(2,row);
            cout<<pnr;
            gotoxy(8,row);
            cout <<tname;
            gotoxy(15,row);
            cout<<clas;
            gotoxy(22,row);
            cout<<d<<"/"<<m<<"/"<<y;
            gotoxy(35,row);
            cout<<p_name;
            gotoxy(47,row);

            cout<<p_age;
        }


        int returnpnr()
        {
            return pnr;
        }
        char* returnname()
        {
            return tname;
        }
        int returnclas()
        {
            return clas;
        }
        int returnd()
        {
            return d;
        }
        int returnm()
        {
            return m;
        }
        int returny()
        {
            return y;
        }
        char*returnp_name()
        {
            return p_name;
        }
        int returnp_age()
        {
            return p_age;
        }

    };
    int main()

    {
        int i,n,o,p,q,r,temppnr,row;
        char pass[30],tempid[30],temppass[30];
        fstream afile,tfile,rfile;
        fstream trfile;
        ifstream trainfile;
        admin a;
        user b;
        reserve c1,t;
        do
        {
            system("cls");
            gotoxy(1,2);
            cout<<"-------------------------------------------------------";
            gotoxy(7,3);
            cout<<"WELCOME TO ONLINE RESERVATION SYSTEM";
            gotoxy(1,4);
            cout<<"--------------------------------------------------------";

            gotoxy(10,7);
            cout<<"     MAIN MENU    ";
            gotoxy(5,10);


            cout<<"1.Administrator mode   ";
            gotoxy(5,12);
            cout << "2.User mode";
            gotoxy(5,14);
            cout << "3.Exit" ;
            gotoxy(5,20);
            cout << "   Enter your choice : ";
            cin>>o;
            switch(o)
            {
                case 1: gotoxy(5,22);
                cout<<"Enter the password(case sensitive) : ";
                cin>>pass;
                if(strcmp(pass,"R41COMP")==0)
                {
                    do
                    {
                        system("cls");
                        gotoxy(1,2);
                        cout<<"----------------------------------------------";
                        gotoxy(7,3);
                        cout<<"WELCOME ADMINSTRATOR ";
                        gotoxy(1,4);
                        cout<<"-----------------------------------------------";
                        gotoxy(5,10);
                        cout<<"1.Add train details";
                        gotoxy(5,12);
                        cout<<"2.Display train details: ";
                        gotoxy(5,14);

                        cout<<"3.Display user details: ";
                        gotoxy(5,16);

                        cout<<"4.Return to main menu";
                        gotoxy(5,22);
                        cout<<"Enter your choice: ";
                        cin>>p;
                        switch(p)
                        {
                            case 1:system("cls");
                                   afile.open("train.dat",ios::app|ios::out);
                                   gotoxy(10,7);
                                   cout<<endl<<"  Enter the number of trains whose details you want to enter: ";
                                   cin>>n;
                                   for(i=0;i<n;i++)
                                   {
                                       a.input();
                                      afile.write((char*)&a,sizeof(admin));
                                   }



                                   afile.close();
                                   break;
                            case 2: system("cls");
                                    afile.open("train.dat",ios::in);
                                    gotoxy(1,1);
                                    cout <<"-----------------------------------------------------------------------";
                                    gotoxy(1,3);
                                    cout <<"TRNO";
                                    gotoxy(7,3);
                                    cout << "TNAME";
                                    gotoxy(14,3);
                                    cout <<"START";
                                    gotoxy(20,3);
                                    cout << "DEST";
                                    gotoxy(28,3);
                                    cout <<"SEATS(1st)";
                                    gotoxy(40,3);
                                    cout << "FARE(1st)";
                                    gotoxy(50,3);
                                    cout <<"SEATS(2nd)";
                                    gotoxy(64,3);
                                    cout<<"FARE(2nd)";
                                    gotoxy(1,5);
                                    cout << "-----------------------------------------------------------------------";
                                    row = 7;
                                    while(afile)
                                    {
                                        afile.read((char*)&a,sizeof(admin));
                                        if(!afile)
                                            break;
                                        a.output(row);
                                        row = row+2;

                                    }
                                    afile.close();
                                    cout<<endl<<"Press any key to continue: ";
                                    getch();
                                    break;
                           case 3: system("cls");
                           afile.open("user.dat",ios::in);
                           cout<<"-----------------------------------------------------------------------"<<endl<<endl;
                           cout<<"Name\t    Age   \t     ID        \t      Password"<<endl<<endl;
                           cout<<"-------------------------------------------------------------------------"<<endl<<endl;
                           while(afile)
                           {
                               afile.read((char*)&b,sizeof(user));
                               if(!afile)
                                break;
                                row = 7;
                               b.output(row);
                               row++;

                           }
                           afile.close();
                           cout<<endl<< endl<< "Press any key to continue";
                           getch();
                           break;

                case 4:break;
                default: cout<<"Wrong Entry !"<<endl;;
                        cout<<endl<<"Press any key to continue";
                        getch();

                 }/*switch (p) */
            }while (p!= 4);
            break;
        } /*if*/

                    else
                        cout<<endl<<endl<<"Incorrect password !! Enter the password correctly ! ";
                        break;

                    case 2: do
                            {
                                system("cls");
                                gotoxy(1,2);
                                cout<<"---------------------------------------------------------------";
                                gotoxy(7,3);
                                cout<<"USER MENU";
                                gotoxy(1,4);
                                cout<<"----------------------------------------------------------------";
                                gotoxy(5,10);
                                cout<<"1.Create new id";
                                gotoxy(5,12);
                                cout <<"2.Login into an existing id";
                                gotoxy(5,14);
                                cout <<"3.Return to main menu";
                                gotoxy(5,20);

                                cout<< "Enter your choice: ";
                                cin>>q;
                                switch(q)
                                {
                                    case 1:afile.open("user.dat",ios::app|ios::out);
                                    b.input();
                                    afile.write((char*)&b,sizeof(user));
                                    afile.close();
                                    cout<<endl<<"Press any key to continue"<<endl;

                                    getch();
                                    break;

                                    case 2: afile.open("user.dat",ios::in);
                                            while(afile)
                                            {
                                                afile.read((char*)&b,sizeof(user));
                                                //if(!afile);
                                                //break;
                                                fflush(stdin);
                                                cout<<endl<<"Enter your id";
                                                cin>>tempid;
                                                cout<<endl<<"Enter your password : ";
                                                cin>>temppass;
                                                if((strcmp(b.returnid(),tempid)==0)&&(strcmp(b.returnpass(),temppass)==0))
                                                {
                                                 do
                                                 {
                                                        system("cls");
                                                        gotoxy(7,3);
                                                        cout<<"Welcome "<<b.returnname();
                                                        gotoxy(5,10);
                                                        cout<<"1.Reserve a ticket";
                                                        gotoxy(5,12);
                                                        cout<< "2.Cancel a ticket";
                                                        gotoxy(5,14);
                                                        cout<<"3.Display the list of passengers";

                                                        gotoxy(5,16);
                                                        cout<< "4.Log off";
                                                        gotoxy(5,22);
                                                        cout<<endl<< "Enter your choice";
                                                        cin>>r;
                                                        switch(r)
                                                        {
                                                         case 1 : system("cls");
                                                                rfile.open("reserve.dat",ios::out|ios::app);
                                                                /*trfile.open("train.dat",ios::in); */

                                                                cout<<"Enter the number of tickets you want to reserve";
                                                                cin>>n;
                                                                int seats_left,total_cost,flg;
                                                                total_cost =0; flg =0;
                                                                for(i=1;i<=n;i++)
                                                                {


                                                                        c1.input(i);


                                                                        trfile.open("train.dat",ios::in);
                                                                        while (trfile)
                                                                        {


                                                                            trfile.read((char *)&a,sizeof(admin));
                                                                            if (!trfile) break;
                                                                            if (strcmp(c1.returnname(),a.returntname()) == 0)
                                                                            {



                                                                                if (c1.returnclas() == 1)
                                                                                {


                                                                                    total_cost += a.returnfare1();



                                                                                }
                                                                                else
                                                                                {


                                                                                    if( c1.returnclas() == 2)


                                                                                      total_cost +=a.returnfare2();

                                                                                  }
                                                                                } /* if */


                                                                            } /* while */

                                                                        trfile.close();

                                                                        rfile.write((char*)&c1,sizeof(reserve));


                                                                        cout<<"--------------------------------------------------------------------"<<endl<<endl;
                                                                        cout<<"\t\tReservation Status"<<endl<<endl;
                                                                        cout<<"---------------------------------------------------------------------"<<endl<<endl;
                                                                        cout<<"Pnr no: " <<c1.returnpnr();

                                                                        cout<<endl<< "Train name:" << c1.returnname();
                                                                        cout<<endl<<"Class (1-fist,2-Second) :"<< c1.returnclas();
                                                                        cout<<endl<<"Date of travel(dd/mm/yyy): "<< c1.returnd()<<"/"<< c1.returnm()<<"/"<< c1.returny();
                                                                        cout<<endl<<"Name the passenger "<< c1.returnp_name();
                                                                        cout<<endl<<"Age of passenger: "<< c1.returnp_age();
                                                                        cout << endl << " TOTAL COST :     " << total_cost;

                                                                        cout<<endl<<endl<<"----------------------------------------------------------------------"<<endl<<endl;




                                                                     } /*for */


                                                                rfile.close();
                                                                cout<<endl<<"Press any key to continue: ";
                                                                getch();
                                                                break;
                                                     case 2:    system("cls");
                                                                rfile.open("reserve.dat",ios::in);
                                                                tfile.open("temp.dat",ios::out);
                                                                cout<<"Enter the PNR of ticket you want to cancel: ";
                                                                cin>>temppnr;
                                                                while(rfile)
                                                                {
                                                                   rfile.read((char*)&c1,sizeof(reserve));
                                                                   if(!rfile)
                                                                     break;



                                                                  if(temppnr == c1.returnpnr())
                                                                  {

                                                                    cout<<"\t\t TICKET CANCELLED "<<endl<<endl;
                                                               cout<<"---------------------------------------------------------------------------------"<<endl<<endl;
                                                              cout<<"PNR : "<<c1.returnpnr();
                                                              cout<<endl<<"Train Name: "<< c1.returnname();
                                                              cout<<endl<<endl<<"Class (1-first, 2-Second) :"<< c1.returnclas();
                                                              cout<<endl<<"Date of travel(mm/dd/yyyy) : "<<c1.returnd()<<"/"<<c1.returnm()<<"/"<<c1.returny();
                                                              cout<<endl<<"Name of passenger : "<<c1.returnp_name();
                                                              cout<<endl<<"Age of passenger: "<< c1.returnp_age();
                                                              cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl<<endl;
                                                              cout<<endl<<"Press any key to continue: "<<endl;
                                                              getch();
                                                                  }
                                                                   else
                                                                          tfile.write((char*)&c1,sizeof(reserve));

                                                               }/*while*/
                                                               rfile.close();
                                                               tfile.close();
                                                               remove("reserve.dat");
                                                               rename("temp.dat","reserve.dat");


                                                               cout << " NOW YOUR RESERVATION IS AS FOLLOWS: " <<endl;
                                                               rfile.open("reserve.dat", ios::in);
                                                               while(rfile)
                                                                {
                                                                   rfile.read((char*)&c1,sizeof(reserve));
                                                                   if(!rfile)
                                                                     break;




                                                               cout<<"---------------------------------------------------------------------------------"<<endl<<endl;
                                                              cout<<"PNR : "<<c1.returnpnr();
                                                              cout<<endl<<"Train Name: "<< c1.returnname();
                                                              cout<<endl<<endl<<"Class (1-first, 2-Second) :"<< c1.returnclas();
                                                              cout<<endl<<"Date of travel(mm/dd/yyyy) : "<<c1.returnd()<<"/"<<c1.returnm()<<"/"<<c1.returny();
                                                              cout<<endl<<"Name of passenger : "<<c1.returnp_name();
                                                              cout<<endl<<"Age of passenger: "<< c1.returnp_age();
                                                              cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl<<endl;
                                                              cout<<endl<<"Press any key to continue: "<<endl;
                                                              getch();
                                                                }

                                                                 rfile.close();                                                                                                                       cout<<"--------------------------------------------------------------------------------"<<endl<<endl;

                                                              break;
                                           case 3: system("cls");
                        rfile.open("reserve.dat",ios::in);
                        gotoxy(1,1);
                        cout<<"--------------------------------------------------------------------";
                        gotoxy(1,3);
                        cout<<"PNR";
                        gotoxy(7,3);
                        cout << "Tname";
                        gotoxy(14,3);
                        cout<< "Class";
                        gotoxy(22,3);
                        cout <<"Date";
                        gotoxy(30,3);
                        cout <<"PassengerName";
                        gotoxy(45,3);
                        cout<<"Passenger Age";
                        gotoxy(1,5);
                        cout<<"---------------------------------------------------------------------"<<endl<<endl;
                        row = 7;

                        while(rfile)
                        {

                            rfile.read((char*)&c1,sizeof(reserve));
                            if(!rfile)
                               break;

                            c1.output(row);
                            row = row + 2;
                        }
                        rfile.close();
                        cout<<endl<<endl<< endl <<"Press any key to continue"<<endl;
                        getch();
                        break;



                                               /* system("cls");
                                                    trainfile.open("train.dat",ios::in);
                                                gotoxy(1,1);
                                    cout <<"-----------------------------------------------------------------------";
                                    gotoxy(1,3);
                                    cout <<"TRNO";
                                    gotoxy(7,3);
                                    cout << "TNAME";
                                    gotoxy(14,3);
                                    cout <<"START";
                                    gotoxy(20,3);
                                    cout << "DEST";
                                    gotoxy(28,3);
                                    cout <<"SEATS(1st)";
                                    gotoxy(40,3);
                                    cout << "FARE(1st)";
                                    gotoxy(50,3);
                                    cout <<"SEATS(2nd)";
                                    gotoxy(64,3);
                                    cout<<"FARE(2nd)";
                                    gotoxy(1,5);
                                    cout << "-----------------------------------------------------------------------";
                                               while(trainfile)
                                                {
                                                    trainfile.read((char*)&a,sizeof(admin));
                                                    if(!trainfile)
                                                       break;
                                                       row = 7;
                                                    a.output(row);
                                                    row = row+2;


                                                 }
                                                trainfile.close();
                                                cout<<endl<<endl<<endl<< "Press any key to continue: ";
                                                getch();
                                                 break; */


                                         case 4: break;
                                        default:  cout<<"Wrong entry!"<<endl<<endl;
                                                  cout<<endl<<"Press any key to continue: "<<endl;
                                                  getch();
                          } /*switch (r) */
                    } while (r!=4);
            } /*if */

            else
                cout<<endl<<endl<<"Incorrect id or password! Enter the id and password";
             break;
          } /*while*/
          afile.close();
         break;
    case 3:break;

    default: cout<<"Wrong entry! "<<endl<<endl;

            cout<<endl<<"Press any key to continue: "<<endl;
            getch();
    } /*switch */
}while(q!=3);
break;


case 3:exit(0);
            default:cout<<endl<<"Wrong entry !"<<endl;
           cout<<endl<<"Press any key to continue"<<endl;
           getch();
    } /* switch(o) */

 }while(o!=3);

}










