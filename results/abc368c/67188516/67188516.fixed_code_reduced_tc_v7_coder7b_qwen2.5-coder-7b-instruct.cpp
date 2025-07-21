#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; ++i) {
        int H;
        cin >> H;
        pq.push(H);
    }
    
    long long T = 0;
    
    while(!pq.empty()) {
        ++T;
        int health = pq.top();
        pq.pop();
        
        if(T % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }
        
        if(health > 0) {
            pq.push(health);
        }
    }
    
    cout << T << endl;
    
    return 0;
}