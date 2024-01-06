#include "quadsim/QuadSim.h"

#define LOAD_CONFIG_FIELD(VAR, VAL)                                                                                    \
    {                                                                                                                  \
        if (VAL)                                                                                                       \
        {                                                                                                              \
            VAR = VAL.as<double>();                                                                                    \
        }                                                                                                              \
    }

namespace quadsim
{

QuadSimConfig::QuadSimConfig(const std::string& configFilePath)
{
    YAML::Node config = YAML::LoadFile(configFilePath);

    LOAD_CONFIG_FIELD(inertialParams.m, config["inertia"]["m"])
    LOAD_CONFIG_FIELD(inertialParams.J(0, 0), config["inertia"]["J"]["x"]["x"])
    LOAD_CONFIG_FIELD(inertialParams.J(0, 1), config["inertia"]["J"]["x"]["y"])
    LOAD_CONFIG_FIELD(inertialParams.J(0, 2), config["inertia"]["J"]["x"]["z"])
    LOAD_CONFIG_FIELD(inertialParams.J(1, 0), config["inertia"]["J"]["y"]["x"])
    LOAD_CONFIG_FIELD(inertialParams.J(1, 1), config["inertia"]["J"]["y"]["y"])
    LOAD_CONFIG_FIELD(inertialParams.J(1, 2), config["inertia"]["J"]["y"]["z"])
    LOAD_CONFIG_FIELD(inertialParams.J(2, 0), config["inertia"]["J"]["z"]["x"])
    LOAD_CONFIG_FIELD(inertialParams.J(2, 1), config["inertia"]["J"]["z"]["y"])
    LOAD_CONFIG_FIELD(inertialParams.J(2, 2), config["inertia"]["J"]["z"]["z"])
    LOAD_CONFIG_FIELD(inertialParams.g(0), config["inertia"]["g"]["x"])
    LOAD_CONFIG_FIELD(inertialParams.g(1), config["inertia"]["g"]["y"])
    LOAD_CONFIG_FIELD(inertialParams.g(2), config["inertia"]["g"]["z"])
    LOAD_CONFIG_FIELD(px0, config["init"]["pos"]["x"])
    LOAD_CONFIG_FIELD(py0, config["init"]["pos"]["y"])
    LOAD_CONFIG_FIELD(pz0, config["init"]["pos"]["z"])
    LOAD_CONFIG_FIELD(qw0, config["init"]["att"]["w"])
    LOAD_CONFIG_FIELD(qx0, config["init"]["att"]["x"])
    LOAD_CONFIG_FIELD(qy0, config["init"]["att"]["y"])
    LOAD_CONFIG_FIELD(qz0, config["init"]["att"]["z"])
    LOAD_CONFIG_FIELD(vx0, config["init"]["vel"]["x"])
    LOAD_CONFIG_FIELD(vy0, config["init"]["vel"]["y"])
    LOAD_CONFIG_FIELD(vz0, config["init"]["vel"]["z"])
    LOAD_CONFIG_FIELD(wx0, config["init"]["omg"]["x"])
    LOAD_CONFIG_FIELD(wy0, config["init"]["omg"]["y"])
    LOAD_CONFIG_FIELD(wz0, config["init"]["omg"]["z"])
}

QuadSim::QuadSim(const QuadSimConfig& cfg) : mCfg(cfg)
{
    mSys.setParams(cfg.inertialParams);
    // ^^^^ TODO initialize states
}

} // end namespace quadsim
