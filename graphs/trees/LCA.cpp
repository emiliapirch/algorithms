#include <bits/stdc++.h>
using namespace std;

constexpr int K = 17;
constexpr int M = 3e4 + 10;

// algorytm bez visited (bo jestes na drzewie i jak idziesz w dol to nie potrzeba)

int jmp[M][K]; // przodkowie poteg dwojki
int dep[M];
vector<int> g[M];

// ustalenie tablicy dep oraz jmp
void jump(int v, int p = 0) {

    // depth dziecka to jest depth parenta + 1
    dep[v] = dep[p] + 1;

    // zerowym przodkiem jest bezposredni rodzic
    jmp[v][0] = p;

    for (int i = 1; i < K; i++) {
        int j = jmp[v][i - 1];
        jmp[v][i] = jmp[j][i - 1];
    }

    // wlacz funkcje dla wszytskich innych dzieci wierzcholka
    for (auto w : g[v]) 
        if (w != p) 
            jump(w, v);
}

int lca(int a, int b) {
    if (dep[b] > dep[a]) swap(a, b);

    // podsadzasz a do gory na poziom b potegami dwojki
    for (int i = K - 1; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b])
            a = jmp[a][i];
    }

    if (a == b) return a;

    for (int i = K - 1; i >= 0; i--) {
        if (jmp[a][i] != jmp[b][i]) {
            a = jmp[a][i];
            b = jmp[b][i];
        }
    }

    return jmp[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    jump(1);

    cin >> a >> b;
    int l = lca(a, b);
}



