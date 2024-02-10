// #include<stdio.h>

// #include<bits/stdc++.h>
// void * maximum(void * args) {
//   // Your code here
//   struct Classroom*classroom=(struct Classroom *)args;
//   int max=classroom->grades[0];
//   for(int i=1;i<classroom->n;i++){
//       if(classroom->grades[i]>max){
//           max=classroom->grades[i];
//       }
//   }
// return (void*)(__intptr_t)max;
// }
// void * second_maximum(void * args) {
//   // Your code here
//   struct Classroom*classroom=(struct Classroom *)args;
//   int max=classroom->grades[0];
//   int second_max=classroom->grades[0];
//   for(int i=1;i<classroom->n;i++)
//   {
//       if(classroom->grades[i]>max)
//       {
//           second_max=max;
//           max=classroom->grades[i];
//       } 
//       else if
//           (classroom->grades[i]>second_max&&classroom->grades[i]<max)
//           {
//       second_max=classroom->grades[i];
//       }
//   }
//   return (void*)(__intptr_t)second_max;
// }

// void * Find_Xor(void * args) 
// {
//   // Your code here   
//   struct Classroom *classroom =(struct Classroom *)args;
//   int xor_result =classroom->grades[0];
//   for(int i=1;i<classroom->n;i++)
//   {
//       xor_result^=classroom->grades[i];
      
//   } 
//   return (void*)(__intptr_t)xor_result;
// }


// int main(){
// int i;
// struct Classroom obj; scanf("%d", & obj.n); for (i = 0; i < obj.n; i++) { scanf("%d", & obj.grades[i]);
// }
// pthread_t thread1, thread2, thread3;
// pthread_create( & thread1, NULL, second_maximum, (void *) & obj); pthread_create( & thread2, NULL, maximum, (void*) & obj);
// pthread_create( & thread3, NULL, Find_Xor, (void *) & obj);
// int * secondmax = NULL, max = NULL, * Xor = NULL;
// pthread_join(thread1, (void *) & secondmax); pthread_join(thread2, (void *) & max); pthread_join(thread3, (void *) & Xor);
// printf("%d ", max);
// printf("%d ", secondmax);
// printf("%d", Xor);
// return 0;
// }