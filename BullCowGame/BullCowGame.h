//
//  BullCowGame.h
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

#ifndef BullCowGame_h
#define BullCowGame_h
#include <string>

class BullCowGame
{
    std::string goalWord;
    std::string guessWord;
    int attempts;
    bool isIsogram(std::string newWord);
    bool isValid(std::string newWord);
    
    
public:
    BullCowGame();
    void reset();
    int getBulls() const;
    int getCows() const;
    int getAttempts() const;
    bool winCheck() const;
    void setGuess();
    std::string getGoalWord() const;
    std::string getGuessWord() const;
};

#endif /* BullCowGame_h */
