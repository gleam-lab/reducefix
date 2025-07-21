#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    for(int i = 0; i < N - 1; i++) {
        while(j < N && a[j] <= b[i]) {
            j++;
        }
        if(j == N || a[j] > b[i]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << *max_element(a.begin(), a.end()) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}