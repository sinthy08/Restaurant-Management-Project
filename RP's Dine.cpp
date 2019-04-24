#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

///class diclaration..
class Admin;
class Customer;

///Global variables...
int i=0,n,j,k,l,choice,counter=0,counter1=0;
double result=0,gtotal=0,vat=0,hd=0;



///Global functions
void admin_menu();
void cus_menu();
void menu();
void print();
void readData();
void search1();
double order();
void search2();
void bar();
void cus_information();
void cus_output();


Admin *current;
Admin *p;
Admin *front;
Admin *f;



class Admin
{
private :
    int code;
    string item_name;
    double price;
    Admin *next;
public:
   Admin():code(0),item_name("n/a"),price(0.0),next(NULL){}
   ~Admin(){}


    int getCode()
   {
       return code;
   }
   string getItem_name()
   {
       return item_name;
   }
   double getPrice()
   {
       return price;
   }
void setNext(Admin *p)
{
    next=p;

}

Admin *getNext()
{
    return next;
}


    void read()
    {
        cout<<"Enter code: ";
        cin>>code;
        cout<<endl<<"Enter item name: ";
        cin>>item_name;
        cout<<endl<<"Enter price: ";
        cin>>price;
        cout<<endl;
   counter++;
    }

    void show ()
    {
        cout<<code<<setw(10)<<item_name<<setw(15)<<price<<endl;
    }

};

class Customer
{
private:
    string name;
    string lname;
    int cr;      //credit card no
    int con_num; //contact no
    string sex;
    string h;    //home
    string rd;  //road name

public:
    Customer():name("n/a"),lname("n/a"),con_num(0),cr(0),sex("n/a"),h("n/a"),rd("n/a"){}
    ~Customer(){}

    string getName(){return name;}
    int getCr(){return cr;}
    int getCon_num(){return con_num;}
    string getSex(){return sex;}
    string getRd(){return rd;}

    void cusinfo ()
    {
        cout<<"Enter 1st Name: ";
        cin>>name;
        cout<<"Enter last Name: ";
        cin>>lname;
        cout<<"Enter House number and Block: ";
        cin>>h;
        cout<<"Enter Road Name: ";
        cin>>rd;
        cout<<"Enter Contact Number: ";
        cin>>con_num;
        cout<<"Enter Sex: ";
        cin>>sex;
        cout<<"Enter Credit Card number: ";
        cin>>cr;
        cout<<endl;
        counter1++;
    }

 void cus_out()
 {
            cout<<endl<<"Name: "<<name;
            cout<<endl<<"Last Name: "<<lname;
            cout<<endl<<"House number and block: "<<h;
            cout<<endl<<"Road Name: "<<rd;
            cout<<endl<<"Contact number: "<<con_num;
            cout<<endl<<"Sex: "<<sex;
            cout<<endl<<"Credit Card number: "<<cr<<endl<<endl;
 }
}cus;

int main ()
{
   cout<<endl<<"     ***Welcome to RP's Restaurant***"<<endl<<endl;

    int pass,ispass=1234;

    for(;;)
    {
        menu();

        cout<<"Enter your choice: ";
        cin>>k;
        cout<<endl;

        if (k==1)
        {
          for(;;)
            {
                cus_menu();
                cout<<endl<<"Enter your choice: "<<endl;
                cin>>j;
                 if(j==1)
                    print();
               else if (j==2)
                  {
                      if(counter==0)
                    {
                        cout<<"Sorry, no foods available"<<endl;
                    }

                    else
                        {

                        result=order();
                        vat=result*0.075;
                        gtotal=result+vat;
                         cout<<endl;
                         cout<<"Customer information.."<<endl<<endl;
                         cus_output();
                        cout<<"Total :"<<result<<endl;
                        cout<<"Grand Total (Including 7.5% vat) : "<<gtotal<<endl<<endl;
                        cout<<"      Thanks for ordering..."<<endl;
                        cout<<"  Your food will be delivered soon."<<endl;
                        }
                  }
                else if(j==3)
                    break;
                else
                    cout<<"Invalid input"<<endl;
            }

        }
        else if (k==2)
        {
            cout<<"Enter Password:  ";
            cin>>pass;
            cout<<endl;
            if (pass==ispass)
            {
              for(;;)
                {
                    admin_menu();
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    cout<<endl;
                    if(choice==1)
                        print();
                        else if (choice==2)
                         readData();

                    else if (choice==3)
                     {
                         if(counter==0)
                            cout<<"No Foods Available"<<endl;
                         else
                            {
                      cout<<"Press 1 for search by Code"<<endl;
                      cout<<"Press 2 for search by Name"<<endl;
                        cin>>n;

                            if (n==1)
                                search1();
                            else if (n==2)
                                search2();
                            else
                                cout<<"Invalid Input"<<endl;

                            }
                    }
                    else if(choice==4)
                        break;
                    else
                        cout<<"invalid input"<<endl;
                }

            }

            else
                cout<<"Wrong password!!! Try again later"<<endl;

        }

        else if(k==3)
                break;
         else cout<<"Invalid Input"<<endl;
    }

    cout<<"*** Thank You ***"<<endl<<"  Have a Good Day  "<<endl;



    return 0;

}

