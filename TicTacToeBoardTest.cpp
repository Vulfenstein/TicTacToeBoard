/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, oneTurn)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, twoTurns)
{
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, outsideRowLower)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(-10, 0), Invalid);
}

TEST(TicTacToeBoardTest, outsideRowUpper)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(10, 0), Invalid);
}

TEST(TicTacToeBoardTest, outsideColumnLower)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, -10), Invalid);
}

TEST(TicTacToeBoardTest, outsideColumnUpper)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 10), Invalid);
}

TEST(TicTacToeBoardTest, placeSinglePiece)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placeTwoPiece)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), X);
  ASSERT_EQ(board.placePiece(0, 1), O);
}

TEST(TicTacToeBoardTest, placeTwice)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), X);
  ASSERT_EQ(board.placePiece(0, 0), X);
  ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, getBlank)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, getOutsideRowLower)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(-10, 0), Invalid);
}

TEST(TicTacToeBoardTest, getOutsideRowUpper)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(10, 0), Invalid);
}

TEST(TicTacToeBoardTest, getOutsideColumnLower)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, -10), Invalid);
}

TEST(TicTacToeBoardTest, getOutsideColumnUpper)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0, 10), Invalid);
}

TEST(TicTacToeBoardTest, getNonWinner)
{
  TicTacToeBoard board;
  ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, winHorizontal)
{
  TicTacToeBoard board;
  board.placePiece(1, 0);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(1, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, winVertical)
{
  TicTacToeBoard board;
  board.placePiece(0, 1);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(2, 1);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, winDiagonalTop)
{
  TicTacToeBoard board;
  board.placePiece(0, 0);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(2, 2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, winDiagonalBottom)
{
  TicTacToeBoard board;
  board.placePiece(2, 0);
  board.toggleTurn();
  board.placePiece(1, 1);
  board.toggleTurn();
  board.placePiece(0, 2);
  ASSERT_EQ(board.getWinner(), X);
}
