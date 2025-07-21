#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N - 1);
    
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++){
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll min_x = LLONG_MAX;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            if (a[i] <= b[j]) {
                min_x = min(min_x, b[j]);
                break;
            }
        }
    }
    
    if (min_x == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_x << endl;
    }
    
    return 0;
}