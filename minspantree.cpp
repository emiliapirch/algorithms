#include <bits/stdc++.h>
using namespace std;

struct EDGE {
    int a, b;
    long long c;
    int in;

    bool operator<(const EDGE& x) const{
        return c > x.c;
    }
};

vector<int> p;
vector<EDGE> edge;
vector<EDGE> del_edge;
vector<int> res;

int get(int a){
    return p[a] = (p[a] == a ? a : get(p[a]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    long long s, c;

    cin >> n >> m >> s;

    p.resize(n+1);

    for (int i=0; i<=n; i++) 
        p[i] = i;

    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        edge.push_back({a, b, c, i+1});
    }
 
    sort(edge.begin(), edge.end());

 
    for (int i=0; i<edge.size(); i++) {
        a = edge[i].a;
        b = edge[i].b;
        c = edge[i].c;

        int A = get(a);
        int B = get(b);
 
        if(A == B) del_edge.push_back(edge[i]);
 
        p[A] = B;
    }

    sort(del_edge.begin(), del_edge.end()); // od najw do najm
    
    long long suma = 0;
    for (int i=del_edge.size()-1; i>=0; i--) {
        if (suma + del_edge[i].c <= s) {
            suma += del_edge[i].c;
            res.push_back(del_edge[i].in);
        }
    }

    cout << res.size() << '\n';

    sort(res.begin(), res.end());
    for (auto i : res) cout << i << ' ';
    cout << '\n';
}

