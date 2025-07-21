#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<pair<ll, ll>> A(N);
        vector<ll> B(N);
        
        for (ll i = 0; i < N; ++i) {
            cin >> A[i].fi >> B[i];
            A[i].se = B[i];
        }
        
        sort(A.begin(), A.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.fi < b.fi;
        });
        
        multiset<ll> sb(B.begin(), B.end());
        ll min_value = numeric_limits<ll>::max();
        
        for (ll i = 0; i <= N - K; ++i) {
            ll max_A = A[i].fi;
            ll sum_B = 0;
            ll start = i;
            ll end = i + K - 1;
            
            while (end >= 0) {
                sum_B += A[end].se;
                if (end >= i) {
                    --end;
                } else {
                    break;
                }
            }
            
            if (end < 0) {
                sum_B += *sb.begin();
                sb.erase(sb.begin());
            }
            
            min_value = min(min_value, max_A * sum_B);
        }
        
        cout << min_value << endl;
    }
    
    return 0;
}