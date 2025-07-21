#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    set<int> st;
    map<int, int> countMap;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            
            // Add element to the set
            st.insert(x);
            // Update the count map
            countMap[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            
            // Remove element from the set
            st.erase(st.find(y));
            // Decrement the count in the map
            countMap[y]--;
            
            // If the count becomes zero, remove the entry from the map
            if (countMap[y] == 0) {
                countMap.erase(y);
            }
        } else if (a == 3) {
            // Output the number of unique elements
            cout << st.size() << endl;
        }
    }
}

int main() {
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