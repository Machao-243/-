#define LEN 20
typedef struct queue{
    int* data;
    int head;
    int rear;
    int size;
} Queue;

typedef struct {
    Queue *queue1, *queue2;
} MyStack;

// k为队长
Queue* initQueue(int k){
    Queue* obj = (Queue*) malloc(sizeof(Queue));
    obj -> data =(int*) malloc(k * sizeof(int));
    obj -> head = -1;
    obj -> rear = -1;
    obj -> size = k;
    return obj;
}

void enQueue(Queue* obj, int e){
    if(obj -> head == -1){
        obj -> head = 0;
    }
    obj -> rear = (obj -> rear + 1) % obj -> size;
    obj -> data[obj -> rear] = e;
}

int deQueue(Queue* obj){
    int a = obj->data[obj->head];
    if(obj -> head == obj -> rear){
        obj -> head = -1;
        obj -> rear = -1;
        return a;
    }
    obj -> head = (obj -> head + 1) % obj -> size;
    return a;
}

int isEmpty(Queue* obj){
    return obj -> head == -1;
}

int getQueueCnt(Queue* obj){
    if(isEmpty(obj)){
        return 0;
    }
    if(obj -> rear >= obj -> head){
        return obj -> rear - obj -> head + 1;
    }else{
        return obj -> size - (obj -> head - obj -> rear) + 1;
    }
}

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*) malloc(sizeof(MyStack));
    obj -> queue1 = initQueue(LEN);
    obj -> queue2 = initQueue(LEN);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if(isEmpty(obj -> queue1)){
        enQueue(obj -> queue2, x);
    }else{
        enQueue(obj -> queue1, x);
    }
}

int myStackPop(MyStack* obj) {
    if(isEmpty(obj -> queue1)){
        while(getQueueCnt(obj -> queue2) > 1){
            enQueue(obj -> queue1, deQueue(obj -> queue2));
        }
        return deQueue(obj -> queue2);
    }
    while(getQueueCnt(obj -> queue1) > 1){
        enQueue(obj -> queue2, deQueue(obj -> queue1));
    }
    return deQueue(obj -> queue1);
}


int myStackTop(MyStack* obj) {
    int val = 0;
    
    if(isEmpty(obj -> queue1)){
        int cnt = getQueueCnt(obj -> queue2);
        while(cnt > 1){
            enQueue(obj -> queue1, deQueue(obj -> queue2));
            cnt--;
        }
        val = deQueue(obj -> queue2);
        enQueue(obj -> queue1, val);
    }else{
        int cnt = getQueueCnt(obj -> queue1);
        while(cnt > 1){
            enQueue(obj -> queue2, deQueue(obj -> queue1));
            cnt--;
        }
        val = deQueue(obj -> queue1);
        enQueue(obj -> queue2, val);
    }
    return val;
}

bool myStackEmpty(MyStack* obj) {
    if(obj -> queue1 -> head == -1 && obj -> queue2 -> head == -1){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    free(obj->queue1);
    obj->queue1 = NULL;
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    free(obj->queue2);
    obj->queue2 = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/