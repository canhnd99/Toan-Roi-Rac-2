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

void reinit()
{
    for(int i = 1; i <= n; i++)
        visited[i] = false;
}

void duyet_cau()
{
    vector<vector<int>> vt;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = matrix[j][i] = 0;
                if(dfs(1) != n)
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    vt.push_back(v);
                }
                reinit();
                matrix[i][j] = 1;
            }
        }
    }
    cout << "cac canh cau la:" << endl;
    for(int i = 0; i < vt.size(); i++)
    {
        for(int j = 0; j < vt[i].size(); j++)
            cout << vt[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    init();
    duyet_cau();
    return 0;
}
