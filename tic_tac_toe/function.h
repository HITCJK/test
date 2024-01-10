void play(char chessBoard[3][3], void (*mode)(char chessBoard[3][3]));
int judgeWinner(char chessBoard[3][3], char P);
int heqi(char chessBoard[3][3]);
void simpleMode(char chessBoard[3][3]);
void masterMode(char chessBoard[3][3]);
void player(char chessBoard[3][3]);
void listChessBoard(char chessBoard[3][3]);
int getscore(char chessBoard[3][3], char player, int X, int O);