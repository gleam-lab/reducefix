#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We try to match the smallest toys with the smallest boxes.
    // If any toy is larger than its corresponding box, we'll need a new box.

    long long required_size = -1;

    // Use a multiset to manage available boxes efficiently
    multiset<long long> boxes;
    for (long long b : B) boxes.insert(b);

    // Sort toys in ascending order
    sort(A.begin(), A.end());

    // Try to assign toys greedily
    for (long long toy : A) {
        auto it = boxes.lower_bound(toy);
        if (it != boxes.end()) {
            // Found a suitable box
            boxes.erase(it);
        } else {
            // No suitable box found, so this toy must go into the new box
            required_size = toy;
            break;
        }
    }

    cout << required_size << endl;

    return 0;
}