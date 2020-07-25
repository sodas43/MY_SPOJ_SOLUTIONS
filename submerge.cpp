#include< bits/stdc++.h>

using namespace std;

vector<vector<int>> adjList;
vector<int> visited, low;
int cnt;

int main() {
	int N, M;

	while(1) {
		cin >> N >> M;
		if(N == 0 && M == 0)	break;

		adjList.resize(N);
		visited.resize(N, -1);
		low.resize(N, 0);

		for(int i = 0; i < N; i++) {
			int u, v;
			cin >> u >> v;

			adjList[u].push_back(v);
			adjList[v].push_back(u);


		}
	}
}