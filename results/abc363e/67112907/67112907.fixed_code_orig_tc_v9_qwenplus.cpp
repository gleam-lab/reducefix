#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int32_t main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W, Y;
	std::cin >> H >> W >> Y;

	std::vector A(H, std::vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> A[i][j];
		}
	}

	std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
	std::vector vis(H, std::vector<char>(W));

	// Initialize the border cells
	auto add_border = [&](int x, int y) {
		if (!vis[x][y]) {
			vis[x][y] = 1;
			pq.push({A[x][y], x, y});
		}
	};

	for (int i = 0; i < H; i++) {
		add_border(i, 0);
		if (W > 1) add_border(i, W - 1);
	}
	for (int j = 1; j < W - 1; j++) {
		add_border(0, j);
		if (H > 1) add_border(H - 1, j);
	}

	int remaining = H * W;
	std::vector<int> result;

	for (int year = 1; year <= Y; year++) {
		// Process all cells that sink at current sea level (year)
		while (!pq.empty()) {
			auto [elevation, x, y] = pq.top();
			if (elevation > year) break;
			pq.pop();
			remaining--;
			
			// Check neighbors
			for (int k = 0; k < 4; k++) {
				int nx = x + d[k][0], ny = y + d[k][1];
				if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
					vis[nx][ny] = 1;
					pq.push({A[nx][ny], nx, ny});
				}
			}
		}
		result.push_back(remaining);
	}

	for (int area : result) {
		std::cout << area << '\n';
	}

	return 0;
}