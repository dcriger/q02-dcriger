/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
    protected:
        PiezasTest(){} //constructor runs before each test
        virtual ~PiezasTest(){} //destructor cleans up after tests
        virtual void SetUp(){} //sets up before each test (after constructor)
        virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
    ASSERT_TRUE(true);
}

TEST(PiezasTest, getBlank)
{
    Piezas game;
    Piece piece;
    piece = game.pieceAt(0,0);

    ASSERT_EQ(piece, Blank);
}

TEST(PiezasTest, getOutOfBounds)
{
    Piezas game;

    ASSERT_EQ(Invalid, game.pieceAt(1,5));
}

TEST(PiezasTest, blankBoard)
{
    Piezas game;
    int count = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(game.pieceAt(i,j) == Blank)
            {
                count++;
            }
        }
    }
    ASSERT_EQ(count, 12);
}

TEST(PiezasTest, placeFirstX)
{
    Piezas game;
    Piece confirm;

    confirm = game.dropPiece(2);

    ASSERT_EQ(confirm, game.pieceAt(2,2));
}

TEST(PiezasTest, fullRowXWin)
{
    Piezas game;
    Piece piece;

    piece = game.dropPiece(0);  //x
    piece = game.dropPiece(0);  //o
    piece = game.dropPiece(1);  //x
    piece = game.dropPiece(1);  //o
    piece = game.dropPiece(2);  //x
    piece = game.dropPiece(0);  //o
    piece = game.dropPiece(3);  //x
    piece = game.dropPiece(3);  //o
    piece = game.dropPiece(2);  //x
    piece = game.dropPiece(1);  //o
    piece = game.dropPiece(2);  //x
    piece = game.dropPiece(3);  //o

    piece = game.gameState();

    ASSERT_EQ(piece, X);
}

TEST(PiezasTest, toggleTurn)
{
    Piezas game;
    Piece piece;

    piece = game.dropPiece(0);
    piece = game.dropPiece(0);

    ASSERT_EQ(piece, O);
}