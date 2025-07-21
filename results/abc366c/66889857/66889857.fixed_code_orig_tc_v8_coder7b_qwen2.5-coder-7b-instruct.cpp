#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> s;

    while(n--) {
        int type; cin >> type;
        if(type == 1) {
            int x; cin >> x;
            s.insert(x);
        } else if(type == 2) {
            int x; cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}