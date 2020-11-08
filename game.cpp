#include <iostream>
using namespace std;

void get_and_verify_input(int& input, string game_board[]);
// PURPOSE: check if the spot the user inputted already contains a symbol
// INPUTS: input - integer reference corresponding to what the user inputted
//         game_board[] - array of strings containing the current gameboard
// OUTPUTS: nothing is returned; variables and array are passed by reference

void check_if_winner(string game_board[], bool& x_winner, bool& o_winner, int& x_wins, int& o_wins, const int MAX_PLAYS, int& play_number, bool& tie, int& tie_count);
// PURPOSE: checks if the board contains a winning row, column, or diagonal line
// INPUTS: game_board[] - array of strings containing the current gameboard
//         x_winner - boolean reference indicating if x made a winning move
//         o_winner - boolean reference indicating if o made a winning move
//         x_wins - integer reference corresponding to the amount of times x has won
//         o_wins - integer reference corresponding to the amount of times o has won  
// OUTPUTS: nothing is returned; variables and array are passed by reference

void output_scoreboard(string game_board[]);
// PURPOSE: outputs the tic tac toe scoreboard
// INPUTS: game_board[] - array of strings containing the gameboard
// OUTPUTS: nothing is returned; output is to the console

void execute_tictactoe();
// PURPOSE: runs the steps of the programming in the corresponding order
// INPUTS: none
// OUTPUTS: nothing is returned; output is to the console

void get_and_verify_input(int& input, string game_board[])
{
	cin >> input;
	// ensure that input is correct and not already occupied
	while (!(input > 0 && input < 17) || game_board[input - 1].compare("X") == 0 || game_board[input - 1].compare("O") == 0)
	{
		cout << "Sorry, that is an invalid input, please try again." << endl;
		cin >> input;
	}
}

void check_if_winner(string game_board[], bool& x_winner, bool& o_winner, int& x_wins, int& o_wins, const int MAX_PLAYS, int& play_number, bool& tie, int& tie_count)
{
// check if o wins on a row
	for (int index = 0; index < 12; index += 4) {
		if (game_board[index] == "X" && game_board[index + 1] == "X" && game_board[index + 2] == "X" && game_board[index + 3] == "X")
		{
			x_winner = true;
			x_wins++;
			cout << "Congratulations! Player X won!" << endl;
		}
	}

	// check if o wins on a row
	for (int index = 0; index < 12; index += 4) {
		if (game_board[index] == "O" && game_board[index + 1] == "O" && game_board[index + 2] == "O" && game_board[index + 3] == "O")
		{
			o_winner = true;
			o_wins++;
			cout << "Congratulations! Player O won!" << endl;
		}
	}

	// check if x wins on a column
	for (int index = 0; index < 12; index += 4) {
		if (game_board[index] == "X" && game_board[index + 4] == "X" && game_board[index + 8] == "X" && game_board[index + 12] == "X")
		{
			x_winner = true;
			x_wins++;
			cout << "Congratulations! Player X won!" << endl;
		}
	}

	// check if o wins on a column
	for (int index = 0; index < 12; index += 4) {
		if (game_board[index] == "O" && game_board[index + 4] == "O" && game_board[index + 8] == "O" && game_board[index + 12] == "O")
		{
			o_winner = true;
			o_wins++;
			cout << "Congratulations! Player O won!" << endl;
		}
	}

	// check if x wins on a diagonal
	if (game_board[0] == "X" && game_board[5] == "X" && game_board[10] == "X" && game_board[15] == "X")
	{
		x_winner = true;
		x_wins++;
		cout << "Congratulations! Player X won!" << endl;
	}
	if (game_board[3] == "X" && game_board[6] == "X" && game_board[9] == "X" && game_board[12] == "X")
	{
		x_winner = true;
		x_wins++;
		cout << "Congratulations! Player X won!" << endl;
	}

	// check if o wins on a diagonal
	if (game_board[0] == "O" && game_board[5] == "O" && game_board[10] == "O" && game_board[15] == "O")
	{
		o_winner = true;
		o_wins++;
		cout << "Congratulations! Player O won!" << endl;
	}
	if (game_board[3] == "O" && game_board[6] == "O" && game_board[9] == "O" && game_board[12] == "O")
	{
		o_winner = true;
		o_wins++;
		cout << "Congratulations! Player O won!" << endl;
  }

    // check if there is a tie
    if (play_number == MAX_PLAYS) {
      tie = true;
      tie_count++;
      cout << "Tie game! No one wins!" << endl;
    }
}

