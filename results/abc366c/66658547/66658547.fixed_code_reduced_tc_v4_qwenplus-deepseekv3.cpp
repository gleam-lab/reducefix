#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> count;
    int distinct = 0;
    int Q;
    cin >> Q;
    
    while (Q--) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (query_type == 2) {
            int x;
            cin >> x;
            if (count[x] == 1) {
                distinct--;
            }
            count[x]--;
        } else {
            cout << distinct << '\n';
        }
    }
    
    return 0;
}