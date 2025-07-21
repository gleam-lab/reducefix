#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll T = 0, attacks = 0;
    for (ll i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        ll temp = (h + 2) / 3; // This is equivalent to ceil(h / 1)
        ll sets_of_3 = temp / 3;
        ll remaining_hits = temp % 3;
        if (remaining_hits != 0) {
            T += (remaining_hits + sets_of_3);
            attacks += (remaining_hits + sets_of_3) * 3;
        } else {
            T += sets_of_3 * 3;
            attacks += sets_of_3 * 3;
        }
    }
    cout << T << endl;
}