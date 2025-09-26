#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 1e6 + 10;

struct node {
    int ow, m_sum, iq_min, iq_max;
} arr[LIM];

int Find(int x) {
    if (arr[x].ow == x) return x;
    arr[x].ow = Find(arr[x].ow);
    return arr[x].ow;
}

void Union(int a, int b) {
    int a_ow = Find(a), b_ow = Find(b);
    if (a_ow == b_ow) return;
    
    arr[b_ow].m_sum += arr[a_ow].m_sum;

    arr[b_ow].iq_min = min(arr[a_ow].iq_min, arr[b_ow].iq_min);
    arr[b_ow].iq_max = max(arr[a_ow].iq_max, arr[b_ow].iq_max);

    arr[a_ow].ow = b_ow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, iq, a, b;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> m >> iq;
        arr[i].m_sum = m;
        arr[i].iq_min = iq; arr[i].iq_max = iq;
        arr[i].ow = i;
    }

    string input;
    while (cin >> input) {
        if (input == "JOIN") {
            cin >> a >> b;
            Union(a, b);
        }
        else if (input == "IQ_MIN") {
            cin >> a;
            cout << arr[Find(a)].iq_min << '\n';
        }
        else if (input == "IQ_MAX") {
            cin >> a;
            cout << arr[Find(a)].iq_max << '\n';
        }

        else if (input == "MASA") {
            cin >> a;
            cout << arr[Find(a)].m_sum << '\n';
        }
    }
}

