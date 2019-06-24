#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int n, matrix[1001][1001];
bool visited[1001];

void init()
{
    ifstream file("matrix.txt", ios::in);
    file >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            file >> matrix[i][j];
        visited[i] = false;
    }
}

void tree_bfs(int u)
{
    vector<vector<int>> vt;
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty())
    {
        int s = Q.front();
        Q.pop();
        for(int t = 1; t <= n; t++)
        {
            if(visited[t] == false && matrix[s][t] == 1)
            {
                vector<int> v;
                v.push_back(s);
                v.push_back(t);
                vt.push_back(v);
                Q.push(t);
                visited[t] = true;
            }
        }
    }
    if(vt.size() < n-1)
        cout << "\ndo thi khong lien thong." << endl;
    else
    {
        cout << "\nCac canh cua cay khung la: " << endl;
        for(int i = 0; i < vt.size(); i++)
        {
            for(int j = 0; j < vt[i].size(); j++)
                cout << vt[i][j] << " ";
            cout << endl;
        }
    }

}

int main()
{
    int s;
    init();
    cout << "nhap vao dinh dau tien:";
    cin >> s;
    tree_bfs(s);
    return 0;
}
