#include <iostream>
#include <string.h>

using namespace std;
class toy
{
public:
    toy* left;
    toy* right;
    char name[20];
    int value;
    toy(int x, char* str)
    {
        value = x;
        strcpy(name, str);
        left = nullptr;
        right = nullptr;
    }
    toy()
    {
        value = 0;
        strcpy(name, "\0");
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
    int m, n;
    cin>>m>>n;
    toy* root = new toy();
    toy all[10001];
    for (size_t i = 0; i < m; i++)
    {
        cin>>all[i].value>>all[i].name;
    }
    
    if (all[0])
    {
        /* code */
    }
    
    
    for (size_t i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
    }
    

    cout<<endl;
    system("pause");
    return 0;
}
