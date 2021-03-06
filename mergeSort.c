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

void MergePass(RecType R[],int length,int n)
{
    int i;
    for(i=0;i+2*length-1<n;i=i+2*length)
    {
        Merge(R,i,i+length-1,i+2*length-1);
    }
    if(i+length-1 < n-1)
    {
        Merge(R,i,i+length -1,n-1);
    }
}

void MergeSort(RecType R[],int n)
{
    int length;
    for(length =1;length<n;length =2 * length)
    {
        MergePass(R,length,n);
    }
}

void MergeSortDC(RecType R[],int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) /2;
        MergeSortDC(R,low,mid);
        MergeSortDC(R,mid+1,high);
        Merge(R,low,mid,high);
    }
}

void MergeSort1(RecType R[], int n)
{
    MergeSortDC(R,0,n-1);
}

void main()
{
    printf("helloworld");
}
