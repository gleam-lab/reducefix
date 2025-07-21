#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the votes to use binary search
    vector<ll> sorted_votes(a.begin(), a.end());
    sort(sorted_votes.begin(), sorted_votes.end());

    vector<ll> additional_votes_needed(n, -1);
    for (int i = 0; i < n; i++) {
        ll current_votes = a[i];
        ll votes_needed = -1;

        // Binary search to find the minimum votes that guarantees victory
        int left = 0, right = k - current_votes;
        while (left <= right) {
            int mid = (left + right) / 2;
            ll simulated_votes = current_votes + mid;

            // Check if this candidate can secure victory with simulated_votes
            int count_leaders = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] + (k - (current_votes + mid)) > simulated_votes) {
                    count_leaders++;
                }
            }

            if (count_leaders < m) {
                votes_needed = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (votes_needed == -1) {
            additional_votes_needed[i] = -1;
        } else {
            additional_votes_needed[i] = votes_needed;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << additional_votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}