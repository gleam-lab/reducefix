#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define int long long

signed main() {
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
        int left = 0, right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        vector<int> distances;
        int i = pos - 1, j = pos;
        while ((i >= 0 || j < N) && distances.size() < k) {
            if (i >= 0 && j < N) {
                if (abs(A[i] - b) <= abs(A[j] - b)) {
                    distances.push_back(abs(A[i] - b));
                    --i;
                } else {
                    distances.push_back(abs(A[j] - b));
                    ++j;
                }
            } else if (i >= 0) {
                distances.push_back(abs(A[i] - b));
                --i;
            } else {
                distances.push_back(abs(A[j] - b));
                ++j;
            }
        }
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}