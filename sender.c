#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
/*
int shmget (key_t key, int size, int flag);
Где key_t - уникальный ключ сегмента памяти
    size - размер сегмента
    
    shmdt() - обращение к процедуре
    shmat() - получения адреса разделяемой памяти
    IPC_CREAT - создать объект, если он не существует;
    0666 - все могут читать и писать
*/
int main() 
{ 
    key_t key = ftok("MIUS",65); 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    char *str = (char*) shmat(shmid,(void*)0,0); 
    printf("%s", "Записываемая строка : \n"); 
    gets(str); 
    printf("Данные записаны в память: %s\n",str); 
    shmdt(str); 
  
    return 0; 
} 
