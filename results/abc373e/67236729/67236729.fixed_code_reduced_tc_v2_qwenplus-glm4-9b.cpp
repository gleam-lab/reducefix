#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    vector<long long> a(n);

    // Input
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort candidates by votes
    sort(a.begin(), a.end(), greater<long long>());

    // Calculate votes needed for each candidate
    vector<long long> votes_needed(n, -1);
    long long votes_needed_top = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            if (votes_needed[a[i]] == -1) { // Calculate only once
                long long votes_to_win = a[i] + (n - m);
                if (votes_to_win > k - m) {
                    votes_needed[a[i]] = -1;
                } else {
                    votes_needed[a[i]] = votes_to_win - a[i];
                }
            }
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << (votes_needed[a[i]] == -1 ? -1 : votes_needed[a[i]]) << ' ';
    }
    cout << endl;

    return 0;
}