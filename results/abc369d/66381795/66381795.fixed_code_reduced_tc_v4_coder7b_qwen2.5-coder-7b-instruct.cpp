#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
vector<int> data;

int main(){
    cin >> n;
    data.resize(n);
    rep(i, n){
        cin >> data[i];
    }
    
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if((i + 1) < n && data[i] * 2 > data[i + 1]){
            sum += min(data[i], data[i + 1]) * 2;
            i++; // Skip the next element as it is already considered
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}