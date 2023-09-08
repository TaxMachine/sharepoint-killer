//
// Created by TaxMachine on 2023-09-08.
//

#ifndef SHAREPOINT_KILLER_LOGS_HPP
#define SHAREPOINT_KILLER_LOGS_HPP

#include <iostream>
#include "colors.hpp"

namespace Logs {
    void Info(const std::string& message) {
        std::cout << Color(0, 0, 255).toForeConsole() << "[INFO] " << message << Color::RESET << std::endl;
    }

    void Error(const std::string& message) {
        std::cout << Color(255, 0, 0).toForeConsole() << "[ERROR] " << message << Color::RESET << std::endl;
    }

    void Success(const std::string& message) {
        std::cout << Color(0, 255, 0).toForeConsole() << "[SUCCESS] " << message << Color::RESET << std::endl;
    }

    void Warning(const std::string& message) {
        std::cout << Color(249, 228, 37).toForeConsole() << "[WARNING] " << message << Color::RESET << std::endl;
    }
}

#endif //SHAREPOINT_KILLER_LOGS_HPP
