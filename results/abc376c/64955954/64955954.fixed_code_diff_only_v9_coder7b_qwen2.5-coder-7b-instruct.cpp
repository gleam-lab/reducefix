#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    
    for(int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.rbegin(), va.rend()); // Sort in descending order
    sort(vb.begin(), vb.end());

    long long maxBoxSize = 0;
    for(int i = 0; i < n - 1; ++i) {
        if(vb[i] >= va[i]) {
            maxBoxSize = max(maxBoxSize, vb[i]);
        } else {
            break;
        }
    }

    if(maxBoxSize >= va[n - 1])
        cout << maxBoxSize << '\n';
    else
        cout << -1 << '\n';

    return 0;
}