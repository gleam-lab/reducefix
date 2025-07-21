#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    map<int, int> counts;
    int distinct = 0;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (counts[x] == 0) {
                ++distinct;
            }
            ++counts[x];
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            --counts[x];
            if (counts[x] == 0) {
                --distinct;
            }
        } 
        else if (type == 3) {
            cout << distinct << "\n";
        }
    }
    
    return 0;
}