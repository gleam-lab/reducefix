#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll sum_A = accumulate(all(A), 0LL);
    K -= sum_A;
    
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll current_A = sorted_A[idx];
        ll low = 0, high = K;
        ll best_X = K + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_A = current_A + mid;
            ll total = 0;
            
            // Find the number of candidates with A_i > new_A
            auto it = upper_bound(all(sorted_A), new_A);
            int cnt_higher = sorted_A.end() - it;
            
            // If cnt_higher is less than M, no problem
            if (cnt_higher < M) {
                best_X = mid;
                high = mid - 1;
                continue;
            }
            
            // Otherwise, need to ensure that at least M candidates are <= new_A
            // So, ensure that (N - cnt_higher) >= M
            // But here, we need to make sure that after adding mid votes, the candidate is in top M candidates
            // So, the number of candidates with A_i + potential votes > new_A should be < M
            // But we don't know how other candidates will receive votes, so we have to assume worst-case scenario:
            // Other candidates will get as many votes as possible to surpass new_A
            // So, the worst case is that M-1 candidates get enough votes to surpass new_A
            // So, we need to make sure that even if M-1 candidates get as many votes as possible, the candidate is still in the top M
            
            // To find the minimal X, we need to ensure that after adding X votes, the candidate is in the top M
            // So, the worst case is that the M-1 candidates with the highest current votes get enough votes to surpass new_A
            // So, we find the M-th largest vote count (from the bottom) and ensure that new_A is >= that
            
            // Another approach is to find the M-th largest vote count after adding X to current_A
            // But since we are trying to minimize X, we need to check if the candidate can be in the top M with X votes
            
            // The steps are:
            // 1. Consider the current votes plus X for the candidate
            // 2. The remaining K - X votes can be distributed to other candidates to try to surpass new_A
            // 3. The worst case is the M-1 candidates with highest votes + (K - X) votes surpass new_A
            // 4. So, we need to ensure that after adding X votes to current_A, the candidate is still in the top M
            
            // The number of candidates that can surpass new_A is at most M-1
            // So, new_A must be >= the (N - M + 1)-th largest vote count possible
            // But the (N - M + 1)-th largest vote count is the (M-1)-th smallest vote count
            // So, new_A must be >= (M-1)-th smallest vote count after distribution
            
            // So, the remaining K - X votes can be distributed to any candidates to try to make M-1 candidates surpass new_A
            // The minimal X is where even if K - X votes are used to make M-1 candidates surpass new_A, the candidate is still in top M
            
            // We need to find the minimal X such that:
            // The number of candidates with A_i + (K - X) > new_A is <= M - 1
            // But since K - X is the total remaining votes, and they can be distributed among any candidates, we need to consider the worst case
            
            // The worst case is when the M-1 candidates with the highest potential votes (A_i + some votes) surpass new_A
            // So, we need to ensure that even if the M-1 highest candidates get all remaining votes, new_A is still >= the (N - M + 1)-th highest vote count
            
            // So, the minimal X is such that:
            // new_A + (number of candidates that need to be surpassed) >= the (N - M + 1)-th highest vote count
            
            // This is getting complex. Maybe it's better to compute the minimal X by considering that after adding X votes to current_A, the candidate is in the top M candidates, even if the remaining K - X votes are distributed to the other candidates in the worst way possible.
            
            // So, the minimal X is the smallest X such that:
            // current_A + X >= the (N - M)-th largest A_i after adding some votes
            
            // To find this, we can consider that the worst case is when the M-1 candidates with the highest current A_i get all the remaining K - X votes
            
            // So, the (N - M + 1)-th largest A_i would be the M-th largest after distribution
            // So, new_A >= this value
            
            // So, let's compute the minimal X such that new_A >= the M-th largest possible vote count after adding K - X votes to the M-1 highest current votes
            
            // So, the M-th largest would be the (N - M)-th smallest vote count (since sorted ascendingly)
            // So, new_A >= sorted_A[N - M] (assuming no votes are added to others)
            // But if votes are added, the M-th largest could be higher
            
            // So, the worst case is when the M-1 largest current votes get all K - X votes, making the M-th largest vote count as sorted_A[N - M] + (K - X) / (M) (distributed to M candidates)
            // Wait, no. The worst case is when the M-1 largest current votes get all K - X votes distributed to them, so the M-th largest vote count remains at sorted_A[N - M]
            
            // So, new_A >= sorted_A[N - M]
            
            // So, X >= sorted_A[N - M] - current_A
            
            // But we also have to ensure that X is non-negative and <= K
            
            // So, the minimal X is max(0, sorted_A[N - M] - current_A)
            // But we need to check if this X is such that the total votes used is <= K
            
            // Additionally, if the candidate is among the top M candidates already (i.e., sorted_A[N - M] <= current_A), then X is 0
            
            // So, for each candidate, the minimal X is:
            // X = max(0, sorted_A[N - M] - current_A)
            // But we need to ensure that X <= K
            
            // But this might not be sufficient, because if the remaining K - X votes are distributed to other candidates, they might surpass new_A
            
            // This suggests that the initial approach is flawed, and we need a better way
            
            // Alternative idea: After adding X votes to current_A, the candidate's new vote count is current_A + X
            // The remaining K - X votes can be distributed to other candidates to try to have as many as possible surpass current_A + X
            // The worst case is when these votes are distributed to the M-1 candidates with the highest current votes, so they surpass current_A + X
            // So, the total votes needed for these M-1 candidates is sum_{i=N-M+1}^{N-1} max(0, current_A + X + 1 - sorted_A[i])
            // But since we only have K - X votes remaining, we need to ensure that this sum <= K - X
            
            // So, the condition is:
            // sum_{i=N-M+1}^{N} max(0, current_A + X + 1 - sorted_A[i]) <= K - X
            // (Note: sum taken over the M highest candidates, excluding the current candidate if applicable)
            
            // So, for the current candidate (idx), we need to find the minimal X such that this condition holds
            
            // So, we can binary search X from 0 to K, and for each mid, compute the sum and check the condition
            // If the condition is satisfied, we try a smaller X; otherwise, we try a larger X
            
            // This seems promising. Let's implement this.
            
            ll sum_needed = 0;
            int start = N - M;
            if (start < 0) start = 0;
            for (int i = start; i < N; ++i) {
                if (i == idx) continue;
                if (sorted_A[i] > new_A) continue;
                sum_needed += new_A + 1 - sorted_A[i];
            }
            if (sum_needed <= K - mid) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X <= K) {
            ans[ord[idx]] = best_X;
        } else {
            ans[ord[idx]] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}