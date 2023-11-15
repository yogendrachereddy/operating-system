 #include<stdio.h>
 #include<stdlib.h>
 #include<pthread.h>
 void*printhello(void*arg){
 	printf("hello from thread1!\n");
 	pthread_exit(NULL);
 }
 void*printworld(void*arg){
 	printf("world from thread2!\n");
 	pthread_exit(NULL);
 }
 int main(){
 pthread_t thread1,thread2;
 if(pthread_create(&thread1,NULL,printhello,NULL)!=0){
 	perror("pthread_create");
 	exit(EXIT_FAILURE);
 }
 if(pthread_create(&thread2,NULL,printworld,NULL)!=0){
 	perror("pthread_create");
 	exit(EXIT_FAILURE);
 }
 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);
 printf("both threads have completed their tasks.\n");
 return 0;
}
