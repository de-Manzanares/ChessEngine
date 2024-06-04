#include <catch2/catch_all.hpp>
#include <iostream>
#include "../src/Board.hpp"
#include "../src/tree.hpp"
#include "../src/search.hpp"

double neg_inf = -std::numeric_limits<double>::infinity();
double pos_inf = std::numeric_limits<double>::infinity();

// TODO there is something wrong with my tree generation... it is taking too long...

TEST_CASE("search")
{
    SECTION("mate in one") {
        Node n("6k1/2R5/6K1/8/8/8/8/8 w - - 0 1");
        n.spawn(1);                                 // we need to get the nodes to stop spawning if game is over
        CHECK(min_max(&n, 1, neg_inf, pos_inf, true) == 1000);        // found the mate in one
    }SECTION("mate in two") {
        Node n("8/6k1/1R6/2R3K1/8/8/8/8 w - - 0 1");
        n.spawn(4);
        CHECK(min_max(&n, 4, neg_inf, pos_inf, true) == 1000);        // found the mate in two
    }SECTION("mate in three") {                     // too slow
        Node n("8/8/6k1/2R5/1R4K1/8/8/8 w - - 0 1");
        n.spawn(5);
        CHECK(min_max(&n, 5, neg_inf, pos_inf, true) == 1000);        // found the mate in three
    }
}