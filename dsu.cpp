#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 1e5 +10;

vector<int> ow, sizes, mini, maks;

int Find(int x) {
    if (ow[x] == x) 
        return x;
    return ow[x] = Find(ow[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (sizes[a] > sizes[b]) swap(a, b);

    ow[b] = a;
    sizes[a] += sizes[b];
    mini[a] = min(mini[a], mini[b]);
    maks[a] = max(maks[a], maks[b]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v;
    string mode;
    
    cin >> n >> m;

    ow.resize(n+1);
    sizes.resize(n+1);
    mini.resize(n+1);
    maks.resize(n+1);

    iota(ow.begin(), ow.end(), 0);
    iota(mini.begin(), mini.end(), 0);
    iota(maks.begin(), maks.end(), 0);

    fill(sizes.begin(), sizes.end(), 1);


    while (m--) {
        cin >> mode >> u;

        if (mode == "union") {
            cin >> v;
            Union(u, v);
        }
        else {
            int owner = Find(u);
            cout << mini[owner] << ' ' << maks[owner] << ' ' << sizes[owner] << '\n';
        }
    }
}

