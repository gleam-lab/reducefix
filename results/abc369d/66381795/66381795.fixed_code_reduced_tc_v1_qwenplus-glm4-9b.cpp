#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n, a;
int main (){
    cin >> n;
    vector<int> data(n);
    rep(i, n){
        cin >> data[i];
    } 
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cnt++;
        if (cnt % 2 == 0) {  // Ensure we are processing pairs
            if (i + 1 < n && data[i + 1] * 2 > data[i] + data[i + 1]) {
                sum += data[i + 1] * 2;
                i++;  // Move past the current pair
            } else {
                sum += data[i] * 2;
            }
        } else {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}