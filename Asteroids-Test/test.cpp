#include"pch.h"
#include"../Asteroids/PlayerController.h"
//#include"../Asteroids/BulletPool.h"

// BEN 1
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(PlayerController, RotationWorksLeft) {
	PlayerController p;
	// Roatate speed = 5
	for (int i = 0; i < 72; i++)
	{
		p.rotateLeft();
	}

	EXPECT_EQ(p.returnRotation(), 0);
}
TEST(PlayerController, RotationWorksRight) {
	PlayerController p;
	// Roatate speed = 5
	for (int i = 0; i < 72; i++)
	{
		p.rotateRight();
	}

	EXPECT_EQ(p.returnRotation(), 360);
}

TEST(PlayerController, RotationWrapsAroundRight) {
	PlayerController p;
	// Roatate speed = 5
	for (int i = 0; i < 73; i++)
	{
		p.rotateRight();
	}

	EXPECT_EQ(p.returnRotation(), 5);
}

TEST(PlayerController, SpeedCaps) {
	PlayerController p;
	// Max speed = 300
	for (int i = 0; i < 100; i++)
	{
		p.acceleration();
	}

	EXPECT_EQ(p.returnSpeed(), 300);
}

TEST(PlayerController, SpeedDecreases) {
	PlayerController p;
	// Max speed = 300
	for (int i = 0; i < 100; i++)
	{
		p.acceleration();
	}

	for (int i = 0; i < 1000; i++)
	{
		p.update(1.0f / 60.0f);
	}

	EXPECT_EQ(p.returnSpeed(), 0);
}

TEST(PlayerController, ItMovesXAxis) {
	PlayerController p;
	// Start 400,300
	// Accelorate speed = 20
	p.acceleration();
	p.acceleration();

	p.update(1);
	EXPECT_NE(p.returnXpos(), 400);
	EXPECT_EQ(p.returnYpos(), 300);
}

TEST(PlayerController, ItMovesYAxis) {
	PlayerController p;
	// Start 400,300
	// Accelorate speed = 20
	for (int i = 0; i < 90; i++)
	{
		p.rotateLeft();
	}
	p.acceleration();
	p.acceleration();

	p.update(1);

	EXPECT_EQ(p.returnXpos(), 400);
	EXPECT_NE(p.returnYpos(), 300);
}

// BEN 2
/*
TEST(BulletPool, SpamFire) {
	BulletPool pool;
	pool.fire(NULL);

	EXPECT_TRUE(pool.fire(NULL));
	EXPECT_FALSE(pool.fire(NULL));
}
*/