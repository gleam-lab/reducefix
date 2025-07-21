#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    unordered_set<int> seen;
    set<int> unique_elements;
    
    while (q--) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            if (!seen.count(x)) {
                unique_elements.insert(x);
                seen.insert(x);
            }
        } else if (a == 2) {
            int x;
            cin >> x;
            if (seen.count(x)) {
                unique_elements.erase(unique_elements.find(x));
                seen.erase(x);
            }
        } else if (a == 3) {
            cout << unique_elements.size() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}