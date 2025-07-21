#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<long long> a(n), b(n-1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];

    sort(a.rbegin(), a.rend()); // Sort sizes of toys in descending order
    sort(b.rbegin(), b.rend()); // Sort sizes of boxes in descending order

    long long max_box_size = 0;
    for(int i=0;i<n-1;i++){
        if(b[i]<a[i]) { // If current box cannot hold current toy
            max_box_size = a[i]; // Update max required box size
            break;
        }
    }

    if(max_box_size == 0){ // If all toys fit in existing boxes
        cout << *max_element(a.begin(), a.end()) << "\n"; // Print the largest toy size
    } else {
        cout << max_box_size << "\n"; // Print the smallest required box size
    }

    return 0;
}