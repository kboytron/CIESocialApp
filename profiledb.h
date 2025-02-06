//
// Created by kss42 on 10/2/2021.
//

#ifndef HW3_PROFILEDB_H
#define HW3_PROFILEDB_H

using namespace std;

class profileDatabase
{
public:

    profileDatabase() = default;

    ////////////////////////////////////////////////////////////////////
    //
    // Function: adds user to database
    // Input:
    // userName - string - name of user to add
    //
    ////////////////////////////////////////////////////////////////////
    void addUser(const string& userName)
    {
        totalUsers.push_back(userName);
    }

    void getProfile ( const string& name) const
    {
        int i = 0;

        while (name != totalUsers[i])
        {
            i++;
        }
        cout << "user " << totalUsers[i] << " already exists" << endl;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function: Delete profile
    // Input:
    // target - string - targeted user to delete
    //
    ////////////////////////////////////////////////////////////////////
    void deleteProfile (const string& target)
    {
        int i = 0;

        while (target != totalUsers[i])
        {
            i++;
        }

        cout << totalUsers[i] << "'s account has been deleted." << endl;

        totalUsers[i] = " ";

    }

    void getProfIndex (const string& rank) const
    {
        int i = 0;
        while(rank != totalUsers[i])
        {
            i++;

        }

        cout << "client rank = " << i+1 << endl;
    }

    static void adminFollow (const string& target1, const string& target2)
    {
        cout << target1 << " and " << target2 << " are now friends " << endl;
    }
    ////////////////////////////////////////////////////////////////////
    //
    // Function: force removes friends
    // Input:
    // target1 - string - first person in friendship
    // target2 - string - second person in friendship
    //
    ////////////////////////////////////////////////////////////////////

    static void adminRemove (const string& target1, const string& target2)
    {
        cout << target1 << " and " << target2 << " are now not friends " << endl;
    }
    ////////////////////////////////////////////////////////////////////
    //
    // Function: update status of user
    // Input:
    // target - string - user to change status
    // newStat - string - new status
    //
    //
    ////////////////////////////////////////////////////////////////////

    static void updateStat (const string& target, const string& newStat)
    {
        cout << "the status of " << target << " has now been updated to " << newStat << endl;

    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function: Print users in database
    // Input:
    // totalUsers (array)
    // Output:
    // total users in database
    //
    ////////////////////////////////////////////////////////////////////
    void printDb()
    {
        for(const auto & totalUser : totalUsers)
        {
            cout << totalUser << endl;

        }

    }

private:

    vector<string> totalUsers;


};

#endif //HW3_PROFILEDB_H
