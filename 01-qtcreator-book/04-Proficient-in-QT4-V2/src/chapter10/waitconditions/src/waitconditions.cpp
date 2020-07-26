
#include <QtCore>
#include <stdio.h>
#include <stdlib.h>

const int DataSize = 10000;
const int BufferSize = 8192;
int buffer[BufferSize];

QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes = 0;
int rIndex=0;

class Producer : public QThread
{
public:
    void run();
};

void Producer::run()
{
 
    for (int i = 0; i < DataSize; ++i) {
        mutex.lock();
        if (numUsedBytes == BufferSize)
            bufferEmpty.wait(&mutex);
//         mutex.unlock();
        buffer[i % BufferSize] = numUsedBytes;
//         mutex.lock();
        ++numUsedBytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}

class Consumer : public QThread
{
public:
    void run();
};

void Consumer::run()
{
 	forever {
        mutex.lock();
        if (numUsedBytes == 0)
            bufferFull.wait(&mutex);
//         mutex.unlock();
				printf("%ul::[%d]=%d->%d \n", currentThreadId (),rIndex,buffer[rIndex],numUsedBytes);
//         mutex.lock();
				rIndex = (++rIndex)%BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
   	printf("\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
		for (int i = 0; i < BufferSize; ++i) {
			buffer[i	] = -1;				
		}
    Producer producer;
    Consumer consumerA;
		Consumer consumerB;
    producer.start();
    consumerA.start();
    consumerB.start();
    producer.wait();
    consumerA.wait();
		consumerB.wait();
    return 0;
}
