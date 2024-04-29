#include"btree.h"
int main()
{
  int ch;
  Node *root=NULL;
  do{
     printf("\n1-create\n2-insert\n3-inorder");
     printf("\nEnter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:root=create(root);
               break;
        case 2:root=insert(root);
               break;       
        case 3:inorder(root);
               break;
     }
  }while(ch<4);
}
