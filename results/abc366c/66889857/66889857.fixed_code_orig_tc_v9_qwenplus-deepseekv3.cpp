#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    unordered_map<int, int> count;
    set<int> present;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                present.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                present.erase(x);
            }
        } else if (type == 3) {
            cout << present.size() << endl;
        }
    }
    return 0;
}