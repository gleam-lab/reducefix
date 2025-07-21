#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the total votes needed to surpass the current leader
    ll max_votes_needed = 0;
    for(int i = 0; i < n; ++i) {
        max_votes_needed = max(max_votes_needed, a[i]);
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i] >= max_votes_needed + m) {
            continue; // Already secured
        }

        // Calculate the worst-case scenario for other candidates
        ll remaining_k = k;
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                remaining_k -= max(0LL, a[j] - a[i]);
            }
        }

        if(remaining_k < 0) {
            ans[i] = -1; // Cannot secure victory
        } else {
            ans[i] = max(0LL, max_votes_needed + m - a[i]);
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}