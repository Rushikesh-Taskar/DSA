// for linear probing
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    cout << "enter size of hash table " << endl;
    cin >> m;

    vector<int> v(m);

    //initializing element with -1 for further use 

    for(int i=0;i<m;i++)
    {
        v[i] = -1;
    }

    cout << "how many element you want to store" << endl;
    int n;
    cin >> n;
    if(n>m)
    {
        cout<<"total number to be inserted is greater than size it may cause \n";
        cout<<"overriding of element or may stop the program"<<endl;
    }
    cout << "enter element" << endl;

    int prob =0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int index = x % m; // hash function

        if (v[index] <0)
        {   
            v[index] = x;

            prob++;
        }

        else
        {
            index = (index + 1) % m; // circular increment

            prob++;  // current position 

            while (v[index] >0)  // check till we get empty space
            {
                index = (index + 1) % m;
                prob++;  // compaired position  

            }
            // if we get empty space then store no 
            v[index] = x;
            prob++;   // inserted position 
        }
    }
     cout<<"linear probing element \n"<<endl;

    for(int i=0;i<m;i++)
    {    
        if(v[i]<0)
        {
            cout<<i<<endl;
        }
        else
         cout<<i<<" -->"<<v[i]<<endl;
    }

    cout<<"total probes = "<<prob<<endl;
}


// for quadratic probing 

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m;
    cout << "enter size of hash table " << endl;
    cin >> m;

    vector<int> v(m);

    //initializing element with -1 for further use 

    for(int i=0;i<m;i++)
    {
        v[i] = -1;
    }

    cout << "how many element you want to store" << endl;
    int n;
    cin >> n;
    if(n>m)
    {
        cout<<"total number to be inserted is greater than size it may cause \n";
        cout<<"overriding of element or may stop the program"<<endl;
    }
    cout << "enter element" << endl;

    int prob =0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int index = x % m; // hash function

        if (v[index] <0)
        {   
            v[index] = x;

            prob++;
        }

        else
        {   
            int q =1;
            int index2; // for store index 
            index2 = (index + q*q) % m; // circular increment

            prob++;  // current position 

            while (v[index2] >0)  // check till we get empty space
            {   
                q++;
                index2 = (index + q*q) % m;
                prob++;  // compaired position  

            }
            // if we get empty space then store no 
            v[index2] = x;
            prob++;   // inserted position 
        }
    }
     cout<<"linear probing element \n"<<endl;

    for(int i=0;i<m;i++)
    {    
        if(v[i]<0)
        {
            cout<<i<<endl;
        }
        else
         cout<<i<<" -->"<<v[i]<<endl;
    }

    cout<<"total probes = "<<prob<<endl;
}*/