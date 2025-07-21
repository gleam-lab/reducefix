#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if(type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << '\n';
        }
    }
    return 0;
}