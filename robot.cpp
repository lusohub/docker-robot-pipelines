#include "robot.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    RobotState robot{0.0, 0.0, 0.0, 0.0, 0.0};

    cout << "Simulador de Robot" << endl;
    cout << "Comandos: L <vel>, R <vel>, Q (sair)" << endl;

    string cmd;
    double val;

    while (true) {
        if (cin >> cmd) {
            if (cmd == "Q" || cmd == "q") {
                cout << "Adeus..." << endl;
                break;
            } else if (cmd == "L" || cmd == "l") {
                cin >> val;
                robot.wl = val;
            } else if (cmd == "R" || cmd == "r") {
                cin >> val;
                robot.wr = val;
            }
        }

        updateRobot(robot);

        cout << "Posição: x=" << robot.x << " y=" << robot.y
             << " θ=" << (robot.theta * 180.0 / M_PI) << "°" << endl;

        this_thread::sleep_for(chrono::milliseconds((int)(DT * 1000)));
    }

    return 0;
}