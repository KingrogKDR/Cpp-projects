#include<iostream>
#include<ctime>
int main(){
    
    int tries, num, guess;

    srand(time(0));
    num = rand()%100 + 1;

    do{
        std::cout<<"Guess the number: ";
        std::cin>>guess;
        tries++;
        std::cout<<"********NUMBER GUESSER********\n";
        if(num>guess){
            std::cout<<"Higher\n";
        }
        else if(num<guess){
            std::cout<<"Lower\n";
        }       
        else{
            std::cout<<"Correct!\n";
            std::cout<<"You took "<<tries<<" tries!\n"; 
        }
        std::cout<<"******************************\n";
        
    }while(guess != num);
  
    return 0;
}