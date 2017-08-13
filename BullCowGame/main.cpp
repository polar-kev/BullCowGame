/*
 Console executable using BullCowClass. 
 View for MVC. 
 
//  main.cpp
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
*/

#include <iostream>
#include "FBullCowGame.h"

using FText = std::string; //Needed for Unreal Engine. FText is for user interaction.
using int32 = int;//Needed for use with Unreal Engine. Allows mult-platform deployment.

void play();
void printIntroText();

FBullCowGame mygame;

//TODO Make a play again loop instead of going back to main menu
//TODO Add more word game types in addition to isograms
int main(int32 argc, const char * argv[]) {
    FText choice;
    int32 i_choice;
    
    do{
        printIntroText();
        std::getline(std::cin,choice);
        i_choice = stoi(choice);
        switch(i_choice){
            case 1:
                play();
                break;
            case 2:
                //Explain the Rules
                break;
            case 3:
                //change the difficulty
                break;
            case 4:
                std::cout << "Quitting Bulls and Cows";
                return 0;
            default:
                break;
        }
    }while(i_choice != 4);
}//end of main


//TODO build a struct for bulls/cows
void play(){
    mygame.reset();
    
    while(mygame.getAttempts() > 0 && !mygame.bWinCheck()){
        std::cout   << "\nGuess a " << mygame.getGoalWordLength() << " letter word.\n"
                    << "You have " << mygame.getAttempts() << " remaining attempts.\n";
        mygame.setGuess();
        std::cout   << "You guessed: " << mygame.getGuessWord() << std::endl
                    << "Bulls: " << mygame.getBulls() << std::endl
                    << "Cows: " << mygame.getCows() << std::endl;
    }//end while
    mygame.printGameSummary();
}//end of play()

void printIntroText(){
    std::cout   << "Welcome to Bulls and Cows.\n"
                << "Can you guess the isogram I've got in my head?\n\n"
                << "Please make a selection: \n"
                << "1.\t Play Bulls and Cows\n"
                << "2.\t Explain the Rules\n"
                << "3.\t Change the Difficulty\n"
                << "4.\t Quit\n\n";
}
