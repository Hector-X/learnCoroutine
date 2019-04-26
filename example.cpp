//这条能解决MacOS废弃ucontext的问题
#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <ucontext.h>
#include <unistd.h>
 
int main(int argc, const char *argv[]){
    ucontext_t context;
 
    getcontext(&context);
    puts("Hello world");
    sleep(1);
    setcontext(&context);
    return 0;
}

//这里网上的blog是有点误解的，只看到几条是因为他们终端了执行，真正情况下main函数不会退出，
//会反复执行hello world直到退出。