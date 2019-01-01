#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
struct date
{
    int day,month,year;
    void display()
    {
        cout<<day<<"-"<<month<<"-"<<year;
    }
};
class customer
{
    char name[20];
    char address[50];
    char telno[11];
    date checkin,checkout;
    int checkinstatus;
    int roomno;
    char roomtype[10];
    float bill,restaurant_bill;
    public:
        customer()
        {
            bill=0.0;restaurant_bill=0.0;
            checkinstatus=0;
            checkout.day=0,checkout.month=0,checkout.year=0;
        }
        void changetype(char CHAR[])
        {
            strcpy(roomtype,CHAR);
        }
        void read()
        {
            cout<<"Name: ";
            cin.ignore();
            gets(name);
            cout<<"Address:-\n";
            gets(address);
            cout<<"Telephone No.(10-digit): ";
            gets(telno);
            cout<<"Check-in Date(DD MM YYYY):";
            cin>>checkin.day>>checkin.month>>checkin.year;
        }
        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Telephone No.: "<<telno<<endl;
            cout<<"Check-in Date : ";
            checkin.display();cout<<endl;
            if(checkout.day!=0)
            {
                cout<<"Check out Date: ";
                checkout.display();
                cout<<endl;
            }
            cout<<"Check-in Status: ";
            if(checkinstatus==1)
                cout<<"Checked in!\n";
            else
                cout<<"NOT Checked-in!\n";
            cout<<"Room No.: "<<roomno<<endl;
            cout<<"Room Type: "<<roomtype<<endl;
            if(bill!=0.0)
                cout<<"Total Bill Amount: Rs. "<<bill+restaurant_bill<<"/-\n";
            if(restaurant_bill!=0.0)
                cout<<"Restaurant Bill Amount: Rs. "<<restaurant_bill<<"/-\n";
        }
        void charge(float amt)
        {
            restaurant_bill+=amt;
        }
        float generatebill(float price)
        {
            int stay=((checkout.year-checkin.year)*365)+((checkout.month-checkin.month)*30)+(checkout.day-checkin.day);
            float amount=price*stay;
            bill=amount;
            cout<<"Stay: "<<stay<<endl;
            cout<<"Charge Per Night: Rs. "<<price<<"/-"<<endl;
            cout<<"Total Hotel Charge: Rs. "<<bill<<"/-"<<endl;
            cout<<"Total Restaurant Charge: Rs. "<<restaurant_bill<<"/-"<<endl;
            cout<<"\nTOTAL BILL AMOUNT: Rs. "<<bill+restaurant_bill<<"/-"<<endl;
        }
        void check_in()
        {
            checkinstatus=1;
        }
        void check_out(int a,int b,int c)
        {
            checkout.day=a;
            checkout.month=b;
            checkout.year=c;
        }
        int retroomno()
        {
            return roomno;
        }
        void assignroomno(int a)
        {
            roomno=a;
        }
        int retcheckinstatus()
        {
            return checkinstatus;
        }
};
class member
{
    char name[20];
    char address[50];
    char telno[11];
    int type;
    int membercode;
    date memshipdate;
public:
    member(int a)
    {
        type=a;
    }
    void read()
    {
        cout<<"NAME: ";
        cin.ignore();
        gets(name);
        cout<<"ADDRESS:-\n";
        gets(address);
        cout<<"TELEPHONE NO. : ";
        gets(telno);
        cout<<"Membership Date(the date you wanna start swimming/gymming!)- ";
        cin>>memshipdate.day>>memshipdate.month>>memshipdate.year;
        cout<<"And you're done! Start swimming/gymming from the membership date. Enjoy!\n";
    }
    int assigncode()
    {
        int flag=0;
        char str[251];char category[10];
        if(type==1)
            strcpy(category,"pool.txt");
        else
            strcpy(category,"gym.txt");
        fstream file(category,ios::in);
        file>>str;
        file.close();
        for(int i=0;i<251;i++)
        {
            if(str[i]=='u')
            {
                str[i]='o';
                membercode=i+1;
                cout<<i+1<<" is your pool/gym membership code.\n";
                flag++;
                break;
            }
        }
        if(flag)
        {
            file.open(category,ios::out);
            file<<str;
            file.close();
        }
        return flag;
    }
};
void book()
{
    customer c1;
    char arr[251];
    int choice,flag=1,a=0,b=0,c=0,d=0,e=0;
    fstream file("rooms.txt",ios::in);
    file>>arr;
    file.close();
    for(int i=0;i<251;i++)
    {
        if(arr[i]=='u')
        {
            if(i>=50)
             if(i>=100)
              if(i>=150)
               if(i>=200)
                a++;
               else
                b++;
              else
               c++;
             else
              d++;
            else
             e++;
        }
    }
    cout<<"We have the following rooms:-\n";
    cout<<"\n\nROOM TYPES  "<<"\t"
	    <<"CODES"<<"\t"<<"CHARGE PER NIGHT\n"
	    <<"ROYAL SUITE (AVAILABILITY: "<<e<<" rooms)"<<"\t"<<"1.   "<<"\t"<<"Rs 20,000\n"
	    <<"SUPER DELUXE(AVAILABILITY: "<<d<<" rooms)"<<"\t"<<"2.   "<<"\t"<<"Rs 15,000\n"
	    <<"DELUXE      (AVAILABILITY: "<<c<<" rooms)"<<"\t"<<"3.   "<<"\t"<<"Rs 10,000\n"
	    <<"DOUBLE BED  (AVAILABILITY: "<<b<<" rooms)"<<"\t"<<"4.   "<<"\t"<<"Rs  5,000\n"
	    <<"SINGLE BED  (AVAILABILITY: "<<a<<" rooms)"<<"\t"<<"5.   "<<"\t"<<"Rs  2,000\n";
    cout<<"Which type of room would you prefer ?\n";
    cin>>choice;cout<<endl;
    switch(choice)
    {
        case 1:
            c1.changetype("ROYAL SUITE");
            for(int i=0;i<50;i++)
            {
                if(arr[i]=='u')
                {
                    arr[i]='o';
                    c1.assignroomno(i+1);
                    flag++;
                    break;
                }
            }
            break;
        case 2:
            c1.changetype("SUPER DELUXE");
            for(int i=50;i<100;i++)
            {
                if(arr[i]=='u')
                {
                    arr[i]='o';
                    c1.assignroomno(i+1);
                    flag++;
                    break;
                }
            }
            break;
        case 3:
            c1.changetype("DELUXE");
            for(int i=100;i<150;i++)
            {
                if(arr[i]=='u')
                {
                    arr[i]='o';
                    c1.assignroomno(i+1);
                    flag++;
                    break;
                }
            }
            break;
        case 4:
            c1.changetype("DOUBLE BED");
            for(int i=150;i<200;i++)
            {
                if(arr[i]=='u')
                {
                    arr[i]='o';
                    c1.assignroomno(i+1);
                    flag++;
                    break;
                }
            }
            break;
        case 5:
            c1.changetype("SINGLE BED");
            for(int i=200;i<250;i++)
            {
                if(arr[i]=='u')
                {
                    arr[i]='o';
                    c1.assignroomno(i+1);
                    flag++;
                    break;
                }
            }
            break;
        default:
            cout<<"OOPS! Wrong option selected!\n";flag=0;
    }
    if(flag==2)
    {
        file.open("rooms.txt",ios::out);
        file<<arr;
        file.close();
        cout<<"Please enter the following credentials.\n\n";
        cout<<"------------------------------------------------------------------------\n";
        c1.read();
        cout<<"\nYour room no. is ";
        cout<<c1.retroomno()<<endl;
        cout<<"------------------------------------------------------------------------\n";
        fstream fout("HOTEL.dat",ios::app|ios::out|ios::binary);
        fout.write((char*)&c1,sizeof(c1));
        fout.close();
    }
    else if(flag==1)
        cout<<"No rooms are available for that category. We're sorry for the inconvenience.\n";
}
void checkin()
{
    customer c1;
    int num,flag=0;
    long ptr=-1*sizeof(c1);
    cout<<"Please Enter Your Room No.: ";
    cin>>num;
    fstream file("HOTEL.dat",ios::binary|ios::in|ios::out);
    while(file.read((char*)&c1,sizeof(c1)))
    {
        if(num==c1.retroomno())
        {
            c1.check_in();
            file.seekp(ptr,ios::cur);
            file.write((char*)&c1,sizeof(c1));
            cout<<"\nChecked-in Successfully!!\n";
            flag++;
            break;
        }
    }
    if(!flag)
    {
        cout<<"OOPS! Wrong Room No. Entered.\n";
    }
    file.close();
}
void checkout()
{
    customer c1;int num,flag=0;
    float price;
    cout<<"Please Enter Your Room No.: ";
    cin>>num;
    if(num>50)
     if(num>100)
      if(num>150)
       if(num>200)
        price=2000;
       else
        price=5000;
      else
       price=10000;
     else
      price=15000;
    else
     price=20000;
    fstream fin("HOTEL.dat",ios::in|ios::binary);
    fstream fout("HOTELNEW.dat",ios::out|ios::binary);
    fstream fout2("CUSTOMER.dat",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&c1,sizeof(c1)))
    {
        if(num==c1.retroomno())
        {
            int a,b,c;
            cout<<"Please Enter Check-out Date(DD MM YYYY): ";
            cin>>a>>b>>c;
            c1.check_out(a,b,c);
            cout<<"------------------------------------------------------------------------\n";
            c1.display();
            cout<<"------------------------------------------------------------------------\n";
            cout<<endl;
            cout<<"--------------------------------BILL------------------------------------\n";
            c1.generatebill(price);
            cout<<"------------------------------------------------------------------------\n";
            cout<<"\nPLS PAY THE ABOVE MENTIONED AMOUNT TO THE RECEPTIONIST.\n";
            fout2.write((char*)&c1,sizeof(c1));
            flag++;
        }
        else
        {
            fout.write((char*)&c1,sizeof(c1));
        }
    }
    fin.close();fout.close();fout2.close();
    remove("HOTEL.dat");
    rename("HOTELNEW.dat","HOTEL.dat");
    if(flag)
    {
        char str[251];
        fstream file("rooms.txt",ios::in);
        file>>str;
        file.close();
        str[num-1]='u';
        file.open("rooms.txt",ios::out);
        file<<str;
        file.close();
        cout<<"\nSuccessfully Checked Out!\n\nTHANK YOU!\nIT WAS A PLEASURE TO HAVE YOU!\nHAVE A GREAT DAY AHEAD!\n\n";
    }
    else
    {
        cout<<"OOPS! Wrong Room No. Entered\n";
    }
}
void viewdata()
{
    customer c1;
    int num,choice,flag=0;
    cout<<"Pls Enter the Room No. for the Customer: ";
    cin>>num;
    cout<<"View Data for:-\n1) Existing Customers\n2) Ex-Customers\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            fstream fin("HOTEL.dat",ios::in|ios::binary);
            while(fin.read((char*)&c1,sizeof(c1)))
            {
                if(num==c1.retroomno())
                {
                    cout<<"\nThe Data for the Customer :-\n";
                    cout<<"------------------------------------------------------------------------\n";
                    c1.display();
                    cout<<"------------------------------------------------------------------------\n";
                    flag++;
                    break;
                }
            }
            if(!flag)
                cout<<"OOPS! There's NO Existing Customer for that Room No.\n";
            fin.close();
            break;
        }
        case 2:
        {
            cout<<"Here is/are Customer(s) who have stayed in that Room:- \n\n";
            fstream fin("CUSTOMER.dat",ios::binary|ios::in);
            while(fin.read((char*)&c1,sizeof(c1)))
            {
                if(num==c1.retroomno())
                {
                    cout<<"The data for the Customer :-\n";
                    cout<<"------------------------------------------------------------------------\n";
                    c1.display();
                    cout<<"------------------------------------------------------------------------\n";
                    flag++;
                }
            }
            if(!flag)
                cout<<"OOPS! There's no ex-Customer for that Room No.\n";\
            fin.close();
            break;
        }
    default:
        cout<<"OOPS! Wrong Option Selected!\n";
    }
}
void cancel()
{
    customer c1;
    char ch,ch1;
    char str[251];
    int num,flag=0;
    fstream file1;
    fstream file2,file3;
    cout<<"Pls Enter Your Room No.: ";
    cin>>num;
    file2.open("HOTEL.dat",ios::in|ios::binary);
    while(file2.read((char*)&c1,sizeof(c1)))
    if(c1.retroomno()==num)
    {
        flag++;
        if(!c1.retcheckinstatus())
        flag++;
        break;
    }
    file2.close();
    if(flag==2)
    {
        cout<<"Are you sure you want to CANCEL the BOOKING\n(Press 'y' to confirm)\n";
        cin>>ch1;
        if((ch1=='y')||(ch1=='Y'))
        {
            file1.open("rooms.txt",ios::in);
            file1>>str;
            file1.close();
            int i=num-1;
            if(str[i]=='o')
            {
                str[i]='u';
                file1.open("rooms.txt",ios::out);
                file1<<str;
                file1.close();
                cout<<"Your booking has been successfully cancelled. We feel sad to see you go :( \n";
                file2.open("HOTEL.dat",ios::binary|ios::in);
                file3.open("temp.dat",ios::binary|ios::out);
                while(file2.read((char*)&c1,sizeof(c1)))
                {
                    if(num!=c1.retroomno())
                    file3.write((char*)&c1,sizeof(c1));
                }
                file2.close();
                file3.close();
                remove("HOTEL.dat");
                rename("temp.dat","HOTEL.dat");
            }
        }
    }
    else if (flag==1)
        cout<<"Sorry for the inconvenience. Booking cannot be cancelled as you're checked-in.\n";
    else
        cout<<"OOPS! Wrong Room No. Entered.\n";
}
void restaurant()
{
	cout<<"\n***************Welcome to the BARRISTA!*****************\n\n";
	float price[113]={245,245,245,245,240,240,240,240,235,235,250,235,235,
	220,215,230,215,240,250,250,250,250,250,250,250,255,245,245,245,245,
	250,240,240,360,290,360,290,370,295,360,290,360,290,250,360,290,360,
	290,250,370,290,360,290,250,250,280,245,290,235,265,240,290,300,256,
	240,265,270,255,255,240,240,235,220,25,30,25,30,35,35,25,30,35,25,35,
	25,25,30,100,105,105,100,105,100,105,125,105,105,100,105,110,115,100,
	100,100,105,105,105,105,125,105,120,120,120};
    char *dishes[]={"SHAHI PANEER", "KADAI PANEER", "CHEESE KORMA", "MALAI KOFTA", "MATAR PANEER", "PALAK PANEER", "MIX VEG.", "ALOO GOBI", "ALOO JEERA", "CHANA MASALA", "MATAR MUSHROOM", "RAJMA MAKHANI", "DAL MAKHANI", "MIXED RAITA", "BUNDI RAITA", "PINEAPPLE RAITA", "SALAD(GREEN)", "DUM ALOO", "MUSHROOM PANEER", "MUTTON MASALA", "MUTTON MUGHLAI", "MUTTON KORMA", "MUTTON DO PYAZA", "MUTTON SAGH", "MUTTON DAHI", "MUTTON ROGAN JOS", "MUTTON CURRY", "KADAI MUTTON", "KEEMA LEVER", "KEEMA MATAR", "KEEMA EGG", "BRAIN CURRY", "EGG CURRY", "BUTTER CHICKEN", "BUTTER CHICKEN(1/2", "KADAI CHICKEN", "KADAI CHICKEN(1/2)", "BUTTER CHICKEN", "BUTTER CHICKEN(BL)(1/2)", "CHICKEN MUGHLAI", "CHICKEN MUGHLAI(1/2", "CHICKEN MASALA", "CHICKEN MASALA(1/2", "CHICKEN MASALA(1/4", "CHICKEN SAGH", "CHICKEN SAGH(1/2", "CHICKEN DAHI", "CHICKEN DAHI(1/2)", "CHICKEN DAHI(1/4)", "CHICKEN KORMA", "CHICKEN KORMA(1/2)", "CHICKEN DO PYAZ", "CHICKEN DO PYAZA(1/2)", "FISH CURRY", "CHICKEN CURRY", "CHICKEN CURRY(1/2)", "CHICKEN CURRY(1/4)", "CHILLI CHICKEN", "TANDOORI ALOO", "CHICKEN TIKKA", "SEEKH KABAB", "FISH TIKKA", "CHICKEN TANDOOR", "CHICKEN TANDOORI(1/2", "PANEER TIKKA", "CHICKEN SEEKH KABA", "CHICKEN HARA KABA", "CHICKEN BIRYANI", "MUTTON BIRYANI", "PANEER PULAO", "VEG.PULAO", "JEERA RICE", "STEAMED RICE", "RUMALI ROTI", "ROTI ", "NAN ", "ALOO NAN", "PANEER NAN", "KEEMA NAN", "PARANTHA", "ALOO PARANTHA", "PANEER PARANTHA", "PUDINA PARANTHA", "BUTTER NAN", "LACHCHA PARANTH", "MISSI ROTI", "KHASTA ROTI", "VEG.BURGER", "PANEER BURGER", "CHEESE SANDWICH", "VEG.PATTI", "CHICKEN PATTI", "TEA       ", "COFFEE      ", "COLD COFFEE", "PINEAPPLE", "STRAWBERRY", "CHOCOLATE", "BLACK FOREST", "DOUBLE STORIED", "TRIPLE STORIED", "SOFT CONE", "VANILLA", "STRAWBERRY", "CHOCOLATE", "CHOCO CHIPS", "MANGO", "TUTTI FRUITY", "LICHI", "PISTA BADAM", "CHOCOLATE PISTA BADA", "CHOCO DIP", "CHOCOLATE LICHI"};
	cout<<"\tMenu\n";
    for(int i=0;i<113;i++)
    {
        cout<<i+1<<") "<<dishes[i]<<setw(28-strlen(dishes[i]))<<price[i]<<endl;
    }
	int n,k,choice,flag=1;
	char ch;
	float total=0;
	do
	{
		cout<<"\nWhat would you like to have?\n";
		cin>>n;
		if((n>=1)&&(n<=113))
        {
            k=n-1;
            total+=price[k];
            cout<<"What to have more?(press'y' to confirm, 'n' if you're done)\n";
            cin>>ch;
        }
        else
        {
            cout<<"OOPS! Wrong option selected\n";
            cout<<"Do you want to select another option?\n";
            cin>>ch;
            if(ch=='n')
            flag=0;
        }
	}while((ch=='y')||(ch=='Y'));
	if(flag)
    {
        cout<<"Your Order is ready!!\n\n";
        do
        {
            cout<<"BIll AMOUNT: "<<total<<endl<<"(1) Would you like to pay the bill in restaurant \n'OR'\n(2) Shall I add it to your Hotel bill amount\n";
            cin>>choice;
            if(choice==1)
            {
                cout<<"\nYour Restaurant Bill is: "<<total<<"\nPlease pay it at the Counter\nTHANK YOU\nWE HOPE TO SEE YOU AGAIN!!\n";
                flag=1;
            }
            else
            if(choice==2)
            {
                int num;
                int flg=0;
                flag=1;
                fstream file;
                customer c;
                cout<<"Please Enter Your Room No.: ";
                cin>>num;
                file.open("HOTEL.dat",ios::binary|ios::in|ios::out);
                while(file.read((char*)&c,sizeof(c)))
                {
                    if(num==c.retroomno())
                    {
                        c.charge(total);
                        int s=file.tellg()-sizeof(c);
                        file.seekp(s);
                        file.write((char*)&c,sizeof(c));
                        flg++;break;
                    }
                }
                file.close();
                if(flg)
                {
                    cout<<"Your Restaurant Bill has been added to your Hotel Bill Amount\nThank You!\nWe Hope To See You Again!\n";
                }
                else
                    {
                        cout<<"OOPS! Wrong Room No. entered.\n\n";
                        flag=0;
                    }
            }
            else
            {
                cout<<"OOPS! Wrong option selected\n\n";flag=0;
            }
        }while(!flag);
    }
}
void taxiservice()
{
    int n,num,flag=0,x;
    cout<<"\n*************HOTEL TAXI SERVICE****************\n"<<"Are you staying in the hotel?\n(1)Yes\n(2)No\n";
    cin>>n;
    if(n==2)
        cout<<"Sorry! but Taxi service is only available for the hotel customers.\n";
    else
    if(n==1)
    {
        fstream file;
        customer c;
        date d;
        cout<<"Please Enter Your Room No.: ";
        cin>>num;
        file.open("HOTEL.dat",ios::binary|ios::in|ios::out);
        while(file.read((char*)&c,sizeof(c)))
        {
            if(num==c.retroomno())
            {
                flag++;break;
            }
        }

        if(flag)
        {
            cout<<"------------------------------------------------------------------------\n";
            cout<<"NO. OF TAXIS NEEDED:  ";
            cin>>x;
            cout<<"TAXI(s) NEEDED ON(dd mm yyyy): ";
            cin>>d.day>>d.month>>d.year;
            cout<<"\nTAXI(s) WILL BE WAITING FOR YOU ON ";
            d.display();
            cout<<"------------------------------------------------------------------------\n";
            cout<<endl<<endl;
        }
        else
            cout<<"\nOOPS! Wrong Room No. entered.\n";
    }
    else
        cout<<"OOPS! Wrong option selected.\n";
}
void Swimming()
{
    int choice;
    cout<<"1)Hotel customers\n2)Members of this facility\n3)Want to become a member?(Rs. 1000/year)\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        customer c1;
        int num,flag=0;
        cout<<"Please Enter Your Room No.: \n";
        cin>>num;
        fstream fin("HOTEL.dat",ios::binary|ios::in);
        while(fin.read((char*)&c1,sizeof(c1)))
        if(c1.retroomno()==num)
        {
            flag++;break;
        }
        if(flag)
		  cout<<"Your room number is verified.\nYou can just head over to the pool and start swimming! :D\n";
        else
		  cout<<"OOPS! Wrong Room No. entered.\n";
        break;
    }
    case 2:
    {
        int num;char str[251];
        cout<<"Please Enter Your Membership Code: ";
        cin>>num;
        fstream fin("pool.txt",ios::in);
        fin>>str;
        fin.close();
        if(str[num-1]=='o')
            cout<<"Just Head over to the pool! :D\n";
        else
            cout<<"OOPS! Wrong Code entered.\n";
        break;
    }

    case 3:
    {
        member p1(1);
        if(p1.assigncode())
        {
            cout<<"Pls fill up the following form and submit it along with Rs. 1000 to the receptionist.\n";
            cout<<"------------------------------------------------------------------------\n";
            p1.read();
            cout<<"------------------------------------------------------------------------\n";
            fstream fout("pool.dat",ios::binary|ios::out);
            fout.write((char*)&p1,sizeof(p1));
            fout.close();
        }
        else
            cout<<"We have no vacancies. We're sorry for the inconvenience. \n";
        break;
    }
    default:
        cout<<"OOPS! Wrong option selected\n";
    }
}
void gym()
{
    int flag=0,choice;
    cout<<"1)Hotel customers\n2)Members of this facility\n3)Want to become a member?(Rs. 1000/year)\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        customer c1;
        int num;
        cout<<"Please Enter Your Room No.: ";
        cin>>num;
        fstream fin("HOTEL.dat",ios::binary|ios::in);
        while(fin.read((char*)&c1,sizeof(c1)))
        if(c1.retroomno()==num)
        {
            flag++;break;
        }
        if(flag)
		  cout<<"Your room number is verified.\nYou can just head over to the gym!:D\n";
        else
		  cout<<"OOPS! Wrong Room No. entered.\n";
        break;
    }
    case 2:
    {
        int num;char str[251];
        cout<<"Please Enter Your Membership Code: ";
        cin>>num;
        fstream fin("gym.txt",ios::in);
        fin>>str;
        fin.close();
        if(str[num-1]=='o')
            cout<<"Just Head over to the gym! :D\n";
        else
            cout<<"OOPS! Wrong code entered.\n";
        break;
    }

    case 3:
    {
        member g1(2);
        if(g1.assigncode())
        {
            cout<<"Pls fill up the following form and submit it along with Rs. 1000 to the receptionist.\n";
            cout<<"------------------------------------------------------------------------\n";
            g1.read();
            cout<<"------------------------------------------------------------------------\n";
            fstream fout("gym.dat",ios::binary|ios::out);
            fout.write((char*)&g1,sizeof(g1));
            fout.close();
        }
        else
            cout<<"We have no vacancies. We're sorry for the inconvenience. \n";
        break;
    }
    default:
        cout<<"OOPS! Wrong option selected\n";
    }
}
int main()
{
    system("color F1");
    int choice;char ch;
    cout<<"*************WELCOME TO HOTEL TAJ!************\n\n";
    do
    {
        cout<<"What would you like to do?\n\n";
        cout<<"1) Book\n2) Check-in\n3) Check-out\n4) View Data\n5) Cancellation\n6) Restaurant\n7) Taxi Service\n8) Swimming pool\n9) Gymnasium\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"--------------------------BOOKING---------------------------------------\n";
                book();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;

                break;
            case 2:
                cout<<"-------------------------CHECK-IN---------------------------------------\n";
                checkin();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 3:
                cout<<"-------------------------CHECK-OUT---------------------------------------\n";
                checkout();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 4:
                cout<<"-------------------------VIEWDATA---------------------------------------\n";
                viewdata();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 5:
                cout<<"-------------------------CANCELLATION-----------------------------------\n";
                cancel();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 6:
                cout<<"--------------------------RESTAURANT------------------------------------\n";
                restaurant();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 7:
                cout<<"-------------------------TAXI-SERVICE-----------------------------------\n";
                taxiservice();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 8:
                cout<<"---------------------------SWIMMING-------------------------------------\n";
                Swimming();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            case 9:
                cout<<"-------------------------GYMNASIUM-------------------------------------\n";
                gym();
                cout<<"------------------------------------------------------------------------\n";
                cout<<"Anything Else?\n";
                cin>>ch;
                break;
            default:
                cout<<"OOPS! Wrong option selected!\n";
                cout<<"Do you want to continue?\n";
                cin>>ch;
        }
    }while(ch=='y'||ch=='Y');
    cout<<"Hope you have a good day ahead!\n\nCheers!\n";
}
