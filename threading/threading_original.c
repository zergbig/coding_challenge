#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define BOOL char 
#define FALSE 0
#define TRUE 1

#define BUFFER_SIZE 10000
char* g_buffer = NULL;
BOOL g_bufferInitialized = FALSE;
pthread_t* g_threads = NULL;
int g_totalThreads = 0;
int g_numRunningThreads = 0;

//TODO: Remove this, pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

void initBuffer()
{
	//TODO: Remove this, pthread_mutex_lock(&buffer_mutex);
	if (FALSE == g_bufferInitialized)
	{
		g_bufferInitialized = TRUE;
		char* initMsg = "Initializing Buffer";
		//TODO: Remove this, printf("%s\n", initMsg);
		FILE* fh = fopen("./buffer.log", "w");
		if (NULL != fh)
		{
			fwrite(initMsg, sizeof(char), strlen(initMsg), fh);
			fclose(fh);
			fh = NULL;
		}
		g_buffer = (char*)malloc(BUFFER_SIZE);
		strcpy(g_buffer, "Start of Data\n");
	}
	//TODO: Remove this, pthread_mutex_unlock(&buffer_mutex);
}

void * threadFunc(void* arg)
{
	pthread_t threadId = pthread_self();
	char msg[64] = {0};
	int bytesWritten = 0;
	int msgLen = 0;
	int myPortionOfBuffer = 0;
	int i = 0;
	
	sprintf(msg, "Thread %ld\n", threadId);
	msgLen = strlen(msg);
	//TODO: Remove this, printf("Starting %s", msg);
	initBuffer();
	myPortionOfBuffer = BUFFER_SIZE / g_totalThreads;
	
	while (i < 5 && (bytesWritten + msgLen) < myPortionOfBuffer)
	{
		//sleep(1);
		//TODO: Remove this, pthread_mutex_lock(&buffer_mutex);
		strcat(g_buffer, msg);
		//TODO: Remove this, pthread_mutex_unlock(&buffer_mutex);
		bytesWritten += msgLen;
		i++;
	}
	
	g_numRunningThreads--;
}

void createAndStartThread(int threadNum)
{
	pthread_t tid;
	pthread_attr_t attr;
	int rc;
	
	// Initialize and start the thread
	rc = pthread_attr_init(&attr);
	if (rc != 0)
	{
		printf("Failed to initialize attr1 for thread number %d\n", threadNum);
		return;
	}
	
	rc = pthread_create(&tid, &attr, &threadFunc, NULL);
	if (rc != 0)
	{
		printf("Failed to create thread for number %d\n", threadNum);
		return;
	}
	g_numRunningThreads++;
}

void createAndStartThreads(int numThreads)
{
	int i = 0;
	g_threads = (pthread_t*)calloc(numThreads, sizeof(pthread_t));
	g_totalThreads = numThreads;
	for (i = 0; i < g_totalThreads; i++)
	{
		createAndStartThread(i);
	}
}

void waitForThreadsToFinish()
{
	int i = 0;
	while (g_numRunningThreads > 0)
	{
		sleep(1);
	}
	
	i = 0;
	while (i < g_totalThreads)
	{
		pthread_join(g_threads[i], NULL);
		i++;
	}
	
	free(g_threads);
}

void main()
{
	createAndStartThreads(3);
	waitForThreadsToFinish();
	
	printf("%sEnd of Data\n", g_buffer);
	free(g_buffer);
}

