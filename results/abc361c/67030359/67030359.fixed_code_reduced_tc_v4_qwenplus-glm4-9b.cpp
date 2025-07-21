#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Pair each element with its next element, and calculate the difference
    vector<pair<int, int>> differences;
    for (int i = 0; i < N - 1; ++i) {
        differences.emplace_back(abs(A[i] - A[i + 1]), i);
    }

    // Sort the differences by the absolute difference in descending order
    sort(all(differences), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });

    // Remove the largest K differences
    for (int i = 0; i < K; ++i) {
        if (differences[i].second < N - 1) {
            A[differences[i].second + 1] = A[differences[i].second];
        }
        if (differences[i].second > 0) {
            A[differences[i].second] = A[differences[i].second - 1];
        }
    }

    // Remove the last element if we removed K elements in the last pair
    if (K >= (N - 1)) {
        A.pop_back();
    }

    // Output the minimum and maximum of the modified sequence A
    cout << *max_element(all(A)) - *min_element(all(A)) << '\n';
    return 0;
}