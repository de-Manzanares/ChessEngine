#include <catch2/catch_all.hpp>
#include <iostream>
#include "../src/bitboard.h"

TEST_CASE("export fen")
{
    Board board;
    std::string s;
    SECTION("starting position export") {
        CHECK(export_fen(&board) == "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    }
}

TEST_CASE("clear")
{
    Board board;
    SECTION("clear") {
        board.clear();
        CHECK(export_fen(&board) == "8/8/8/8/8/8/8/8 w - - 0 0");
    }
}

TEST_CASE("import fen")
{
    Board board;
    std::string s;
    SECTION("pos a") {
        s = "b5k1/2qn3p/p2p2pb/Np1Pp3/1P2P3/P1n2PBP/2rN4/R3QBK1 w - - 1 31";
        import_fen(&board, s);
        CHECK(export_fen(&board) == s);
    }SECTION("pos start") {
        s = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        import_fen(&board, s);
        CHECK(export_fen(&board) == s);
    }SECTION("pos en passant") {
        s = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
        import_fen(&board, s);
        CHECK(export_fen(&board) == s);
    }SECTION("castling") {
        s = "r1b1k2r/pp1nqpb1/2p1p1pp/3p4/2PP4/P1N1PN2/1P2BPPP/2RQ1RK1 b kq - 0 11";
        import_fen(&board, s);
        CHECK(export_fen(&board) == s);
    }
}

