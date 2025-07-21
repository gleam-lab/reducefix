#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m, k;
    vector<ll> votes;
    cin >> n >> m >> k;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        votes.push_back(a);
        sum += a;
    }

    vector<ll> required_votes(n, 0);

    // Sort the votes for binary search
    sort(votes.begin(), votes.end());

    for (int i = 0; i < n; i++) {
        // Binary search for the minimum additional votes needed
        ll low = 0, high = k - sum;
        bool found = false;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll count = 0;
            ll current_sum = votes[i] + mid;

            // Count how many candidates can have more votes than this
            for (int j = 0; j < n; j++) {
                if (votes[j] + mid > current_sum) {
                    count++;
                }
            }

            if (count >= m) {
                found = true;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (found) {
            required_votes[i] = low;
        } else {
            required_votes[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << required_votes[i] << " ";
    }
    cout << endl;

    return 0;
}