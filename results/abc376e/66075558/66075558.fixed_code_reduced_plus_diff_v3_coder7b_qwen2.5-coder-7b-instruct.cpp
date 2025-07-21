#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define ll long long

struct Element {
    ll value;
    bool type; // true for A, false for B
};

bool cmp(Element a, Element b) {
    return a.value != b.value ? a.value > b.value : a.type < b.type;
}

ll minProduct(int N, int K, vector<ll>& A, vector<ll>& B) {
    vector<Element> elements;
    for (int i = 0; i < N; ++i) {
        elements.push_back({A[i], true});
        elements.push_back({B[i], false});
    }
    
    sort(elements.begin(), elements.end(), cmp);
    
    priority_queue<ll> pqMaxA;
    priority_queue<ll, vector<ll>, greater<ll>> pqMinB;
    
    ll result = LLONG_MAX;
    ll currentSumB = 0;
    int countA = 0, countB = 0;
    
    for (auto& elem : elements) {
        if (elem.type) { // element from A
            pqMaxA.push(elem.value);
            countA++;
            if (countA > K) {
                pqMaxA.pop();
                countA--;
            }
        } else { // element from B
            pqMinB.push(elem.value);
            currentSumB += elem.value;
            countB++;
            if (countB > K) {
                currentSumB -= pqMinB.top();
                pqMinB.pop();
                countB--;
            }
        }
        
        if (countA == K && countB == K) {
            result = min(result, pqMaxA.top() * currentSumB);
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        cout << minProduct(N, K, A, B) << '\n';
    }
    return 0;
}