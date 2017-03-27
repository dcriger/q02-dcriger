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

TEST(PiezasTest, blankBoard)
{
    Piece board[3][4];
    int count = 0;

    board.reset();

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == Blank)
            {
                count++;
            }
        }
    }
    ASSERT_EQ(count, 12);
}