#include <errno.h> // per controllo errori
#include <stdlib.h>	// EXIT_FAILURE/SUCCESS
#include <signal.h>	// controllo segnale Ctrl+C
#include <string.h>	// strerror & memset

#include <pthread.h> // crea nuovo thread posix
#include <semaphore.h>	// crea semaforo posix

#include <stdio.h> // fprintf

#include "storesimul/storesimul.h"

#define ERROR_HANDLER(error, msg)                               \
            do {                                                    \
                fprintf(stderr, "[%s]: %s", msg, strerror(error));  \
                exit(EXIT_FAILURE);                                 \
            } while (0)

pthread_t               thread;
sem_t                   sem; // semaforo per sbloccare il thread di uscita sicura
sem_t                   cs_sem;	// semaforo per la sezione critica nelle simulazioni (azione atomica)

void sig_handler(int signum) {
    // incrementa il semaforo (sblocca l'altro thread)
    if (sem_post(&sem))
        ERROR_HANDLER(errno, "sem_post");
}

void* thread_run(void* args) {
    simulation_storage_t* storage = (simulation_storage_t*) args;

    if (sem_wait(&sem)) // rimane bloccato qui
        ERROR_HANDLER(errno, "sem_wait");
    
    if (sem_wait(&cs_sem))
        ERROR_HANDLER(errno, "sem_wait");

    // segue codice per salvare...
    store_simulation(storage);

    if (sem_post(&cs_sem))
        ERROR_HANDLER(errno, "sem_post");

    if (sem_destroy(&sem))
        ERROR_HANDLER(errno, "sem_destroy");

    if (sem_destroy(&cs_sem))
        ERROR_HANDLER(errno, "sem_destroy");
    
    exit(EXIT_SUCCESS);
}

void create_simulation_storage(simulation_storage_t* params) {
    struct sigaction        sig_act;

    memset(&sig_act, 0, sizeof(struct sigaction));

    sig_act.sa_handler = sig_handler;

    // block every signal during handler execution
    sigfillset(&sig_act.sa_mask);

    // allaccia al segnale SIGINT (Ctrl+C) l'handler specificato nella struct sig_act
    sigaction(SIGINT, &sig_act, NULL);
    
    // crea il semaforo per sincronizzarsi con il thread separato
    if (sem_init(&sem, 0, 0))
        ERROR_HANDLER(errno, "sem_init");

    // crea il semaforo per la sezione critica della simulazione
    if (sem_init(&cs_sem, 0, 1))
        ERROR_HANDLER(errno, "sem_init");

    // crea thread separato per salvare i dati
    if (pthread_create(&thread, NULL, thread_run, (void*) params))
        ERROR_HANDLER(errno, "pthread_create");
    
    // non interessarti dell'altro thread
    if (pthread_detach(thread))
        ERROR_HANDLER(errno, "pthread_detach");
}

void wait_simulation() {
	if (sem_wait(&cs_sem))
        ERROR_HANDLER(errno, "sem_wait");
}

void post_simulation() {
	if (sem_post(&cs_sem)) // rimane bloccato qui
        ERROR_HANDLER(errno, "sem_post");
}