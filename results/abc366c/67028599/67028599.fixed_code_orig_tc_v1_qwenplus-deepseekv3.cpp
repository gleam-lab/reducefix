#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    unordered_map<int, int> freq;
    unordered_set<int> distinct;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
            if (freq[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << '\n';
        }
    }
    
    return 0;
}