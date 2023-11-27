#include "quad-sim-cpp/QuadSim.h"

std::string getHelloWorld(const std::string& name, const bool& exclaim)
{
    return std::string("Hello, ") + name + std::string((exclaim) ? "!" : ".");
}
