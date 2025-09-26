#include <bits/stdc++.h>
using namespace std;

// Strongly Connected Components
// wedlug odwrotnej kolejnosci postordera pusc dwa DFSsy na grafie transponowanym
// DFSy sa dwa - jeden by wyznaczyc postorder a drugi na grafie transponowanym by znalezc sss

// - w kazdej sss jest cykl
// - graf transponowany to graf, w ktorym wszystkie krawedzie sa odwrocone

typedef pair<int, int> para;

constexpr int LIM = 1e6 + 10;

bool vis[LIM];
vector<int> edges[LIM];
vector<int> edges_rev[LIM];
vector<int> owner[LIM];
vector<para> postorder;


int order = 0;
void DFS(int parent) {
    vis[parent] = true;
    for (int child : edges[parent]) {
        if (vis[child]) continue;
        DFS(child);
    }
    postorder.push_back({order++, parent});
}

void revDFS(int parent, int ow) {
    vis[parent] = true;
    owner[ow].push_back(parent);

    for (int child : edges[parent]) {
        if (vis[child]) continue;
        revDFS(child, ow);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges_rev[b].push_back(a);
    }

    // ustawienie postorderu
    for (int i=1; i<=n; i++) 
        if (!vis[i]) 
            DFS(i);

    // resetowanie vis
    for (int i=1; i<=n; i++) 
        vis[i] = false;

    // wedlug postorderu revDFS
    int ow = 1;
    for (int i=postorder.size() - 1; i>0; i++) 
        if (!vis[i]) 
            revDFS(postorder[i].second, ow++);
}

