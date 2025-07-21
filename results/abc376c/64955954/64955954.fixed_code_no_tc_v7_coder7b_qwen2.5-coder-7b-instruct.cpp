#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int ans = -1;
    for(int i = 0; i < n - 1; ++i) {
        if(va[i] <= vb[i]) continue;
        if(ans == -1 || ans < va[i])
            ans = va[i];
    }

    if(ans == -1 && va[n - 1] > vb[n - 2])
        ans = va[n - 1];

    cout << ans << endl;
    return 0;
}