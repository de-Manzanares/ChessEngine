#include <catch2/catch_all.hpp>
#include <iostream>
#include "../src/Board.hpp"

using s = Square;

Board board;

// little play test
// 1.d4 Nf6
// 2.c4 c6
// 3.Nc3 d5
// 4.Nf3 dxc4
// 5.a4 Bf5
// 6.Nh4 Bg4
// 7.h3 Bd7
// 8.e4 e6
// 9.Bxc4 Nxe4
// 10.Nxe4 *

std::vector<int> number_of_legal_moves = {
        0,
        20, 20,
        28, 22,
        30, 23,
        33, 31,
        34, 33,
        34, 39,
        32, 36,
        33, 27,
        40, 29,
        48, 29
};
int i = 1;
TEST_CASE("sample game")
{
    board.import_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::d2, s::d4);
    CHECK(board.export_fen() == "rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d3 0 1");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::g8, s::f6);
    CHECK(board.export_fen() == "rnbqkb1r/pppppppp/5n2/8/3P4/8/PPP1PPPP/RNBQKBNR w KQkq - 1 2");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::c2, s::c4);
    CHECK(board.export_fen() == "rnbqkb1r/pppppppp/5n2/8/2PP4/8/PP2PPPP/RNBQKBNR b KQkq c3 0 2");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::c7, s::c6);
    CHECK(board.export_fen() == "rnbqkb1r/pp1ppppp/2p2n2/8/2PP4/8/PP2PPPP/RNBQKBNR w KQkq - 0 3");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::b1, s::c3);
    CHECK(board.export_fen() == "rnbqkb1r/pp1ppppp/2p2n2/8/2PP4/2N5/PP2PPPP/R1BQKBNR b KQkq - 1 3");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::d7, s::d5);
    CHECK(board.export_fen() == "rnbqkb1r/pp2pppp/2p2n2/3p4/2PP4/2N5/PP2PPPP/R1BQKBNR w KQkq d6 0 4");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::g1, s::f3);
    CHECK(board.export_fen() == "rnbqkb1r/pp2pppp/2p2n2/3p4/2PP4/2N2N2/PP2PPPP/R1BQKB1R b KQkq - 1 4");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::d5, s::c4);
    CHECK(board.export_fen() == "rnbqkb1r/pp2pppp/2p2n2/8/2pP4/2N2N2/PP2PPPP/R1BQKB1R w KQkq - 0 5");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::a2, s::a4);
    CHECK(board.export_fen() == "rnbqkb1r/pp2pppp/2p2n2/8/P1pP4/2N2N2/1P2PPPP/R1BQKB1R b KQkq a3 0 5");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::c8, s::f5);
    CHECK(board.export_fen() == "rn1qkb1r/pp2pppp/2p2n2/5b2/P1pP4/2N2N2/1P2PPPP/R1BQKB1R w KQkq - 1 6");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::f3, s::h4);
    CHECK(board.export_fen() == "rn1qkb1r/pp2pppp/2p2n2/5b2/P1pP3N/2N5/1P2PPPP/R1BQKB1R b KQkq - 2 6");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::f5, s::g4);
    CHECK(board.export_fen() == "rn1qkb1r/pp2pppp/2p2n2/8/P1pP2bN/2N5/1P2PPPP/R1BQKB1R w KQkq - 3 7");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::h2, s::h3);
    CHECK(board.export_fen() == "rn1qkb1r/pp2pppp/2p2n2/8/P1pP2bN/2N4P/1P2PPP1/R1BQKB1R b KQkq - 0 7");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::g4, s::d7);
    CHECK(board.export_fen() == "rn1qkb1r/pp1bpppp/2p2n2/8/P1pP3N/2N4P/1P2PPP1/R1BQKB1R w KQkq - 1 8");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::e2, s::e4);
    CHECK(board.export_fen() == "rn1qkb1r/pp1bpppp/2p2n2/8/P1pPP2N/2N4P/1P3PP1/R1BQKB1R b KQkq e3 0 8");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::e7, s::e6);
    CHECK(board.export_fen() == "rn1qkb1r/pp1b1ppp/2p1pn2/8/P1pPP2N/2N4P/1P3PP1/R1BQKB1R w KQkq - 0 9");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::f1, s::c4);
    CHECK(board.export_fen() == "rn1qkb1r/pp1b1ppp/2p1pn2/8/P1BPP2N/2N4P/1P3PP1/R1BQK2R b KQkq - 0 9");

    CHECK(board.nodes_at_depth_1(Color::black) == number_of_legal_moves[i++]);
    board.move(s::f6, s::e4);
    CHECK(board.export_fen() == "rn1qkb1r/pp1b1ppp/2p1p3/8/P1BPn2N/2N4P/1P3PP1/R1BQK2R w KQkq - 0 10");

    CHECK(board.nodes_at_depth_1(Color::white) == number_of_legal_moves[i++]);
    board.move(s::c3, s::e4);
    CHECK(board.export_fen() == "rn1qkb1r/pp1b1ppp/2p1p3/8/P1BPN2N/7P/1P3PP1/R1BQK2R b KQkq - 0 10");
}