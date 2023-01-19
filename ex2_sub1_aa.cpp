/*
    Sa se genereze un graf orientat ponderat avand pe post de chei numerice codurile ASCII ale literelor
    din alfabet. Arcele se vor introduce automat de la fiecare vocala spre fiecare consoana.
    a) ponderea asociata fiecarui arc este data de suma codurilor ASCII ale nodurilor conectatede
    acesta
    b) sa se afiseze suma tuturor arcelor care constituie arborele de acoperire minima din graf
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define N 26
using namespace std;

int mat[N][N];
vector<int> visited;

int charToIdx(char c)
{
    return c - 'A';
}

void afisare()
{
    cout<<endl;
    for (int i=0; i < N; i++)
    {
        cout<<endl;
        for(int j=0;j<N;j++)
        {
            printf("%3d ",mat[i][j]);
        }
    }
    cout<<endl;
}

void prim(int nod)
{
    visited.push_back(nod);
    int min=999;
    int minIdx=-1;
    int sum = 0;
    while(visited.size()<22)
    {
        min=999;
        minIdx=-1;
        int from=-1;
        for(int num : visited)
        {
            for(int i=0;i<N;i++)
            {
                if(mat[num][i]<min && mat[num][i]!=0 && count(visited.begin(),visited.end(),i)==0)
                {
                    min = mat[num][i];
                    minIdx=i;
                    from = num;
                }
            }
        }
        visited.push_back(minIdx);
        sum+=min;
        cout<<from<<"->"<<minIdx<<"("<<min<<")"<<endl;
    }
}
int main()
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'X', 'Y', 'W', 'Z'};

    for (int i=0; i < 5; i++)
    {
        for(int j=0;j<21;j++)
        {
            mat[charToIdx(vowels[i])][charToIdx(consonants[j])] = vowels[i] + consonants[j];
        }
    }
    afisare();
    prim(0);

    return 0;
}
