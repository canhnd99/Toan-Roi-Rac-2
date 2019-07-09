
/*
    -) Kiến thức cần nhớ:
        +) kiểu dữ liệu struct.
        +) Hàm sort trong thư viện algorithm.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
    int u, v, w;
};

int n, m, D = 0;
vector<int> parent;
vector<edge> edges;
vector<edge> T;

void init()
{
    cout << "Nhap vao so dinh va so canh: ";
    cin >> n >> m;
    parent.resize(n);
    edges.resize(m);
    cout << "Nhap vao canh va trong so tuong ung: " << endl;
    for(edge &e: edges)
        cin >> e.u >> e.v >> e.w;
}

bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

void simpleKruskal()
{
    for(int v = 1; v <= n; v++)
        parent[v] = v;

    sort(edges.begin(), edges.end(), cmp); // sap xep cac canh theo trong so.

    for(edge &e: edges)
    {
        if(parent[e.u] != parent[e.v])
        {
            D += e.w;
            T.push_back(e);

            int old_par = parent[e.u];
            int new_par = parent[e.v];
            for(int i = 1; i <= n; i++)
            {
                if(parent[i] == old_par)
                    parent[i] = new_par;
            }
        }
    }
}

void printResults()
{
    cout << "==> Cac canh cua cay khung nho nhat: " << endl;
    for(int i = 0; i < T.size(); i++)
        cout << T[i].u << "," << T[i].v << endl;
    cout << "==> Gia tri cua cay khung nho nhat: " << D << endl;
}

int main()
{
    init();
    simpleKruskal();
    printResults();
    return 0;
}
