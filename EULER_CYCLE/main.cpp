#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int n, matrix[1001][1001];

void read_data()
{
    ifstream file("matrix.txt", ios::in);
    file >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            file >> matrix[i][j];
    }
}


void euler_cycle(int u)
{
    stack<int> st, CE;
    st.push(u);
    while(!st.empty())
    {
        int counter = 0;
        int s = st.top();
        for(int i = 1; i <= n; i++)
        {
            if(matrix[s][i] == 0)
                counter++;
        }
        if(counter != n)
        {
            for(int t = 1; t <= n; t++)
            {
                if(matrix[s][t] == 1)
                {
                    st.push(t);
                    matrix[s][t] = matrix[t][s] = 0;
                    break;
                }
            }
        }
        else
        {
            CE.push(s);
            st.pop();
        }
    }
    cout << "\nEuler Cycle:" << endl;
    while(!CE.empty())
    {
        cout << CE.top() << "->";
        CE.pop();
    }
}


int main()
{
    int s;
    read_data();
    cout << "Enter first point: ";
    cin >> s;
    euler_cycle(s);
    return 0;
}
