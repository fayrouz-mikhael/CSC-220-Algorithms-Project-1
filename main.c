

#include <stdio.h>
#include <stdlib.h>

struct listnode {
    struct listnode * next;
    long key;
} ;

int length(struct listnode * list){ // the length of the list
    int count = 0;
    while(list != NULL){
        count ++ ;
        list= list->next;
    }
    return count;
}

struct listnode *Pivot(struct listnode *list) // choose the pivot randomly
{
    if(list == NULL){
    return 0;
  }

    int len = length(list);
    struct listnode * pivot = list;
    for(int n=0 ; n<(rand()%len); ++n){
             pivot = pivot -> next;
    
    }
    return pivot;
}

struct listnode *sort(struct listnode *currentList) // the QuickSort function
{
    if(length(currentList)<2){
        return currentList;
    }
    struct listnode * newpivot = Pivot(currentList);
    struct listnode * left = NULL ;
    struct listnode * right = NULL ;
     struct listnode * tmp ;
    struct listnode * tmpLeft ;
    struct listnode * tmpList = NULL ;
    
while(currentList !=NULL){
    tmp = currentList->next;
    
    if(currentList->key != newpivot->key){
        currentList-> next = tmpList;
        tmpList = currentList;
       
}
    currentList = tmp;
}
while(tmpList !=NULL){
    tmp = tmpList->next;
    
    if(tmpList ->key > newpivot->key){
        tmpList-> next = right;
        right = tmpList;
    }
    else {
        tmpList -> next = left;
        left = tmpList;
    }
    tmpList = tmp;
    }
    
    left = sort(left);
    right = sort(right);
    
    
    
    if(left == NULL){
        newpivot -> next = right;
        return newpivot;
    }
    else{
        tmpLeft = left;
        while(tmpLeft->next != NULL){
            tmpLeft = tmpLeft ->next;
        }
        newpivot -> next = right;
        tmpLeft -> next = newpivot;
        return left;
    
    }
        
}



int main(void)
{
  long i;
    struct listnode *node, *tmpnode, *space;
    space =  (struct listnode *) malloc( 500000*sizeof(struct listnode));
    for( i=0; i< 500000; i++ )
    {  (space + i)->key = 2*((17*i)%500000);
        (space + i)->next = space + (i+1);
    }
   (space+499999)->next = NULL;
    node = space;
    printf("\n prepared list, now starting sort\n");
    node = sort(node);
    printf("\n checking sorted list\n");
    for( i=0; i < 500000; i++)
    {  if( node == NULL )
    {  printf("List ended early\n"); exit(0);
    }
        if( node->key != 2*i )
        {  printf("Node contains wrong value\n"); exit(0);
        }
        node = node->next;
    }

    
    printf("Sort successful\n");
    exit(0);

}
