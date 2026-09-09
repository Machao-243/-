typedef struct {
    int* stk;
    int stkSize;
    int stkCapacity;
} Stack;

Stack* stackCreate(int capacity){
    Stack* ret = malloc(sizeof(Stack));
    ret -> stk = malloc(sizeof(int) * capacity);
    ret -> stkSize = 0;
    ret -> stkCapacity = capacity;
    return ret;
}

void stackPush(Stack* obj, int x){
    obj -> stk[(obj -> stkSize)++] = x;
}

void stackPop(Stack* obj){
    obj -> stkSize--;
}

int stackTop(Stack* obj){
    return obj -> stk[obj -> stkSize - 1];
}

bool stackEmpty(Stack* obj){
    return obj -> stkSize == 0;
}

void stackFree(Stack* obj){
    free(obj -> stk);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret -> inStack = stackCreate(100);
    ret -> outStack = stackCreate(100);
    return ret;
}

void in2out(MyQueue* obj){
    while(!stackEmpty(obj -> inStack)){
        stackPush(obj -> outStack, stackTop(obj -> inStack));
        stackPop(obj -> inStack);
    }
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj -> inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if(stackEmpty(obj -> outStack)){
        in2out(obj);
    }
    int x = stackTop(obj -> outStack);
    stackPop(obj -> outStack);
    return x;
}

int myQueuePeek(MyQueue* obj) {
    if(stackEmpty(obj -> outStack)){
        in2out(obj);
    }
    return stackTop(obj -> outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj -> inStack) && stackEmpty(obj -> outStack);
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj -> inStack);
    stackFree(obj -> outStack);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/