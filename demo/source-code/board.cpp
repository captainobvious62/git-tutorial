//
//  board.cpp
//  Source Code
//
//  Created by Illya Starikov on 12/20/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#include "board.h"

// Returns the enum corresponding to the value of who is the winner
// A blank is returned if no one won
GameState Board::getWinner() {
	static const std::vector<std::vector<int>> winCondition = {
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 1, 0, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0 }
	};
	
	for (const auto & conditions : winCondition) {
		auto boardAndWin = zip(conditions, flatten(board), 0, blank);
		
		if (accumulate(boardAndWin.begin(), boardAndWin.end(), true, 
			[&] (bool accumulator, auto next) { return accumulator && (std::get<0>(next) == 0 ? true : std::get<1>(next) == x); }
		)) {
			return x; 
		} else if (accumulate(boardAndWin.begin(), boardAndWin.end(), true, 
			[&] (bool accumulator, auto next) { return accumulator && (std::get<0>(next) == 0 ? true : std::get<1>(next) == o); }
		)) {
			return o;
		}
	}
	
	return blank;
}

bool Board::hasWon() {
	return getWinner() != blank;
}

bool Board::noMoreMovesAvailable() {
	auto flatBoard = flatten(board);
	return accumulate(flatBoard.begin(), flatBoard.end(), true, 
		[&] (bool accumulator, auto next) { return accumulator && next != blank; }
	);
}