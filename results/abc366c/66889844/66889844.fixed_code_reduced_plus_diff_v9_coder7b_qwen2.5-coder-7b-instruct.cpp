#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<int> a;

    while (n--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            a.insert(x);
        } else if (type == 2) {
            cin >> x;
            a.erase(a.find(x));
        } else if (type == 3) {
            cout << a.size() << '\n';
        }
    }

    return 0;
}