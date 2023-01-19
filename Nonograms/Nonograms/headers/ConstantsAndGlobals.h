#pragma once
const int MAX_USERNAME_SIZE = 12;
const int MAX_PASSWORD_SIZE = 16;
const int MIN_USERNAME_SIZE = 5;
const int MIN_PASSWORD_SIZE = 7;
const int MAX_DIR_SIZE = 50;
const int MAX_INPUT_SIZE = 101;
const char* RULES = "The goal of the game is to guess all the filled cells.\n In the beginning you get a matrix whith covored cells. Above every column and nex to to every row there are numbers.\n Each number tells you exactly how many filled cells are there one after another without gaps.\n You win by guessing every filled cell. Each mistake costs one life. If you run out of lives u lose.\n Good luck and think smart!\n Type /help for more info";
const char DIR_ACCOUNTS[] = "files/Accounts/Accounts.txt";
const char DIR_ACCOUNTS_COUNT[]= "files/Accounts/AccountsCount.txt";
const char DIR_DRAWING[] = "files/Drawings";
const char DIR_SOLUTION[] = "files/Levels";
const char DIR_LAST_ATTEPMTS[] = "files/LastAttempts";
const char DIR_AVAILABLE_LEVELS[] = "files/AvailableLevels";
const char GAME_OVER_LOST[] = "You ran out of lives! Game Over!";
const char* LIST_OF_DIFFICULTIES[5] = { "Beginner","Easy","Medium","Hard","Expert" };
const char* LIST_OF_LEVELS[10] = { "Beginner1","Beginner2", "Easy1","Easy2","Medium1","Medium2" ,"Hard1" ,"Hard2","Expert1","Expert2" };
const char* LIST_OF_STARTING_COMANDS[3] = { "/close - ends your session","/register <username> <password> - Creates an account (Username must be at least 5 symbols long! Password must be at least 7 symbols long!)","/login <username> <password> - Log in your account" };
const char* LIST_OF_OFFGAME_COMANDS[5] = { "/close - ends your session","/last - Loads your last attempt","/levels - Shows a list of all your availavle levels","/play <level_name> - Starts the chosen level (this will start the level from the beginning)","/exit - Logs out of your profile"};
const char* LIST_OF_INGAME_COMANDS[4] = {"/close - ends your session", "/guess <row_num> <col_num> <'full/empty'> - Specify if a cell is full or empty","/save - saves your current progress on this level (note that this command will delete your last save)", "/exit - exits and saves your progress. This comand will log you out of your profile" };
const char* MESSAGE_INVALID_COMAND = "You have entered an invalid command or invalid number of arguments!";
const char* MESSAGE_NO_PERMISSION = "You can't use this comand right now";
const char* MESSAGE_INVALID_LEVEL = "This level does not exist!";
const char* MESSAGE_LOGOUT = "You logged out of your profile!";
const char* MESSAGE_CELL_GUESSED = "This cell is already guessed!";
const char* MESSAGE_SUCCESSFULL_SAVE = "You saved your progress successfully!";
const char* MESSAGE_GOODBYE = "Thank you for playing Nonograms by Angel Momov";
const char* MESSAGE_WELCOME = "                                    =====================================\n                                   | Welcome to Nonograms by Angel Momov |\n                                    =====================================";
const char* MESSAGE_GAME_WON = "You have successfully finished level";
const char* MESSAGE_LEVEL_PERMISSION_DENIED = "You don't have access to this level yet!";
const char* MESSAGE_INDEX_OUT_OF_RANGE = "Row or column index is out of range!";
const char* MESSAGE_NO_LAST_ATTEMPTS = "You don't have any last attempts!";
char* ListOfAvailableLevels; //list of all levels available to the logged user
char** drawing; //A matrix in which is saved the progress of the playerin his level. Consists of guessed and not guessed cells.
char** solution; // A matrix in which is saved the solution of the level which the player is playing. Consists the answer to the level.
char* logged; //Username of the logged user/
char* level; //Name of the level which is played.
char* difficulty; // DIfficulty of the level which is played.
bool isLogged = false;
bool inGame = false;
//Game Propperties
int columns = -1; 
int rows = -1;
int countOfLives = -1;
int rowIndex = -1;
int colIndex = -1;
int matrixSize = -1;
