#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int pos = left;
        vector<long long> distances;
        int i = pos, j = pos - 1;
        while (distances.size() < N) {
            if (i < N && (j < 0 || abs(A[i] - b) < abs(A[j] - b))) {
                distances.push_back(abs(A[i] - b));
                i++;
            } else if (j >= 0) {
                distances.push_back(abs(A[j] - b));
                j--;
            } else {
                distances.push_back(abs(A[i] - b));
                i++;
            }
        }
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}