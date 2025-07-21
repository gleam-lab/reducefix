#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    
    int toy_ptr = 0;
    int box_ptr = 0;
    vector<bool> box_used(N-1, false);
    int remaining_toy = -1;
    
    while (toy_ptr < N && box_ptr < N-1) {
        if (a[toy_ptr] <= b[box_ptr]) {
            box_used[box_ptr] = true;
            toy_ptr++;
            box_ptr++;
        } else {
            if (remaining_toy == -1) {
                remaining_toy = toy_ptr;
                toy_ptr++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (toy_ptr < N) {
        if (remaining_toy == -1) {
            remaining_toy = toy_ptr;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (remaining_toy != -1) {
        cout << a[remaining_toy] << endl;
    } else {
        cout << 1 << endl; // All toys fit in existing boxes, but we need to buy a new box (minimum x is 1)
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}