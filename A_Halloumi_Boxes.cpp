#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        bool flag = true;
        if (k == 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] > v[i + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
 }
}
}