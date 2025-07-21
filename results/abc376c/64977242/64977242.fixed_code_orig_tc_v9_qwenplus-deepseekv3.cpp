#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> unmatched;
    int i = 0, j = 0;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            unmatched.push_back(A[i]);
            ++i;
        }
    }
    while (i < N) {
        unmatched.push_back(A[i]);
        ++i;
    }

    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else {
        if (unmatched.empty()) {
            // All toys fit in the existing boxes, but need to place one in the new box.
            // The new box can be as small as 1, but need to ensure it's at least the smallest toy not placed.
            // In this case, all toys are placed in existing boxes, so the new box can be any size >= the largest toy (but this scenario shouldn't happen as N boxes are needed for N toys)
            cout << 1 << endl; // though logically, this case shouldn't exist as per problem statement
        } else {
            cout << unmatched[0] << endl;
        }
    }

    return 0;
}