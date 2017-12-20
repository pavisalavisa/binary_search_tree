#include <stdio.h>
#include <stdlib.h>
#define RESULT_OK 0
//rad s binarnim stablom pretrazivanja
//unos novog elementa u stablo, ispis elemenata, brisanje, pronalazenje

struct _treeNode;
typedef struct _treeNode* Position;
typedef struct _treeNode{
    int el;
    int nCounter;
    Position left;
    Position right;
}_TREENODE;

Position createTreeNode();
int insertNode(Position,int);
int printTreeInOrder(Position);
Position findMax(Position);
Position findMin(Position);
Position findElement(Position,int);
Position deleteNode(Position,int);
Position deleteNodev2(Position,int);

int main(int argc,char** argv)
{
    Position root=NULL;//ne treba nam head
    return RESULT_OK;
}

Position createTreeNode()
{
    Position q=NULL;
    q=(Position)malloc(sizeof(_TREENODE));
    if(q==NULL)return NULL;
    q->nCounter=1;
    q->left=NULL;
    q->right=NULL;
    return q;
}

int insertNode(Position q,int x)
{
    //insert refresha sve pokazivace od roota do mjesta di stavljamo novi element
    if(q==NULL){
        q=createTreeNode();
        q->el=x;
    }
    else if(x>q->el)
        q->right=insertNode(q->right,x);
    else if(x<q->el)
        q->left=insertNode(q->left,x);
    else
        q->nCounter++;
    return q;
}

int printTreeInOrder(Position t)
{
    if(t==NULL)return RESULT_OK;
    printTree(t->left);
    printf("\n%d",t->el);
    printTree(t->right);
    return RESULT_OK;
}

Position findMax(Position t)
{
    while(t->right!=NULL)
        t=t->right;
    return t;
}
Position findMin(Position t)
{
    while(t->left!=NULL)
        t=t->left;
    return t;
}

Position findElement(Position t,int x)
{
    if(t==NULL)return t;
    else if(x<t->el)
        return findElement(t->left,x);
    else if(x>t->el)
        return find(t->right,x);
    else
        return t;
}

Position deleteNode(Position t,int x)
{
    Position tmp=NULL;
    if(t==NULL)return t;
    else if(x<t->el)
        t->left=deleteNode(t->left,x);
    else if(x>t->el)
        t->right=deleteNode(t->right,x);
    else{
        if(t->left==NULL&&t->right==NULL)
        {
            free(t);
            t=NULL;
        }
        else if(t->left==NULL)
        {
            tmp=t;
            t=t->left;
            free(tmp);
        }
        else if(t->right==NULL)
        {
            tmp=t;
            t=t->right;
            free(tmp);
        }
        else if(t->left!=NULL&&t->right!=NULL)
        {
            tmp=findMin(t->right);
            t->el=tmp->el;
            t->right=deleteNode(t->right,t->el);
        }
        return t;
    }
}

Position deleteNodev2(Position t,int x)
{
    Position tmp=NULL;
    if(t==NULL)return t;
    else if(x<t->el)
        t->left=deleteNode(t->left,x);
    else if(x>t->el)
        t->right=deleteNode(t->right,x);
    else{
       if(t->left!=NULL&&t->right!=NULL)
        {
            tmp=findMin(t->right);
            t->el=tmp->el;
            t->right=deleteNode(t->right,t->el);
        }
        else{
            tmp=t;
            if(t->left!=NULL)t=t->left;
            else t=t->right;
            free (tmp);
        }
        return t;
    }
}
