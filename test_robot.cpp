#include "robot.h"
#include <gtest/gtest.h>

// Testa se o robot anda em frente corretamente
TEST(RobotTest, ForwardMotion) {
    RobotState r{0.0, 0.0, 0.0, 1.0, 1.0}; 
    updateRobot(r);
    EXPECT_GT(r.x, 0.0);
    EXPECT_NEAR(r.y, 0.0, 1e-6);
}

// Testa se o robot roda para a esquerda
TEST(RobotTest, RotateLeft) {
    RobotState r{0.0, 0.0, 0.0, 0.0, 1.0}; 
    updateRobot(r);
    EXPECT_GT(r.theta, 0.0);
}

// Testa se o robot roda para a direita
TEST(RobotTest, RotateRight) {
    RobotState r{0.0, 0.0, 0.0, 1.0, 0.0}; a
    updateRobot(r);
    EXPECT_LT(r.theta, 0.0);
}

// Testa se o robot fica parado
TEST(RobotTest, NoMotion) {
    RobotState r{0.0, 0.0, 0.0, 0.0, 0.0};
    updateRobot(r);
    EXPECT_DOUBLE_EQ(r.x, 0.0);
    EXPECT_DOUBLE_EQ(r.y, 0.0);
    EXPECT_DOUBLE_EQ(r.theta, 0.0);
}