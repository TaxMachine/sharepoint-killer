//
// Created by TaxMachine on 2023-07-14.
//
#include <string>

class Color {
    public:
        Color(int r, int g, int b);

        int r, g, b;
        static std::string RESET, BOLD, FAINT, UNDERLINE, BLINK;
        static void Clear();

        [[nodiscard]] int toDecimal() const;
        [[nodiscard]] std::string toForeConsole() const;
        [[nodiscard]] std::string toBackConsole() const;
};