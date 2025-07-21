#include <bits/stdc++.h>
using namespace std;

vector<int> A;

bool check(int mid, int k) {
    int cnt = 0;
    for (int a : A) {
        if (abs(a - mid) <= mid) {
            cnt++;
        }
    }
    return cnt >= k;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int j = 0; j < Q; ++j) {
        int B, k;
        cin >> B >> k;
        
        int left = 0, right = 2 * 1e8;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(B, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
    
    return 0;
}