#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> aMatch, bMatch;
vector<bool> visited;
bool adj[52][52];
int one, two;

bool isPrime(int x)
{
    if(x == 1) return false;

    int max = sqrt(x);
    for(int i = 2; i <= max; ++i)
        if(x % i == 0) return false;

    return true;
}

void makeEdge(vector<int>& even, vector<int>& odd)
{
    for(int i = 0; i < odd.size(); ++i)
    {
        for(int j =0; j < even.size(); ++j)
        {
            if(isPrime(odd[i] + even[j]))
            {
                adj[i][j] = true;
            }
        }
    }
}

bool dfs(int a, vector<int>& odd, vector<int>& even)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < even.size(); ++b)
    {
        if(b == two) continue;
        if(adj[a][b]) 
        {
            if(bMatch[b] == -1 || dfs(bMatch[b], odd, even))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartitematch(vector<int>& odd, vector<int>& even)
{
    aMatch = vector<int>(odd.size(), -1);
    bMatch = vector<int>(even.size(), -1);
    int size = 0;
    for(int i = 0; i < odd.size(); ++i)
    {
        visited = vector<bool>(odd.size(), false);
        visited[0] = true;
        if(dfs(i, odd, even)) ++size;
    }
    return size;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> even, odd;
    char c = 'B';
    int first;
    cin >> first;
    if(first % 2 == 1)
    {
        odd.push_back(first);
        c = 'A';
    }
    else even.push_back(first);

    for(int i = 1; i < N; ++i)
    {
        int temp;
        cin >> temp;

        if(temp % 2 == 0)
            even.push_back(temp);
        else
            odd.push_back(temp);
    }
    if(c == 'B') odd.swap(even);
    makeEdge(even, odd);

    vector<int> result;
    for(int i = 0; i < even.size(); ++i)
    {
        if(adj[0][i] == 1)
        {
            one = 0; two = i;
            if(bipartitematch(odd, even) == (N / 2 - 1))
                result.push_back(even[i]);
        }
    }

    sort(result.begin(), result.end());

    for(auto& e : result)
        cout << e << " ";
    
    if(result.size() == 0)
        cout << "-1" << endl;

}