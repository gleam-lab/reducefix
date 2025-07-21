#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    set<int> allElements; // To store all elements
    unordered_set<int> uniqueElements; // To store unique elements
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            if (uniqueElements.find(x) == uniqueElements.end()) {
                uniqueElements.insert(x);
            }
            allElements.insert(x);
        } else if (a == 2) {
            int y;
            cin >> y;
            if (uniqueElements.find(y) != uniqueElements.end()) {
                uniqueElements.erase(uniqueElements.find(y));
            }
            allElements.erase(allElements.find(y));
        } else if (a == 3) {
            cout << uniqueElements.size() << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}