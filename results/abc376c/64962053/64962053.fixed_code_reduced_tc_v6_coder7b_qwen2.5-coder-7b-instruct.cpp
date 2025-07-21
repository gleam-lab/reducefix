#include <bits/stdc++.h>
using namespace std;

bool canStore(vector<int>& A, vector<int>& B, long long mid) {
    int n = A.size();
    multiset<long long> boxes(B.begin(), B.end());

    for(int i=0; i<n; ++i) {
        auto it = boxes.lower_bound(A[i]);
        if(it == boxes.end())
            return false;
        boxes.erase(it);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    
    for(int i=0; i<n; ++i)
        cin >> A[i];

    for(int i=0; i<n-1; ++i)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long left = 0, right = 1e9 + 10;
    while(left < right) {
        long long mid = left + (right - left) / 2;
        
        if(canStore(A, B, mid))
            right = mid;
        else
            left = mid + 1;
    }

    cout << (left == 1e9 + 10 ? -1 : left) << '\n';
    
    return 0;
}