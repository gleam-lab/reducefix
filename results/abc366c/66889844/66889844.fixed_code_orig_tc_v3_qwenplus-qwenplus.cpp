#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    map<int, int> freq;
    set<int> unique;
    
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                unique.insert(x);
            }
            freq[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                unique.erase(x);
            }
        } else if (type == 3) {
            cout << unique.size() << '\n';
        }
    }
    
    return 0;
}