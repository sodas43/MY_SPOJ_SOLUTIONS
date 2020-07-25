#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> dirs {{ -2, -1}, { -1, -2}, {1, -2}, {2, -1},
	{ -2, 1},  { -1, 2},  {1, 2},  {2, 1}};

bool inSide(int x, int y) {
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

class cell {
public:
	int x, y;
	int depth;
	cell() {}
	cell(int x, int y, int depth) : x(x), y(y), depth(depth) {}
};

int minMove(int start_x, int start_y, int end_x, int end_y) {

	bool visited[9][9];
	memset(visited, false, sizeof(visited));

	queue<cell> q;
	cell node(start_x, start_y, 0);

	q.push(node);
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		cell tmp = q.front();
		q.pop();

		if (tmp.x == end_x && tmp.y == end_y) {
			return tmp.depth;
		}

		for (int i = 0; i < 8; ++i) {
			int dx = tmp.x + dirs[i][0];
			int dy = tmp.y + dirs[i][1];

			if (inSide(dx, dy) && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push(cell(dx, dy, tmp.depth + 1));

			}
		}
	}
}

int main() {
	init();

	int T;
	cin >> T;

	while (T--) {
		char start_x, end_x;
		int start_y, end_y;

		cin >> start_x >> start_y >> end_x >> end_y;

		start_x = start_x - 'a' + 1;
		end_x   = end_x - 'a' + 1;

		cout << minMove(start_x, start_y, end_x, end_y) << endl;
	}
	return 0;
}