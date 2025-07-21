#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the candidates array in ascending order
    sort(a.begin(), a.end());

    // Process each candidate
    for (int i = 0; i < n; ++i) {
        // Calculate the remaining votes
        long long remaining_votes = k - accumulate(a.begin(), a.begin() + i, 0LL);
        // Calculate the votes needed to win
        long long votes_needed = remaining_votes - (n - i - 1) - a[i];
        // Check if they can win
        if (votes_needed >= m) {
            cout << votes_needed << ' ';
        } else {
            cout << -1 << ' ';
        }
    }

    return 0;
}