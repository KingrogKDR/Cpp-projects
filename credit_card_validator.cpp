#include<iostream>

// ---Luhn Algorithm---
 
// 1. Double every second digit number from right to left. If doubled number is 2 digits, split them
// 2. Add all the single digits from step 1
// 3. Add all odd numbered digits from right to left
// 4. Add the results of step 1 and step 2
// 5. if step 4 is divisible by 10, the number is valid.

int getDigit(const int number);
int sumOfEvenDigits(const std::string cardNumber);
int sumOfOddDigits(const std::string cardNumber);

int main(){
    std::string cardNumber;
    std::cout<<"Enter a credit card #: ";
    std::cin>>cardNumber;

    int result = sumOfEvenDigits(cardNumber) + sumOfOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout<<cardNumber<<" is valid";
    }
    else{
        std::cout<<cardNumber<<" is invalid";
    }
    return 0;
}

int getDigit(const int number){     
    return number % 10 + (number / 10 % 10);  // splitting the 2-digit number and adding the digits since we
}                                            // have to add them anyway
int sumOfEvenDigits(const std::string cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i] - '0')*2);
    }
    return sum;
}
int sumOfOddDigits(const std::string cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}