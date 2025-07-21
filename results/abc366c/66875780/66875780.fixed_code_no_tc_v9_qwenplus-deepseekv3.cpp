#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

typedef long long ll;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve() {
    ll Q;
    cin >> Q;
    unordered_map<ll, ll> count;
    set<ll> distinct;
    
    while (Q--) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (a == 2) {
            ll x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << "\n";
        }
    }
}

int main() {
    fastIO();
    
    int t = 1;
    while (t--) {
        Solve();
    }
    
    return 0;
}