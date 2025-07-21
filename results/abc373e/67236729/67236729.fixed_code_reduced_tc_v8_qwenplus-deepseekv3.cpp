#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    i64 K;
    cin >> N >> M >> K;
    
    vector<i64> A(N);
    for (i64 &a : A) {
        cin >> a;
    }
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    for (i64 a : A) {
        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (sorted_A[mid] <= a) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pos = left - 1;
        
        int need = max(0, M - (N - pos - 1));
        if (need <= 0) {
            cout << "0 ";
            continue;
        }
        
        i64 low = 0, high = K, answer = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            int left2 = 0, right2 = N;
            while (left2 < right2) {
                int mid2 = (left2 + right2) / 2;
                if (sorted_A[mid2] <= new_a) {
                    left2 = mid2 + 1;
                } else {
                    right2 = mid2;
                }
            }
            int pos2 = left2 - 1;
            
            int candidates_above = N - pos2 - 1;
            if (candidates_above >= M) {
                low = mid + 1;
                continue;
            }
            
            int need2 = M - candidates_above;
            if (need2 <= 0) {
                answer = mid;
                high = mid - 1;
                continue;
            }
            
            i64 sum = 0;
            if (pos2 >= need2) {
                sum = prefix[pos2 + 1] - prefix[pos2 + 1 - need2];
            } else {
                sum = prefix[pos2 + 1];
                need2 -= pos2 + 1;
                sum += need2 * new_a;
            }
            
            i64 total_needed = sum - (prefix[pos2 + 1] - prefix[pos2 + 1 - need2]);
            
            if (sum <= (new_a * need2) + (K - mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << " ";
    }
    cout << "\n";
    
    return 0;
}