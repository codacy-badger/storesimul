#ifndef _ATOMIC_H_
#define _ATOMIC_H_

int sem_init(int value);

int sem_wait(int sem_fd);

int sem_post(int sem_fd);

int sem_destroy(int sem_fd);

#endif /* _ATOMIC_H_ */