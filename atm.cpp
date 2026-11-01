#include <iostream>
using namespace std;

int main ()
{
    int choice , deposit  , withdraw , enterd_pin , set_PIN{1234} , tries{3} ;
    double balance , amount , years , interest , interest_amount , new_balance;
    balance = 1000;

do
{                   //PIN
    cout << "Enter your PIN." << endl;
    cout << "PIN: ";
    cin >> enterd_pin ;
    if(enterd_pin != set_PIN)
    cout << "WORNG PIN, you got " << tries-- << "left before locking out." << endl;


    

            // Options Menu
        do
        {
    
        cout << "\n 1. Balance Check\n 2. Deposit Money\n 3. Withdraw Money\n 4. Claculate Simple Interest\n 5. Exit\n\nEnter your choice: ";
        cin >> choice;
         switch ( choice)
         {
            case 1:
                cout << "your balance is " << balance << "$\n";
                break;
            case 2:
                cout << "How much would you like to deposit?\n";
    
                do
                { cin >> deposit;}
                while(deposit < 0);
    
                balance += deposit;
                cout << "your balance is now " << balance << "$";
                break;
            case 3: 
                 cout << "How much would you like to withdraw?\n";
                    do
                    {cin >> withdraw;}
                     while( withdraw < 0 );
                     
                      balance -= withdraw;
                 cout << "your balance is now " << balance << "$";
                break;
            case 4: 
                 cout << "How much is the amount? \n amount: ";
                     do
                    {cin >> amount;}
                    while( amount < 0);
                 cout << "How much is the interest? \n interest: "; 
                    do
                    {cin >> interest; }
                    while(interest < 0);
                 interest_amount = (interest / 100.0);
                 cout << "For how long? (in years) \n years: ";
                    do 
                    {cin >> years;}
                    while( years < 0);
                    
                 cout << "so " << amount << "$ by " << interest << "% " << "interest, for "<< years << " years would be... " << ((amount * interest_amount * years) + amount) << "$\n" ;
                 break;
    
            case 5:
            cout << "Thank you for using the ATM. Goodbye!\n";
            break;
    
            default:
            cout << "Invalid choice! Please select between 1 and 5.\n";  
         }
        }
        while(choice !=5);
}
while(tries <= 0);
    
}