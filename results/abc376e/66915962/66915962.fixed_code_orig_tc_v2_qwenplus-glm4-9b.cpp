#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> elements(N);
        
        for(int i = 0; i < N; i++){
            cin >> elements[i].first;
            cin >> elements[i].second;
        }
        
        // Sort elements based on first element (descending) and then second element (descending)
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        });
        
        ll maxA = elements[0].first;
        ll sumB = elements[0].second;
        ll answer = maxA * sumB;
        
        // Iterate through the rest of the elements to find the minimum possible value
        for(int i = 1; i < K; i++){
            sumB += elements[i].second;
            if(elements[i].first < maxA)
                maxA = elements[i].first;
            answer = min(answer, maxA * sumB);
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}