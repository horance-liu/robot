#include "robot.h"
#include "ctrl_api.h"
#include <stddef.h>

static Robot robot;

void robot_init(uint32_t maxOrderNum, uint32_t maxPower)
{
    robot.numOfOrders = 0;
    robot.maxOrderNum = maxOrderNum;
    robot.remainPower = maxPower;
}

Status robot_push_order()
{
    if (robot.numOfOrders >= robot.maxOrderNum) {
        ctrl_report(ORDER_FULL, &robot.maxOrderNum);
        return M_FAIL;
    } else {
        robot.numOfOrders++;
        return M_OK;
    }
}

Status robot_fetch_order()
{
    if (robot.numOfOrders == 0) {
        ctrl_report(ORDER_EMPTY, &robot.maxOrderNum);        
        return M_FAIL;
    }

    robot.numOfOrders--;

    if (robot.numOfOrders == 0) {
        ctrl_report(ORDER_FINISHED, &robot.maxOrderNum);
    }

    return M_OK;
}

Status robot_exhaust(uint32_t power)
{
    if (robot.remainPower < power) {
        robot.remainPower = 0;
        ctrl_report(POWER_LOW1, &robot.remainPower);
        return M_FAIL;
    }

    robot.remainPower -= power;

    if (robot.remainPower < MIN_REMAIN_POWER) {
        ctrl_report(POWER_LOW2, &robot.remainPower);
    }

    return M_OK;
}
