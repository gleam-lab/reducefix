#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int index = it - a.begin();
        
        if(index == n) {
            cout << abs(b - a.back()) << '\n';
        } else if(index == 0) {
            cout << abs(b - a.front()) << '\n';
        } else {
            int dist1 = abs(b - a[index]);
            int dist2 = abs(b - a[index - 1]);
            
            if(k == 1) {
                cout << min(dist1, dist2) << '\n';
            } else {
                cout << dist1 << '\n';
            }
        }
    }

    return 0;
}