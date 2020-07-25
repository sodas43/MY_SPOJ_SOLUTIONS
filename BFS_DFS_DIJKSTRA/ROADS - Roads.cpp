#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

typedef pair<int, pii> piii;

//unordered_map<int, vector<pii>> g; // standard weighted graph <src, {dst, weight}>
//for this problem we also need to take toll. so need to modify above to <src, {dst, {weight, toll}}>
unordered_map <int, vector<piii>> g;

/*
printGraph(int totCities) {
    for (int u = 1; u <= totCities; u++) {
        cout << "City " << u << " makes an edge with \n";
        for (auto& neigh : g[u]) {
            cout << "\tCity " << neigh.first << " weight = "
                 << neigh.second.first << ":" << "toll = " << neigh.second.second << "\n";
        }
        cout << "\n";
    }
}*/

int dijkstra(int totCoins, int totCities) {
    priority_queue<piii, vector<piii>, greater<piii>> minHeap;

    minHeap.push( {0, {0, 1}} );

    while (!minHeap.empty()) {
        auto cur = minHeap.top();
        minHeap.pop();

        // these are priorty queue's elements.
        // len should be 1st item because based on this minHeap is working
        // changing to other ones as 1st element is not working

        auto lenSoFar  = cur.first;
        auto tollSoFar = cur.second.first;
        auto curCity   = cur.second.second;

        //cout << curCity << ", { " << lenSoFar << ", " << tollSoFar << " }" << endl;

        if (curCity == totCities) {
            return lenSoFar;
        }

        for (auto& neigh : g[curCity]) {

            // these are graph's elemnets
            auto neighCity  = neigh.first;
            auto neighLen = neigh.second.first;
            auto neighToll = neigh.second.second;

            //cout << "\t" << neighCity << ", { " << neighLen << ", " << neighToll << " }" << endl;

            if (tollSoFar + neighToll <= totCoins) {
                //minHeap.push({neighCity, {lenSoFar + neighLen, tollSoFar + neighToll}});
                minHeap.push({lenSoFar + neighLen, {tollSoFar + neighToll, neighCity}});
            }
        }
    }
    return -1;
}

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin); typedef pair<int, int> pii;
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

int main() {
    init();

    int T;
    cin >> T;

    while (T--) {
        g.clear();

        int totCoins, totCities, totRoads;
        cin >> totCoins >> totCities >> totRoads;

        while (totRoads--) {
            int src, dst, roadLen, toll;
            cin >> src >> dst >> roadLen >> toll;

            g[src].push_back( { dst, {roadLen, toll} } );
        }

        //printGraph(totCities);
        cout << dijkstra(totCoins, totCities) << endl;

    }
    return 0;
}