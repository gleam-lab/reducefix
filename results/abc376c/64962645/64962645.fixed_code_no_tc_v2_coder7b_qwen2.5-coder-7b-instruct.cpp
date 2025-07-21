#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& va, vector<int>& vb, int mid)
{
    for (int i = 0; i < va.size(); i++) {
        if (va[i] > mid) return false;
    }

    for (int i = 1; i < vb.size(); i++) {
        if (vb[i] > mid) return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);

    for (int i = 0; i < n; i++)
        cin >> va[i];

    for (int i = 0; i < n - 1; i++)
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int low = 0, high = max(*max_element(va.begin(), va.end()), *max_element(vb.begin(), vb.end()));
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(va, vb, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}