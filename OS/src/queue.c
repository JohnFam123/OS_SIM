#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q->size < MAX_QUEUE_SIZE){
                q->proc[q->size] = proc;
                q->size++;    
        }
}

struct pcb_t * dequeue(struct queue_t * q) {
        struct pcb_t* proc = NULL;
        if (q->size == 0) return proc;
        int min_prio=0;
        int min_prio_index=0;
        for (int i=0; i<q->size; i++) {
                if (q->proc[i]->priority > min_prio) {
                        min_prio = q->proc[i]->priority;
                        min_prio_index = i;
                }
        }
        proc = q->proc[min_prio_index];
#ifdef QDEBUG        
        printf ("current process: %d, prio = %d\n", proc->pid,proc->prio);
#endif
        for (int i=min_prio_index; i<q->size-1; i++) {
                q->proc[i] = q->proc[i+1];
        }
        q->size --;
        return proc;
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
}

