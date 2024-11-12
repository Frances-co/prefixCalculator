#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    double num;
    struct node* next;
} stackNode;

int isOperator(char x);
double substringToDouble(char* start, char* end);
double pop(stackNode** top);
stackNode* push(double x, stackNode** top);
double doOperation(char operatorr, double operand1, double operand2);
void instructions();

int main()
{
    int expressionSize;
    instructions();

    printf("Enter you expression size: ");
    scanf("%d", &expressionSize);
    char expression[expressionSize+1];
    getchar();
    printf("Enter the prefix expression:\n");
    for(int i=0; i<expressionSize; i++){
        scanf("%c", &expression[i]);
    }
    expression[expressionSize]= '\0';
    stackNode* top= NULL;
    double operand1;
    double operand2;
    double result= 0;
    int spaceIndex=-1;

    for(int i=expressionSize-1; i>=0;){
        //printf("%d\n", i);
        switch(expression[i]){
            case '-':
            case '+':
            case '/':
            case '*':
                operand1= pop(&top);
                operand2= pop(&top);
                result= doOperation(expression[i], operand1, operand2);
                //printf("%f,,%f##%f##\n",operand1, operand2, result);
                push(result, &top);
                spaceIndex=i-1;
                i-=2;
                break;

            default:
                if(expression[i]==' '){
                    if(spaceIndex==-1){
                        top= push(substringToDouble(expression+i+1, expression+expressionSize-1),&top);
                    }
                    else{
                        top= push(substringToDouble(expression+i+1, expression+spaceIndex-1), &top);
                    }
                    spaceIndex=i;
                }
                i-=1;
        }
    }
    printf("%f", result);
    return 0;
}

void instructions() {
    printf("Enter the size of the expression, including all spaces and operands, followed by the expression itself.\n");
    printf("Ensure each number is separated from operators by a single space.\nExample:\n+ - 2 7 * 8 / 4 12\n");
    printf("------------------------------------------------------\n");
}

double doOperation(char operatorr, double operand1, double operand2) {
    switch (operatorr) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
    }
}

stackNode* push(double x, stackNode** top) {
    stackNode* newTop = (stackNode*)malloc(sizeof(stackNode));
    newTop->num = x;
    newTop->next = *top;
    *top = newTop;
    return *top;
}

double pop(stackNode** top) {
    double popMe = (*top)->num;
    stackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popMe;
}

double substringToDouble(char* start, char* end) {
    size_t length = end+1 - start;
    char temp[length + 1];
    strncpy(temp, start, length);
    temp[length] = '\0';
    return strtod(temp, NULL);
}

int isOperator(char x) {
    return (x == '-' || x == '+' || x == '/' || x == '*') ? 1 : 0;
}

//Example:+ – 2 7 * 8 / 4 12 (size: 19), + - 9 2 6 (size: 9) 6 2 9 - +
