#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
int main(){
    cin >> n;
    vector<int> data(n);
    rep(i, n){
        cin >> data[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0 && i + 1 < n){
            sum += 2 * data[i] + 2 * data[i+1];
            i++; // Skip the next element as it's already added
        } else {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}