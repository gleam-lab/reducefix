#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
	
	m_int n,q; cin>>n>>q;
	vector<m_int> a(n), distances(n);
	
	for(m_int i=0;i<n;++i) {
		cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	while(q--) {
		
		m_int b, k;cin>>b>>k;

		// Calculate all distances from B_j to all points A_i
		for(int i = 0; i < n; ++i) {
			distances[i] = abs(b - a[i]);
		}
		// Sort these distances
		sort(distances.begin(), distances.end());
		// The k_j-th smallest distance is at index k_j-1
		cout << distances[k-1] << "\n";
	}
}