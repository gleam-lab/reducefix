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

    // Check if it's possible to assign toys to boxes without the extra box
    // We do this by trying to fit smallest toy into smallest box, and so on
    // If any toy doesn't fit in its corresponding box, we will need to use the extra box

    int a_ptr = 0, b_ptr = 0;
    vector<long long> leftover_toys;

    while (a_ptr < N && b_ptr < N - 1) {
        if (A[a_ptr] <= B[b_ptr]) {
            a_ptr++;
        } else {
            leftover_toys.push_back(A[a_ptr]);
        }
        b_ptr++;
    }

    // If there are still toys left after processing all boxes, they would need to go into the new box
    while (a_ptr < N) {
        leftover_toys.push_back(A[a_ptr]);
        a_ptr++;
    }

    if (leftover_toys.size() > 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << leftover_toys[0] << endl;
    return 0;
}