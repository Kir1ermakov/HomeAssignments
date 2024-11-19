#include <gtest/gtest.h>
#include "gun.h"
#include "heart.h"
#include "autobot.h"
#include <cstdio>

class AutobotTest : public ::testing::Test {
protected:
    Gun gun;
    Heart heart;
    Autobot autobot;

    AutobotTest() : autobot(&gun, heart) {}
};

TEST_F(AutobotTest, InitialValues) {
    EXPECT_EQ(autobot.getCountFriends(), 0);
    EXPECT_EQ(autobot.getHumanity(), 10);
}

TEST_F(AutobotTest, MakeFriends) {
    autobot.makeFriends();
    EXPECT_EQ(autobot.getCountFriends(), 1);
    EXPECT_EQ(autobot.getHumanity(), 11);
    EXPECT_EQ(autobot.getHealth(), 110); 
}

TEST_F(AutobotTest, SetCountFriends) {
    autobot.setCountFriends(5);
    EXPECT_EQ(autobot.getCountFriends(), 5);
}

TEST_F(AutobotTest, SetHumanity) {
    autobot.setHumanity(15);
    EXPECT_EQ(autobot.getHumanity(), 15);
}
