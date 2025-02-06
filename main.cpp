#include <iostream>
#include <string>
#include <vector>
#include "profile.h"
#include "profiledb.h"

/////////////////////////////////////////////////////////////
//
// Programmer: Karan Singh
// Date: 10/8/21
// Name: hw3
// Description: A Social Media program
//
/////////////////////////////////////////////////////////////

using namespace std;

int main()
{
    //Part 1 testing
    profile U1;
    U1.setUserName("jeff");
    U1.setStatus("working");
    U1.addFriend("amy");
    U1.addFriend("emily");
    U1.deleteFriend("emily");
    U1.printPage();

    //part 2 testing
    profileDatabase client1;
    client1.addUser("jeff");
    client1.addUser("amy");
    client1.getProfile("jeff");
    client1.deleteProfile("jeff");
    client1.getProfIndex("amy");
    client1.adminFollow("jeff", "amy");
    client1.adminRemove("amy", "jeff");
    client1.updateStat("amy", "sleeping");
    client1.printDb();

    profile MainUser; //class for using app menus
    profileDatabase MainDb;

    string username = " "; //string for passing username input to class functions

    int mMenu = 0; // for navigating menu loop


    while ( mMenu != 5) // first menu
    {
        cout << "<================================>" << endl;
        cout << "      CIE Social Media App        " << endl;
        cout << "<================================>" << endl;
        cout << "1. Existing Users" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Manage Account " << endl;
        cout << " Select Option 1,2,3,4 or 5 to quit" << endl;
        cout << "<================================>" << endl;

        cin >> mMenu;

        if (mMenu == 1) // print all users
        {
            MainDb.printDb();
        }
        else if (mMenu == 2) // create user
        {
            cout << "Type in your username ( no spaces allowed ): " << endl;
            cin >> username;

            MainUser.setUserName(username);
            MainDb.addUser(username);
        }
        else if (mMenu == 3) // delete user
        {
            string target = " ";
            cout << "Type in the username of the account you want to delete" << endl;
            cin >> target;
            MainDb.deleteProfile(target);
        }
        else if (mMenu == 4) // account menu
        {
            int userInput = 0;

            while (userInput != 4) {
                cout << "<================================>" << endl;
                cout << "      CIE Social Media App        " << endl;
                cout << "<================================>" << endl;
                cout << "1. Set Status" << endl;
                cout << "2. Add Friend" << endl;
                cout << "3. Show Friends" << endl;
                cout << " Select Option 1,2,3 or 4 to quit" << endl;
                cout << "<================================>" << endl;

                cin >> userInput;

                if (userInput == 1) // change status
                {

                    cout << " type in your new status: " << endl;
                    string status;
                    cin >> status;

                    MainUser.setStatus(status);
                    MainDb.updateStat(username, status);
                    MainUser.printPage();
                }
                if (userInput == 2) //add friend
                {
                    string newFriend;
                    cout << " type in your friend's name: " << endl;
                    cin >> newFriend;

                    MainUser.addFriend(newFriend);
                    MainDb.adminFollow(username, newFriend);
                }
                if (userInput == 3) // list friends
                {
                    cout << "Your Friends are: " << endl;

                    for (const auto & i : MainUser.friendList) {
                        cout << i << endl;
                    }

                }
            }
        }
    }

    cout << "goodbye" << endl; // end of program

    return 0;
}