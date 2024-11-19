#include <gtest/gtest.h>
#include "gun.h"
#include "heart.h"
#include "decepticon.h"
#include <cstdio>

class DecepticonTest : public ::testing::Test {
protected:
    Gun gun;
    Heart heart;
    Decepticon decepticon;

    DecepticonTest() : decepticon(&gun, heart) {}
};

TEST_F(DecepticonTest, InitialValues) {
    EXPECT_EQ(decepticon.getCountEnemies(), 0);
    EXPECT_EQ(decepticon.getAgression(), 10);
}

TEST_F(DecepticonTest, MakeEnemies) {
    decepticon.makeEnemies();
    EXPECT_EQ(decepticon.getCountEnemies(), 1);
    EXPECT_EQ(decepticon.getAgression(), 11);
    EXPECT_EQ(decepticon.getHealth(), 95);
    EXPECT_EQ(decepticon.getDamage(), 55);
}

TEST_F(DecepticonTest, SetCountEnemies) {
    decepticon.setCountEnemies(5);
    EXPECT_EQ(decepticon.getCountEnemies(), 5);
}

TEST_F(DecepticonTest, SetAgression) {
    decepticon.setAgression(20);
    EXPECT_EQ(decepticon.getAgression(), 20);
}
