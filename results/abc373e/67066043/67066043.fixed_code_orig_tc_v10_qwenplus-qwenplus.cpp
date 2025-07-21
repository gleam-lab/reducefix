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

    // Total votes already distributed
    ll total_used = accumulate(all(A), 0LL);
    ll remaining = K - total_used;

    vector<ll> result(N);

    // We need to process each candidate and determine how many additional votes they need
    for (int i = 0; i < N; ++i) {
        ll my_votes = A[i];

        // Create a copy of A to manipulate
        vector<ll> temp = A;
        temp[i] = my_votes + remaining;

        // Sort in descending order to find top M candidates
        sort(temp.rbegin(), temp.rend());

        // Count how many have strictly more than current candidate's max possible
        int count_more = 0;
        for (int j = 0; j < N; ++j) {
            if (temp[j] > my_votes) {
                count_more++;
            }
        }

        // If less than M candidates have more votes, then we're safe with 0 extra
        if (count_more < M) {
            result[i] = 0;
            continue;
        }

        // Binary search on the minimum X
        ll low = 0, high = remaining;
        ll answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_my_votes = A[i] + mid;

            // Now simulate giving other candidates as much as possible without exceeding new_my_votes
            ll needed = mid;
            ll available = remaining - mid;

            vector<ll> others;
            for (int j = 0; j < N; ++j) {
                if (j != i) {
                    others.push_back(A[j]);
                }
            }

            sort(others.rbegin(), others.rend());

            // Try to cap the top (M-1) candidates at min(A[j], new_my_votes)
            bool valid = true;
            int count_better = 0;
            for (int j = 0; j < N && available >= 0; ++j) {
                if (j == i) continue;
                if (others[j] > new_my_votes) {
                    count_better++;
                    ll diff = others[j] - new_my_votes;
                    if (diff > available) {
                        valid = false;
                        break;
                    }
                    available -= diff;
                    others[j] = new_my_votes;
                }
            }

            // After ensuring no one among top M can be capped without exceeding available
            if (valid && count_better < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer == -1) {
            result[i] = -1;
        } else {
            result[i] = answer;
        }
    }

    for (auto val : result) {
        cout << val << " ";
    }
}