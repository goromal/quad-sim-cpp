#include <yaml-cpp/yaml.h>
#include <boost/program_options.hpp>
#include <iostream>

#include "quad-sim-cpp/QuadSim.h"

int main(int argc, char* argv[])
{
    boost::program_options::options_description args_desc("Options");
    // clang-format off
    args_desc.add_options()
        ("help,h", "print usage")
        ("config,c", boost::program_options::value<std::string>(), "Configuration YAML file path.");
    // clang-format on

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, args_desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << args_desc << std::endl;
        return 0;
    }

    quadsim::QuadSimConfig quadSimCfg;

    if (vm.count("config"))
    {
        std::cout << "Loading config from file: " << vm["config"].as<std::string>() << std::endl;
        YAML::Node config = YAML::LoadFile(vm["config"].as<std::string>());

        if (config["init"]["pos"]["x"])
        {
            quadSimCfg.px0 = config["init"]["pos"]["x"].as<double>();
        }
        if (config["init"]["pos"]["y"])
        {
            quadSimCfg.py0 = config["init"]["pos"]["y"].as<double>();
        }
        if (config["init"]["pos"]["z"])
        {
            quadSimCfg.pz0 = config["init"]["pos"]["z"].as<double>();
        }
        if (config["init"]["att"]["w"])
        {
            quadSimCfg.qw0 = config["init"]["att"]["w"].as<double>();
        }
        if (config["init"]["att"]["x"])
        {
            quadSimCfg.qx0 = config["init"]["att"]["x"].as<double>();
        }
        if (config["init"]["att"]["y"])
        {
            quadSimCfg.qy0 = config["init"]["att"]["y"].as<double>();
        }
        if (config["init"]["att"]["z"])
        {
            quadSimCfg.qz0 = config["init"]["att"]["z"].as<double>();
        }
        if (config["init"]["vel"]["x"])
        {
            quadSimCfg.vx0 = config["init"]["vel"]["x"].as<double>();
        }
        if (config["init"]["vel"]["y"])
        {
            quadSimCfg.vy0 = config["init"]["vel"]["y"].as<double>();
        }
        if (config["init"]["vel"]["z"])
        {
            quadSimCfg.vz0 = config["init"]["vel"]["z"].as<double>();
        }
        if (config["init"]["omg"]["x"])
        {
            quadSimCfg.wx0 = config["init"]["omg"]["x"].as<double>();
        }
        if (config["init"]["omg"]["y"])
        {
            quadSimCfg.wy0 = config["init"]["omg"]["y"].as<double>();
        }
        if (config["init"]["omg"]["z"])
        {
            quadSimCfg.wz0 = config["init"]["omg"]["z"].as<double>();
        }
    }

    std::cout << "Initializing Quadrotor Simulation with config:\n\n" << quadSimCfg << std::endl;

    quadsim::QuadSim sim(quadSimCfg);

    return 0;
}
