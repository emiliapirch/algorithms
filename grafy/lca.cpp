#include <bits/stdc++.h>
using namespace std;

// algorytmy na odleglosci miedzy wierzcholkami: BFS, Dijkstra, Berman Ford, LCA

// Definicje drzewa:
// - spojny graf ktory ma n-1 krawedzi
// - spojny graf bez cykli
// - z ktorego da sie dojsc z kazdego do kazdego innego miejsca na jeden sposob

// LCA -------------------------------------------------------------------------
// czyli znajdywanie najnizszego wspolnego przodka dwoch wierzcholkow
// - dziala tylko na drzewach
// - czas O(log n) 

// Krok po kroku... 
// 0. DFS(), zapisanie ojcow i odleglosci od korzenia
// 1. Wyrownaj wierzcholek, ktory jest nizej, do wierzchoka, ktory jest wyzej - teraz są na tym samym depth
// 2. Sprawdz czy wierzcholki nie sa takie same (czy a == b)
// 3. Idz z wierzcholkow w gore potegami dwojki dopoki drogi nie skrzyzuja sie (dopoki a == b)
//          jezeli po skoku o 2^n a == b, znaczy to ze najblizszy przodek mogl zostac ominiety,
//          wiec musisz zrobic mniejszy skok
// 4. Parent wierzcholkow, w ktorych sie zatrzymasz, jest wynikiem


// offline - nie przyjmuje modyfikacji grafu
// n log n

// Zlozonosc pamieciowa:
// 10^6 * int == 4 mb
// 10^6 * long long = 8 mb

// 2^n == 1 << n

constexpr int LIM = 1e6 + 10;
constexpr int LOG = 21;

struct node {
                   // skooki potegami dwojki dla kazdego wierzcholka
    int depth = 0, anc[LOG];
    bool vis = false;
    vector<int> edges;
} tree[LIM];

void DFS(int parent_ind = 1) {
    tree[parent_ind].vis = true;

    for (int child_ind : tree[parent_ind].edges) {
        if (tree[child_ind].vis) continue;

        tree[child_ind].depth = tree[parent_ind].depth + 1;
        
        tree[child_ind].anc[0] = parent_ind;
        for (int i=1; (1 << i) <= tree[child_ind].depth; i++) {
            tree[child_ind].anc[i] = tree[ tree[child_ind].anc[i-1] ].anc[i-1];
        }

        DFS(child_ind);
    }
}

int LCA(int a_ind, int b_ind) {
    if (tree[a_ind].depth < tree[b_ind].depth) swap(a_ind, b_ind);

    int dis = tree[a_ind].depth - tree[b_ind].depth, pow = LOG;
    while (dis > 0) {
        while ((1 << pow) > dis) {
            pow--;
        }
        a_ind = tree[a_ind].anc[pow];
        dis -= (1 << pow);
    }

    if (a_ind == b_ind) return a_ind;

    for (int i=LOG-1; i>=0; i--) {
        int ancA = tree[a_ind].anc[i], ancB = tree[b_ind].anc[i];

        if (ancA == ancB) continue;

        a_ind = ancA;
        b_ind = ancB;
    }

    return tree[a_ind].anc[0];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, parent;
    cin >> n >> m;

    for (int i=2; i<=n; i++) {
        cin >> parent;
        tree[parent].edges.push_back(i);
        tree[i].edges.push_back(parent);
    }

    DFS();

    while (m--) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}

