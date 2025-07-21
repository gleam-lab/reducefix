#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> s;

    while (n--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            s.insert(x);
        } else if (type == 2) {
            s.erase(s.find(x));
        } else if (type == 3) {
            cout << s.size() << '\n';
        }
    }

    return 0;
}