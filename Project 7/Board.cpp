// Name: Kitu Komya
// UID: 404-491-375
// Assignment: Project 7
// File: Board.cpp

#include "Board.h"

namespace cs31
{
	Board::Board() : mRound(0)
	{
		// initializes each of the BoardRow
		for (int a = 1; a <= 6; a++)
		{
			mBoardRow[a].setRound(a);
		}
	}

	void Board::setCurrentRound(int round)
	{
		// unsets current BoardRow
		if (mRound >= 0 && mRound <= 6)
			mBoardRow[mRound].setCurrentRound(false);
		mRound = round;

		// sets the current BoardRow
		if (mRound >= 0 && mRound <= 6)
			mBoardRow[mRound].setCurrentRound(true);
	}

	// sets human player as winner for the round
	void Board::markHumanAsWinner()
	{
		mBoardRow[mRound].setHumanAsWinner();	
	}

	// sets computer player as winner for the round
	void Board::markComputerAsWinner()
	{
		mBoardRow[mRound].setComputerAsWinner();
	}

	// stringifies the Board
	std::string Board::display() const
	{
		std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";

		for (int i = 1; i <= 6; i++)
		{
			s += mBoardRow[i].display() + "\n";
		}

		return(s);
	}

	// calculates # of rounds human player has won in a game using variable total
	int Board::countUpHumanRoundWins() const
	{
		int total = 0;								
		for (int i = 1; i <= 6; i++)
		{
			if (mBoardRow[i].didHumanWin())			
			{
				total++; // total sum increases when human wins a round							
			}

		}
		return total;								
	}

	// calculates # of rounds computer player has won in a game using variable total
	int Board::countUpComputerRoundWins() const
	{
		int total = 0;								
		for (int b = 1; b <= 6; b++)				
		{
			if (mBoardRow[b].didComputerWin())
			{
				total++; // total sum increases when computer wins a round
			}

		}
		return total;						
	}


}
