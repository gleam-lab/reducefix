#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> pq(h.begin(), h.end());
    int t = 0;
    while(!pq.empty()){
        int currentHealth = pq.top();
        pq.pop();
        
        if(currentHealth <= 0){
            continue;
        }
        
        if((t + 1) % 3 == 0){
            pq.push(currentHealth - 3);
        }else{
            pq.push(currentHealth - 1);
        }
        
        ++t;
    }
    
    cout << t << endl;
    return 0;
}