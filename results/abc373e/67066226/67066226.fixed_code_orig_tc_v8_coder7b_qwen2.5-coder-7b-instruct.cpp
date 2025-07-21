#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<long long> minVotesToWin(int n, int m, long long k, vector<long long>& a) {
    // Sort the vote counts in descending order
    sort(a.rbegin(), a.rend());
    
    // Calculate the prefix sums of sorted vote counts
    vector<long long> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Initialize the result vector with -1
    vector<long long> res(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; ++i) {
        long long needed = 0;

        // Calculate the minimum votes required to win
        for(int j = 0; j < m; ++j) {
            if(j < n - 1) {
                needed += a[j] + 1;
            } else {
                needed += a[j];
            }
        }

        // Check if we can afford the needed votes from the remaining ballots
        if(k - pref[n] + pref[i + 1] >= needed) {
            res[i] = 0;
        } else {
            // Binary search to find the exact number of votes needed
            int left = 0, right = k - pref[n] + pref[i + 1];
            while(left < right) {
                int mid = (left + right) / 2;
                long long total = pref[i + 1] + mid + (m - i - 1) * (a[i] + 1);
                if(total <= k) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = left;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<long long> res = minVotesToWin(n, m, k, a);

    for(long long x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}