#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sorted_A[i] = A[i];
    }
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        int rank = lower_bound(sorted_A.begin(), sorted_A.end(), current) - sorted_A.begin();
        int higher = N - rank;
        if (higher < M) {
            ans[i] = 0;
            continue;
        }
        
        ll low = 0, high = K;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int new_rank = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();
            int new_higher = N - new_rank;
            
            if (new_higher < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best != -1 && best <= K) {
            ans[i] = best;
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    return 0;
}