#include <stdio.h>

#define MAXD 10
#define MAXR 10

typedef struct node
{
    char data[MAXD];
    struct node *next;

}NodeType;

void RadixSort(NodeType *p,int r,int d)
{
    NodeType * head[MAXR],*tail[MAXR],*t;
    int k;
    for(int i=0;i<d-1;i++)
    {
        for(int j=0;j<r;j++)
        {
            head[j] = tail[j] = NULL;
        }
        while(p != NULL)
        {
            k = p->data[i] - '0';
            if(head[k] == NULL)
            {
                head[k] = p;
                tail[k] = p;

            }else{
                tail[k] ->next = p;
                tail[k] = p;
            }
            p = p->next;
        }
        p = NULL;
        for(int j =0;j<r;j++)
        {
            if(head[j] != NULL)
            {
                if(p== NULL)
                {
                    p = head[j];
                    t = tail[j];
                }else{
                    t->next = head[j];
                    t= tail[j];
                }
            }
        }
        t ->next = NULL;
    }
}
void main()
{

    printf("hello world");
}
