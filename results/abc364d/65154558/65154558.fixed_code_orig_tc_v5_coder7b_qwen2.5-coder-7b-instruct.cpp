#include<bits/stdc++.h>
#include<array>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int a[N];

bool check(int mid, int x, int y) {
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x + 100000000]++;
    }
    for(int i = 1; i < N; i++) {
        a[i] += a[i - 1];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        
        // Clear previous distances
        while(!pq.empty()) pq.pop();
        
        // Add distances from left side
        for(int j = 0; j <= min(x, 200000000); j++) {
            if(a[min(N - 1, x + j)] - a[max(0, x - j - 1)] >= k) {
                pq.push(j);
            }
        }
        
        // Add distances from right side
        for(int j = 1; j <= 200000000; j++) {
            if(a[min(N - 1, x + j)] - a[max(0, x - j - 1)] >= k) {
                pq.push(j);
            }
        }
        
        // Remove extra distances that are larger than k
        while(pq.size() > k) pq.pop();
        
        if(!pq.empty()) {
            cout << pq.top() << endl;
        } else {
            cout << "0" << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}