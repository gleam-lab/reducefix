#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> count;
    set<int> distinct;
    
    int q;
    cin >> q;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else if (type == 3) {
            cout << distinct.size() << "\n";
        }
    }
    
    return 0;
}