#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
long long a[N], b[N];

bool check(long long x, int idx) {
    vector<long long> dist(n);
    for(int i = 0; i < n; ++i) 
        dist[i] = abs(a[i] - b[idx]);
    
    sort(dist.begin(), dist.end());
    return dist[k[idx] - 1] <= x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    for(int i = 0; i < m; ++i) 
        cin >> b[i];
    
    vector<int> k(m);
    for(int i = 0; i < m; ++i) 
        cin >> k[i];
    
    long long left = 0, right = 1e16;
    while(left < right) {
        long long mid = (left + right) / 2;
        bool valid = true;
        for(int i = 0; i < m && valid; ++i) 
            if(!check(mid, i)) 
                valid = false;
        
        if(valid) 
            right = mid;
        else 
            left = mid + 1;
    }
    
    cout << left << "\n";
    return 0;
}