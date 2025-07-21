#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while(Q--) {
        ll b, k;
        cin >> b >> k;
        auto cmp = [&](ll val) {
            return val < b;
        };
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        int left = pos - 1, right = pos;
        vector<ll> distances;
        for(int i = 0; i < k; ++i) {
            if(left >= 0 && right < N) {
                if(b - A[left] <= A[right] - b) {
                    distances.push_back(b - A[left]);
                    left--;
                } else {
                    distances.push_back(A[right] - b);
                    right++;
                }
            } else if(left >= 0) {
                distances.push_back(b - A[left]);
                left--;
            } else if(right < N) {
                distances.push_back(A[right] - b);
                right++;
            }
        }
        cout << distances[k-1] << '\n';
    }
    
    return 0;
}