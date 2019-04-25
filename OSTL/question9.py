acclist=[]

class Account:
    balance = 500.0
    rate = 0.07
    count = 1000

    def createAccount(self):
        self.name = str(input('Enter name'))
        self.address = str(input('Enter address'))
        self.contact = int(input('Enter contact number '))
        Account.count += 1
        self.accno = Account.count
    
    def computeInterest(self):
        return self.balance*self.rate

    def deposit(self):
        add = int(input('Enter the amount of interest '))
        self.balance += Account.computeInterest(self) + add
    
    def withdraw(self):
        sub = int(input('Enter the amount to withdraw'))

        if(self.balance - sub < 0):
            print("Cannot withdraw ")
        else:
            self.balance -= sub

        print("Account balance is {self.balance}")


    def __str__(self):
        return(f"-----Account Details-----\nAccount number: {self.accno}\nAccount name: {self.name}\nBalance: {self.balance}\nAddress: {self.address}\nContact: {self.contact}\n")

def menu(Acc):
    while(True):
        print('Deposit : ')
        print('Withdraw : ')
        print('Show details : ')
        print('Return: ')
        choice = int(input('Enter :'))

        if(choice == 1):
            Acc.deposit()
        elif(choice == 2):
            Acc.withdraw()
        elif(choice == 3):
            print(Acc)
        elif(choice == 4):
            break
        else:
            print('Wrong Choice')


while(True):
    print('Create New Account : ')
    print('Show All account : ')
    print('Exit : ')
    ch = int(input("Enter : "))

    if(ch == 1):
        new = Account()
        new.createAccount()
        menu(new)
        acclist.append(new)

    elif ch == 2:
        print('List of accounts ')

        if(acclist):
            for accounts in acclist:
              print(accounts.accno)

    elif ch == 3:
        print("Thank you")
        break

    else:
        print("Wrong Choice")

