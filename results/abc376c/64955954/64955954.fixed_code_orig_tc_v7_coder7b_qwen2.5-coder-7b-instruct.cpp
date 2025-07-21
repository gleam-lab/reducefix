#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n - 1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long ans = -1;
    for(int i = n - 1; i >= 0; --i) {
        if(vb[i] >= va[i]) {
            ans = va[i];
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}