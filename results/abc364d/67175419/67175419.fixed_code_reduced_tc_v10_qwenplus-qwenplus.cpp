#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, Q;
vector<long long> A;
vector<pair<long long, int>> queries[MAXN];

long long answer[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    for (int j = 0; j < Q; ++j) {
        long long b;
        int k;
        cin >> b >> k;
        queries[j] = {make_pair(b, k)};
    }

    // For each query, binary search the minimum distance such that there are at least k elements within that distance
    for (int j = 0; j < Q; ++j) {
        long long b = queries[j].first;
        int k = queries[j].second;
        
        long long low = 0;
        long long high = 2e14;  // Max possible distance is ~2*1e8, but be generous
        
        while (low < high) {
            long long mid = (low + high) / 2;
            
            // Find the range of elements in A within distance mid from b
            long long left = b - mid;
            long long right = b + mid;
            
            auto l = lower_bound(A.begin(), A.end(), left);
            auto r = upper_bound(A.begin(), A.end(), right);
            int count = r - l;
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        answer[j] = low;
    }
    
    for (int j = 0; j < Q; ++j) {
        cout << answer[j] << "\n";
    }
    
    return 0;
}