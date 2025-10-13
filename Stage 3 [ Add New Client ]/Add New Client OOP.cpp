// Add New Client OOP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName : ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName : ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email : ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone : ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode : ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance : ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}


void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is already Used, Choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:

        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
        break;

    case clsBankClient::enSaveResults::svFaildEmptyObject :

        cout << "\nError Account was not saved because it's empty\n";
        break;

    case clsBankClient::enSaveResults::svFaildAccountNumberExists:

        cout << "\nError Account was not saved because Account Number is used!\n";
        break;
    }
}

int main()
{
    AddNewClient();

    system("pause>0");
    return 0;
}