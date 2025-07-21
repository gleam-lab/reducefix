#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    set<int> a;

    while(n--) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            a.insert(x);
        } else if(t == 2) {
            int x; cin >> x;
            a.erase(a.find(x));
        } else {
            cout << a.size() << '\n';
        }
    }

    return 0;
}