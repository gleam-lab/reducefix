#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> count;
    set<int> distinct;
    int type, x;
    
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            count[x]++;
            distinct.insert(x);
        } else if (type == 2) {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << endl;
        }
    }

    return 0;
}