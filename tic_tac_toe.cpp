#include<iostream>
#include<ctime>

void drawboard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
int main(){

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);

    while(running){
        playerMove(spaces, player);
        drawboard(spaces);
        
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawboard(spaces);

        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout<<"Thanks for playing!";
    return 0;
}

void drawboard(char *spaces){
    std::cout<<'\n';
    std::cout<<"   |   |   \n";
    std::cout<<" "<<spaces[0]<<" | "<<spaces[1]<<" | "<<spaces[2]<<" "<<'\n';
    std::cout<<"___|___|___\n";
    std::cout<<"   |   |   \n";
    std::cout<<" "<<spaces[3]<<" | "<<spaces[4]<<" | "<<spaces[5]<<" "<<'\n';
    std::cout<<"___|___|___\n";
    std::cout<<"   |   |   \n";
    std::cout<<" "<<spaces[6]<<" | "<<spaces[7]<<" | "<<spaces[8]<<" "<<'\n';
    std::cout<<"   |   |   \n";
    std::cout<<'\n';
}
void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout<<"Enter you choice in numbers of the grid (1-9): ";
        std::cin>>number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }

    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));
    
    while(true){
    	number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[3] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;
}
bool checkTie(char *spaces){
    for (int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout<<"IT'S A TIE!!";
    return true;
}
