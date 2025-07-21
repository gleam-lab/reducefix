#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    unordered_map<int, int> freq;
    int distinct = 0;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                distinct++;
            }
            freq[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                distinct--;
            }
        } else if (type == 3) {
            cout << distinct << "\n";
        }
    }
    
    return 0;
}