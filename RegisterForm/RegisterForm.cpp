#include <iostream>
#include <fstream>

using namespace std;
bool flag = false;      //flag for password
bool tempflag = false;  //flag for username

void login() { //login function
    ifstream fin("db.txt");
    string strfile;
    string username, password;
    char file[50];
    if (!fin.is_open()){ // if file is not open
        cout << "File not find!\n";
    }
    else
    {
        cout << "\nInput you username: \n";
        cin >> username;
        cout << "\nInput you password: \n";
        cin >> password;
        cout << "\n";
        while (true)
        {
            fin.getline(file, 50);
            strfile = string(file);
            if (strfile[0] != '-') { //end list of users
                break;
            }
            else if (strfile.substr(2, username.length()) == username) { //check username
                tempflag = true;
                if (strfile.substr(username.length() + 3, password.length()) == password) { //check password
                    system("cls");
                    cout << "Enter the system\n";
                    flag = true;
                }
                else {
                    system("cls");
                    cout << "Error! Password is not correct \n";
                }
            }
        }
        if (flag == false && tempflag == false) {// no user in list
            system("cls");
            cout << "Error! Unknown user \n";
        }
        

        
    }
}

void registration() { // register function
    ofstream fout("db.txt", ios_base::app);
    ifstream fin("db.txt");
    string strfile;
    char file[50];
    fin.getline(file, 50);
    strfile = string(file);
    string username, password;
    cout << "\nInput you user name: \n";
    cin >> username;
    cout << "\nInput you password \n";
    cin >> password;
    if (strfile.substr(2, username.length()) == username) {//user already exists
        system("cls");
        cout << "This user already exists";
        registration();
    }
    else {// add user in list
        system("cls");
        cout << "\nRegister complited\n";
        fout << "- " << username << " " << password << "\n";
    }
    fout.close();
}

int main()
{
    setlocale(0, "");
    int choise;
    while (1) {
        cout << "-------------------------------------\n"
                "| 1. LogIn                          |\n"
                "| 2. Register                       |\n"   // choise form
                "| 3. Exit                           |\n"
                "-------------------------------------\n";

        cin >> choise;
        switch (choise)
        {
        case 1: login(); break;
        case 2: registration(); break;
        case 3: return 0; break;
        default:cout << "Unknown command \n"; system("PAUSE"); system("cls"); break;
        }
    }
    return 0;
}
