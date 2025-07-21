#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++)
        cin >> va[i];
    for (int i = 0; i < n - 1; i++)
        cin >> vb[i];
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    int minBoxSize = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (vb[i] >= va[n - 1])
            minBoxSize = vb[i];
    }
    if (minBoxSize == -1)
        cout << -1 << endl;
    else
        cout << minBoxSize << endl;
}