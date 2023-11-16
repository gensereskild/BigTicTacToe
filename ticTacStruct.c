#include <stdio.h>
#include <stdbool.h>

char board[3][3];
bool player1Turn = true;

typedef char brett[3][3];

//brett board1 = {{'a','b','v'},{'2'}};
//test1234
typedef struct{
    char board[3][3];
    //4 states, x = x vant brettet, o = o vant brettet, t = tie, null = pågående 
    char state;
    //"e1"
}board1;

int main(){
    board1 boards[3][3] = {{{'a','b','c'},{'a','b','c'},{'a','b','c'}},'l'};

    printf("fawfwa %c",boards[0][0].board[1][1]);

    return 0;
}