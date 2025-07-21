#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Calculate votes needed for the last candidate to have at least one vote more than the second last in the sorted order
    ll max_votes_needed = a[n-1] - a[n-2] + 1;
    // If there's only one candidate, they are guaranteed to win with any number of additional votes
    if (n == 1) {
        cout << 0 << " ";
        return 0;
    }

    // Prepare sorted and reverse-sorted vectors for binary search
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> reverse_sorted_a(a);
    reverse(reverse_sorted_a.begin(), reverse_sorted_a.end());

    // Binary search to find the minimum number of votes needed for candidates from n-m+1 to n
    for (int i = n - m; i < n; ++i) {
        ll needed_votes = sorted_a[i] - max_votes_needed;
        if (needed_votes <= 0) {
            cout << 0 << " ";
        } else {
            // Check if it's possible to win with the calculated votes
            ll remaining_votes = k - (n * max_votes_needed);
            if (remaining_votes < needed_votes) {
                cout << -1 << " ";
            } else {
                cout << needed_votes << " ";
            }
        }
    }

    // Binary search to find the minimum number of votes needed for candidates from 0 to n-m
    for (int i = 0; i < n - m; ++i) {
        ll votes_needed = reverse_sorted_a[i] - max_votes_needed;
        if (votes_needed <= 0) {
            cout << 0 << " ";
        } else {
            // Check if it's possible to win with the calculated votes
            ll remaining_votes = k - (n * max_votes_needed);
            if (remaining_votes < votes_needed) {
                cout << -1 << " ";
            } else {
                cout << needed_votes << " ";
            }
        }
    }

    // Handle candidates from n-m to 0
    if (m > 1) {
        // Total votes needed for n-m+1th candidate to win
        ll total_votes_needed = reverse_sorted_a[n - m] - max_votes_needed + (m - 1) * max_votes_needed;
        // Check if it's possible to win with the calculated votes
        ll remaining_votes = k - (n * max_votes_needed);
        if (remaining_votes < total_votes_needed) {
            cout << -1 << " ";
        } else {
            for (int i = n - m; i >= 0; --i) {
                cout << total_votes_needed << " ";
            }
        }
    }

    return 0;
}