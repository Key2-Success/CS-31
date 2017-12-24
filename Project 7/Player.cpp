// Name: Kitu Komya
// UID: 404-491-375
// Assignment: Project 7
// File: Bunco.cpp

#include "Player.h"
#include "Die.h"

namespace cs31
{

	Player::Player() : mDie(6), mScore(0), mRound(0)				//constructor
	{
		//this is empty since initialized earlier 
	}

	// player rolls die
	int Player::roll(int amount)
	{
		int roll(0);						
		if (amount == 0) // if amount is 0, then does a random roll				
		{
			mDie.roll();					
			roll = mDie.getValue();		
		}
		else if (amount > 0 && amount < 7) // else if amount is valid, roll is the amount value
		{
			roll = amount;				
		}
		if (roll == mRound) // if roll is equal to the round, increment score
		{
			mScore++;					
		}
		return roll;					
	}

	// sets current round and resets player's score to 0
	void Player::setRound(int round)
	{
		mScore = 0; // player score is 0
		if (round > 0 && round < 7) // if round is valid, set current round
		{
			mRound = round;			
		}
	}

	// returns score member variable
	int  Player::getScore() const
	{
		return mScore; // returns score
	}


}