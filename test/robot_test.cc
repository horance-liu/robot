#include "gtest/gtest.h"
#include "robot.h"

struct RobotTest : testing::Test {
};

const uint32_t MAX_ORDER_NUM = 3;
const uint32_t MAX_POWER = 20;

TEST_F(RobotTest, robot_push_order)
{
    robot_init(MAX_ORDER_NUM, MAX_POWER);
}