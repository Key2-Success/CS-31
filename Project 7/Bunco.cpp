// Name: Kitu Komya
// UID: 404-491-375
// Assignment: Project 7
// File: Bunco.cpp

#include "Bunco.h"
#include <iostream>

namespace cs31
{
	Bunco::Bunco() : mRound(0)
	{

	}

	// stringifies game by stringifying Board
	std::string Bunco::display(std::string msg) const
	{
		using namespace std;
		std::string s = mBoard.display();
		s = s + msg;

		if (gameIsOver()) // determines if game has ended
		{
			if (determineGameOutcome() == TIEDGAME)
			{
				s = s + "\n\t\tBunco wound up tied!\n";
			}
			else if (determineGameOutcome() == HUMANWONGAME)
			{
				s = s + "\n\t\tyou won Bunco!\n";
			}
			else
			{
				s = s + "\n\t\tyou lost Bunco!\n";
			}
		}
		return(s); // returns output of game
	}

	// set the current round of play, notifying the board and each
	// player of the current round
	void Bunco::setRound(int round)
	{
		mRound = round;
		mBoard.setCurrentRound(round);
		mHuman.setRound(round);
		mComputer.setRound(round);
	}

	// human rolls die
	int Bunco::humanPlay(int amount)
	{
		int roll(0);							
		if (amount == 0) // if amount is 0, then does a random roll
		{
			roll = mHuman.roll();				
		}
		else
		{
			roll = mHuman.roll(amount); // otherwise, the roll is the amount value
		}
		return(roll);							
	}

	// computer rolls die
	int Bunco::computerPlay(int amount)
	{
		int roll(0);							
		if (amount == 0) // if amount is 0, then does a random roll
		{
			roll = mComputer.roll();			
		}
		else
		{
			roll = mComputer.roll(amount); // otherwise, the roll is the amount value
		}
		return(roll);							
	}

	// determines winner of the round
	Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome()
	{
		ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
		if (mHuman.getScore() > mComputer.getScore()) // if human's score is more than the computer's, then declare human as winner
		{
			mBoard.markHumanAsWinner();						
			result = ROUNDOUTCOME::HUMANWON;		
		}
		if (mHuman.getScore() < mComputer.getScore()) // if human's score is less than the computer's, then declare computer as winner
		{
			mBoard.markComputerAsWinner();				
			result = ROUNDOUTCOME::COMPUTERWON;			
		}
		if (mHuman.getScore() == mComputer.getScore()) // if both scores are tied, the game's result is not decided
		{
			result = ROUNDOUTCOME::NOTDECIDED;			
		}
		return(result);									
	}

	// determines winner of the game
	Bunco::GAMEOUTCOME  Bunco::determineGameOutcome() const
	{
		GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
		if ((mBoard.countUpComputerRoundWins()+mBoard.countUpHumanRoundWins())==6) // determine only oncetthe score for human and computer add to 6
		{
			{
				if (mBoard.countUpHumanRoundWins() > mBoard.countUpComputerRoundWins()) // if human had more wins, then human wins the game
				{
					result = GAMEOUTCOME::HUMANWONGAME;										
				}
				else if (mBoard.countUpHumanRoundWins() < mBoard.countUpComputerRoundWins()) // if human had fewer wins, then computer wins the game
				{
					result = GAMEOUTCOME::COMPUTERWONGAME;								
				}
				else if (mBoard.countUpHumanRoundWins() == mBoard.countUpComputerRoundWins()) // if both human and computer had the same score, the game is tied
				{
					result = GAMEOUTCOME::TIEDGAME;											
				}
			}
		}
		return(result);
	}

	// determine if game is over
	bool Bunco::gameIsOver() const	
	{
		GAMEOUTCOME result = determineGameOutcome(); // checks by determining if game outcome has been determined
		return(result != GAMENOTOVER);
	}

}