#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct Stack {
    Node* top;
} Stack;

// Função para inicializar a pilha
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Função para empilhar um caractere na pilha
void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Função para desempilhar um caractere da pilha
char pop(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Função para verificar se os caracteres de abertura têm os correspondentes fechamentos
int isMatchingPair(char char1, char char2) {
    return (char1 == '[' && char2 == ']') || (char1 == '(' && char2 == ')') || (char1 == '{' && char2 == '}');
}

// Função para verificar se a expressão está balanceada
int isBalanced(char* expression) {
    Stack stack;
    initializeStack(&stack);

    while (*expression) {
        if (*expression == '[' || *expression == '(' || *expression == '{') {
            push(&stack, *expression);
        } else if (*expression == ']' || *expression == ')' || *expression == '}') {
            if (stack.top == NULL || !isMatchingPair(pop(&stack), *expression)) {
                return 0; // Não está balanceado
            }
        }

        expression++;
    }

    // A expressão está balanceada se a pilha estiver vazia no final
    return stack.top == NULL;
}

int main() {
    FILE* file = fopen("codigo_fonte.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    char code[10000];  // Assumindo que o código não excede 10000 caracteres
    char* current = code;

    while (fgets(current, sizeof(code) - (current - code), file)) {
        current += strlen(current);
    }

    if (isBalanced(code)) {
        printf("sucess\n");
    } else {
        printf("fail\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}
