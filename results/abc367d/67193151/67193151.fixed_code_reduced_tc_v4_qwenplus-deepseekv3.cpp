#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n * 2);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    vector<int> prefix(n * 2);
    prefix[0] = a[0] % m;
    for(int i = 1; i < n * 2; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    
    long long sum = 0;
    vector<int> cnt(m, 0);
    cnt[0] = 1;
    
    for(int i = 0; i < n * 2; i++) {
        if(i >= n) {
            cnt[prefix[i - n]]--;
        }
        sum += cnt[prefix[i]];
        if(i < n) {
            cnt[prefix[i]]++;
        }
    }
    
    cout << sum << "\n";
    return 0;
}