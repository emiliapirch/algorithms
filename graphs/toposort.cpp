#include <bits/stdc++.h>
using namespace std;

// ------------ TopoSort ------------ 
// sortowanie wierzcholkow (lub sss, ktore mozesz przedstawic jako wierzcholki w nowoutworzonym grafie) w grafie skier. wedlug kierunku krawedzi: wszystkie krawedzie wchodzace do wierzcholka sa po lewej a wychodzace po prawej
 
// pierwszymi wierzcholkmi sa te, ktore nie maja wchodzacych krawedzi
// dodajesz do wyniku wierzcholki, ktorych wszystkie krawedzie wchodzace zostaly juz rozpatrzone (wierzcholki z ktorych one wychodza juz zostaly uwzglednione w wyniku)

// nie da sie zrobic TopoSort na grafie, w ktorym jest jakis cykl. Np. graf: a -> b oraz b <- a 
// DAG - directed acyclic graph, sklada sie z jedynie jednej sss ??. Wlasnie na tego typu grafach mozna uzywac TopoSort.

// Krok po kroku...
// 1. liczymy stopien wejsciowy wierzcholkow przy wczytywaniu danych i zapisujemy go do tablicy (enters, deg_in)
// 2. na kolejke wrzucamy wierzcholki, ktorych deg_in == 0
// 3. petla: a) bierzemy wierzcholek z kolejki; 
//           b) wrzucamy go na rozwiazanie (liste indeksow posortowanych wierzcholkow);
//           c) dla kazdego sasiada X zmniejszamy deg_in[x]--
//           d) jezeli deg_in[x] == 0, to wrzucamy go na kolejke;


// ------------ TopoSort ------------ english
// sorting vertices (or SCCs, which you can represent as vertices in a newly created graph) 
// in a directed graph according to the direction of edges: all incoming edges to a vertex are on the left, 
// and outgoing edges are on the right

// The first vertices are those that have no incoming edges
// You add to the result the vertices whose all incoming edges have already been considered 
// (the vertices from which these edges originate have already been included in the result)

// TopoSort cannot be applied to a graph that contains any cycle. 
// For example, a graph: a -> b and b <- a
// DAG - directed acyclic graph, consists of only one SCC ?? 
// TopoSort can be used precisely on this type of graph.

// Step by step...
// 1. Compute the in-degree of vertices when reading the input data and store it in an array (enters, deg_in)
// 2. Push vertices with deg_in == 0 into a queue
// 3. Loop: a) take a vertex from the queue; 
//          b) add it to the solution (list of sorted vertex indices);
//          c) for each neighbor X, decrement deg_in[x]--;
//          d) if deg_in[x] == 0, push it into the queue;

constexpr int LIM = 1e5 + 10;
int deg_in[LIM];
vector<int> edges[LIM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> output;
    int n, m, a, b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        deg_in[b]++;
        edges[a].push_back(b);
    }

    queue<int> q;
    for (int i=1; i<=n; i++)
        if (deg_in[i] == 0) q.push(i);

    while (!q.empty()) {
        int f = q.front(); q.pop();
        output.push_back(f);

        for (int child : edges[f]) {
            deg_in[child]--;
            if (deg_in[child] == 0) q.push(child);
        }
    }

    if (output.size() == n) {
        cout << "TAK\n";
        for (int i : output) cout << i << ' ';
        cout << '\n';
    }
    else cout << "NIE\n";
}

