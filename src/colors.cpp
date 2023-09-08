//
// Created by TaxMachine on 2023-07-14.
//

#include <iostream>
#include "colors.hpp"

using std::string;
using std::to_string;

string Color::RESET = "\x1b[0m";
string Color::BOLD = "\x1b[1m";
string Color::FAINT = "\x1b[2m";
string Color::UNDERLINE = "\x1b[4m";
string Color::BLINK = "\x1b[5m";

Color::Color(int r, int g, int b) {
    this->r = r;
    this->b = b;
    this->g = g;
}

int Color::toDecimal() const {
    return this->r * 65536 + this->g * 256 + this->b;
}

string Color::toForeConsole() const {
    return "\x1b[38;2;" +
            to_string(this->r) + ";" +
            to_string(this->g) + ";" +
            to_string(this->b) + "m";
}

string Color::toBackConsole() const {
    return "\x1b[48;2;" +
           to_string(this->r) + ";" +
           to_string(this->g) + ";" +
           to_string(this->b) + "m";
}

void Color::Clear() {
    __FILE__[0] == '/' ? system("clear") : system("cls");
}
