#pragma once

#include <Eigen/Core>
#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace quadsim
{

struct QuadSimConfig
{
    QuadSimConfig() {}
    QuadSimConfig(const std::string& configFilePath);

    double px0 = 0;
    double py0 = 0;
    double pz0 = 0;

    double qw0 = 1;
    double qx0 = 0;
    double qy0 = 0;
    double qz0 = 0;

    double vx0 = 0;
    double vy0 = 0;
    double vz0 = 0;

    double wx0 = 0;
    double wy0 = 0;
    double wz0 = 0;
};

inline std::ostream& operator<<(std::ostream& os, const QuadSimConfig& cfg)
{
    os << "x0:" << std::endl
       << "\tp: [" << cfg.px0 << ", " << cfg.py0 << ", " << cfg.pz0 << "]\n\tq: [" << cfg.qw0 << ", " << cfg.qx0 << ", "
       << cfg.qy0 << ", " << cfg.qz0 << "]\n\tv: [" << cfg.vx0 << ", " << cfg.vy0 << ", " << cfg.vz0 << "]\n\tw: ["
       << cfg.wx0 << ", " << cfg.wy0 << ", " << cfg.wz0 << "]\n";
    return os;
}

class QuadSim
{
public:
    QuadSim() : mCfg(QuadSimConfig()) {}
    QuadSim(const QuadSimConfig& cfg) : mCfg(cfg) {}

private:
    QuadSimConfig mCfg;
};

} // end namespace quadsim
