#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    
    for(auto& val : v){
        cin >> val;
    }
    
    sort(v.begin(), v.end()); // Sort the array
    
    long long ans = v[n-1] - v[0]; // Initial answer is the difference between max and min values
    
    // Try removing k smallest elements
    for(int i=0; i<k; i++){
        ans = min(ans, v[n-k+i] - v[i]);
    }
    
    cout << ans << endl; // Print the final answer
    return 0;
}