#ifndef ROBOT_H
#define ROBOT_H

#include <cmath>

const double WHEEL_RADIUS = 0.05; 
const double WHEEL_BASE = 0.15;   
const double DT = 0.1;            

struct RobotState {
    double x;
    double y;
    double theta;
    double wl;
    double wr;
};

inline void updateRobot(RobotState &state) {
    double v = (WHEEL_RADIUS / 2.0) * (state.wr + state.wl);
    double w = (WHEEL_RADIUS / WHEEL_BASE) * (state.wr - state.wl);

    state.x += v * cos(state.theta) * DT;
    state.y += v * sin(state.theta) * DT;
    state.theta += w * DT;

    if (state.theta > M_PI) state.theta -= 2 * M_PI;
    if (state.theta < -M_PI) state.theta += 2 * M_PI;
}

#endif