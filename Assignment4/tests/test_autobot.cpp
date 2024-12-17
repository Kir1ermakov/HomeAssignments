#include <gtest/gtest.h>
#include <cstdio>
#include "../src/gun.h"
#include "../src/heart.h"
#include "../src/autobot.h"


class AutobotTest : public ::testing::Test
{
protected:
    Gun gun;
    Heart heart;
    Autobot autobot;

    AutobotTest() : autobot(&gun, heart) {}
};

TEST_F(AutobotTest, InitialValues)
{
    EXPECT_EQ(autobot.getCountFriends(), 0);
    EXPECT_EQ(autobot.getHumanity(), 10);
}

TEST_F(AutobotTest, MakeFriends)
{
    autobot.makeFriends();
    EXPECT_EQ(autobot.getCountFriends(), 1);
    EXPECT_EQ(autobot.getHumanity(), 11);
    EXPECT_EQ(autobot.getHealth(), 110);
}

TEST_F(AutobotTest, SetCountFriends)
{
    autobot.setCountFriends(5);
    EXPECT_EQ(autobot.getCountFriends(), 5);
}

TEST_F(AutobotTest, SetHumanity)
{
    autobot.setHumanity(15);
    EXPECT_EQ(autobot.getHumanity(), 15);
}

TEST_F(AutobotTest, CompareAutobots)
{
    Gun gun;
    Heart heart;

    Autobot a1(&gun, heart);
    Autobot a2(&gun, heart);

    a1.setHealth(150);
    a2.setHealth(100);

    EXPECT_TRUE(a1 > a2);
    EXPECT_FALSE(a2 > a1);
}