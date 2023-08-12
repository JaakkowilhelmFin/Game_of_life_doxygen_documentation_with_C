/**
 * @file game_of_life.c
 * @brief Game of Life - a simple version.
 */

/**
 * @mainpage Game of Life - Simple Version
 *
 * @section intro_sec Introduction
 * This program is a simple implementation of Conway's Game of Life, a cellular automaton simulation.
 * It evolves according to certain rules based on the initial configuration of cells.
 *
 * @section usage_sec Usage
 * - Compile: gcc -o game_of_life game_of_life.c
 * - Run: ./game_of_life
 */

/**
 * @file game_of_life.c
 * @brief Game of Life - a simple version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define ROWS 9
#define COLS 9

/* Global variables */
#define DEAD 0
#define ALIVE 1

/* Global structures */
struct cell
 {

 int current; /* current situation, which is visible on screen */

 int future; /* temporary calculation area for next round calculation */

 };

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
/**
 * @brief Initializes the game board.
 * 
 * This function sets all cells on the game board to DEAD and initializes specific cells to ALIVE.
 * 
 * @param board The game board represented as a 2D array of cells.
 * @return void
 */
int init_gameboard(struct cell board[ROWS][COLS]);


/**
 * @brief Updates the game board to the next generation based on the current state.
 * 
 * This function calculates the next generation of cells based on the current state
 * and updates the game board accordingly.
 * 
 * @param board The game board represented as a 2D array of cells.
 * @return void
 */
int update_gameboard(struct cell board[ROWS][COLS]);

/**
 * @brief Prints the game board to the console.
 * 
 * This function prints the current state of the game board to the console.
 * Alive cells are represented by '*' characters, and dead cells are represented by '.' characters.
 * 
 * @param board The game board represented as a 2D array of cells.
 * @return void
 */
void print_gameboard(struct cell board[ROWS][COLS]);


/**
 * @brief counts neighbours.
 * 
 * This function counts objects on neighbouring cells. 
 * 
 * @param board The game board represented as a 2D array of cells.
 * @return void
 */

int count_neighbors(struct cell board[ROWS][COLS], int row, int col);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/
int main() 
{
  struct cell board[ROWS][COLS];
  init_gameboard(board);
 
  int i =0; 
  print_gameboard(board);
  for (i; i < 10; i++) 
  {
    update_gameboard(board);
    print_gameboard(board);
  }
  return 0;
}
/* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: init_gameboard();
 DESCRIPTION: gives an array of the game (board)
    Input: all are zeroes. 
    Output: 
  Used global variables:struct
 REMARKS when using this function:
*********************************************************************/
 int init_gameboard(struct cell board[ROWS][COLS])
{
  int i; 
  int j; 
  for(i =0; i < ROWS; i++)
  {
    for(j=0; j < COLS; j++)
    {
        board[i][j].current = DEAD ;
        board[i][j].future = DEAD; 
        
    }
  }
  board[3][7].current = ALIVE;
  board[3][3].current = ALIVE; 
  board[5][7].current = ALIVE;
  board[1][2].current = ALIVE; 
  board[5][5].current = ALIVE;
  board[1][4].current = ALIVE;
  board[6][7].current = ALIVE;
  board[5][8].current = ALIVE;
  board[3][4].current = ALIVE; 
  board[3][5].current = ALIVE;
  board[2][5].current = ALIVE; 
  board[5][4].current = ALIVE;
  board[1][3].current = ALIVE;
  board[1][2].current = ALIVE;
}
 
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_neighbors()
 DESCRIPTION: counts the neighbors
    Input:
    Output: 
  Used global variables:struct
 REMARKS when using this function:
*********************************************************************/
int count_neighbors(struct cell board[ROWS][COLS], int row, int col)
{
  int count= 0;
  int i;
  int j; 

  for(i = -1; i <= 1; i++)
  {
    for( j= -1; j <= 1; j++)
    {
      if ( i != 0 || j !=0)
      {
        count = count + 0;
      }
      else if (board[i+row][j+col].current == 1)
      {  
        count++;
      }
    }

  }
  return count;
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int update_gameboard()
 DESCRIPTION: updates game from future situation to present
    Input:
    Output: 
  Used global variables:struct
 REMARKS when using this function:
*********************************************************************/
int update_gameboard(struct cell board[ROWS][COLS])
{
int i, j; 
int neighborhood = count_neighbors(board, i, j);
  for(i = 0;i < ROWS ; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      switch(board[i][j].current)
      {
        case ALIVE:
          if(neighborhood < 2 || neighborhood > 3)
          {
            board[i][j].future = DEAD;
          }
          else
          {
            board[i][j].future = ALIVE;
          }
          break;

        case DEAD:
          if( neighborhood == 3)
          {
            board[i][j].future = ALIVE;
          }
          else
          {
            board[i][j].future = DEAD;
          }
          break;

        default: 
          printf("invalid operation. something went wrong");
      }
    }
  }  

  for(i = 0;i < ROWS ; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      board[i][j].current = board[i][j].future; 
    }
      
  }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void print_gameboard()
 DESCRIPTION: prints gameboard to screen
    Input:
    Output: 
  Used global variables:struct
 REMARKS when using this function:
*********************************************************************/
void print_gameboard(struct cell board[ROWS][COLS])
{
  int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) 
    {
      for (j = 0; j < COLS; j++) 
      {
        if (board[i][j].current == ALIVE) 
        {
          printf("%c", '*');
        } 
        else 
        {
          printf("%c", '.');
        }
      }
        printf("\n");
    }
  printf("\n");
}