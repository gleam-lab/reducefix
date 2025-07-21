#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long long, long long> pl;

long long minProduct(int N, int K, vector<int>& A, vector<int>& B) {
    // Sort pairs based on A[i] in descending order
    vector<pl> v(N);
    for(int i = 0; i < N; ++i)
        v[i] = {A[i], B[i]};
    sort(v.rbegin(), v.rend());

    // Priority queue to maintain the smallest sum of B[i]
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;
    for(int i = 0; i < K; ++i) {
        sum += v[i].second;
        pq.push(v[i].second);
    }

    long long result = LLONG_MAX;
    for(int i = K; i < N; ++i) {
        result = min(result, sum * v[i].first);
        sum -= pq.top();
        pq.pop();
        sum += v[i].second;
        pq.push(v[i].second);
    }

    // Handle the last segment
    if(K == N)
        return sum * v[0].first;

    result = min(result, sum * v[K].first);

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        for(int i = 0; i < N; ++i)
            cin >> B[i];

        cout << minProduct(N, K, A, B) << '\n';
    }
    return 0;
}