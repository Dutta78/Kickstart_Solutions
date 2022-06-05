#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for (int tr = 1; tr <= tc; tr++)
    {

        cout << "Case #" << tr << ": ";
        string s;
        int n;
        cin >> n >> s;
        int no = 0;
        int cap = 0;
        int low = 0;
        int sp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
                no++;
            if (s[i] <= 'Z' && s[i] >= 'A')
                cap++;
            if (s[i] <= 'z' && s[i] >= 'a')
                low++;
            char d = s[i];
            if (d == '#' || d == '@' || d == '*' || d == '&')
                sp++;
        }
        if (low == 0)
        {
            s += 'a';
            n++;
        }
        if (cap == 0)
        {
            s += 'A';
            n++;
        }
        if (sp == 0)
        {
            s += '#';
            n++;
        }
        while (n < 7 || no == 0)
        {
            s += '1';
            no++;
            n++;
        }
        cout << s;
        cout << "\n";
    }
    return 0;
}