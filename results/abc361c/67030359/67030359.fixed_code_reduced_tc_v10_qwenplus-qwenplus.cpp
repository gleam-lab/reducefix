#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define mp make_pair
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N); // value, index

    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // Sort by value
    sort(all(A));

    int min_diff = numeric_limits<int>::max();

    // We need to choose a window of size (N - K) in the sorted array such that
    // the elements in this window correspond to at most K removals in the original array.
    // That means the indices of the selected elements must appear in order in the original array.

    // So we try all windows of size (N - K) in the sorted list,
    // and for each window, check if the corresponding indices are in increasing order (can be kept without violating the order).

    for (int i = 0; i + (N - K) <= N; ++i) {
        vector<int> indices;
        for (int j = i; j < i + (N - K); ++j) {
            indices.push_back(A[j].second);
        }
        sort(all(indices)); // Check if these indices can remain without violating order
        bool valid = true;
        for (int j = 1; j < (int)indices.size(); ++j) {
            if (indices[j] < indices[j - 1]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            min_diff = min(min_diff, A[i + (N - K) - 1].first - A[i].first);
        }
    }

    cout << min_diff << endl;
}