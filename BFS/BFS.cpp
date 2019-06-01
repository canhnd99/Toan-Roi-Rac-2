#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int n;
int matrix[1001][1001];
bool visited[1001];

void Init()
{
    ifstream file("matrix.txt", ios::in);
    file >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            file >> matrix[i][j];
        }
        visited[i] = false;
    }
}

void BFS(int u)
{
    cout << "BFS(" << u << "): ";
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while(!Q.empty())
    {
        int s = Q.front();
        cout << s << " ";
        Q.pop();
        for(int t = 1; t <= n; t++)
        {
            if(visited[t] == false && matrix[s][t] == 1)
            {
                Q.push(t);
                visited[t] = true;
            }
        }
    }
}

int main()
{
    int u;
    Init();
    cout << "Chon dinh bat dau: ";
    cin >> u;
    BFS(u);
    return 0;
}
