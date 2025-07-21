#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = left;
        int low = pos - 1, high = pos;
        vector<ll> distances;
        while (distances.size() < k && (low >= 0 || high < N)) {
            if (low >= 0 && high < N) {
                if (abs(A[low] - b) <= abs(A[high] - b)) {
                    distances.push_back(abs(A[low] - b));
                    low--;
                } else {
                    distances.push_back(abs(A[high] - b));
                    high++;
                }
            } else if (low >= 0) {
                distances.push_back(abs(A[low] - b));
                low--;
            } else {
                distances.push_back(abs(A[high] - b));
                high++;
            }
        }
        cout << distances[k - 1] << '\n';
    }
    return 0;
}