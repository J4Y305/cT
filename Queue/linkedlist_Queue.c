#include <stdio.h>
#include <malloc.h>

typedef char element; // 연결 큐 원소(element)의 자료형 char로 정의
typedef struct QNode{ // 연결 큐의 노드를 구조체로 정의
    element data;
    struct QNode *link;
} QNode;

typedef struct{ // 연결 큐에서 사용하는 포인터 front, rear를 구조체로 정의
    QNode *front, *rear;
} LQueueType;

// 공백 연결 큐를 생성하는 연산
LQueueType *createLinkedQueue(){
    LQueueType *LQ;
    LQ=(LQueueType *)malloc(sizeof(LQueueType));
    LQ->front=NULL;
    LQ->rear=NULL;
    return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isEmpty(LQueueType *LQ){
    if(LQ->front==NULL){
        printf("연결 큐가 공백 상태입니다!");
        return 1;
    }
    else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(LQueueType *LQ, element item){
    QNode *newNode= (QNode *)malloc(sizeof(QNode));
    newNode->data=item;
    newNode->link=NULL;
    if(LQ->front==NULL){
        LQ->front=newNode;
        LQ->rear=newNode;
    }
    else{
        LQ->rear->link=newNode;
        LQ->rear=newNode;
    }
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deQueue(LQueueType *LQ){
    QNode *old=LQ->front;
    element item;
    if(isEmpty(LQ)) return 0;
    else{
        item=old->data;
        LQ->front=LQ->front->link;
        if(LQ->front==NULL)
            LQ->rear=NULL;
        free(old);
        return item;
    }
}

// 연결 큐에서 원소를 검색하는 연산
element peek(LQueueType *LQ){
    element item;
    if(isEmpty(LQ)) return 0;
    else {
        item =LQ->front->data;
        return item;
    }
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType *LQ){
    QNode *temp=LQ->front;
    printf(" Linked Queue : [");
    while(temp){
        printf("%3c", temp->data);
        temp=temp->link;
    }
    printf(" ] ");
}

void main(){
    LQueueType *LQ = createLinkedQueue(); // 연결 큐 생성
    element data;
    printf("\n ***** 연결 큐 연산 ***** \n");
    printf("\n 삽입 A>>"); enQueue(LQ, 'A'); printLQ(LQ);
    printf("\n 삽입 B>>"); enQueue(LQ, 'B'); printLQ(LQ);
    printf("\n 삽입 C>>"); enQueue(LQ, 'C'); printLQ(LQ);
    data=peek(LQ);
    printf(" peek item : %c \n", data);
    printf("\n 삭제 >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t삭제 데이터 : %c", data);
    printf("\n 삭제 >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t\t삭제 데이터 : %c", data);
    printf("\n 삭제 >>"); data=deQueue(LQ); printLQ(LQ);
    printf("\t\t삭제 데이터 : %c", data);
    printf("\n 삽입 D>>"); enQueue(LQ, 'D'); printLQ(LQ);
    printf("\n 삽입 E>>"); enQueue(LQ, 'E'); printLQ(LQ);
    getchar();
}