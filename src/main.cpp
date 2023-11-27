#include <boost/program_options.hpp>
#include <iostream>

#include "../include/quad-sim-cpp/QuadSim.h"

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
        quadSimCfg = quadsim::QuadSimConfig(vm["config"].as<std::string>());
    }

    std::cout << "Initializing Quadrotor Simulation with config:\n\n" << quadSimCfg << std::endl;

    quadsim::QuadSim sim(quadSimCfg);

    return 0;
}
