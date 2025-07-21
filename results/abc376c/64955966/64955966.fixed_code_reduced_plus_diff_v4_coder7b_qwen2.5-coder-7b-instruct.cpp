#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

bool canStore(ll mid, vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    int m = b.size();
    sort(b.begin(), b.end());
    multiset<ll> s(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(a[i]);
        if (it == s.end()) {
            return false;
        } else {
            s.erase(it);
        }
    }
    return true;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }
    
    ll low = *max_element(a.begin(), a.end()), high = accumulate(a.begin(), a.end(), 0LL);
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canStore(mid, a, b)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (low > accumulate(a.begin(), a.end(), 0LL)) {
        cout << -1 << endl;
    } else {
        cout << low << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}