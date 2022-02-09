#include"pch.h"
#include"../Asteroids/PlayerController.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(PlayerController, RotationWrapsAroundLeft) {
	PlayerController p;

	for (int i = 0; i < 361; i++)
	{
		p.rotateLeft();
	}

	EXPECT_EQ(p.returnRotation(), 1);
}