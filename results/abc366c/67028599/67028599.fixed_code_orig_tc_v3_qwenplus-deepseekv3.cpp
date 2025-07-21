#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, int> count;
    set<int> unique;
    
    while(q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                unique.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                unique.erase(x);
            }
        } else {
            cout << unique.size() << endl;
        }
    }

    return 0;
}