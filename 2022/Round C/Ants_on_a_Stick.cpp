#include <bits/stdc++.h>
using namespace std;

// not correct solution
int main()
{
    int tc;
    cin >> tc;
    for (int tr = 1; tr <= tc; tr++)
    {
        cout << "Case #" << tr << ": ";
        int n, l;
        cin >> n >> l;
        vector<vector<int>> ar(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i][0] >> ar[i][1];
            // ar[i][0] *= 2;
            ar[i][2] = i;
        }
        sort(ar.begin(), ar.end());
        vector<pair<int, int>> time;
        vector<int> next(n, n);
        int lk = n;
        for (int i = n - 1; i >= 0; i--)
        {
            next[i] = lk;
            if (ar[i][1] == 1)
            {
                lk = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ar[i][1] == 0)
            {
                time.push_back({ar[i][0], ar[i][2]});
            }
            else
            {
                int nxt = next[i];
                if (nxt == n)
                {
                    time.push_back({l - ar[i][0], ar[i][2]});
                    continue;
                }
                time.push_back({ar[nxt][0], ar[i][2]});

                for (int k = i + 1; k <= nxt; k++)
                {
                    next[k] = next[nxt];
                    ar[k][0] = ar[k - 1][0];
                }
                ar[nxt][1] = 0;
            }
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < time.size(); i++)
        {
            cout << time[i].second + 1 << " ";
        }
        cout << endl;
    }
}