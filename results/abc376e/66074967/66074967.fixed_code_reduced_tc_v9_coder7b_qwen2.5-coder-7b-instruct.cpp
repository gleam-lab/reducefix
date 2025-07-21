#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2e5 + 9;

struct Element {
    int val, idx;
};

bool cmp(Element &a, Element &b) {
    return a.val > b.val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<Element> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].val;
            A[i].idx = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].val;
            B[i].idx = i;
        }
        
        // Sort A based on values in descending order
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        
        long long best_sum = INF, best_max = -INF;
        for (int i = 0; i < N; ++i) {
            best_sum += B[i].val;
            best_max = max(best_max, A[i].val);
            
            if (i >= K) {
                best_sum -= B[i - K].val;
            }
            
            if (i >= K - 1) {
                best_sum = max(best_sum, best_sum - best_max + A[i].val);
                best_max = max(best_max, A[i].val);
            }
        }
        
        cout << best_sum << '\n';
    }
    
    return 0;
}