%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
struct node
{
  int value;
  struct node *left;
  struct node *right;
};
%}
%token NUMBER
%%

S:E {}
;

E: E '+' T  {
              struct node* tempNode;
              tempNode = malloc(sizeof(struct node*));
              tempNode->left = $1;
              tempNode->right = $3;
              $$ = tempNode;
              printf("Address: %p Value: + Left: %p Right: %p\n", tempNode, tempNode->left, tempNode->right);
            }
  |T        {}
  ;

T: T '*' F  {
              struct node* tempNode;
              tempNode = malloc(sizeof(struct node*));
              tempNode->left = $1;
              tempNode->right = $3;
              $$ = tempNode;
              printf("Address: %p Value: * Left: %p Right: %p\n", tempNode, tempNode->left, tempNode->right);
            }
  |F        {}
  ;

F: NUMBER {
            struct node* start;
            start = malloc(sizeof(struct node*));
            start->value = $1;
            start->left = start->right = NULL;
            $$ = start;
            printf("Address: %p Value: %d Left: %p Right: %p\n", start, start->value, start->left, start->right);
          }
  ;

%%
int main()
{
    yyparse();
    //return 0;
}
int yyerror(char *s)
{
    //printf("error:%s",s);
}
int yywrap()
{
  return(1);
}