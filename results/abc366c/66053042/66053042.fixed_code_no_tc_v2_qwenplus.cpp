#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
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
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                m.erase(x);
            }
        }
        else if (type == 3)
        {
            cout << m.size() << endl;
        }
    }
}