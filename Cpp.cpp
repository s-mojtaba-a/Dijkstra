#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkestra(vector<vector<pair<int, int>>> &s,
               int dis[], int v, int n)
{
    // pair<int,int> = {wight , neighbor node}
    // dijkestra from node v
    // n = number of nodes
    fill(dis, dis + n + 1, 1000000000);
    dis[v] = 0;
    // min-heap
    // pair<int,int> = {wight , vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, v});
    // mark boolean array
    bool mark[n + 1] = {0};

    while (!Q.empty())
    {
        pair<int, int> x = Q.top();
        int w = x.first;
        int v = x.second;
        Q.pop();
        if (mark[v])
            continue;
        mark[v] = 1;
        int len = s[v].size();
        for (int i = 0; i < len; i++)
        {
            if (dis[s[v][i].second] > w + s[v][i].first)
            {
                dis[s[v][i].second] = w + s[v][i].first;
                if (!mark[s[v][i].second]) Q.push({dis[s[v][i].second], s[v][i].second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    /* int n,v ;
    cin >> n >> v ;
    vector<vector<pair<int,int>>> s (n+1) ;
    int dis[n+1];
    */
}
