//
//  main.cpp
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

#include <iostream>
#include "BullCowGame.h"


void play();
void printIntroText();


int main(int argc, const char * argv[]) {
    int choice;
    
    do{
        printIntroText();
        std::cin >> choice;
        switch(choice){
            case 1:
                //play game
                std::cin.ignore(256, '\n');//input buffer maintenance
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
    }while(choice != 4);
}//end of main


//initialize the game
void play(){
    BullCowGame mygame;
    int bulls,cows;
    
    while(mygame.getAttempts() > 0){
        std::cout   << "\nGuess a " << mygame.getGoalWord().length() << " letter word.\n"
                    << "You have " << mygame.getAttempts() << " remaining attempts.\n";
        mygame.decreaseAttempts();
        mygame.setGuess();
        std::cout << "You guessed: " << mygame.getGuessWord() << std::endl;
        
        bulls = mygame.getBulls();
        cows = mygame.getCows();
            
        std::cout   << "Bulls: " << bulls << std::endl
                    << "Cows: " << cows << std::endl;
    
        if(mygame.winCheck()){
            std::cout << "You win! The word was " << mygame.getGoalWord() << "!" << std::endl << std::endl;
            break;
        }
    }//end while
    if(mygame.getAttempts()==0){
        std::cout << "You have 0 attempts left. YOU LOSE!\n\n";
    }
}//end of play()


void printIntroText(){
    std::cout   << "Welcome to Bulls and Cows.\n"
                << "Can you guess the isogram I've got in my head?\n"
                << "Please make a selection: \n"
                << "1.\t Play Bulls and Cows\n"
                << "2.\t Explain the Rules\n"
                << "3.\t Change the Difficulty\n"
                << "4.\t Quit\n";
}
