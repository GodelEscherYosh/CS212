
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct {
    int num_items;
    int front;
    int back;
    char strings[QUEUE_SIZE][80];
} Queue;

Queue* InitializeQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->back = 0;
    q->num_items = 0;

    return q;
}

void Enqueue(Queue* queue, const char* item) {
    if (queue->num_items == QUEUE_SIZE) {
        printf("Queue is Full!\n");
    }
    else {
        strcpy(queue->strings[queue->back], item);
        queue->back = (queue->back + 1) % QUEUE_SIZE;
        queue->num_items++;
    }

}

char* Dequeue(Queue* queue) {
    if (queue->num_items == 0) {
        printf("Queue is Empty!\n");
        return NULL;
    } else {
        char *str = (char *)malloc(sizeof(queue->strings[queue->front]));
        strcpy(str, queue->strings[queue->front]);
        strcpy(queue->strings[queue->front], "");
        queue->front = (queue->front + 1) % QUEUE_SIZE;
        queue->num_items--;
        return str;
    }
}

int sudoPeak(Queue* queue) {
    if (queue->num_items == 0) {
        return 0;
    } else {
        return 1;
    }
}

void
PrintQueue(Queue *q)
{
    int i;
    printf("Printing queue %p\n", q);
    printf("\tThe index for the front of the queue is %d\n", q->front);
    printf("\tThe index for the back of the queue is %d\n", q->back);
    if (q->front == q->back)
    {
        printf("\tThe queue is empty.\n");
        return;
    }
    int back = q->back;
    if (q->back < q->front)
    {
        // wrapped around, so modify indexing
        back += QUEUE_SIZE;
    }

    for (i = q->front ; i < back ; i++)
    {
        printf("\t\tEntry[%d] = \"%s\"\n", i%QUEUE_SIZE, q->strings[i%QUEUE_SIZE]);
    }
}

void PrettyPrintQueue(Queue *q, char *type) {
    if (q->front == q->back) {
        printf("No unmatched entries for %s\n", type);
    } else {
        printf("Unmatched %s:\n", type);
        while (q->num_items > 0) {
            char *s = Dequeue(q);
            printf("%s\n", s);
        }
    }
}

char *NewString(char *s)
{
    int len = strlen(s);
    char *rv = malloc(len+1);
    strcpy(rv, s);
    rv[len-1] = '\0'; /* take out newline */
    return rv;
}

char *StringToName(char *s, int skip) {
    int len = strlen(s);
    char *rv = malloc(len - skip + 1);  // Include space for the null terminator
    strcpy(rv, s + skip);  // Copy the string starting from the third character
    return rv;
}


int main(int argc, char **argv)
{
    FILE* file = fopen(argv[1], "r");

    Queue *female_donors = (Queue *)malloc(sizeof(Queue));
    Queue *female_recipients = (Queue *)malloc(sizeof(Queue));
    Queue *male_donors = (Queue *)malloc(sizeof(Queue));
    Queue *male_recipients = (Queue *)malloc(sizeof(Queue));
    Queue *hospitals = (Queue *)malloc(sizeof(Queue));

    female_donors = InitializeQueue();
    female_recipients = InitializeQueue();
    male_donors = InitializeQueue();
    male_recipients = InitializeQueue();
    hospitals = InitializeQueue();

    char line[80];
    while (fgets(line, sizeof(line), file)) {
        char* event = NewString(line);
        if (event[0] == 'H'){
            char *name = StringToName(event, 2);
            Enqueue(hospitals, name);
        }else if (event[0] == 'R'){
            char *name = StringToName(event, 4);
            if(event[2] == 'F'){
                Enqueue(female_recipients, name);
            }
            else if(event[2] == 'M'){
                Enqueue(male_recipients, name);
            }
        }else if(event[0] == 'D'){
            char *name = StringToName(event, 4);
            if(event[2] == 'F'){
                Enqueue(female_donors, name);
            }
            else if(event[2] == 'M'){
                Enqueue(male_donors, name);
            }
        }

        // Now we need to check if something is in two complentary sets.
        //Female First
        if((sudoPeak(female_donors) == 1) &&(sudoPeak(female_recipients) == 1) && (sudoPeak(hospitals) == 1)){
            char *femD = Dequeue(female_donors);
            char *femR = Dequeue(female_recipients);
            char *hosp = Dequeue(hospitals);
            printf("MATCH: %s donates to %s at hospital %s\n", femD, femR, hosp);
        }
        if((sudoPeak(male_donors) == 1) &&(sudoPeak(male_recipients) == 1) && (sudoPeak(hospitals) == 1)){
            char *maleD = Dequeue(male_donors);
            char *maleR = Dequeue(male_recipients);
            char *hosm = Dequeue(hospitals);
            printf("MATCH: %s donates to %s at hospital %s\n", maleD, maleR, hosm);
        }

        free(event);
    }
    // Print the contents of queues at the end using PrintQueue
    PrettyPrintQueue(female_donors, "female donors");
    PrettyPrintQueue(female_recipients, "female recipients");
    PrettyPrintQueue(male_donors, "male donors");
    PrettyPrintQueue(male_recipients, "male recipients");
    PrettyPrintQueue(hospitals, "hospitals");

    fclose(file);

    return 0;
}


