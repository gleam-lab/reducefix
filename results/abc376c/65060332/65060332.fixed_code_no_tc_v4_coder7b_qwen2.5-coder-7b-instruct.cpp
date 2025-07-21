#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int> a(N), b(N);

bool canPlaceAll(int x) {
    sort(a.begin() + 1, a.begin() + N);
    sort(b.begin(), b.begin() + N - 1);
    
    for(int i = 1; i < N; ++i) {
        if(a[i] > x || (i != N - 1 && b[i - 1] < a[i])) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i) cin >> b[i];
    
    int lo = *max_element(a.begin() + 1, a.begin() + n), hi = 1e9;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(canPlaceAll(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    if(!canPlaceAll(lo)) cout << -1 << '\n';
    else cout << lo << '\n';
    
    return 0;
}