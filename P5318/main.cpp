#include <iostream>
#include <queue>
#define MaxVexNum 100000
using namespace std;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct 
{
    ArcNode* firstNode;
}VerNode;

typedef struct
{
    VerNode  vertices[MaxVexNum];
    int   vernum, arcnum;
}ALGraph;


void CreatAlgraph(ALGraph* G)
{
    ArcNode* p;

    scanf("%d %d", &G->vernum, &G->arcnum);
    
    for (size_t i = 0; i < G->vernum; i++)
    {
        G->vertices[i].firstNode = NULL;
    }

    for (size_t i = 0; i < G->arcnum; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = n;
        p->next = G->vertices[m].firstNode;
        G->vertices[m].firstNode = p;
    }
    
}
/*
DFS实现:
层层递进，递归实现
将访问过的节点标记为已访问
输出节点
递进到下一个节点
*/
void DFS(ALGraph* G, int start, bool visited[])
{
    ArcNode* p;
    visited[start] = true;
    cout<<start<<" ";
    p = G->vertices[start].firstNode;
    while (p)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visited);
        }
        p = p->next;
    }
}

void BFS(ALGraph* G, int start, bool visited[])
{
    queue<int> q;
    visited[start] = true;    
    q.push(start);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        ArcNode* p = G->vertices[v].firstNode;
        while (p)
        {
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = true;
                q.push(p->adjvex);
            }
            p = p->next;
        }
    }
}

int main()
{
    bool visited1[MaxVexNum + 1] = {false};
    ALGraph G;
    CreatAlgraph(&G);
    DFS(&G, 1, visited1);
    cout << endl;
    bool visited2[MaxVexNum + 1] = {false};
    DFS(&G, 1, visited2);
    return 0;
}
