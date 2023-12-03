#include "quadsim/QuadSim.h"

namespace quadsim
{

QuadSimConfig::QuadSimConfig(const std::string& configFilePath)
{
    YAML::Node config = YAML::LoadFile(configFilePath);

    if (config["init"]["pos"]["x"])
    {
        px0 = config["init"]["pos"]["x"].as<double>();
    }
    if (config["init"]["pos"]["y"])
    {
        py0 = config["init"]["pos"]["y"].as<double>();
    }
    if (config["init"]["pos"]["z"])
    {
        pz0 = config["init"]["pos"]["z"].as<double>();
    }
    if (config["init"]["att"]["w"])
    {
        qw0 = config["init"]["att"]["w"].as<double>();
    }
    if (config["init"]["att"]["x"])
    {
        qx0 = config["init"]["att"]["x"].as<double>();
    }
    if (config["init"]["att"]["y"])
    {
        qy0 = config["init"]["att"]["y"].as<double>();
    }
    if (config["init"]["att"]["z"])
    {
        qz0 = config["init"]["att"]["z"].as<double>();
    }
    if (config["init"]["vel"]["x"])
    {
        vx0 = config["init"]["vel"]["x"].as<double>();
    }
    if (config["init"]["vel"]["y"])
    {
        vy0 = config["init"]["vel"]["y"].as<double>();
    }
    if (config["init"]["vel"]["z"])
    {
        vz0 = config["init"]["vel"]["z"].as<double>();
    }
    if (config["init"]["omg"]["x"])
    {
        wx0 = config["init"]["omg"]["x"].as<double>();
    }
    if (config["init"]["omg"]["y"])
    {
        wy0 = config["init"]["omg"]["y"].as<double>();
    }
    if (config["init"]["omg"]["z"])
    {
        wz0 = config["init"]["omg"]["z"].as<double>();
    }
}

QuadSim::QuadSim(const QuadSimConfig& cfg) : mCfg(cfg)
{
    // ^^^^ TODO initialize model
}

} // end namespace quadsim
