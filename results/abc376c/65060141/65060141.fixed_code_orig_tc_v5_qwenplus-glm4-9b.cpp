#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N], max_box_size[N]; // max_box_size[i] will hold the largest box size that can accommodate toy i or larger

int main(){
.ll n, i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n - 1; i++) cin >> b[i];

    // Initialize all max_box_size to -1 (indicating no box size has been assigned yet)
    for(i = 0; i < n; i++) max_box_size[i] = -1;

    // Assign box sizes for each toy
    for(i = 1; i < n; i++) {
        // Check if there's an available box of size >= a[i]
        ll j;
        for(j = n - 1; j >= 0 && max_box_size[i - 1] == -1; j--) {
            if(b[j] >= a[i]) {
                max_box_size[i] = b[j];
                // Update the next toy's max_box_size if needed
                if(i < n - 1 && max_box_size[i + 1] == -1) max_box_size[i + 1] = b[j];
                break;
            }
        }
        // If we couldn't find a box big enough, output -1
        if(max_box_size[i] == -1) {
            cout << -1;
            return 0;
        }
    }

    // The minimum x is the minimum of all max_box_size values
    ll min_x = LLONG_MAX;
    for(i = 0; i < n; i++) {
        if(max_box_size[i] != -1) min_x = min(min_x, max_box_size[i]);
    }
    cout << min_x;
    return 0;
}