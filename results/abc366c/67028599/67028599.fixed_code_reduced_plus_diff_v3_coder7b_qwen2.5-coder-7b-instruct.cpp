#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    set<int> s;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if(t == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << "\n";
        }
    }

    return 0;
}