#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        vector<ll> distances;
        int left = pos - 1;
        int right = pos;
        while ((left >= 0 || right < N) && distances.size() < k) {
            if (left >= 0 && right < N) {
                if (abs(A[left] - b) <= abs(A[right] - b)) {
                    distances.push_back(abs(A[left] - b));
                    left--;
                } else {
                    distances.push_back(abs(A[right] - b));
                    right++;
                }
            } else if (left >= 0) {
                distances.push_back(abs(A[left] - b));
                left--;
            } else {
                distances.push_back(abs(A[right] - b));
                right++;
            }
        }
        nth_element(distances.begin(), distances.begin() + (k - 1), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}