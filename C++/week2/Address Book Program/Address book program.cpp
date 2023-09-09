#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include<iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;
///////////////////
void addContact();
void viewContact();
void searchContact();

void deleteContact();

int main()
{
    f:
    system("cls");
    bool run=true;

    do{
        int Option;
        cout<<"---------------------AddressBook-------------------"<<endl;
        cout<<"n";
        cout<<"What would you like to do? "<<endl;
        cout << "1.) Add Contact" << endl;
        cout << "2.) Delete Contact" << endl;
        cout << "3.) View All Contacts" << endl;
        cout << "4.) Search Address Book" << endl;
        cout << "5.) Exit" << endl << endl;
        cout << "Choose an option: ";

        cin >> Option;
        cin.ignore();
        switch (Option)
        {
            case 1:
            addContact();break;
            case 2:
            deleteContact();break;
            case 3:
            viewContact();break;
            case 4:
            searchContact();break;
            case 5:
            run =false;break;
            default:
            cout << "Please choose 1 to 6" << endl;
            goto f;
        }

    } while (run);

    cout<<"Program Terminated";
    
    
}   
void addContact()//function to add contact 
{
    system("cls");//to clear screen
    string fname,lname,address,contact, list, name, Fname2, Lname2, Address2, Contact2;
    double counter=0, number=0;
    cout<<"---------------addressBook---------"<<endl;
    cout<<"dont use space if entry has 2 or more word"<<endl;
    cout<<"use 'quit' to quit"<<endl;
    if( fname == "quit" ) { main () ; }
    cout<<"enter the fitst name: ";
    getline(cin,fname);
    cout<<"enter the last name: ";
    getline(cin,lname);
    cout<<"enter address: ";
    getline(cin,address);
    cout<<"enter your number: ";
    getline(cin,contact);

    ifstream file("adressesbook.txt");//create file .txt
    while(file>>counter>>Fname2>>Lname2>>Address2>>Contact2){
        if(counter==100)
        {
            cout<<"invalid ,max is 100 contact";
            main();
        }
        else
        {
            number=counter;
        }
    }
    ofstream file2 ("adressesbook.txt",ios::app);//to access the file.txt i creat
    number=number+1;
    file2 << number<<" "<<fname<<" "<<lname<<" "<<address<<" "<<contact<<" "<<endl;
    system("pause");
    system("cls");
    
}

void  viewContact()
{
    system("cls");
    double counter;
    string fname, lname,address,contact;

    ifstream addressbook("adressesbook.txt");
    cout<<"entry #"<<setw(17)<< "First Name" << setw(23)<< "Last Name" << setw(23) <<"Address"<< setw(29) <<"Contact"<< endl;
    while (addressbook>>counter>>fname>>lname>>address>>contact) {
    
    cout << setw(3)<< counter << setw(19)<< fname << setw(23) << lname << setw(25) << address << setw(30) << contact << endl;

    }
    
    cout<<endl;
    system("pause");
   

}   
void searchContact()
{
    system("cls");
    int choice;
    double counter,number=0;
    string fname, lname, address, contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
    ifstream edit("adressesbook.txt");///read
    ofstream temp("temp.txt",ios::app);
    cout<<"please type the enter number that you want edit";
    cin>>choice;
    cout<<endl;
    if(choice==0||choice>100)
    {
        cout<<"----wrong----"<<endl;
        system("pause>0");
      
    }
    while(edit>>counter>>Fname2>>Lname2>>Address2>>Contact2)
    {
        if(counter==choice)
        {
            cout<<counter<<" "<<Fname2<<" "<<Lname2<<" "<<Address2<<" "<<Contact2<<endl;
            cout<<"is this the contact you want (y or n)"<<endl;
            cin>>choice3;
            cout<<endl;
        }
        if(choice3=="n")
        {main();}
        if(choice3=="y")
        {
            if(counter<choice)
            {
                temp<<counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;

            }
            if(counter==choice)
            {
                cout << "Enter New First name: ";
                cin >> fname;
                cout << "Enter New Last name: ";
                cin >> lname;
                cout << "Enter New Address: ";
                cin >> address;
                cout << "Enter New Contact: ";
                cin >> contact;

                temp << choice << " " << fname << " "<< lname << " " << address << " " << contact << endl;

            }
            if(counter>choice)
            {
                temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;

            }
        
        }
    
    }
    edit.close();
    temp.close();
    if (remove("adressesbook.txt")==0){
    cout << "Succesful Removing File" << endl;
    }else{
    cout << "Error removing"<< endl;
    }
    if(rename("Temp.txt", "adressesbook.txt")==0){
    cout << "Succesful Renaming file"<< endl;
    }else{
    cout << "Error renaming"<<endl;
    }
    system("pause");
    system("cls");

}

void deleteContact()
{
    system("cls");
    int choice;
    double counter=0,number=0;
    string fname, lname, address, contact, Fname2, Lname2, Address2, Contact2, choice2,choice3;
    ifstream edit("adressesbook.txt");
    ofstream temp("temp.txt",ios::app);
    cout<<"enter your numper you want delete: ";
    cin>>choice;
    cout<<endl;
    while (edit>>counter>>Fname2>>Lname2>>Address2>>Contact2)
    {
        if(counter==choice){
        cout<<counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 <<endl;
    
        cout<<"is this contact you want to delete? (y or n): ";
        cin>>choice3;
        cout<<endl;
        }
        if(choice3=="n")
        {
            main();
        }
        if(counter<choice)
        {
            temp << counter << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        if(counter>choice)
        {
            temp << counter - 1 << " " << Fname2 << " "<< Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        
    }
    edit.close();
    temp.close();
    if(remove("adressesbook.txt")==0)
    {
         cout << "Succesful Removing File" << endl;
    }
    else
    {
        cout << "Error removing"<< endl;
    }
    if(rename("temp.txt", "adressesbook.txt")==0)
    {
        cout << "Succesful Renaming file"<< endl;
    }
    else
    {
        cout << "Error renaming"<<endl;
    }
    system("pause");
    system("cls");
}
