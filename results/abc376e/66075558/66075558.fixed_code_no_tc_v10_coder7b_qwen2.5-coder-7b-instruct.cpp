#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T, N, K;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        vector<pair<ll, ll>> A(N), B(N);
        for(int i = 0; i < N; ++i) {
            cin >> A[i].first >> A[i].second;
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i].first >> B[i].second;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        ll maxA = A[K-1].first;
        ll sumB = 0;
        for(int i = 0; i < K; ++i) {
            sumB += B[i].first;
        }

        ll result = maxA * sumB;

        for(int i = K; i < N; ++i) {
            sumB -= B[i-K].first;
            sumB += B[i].first;
            result = min(result, maxA * sumB);
            if(maxA < A[i].first) {
                maxA = A[i].first;
                sumB -= B[i-K].first;
                sumB += B[i].first;
                result = min(result, maxA * sumB);
            }
        }

        cout << result << "\n";
    }
    return 0;
}