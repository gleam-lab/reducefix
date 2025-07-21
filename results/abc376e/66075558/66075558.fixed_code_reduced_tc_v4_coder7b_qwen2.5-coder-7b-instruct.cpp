#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 9;

struct Node {
    ll first, second;
};

Node a[MAXN], b[MAXN];

bool cmp(Node a, Node b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    for(int i = 1; i <= n; ++i) {
        a[i].first = A[i-1];
        a[i].second = i;
    }
    
    for(int i = 1; i <= n; ++i) {
        b[i].first = B[i-1];
        b[i].second = i;
    }
    
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+n+1, cmp);
    
    ll ans = LLONG_MAX, sum = 0;
    for(int i = 1; i <= k; ++i) {
        sum += b[i].first;
    }
    
    ans = min(ans, sum * a[k].first);
    
    for(int i = k+1; i <= n; ++i) {
        sum += b[i].first - b[i-k].first;
        ans = min(ans, sum * a[i].first);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}