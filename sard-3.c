/*
  PLOVER: BUFF.OVER, RACE, NUM.OBO
 */
/*
  Unprotected string copy, unlocked shared resource
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 5

pthread_mutex_t mut  = PTHREAD_MUTEX_INITIALIZER;


void *foo(void* targ)
{
  char *buffer = ((char **)targ)[0];
  char *str =  ((char **)targ)[1];
  char *str2 =  ((char **)targ)[2];
  
  pthread_mutex_lock(&mut);

  if(strlen(str) < BUFSIZE)
    strcpy(buffer, str);
  else
    pthread_exit(NULL);
  if(strlen(str) + strlen(str2) <= BUFSIZE)	
    strcat(str, str2);
  else
    pthread_exit(NULL);
  printf("results: %s\n", str);  
  pthread_mutex_unlock(&mut);  

  pthread_exit(NULL);
}

void *bar(void* targ)
{
  char **buffer = (char **)targ;

  *buffer = NULL;

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  char buf[BUFSIZE];
  pthread_t tids[3];
  char *tin[3];
  tin[0] = buf;
  if(argc > 2){
    tin[1] = argv[1];
    tin[2] = argv[2];
  }
  else
    return 0;

  int rc = pthread_create(&tids[0], NULL, foo, (void *)tin);
  rc = pthread_create(&tids[1], NULL, bar, (void *)&buf);
  rc = pthread_create(&tids[2], NULL, bar, (void *)&argv[2]);
  pthread_join(tids[0],NULL);
  pthread_join(tids[1],NULL);
  pthread_join(tids[2],NULL);
  printf("final string: %s \n", buf);

  return 0;
}
