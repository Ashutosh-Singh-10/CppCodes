#include <stdio.h>

int main() {
  // Go for it!
  // 1  represents Red card and 0 represents Black card
int n;
  scanf("%d", &n);

 /* printf("%s", " Enter a number between 1-6 for shuffling the cards between two decks = ");
  int t; // I took input from user to shuffle the cards in both the decks instead of rolling a dice to get a better trick
  scanf("%d", &t);

  if(t<1 || t>6){
    printf("%s", " Incorrect Input, Please Enter a number between 1-6 ");
  }
  */
  int a[n];
  for(int i = 0; i<n; i++){
  scanf("%d", &a[i]);
    }
  int Red=0, Black = 0;
  
  for(int i = 0; i<n; i++){
    if(a[i] == 1){
      Red++;
    }
    if(a[i] == 0){
      Black++;
    }
  }
  if(Red != Black){
    printf("%d",Black);
    printf("%d",Red);
    printf("%s", "INCORRECT INPUT - Red and Black Cards are not equal ");
  }
int a1[n/2];  // (n+1)th Card go to this if nth card is Red
int a2[n/2];  // (n+1)th Card go to this if nth card is Black
int x,y = 0; 
  for(int i = 0; i<n; i = i + 2){
  if(a[i] == 1){
    a1[x] = a[i+1];
    x++;
  }
    if(a[i] == 0){
      a2[y] = a[i+1];
      y++;
    }
    
  }
  //for(int j = 0; j<n/2 ;j++){
   // printf("%d", a1[j]);
  //}
  
  /*
  int temp[t];
  for(int i = 0; i<t; i++){
    temp[i] = a1[i];
  }
  for(int i = 0; i<t; i++){
    a1[i] = a2[i];
  }
  for(int i = 0; i<t; i++){
    a2[i] = temp[i];
  }
  */
  
  int R2, B2 =0;
  for(int i = 0; i<n/2; i++){
    if(a1[i] == 1){
      R2++;
    }
  }

  for(int i = 0; i<n/2; i++){
    if(a2[i] == 0){
      B2++;
    }
  }
  printf("%s", " \n");
  printf("%s", "Number of red cards = \n"); 
  printf("%d", R2);
  printf("%s", "Number of black cards = \n"); 
  printf("%d", B2 );
  
  
    return 0;
}