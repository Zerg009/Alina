#include <iostream>
#include <fstream>
#include <deque>
#define N 8
using namespace std;

int arr[N][N];
deque<int> nums;
int visited[N];
int par[N];

void bfs(int start)
{
    nums.push_back(start);
    visited[start] = 1;
    while (!nums.empty())
    {
        int curent = nums.front();
        nums.pop_front();
        cout << curent << " ";
        for (int i = 0; i < N; i++)
        {
            if (arr[curent][i] && !visited[i])
            {
                par[i] = curent;
                nums.push_back(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start)
{
    if (visited[start])
        return;

    visited[start] = 1;
    cout << start << " ";
    for (int i = 0; i < N; i++)
    {
        if (arr[start][i] && !visited[i])
        {
            dfs(i);
        }
    }
}


void add_arc(int from, int to)
{
    arr[from][to] = 1;
    arr[to][from] = 1;
}

void afisare()
{
    ofstream out("out.out");
    for (int i = 0; i < N; i++)
    {
        out << endl;
        for (int j = 0; j < N; j++)
        {
            out << arr[i][j] << " ";
        }
    }
}
int main()
{
    ifstream in("in.in");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            in >> arr[i][j];
        }
    }
    int opt;
    int from, to;

    while (1)
    {
        cout << "\n--------------Meniu--------------" << endl;
        cout << "1.Adaugare arc." << endl;
        cout << "2.Afisare" << endl;
        cout << "3.Bfs" << endl;
        cout << "4.Dfs" << endl;
        cout << "Introduceti optiunea: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "From: ";
            cin >> from;
            cout << "To: ";
            cin >> to;
            add_arc(from, to);
            break;
        case 2:
            afisare();
            break;
        case 3:
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (arr[i][j] && !visited[j])
                    {
                        bfs(j);
                    }
                }
            }
            cout << "From: ";
            cin >> from;
            cout << "To: ";
            cin >> to;

            while (par[to] != from)
            {
                to = par[to];
            }

            break;
        case 4:
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (arr[i][j] && !visited[j])
                    {
                        dfs(j);
                    }
                }
            }

            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
