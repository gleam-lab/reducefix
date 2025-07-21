#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll Q;
    cin >> Q;

    set<ll> s;
    while (Q--) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll tp;
            cin >> tp;
            s.insert(tp);
        } else if (a == 2) {
            ll tp;
            cin >> tp;
            s.erase(tp);
        } else {
            cout << s.size() << "\n";
        }
    }

    return 0;
}