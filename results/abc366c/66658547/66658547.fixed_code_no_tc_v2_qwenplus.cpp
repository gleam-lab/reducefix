#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> count;
    int q;
    cin >> q;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                count.erase(x);
            }
        } 
        else if (type == 3) {
            cout << count.size() << '\n';
        }
    }
    
    return 0;
}