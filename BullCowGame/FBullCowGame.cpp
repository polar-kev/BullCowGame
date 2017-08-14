/*
 Game class Implementation of the game Bulls and Cows,
 based on the popular Mastermind boardgame.
 Changes to syntax were made to make this code compatible with the Unreal Engine
 
 Kevin Semple - 2017
 
*/

//#include <stdio.h>
#include <iostream>
#include "FBullCowGame.h"
#include <map>
#define TMap std::map //Used for Unreal Engine compatibility

//Used for Unreal Engine compatibility
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame(){
    gamestyle = EGamestyle::PALINDROME;//
    reset();
}

void FBullCowGame::reset(){
    if(gamestyle == EGamestyle::ISOGRAM){
        goalWord = "bonus";//support for hardcoded words length 3-7 letters
    }else{
        goalWord = "kayak";
    }
    
    guessWord = "";
    attempts = getAttempts();
    bWin = bWinCheck();
}

//Bull: letter in the guessed word is in the same position as in the hidden word
int32 FBullCowGame::getBulls() const {
    int32 count = 0;
    for(int32 i=0;i<goalWord.length();i++){
        if(goalWord[i] == guessWord[i]){
            count++;
        }
    }
    return count;
}

//Cow: letter in the guessed word is in a different position in the hidden word
int32 FBullCowGame::getCows() const {
    int32 count = 0;
    for(int32 i=0;i<goalWord.length();i++){
        for(int32 j=0;j<goalWord.length();j++){
            if(i==j && goalWord[i] == guessWord[j]){
                break;
            }
            if(goalWord[i] == guessWord[j]){
                count++;
            }
        }
    }
    return count;
}

//Takes input from player and does not proceed with game logic until valid input is received
void FBullCowGame::inputGuess(){
    FString newWord;
    EWordStatus status = EWordStatus::INVALID_STATUS;
    
    do{
        std::getline(std::cin,newWord);
        status = isValid(newWord);
        switch (status) {
            case EWordStatus::WRONG_LENGTH :
                std::cout << "Please enter a " << getGoalWordLength() << " letter word.\n";
                break;
            case EWordStatus::NOT_ISOGRAM :
                std::cout << "Please enter a word with no repeated letters.\n";
                break;
            case EWordStatus::NOT_LOWERCASE :
                std::cout << "Please make sure all the letters are lowercase.\n";
                break;
            case EWordStatus::NUMBERS :
                std::cout << "Please make sure your word has no numbers.\n";
                break;
            case EWordStatus::NOT_PALINDROME :
                std::cout << "Please make sure your word is a palindrome.\n";
                break;
            default:
                break;
        }
    }while(status != EWordStatus::OK);
    
    guessWord=newWord;
    bWin = bWinCheck();//win condition
    attempts-=1;
}

//Verify that user input is valid
EWordStatus FBullCowGame::isValid(FString newWord){
    if(bHasNumber(newWord)){
        return EWordStatus::NUMBERS;
    }else if(goalWord.length() != newWord.length()){
        return EWordStatus::WRONG_LENGTH;
    }else if((gamestyle == EGamestyle::ISOGRAM) && !bIsIsogram(newWord)){
        return EWordStatus::NOT_ISOGRAM;
    }else if((gamestyle == EGamestyle::PALINDROME) && !bIsPalindrome(newWord)){
        return EWordStatus::NOT_PALINDROME;
    }else if(!bIsLowerCase(newWord)){
        return EWordStatus::NOT_LOWERCASE;
    }
    else{
        return EWordStatus::OK;
    }
    
}

//Isogram- a word where every letter only appears once in the word
//Algorithm improved from O(n^2) to O(n) using hash map
bool FBullCowGame::bIsIsogram(FString newWord) const{
    //treat 0 and 1 letter words as isograms
    if(newWord.length()<=1){return true;}
    
    TMap<char,bool> letterSeen;
    for(auto Letter : newWord){
        Letter = tolower(Letter);//only want to work with lowercase letters
        if(letterSeen[Letter] == true){//if the letter is in the map
            return false;//We do not have an isogram
        } else{
            letterSeen[Letter]=true;
        }
    }
    
    /*Old implementation
    //isogram = a word where each letter only appears once
    for(int32 i=0;i<newWord.length();i++){
        for(int32 j=0;j<newWord.length();j++){
            if(i==j){
                break;
            }
            if(newWord[i] == newWord[j]){return false;}
        }
    }
    return true;
     */
    
    return true;//for example in cases where /0 is entered
}

bool FBullCowGame::bIsPalindrome (FString word) const{
    int maxchars = (uint32_t)word.length();
    if(maxchars<=1){return true;}
    int middle = (maxchars-1)/2;
    if(maxchars%2 != 0){middle--;}//if odd number of chars, middle letter will be unique
    for(int i=0;i<=middle;i++){
        if(!(word[i] == word[maxchars-1-i])){//if the letters don't match counting out from the middle
            return false;
        }
    }
    return true;
}

bool FBullCowGame::bIsLowerCase(FString word) const{
    for(auto letter : word){
        if(!islower(letter)){
            return false;
        }
    }
    return true;
}

bool FBullCowGame::bHasNumber(FString word) const{
    for(auto letter : word){
        if(isdigit(letter)){
            return true;
        }
    }
    return false;
}

void FBullCowGame::printGameSummary(){
    if(bWinCheck()){
        std::cout << "\nYOU WIN!" << std::endl << "The word was " << getGuessWord() << "!" << std::endl << std::endl;
    }else{
        std::cout << "\nYOU LOSE!\n\n";
    }
}

void FBullCowGame::setGamestyle(){
    if(gamestyle == EGamestyle::ISOGRAM){
        gamestyle = EGamestyle::PALINDROME;
        std::cout << "Game style set to Palindromes!\n\n";
    }else{
        gamestyle = EGamestyle::ISOGRAM;
        std::cout << "Game style set to Isograms!\n\n";
    }
}

//Win condition- the player guessed the right word
bool FBullCowGame::bWinCheck() const {return (guessWord==goalWord);}

int32 FBullCowGame::getGoalWordLength() const {return (uint32_t)goalWord.length();}//Word length is very unlikely to be too large for 'int' data type.

FString FBullCowGame::getGuessWord() const {return guessWord;}

//Generate numbere of guess attempts based on word length
int32 FBullCowGame::getAttempts() const {
    TMap<int32,int32>WordLengthToAttemps {{3,3},{4,5},{5,5},{6,10},{7,15}};
    return WordLengthToAttemps[getGoalWordLength()];
}
