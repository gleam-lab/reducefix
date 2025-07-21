#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

ll min_value(ll N, ll K, vi &A, vi &B){
    // Sort A and B based on A's elements in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // Calculate prefix sums of B
    vi prefix_sum(N+1, 0);
    for(int i=1; i<=N; ++i){
        prefix_sum[i] = prefix_sum[i-1] + B[i-1];
    }

    // Initialize variables to store the result and current sum
    ll res = LLONG_MAX, curr_sum = 0;

    // Iterate through A to find the minimum value
    for(int i=0; i<K; ++i){
        curr_sum += B[A[i]-1]; // Add corresponding B element
        res = min(res, A[i]*curr_sum); // Update result
    }

    // Adjust the result by considering remaining elements
    for(int i=K; i<N; ++i){
        curr_sum -= B[A[i-K]-1]; // Remove the element that is out of window
        curr_sum += B[A[i]-1]; // Add the new element into window
        res = min(res, A[i]*curr_sum); // Update result
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        vi A(N), B(N);
        for(ll i=0; i<N; ++i) cin >> A[i];
        for(ll i=0; i<N; ++i) cin >> B[i];

        ll result = min_value(N, K, A, B);
        cout << result << "\n";
    }

    return 0;
}