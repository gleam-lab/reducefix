#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> elements;
    map<int, int> counts;
    
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int t; cin >> t;
            elements.insert(t);
            counts[t]++;
        } else if (x == 2) {
            int t; cin >> t;
            elements.erase(t);
            counts[t]--;
            if (counts[t] == 0) {
                counts.erase(t);
            }
        } else if (x == 3) {
            cout << elements.size() << '\n';
        }
    }
    
    return 0;
}