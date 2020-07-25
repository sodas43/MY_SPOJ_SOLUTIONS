
/*
 * Dijkstra's algorithm is meant to solve the Single Source shortest path problem,
 * which essentially means that the source vertex is fixed and we want to find the
 * shortest(minimum weight) path to all other vertices. Notice here that in this
 * problem, the destination vertex is fixed (the exit cell) while the source vertex
 * is different for each mouse. It would be computationally inefficient if we run a
 * Dijkstra for n different source vertices. Hence a better approach would be to
 * reverse the edges so that we can treat the destination vertex (as the source vertex)
 * and see how many mice are able to reach their starting vertex within the given time
 * limit. This can be done by reversing the edges and then applying Dijkstra treating
 * the exit cell as the "source vertex".
 *
 * So Reverse the given edges and use the given end cell as source cell(starting cell)
 * and then count the cells that can be reached within given time limit.
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

unordered_map<int, vector<pii>> g;
vector<int> dist;

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    minHeap.push( {0, src} );
    dist[src] = 0;

    while (!minHeap.empty()) {
        auto cur = minHeap.top();
        minHeap.pop();

        auto curDist = cur.first;
        auto curNode = cur.second;

        if (curDist > dist[curNode])    continue;

        for (auto& neigh : g[curNode]) {
            auto neighNode = neigh.first;
            auto neighDist = neigh.second;

            if (neighDist + curDist < dist[neighNode]) {
                dist[neighNode] = neighDist + curDist;
                minHeap.push( {dist[neighNode], neighNode} );
            }
        }
    }
}

int main() {
    init();

    int cells, exitCell, timer, connections;
    cin >> cells >> exitCell >> timer >> connections;

    g.clear();
    dist.clear();
    //dist.resize(cells + 1);
    dist.assign(cells + 1, INT_MAX);

    for (int i = 0; i < connections; ++i) {
        int src, dst, weight;
        cin >> src >> dst >> weight;

        //revesre edges
        g[dst].push_back({src, weight});
    }

    dijkstra(exitCell);

    int noOfMice = 0;

    for (int i = 1; i <= cells; ++i) {
        if (dist[i] <= timer)   ++noOfMice;
    }

    cout << noOfMice << endl;

    return 0;
}