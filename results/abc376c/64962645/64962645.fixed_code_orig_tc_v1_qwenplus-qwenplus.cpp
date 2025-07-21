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

    multiset<long long> boxSizes;
    int j = 0;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N && A[j] <= B[i]) {
            boxSizes.insert(A[j]);
            ++j;
        }
        if (!boxSizes.empty()) {
            boxSizes.erase(boxSizes.begin()); // assign smallest available toy to this box
        } else {
            // No toy can fit in this box
            cout << -1 << endl;
            return 0;
        }
    }

    // One toy will remain for the new box
    if (j < N) {
        cout << A[j] << endl;
    } else {
        // All toys were used, but one must be left for the new box
        cout << A[N - 1] << endl;
    }

    return 0;
}