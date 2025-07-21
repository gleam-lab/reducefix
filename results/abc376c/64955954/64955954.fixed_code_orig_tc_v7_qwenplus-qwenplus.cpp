#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> box_sizes;
    int j = 0;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N && A[j] <= B[i]) {
            box_sizes.insert(A[j]);
            j++;
        }
        if (!box_sizes.empty()) {
            box_sizes.erase(box_sizes.begin()); // Assign smallest available toy to this box
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    // One toy remains, find the minimal x that can accommodate it
    if (j < N) {
        cout << A[j] << endl;
    } else {
        // All toys were matched to boxes, no toy is left -> purchase any size >= last toy
        cout << A.back() << endl;
    }

    return 0;
}