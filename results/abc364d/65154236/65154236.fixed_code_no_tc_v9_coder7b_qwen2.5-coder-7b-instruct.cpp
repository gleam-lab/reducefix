#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> A, B;
vector<pair<int, int>> queries;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first < p2.first;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    // Read coordinates of points A
    for(int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    
    // Read coordinates of points B and corresponding k values
    for(int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        B.push_back(b);
        queries.push_back({b, k});
    }
    
    // Sort the array A
    sort(A.begin(), A.end());
    
    // Process each query
    for(auto& [b, k]: queries) {
        int index = upper_bound(A.begin(), A.end(), b) - A.begin(); // Find first element greater than b
        int count_less = index; // Number of elements less than or equal to b
        
        // If there are not enough elements less than or equal to b
        if(count_less < k) {
            cout << A[count_less] - b << endl; // Distance to next element
        } else {
            // Calculate the position of the k-th closest element
            int pos = index - k + 1;
            cout << abs(A[pos] - b) << endl; // Distance to k-th closest element
        }
    }
    
    return 0;
}