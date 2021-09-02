//
// Created by 赖於领 on 2021/8/31.
//


#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>

using namespace std;

//互斥锁
pthread_mutex_t _mutex;
//条件变量
pthread_cond_t _cond;
//队列
queue<int> _queue;
int i = 0;

void *pthread1_method(void *args) {
    //如果 pthread_create 函数第四个参数传一个 int = 1 的话，这里就可以接收到
    // int*receive_int = reinterpret_cast<int*>(args);
    cout << "pthread1_ start" << endl;

    while (1) {
        sleep(1);
        //1.先加锁
        //2.向 queue 里面放数据
        //3.通知
        //4.解锁
        pthread_mutex_lock(&_mutex);
        _queue.push(i++);
        pthread_cond_signal(&_cond);
        pthread_mutex_unlock(&_mutex);
    }
    cout << "pthread1_ end" << endl;
}

void *pthread2_method(void *args) {
    sleep(5);
    cout << "pthread2_ start" << endl;
    while (1) {
        //1.先加锁
        //2.如果 queue 里面没有数据就堵塞住
        //3.取出并消费 queue 里面的数据
        //4.解锁
        pthread_mutex_lock(&_mutex);
        if (_queue.empty()) {
            pthread_cond_wait(&_cond, &_mutex);
        }
        cout << " i is " << _queue.front() << endl;
        _queue.pop();
        pthread_mutex_unlock(&_mutex);
    }
    cout << "pthread2_ end" << endl;
}

//int main() {
//    cout << "main start" << endl;
//    //初始化互斥锁
//    pthread_mutex_init(&_mutex, NULL);
//    //初始化条件变量
//    pthread_cond_init(&_cond, NULL);
//
//    //线程 id
//    pthread_t tid1;
//    pthread_t tid2;
//
//    //事先创建好的pthread_t类型的参数。成功时tidp指向的内存单元被设置为新创建线程的线程ID。
//    //用于定制各种不同的线程属性。通常直接设为NULL。
//    //回调函数。无回调函数时设为NULL即可。
//    //回调函数的参数。无参数时设为NULL即可。有参数时输入参数的地址。
//    pthread_create(&tid1, NULL, pthread1_method, NULL);
//    pthread_create(&tid2, NULL, pthread2_method, NULL);
//
//    //与主线程分离
//    pthread_detach(tid1);
//    pthread_detach(tid2);
//
//    sleep(10);
//
//    //销毁互斥锁与条件变量
//    pthread_cond_destroy(&_cond);
//    pthread_mutex_destroy(&_mutex);
//
//    cout << "main end" << endl;
//    return 0;
//}
