//
//  BullCowGame.h
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

#ifndef BullCowGame_h
#define BullCowGame_h

class BullCowGame
{
    std::string goalWord;
    std::string guessWord;
    int attempts;
    bool isIsogram(std::string newWord);
    bool isValid(std::string newWord);
    
    
public:
    BullCowGame();
    void decreaseAttempts();
    int getBulls();
    int getCows();
    int getAttempts();
    bool winCheck();
    void setGuess();
    std::string getGoalWord();
    std::string getGuessWord();
};

#endif /* BullCowGame_h */
