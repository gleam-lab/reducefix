#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> uset;
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int t; cin >> t;
            uset.insert(t);
        } else if(x == 2) {
            int t; cin >> t;
            uset.erase(t);
        } else if(x == 3) {
            cout << uset.size() << "\n";
        }
    }
    return 0;
}