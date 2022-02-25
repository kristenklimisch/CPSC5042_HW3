
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std;

// Global variables
pthread_mutex_t mutex;
int j = 0;

void* threadfunc(void * arg)
{
   int val = *(int *) arg;
    pthread_mutex_lock(&mutex);

    //critical section
    j += val;

    sleep(1);

   pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_init(&mutex, NULL);

    int n;
    cout << "Please enter the number of threads you want to create: ";
    cin >> n;

    pthread_t thread_id[n];
    int val=1;

    for (int i = 0; i <= n-1; i++ ) {
        pthread_create(&thread_id[i], NULL, threadfunc, &val);
    }

    for (int i = 0; i <= n-1; i++){
        pthread_join(thread_id[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("J is %d\n", j);

    return 0;
}
