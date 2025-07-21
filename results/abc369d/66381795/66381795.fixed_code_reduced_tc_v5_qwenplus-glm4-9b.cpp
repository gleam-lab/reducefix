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
    rep(i, n){
        cnt++;
        if (cnt % 4 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}