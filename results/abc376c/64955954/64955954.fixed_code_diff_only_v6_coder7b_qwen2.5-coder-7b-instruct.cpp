#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; i++) cin >> va[i];
    for(int i = 0; i < n-1; i++) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(vb[i] < va[i]) {
            ans = max(ans, (long long)va[i]);
        } else {
            ans = max(ans, (long long)vb[i+1]);
        }
    }

    if(ans == 0 && vb[n-2] >= va[n-1]) ans = va[n-1];
    if(ans == 0) ans = -1;

    cout << ans << '\n';

    return 0;
}