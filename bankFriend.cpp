#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
    private:
        string account_holder;
        double balance;

    public:
        // Constructor
        BankAccount(string name, double bal)
        {
            account_holder = name;
            balance = bal;
        }

        // Const member function to display balance
        void display_balance() const
        {
            cout << "Account Holder: " << account_holder << endl;
            cout << "Balance: $" << balance << endl;
        }

        // Friend function declaration
        friend void apply_interest(BankAccount& account, double rate);
};

// Friend function definition
void apply_interest(BankAccount& account, double rate)
{
    account.balance += account.balance * rate;
}

int main()
{
    // Create a BankAccount object
    BankAccount myAccount("Alex Johnson", 1000.00);

    // Display initial balance
    cout << "Initial Account Balance:" << endl;
    myAccount.display_balance();

    // Apply interest (e.g., 5% interest)
    apply_interest(myAccount, 0.05);

    // Display updated balance
    cout << "\nAfter Applying Interest:" << endl;
    myAccount.display_balance();

    return 0;
}