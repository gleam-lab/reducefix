#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attacks(ll h) {
    ll full_cycles = h / 5;
    ll remaining = h % 5;
    ll additional = 0;
    if (remaining > 0) {
        if (remaining <= 3) {
            additional = remaining == 3 ? 1 : remaining;
        } else {
            additional = 2; // remaining is 4, which requires 2 attacks (1 + 3)
        }
    }
    return full_cycles * 3 + additional;
}

ll calculate_total_time(const vector<ll>& H) {
    ll total_T = 0;
    ll max_T = 0;
    for (ll h : H) {
        ll attacks = num_attacks(h);
        max_T = max(max_T, total_T + attacks);
        total_T += attacks;
    }
    return max_T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    cout << calculate_total_time(H) << endl;
    
    return 0;
}