void output_scoreboard(string game_board[])
{
	// outputs scoreboard with formatting
    for (int i = 0; i < 16; i++)
	{
		cout << game_board[i] << "\t";
		
        if ((i + 1) % 4 == 0)
		{
			cout << endl;
		}
	}
}

void execute_tictactoe()
{
	// declare and initialize variables
    int input = 0;                 
    bool x_winner = false;
    bool o_winner = false;
    bool x_starts = false;
    bool o_starts = false;
    int game_number = 0;
    int x_wins = 0;
    int o_wins = 0;
	string play_again;
    bool keep_playing = true;
    bool tie = false;
    int tie_count = 0;
    const int MAX_PLAYS = 16;
    int play_number = 0;

	// processing various rounds of tictactoe game
	do
	{
    // increment the game number by one
    game_number++;

		// reset variables for next round
		x_winner = false;
		o_winner = false;
    tie = false;
    x_starts = false;
    o_starts = false;
		play_again = "Y";
		string game_board[16] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
    play_number = 0;

    // determine who starts first 
    if (game_number % 2 == 0) {
      o_starts = true;
    } else {
      x_starts = true;
    }

		while (!x_winner && !o_winner && !tie)
		{
			// get input from player X
      if (x_starts) {
			cout << "Player X, please enter a number from 1-16." << endl;
			get_and_verify_input(input, game_board);
      play_number++;
			
            game_board[input - 1] = "X";

			// output formatted array 
			output_scoreboard(game_board);
			check_if_winner(game_board, x_winner, o_winner, x_wins, o_wins, MAX_PLAYS, play_number, tie, tie_count);
			if (x_winner || o_winner || tie)
			{
				break;
			}

			// get input from player O
			cout << "Player O, please enter a number from 1-16." << endl;
			get_and_verify_input(input, game_board);
      play_number++;

			game_board[input - 1] = "O";

			// output formatted array 
			output_scoreboard(game_board);
			check_if_winner(game_board, x_winner, o_winner, x_wins, o_wins, MAX_PLAYS, play_number, tie, tie_count);
      } else if (o_starts) {
        cout << "Player O, please enter a number from 1-16." << endl;
			get_and_verify_input(input, game_board);
      play_number++;

			game_board[input - 1] = "O";

			// output formatted array 
			output_scoreboard(game_board);
			check_if_winner(game_board, x_winner, o_winner, x_wins, o_wins, MAX_PLAYS, play_number, tie, tie_count);
      if (x_winner || o_winner || tie)
			{
				break;
			}
      cout << "Player X, please enter a number from 1-16." << endl;
			get_and_verify_input(input, game_board);
			play_number++;
      
            game_board[input - 1] = "X";

			// output formatted array 
			output_scoreboard(game_board);
			check_if_winner(game_board, x_winner, o_winner, x_wins, o_wins, MAX_PLAYS, play_number, tie, tie_count);
      }
		}

		// output results of the round
        cout << "\nScore:" << endl;
		cout << "Player X won: " << x_wins << " times" << endl;
		cout << "Player O won: " << o_wins << " times" << endl;
    cout << "Tie games: " << tie_count << endl;
		
		// input: ask if users want to replay
		cout << "Do you want to play again? Y/N" << endl;
		cin >> play_again;

		if (play_again.compare("N") == 0 || play_again.compare("n") == 0)
		{
			keep_playing = false;
		}
	} while (keep_playing);
}

int main() {
	execute_tictactoe(); // executes tictactoe game function
}
