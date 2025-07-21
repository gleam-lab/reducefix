#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    
    // Sort candidates by their current votes in descending order
    sort(A.begin(), A.end(), [](const Candidate& x, const Candidate& y) {
        return x.a > y.a;
    });
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].a;
    }
    
    ll remaining_votes = K - prefix[N];
    vector<ll> res(N, -1);
    
    for (int i = 0; i < N; ++i) {
        // Check if the candidate is already in top M
        if (i < M) {
            // The candidate might already be safe
            if (i == M - 1) {
                // The M-th candidate is safe if they have enough votes
                res[A[i].idx] = 0;
            } else if (A[i].a > A[M].a) {
                // The candidate is already in top M
                res[A[i].idx] = 0;
            } else {
                // Need to calculate required votes
                ll low = 0, high = remaining_votes;
                ll ans = -1;
                while (low <= high) {
                    ll mid = (low + high) / 2;
                    ll new_votes = A[i].a + mid;
                    
                    // Find how many candidates have votes > new_votes
                    int cnt = upper_bound(A.begin(), A.end(), new_votes, 
                        [](ll val, const Candidate& c) {
                            return val < c.a;
                        }) - A.begin();
                    
                    if (cnt < M) {
                        ans = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                res[A[i].idx] = ans;
            }
        } else {
            // Candidate is not in top M, need to surpass at least M-th candidate
            ll target = A[M - 1].a;
            ll required = target - A[i].a + 1;
            if (required <= 0) {
                res[A[i].idx] = 0;
            } else if (required <= remaining_votes) {
                res[A[i].idx] = required;
            } else {
                res[A[i].idx] = -1;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    
    return 0;
}