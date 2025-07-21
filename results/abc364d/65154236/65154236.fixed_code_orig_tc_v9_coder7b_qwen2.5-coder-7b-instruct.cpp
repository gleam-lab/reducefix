#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector<int> A, B;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    A.resize(N + 1);
    B.resize(Q + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= Q; ++i) {
        cin >> B[i] >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 1; i <= Q; ++i) {
        int k = A[i];
        auto it = lower_bound(A.begin() + 1, A.end(), B[i]);
        int idx = it - A.begin();

        if (idx == 1) {
            ans.push_back(abs(B[i] - A[1]));
        } else if (idx == N + 1) {
            ans.push_back(abs(B[i] - A[N]));
        } else {
            int leftDist = abs(B[i] - A[idx - 1]);
            int rightDist = abs(B[i] - A[idx]);

            if (leftDist <= rightDist) {
                ans.push_back(leftDist);
            } else {
                ans.push_back(rightDist);
            }
        }
    }

    for (int i = 1; i <= Q; ++i) {
        cout << ans[i - 1] << '\n';
    }

    return 0;
}