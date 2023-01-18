#pragma once
const int MAX_USERNAME_SIZE = 12;
const int MAX_PASSWORD_SIZE = 16;
const int MIN_USERNAME_SIZE = 5;
const int MIN_PASSWORD_SIZE = 7;
const char DRAWING_DIR[] = "files/Drawings";
const char SOLUTION_DIR[] = "files/Levels";
static char * difficulty;
static int countOfLives = -1;
static char** drawing;
static char** solution;
const char LIST_OF_LEVELS[10][10] = { "Beginner1","Beginner2", "Easy1","Easy2","Medium1","Medium2" ,"Hard1" ,"Hard2","Expert1","Expert2" };
static int rowIndex = -1;
static int colIndex = -1;
