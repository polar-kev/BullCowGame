/*
 Bulls and Cows game Class declarations
 Changes to syntax were made to make this code compatible with the Unreal Engine
 
 Kevin Semple - 2017
*/

#ifndef FBullCowGame_h
#define FBullCowGame_h
#include <string>

//Used for Unreal Engine compatibility
using FString = std::string;
using int32 = int;

enum class EWordStatus {
    INVALID_STATUS,
    OK,
    NOT_ISOGRAM,
    NOT_PALINDROME,
    NOT_LOWERCASE,
    NUMBERS,
    WRONG_LENGTH,
    
};

enum class EGamestyle {
    ISOGRAM,
    PALINDROME,
};

class FBullCowGame
{
    FString goalWord;
    FString guessWord;
    int32 attempts;
    bool bIsIsogram (FString) const;
    bool bIsPalindrome (FString) const;
    bool bWin;
    bool bIsLowerCase (FString) const;
    bool bHasNumber (FString) const;
    EWordStatus isValid(FString);
    EGamestyle gamestyle;
    
    
public:
    FBullCowGame();
    void reset();
    void inputGuess();
    void printGameSummary();
    void setGamestyle();
    bool bWinCheck() const;
    int32 getBulls() const;
    int32 getCows() const;
    int32 getAttempts() const;
    int32 getGoalWordLength() const;
    FString getGuessWord() const;
};

#endif /* FBullCowGame_h */
