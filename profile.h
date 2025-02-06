#include <utility>

//
// Created by kss42 on 10/1/2021.
//

#ifndef HW3_PROFILE_H
#define HW3_PROFILE_H

using namespace std;

class profile
{

public:

    profile()
    {
        userNInput = " ";
        userStatus = " ";
    }

    string getUserName()
    {
        return userNInput;
    }

    void setUserName(string user)
    {
        userNInput = std::move(user);
    }

    string getUserStatus()
    {
        return userStatus;
    }

    void setStatus(string status)
    {
        userStatus = std::move(status);
    }

    vector<string> friendList;

    ////////////////////////////////////////////////////////////////////
    //
    // Function: adds friend
    // Input:
    // following - string - name of user to follow
    //
    ////////////////////////////////////////////////////////////////////
    void addFriend(const string& following)
    {
        friendList.push_back(following);
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function: prints page
    //
    ////////////////////////////////////////////////////////////////////
    void printPage()
    {

        cout << userNInput << endl;
        cout << userStatus << endl;

        for(const auto & i : friendList)
        {
            cout << i << endl;
        }

    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function: deletes friend
    // Input:
    // follower- string - name of user to unfriend
    //
    ////////////////////////////////////////////////////////////////////
    void deleteFriend (const string& follower)
    {

        int i = 0;
        while (follower != friendList[i])
        {
            i++;
        }

        friendList[i] = " ";

    }

private:

    string userNInput;
    string userStatus = "Idle";


};

#endif //HW3_PROFILE_H