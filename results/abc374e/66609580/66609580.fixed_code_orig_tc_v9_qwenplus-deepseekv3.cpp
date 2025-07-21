#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v){
    long long cnt = 0;
    for (int i = 1;i <= n;i++){
        long long _lcm = a[i] / __gcd(a[i],b[i]) * b[i];
        long long full_cycles = v / _lcm;
        long long partial_time = v % _lcm;
        
        // Calculate cost for full cycles
        long long full_cost = full_cycles * min(p[i] * (_lcm / a[i]), q[i] * (_lcm / b[i]));
        
        // Calculate cost for remaining partial cycle
        long long partial_cost = LLONG_MAX;
        for (long long j = 0; j * a[i] <= partial_time; j++){
            long long remaining = partial_time - j * a[i];
            long long b_count = (remaining + b[i] - 1) / b[i]; // ceil division
            partial_cost = min(partial_cost, j * p[i] + b_count * q[i]);
        }
        
        cnt += full_cost + partial_cost;
        if (cnt > x) return false;
    }
    return true;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> x;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 1LL << 60;
    while (l < r){
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}