#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    long long del = k / 2;
    long long md = k % 2;
    long long st = del;
    long long gl = (n - 1) - del;
    if(md == 0){
        cout << num[gl] - num[st] << endl;
    }else{
        long long ans = min((num[gl - 1] - num[st]), (num[gl] - num[st + 1]));
        cout << ans << endl;
    }
    return 0;
}