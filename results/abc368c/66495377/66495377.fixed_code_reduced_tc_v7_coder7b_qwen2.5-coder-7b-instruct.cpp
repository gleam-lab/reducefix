#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++) pq.push({h[i], i});

    int t = 0;
    while(!pq.empty()) {
        auto [health, idx] = pq.top(); pq.pop();
        if(health <= 0) continue;
        
        t++;
        if(t % 3 == 0) health -= 3;
        else health -= 1;
        
        pq.push({health, idx});
    }

    cout << t << endl;
    return 0;
}