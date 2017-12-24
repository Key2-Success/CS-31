// Name: Kitu Komya
// UID: 404-491-375
// Assignment: Project 7
// File: Board.h

#ifndef Board_h
#define Board_h
#include "BoardRow.h"

namespace cs31
{

	// CS 31 students have been provided this class to represent
	// a Bunco Board.  Each Board is made up of an array of BoardRow.
	// The display( ) method is used by the Bunco game to print the
	// current state of the game.  Each Board knows the current round
	// in play.  Each Board gets told when either the human player wins
	// the round or the computer player wins the round.  Given the
	// array of BoardRow, this class can count up how many rounds each
	// player has won.
	// CS 31 students need to complete the TODO portions of this class
	class Board
	{
	public:
		Board();
		// sets current round
		void setCurrentRound(int round);
		// sets human as round winner
		void markHumanAsWinner();
		// sets computer as round winner
		void markComputerAsWinner();
		// calculates # of rounds computer has won
		int countUpComputerRoundWins() const;
		// calculates # of rounds human as won
		int countUpHumanRoundWins() const;
		// stringifies the Board
		std::string display() const;
	private:
		BoardRow mBoardRow[7];  // elements 1-6, ignoring spot 0,
								// are used for rounds 1-6
		int mRound;             // the current round of play
	};

}

#endif /* Board_h */
