#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

int n;
int matrix[1001][1001];
bool visited[1001];

void init()
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

int dfs(int u)
{
    int counter = 0;
    stack<int> st;
    st.push(u);
    counter++;
    visited[u] = true;
    while(!st.empty())
    {
        int s = st.top();
        st.pop();
        for(int t = 1; t <= n; t++)
        {
            if(visited[t] == false && matrix[s][t] == 1)
            {
                counter++;
                visited[t] = true;
                st.push(s);
                st.push(t);
                break;
            }
        }
    }
    return counter;
}

void duyet_tru()
{
    vector<int> vt;
    for(int u = 1; u <= n; u++)
    {
        visited[u] = true;
        if(u == 1)
        {
            if(dfs(2) != n-1)
                vt.push_back(u);
        }
        else
        {
            if(dfs(1) != n-1)
                vt.push_back(u);
        }

        for(int i = 1; i <= n; i++)
            visited[i] = false;
    }
    cout << "Cac dinh tru la: ";
    for(int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";
}

int main()
{
    init();
    duyet_tru();
    return 0;
}







