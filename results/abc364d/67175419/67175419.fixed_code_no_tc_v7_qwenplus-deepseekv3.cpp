#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    while (Q--) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = 0;
        auto it = lower_bound(A.begin(), A.end(), b);
        if (it != A.begin()) {
            left = distance(A.begin(), it) - 1;
        } else {
            left = -1;
        }
        right = distance(A.begin(), it);
        vector<int> distances;
        while (distances.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                int dist_left = abs(A[left] - b);
                int dist_right = abs(A[right] - b);
                if (dist_left <= dist_right) {
                    distances.push_back(dist_left);
                    --left;
                } else {
                    distances.push_back(dist_right);
                    ++right;
                }
            } else if (left >= 0) {
                distances.push_back(abs(A[left] - b));
                --left;
            } else {
                distances.push_back(abs(A[right] - b));
                ++right;
            }
        }
        cout << distances[k - 1] << '\n';
    }
    return 0;
}