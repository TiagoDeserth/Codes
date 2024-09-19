#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char D;
    struct Node* left;
    struct Node* right;
} Node;

Node* MontaNode(char dat) {
    Node* P = (Node*)malloc(sizeof(Node));
    if (P != NULL) {
        P->D = dat;
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

typedef struct {
    Node* Root;
} expTree;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

Node* constructExpressionTree(char* expression) {
    Node* nodeStack[100]; 
    char operatorStack[100];
    int nodeTop = -1, operatorTop = -1;
    
    if (isOperator(expression[0])) {
        Node* zeroNode = MontaNode('0');
        nodeStack[++nodeTop] = zeroNode;
    }

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == ' ') {
            continue;
        } else if (isdigit(c) || isalpha(c)) {
            Node* newNode = MontaNode(c);
            nodeStack[++nodeTop] = newNode;
        } else if (isOperator(c)) {
            while (operatorTop != -1 && precedence(c) <= precedence(operatorStack[operatorTop])) {
                Node* rightNode = nodeStack[nodeTop--];
                Node* leftNode = nodeStack[nodeTop--];

                Node* newNode = MontaNode(operatorStack[operatorTop--]);
                newNode->left = leftNode;
                newNode->right = rightNode;

                nodeStack[++nodeTop] = newNode;
            }
            operatorStack[++operatorTop] = c;
        } else if (c == '(') {
            operatorStack[++operatorTop] = c;
        } else if (c == ')') {
            while (operatorTop != -1 && operatorStack[operatorTop] != '(') {
                Node* rightNode = nodeStack[nodeTop--];
                Node* leftNode = nodeStack[nodeTop--];

                Node* newNode = MontaNode(operatorStack[operatorTop--]);
                newNode->left = leftNode;
                newNode->right = rightNode;

                nodeStack[++nodeTop] = newNode;
            }
            operatorTop--;
        }
    }

    while (operatorTop != -1) {
        Node* rightNode = nodeStack[nodeTop--];
        Node* leftNode = nodeStack[nodeTop--];

        Node* newNode = MontaNode(operatorStack[operatorTop--]);
        newNode->left = leftNode;
        newNode->right = rightNode;

        nodeStack[++nodeTop] = newNode;
    }

    return nodeStack[nodeTop];
}

void printLevelOrder(Node* P) {
    if (P == NULL) {
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = P;

    int level = 0;

    while (front < rear) {
        int size = rear - front;

        printf("Nivel %d: ", level);

        for (int i = 0; i < size; i++) {
            Node* node = queue[front++];

            if (isOperator(node->D)) {
                printf("%c", node->D);
            } else {
                if (node->D != '0') {
                    printf("%c", node->D);
                }
            }

            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        printf("\n");
        level++;
    }
}

void MontaArvore(expTree* tree, char* expression) {
    tree->Root = constructExpressionTree(expression);
}

void Print(expTree* tree) {
    printLevelOrder(tree->Root);
}

int main() {
    char expression[1000];
    int primeiraLinha = 1;

    while (fgets(expression, 1000, stdin) != NULL) {
        expression[strcspn(expression, "\n")] = 0;

        if (primeiraLinha) {
            primeiraLinha = 0;
        } else {
            printf("\n");
        }

        expTree a;
        a.Root = NULL;
        MontaArvore(&a, expression);
        Print(&a);
    }

    return 0;
}
