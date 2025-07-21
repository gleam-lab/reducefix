#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int distinct = 0;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            m[x]++;
            if (m[x] == 1) {
                distinct++;
            }
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                distinct--;
            }
        }
        else if (type == 3)
        {
            cout << distinct << endl;
        }
    }
}