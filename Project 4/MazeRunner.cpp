/* Solve the given maze using right-hand algorithm
 * If the rat can turn right, it does so. If it cannot, it moves forward. If it
 * cannot move forward, it turns left. If it cannot turn left, it backtracks.
 * Alex Debrecht */

#include <iostream>
using namespace std;

// function main begins program execution
int main() {

	// Initialize maze
	char maze[12][12] =
	{ { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
			{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
			{ 'R', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
			{ '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#' },
			{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.' },
			{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
			{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
			{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
			{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
			{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
			{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
			{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };

	// Start at entrance of left hand side
	int forward = 1; // 0 is up, 1 is right, 2 is down, 3 is left
	int currentRow = 2;
	int currentCol = 0;

	// Loop until you reach the right hand side
	while (currentCol != 11) {

		/* For each if statement below, checks for wall (#), new path (.),
		 * and traveled path (*), and replaces direction moved with appropriate symbol
		 * R represents current location of rat */

		// Rat initially hasn't moved
		bool move = false;

		switch (forward) {
		// If facing up, check right
		case 0:
			// If right is open, move
			if (maze[currentRow][currentCol + 1] == '.') {
				maze[currentRow][currentCol] = '*';
				currentCol = currentCol + 1;
				maze[currentRow][currentCol] = 'R';
				forward = 1;
				move = true;
				break;
				// If right has been traveled, backtrack
			} else if (maze[currentRow][currentCol + 1] == '*') {
				maze[currentRow][currentCol] = '-';
				currentCol = currentCol + 1;
				maze[currentRow][currentCol] = 'R';
				forward = 1;
				move = true;
				break;
				// If right is a wall, turn
			} else if (maze[currentRow][currentCol + 1] == '#') {
				forward = 3;
				break;
			}
			break;
			// If facing right, check down
		case 1:
			// If down is open, move
			if (maze[currentRow + 1][currentCol] == '.') {
				maze[currentRow][currentCol] = '*';
				currentRow = currentRow + 1;
				maze[currentRow][currentCol] = 'R';
				forward = 2;
				move = true;
				break;
				// If down has been traveled, backtrack
			} else if (maze[currentRow + 1][currentCol] == '*') {
				maze[currentRow][currentCol] = '-';
				currentRow = currentRow + 1;
				maze[currentRow][currentCol] = 'R';
				forward = 2;
				move = true;
				break;
				// If down is a wall, turn
			} else if (maze[currentRow + 1][currentCol] == '#') {
				forward = 0;
				break;
			}
			break;
			// If facing down, check left
		case 2:
			// If left is open, move
			if (maze[currentRow][currentCol - 1] == '.') {
				maze[currentRow][currentCol] = '*';
				currentCol = currentCol - 1;
				maze[currentRow][currentCol] = 'R';
				forward = 3;
				move = true;
				break;
				// If left has been traveled, backtrack
			} else if (maze[currentRow][currentCol - 1] == '*') {
				maze[currentRow][currentCol] = '-';
				currentCol = currentCol - 1;
				maze[currentRow][currentCol] = 'R';
				forward = 3;
				move = true;
				break;
				// If left is a wall, turn
			} else if (maze[currentRow][currentCol - 1] == '#') {
				forward = 1;
				break;
			}
			break;
			// If facing left, check up
		case 3:
			// If up is open, move
			if (maze[currentRow - 1][currentCol] == '.') {
				maze[currentRow][currentCol] = '*';
				currentRow = currentRow - 1;
				maze[currentRow][currentCol] = 'R';
				forward = 0;
				move = true;
				break;
				// If up has been traveled, backtrack
			} else if (maze[currentRow - 1][currentCol] == '*') {
				maze[currentRow][currentCol] = '-';
				currentRow = currentRow - 1;
				maze[currentRow][currentCol] = 'R';
				forward = 0;
				move = true;
				break;
				// If up is a wall, turn
			} else if (maze[currentRow - 1][currentCol] == '#') {
				forward = 2;
				break;
			}
			break;
		} // End of nested if blocks

		// After each iteration (if rat has moved), print status of maze
		if (move) {
			for (int i = 0; i < 12; ++i) {
				for (int j = 0; j < 12; ++j) {
					cout << maze[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

	} // end while loop
} // exit main
