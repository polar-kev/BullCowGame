//
//  FBullCowGame.h
//  BullCowGame
//
//  Created by Kevin Semple on 2017-08-12.
//  Copyright © 2017 ksemp. All rights reserved.
//

#ifndef FBullCowGame_h
#define FBullCowGame_h
#include <string>

using FString = std::string;//Needed for use with Unreal Engine. FString is mutable.
using int32 = int;//Needed for use with Unreal Engine. Allows mult-platform deployment.

enum class EWordStatus {
    INVALID_STATUS,
    OK,
    NOT_ISOGRAM,
    NOT_LOWERCASE,
    NUMBERS,
    WRONG_LENGTH,
    
};

class FBullCowGame
{
    FString goalWord;
    FString guessWord;
    int32 attempts;
    bool bIsIsogram(FString);
    bool bWin;
    bool bIsLowerCase(FString);
    bool bHasNumber(FString);
    EWordStatus isValid(FString);
    
public:
    FBullCowGame();
    void reset();
    void setGuess();
    void printGameSummary();
    bool bWinCheck() const;
    int32 getBulls() const;
    int32 getCows() const;
    int32 getAttempts() const;
    int32 getGoalWordLength() const;
    FString getGuessWord() const;
};

#endif /* FBullCowGame_h */
