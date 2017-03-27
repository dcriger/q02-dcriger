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

