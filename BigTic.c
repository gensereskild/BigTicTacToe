#include <stdio.h>
#include <stdbool.h>

char board[3][3];
bool player1Turn = true;

typedef char brett[3][3];

//brett board1 = {{'a','b','v'},{'2'}};

typedef struct{
    char board[3][3];
    //4 states, x = x vant brettet, o = o vant brettet, t = tie, null = pågående 
    char state;
}board1;

void resetBoard();
void printBoard();

void placeSymbol();

bool isFinished();

int main(){
    board1 boards[3][3] = {{{'a','b','c'},{'a','b','c'},{'a','b','c'}},'l'};

    printf("fawfwa %c",boards[0][0].board[1][1]);

    /*resetBoard();
    do{
    printBoard();
    placeSymbol();

    }while(!isFinished());
    printBoard();
    
    if(player1Turn){
        printf("Spiller 1 vant");
    }*/

    //(player1Turn) ? printf("spiller 1 vant") : printf("spiller 2 vant");
    //slutt:
    return 0;
}

void resetBoard(){
    printf("yo \n");
    for(int i = 0; i<3; i++){
        for ( int j = 0; j<3; j++){
            board[i][j]=' ';
        }
    }
}

void printBoard(){
    for(int i = 0; i< sizeof(board[0])/sizeof(board[0][0]); i++){

        for(int j = 0; j < sizeof(board)/sizeof(board[0]); j++){
            printf("| %c |",board[i][j]);
        }
        printf("\n################\n");
    }
}
void placeSymbol(){
    beginning:
    int collum;
    int row;
    printf("What collum do you want to place in? 1, 2 or 3 \n");
    scanf("%d",&collum);
    collum--;
    printf("What row do you want to place in? 1, 2 or 3 \n");
    scanf("%d", &row);
    row--;
    if(board[row][collum]!=' '){
        printf("Invalid row or collum try again");
        goto beginning;
    }
    if(player1Turn){
        board[row][collum]='X';
        player1Turn = false;
    }
    else if(!player1Turn){
        board[row][collum]='O';
        player1Turn = true;
    }
}

bool isFinished(){
    for (int i = 0; i < sizeof(board)/sizeof(board[0]); i++){
        //check horisontal
        if((board[i][0] == board[i][1] && board[i][0]!=' ') && (board[i][1]==board[i][2])){
            printf("Horizontal GG \n");
            return true;
        }
        //check vertical
        if(board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[0][i]!= ' '){
            printf("Vertical GG \n");
            return true;
        }
    }
    //check diagonal
    if((board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=' ')
     ||(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=' ')){
        printf("GG diagonal \n");
        return true;
    }

    bool tie = true;
    //sjekker TIE
    for(int i =0; i<sizeof(board)/sizeof(board[0]); i++){
        for(int j = 0; j < sizeof(board[0])/sizeof(board[0][0]); j++){
            if(board[i][j]==' '){
                tie = false;
            }
        }
    }
    return tie;
}