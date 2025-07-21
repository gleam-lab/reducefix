#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    int total_votes = K;
    for (int a : A) {
        total_votes += a;
    }
    
    for (int i = 0; i < N; ++i) {
        int low = 0, high = K;
        int ans = -1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int new_vote = A[i] + mid;
            
            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_vote) - sortedA.begin();
            int better = N - pos;
            
            if (A[i] + mid >= sortedA.back()) {
                better = 0;
            }
            
            if (better < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            int remaining = K - ans;
            int new_vote = A[i] + ans;
            
            vector<int> temp = A;
            temp[i] += ans;
            
            int sum_others = 0;
            for (int j = 0; j < N; ++j) {
                if (j != i && temp[j] > new_vote) {
                    sum_others += temp[j] - new_vote;
                }
            }
            
            if (sum_others > remaining) {
                ans = -1;
            } else {
                int needed = 0;
                for (int j = 0; j < N; ++j) {
                    if (j != i && temp[j] > new_vote) {
                        needed += temp[j] - new_vote;
                    }
                }
                if (needed <= remaining) {
                    // feasible
                } else {
                    ans = -1;
                }
            }
        }
        
        cout << (ans == -1 ? -1 : ans) << " ";
    }
    
    return 0;
}