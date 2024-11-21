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


int main()
{
    

    cout<<endl;
    system("pause");
    return 0;
}
