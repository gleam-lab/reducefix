#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the array of votes in descending order
    sort(a.rbegin(), a.rend());

    vector<long long> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        long long required_votes = 0;
        
        // Calculate the maximum number of votes that can be distributed among other candidates
        for(int j = 0; j < min(m, i); ++j) {
            required_votes += a[j] - a[i];
        }
        
        // Check if the current candidate can win even if other candidates get all their remaining votes
        if(required_votes <= k) {
            ans[i] = 0;
        } else {
            // Calculate the minimum additional votes needed
            long long remaining_votes = required_votes - k;
            ans[i] = remaining_votes + 1;
        }
    }

    // Print the results
    for(long long x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}