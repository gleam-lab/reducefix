#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, K;
    cin >> n >> m >> K;
    vector<long long> a(n);
    for (long long &v : a) cin >> v;

    // Sort the candidates by votes in descending order
    sort(a.begin(), a.end(), greater<long long>());

    vector<long long> ac(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        long long votes_needed = 0;
        // Find the Mth largest candidate's votes
        int j = n - m;
        if (j >= 0) {
            votes_needed = a[j] - a[i];
        } else {
            // If the Mth largest candidate is not present, the smallest candidate wins
            votes_needed = 0;
        }

        // Check if the votes needed can be provided from the remaining votes
        if (votes_needed <= K) {
            cout << votes_needed << " ";
        } else {
            cout << "-1 ";
        }
        K -= votes_needed;
    }
    cout << endl;

    return 0;
}