//
//  main.cpp
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

#include <iostream>

bool isogramCheck(char myword[]);
bool bullCheck(std::string myword);


int main(int argc, const char * argv[]) {
    char word[6];
    std::cout << "Welcome to Bulls and Cows.\n";
    std::cout << "Enter a 5 letter word to see if it is an isogram: \n";
    std::cin >> word;
    if(isogramCheck(word)){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}

//isogram is a word where each letter only appears once
bool isogramCheck(char myword[]){
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            if(i==j){
                break;
            }
            if(myword[i] == myword[j]){
                return false;
            }
        }
    }
    return true;
}
