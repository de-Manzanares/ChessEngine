#include <catch2/catch_all.hpp>
#include <iostream>
#include "../src/Board.hpp"
#include "../src/FEN.hpp"
#include "../src/Move-and-rules.hpp"

TEST_CASE("clear")
{
    Board board;
    SECTION("clear") {
        board.clear();
        CHECK(export_fen(&board) == "8/8/8/8/8/8/8/8 w - - 0 0");
    }
}

TEST_CASE("export fen")
{
    Board board;
    std::string s;
    SECTION("starting position export") {
        CHECK(export_fen(&board) == "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
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

TEST_CASE("square_to_uint()")
{
    SECTION("Test for valid inputs") {
        REQUIRE(square_to_uint("h1") == 0);
        REQUIRE(square_to_uint("g1") == 1);
        REQUIRE(square_to_uint("f1") == 2);
        REQUIRE(square_to_uint("e1") == 3);
        REQUIRE(square_to_uint("d1") == 4);
        REQUIRE(square_to_uint("c1") == 5);
        REQUIRE(square_to_uint("b1") == 6);
        REQUIRE(square_to_uint("a1") == 7);
        REQUIRE(square_to_uint("h2") == 8);
        REQUIRE(square_to_uint("g2") == 9);
        REQUIRE(square_to_uint("f2") == 10);
        REQUIRE(square_to_uint("e2") == 11);
        REQUIRE(square_to_uint("d2") == 12);
        REQUIRE(square_to_uint("c2") == 13);
        REQUIRE(square_to_uint("b2") == 14);
        REQUIRE(square_to_uint("a2") == 15);
        REQUIRE(square_to_uint("h3") == 16);
        REQUIRE(square_to_uint("g3") == 17);
        REQUIRE(square_to_uint("f3") == 18);
        REQUIRE(square_to_uint("e3") == 19);
        REQUIRE(square_to_uint("d3") == 20);
        REQUIRE(square_to_uint("c3") == 21);
        REQUIRE(square_to_uint("b3") == 22);
        REQUIRE(square_to_uint("a3") == 23);
        REQUIRE(square_to_uint("h4") == 24);
        REQUIRE(square_to_uint("g4") == 25);
        REQUIRE(square_to_uint("f4") == 26);
        REQUIRE(square_to_uint("e4") == 27);
        REQUIRE(square_to_uint("d4") == 28);
        REQUIRE(square_to_uint("c4") == 29);
        REQUIRE(square_to_uint("b4") == 30);
        REQUIRE(square_to_uint("a4") == 31);
        REQUIRE(square_to_uint("h5") == 32);
        REQUIRE(square_to_uint("g5") == 33);
        REQUIRE(square_to_uint("f5") == 34);
        REQUIRE(square_to_uint("e5") == 35);
        REQUIRE(square_to_uint("d5") == 36);
        REQUIRE(square_to_uint("c5") == 37);
        REQUIRE(square_to_uint("b5") == 38);
        REQUIRE(square_to_uint("a5") == 39);
        REQUIRE(square_to_uint("h6") == 40);
        REQUIRE(square_to_uint("g6") == 41);
        REQUIRE(square_to_uint("f6") == 42);
        REQUIRE(square_to_uint("e6") == 43);
        REQUIRE(square_to_uint("d6") == 44);
        REQUIRE(square_to_uint("c6") == 45);
        REQUIRE(square_to_uint("b6") == 46);
        REQUIRE(square_to_uint("a6") == 47);
        REQUIRE(square_to_uint("h7") == 48);
        REQUIRE(square_to_uint("g7") == 49);
        REQUIRE(square_to_uint("f7") == 50);
        REQUIRE(square_to_uint("e7") == 51);
        REQUIRE(square_to_uint("d7") == 52);
        REQUIRE(square_to_uint("c7") == 53);
        REQUIRE(square_to_uint("b7") == 54);
        REQUIRE(square_to_uint("a7") == 55);
        REQUIRE(square_to_uint("h8") == 56);
        REQUIRE(square_to_uint("g8") == 57);
        REQUIRE(square_to_uint("f8") == 58);
        REQUIRE(square_to_uint("e8") == 59);
        REQUIRE(square_to_uint("d8") == 60);
        REQUIRE(square_to_uint("c8") == 61);
        REQUIRE(square_to_uint("b8") == 62);
        REQUIRE(square_to_uint("a8") == 63);
    }
}

TEST_CASE("what_piece")
{
    Board board;
    CHECK(board.what_piece(0) == 'R');
    CHECK(board.what_piece(1) == 'N');
    CHECK(board.what_piece(2) == 'B');
    CHECK(board.what_piece(3) == 'K');
    CHECK(board.what_piece(4) == 'Q');
    CHECK(board.what_piece(5) == 'B');
    CHECK(board.what_piece(6) == 'N');
    CHECK(board.what_piece(7) == 'R');
    CHECK(board.what_piece(8) == 'P');
    CHECK(board.what_piece(9) == 'P');
    CHECK(board.what_piece(10) == 'P');
    CHECK(board.what_piece(11) == 'P');
    CHECK(board.what_piece(12) == 'P');
    CHECK(board.what_piece(13) == 'P');
    CHECK(board.what_piece(14) == 'P');
    CHECK(board.what_piece(15) == 'P');
    CHECK(board.what_piece(48) == 'p');
    CHECK(board.what_piece(49) == 'p');
    CHECK(board.what_piece(50) == 'p');
    CHECK(board.what_piece(51) == 'p');
    CHECK(board.what_piece(52) == 'p');
    CHECK(board.what_piece(53) == 'p');
    CHECK(board.what_piece(54) == 'p');
    CHECK(board.what_piece(55) == 'p');
    CHECK(board.what_piece(56) == 'r');
    CHECK(board.what_piece(57) == 'n');
    CHECK(board.what_piece(58) == 'b');
    CHECK(board.what_piece(59) == 'k');
    CHECK(board.what_piece(60) == 'q');
    CHECK(board.what_piece(61) == 'b');
    CHECK(board.what_piece(62) == 'n');
    CHECK(board.what_piece(63) == 'r');
}

TEST_CASE("attack map")
{
    Board board;
    std::vector<Square> v{};
    std::vector<Square> a{};
    SECTION("rook") {
        import_fen(&board, "8/8/8/3r4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 14);
        import_fen(&board, "8/8/3p4/2prp3/3p4/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 4);
        import_fen(&board, "8/8/8/3R4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 14);
        import_fen(&board, "8/8/3p4/2pRp3/3p4/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 4);
    }SECTION("bishop") {
        import_fen(&board, "8/8/8/3b4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 13);
        import_fen(&board, "8/8/8/3B4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 13);
        import_fen(&board, "8/8/2p1p3/3b4/2p1p3/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 4);
        import_fen(&board, "8/8/2p1p3/3B4/2p1p3/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 4);
    }SECTION("queen") {
        import_fen(&board, "8/8/8/3Q4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 27);
        import_fen(&board, "8/8/8/3q4/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 27);
        import_fen(&board, "8/8/2ppp3/2pQp3/2ppp3/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 8);
        import_fen(&board, "8/8/2ppp3/2pqp3/2ppp3/8/8/8 w - - 0 1");
        a = board.attack_map(Square::d5);
        CHECK(a.size() == 8);
    }SECTION("knight") {
        import_fen(&board, "8/8/2N5/8/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::c6);
        CHECK(a.size() == 8);
        import_fen(&board, "8/8/2n5/8/8/8/8/8 w - - 0 1");
        a = board.attack_map(Square::c6);
        CHECK(a.size() == 8);
        import_fen(&board, "8/2NNNN2/1N4N1/1N4N1/1N4N1/1N4N1/2NNNN2/8 w - - 0 1");
        a = board.attack_map(Square::c7);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::d7);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::e7);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::f7);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::c2);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::d2);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::e2);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::f2);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::b6);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::b5);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::b4);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::b3);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::g6);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::g5);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::g4);
        CHECK(a.size() == 6);
        a = board.attack_map(Square::g3);
        CHECK(a.size() == 6);
        import_fen(&board, "8/1N4N1/8/8/8/8/1N4N1/8 w - - 0 1");
        a = board.attack_map(Square::g2);
        CHECK(a.size() == 4);
        a = board.attack_map(Square::b2);
        CHECK(a.size() == 4);
        a = board.attack_map(Square::g7);
        CHECK(a.size() == 4);
        a = board.attack_map(Square::b7);
        CHECK(a.size() == 4);
        import_fen(&board, "1N4N1/N6N/8/8/8/8/N6N/1N4N1 w - - 0 1");
        // g1, b1, h2, a2, h7, a7, g8, b8
        a = board.attack_map(Square::g1);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::b1);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::h2);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::a2);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::h7);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::a7);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::g8);
        CHECK(a.size() == 3);
        a = board.attack_map(Square::b8);
        CHECK(a.size() == 3);
        // h1, a1, h8, a8
        import_fen(&board, "N6N/8/8/8/8/8/8/N6N w - - 0 1");
        a = board.attack_map(Square::h1);
        CHECK(a.size() == 2);
        a = board.attack_map(Square::a1);
        CHECK(a.size() == 2);
        a = board.attack_map(Square::h8);
        CHECK(a.size() == 2);
        a = board.attack_map(Square::a8);
        CHECK(a.size() == 2);
    }SECTION("king") {

    }
}
