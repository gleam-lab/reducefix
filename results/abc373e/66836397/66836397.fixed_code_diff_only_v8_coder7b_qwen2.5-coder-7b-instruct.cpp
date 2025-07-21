#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> ac(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ac[i + 1] = ac[i] + a[i];
    }
    
    sort(rbegin(ac), rend(ac)); // Sort in descending order
    
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ll total_votes_needed = 0;
        for (int j = 0; j < m; j++) {
            if (j != i) {
                total_votes_needed += max(0LL, ac[j + 1] - a[i]);
            }
        }
        if (total_votes_needed > K - ac[0]) {
            ans[i] = -1;
        } else {
            ans[i] = K - ac[0] - total_votes_needed;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}