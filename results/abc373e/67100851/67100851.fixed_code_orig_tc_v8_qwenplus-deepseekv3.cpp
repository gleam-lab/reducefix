#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // We need to find the M-th largest element in the array
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    ll threshold = (M == N) ? 0 : sorted_A[M];  // M-th largest value (0-indexed if M == N)
    
    ll total_votes = 0;
    for (ll a : A) {
        total_votes += a;
    }
    ll remaining_votes = K - total_votes;
    
    for (int i = 0; i < N; i++) {
        // Current candidate's votes
        ll current = A[i];
        
        // To guarantee election, we need to ensure that at most M-1 candidates
        // have strictly more votes than this candidate after distribution
        
        // Case 1: Already has enough votes (no need to add any)
        if (current > threshold) {
            cout << 0 << " ";
            continue;
        }
        // Case 2: Can't be elected even with all remaining votes
        if (current + remaining_votes <= threshold && M != N) {
            cout << -1 << " ";
            continue;
        }
        // Case 3: Need to add some votes
        // We need to make sure that at most M-1 candidates have > current+X votes
        // The key is to find X such that current+X > threshold (if M != N)
        if (M == N) {
            // All candidates are elected, no need to add any votes
            cout << 0 << " ";
        } else {
            ll needed = max(0LL, threshold - current + 1);
            if (needed <= remaining_votes) {
                cout << needed << " ";
            } else {
                cout << -1 << " ";
            }
        }
    }
    cout << endl;
    
    return 0;
}