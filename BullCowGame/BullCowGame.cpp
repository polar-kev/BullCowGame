//
//  BullCowGame.cpp
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

//#include <stdio.h>
#include <iostream>
#include "BullCowGame.h"
using namespace std;

BullCowGame::BullCowGame(){
    reset();
}

void BullCowGame::reset(){
    goalWord = "clown";
    guessWord = "";
    attempts = 5;
}

int BullCowGame::getBulls() const {
    //Bull- letters in the guess word are in the same index position as the goal word
    int count = 0;
    for(int i=0;i<goalWord.length();i++){
        if(goalWord[i] == guessWord[i]){
            count++;
        }
    }
    return count;
}

int BullCowGame::getCows() const {
    //cow- a letter in the guess word can also be found in the goal word but the letters are not in the same index position
    int count = 0;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            if(i==j){
                break;
            }
            if(goalWord[i] == guessWord[j]){
                count++;
            }
        }
    }
    return count;
}

void BullCowGame::setGuess(){
    std::string newWord;
    
    std::cout << "Please guess a word.\n";
    std::getline(std::cin,newWord);
    
    while(!isValid(newWord)){
        std::cout << "Please guess a valid isogram.\n";
        std::getline(std::cin,newWord);
    }
    guessWord=newWord;
    attempts-=1;
}

bool BullCowGame::isValid(std::string newWord){
    if(goalWord.length() != newWord.length() || !isIsogram(newWord)){
        return false;
    }
    return true;
}

bool BullCowGame::isIsogram(std::string newWord){
    //isogram = a word where each letter only appears once
    for(int i=0;i<newWord.length();i++){
        for(int j=0;j<newWord.length();j++){
            if(i==j){
                break;
            }
            if(newWord[i] == newWord[j]){return false;}
        }
    }
    return true;
}

bool BullCowGame::winCheck() const {return goalWord==guessWord;}


std::string BullCowGame::getGoalWord() const {return goalWord;}

std::string BullCowGame::getGuessWord() const {return guessWord;}

int BullCowGame::getAttempts() const {return attempts;}
