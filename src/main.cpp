#include <iostream>
#include "Board.hpp"
#include "tree.hpp"
#include "search.hpp"

// TODO just get it working first...you can go back later and make it more efficient =-)
// don't get to worried about writing clever code =-)
// keep it simple

void string_to_move(const std::string *string, Square *from, Square *to, char *ch);

int main()
{
    std::string in;

    while (std::getline(std::cin, in)) {

        if (in == "uci") {
            // should give engine options to be configured ... we don't have any right now, so ... uciok!
            std::cout << "id name Raab\n"
                      << "id author Schauss\n"
                      << "uciok\n";
        }
        else if (in == "isready") {
            // to give the engine time to set up stuff ... but we don't have any stuff!!!
            std::cout << "readyok\n";
        }

        if (in.find("position") != std::string::npos) {
            // set up a board in the given position, wait for "go" to search
            // a fen or a list of moves may follow "position"
            if (in.find("fen") != std::string::npos) {
                // import fen
            }
            if (in.find("startpos") != std::string::npos) {
                Node n("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
                if (in.find("moves") != std::string::npos) {
                    // get moves from the string and perform them
                    std::istringstream iss(in);
                    std::string s;
                    // get rid of "position startpos moves"
                    for (auto i = 0; i < 3; i++) {
                        iss >> s;
                    }
                    // next string will be a move
                    while (iss >> s) {
                        Square from, to;
                        char ch;
                        string_to_move(&s, &from, &to, &ch);
                        n._board.move(from, to, ch);
                    }
                }
            }
        }

        if (in.find("go") != std::string::npos) {
            // start calculating for current position
        }
        if (in.find("stop") != std::string::npos) {
            // stop calculating
        }

        else if (in == "quit") { break; }
    }
    return 0;
}

void string_to_move(const std::string *string, Square *from, Square *to, char *ch)
{
    std::string temp;
    auto count = 0;
    for (const auto c : *string) {
        if (c != 'x' && c != '#') {
            temp.push_back(c);
            count++;
        }
        if (count == 2) {
            *from = string_to_square(temp);
            temp.clear();
        }
        else if (count == 4) {
            *to = string_to_square(temp);
            temp.clear();
        }
        else if (count == 5) {
            *ch = c;
        }
    }
}
