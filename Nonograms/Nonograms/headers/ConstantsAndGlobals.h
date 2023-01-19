#pragma once
const int MAX_USERNAME_SIZE = 12;
const int MAX_PASSWORD_SIZE = 16;
const int MIN_USERNAME_SIZE = 5;
const int MIN_PASSWORD_SIZE = 7;
const int MAX_DIR_SIZE = 50;
const char DIR_DRAWING[] = "files/Drawings";
const char DIR_SOLUTION[] = "files/Levels";
const char DIR_LAST_ATTEPMTS[] = "files/LastAttempts";
const char* LIST_OF_DIFFICULTIES[5] = { "Beginner","Easy","Medium","Hard","Expert" };
const char* LIST_OF_LEVELS[10] = { "Beginner1","Beginner2", "Easy1","Easy2","Medium1","Medium2" ,"Hard1" ,"Hard2","Expert1","Expert2" };
const char* LIST_OF_STARTING_COMANDS[3] = { "/close ends your session","/register <username> <password> - Creates an account (Username must be at least 5 symbols long! Password must be at least 7 symbols long!)","/login <username> <password> - Log in your account" };
const char* LIST_OF_OFFGAME_COMANDS[5] = { "/close ends your session","/last - Loads your last attempt","/levels - Shows a list of all your availavle levels","/load <level_name> - Starts the chosen level (this will start the level from the beginning)","/exit - Logs out of your profile"};
const char* LIST_OF_INGAME_COMANDS[4] = {"/close ends your session", "/guess <row_num> <col_num> <'full/empty'> - Specify if a cell is full or empty","/save - saves your current progress on this level (note that this command will delete your last save)", "/exit - exits and saves your progress. This comand will log you out of your profile" };
const char* MESSAGE_INVALID_COMAND = "You have entered an invalid command or invalid number of arguments!";
const char* MESSAGE_NO_PERMISSION = "You can't use this comand right now";
const char* MESSAGE_INVALID_LEVEL = "This level does not exist!";
const char* MESSAGE_LOGOUT = "You logged out of your profile!";
const char* MESSAGE_SUCCESSFULL_SAVE = "You saved your progress successfully!";
const char* MESSAGE_GOODBYE = "Thank you for playing Nonograms by Angel Momov";
const char* MESSAGE_WELCOME = "Welcome to Nonograms by Angel Momov. Type /help for more info";
char** drawing;
char** solution;
char* logged;
char* level;
char* difficulty;
int columns = -1;
int rows = -1;
int countOfLives = -1;
int rowIndex = -1;
int colIndex = -1;
int matrixSize = -1;
bool isLogged = false;
bool inGame = false;
