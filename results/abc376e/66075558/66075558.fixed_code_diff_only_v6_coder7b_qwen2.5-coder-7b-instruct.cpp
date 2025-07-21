#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(ll N, ll K, vector<ll>& A, vector<ll>& B) {
    // Create a vector to store pairs of (A_i, B_i) and their indices
    vector<pair<ll, pair<ll, ll>>> v;
    for(int i=0;i<N;i++){
        v.push_back({A[i], {B[i], i}});
    }
    
    // Sort the vector based on A_i in descending order
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return a.first > b.first || (a.first == b.first && a.second.second < b.second.second);
    });
    
    // Priority queue to keep track of B_i values for selected elements
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    
    // Select the first K elements
    for(int i=0;i<K;i++){
        pq.push(v[i].second.first);
        sum += v[i].second.first;
    }
    
    // Initialize result with the current product
    ll res = sum * v[K-1].first;
    
    // Iterate through the remaining elements
    for(int i=K;i<N;i++){
        pq.push(v[i].second.first);
        sum += v[i].second.first;
        
        // Remove the smallest element from the queue
        sum -= pq.top();
        pq.pop();
        
        // Update the result with the new product
        res = min(res, sum * v[i].first);
    }
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for(int i=0;i<N;i++)
            cin >> A[i];
        for(int i=0;i<N;i++)
            cin >> B[i];
        
        cout << solve(N, K, A, B) << "\n";
    }
    return 0;
}