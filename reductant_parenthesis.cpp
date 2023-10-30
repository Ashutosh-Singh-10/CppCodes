#include <bits/stdc++.h>
using namespace std;
void print_ch(stack<char> st)
{
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}
bool reductant_paranthesis(string st, int n)
{
    int i = 0;
    stack<char> ch;
    while (i < n)
    {
        print_ch(ch);
        if (st[i] == '}')
        {
            if (ch.top() == '{')
            {
                
                return false;
            }

            while (1)
            {

                if (ch.empty())
                {
                    cout << "here";
                    return false;
                }

                else if (ch.top() == '{')
                {
                    ch.pop();
                    break;
                }
                ch.pop();
            }
        }
        else if (st[i] == '*' || st[i] == '+' || st[i] == '/' || st[i] == '-' || st[i] == '{')
        {
            ch.push(st[i]);
        }

        i++;
    }
    return true;
}

int main()
{
    string st = "{{5*4/5}}";
    bool ans = reductant_paranthesis(st, 9);
    cout << ans;
    return 0;
}