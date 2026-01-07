#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
    public:
    int v;
    list<int> *l;
    
    Graph(int vertices) {
        v = vertices;
        l = new list<int> [v];
    }
    void add(int u, int x)
    {
        l[u].push_back(x);
        l[x].push_front(u);
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout<<i<<":";
        
            for(int neignbor : l[i])
            {
                cout<<neignbor<<" ";
            }
            cout<<endl;
        }
    }
    void bfs()
    {
        queue<int> q;
        vector<bool> visited (v,false);

        q.push(0);
        visited[0]=true;

        while (q.size()>0)
        {
            int u=q.front();
            q.pop();
            cout<<u<<endl;

        }
        
    }
};
int main()
{
    Graph g(5);
    g.add(0,1);
    g.add(1,2);
    g.add(1,3);
    g.add(2,3);
    g.add(2,4);
    // g.print();
    return 0;

}