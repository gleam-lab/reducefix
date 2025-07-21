#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    for (ll i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = rem;
        ll res = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a_i + mid;
            
            ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a) - sorted_A.begin();
            ll cnt = N - pos; // number of candidates with votes > new_a
            
            if (cnt < M) {
                // Need to ensure that no more than M-1 candidates have > new_a votes after redistribution
                // The worst case is when other candidates get as many votes as possible to surpass new_a
                ll needed = 0;
                ll left = max(0LL, N - (M - 1));
                needed = new_a * left - (prefix[left] - prefix[0]);
                
                if (needed <= rem - mid) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        
        cout << res << " \n"[i == N - 1];
    }
    
    return 0;
}