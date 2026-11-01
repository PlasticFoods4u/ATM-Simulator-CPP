#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main ()
{
    int coin_flip , bet{0} , choice , deposit  , withdraw , enterd_pin , set_PIN{1234} , tries{3} , tries1{3} ;
    double balance , amount , years , interest , interest_amount , new_balance;
    balance = 1000;

    srand(time(0));

    cout << "####################################################" << endl;
    cout << "####################](--ATM--)[#####################" << endl;
    cout << "####################################################\n" << endl;

do
{                   //PIN
   
    cout << "Enter your PIN." << endl;
    cout << "PIN: ";
    

    
  cin >> enterd_pin ;
    if(enterd_pin != set_PIN)
    {
        cout << "\nWORNG PIN, you got " << --tries << " tries left before locking out." << endl;
        if(tries == 0)
        goto lockdown;
    }
    else 
    break;
    
}
while(tries >= 0);
    

    

            // Options Menu
        do
        {
    
        cout << "\n 1. Balance Check\n 2. Deposit Money\n 3. Withdraw Money\n 4. Claculate Simple Interest\n 5. Exit\n 6. Gambling Bouns\n\nEnter your choice: ";
        cin >> choice;
         switch (choice)
         {
            case 1:
                cout << "your balance is " << balance << "$\n";
                break;
                // deposit
            case 2:
                cout << "How much would you like to deposit?\n";
                do
                { 
                    cin >> deposit;
                    if(deposit < 0)
                    {
                        cout << "You cant enter a negeative amount, you got " << --tries1 << " tries before your account gets frozen" <<endl;
                        if(tries1 == 0)
                        goto Account_frozen;
                    }
                }
                while(deposit < 0);

                balance += deposit;
                cout << "your balance is now " << balance << "$";
                break;
                    // withdraw
            case 3: 
                 cout << "How much would you like to withdraw?\n";
                    do
                    {cin >> withdraw;}
                     while( withdraw < 0 );
                     
                      balance -= withdraw;
                 cout << "your balance is now " << balance << "$";
                break;
                // interest calculater
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
                    // exist
            case 5:
                goto finish;
            break;
                // gambling game
            case 6:
                cout << "how much you want bet on this coin flip?\n";
                cin >> bet;               // add  so you bet more than you have and no negeative numbers
                balance -= bet;

                coin_flip = rand() % 2;
                if(coin_flip == 1)
                {
                    bet *= 2;   balance += bet;
                    cout << "\nyour coin flip landed on heads so your bet ammount is doubled \n balance: " << balance << endl;
                }
                else
                  cout << "\nyour coin flip landed on tails so you gained nothing :( ";
                break;
            
            default:
            cout << "Invalid choice! Please select between 1 and 5.\n";  
         }
        }
        while(choice !=5);

    lockdown:
        cout << "\nLOCKED OUT. \n contact the bank to lift the lockdown up if you'r the owner" << endl;
        return 0;

    Account_frozen:
        cout << "\nACCOUNT FROZEN. CONTACT THE BANK.\n" << endl;
        return 0;
    finish:
        cout << "Thank you for using the ATM. Goodbye!\n";


}
