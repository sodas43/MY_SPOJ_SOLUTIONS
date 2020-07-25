#include <bits/stdc++.h>

// ALGO: DO two DFS/BFS traversals from any vertex S to find the furthest vertex X.
// Then do another DFS/BFS from vertex X to get the ACTUAL furthest vertex Y from X.
// The length of the unique path from X to Y is the diameter of tree.

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

unordered_map<int, vector<int>> g;
vector<int> dist;

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

pii bfs(int src, int nodes) {
	queue<int> q;

	dist.clear();
	dist.assign(nodes + 1, INT_MAX);

	q.push(src);
	dist[src] = 0;

	while (!q.empty()) {
		auto parent = q.front();
		q.pop();

		for (auto& neighbour : g[parent]) {

			if (dist[neighbour] == INT_MAX) {
				q.push(neighbour);
				dist[neighbour] = dist[parent] + 1;
			}
		}
	}

	//  get farthest node distance and its index
	int maxDistance = 0, nodeIdx;

	for (int i = 1; i <= nodes; ++i) {

		if (dist[i] > maxDistance) {
			maxDistance = dist[i];
			nodeIdx = i;
		}
	}

	return {nodeIdx, maxDistance};
}

int main() {
	init();

	int nodes;
	cin >> nodes;

	g.clear();

	for (int i = 1; i <= nodes - 1; ++i) {
		int src, dst;
		cin >> src >> dst;

		g[src].push_back(dst);
		g[dst].push_back(src);

	}

	// start
	pii t1, t2;
	t1 = bfs(1, nodes);

	t2 = bfs(t1.first, nodes);

	/*cout << "longest path is from " << t1.first <<" to " << t2.first
	    << " of length " << t2.second << endl;*/

	cout << t2.second;

	return 0;
}