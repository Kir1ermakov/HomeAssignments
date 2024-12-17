#include <gtest/gtest.h>
#include <cstdio>
#include "../src/gun.h"
#include "../src/heart.h"
#include "../src/transformer.h"

class TransformerTest : public ::testing::Test
{
protected:
    Gun gun;
    Heart heart;
    Transformer transformer;

    TransformerTest() : transformer(&gun, heart) {}
};

TEST_F(TransformerTest, InitialValues)
{
    EXPECT_EQ(transformer.getHealth(), 100);
    EXPECT_EQ(transformer.getEnergy(), 50);
    EXPECT_EQ(transformer.getDamage(), 40);
    EXPECT_EQ(transformer.getLuck(), 5);
}

TEST_F(TransformerTest, SetHealth)
{
    transformer.setHealth(80);
    EXPECT_EQ(transformer.getHealth(), 80);
}

TEST_F(TransformerTest, SetEnergy)
{
    transformer.setEnergy(60);
    EXPECT_EQ(transformer.getEnergy(), 60);
}

TEST_F(TransformerTest, SetDamage)
{
    transformer.setDamage(50);
    EXPECT_EQ(transformer.getDamage(), 50);
}

TEST_F(TransformerTest, SetLuck)
{
    transformer.setLuck(10);
    EXPECT_EQ(transformer.getLuck(), 10);
}

TEST_F(TransformerTest, TakeDamage)
{
    transformer.takeDamage();
    EXPECT_EQ(transformer.getHealth(), 99);

    for (int i = 0; i < 99; ++i)
    {
        transformer.takeDamage();
    }
    EXPECT_FALSE(transformer.takeDamage());
}

TEST_F(TransformerTest, Shock)
{
    transformer.shock();
    EXPECT_EQ(transformer.getEnergy(), 49);

    for (int i = 0; i < 50; ++i)
    {
        transformer.shock();
    }
    EXPECT_FALSE(transformer.shock());
}

TEST_F(TransformerTest, CompareAutobots)
{
    Gun gun;
    Heart heart;

    Transformer t1(&gun, heart);
    Transformer t2(&gun, heart);

    t1.setHealth(150);
    t2.setHealth(100);

    EXPECT_TRUE(t1 > t2);
    EXPECT_FALSE(t2 > t1);
}

