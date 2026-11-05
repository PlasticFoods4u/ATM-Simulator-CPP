#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void cin_guard (int &value);
void cin_guard (double &value);
void coin_flip(int bet , double &balance);
void number_check(int withdraw_deposit_amount , int &tries1);
int menu(int choice , double &balance);

int main ()
{
    int coin_result , bet{0} , choice , withdraw_deposit_amount   , enterd_pin , set_PIN{1234} , tries{3} , tries1 , output ;
    double balance , amount , years , interest , interest_amount , new_balance;
    balance = 1000;

    srand(time(0));

    cout << "\n\n                         _____" << endl;
    cout << "               /\\          |        /\\    /\\" << endl;
    cout << "              /__\\         |       /  \\  /  \\" << endl;
    cout << "             /    \\        |      /    \\/    \\\n" << endl;

do
{                   //PIN
    cout << "Enter your PIN." << endl;
    cout << "PIN: ";
        
        cin_guard(enterd_pin);
        if(enterd_pin != set_PIN)
        {
            cout << "\nWORNG PIN, you got " << --tries << " tries left before locking out." << endl;
            if(tries == 0)
            cout << "\nLOCKED OUT. \n contact the bank to lift the lockdown up if you'r the owner" << endl;
        }
        else 
            break;
}
while(tries >= 0);
    

menu(choice , balance);     
}
////////////////////////////////////////////Functions///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Main ATM menu.
// Handles all user actions and updates balance.
int menu(int choice , double &balance)
{
 int  bet{0} , withdraw_deposit_amount   , enterd_pin , set_PIN{1234} , tries{3} , tries1{3} ;
    double  amount , years , interest , interest_amount , new_balance;
            // Options Menu
            do
        {
            
            cout << "\n\n 1. Balance Check\n 2. Deposit Money\n 3. Withdraw Money\n 4. Claculate Simple Interest\n 5. Exit\n 6. Gambling Bouns\n\nEnter your choice: ";
            cin_guard(choice);
        
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
                        cin_guard(withdraw_deposit_amount);
                        number_check(withdraw_deposit_amount , tries1);
                }
                while(withdraw_deposit_amount < 0);
                    balance += withdraw_deposit_amount;
                    cout << "your balance is now " << balance << "$";
                break;
                    // withdraw
            case 3:
               cout << "How much would you like to withdraw?\n";
                do
                { 
                        cin_guard(withdraw_deposit_amount);
                        number_check(withdraw_deposit_amount , tries1);
                    }
                    while(withdraw_deposit_amount < 0);
                    if (withdraw_deposit_amount > balance)
                    {
                        cout << "you cant withdraw more than you have in your balance which is " << balance << " $" << endl;
                    }
                    else
                    {
                        balance -= withdraw_deposit_amount;
                        cout << "your balance is now " << balance << " $";
                    }
                break;
                // interest calculater   make it into a function later.
            case 4: 
                 cout << "How much is the amount? \n amount: ";
                     do
                    {cin_guard(amount);}
                    while( amount < 0);
                 cout << "How much is the interest? \n interest: "; 
                    do
                    {cin_guard(interest); }
                    while(interest < 0);
                 interest_amount = (interest / 100.0);
                 cout << "For how long? (in years) \n years: ";
                    do 
                    {cin_guard(years);}
                    while( years < 0);
                    
                 cout << "so " << amount << "$ by " << interest << "% " << "interest, for "<< years << " years would be... " << ((amount * interest_amount * years) + amount) << "$\n" ;
                 break;
                    // exist
            case 5:
             cout << "Thank you for using the ATM. Goodbye!\n";
             return 0;
            break;
                // gambling game
            case 6:
                cout << "how much you want bet on this coin flip?\n";
                
                    cout << "Bet: ";
                    cin_guard(bet);
                    // add  so you bet more than you have and no negeative numbers
                    if (bet > 0 && bet <= balance)
                    {
                        coin_flip(bet , balance);
                    }
                    else if (bet > balance)
                    {
                        cout << "\nYou cant bet money you dont have. you only have " << balance << " $" << endl ;
                    }
                    else
                    {
                        cout << "\nYou can't bet negeative numbers.";
                    }
                    break;
            
            default:
            cout << "Invalid choice! Please select between 1 and 5.\n"; 
             
         }
        }
        while(choice !=5);
        return 0;
}

// Prevents negative deposit/withdraw amounts.
// After too many invalid attempts the account is frozen.
void number_check(int withdraw_deposit_amount , int &tries1)
{
    if(withdraw_deposit_amount < 0)
 {
    cout << "You cant enter a negeative amount, you got " << -- tries1 << " tries before your account gets frozen" <<endl;
    if(tries1 == 0)
    cout << "\nACCOUNT FROZEN. CONTACT THE BANK.\n" << endl;
 }
}

// Simple gambling minigame.
// User bets money and has a 50/50 chance to double it or lose it.
void coin_flip(int bet , double &balance)
{
    int coin_result ;
                balance -= bet;
                coin_result = rand() % 2;
                if(coin_result == 1)
                {
                    bet *= 2;   balance += bet;
                    cout << "\nyour coin flip landed on heads so your bet ammount is doubled \n balance: " << balance << endl;
                }
                else
                  cout << "\nyour coin flip landed on tails so you gained nothing :( ";
}

// Integer input validation.
// Prevents the user from entering text when a number is expected.
void cin_guard (int &value)
{
    while(true)
    {                                  
        if(!(cin >> value))
            {                          
                cout << "please enter a valid number...\n";

                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue;
            }
             else
             break;
    }
}
// Floating point input validation.
// Used when decimal numbers are allowed.
void cin_guard (double &value)
{
    while(true)
    {                                  
        if(!(cin >> value))
            {                          
                cout << "please enter a valid number...\n";

                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue;
            }
             else
             break;
    }
}
