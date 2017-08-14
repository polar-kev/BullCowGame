/*
 Console executable using BullCowClass. 
 The Bulls and Cows game is based of the popular board game Mastermind.
 
 Changes to syntax were made to make this code compatible with the Unreal Engine
 
 Kevin Semple - 2017
*/

#include <iostream>
#include "FBullCowGame.h"

//Used for Unreal Engine compatibility
using FText = std::string;
using int32 = int;

void play();
void printIntroText();
void printTextArt();
void printRules();
int32 submitChoice(FText);

FBullCowGame mygame;

//TODO Make a play again loop instead of going back to main menu
//TODO Add more word game types in addition to isograms (palindrome)


int main(int32 argc, const char * argv[]) {
    FText choice;
    int32 validChoice;
    
    printTextArt();
    
    do{
        printIntroText();
        std::getline(std::cin,choice);
        validChoice = submitChoice(choice);
        
        switch(validChoice){
            case 1:
                play();
                break;
            case 2:
                printRules();
                break;
            case 3:
                mygame.setGamestyle();
                break;
            case 4:
                std::cout << "Quitting Bulls and Cows. \n\n";
                return 0;
            case 5:
            default:
                std::cout << "\nInvalid Selection!\n";
                break;
        }
    }while(validChoice != 4);
}//end of main


//TODO build a struct for bulls/cows
void play(){
    mygame.reset();
    
    while(mygame.getAttempts() > 0 && !mygame.bWinCheck()){
        std::cout   << "\nGuess a " << mygame.getGoalWordLength() << " letter word.\n"
                    << "You have " << mygame.getAttempts() << " remaining attempts.\n";
        mygame.inputGuess();
        std::cout   << "You guessed: " << mygame.getGuessWord() << std::endl
                    << "Bulls: " << mygame.getBulls() << std::endl
                    << "Cows: " << mygame.getCows() << std::endl
        << "------------" << std::endl;
    }//end while
    
    mygame.printGameSummary();
    
}//end of play()

//TODO make sure user can't submit a menu value that is out of range of int
//Verify valid main menu selection
int32 submitChoice(FText choice){
    int verified;
    if(isdigit(choice[0])){
        verified = stoi(choice);
        return verified;
    }
    return -1;//invalid choice
}


void printTextArt(){
    std::cout   <<"//                                      _" << std::endl
    <<"//   _____ _____ __    __    _____    _| |_    _____ _____ _ _ _ _____" << std::endl
    <<"//  | __  |  |  |  |  |  |  |   __|  |   __|  |     |     | | | |   __|" << std::endl
    <<"//  | __ -|  |  |  |__|  |__|__   |  |   __|  |   --|  |  | | | |__   |" << std::endl
    <<"//  |_____|_____|_____|_____|_____|  |_   _|  |_____|_____|_____|_____|" << std::endl
    <<"//                                     |_|" << std::endl  << std::endl;
}
void printIntroText(){
    std::cout   << "Welcome to Bulls and Cows.\n"
                << "Can you guess the word I've got in my head?\n\n"
                << "Please make a selection: \n"
                << "1.\t Play Bulls and Cows\n"
                << "2.\t Explain the Rules\n"
                << "3.\t Toggle Palindromes vs Isograms\n"
                << "4.\t Quit\n\n";
}

void printRules(){
    std::cout   << "\nGuess the word in my head before you run out of attempts." << std::endl
                << "An Isogram is a word that has no repeating letters." << std::endl
                << "A Palindrome is a word that reads the same backwards and forwards." << std::endl
                << "Good Luck!" << std::endl << std::endl;
}
