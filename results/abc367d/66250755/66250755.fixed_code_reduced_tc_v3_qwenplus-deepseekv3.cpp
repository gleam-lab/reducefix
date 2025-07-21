#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> w(2 * n + 1);
    unordered_map<int, int> count;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    count[0] = 1;
    long long an = 0;
    
    for(int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        if(i > n) {
            count[w[i - n]]--;
        }
        if(i >= n) {
            an += count[w[i]];
        }
        count[w[i]]++;
    }
    
    cout << an;
    return 0;
}