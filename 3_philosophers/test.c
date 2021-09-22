#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *p2_function(void *param)
{
	for (int i = 0; i < 20; i++)
	{
		printf("%s : %d\n", (char *)param, i);
		sleep(1);
	}
	printf("t2 end\n");
	return (0);
}

void *p1_function(void *param)
{
	pthread_t p_thread2;
	pthread_create(&p_thread2, NULL, p2_function, "thread2");
	pthread_detach(p_thread2);
	// pthread_join(p_thread2, NULL);

    for (int i = 0; i < 5; i++)
    {
		printf("%s : %d\n", (char *)param, i);
        sleep(1);
    }
	printf("t1 end\n");
	return (0);
}
int main()
{
    pthread_t p_thread1;
	pthread_create(&p_thread1, NULL, p1_function, "thread1");
	pthread_detach(p_thread1);
	// pthread_join(p_thread1, NULL);

	int s = 0;
	while(1)
	{
   		printf("%d초 경과\n", s++);
    	sleep(1);
	}
    return 0;
}
