typedef int KeyType;
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

void Merge(RecType R[],int low,int mid,int high) //�鲢R[low..high];
{

    RecType *R1;
    int i=low,j=mid +1,k=0;
    R1=(RecType *)malloc((high-low-1)*sizeof(RecType));
    while(i<=mid &&j<=high)
    {
        if(R[i].key <= R[j].key)
        {
            R1[k] = R[i];
            i++;
            k++;
        }else
        {
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        R1[k] = R[j];
        i++;
        k++;
    }
    while(j<=high)
    {
        R1[k] =R[j];
        j++;
        k++;
    }
    for(k=0,i=low;i<=high;k++,i++)
    {
        R[i] = R1[k];
    }
    free(R1);
}

void main()
{
    printf("helloworld");
}
