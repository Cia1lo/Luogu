#include <iostream>
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

int main()
{
    

    cout<<endl;
    system("pause");
    return 0;
}
