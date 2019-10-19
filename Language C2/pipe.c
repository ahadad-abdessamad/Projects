#include<stdio.h>
#include<unistd.h>

int main() {
   int p1[2], p2[2];
   int rs1, rs2; //return status
   int pid;
   char p1msg[20] = "Hi";
   char p2msg[20] = "Hello";
   char rd[20]; //read Message
   
   rs1 = pipe(p1);
   rs2 = pipe(p2);
   
   if (rs1 == -1) {
      printf("cannot create pipe 1 \n");
      return 1;
   }
   
   if (rs2 == -1) {
      printf("cannot create pipe 2 \n");
      return 1;
   }
   
   pid = fork();
   
   if (pid != 0) { 
      close(p1[0]); // Close pipe1 read side
      close(p2[1]); // Close pipe2 write side
      printf("p1: Write to pipe 1 : %s\n", p1msg);
      write(p1[1], p1msg, sizeof(p1msg));
      read(p2[0], rd, sizeof(rd));
      printf("p1: Read from pipe 2 : %s\n", rd);
   } else {
      close(p1[1]); 
      close(p2[0]); 
      read(p1[0], rd, sizeof(rd));
      printf("p2: Read from pipe 1 : %s\n", rd);
      printf("p2: Write to pipe 2  : %s\n", p2msg);
      write(p2[1], p2msg, sizeof(p2msg));
   }
   return 0;
}
