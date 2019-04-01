//Huffman Codes (Don't Use)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n=0;
struct node
{
  struct node *lchild;
  char data[3];
  int freq;
  struct node *rchild;
};
void min_heapify(struct node a[],int i)
{
  int l,r,smallest;
  l=2*i;
  r=2*i+1;
  if((l<=n)&&(a[l].freq<a[i].freq))
    smallest=l;
  else
    smallest=i;
  if((r<=n)&&(a[r].freq<a[smallest].freq))
    smallest=r;
    if(smallest!=i)
    {
      struct node temp;
      temp=a[i];
      a[i]=a[smallest];
      a[smallest]=temp;
      min_heapify(a,smallest);
    }
}
void build_heap(struct node a[])
{
  int i;
  for(i=n/2;i>=1;--i)
  {
    min_heapify(a,i);
  }
}
void insert_heap(struct node a[],struct node *new)
{
  int i;
  n+=1;
  a[n]=*new;
  i=n;
  while((i>1)&&(a[i/2].freq>a[i].freq))
  {
      struct node temp;
      temp=a[i];
      a[i]=a[i/2];
      a[i/2]=temp;
      i/=2;
  }
}
void extract_min(struct node a[],struct node **new)
{
  if(n<1)
  {
    return NULL;
  }
  strcpy((*new)->data,a[1].data);
  (*new)->freq=a[1].freq;
  (*new)->lchild=a[1].lchild;
  (*new)->rchild=a[1].rchild;
  a[1]=a[n];
  n-=1;
  min_heapify(a,1);
}
void printCodes(struct node *root, int arr[], int index)
{
  if(root->lchild!=NULL)
  {
    arr[index]=0;
    printCodes(root->lchild,arr,index+1);
  }
  if (root->rchild!=NULL)
  {
    arr[index]=1;
    printCodes(root->rchild,arr,index+1);
  }
  if ((root->lchild==NULL)&&(root->rchild== NULL))
  {
    printf("%s: ",root->data);
    int i;
    for (i=0;i<index;++i)
      printf("%d",arr[i]);
    printf("\n");
    return;
  }
}
void hmc(struct node a[])
{
  int i=1,j;
  build_heap(a);
  while(n>1)
  {
    struct node *p1,*p2;
    p1=(struct node *)malloc(sizeof(struct node));
    p2=(struct node *)malloc(sizeof(struct node));
    extract_min(a,&p1);
    extract_min(a,&p2);
    struct node *curr=(struct node *)malloc(sizeof(struct node));
    curr->lchild=p1;
    curr->rchild=p2;
    curr->freq=p1->freq+p2->freq;
    sprintf(curr->data,"N%d",i);
    insert_heap(a,curr);
    ++i;

  }
  int arr[100];
  printCodes(&a[1],arr,0);
}
int main()
{
  int i;
  printf("\nEnter the no. of nodes:");
  scanf("%d",&n);
  struct node a[n+1];
  for(i=1;i<=n;++i)
  {
    printf("\nEnter the data and frequency:");
    scanf("%s%d",a[i].data,&a[i].freq);
    a[i].lchild=NULL;
    a[i].rchild=NULL;
  }
  hmc(a);
  return 0;
}
