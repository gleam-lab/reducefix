#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    unordered_set<int> s;
    int q; cin >> q;
    
    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int t; cin >> t;
            s.insert(t);
        } else if(x == 2) {
            int t; cin >> t;
            s.erase(s.find(t));
        } else if(x == 3) {
            cout << s.size() << '\n';
        }
    }

    return 0;
}