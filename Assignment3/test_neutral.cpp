#include <gtest/gtest.h>
#include "gun.h"
#include "heart.h"
#include "neutral.h"
#include <cstdio>
class NeutralTest : public ::testing::Test {
protected:
    Gun gun;
    Heart heart;
    Neutral neutral;

    NeutralTest() : neutral(&gun, heart) {}
};

TEST_F(NeutralTest, InitialValues) {
    EXPECT_EQ(neutral.getCountFriends(), 0);
    EXPECT_EQ(neutral.getCountEnemies(), 0);
    EXPECT_EQ(neutral.getHumanity(), 0);
    EXPECT_EQ(neutral.getAgression(), 0);
}

TEST_F(NeutralTest, MakeFriends) {
    neutral.makeFriends();
    EXPECT_EQ(neutral.getCountFriends(), 1);
    EXPECT_EQ(neutral.getHumanity(), 1);
    EXPECT_EQ(neutral.getHealth(), 110);
}

TEST_F(NeutralTest, MakeEnemies) {
    neutral.makeEnemies();
    EXPECT_EQ(neutral.getCountEnemies(), 1);
    EXPECT_EQ(neutral.getAgression(), 1);
    EXPECT_EQ(neutral.getHealth(), 95);
    EXPECT_EQ(neutral.getDamage(), 55);
}

TEST_F(NeutralTest, SetCountFriends) {
    neutral.setCountFriends(5);
    EXPECT_EQ(neutral.getCountFriends(), 5);
}

TEST_F(NeutralTest, SetCountEnemies) {
    neutral.setCountEnemies(3);
    EXPECT_EQ(neutral.getCountEnemies(), 3);
}

TEST_F(NeutralTest, SetHumanity) {
    neutral.setHumanity(5);
    EXPECT_EQ(neutral.getHumanity(), 5);
}

TEST_F(NeutralTest, SetAgression) {
    neutral.setAgression(10);
    EXPECT_EQ(neutral.getAgression(), 10);
}
