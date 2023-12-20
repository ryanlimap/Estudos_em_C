//Cria uma fila e inicializa os campos
Queue create() {
    Queue novafila = (Queue*)malloc(sizeof(Queue));

    novafila->front = NULL;
    novafila->rear = NULL;

    return novafila;
}

//Recebe uma fila como parâmetro e retorna o id da próxima tarefa a ser executada 
int next_task(Queue *task_queue) {
    if(!task_queue->front == NULL) {        
        int prox_id = task_queue->front->task->id;
    }
    else {
        int prox_id = -1;
    }

    return prox_id;
}

//recebe uma fila e uma descrição de tarefa como parâmetros, e insere a tarefa no final da fila. 
void add_task(Queue *task_queue, const char* desc) {
    QueueNode novatarefa = (QueueNode)malloc(sizeof(QueueNode));
    novatarefa->next = NULL;
    novatarefa->task = (Task*)malloc(sizeof(Task));
    strcpy(novatarefa->task->desc, desc);

    if(!task_queue == NULL) {
        novatarefa->task->id = task_queue->rear->task->id + 1;
        task_queue->rear->next = novatarefa;
    }
    else {
        novatarefa->task->id = 1;
        task_queue->front = novatarefa;
    }

    task_queue->rear = novatarefa;
}