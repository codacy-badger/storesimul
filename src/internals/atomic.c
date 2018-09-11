#include "storesimul/internals/atomic.h"

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int sem_init(int value) {
	long sem_fd = semget(IPC_PRIVATE, 1, IPC_CREAT | 0660);
	if (sem_fd == -1)
		return -1;
	if (semctl(sem_fd, 0, SETVAL, value) == -1)
		return -1;
	return sem_fd;
}

int sem_wait(int sem_fd) {
	struct sembuf op = {0, -1, 0};
	return semop(sem_fd, &op, 1);
}

int sem_post(int sem_fd) {
	struct sembuf op = {0, +1, 0};
	return semop(sem_fd, &op, 1);
}

int sem_destroy(int sem_fd) {
	return semctl(sem_fd, 0, IPC_RMID, 1);
}