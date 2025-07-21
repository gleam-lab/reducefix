#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 1; i < n; ++i) cin >> vb[i];
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) / 2;
        vector<bool> used(n, false);
        bool possible = true;
        for(int i = 0; i < n; ++i) {
            int j = upper_bound(vb.begin(), vb.end(), mid - va[i]) - vb.begin();
            if(j >= n || used[j]) {
                possible = false;
                break;
            }
            used[j] = true;
        }
        if(possible) r = mid;
        else l = mid + 1;
    }
    
    if(r == 1e9) cout << -1 << '\n';
    else cout << r << '\n';
    return 0;
}