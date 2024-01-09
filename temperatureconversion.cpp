#include<iostream>
int main(){
    float temp;
    char unit;
    std::cout<<"*************Temperature converter*************\n";
    std::cout<<"C = Celsius: ";
    std::cout<<"F = Fahrenheit: ";
    std::cout<<"Which unit would you like to convert it to? (C / F)\n";
    std::cin>>unit;
        
    if (unit == 'F'|| unit == 'f'){
        std::cout<<"Enter the temperature in Celsius: ";
        std::cin>>temp;
        temp = (temp*1.8) + 32;
    }
    else if (unit == 'C'|| unit == 'c'){
        std::cout<<"Enter the temperature in Fahrenheit: ";
        std::cin>>temp;
        temp = (temp-32)/1.8;
    }
    else{
        std::cout<<"Invalid input! Please enter either C or F!\n";
    }
    std::cout<<"The converted temp is: "<<temp<<" degree "<<unit;
    std::cout<<"***********************************************";
    return 0;
}