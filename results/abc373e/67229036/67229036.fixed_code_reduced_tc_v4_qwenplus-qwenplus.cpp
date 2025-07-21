#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N];
int sorted_votes[N];
int prefix_sum[N];

// Function to compute the minimum additional votes needed for candidate with current votes 'x'
int compute_min_votes(int x, int total_remaining) {
    // Binary search on the number of additional votes needed
    int left = 0, right = total_remaining + 1;
    int answer = -1;

    while (left < right) {
        int mid = (left + right) / 2;

        // We need to assume best case scenario for i-th candidate: gets 'mid' extra votes
        // Now check if this guarantees victory regardless of how remaining votes are distributed

        // We will try to maximize the number of candidates that can have more votes than i
        // We take top n-1 candidates (excluding i), add their values and see if we can make at least m candidates > i
        // If not, then i is elected

        // We simulate inserting (a_i + mid) into the array and then removing it,
        // to get the list of other candidates' votes

        // To do this efficiently:
        // Create an array of all votes except a[i], then add a[i] + mid, sort it again? Not efficient

        // Better approach:
        // Assume we're checking for candidate i with value (x + mid)
        // We want to ensure that no more than m-1 candidates can have strictly greater votes
        // So we select up to (m) candidates with highest current votes and try to boost them to beat i

        // Let's find how many candidates can potentially have more votes than i after adding X votes to i
        // At most m-1 candidates can be above i for i to win

        // We use the global sorted list of votes

        // Try to give as many votes as possible to the top (m) candidates (excluding i) to beat i

        // We need to calculate in the worst-case distribution of remaining votes
        // Give as much as possible to top m candidates other than i to try to prevent i from winning

        // Total votes left after giving X to i: rem = K - X

        // We try to distribute these votes among other candidates to make as many as possible have > (a[i]+X)

        // The idea is:
        // Take all votes except i, add X to i's vote
        // Sort all votes
        // Find the (n - m)-th largest vote. If i's vote is <= this value, then at least m candidates can have >= this value
        // So we need i's vote to be > that value

        // Efficient method:
        // Use binary search on the k-th smallest vote

        // We want to know whether i-th candidate can be among top m candidates after getting X votes

        // Simulate:
        // After giving X votes to i, its new vote count is curr = a[i] + X
        // We want at most (m-1) candidates who can have > curr votes
        // So we need curr > b[n-m+1] (in the sorted list of all votes after adding X to i)

        // But since we don't want to sort every time, we simulate by assuming worst case:
        // pick the top (n-m) candidates other than i, and try to raise them as high as possible

        // Let's proceed with this strategy:

        int required = 0;
        int rem = total_remaining - mid;

        if (rem < 0) {
            // Not enough votes to assign X to i
            required = -1;
        } else {
            // Create a copy of the votes and update i-th candidate
            // We use a binary search approach to determine how many candidates can beat i

            // We want to ensure that i beats at least (n - m + 1) candidates

            // Find the threshold index
            int* pos = upper_bound(sorted_votes + 1, sorted_votes + n, x + mid);
            int idx = n - (pos - sorted_votes) + 1;

            if (idx <= m) {
                // i is guaranteed to be in top m
                required = 0;
            } else {
                // Need to increase i's votes to beat at least (idx - m) candidates
                // This part needs correction...

                // We need to find how many votes are needed to beat the (n - m + 1)-th candidate

                int target_pos = n - m + 1;
                int target_vote = sorted_votes[n - target_pos + 1];

                if (x + mid > target_vote) {
                    required = 0;
                } else {
                    required = target_vote - x + 1;
                    if (required > total_remaining || required < 0) {
                        required = -1;
                    }
                }
            }
        }

        if (required == -1 || required > total_remaining) {
            // Not possible with this X
            return false;
        }

        return true;
    }

    return answer;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Compute sum of current votes
    int sum_a = 0;
    for (int i = 1; i <= n; ++i) {
        sum_a += a[i];
    }

    int remaining = k - sum_a;

    // Prepare sorted list of current votes
    int b[N];
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);

    // Compute prefix sums
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    // For each candidate, perform binary search
    for (int i = 1; i <= n; ++i) {
        int left = 0;
        int right = remaining + 1;
        int result = -1;

        while (left < right) {
            int mid = (left + right) / 2;
            int curr = a[i] + mid;

            // Count how many candidates can have more than curr votes
            // Use binary search on b array

            int* ptr = upper_bound(b + 1, b + n + 1, curr);
            int cnt = n - (ptr - b) + 1;

            if (cnt < m) {
                // i-th candidate is in top m
                result = mid;
                right = mid;
            } else {
                // Too many candidates may beat i
                // Need to give more votes to i
                left = mid + 1;
            }
        }

        if (result <= remaining) {
            cout << result << " ";
        } else {
            cout << "-1 ";
        }
    }

    cout << "\n";
    return 0;
}