#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    vector<ll> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        candidates[i] = {A[i], i};
    }

    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    // Compute prefix sums
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + candidates[i].votes;

    K -= prefix[N]; // Remaining unassigned votes

    vector<ll> result(N, -1);

    // For each candidate, binary search on minimal additional votes needed
    for (int i = 0; i < N; ++i) {
        int pos = i;
        ll low = 0, high = K;
        bool possible = false;

        auto get_min_votes = [&](ll x) {
            ll my_total = candidates[pos].votes + x;
            int left = pos;
            int right = N - 1;
            int count = 0;

            // Use binary search to find how many others have strictly more votes than me
            while (left <= right) {
                int mid = (left + right) / 2;
                if (candidates[mid].votes > my_total)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            int first_worse = left;
            count = N - first_worse;

            if (count < M) return false; // Not enough people below me

            // Now, try to force at least M people to be *strictly* less than or equal to me
            // This means at most M-1 people can have more than me

            // Greedily give extra votes to the top ones above me so they do not beat me
            // Find how many of them can be made <= me with given x
            ll needed = 0;
            for (int j = first_worse - 1; j >= 0 && count < M; --j) {
                if (candidates[j].votes > my_total) {
                    needed += (candidates[j].votes - my_total + 1);
                    count++;
                }
            }

            return needed <= K - x;
        };

        // Binary search over additional votes
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (get_min_votes(mid)) {
                result[candidates[pos].index] = mid;
                high = mid - 1;
                possible = true;
            } else {
                low = mid + 1;
            }
        }

        if (!possible) result[candidates[pos].index] = -1;
    }

    // Output results in original order
    for (int i = 0; i < N; ++i)
        cout << result[i] << " ";
    cout << "\n";

    return 0;
}