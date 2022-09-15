#include <Arduino.h>
char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char computer = 'C';
char player = 'P';

void print_board()
{
  printf("\n\t\t%c\t%c\t%c\n", board[0], board[1], board[2]);
  printf("\n\t\t%c\t%c\t%c\n", board[3], board[4], board[5]);
  printf("\n\t\t%c\t%c\t%c\n", board[6], board[7], board[8]);
}
void reset_board()
{
  for (int i = 0; i < 9; i++)
  {
    board[i] = '-';
  }
}
bool check_winner()
{
  bool winner = false;

  // checking the rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != ' ')
  {
    winner = true;
  }
  else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != ' ')
  {
    winner = true;
  }

  else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != ' ')
  {
    winner = true;
  }

  // checking the columns

  else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != ' ')
  {
    winner = true;
  }

  else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != ' ')
  {
    winner = true;
  }

  else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != ' ')
  {
    winner = true;
  }

  // checking the diagonals

  else if ((board[0] == board[4]) && (board[4] == board[8]) && board[0] != ' ')
  {
    winner = true;
  }

  else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != ' ')
  {
    winner = true;
  }

  return winner;
}
int userInput()
{ // user input from Serial monitor
  int data;
  Serial.flush();
  // long t = millis();
  while (!Serial.available())
  {
    // if (millis() - t > 1000)
    // {
    //   t = millis();
    //   Serial.println("!");
    // }
  }
  String str = "";
  while (Serial.available())
  {
    char c = Serial.read();
    if (c == '\n')
      break;
    str += c;
  }
  Serial.println(str);
  data = str.toInt(); // Read integer type data
  return data;
}
bool filled_up()
{
  bool filled = true;

  for (int i = 0; i < 9; i++)
  {
    if (board[i] == ' ')
    {
      filled = false;
    }
  }

  return filled;
}
void player_move()
{
  int x;
  while (board[x] != ' ')
  {
    printf("\nEnter your Number(1---9): ");
    x = userInput();
    x--; // 0---8
    Serial.println(x);

    if (board[x] != ' ')
    {
      printf("Invalid number!, Please Try Again: \n"); // return this, for putting out of the limit of the number
    }
    else
    {
      board[x] = player; // return "%" at the relevant section, for within the limit of the number
      break;
    }
  }
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  player_move();
  print_board();
 
  // delay(1000);
  // print_board();
  // reset_board();
  // print_board();
  // while (1)
  //   ;
}