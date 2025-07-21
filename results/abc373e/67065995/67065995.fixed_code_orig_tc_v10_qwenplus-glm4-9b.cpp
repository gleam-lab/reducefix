#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i]; // Subtract the votes already counted from k
    }

    // Create a vector of pairs and sort it by votes
    vector<pair<long long, int>> votes(a.begin(), a.end());
    sort(votes.begin(), votes.end());

    vector<long long> ans(n, 0);
    // Calculate the votes needed for each candidate to secure their victory
    for (int i = 0; i < n; ++i) {
        // Minimum votes needed is the difference between the Mth most voted and current votes
        ans[i] = votes[m-1].first - votes[i].first;
        // If the Mth most voted candidate has the same votes as the current candidate
        if (votes[m-1].first == votes[i].first) {
            // Calculate if the current candidate can secure victory by just adding remaining votes
            if (i < m - 1) {
                ans[i] += votes[m-1].first - votes[i+1].first;
            } else if (i > m - 1) {
                ans[i] += votes[m-1].first - votes[i-1].first;
            }
        }
        // Ensure the answer does not exceed the available votes
        ans[i] = min(ans[i], k);
    }

    // Output the minimum votes needed for each candidate
    for (int i = 0; i < n; ++i) {
        if (ans[i] < 0) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

    return 0;
}