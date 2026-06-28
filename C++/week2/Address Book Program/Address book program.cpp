#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

string names[MAX];
string phones[MAX];
string emails[MAX];
int countContact = 0;

//-----------------------------------
void loadContacts()
{
    ifstream file("contacts.txt");

    while (file >> names[countContact]
                >> phones[countContact]
                >> emails[countContact])
    {
        countContact++;
    }

    file.close();
}

//-----------------------------------
void saveContacts()
{
    ofstream file("contacts.txt");

    for (int i = 0; i < countContact; i++)
    {
        file << names[i] << " "
             << phones[i] << " "
             << emails[i] << endl;
    }

    file.close();
}

//-----------------------------------
void addContact()
{
    if (countContact == MAX)
    {
        cout << "Address Book is Full\n";
        return;
    }

    cout << "\nEnter Name : ";
    cin >> names[countContact];

    cout << "Enter Phone: ";
    cin >> phones[countContact];

    cout << "Enter Email: ";
    cin >> emails[countContact];

    countContact++;

    saveContacts();

    cout << "\nContact Added Successfully.\n";
}

//-----------------------------------
void viewContacts()
{
    if (countContact == 0)
    {
        cout << "\nNo Contacts Found.\n";
        return;
    }

    cout << "\n========== CONTACTS ==========\n";

    for (int i = 0; i < countContact; i++)
    {
        cout << "\nContact #" << i + 1 << endl;
        cout << "Name  : " << names[i] << endl;
        cout << "Phone : " << phones[i] << endl;
        cout << "Email : " << emails[i] << endl;
    }
}

//-----------------------------------
void searchContact()
{
    string name;

    cout << "\nEnter Name: ";
    cin >> name;

    for (int i = 0; i < countContact; i++)
    {
        if (names[i] == name)
        {
            cout << "\nFound\n";

            cout << "Name  : " << names[i] << endl;
            cout << "Phone : " << phones[i] << endl;
            cout << "Email : " << emails[i] << endl;

            return;
        }
    }

    cout << "\nContact Not Found.\n";
}

//-----------------------------------
void updateContact()
{
    string name;

    cout << "\nEnter Name to Update: ";
    cin >> name;

    for (int i = 0; i < countContact; i++)
    {
        if (names[i] == name)
        {
            cout << "\nEnter New Phone: ";
            cin >> phones[i];

            cout << "Enter New Email: ";
            cin >> emails[i];

            saveContacts();

            cout << "\nUpdated Successfully.\n";

            return;
        }
    }

    cout << "\nContact Not Found.\n";
}

//-----------------------------------
void deleteContact()
{
    string name;

    cout << "\nEnter Name to Delete: ";
    cin >> name;

    for (int i = 0; i < countContact; i++)
    {
        if (names[i] == name)
        {
            for (int j = i; j < countContact - 1; j++)
            {
                names[j] = names[j + 1];
                phones[j] = phones[j + 1];
                emails[j] = emails[j + 1];
            }

            countContact--;

            saveContacts();

            cout << "\nDeleted Successfully.\n";

            return;
        }
    }

    cout << "\nContact Not Found.\n";
}

//-----------------------------------
int main()
{
    loadContacts();

    int choice;

    do
    {
        cout << "\n========== Address Book ==========\n";

        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            viewContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            updateContact();
            break;

        case 5:
            deleteContact();
            break;

        case 6:
            cout << "\nGood Bye.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}