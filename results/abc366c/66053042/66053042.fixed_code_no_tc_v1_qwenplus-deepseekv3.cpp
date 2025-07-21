#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int distinct_count = 0;
    
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
            if (m[x] == 0)
            {
                distinct_count++;
            }
            m[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0)
            {
                distinct_count--;
            }
        }
        else if (type == 3)
        {
            cout << distinct_count << endl;
        }
    }
    return 0;
}