#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> para;

constexpr int LIM = 5e5 + 10;
constexpr ll oo = LLONG_MAX;

struct node {
    vector<pair<int, int>> edges;
    ll dis = oo;
    bool visited = false;
} arr[LIM];

void dijkstra() {
    priority_queue<para, vector<para>, greater<para>> pq; // sortuje wedlug .first, rosnąco w prawo
							  // sorts according to .first, from the smallest to the biggest

    arr[1].dis = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        para f = pq.top(); pq.pop();
        ll cost = f.first;

        if (arr[f.second].visited) continue;
        arr[f.second].visited = true;

        for (auto droga : arr[f.second].edges) { // droga == route in polish
            if (droga.first + cost < arr[droga.second].dis) {
                arr[droga.second].dis = droga.first + cost;
                pq.push({arr[droga.second].dis, droga.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        arr[a].edges.push_back({c, b});
        arr[b].edges.push_back({c, a});
    }

    dijkstra();

    for (int i=1; i<=n; i++) {
        if (arr[i].dis != oo) cout << arr[i].dis << '\n';
        else cout << -1 << '\n';
    }
}

