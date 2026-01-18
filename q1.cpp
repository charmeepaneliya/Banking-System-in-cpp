#include <iostream>
#include <string>
using namespace std;


class BankAccount {
    protected:
        int accountNumber;
        string accountHolderName;
    private:
        double balance; 
    public:
        BankAccount(int accNo, string name, double bal) {
            accountNumber = accNo;
            accountHolderName = name;
            balance = bal;
        } 
        
     
        virtual ~BankAccount() {}

       
        void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Rs. " << amount << " deposited successfully!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }
        virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Rs. " << amount << " withdrawn successfully!\n";
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }
        
        double getBalance() {
            return balance;
        }

        
        void displayAccountInfo() {
            cout<<"\n..........Account details..........\n";
            cout << "\nAccount Number : " << accountNumber << endl;
            cout << "Account Holder : " << accountHolderName << endl;
            cout << "Balance        : " << balance << endl;
        }
        
        virtual void calculateInterest() {
            cout << "Interest not applicable for this account.\n";
        }
        protected:
    
    void setBalance(double newBalance) {
        balance = newBalance;
    }

};



class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    public:
        SavingsAccount(int accNo, string name, double bal, double rate)
            : BankAccount(accNo, name, bal) {
            interestRate = rate;
        }
        
        void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        cout << "\n--- Savings Account Interest Calculation ---\n";
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Current Balance: Rs. " << getBalance() << endl;
        cout << "Interest Earned: Rs. " << interest << endl;
        cout << "-------------------------------------------\n";
    }
};



class ChekingAccount : public BankAccount {
    private:
        double overdraftLimit;
    public:
        ChekingAccount(int accNo, string name, double bal, double limit)
            : BankAccount(accNo, name, bal) {
            overdraftLimit = limit;
        }

       void withdraw(double amount) override {
        if (amount > 0) {
            if (checkOverdraft(amount)) {
                double newBalance = getBalance() - amount;
                setBalance(newBalance);
                cout << "Amount Rs. " << amount << " withdrawn successfully!\n";
                if (newBalance < 0) {
                    cout << "Note: Overdraft used. Current balance: Rs. " << newBalance << endl;
                }
            } else {
                cout << "Withdrawal denied! Exceeds overdraft limit.\n";
            }
        } else {
            cout << "Invalid amount!\n";
        }
    }
    bool checkOverdraft(double amount) {
        double potentialBalance = getBalance() - amount;
        if (potentialBalance >= -overdraftLimit) {
            return true;
        }
        cout << "\n--- Overdraft Check ---\n";
        cout << "Requested Amount: Rs. " << amount << endl;
        cout << "Current Balance: Rs. " << getBalance() << endl;
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
        cout << "This withdrawal exceeds your overdraft limit!\n";
        cout << "----------------------\n";
        return false;
    }

};



class FixedDepositAccount : public BankAccount {
    private:
        int termMonths; // in months
    public:
        FixedDepositAccount(int accNo, string name, double bal, int months)
            : BankAccount(accNo, name, bal) {
            termMonths = months;
        }

         void calculateInterest() override {
        
        double annualRate = 6.0;
        double interest = getBalance() * annualRate * termMonths / (12 * 100);
        
        cout << "\n--- Fixed Deposit Interest Calculation ---\n";
        cout << "Term Period: " << termMonths << " months\n";
        cout << "Annual Interest Rate: " << annualRate << "%\n";
        cout << "Principal Amount: Rs. " << getBalance() << endl;
        cout << "Interest Earned: Rs. " << interest << endl;
        cout << "Maturity Amount: Rs. " << (getBalance() + interest) << endl;
        cout << "------------------------------------------\n";
    }
     void withdraw(double amount) override {
        cout << "Warning: Withdrawals from Fixed Deposit may incur penalties!\n";
        cout << "Contact bank for premature withdrawal.\n";
    }
};



int main() {
    BankAccount* account = nullptr;

    int accNo;
    string name;
    double balance;

    cout<<"Enter Account Number: ";
    cin>>accNo;

    cout<<"Enter Account Holder Name: ";
    cin>>name;  

    cout<<"Enter Initial Balance: ";
    cin>>balance;   

    cout << "Select Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Checking Account\n";
    cout << "3. Fixed Deposit Account\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        double rate;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        account = new SavingsAccount(accNo, name, balance, rate);
    } else if (choice == 2) {
        double limit;
        cout << "Enter Overdraft Limit: ";
        cin >> limit;
        account = new ChekingAccount(accNo, name, balance, limit);
    } else if (choice == 3) {
        int months;
        cout << "Enter Term Period (in months): ";
        cin >> months;
        account = new FixedDepositAccount(accNo, name, balance, months);
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    int option;
    double amount;
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Info\n";
        cout << "5. Calculate Interest\n";
        cout << "0. Exit\n";
        cin >> option;

        if(option==1){
            cout<<"Enter amount: ";
            cin>>amount;
            account->deposit(amount);
        }else if(option==2){
            cout<<"Enter amount: ";
            cin>>amount;
            account->withdraw(amount);
        }else if(option==3){
            cout<<"Current Balance: "<<account->getBalance()<<endl;
        }else if(option==4){
            account->displayAccountInfo();
        }else if(option==5){
            account->calculateInterest();
        }else if(option==0){
            cout<<"Thank you\n";
        }else{
            cout<<"Invalid option\n";
        }
    }while(option!=0);
        delete account;
    
   
       
    return 0;
}