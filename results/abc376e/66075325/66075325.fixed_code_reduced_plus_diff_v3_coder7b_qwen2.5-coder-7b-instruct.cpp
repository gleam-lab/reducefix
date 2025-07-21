#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<long long, int> pii;

long long minProduct(int N, int K, vector<int>& A, vector<int>& B) {
    vector<pii> pairs(N);
    for(int i = 0; i < N; ++i) {
        pairs[i] = {A[i], B[i]};
    }
    
    // Sort pairs based on A[i]
    sort(pairs.begin(), pairs.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0, result = LLONG_MAX;
    
    for(int i = 0; i < N; ++i) {
        int a = pairs[i].first, b = pairs[i].second;
        
        if(i < K) {
            pq.push(b);
            sum += b;
        } else {
            if(b > pq.top()) {
                sum -= pq.top();
                sum += b;
                pq.pop();
                pq.push(b);
            }
        }
        
        if(i >= K - 1) {
            result = min(result, static_cast<long long>(a) * sum);
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        for(int i = 0; i < N; ++i) cin >> A[i];
        for(int i = 0; i < N; ++i) cin >> B[i];
        
        cout << minProduct(N, K, A, B) << '\n';
    }
    
    return 0;
}