#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void removeList(Node *pre) {
  Node *temp;       //새 node를 생성하는 것이 아님, malloc 필요없
  temp = pre->next; // temp가 제거할 node를 가르킴
  pre->next = temp->next; //제거할 것의 next가 pre의 next로
  free(temp);
}

int main() {
  Node *a = (Node *)malloc(sizeof(Node));
  Node *b = (Node *)malloc(sizeof(Node));
  Node *c = (Node *)malloc(sizeof(Node));

  a->data = 1;
  b->data = 2;
  c->data = 3;

  a->next = b;
  b->next = c;
  c->next = NULL;

  removeList(a); // b를 제거하려면 a를 전달해줘야함

  while (a != NULL) {
    printf("%d ", a->data);
    a = a->next;
  }
}