#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    unordered_map<int, int> freq;
    int distinct_count = 0;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
                distinct_count++;
            freq[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                distinct_count--;
        }
        else if (type == 3)
        {
            cout << distinct_count << '\n';
        }
    }

    return 0;
}