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

void AddEdge(ALGraph* G, int i, int j)
{
    ArcNode* newArc = (ArcNode*)malloc(sizeof(ArcNode));
    newArc->adjvex = j;
    if (G->vertices[i].firstNode == NULL || G->vertices[i].firstNode->adjvex > j)
    {
        newArc->next = G->vertices[i].firstNode;
        G->vertices[i].firstNode = newArc;
        return;
    }
    else
    {
        ArcNode* p = G->vertices[i].firstNode;
        while (p->next && p->next->adjvex < j)
        {
            p = p->next;
        }
        newArc->next = p->next;
        p->next = newArc;
    }
}

//头插法创建邻接表
void CreatAlgraph(ALGraph* G)
{
    ArcNode* p;
    int m, n;
    scanf("%d %d", &G->vernum, &G->arcnum);
    
    for (size_t i = 0; i < G->vernum; i++)
    {
        G->vertices[i].firstNode = NULL;
    }

    for (size_t i = 0; i < G->arcnum; i++)
    {
        scanf("%d %d", &m, &n);
        AddEdge(G, m, n);
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
/*
BFS实现:
使用队列实现
创建队列，将起始节点入队
标记起始节点为已访问
队列不为空时，出队一个节点，输出节点
将该节点的所有邻接节点入队
*/
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
    BFS(&G, 1, visited2);
    return 0;
}
