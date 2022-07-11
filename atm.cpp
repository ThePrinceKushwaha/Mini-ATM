#include<iostream>
#include<conio.h>
#include<string>

/*
----------MiniProject: ATM----------
-    -> Check Balance              -
-    -> Cash Withdraw              -
-    -> User details               -
-    -> Update mobile  no.         -
------------------------------------
*/

using namespace std;

class atm
{
    private:
        long int account_No;
        string name; 
        int PIN;
        double balance;
        string mobile_No;

    public:
        // setData is setting the data into the private member variables
        void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
        {
            account_No=account_No_a;
            name=name_a;
            PIN=PIN_a;
            balance=balance_a;
            mobile_No=mobile_No_a;

        }

        // getAccountNo function is returning the user's account no.
        long int getAccountNo()
        {
            return account_No;
        }

        // getName function is returning the user's name
        string getName(){
            return name;
        }

        //getPIN function is returning the user's users pin
        int getPIN(){
            return PIN;

        }

        // getBalance function is returning the user's balance in his accounts
        double getBalance(){
            return balance;
        }

        //getMobile returns the user mobile number
        string getMobile(){
            return mobile_No;
        }
        
        //setMobile function is updating the user mobile no.
        void setMobile(string prev_mobile, string new_mobile){
              if(prev_mobile==mobile_No){
                mobile_No=new_mobile;
                cout<<endl<<"Phone number successfully updated.";
                cout<<endl<<"Enter any key to return to main-menu"<<endl;
                _getch();
              }
              else{
                cout<<"Old Phone number doesn't matches.!!!\n Please enter the correct phone number.";
                _getch();
              }
        }


        void cashWithdraw(int amount_a){
            if(amount_a>0 && amount_a<balance){
                balance -= amount_a;
                cout<<endl<<"Please Collect Your cash";
                cout<<endl<<"Your new balance is: "<<balance;
                // cout<<endl<<"Enter any key to return to main-menu"<<endl;
                _getch();
            }
            else{
                cout<<endl<<"Invalid Input or Insufficient Balance in your Account."<<endl;
                
                _getch();
            }
        }

};



//
int main()
{
    int enterPin, choice=0;         // enterPin for authentication
    long int enterAccountNo;        // enterAccountNo for validation

    system("cls");                  // clear the console screen
    
    // creating object for amt user
    atm user1;


    //setting the users details for compile time
    // set user details into object
    user1.setData(1234567890, "Dev", 1234, 194052.64, "9845798672");

    do{
        system("cls");

        cout<<endl<<"********Welcome to ATM********";
        cout<<endl<<"Enter your Account Number: ";
        cin>>enterAccountNo;

        cout<<endl<<"Enter your valid ATM pin: ";
        cin>>enterPin;

        // validating the user entered account number and pin number
            if((enterAccountNo==user1.getAccountNo())&&(enterPin==user1.getPIN()))
            {
                do{
                    int amount=0;
                    string oldMobileNo, newMobileNo;

                    system("cls");

                    // user Interface
                    cout<<endl<<"********Welcome to ATM********"<<endl;
                    cout<<endl<<"Select options";
                    cout<<endl<<"1. Check Balance";
                    cout<<endl<<"2. Cash Withdraw";
                    cout<<endl<<"3. View User Details";
                    cout<<endl<<"4. Update Mobile Number";
                    cout<<endl<<"5. Exit"<<endl;
                    cin>>choice;        // get the user choice to perform the actions


                    switch(choice){

                        case 1:
                            cout<<endl<<" Your Account Balance is: "<<user1.getBalance();
                            _getch();
                            break;
                        
                        case 2:
                            cout<<endl<<"Enter amount: ";
                            cin>>amount;
                            user1.cashWithdraw(amount);

                            break;
                        
                        case 3:
                            cout<<endl<<"Account No.: "<<user1.getAccountNo();
                            cout<<endl<<"Account Holder Name: "<<user1.getName();
                            cout<<endl<<"Balance: "<<user1.getBalance();
                            cout<<endl<<"Mobile Number: "<<user1.getMobile();
                            // cout<<endl<<"Enter any key to return to main-menu"<<endl;
                            _getch();
                            break;
                        
                        case 4:
                            cout<<endl<<"Enter old mobile number: ";
                            cin>>oldMobileNo;                             // takes the old registered mobile number for validation/ authentication

                            cout<<endl<<"Entey New Mobile Number: ";       // takes the new user mobile number for update
                            cin>>newMobileNo;

                            user1.setMobile(oldMobileNo, newMobileNo);    // set the new user mobile number

                            break;

                        case 5:
                            exit(0);            // exit the ATM Application
        
                        default:
                            cout<<endl<<"Invalid Input.\n Please enter valid input. ";

                    }
                } while(1);
            } 
            else{
                cout<<endl<<"Please enter the valid account number and atm pin.";
                _getch();
            }


    }
        while(1);


    return 0;
}