void menu()
{
    cout<<endl;
    cout<<"============== MAIN MENU ================"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Press 1 if you are a Customer"<<endl;
    cout<<"Press 2 if you wanted to sign as an admin"<<endl;
    cout<<"Press 3 for Exit"<<endl<<endl;
    cout<<"========================================="<<endl<<endl;
}


void readData ()
{
     char ch;
     int i=0;
while(true)
    {   f=new Admin;
        p=new Admin;
        p->read();

        if(i==0)
        {
            front=p;
            current=p;
        }

        else
        {
        current->setNext(p);
        current=p;
        }
        i++;

    cout<<"Do you want to continue y/n "<<endl;
    cin>>ch;
    if(ch=='y')
    continue;
    else if(ch=='n')
        break;
    else cout<<"Invalid input"<<endl;
    }
}


void bar()
{
        cout<<"Code      "<<setw(4)<<"Item name   "<<setw(10)<<"Price"<<endl;
        cout<<"---------------------------------------------------"<<endl;
}

void print()
{
current=front;

 if (current==NULL)
        cout<<"No Foods Available"<<endl;

    else
        {
             cout<<"Code      "<<setw(4)<<"Item name   "<<setw(10)<<"Price"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            while(current!=NULL)
            {
                current->show();
                current=current->getNext();
            }
        }

}

void admin_menu()
{
    cout<<endl;
    cout<<"        ***  ADMIN MENU   ***"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Press 1 for watching the food menu"<<endl;
    cout<<"Press 2 for Adding a food item"<<endl;
    cout<<"Press 3 for Searching an item"<<endl;
    cout<<"Press 4 to Exit"<<endl;
}

void cus_menu()
{
    cout<<endl;
    cout<<"    ===== Customer Menu =====   "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Press 1 for watching the food menu"<<endl;
    cout<<"Press 2 for Ordering"<<endl;
    cout<<"Press 3 to Exit"<<endl;

}



void search1()
{
    if(counter==0)
    {
        cout<<"No foods available"<<endl;
    }
    else{
            cout<<"Enter code: ";
            cin>>n;
            cout<<endl;

            current=front;

            while(current!=NULL)
            {
                if(current->getCode()==n)
                {
                    bar();
                    current->show();
                }
                    current=current->getNext();
            }
        }
}


void search2 ()
{
  string itname;   //item name

    if(counter==0)
        cout<<"No foods available"<<endl;
    else
    {
    cout<<"Enter Name: ";
         cin>>itname;
         cout<<endl;
              current=front;
            while(current!=NULL)
            {
                    if(current->getItem_name()==itname)
                       {
                             bar();
                            current->show();
                       }
                    current=current->getNext();

            }

    }
}


void cus_information()
{
    cus.cusinfo();
}

void cus_output()
{
    cus.cus_out();
}


double order ()
{
    double r=0;
    int c;
    int i=0;
    char ch;
    current=front;
    int amt;

    cus_information();

    for(i=0;i<100;i++)
        {
            cout<<"Enter Codes that you want to order: "<<endl;
            cin>>c;
            cout<<"Enter Amount of this Dish: ";
            cin>>amt;
        current=front;

              while(current!=NULL)
                {
                  if(current->getCode()==c)
                    {
                        bar();
                        current->show();
                        r+=(current->getPrice()*amt);

                    }
                    current=current->getNext();
                }

            cout<<"Do you want to continue? (y/n) "<<endl;
                    cin>>ch;
                    if(ch=='y')
                    continue;
                    else if(ch=='n')
                        break;
                    else cout<<"Invalid input"<<endl;
        }


return r;
}

