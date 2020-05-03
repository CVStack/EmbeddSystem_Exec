#include "Server.h"

void insert(Node ** head, Node ** tail, int n) { //tail이 가르키는 곳에 데이터를 삽입

    Node * temp = (Node *) malloc(sizeof(Node));
    temp->ns = n;
    temp->next = NULL;

    if(*head == NULL) { //맨 처음 삽입 하는것이라면, head와 tail을 해당 데이터를 가리키도록 함
        *head = temp; 
    }
    else { //처음 삭제하는것이 아니라면, temp의 다음을 tail의 다음으로 설정한 후 tail의 next를 방금 삽입한 데이터를 가르키도록함
        temp->next = (*tail)->next; //항상 tail에만 넣어서 실질적으론 사용안될듯
        (*tail)->next = temp;
    }

    (*tail) = temp;
} 

void delete(Node ** head, Node ** tail ,int n) { //head부터 해당 데이터를 검색 후 삭제

    Node * before; //전의 Node 포인터를 저장 , 삭제시 전 Node next를 삭제하려는 Node의 next로 이어주기 위해

    for(Node * temp = *head ; temp != NULL ; temp = temp->next) {

        if(temp->ns == n) { //해당 데이터 찾을시

            if(temp == *head) { //해당 데이터가 head일시, head를 다음 노드로 옮겨줌
                *head = (*head)->next;        
            }
            else if(temp == *tail) { //해당 데이터가 tail일시, tail를 전 노드로 옮김
                before->next = NULL;
                *tail = before;
            }
            
            else {
                before->next = temp->next;
            }

            break;
        }
        before = temp;
    }
}


// int main() 
// {

//     Node * head = NULL;
//     Node * tail = NULL;

//     for(int x = 0 ; x < 10 ; x++) {
//         insert(&head,&tail,x);
//     }

//     for(Node * temp = head ; temp != NULL; temp = temp->next) {
//         printf("%d ", temp->ns);
//     }

//     for(int x = 0 ; x < 10 ; x++) {
//         if(x % 2)
//             delete(&head,&tail,x);
//     }

//     printf("\n");
//     for(Node * temp = head ; temp != NULL; temp = temp->next) {
//         printf("%d ", temp->ns);
//     }
// }