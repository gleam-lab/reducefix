#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    cin >> n >> m;
    
    // Input the sequence a
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Initialize variables
    int sum = 0, cnt = 0;
    int* b = new int[m]();  // Using a vector to store counts, initialized with 0
    
    // Process the sequence
    for(int i = 0; i < 2 * n; i++) {
        int mod = (i < n) ? a[i] % m : a[i - n] % m;
        cnt += b[mod];  // Increment count based on value of mod
        sum += cnt;  // Add current count to sum
        b[mod]++;  // Increment count for mod in b
    }
    
    cout << sum;
    delete[] b;  // Don't forget to free the allocated memory
    return 0;
}