#include <boost/test/unit_test.hpp>
#include "quadsim/QuadSim.h"

BOOST_AUTO_TEST_SUITE(TestExample)

BOOST_AUTO_TEST_CASE(TestConfigLoading)
{
    quadsim::QuadSimConfig cfg("test.yaml");
    std::cout << cfg << std::endl;
    BOOST_CHECK_CLOSE(cfg.px0, 4.0, 1e-3);
    BOOST_CHECK_CLOSE(cfg.py0, 2.0, 1e-3);
    // BOOST_CHECK_CLOSE(cfg.)
}

BOOST_AUTO_TEST_SUITE_END()