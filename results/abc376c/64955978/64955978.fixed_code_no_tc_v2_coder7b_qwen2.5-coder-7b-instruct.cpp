#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end()); // Sort toys in ascending order
    sort(b.begin(), b.end()); // Sort boxes in ascending order

    ll j = 0; // Index for boxes
    bool found = false;

    for(int i = N-1; i >= 0; i--) { // Iterate over toys in reverse order
        while(j < N-1 && b[j] < a[i]) { // Find a suitable box for the current toy
            j++;
        }
        if(j == N-1 && b[j] < a[i]) { // If no suitable box is found
            found = true;
            break;
        }
        j++; // Move to the next box
    }

    if(found) {
        cout << -1 << endl; // No suitable box found
    } else {
        cout << b[N-2] + 1 << endl; // Print the minimum required box size
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}