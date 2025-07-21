#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
long long a[MAXN], b[MAXN];

bool check(long long x, vector<long long>& A, vector<long long>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 0; i < A.size(); ++i) {
        if(i >= B.size() || A[i] > B[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    vector<long long> A(a, a + n), B(b, b + n - 1);
    
    long long left = *max_element(A.begin(), A.end()), right = 1e9 + 7;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        B.push_back(mid);
        sort(B.begin(), B.end());
        
        if(check(mid, A, B)) {
            right = mid - 1;
        } else {
            left = mid + 1;
            B.pop_back();
        }
    }

    cout << left << '\n';

    return 0;
}