//Huffman Codes
#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
  struct node *lchild;
  char data;
  int freq;
  struct node *rchild;
};
void min_heapify(struct node a[],int i)
{
  int l,r,smallest;
  struct node temp;
  l=2*i+1;
  r=2*i+2;
  if((a[l].freq<a[i].freq)&&(l<n))
  {
    smallest=l;
  }
  else
  {
    smallest=i;
  }
  if((a[r].freq<a[smallest].freq)&&(r<n))
  {
    smallest=r;
  }
  if(smallest!=i)
  {
    temp=a[i];
    a[i]=a[smallest];
    a[smallest]=temp;
    min_heapify(a,smallest);
  }
}
void build_heap(struct node a[])
{
  int i;
  for(i=(n/2);i>=0;--i)
  {
    min_heapify(a,i);
  }
}
void extract_min(struct node a[],struct node **new)
{
  if(n<1)
  {
    return NULL;
  }
  (*new)->lchild=a[0].lchild;
  (*new)->rchild=a[0].rchild;
  (*new)->data=a[0].data;
  (*new)->freq=a[0].freq;
  a[0]=a[n-1];
  --n;
  min_heapify(a,0);
}
void insert_heap(struct node a[],struct node *new)
{
  int i=n;
  struct node temp;
  a[n]=*new;
  ++n;
  while((i>0)&&(a[i].freq<a[(i-1)/2].freq))
  {
    temp=a[i];
    a[i]=a[(i-1)/2];
    a[(i-1)/2]=temp;
    i=(i-1)/2;
  }
}
void hmc(struct node a[])
{
  build_heap(a);
  while(n>1)
  {
    struct node *p1,*p2,*curr;
    p1=(struct node *)malloc(sizeof(struct node));
    p2=(struct node *)malloc(sizeof(struct node));
    curr=(struct node *)malloc(sizeof(struct node));
    extract_min(a,&p1);
    extract_min(a,&p2);
    curr->data=0;
    curr->freq=p1->freq+p2->freq;
    curr->lchild=p1;
    curr->rchild=p2;
    insert_heap(a,curr);
  }
}
void print_tree(struct node *root,int arr[],int index)
{
  if(root->lchild!=NULL)
  {
    arr[index]=0;
    print_tree(root->lchild,arr,index+1);
  }
  if(root->rchild!=NULL)
  {
    arr[index]=1;
    print_tree(root->rchild,arr,index+1);
  }
  if((root->lchild==NULL)&&(root->rchild==NULL))
  {
    printf("\n%c:",root->data);
    int i;
    for(i=0;i<index;++i)
    {
      printf("%d",arr[i]);
    }
    return;
  }
}
int main()
{
  int i;
  printf("\nEnter the range:");
  scanf("%d",&n);
  struct node a[n];
  for(i=0;i<n;++i)
  {
    printf("\nEnter the data and frequency:");
    scanf(" %c%d",&a[i].data,&a[i].freq);
    a[i].lchild=NULL;
    a[i].rchild=NULL;
  }
  hmc(a);
  int arr[n];
  print_tree(a,arr,0);
  return 0;
}
