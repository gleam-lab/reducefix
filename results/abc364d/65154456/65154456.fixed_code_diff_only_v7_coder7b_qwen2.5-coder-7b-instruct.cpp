#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first < b.first;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    B.resize(Q);
    
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for(int i = 0; i < Q; ++i) {
        cin >> B[i].first >> B[i].second;
    }
    
    sort(A.begin(), A.end());
    
    for(auto& b : B) {
        int target = b.first;
        int k = b.second;
        
        // Binary search to find the k-th closest point
        int left = 0, right = N - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(abs(target - A[mid]) * 2 < abs(target - A[left])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Adjusting index based on the comparison with adjacent elements
        if(left > 0 && abs(target - A[left - 1]) <= abs(target - A[left])) --left;
        
        // Calculating the k-th closest distance
        int result = abs(target - A[(left + k - 1) % N]);
        
        cout << result << endl;
    }
    
    return 0;
}