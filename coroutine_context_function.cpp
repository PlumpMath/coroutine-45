/**
 *  A simple coroutine test file to help you understand 
 *  how to using basic coroutine funciton:
 *
 *  1 getcontext(ucontext_t * ucp)

 *  2 setcontext(ucontext_t * ucp)
 *  
 *  3 makecontext(ucontext_t * ucp);
 *
 *  4 swapcontext(ucontext_t * oucp, ucontext_t * nucp)
 *
 *  all funciton is a synchronized funciton.
 */
#include <stdio.h>
#include <ucontext.h>
#include <stdlib.h>
#include <unistd.h>

void test_func()
{
	for(int i = 0; i < 1000; i++)
	{
		printf("hello world\n");
	}

	printf("test_func\n");
}


void test_func1()
{
	for(int i = 0; i < 1000; i++)
	{
		printf("Good Morning\n");
	}

	printf("test_func1 end\n");
}

void coroutine_test()
{
    ucontext_t first_context_t, last_context_t;

	char stack[1024 * 1024] = {0};
	getcontext(&first_context_t);
    
	first_context_t.uc_stack.ss_sp = stack;
	first_context_t.uc_stack.ss_size = sizeof(stack);
	first_context_t.uc_link = &last_context_t;

	makecontext(&first_context_t, test_func, 0);

	swapcontext(&last_context_t, &first_context_t);

	printf("coroutine_test\n");

}

void coroutine_test1()
{
	ucontext_t first_context_t, last_context_t;
	char stack[1024*1024] = {0};

	getcontext(&first_context_t);

	first_context_t.uc_stack.ss_sp = stack;
	first_context_t.uc_stack.ss_size = sizeof(stack);
	first_context_t.uc_link = &last_context_t;

	makecontext(&first_context_t, test_func1, 0);
	
	swapcontext(&last_context_t, &first_context_t);

	printf("coroutine_test1\n");
}


int main(int argc, const char * args[])
{
	coroutine_test();

	printf("continue coroutine_test1\n");

	coroutine_test1();


	return 0;
}
