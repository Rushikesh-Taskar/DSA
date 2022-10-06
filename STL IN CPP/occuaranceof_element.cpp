#include <bits/stdc++.h>
using namespace std;
int maxvalue(map<int, int> &mp)
{
    int max_no = 0;
    pair<int, int> p(0, 0);
    for (auto i : mp)
    {
        if (i.second > p.second)
        {
            p.first = i.first;
            p.second = i.second;
        }
    }
    cout << "maximum element occurance is : ";
    cout << p.first << " and occure in " << p.second << " time" << endl;
}
int main()
{
    map<int, int> mp;
    cout << "enter size " << endl;
    int n;
    cin >> n;
    cout << "enter element " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    maxvalue(mp);
}