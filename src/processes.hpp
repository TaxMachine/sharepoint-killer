//
// Created by TaxMachine on 2023-09-08.
//

#ifndef SHAREPOINT_KILLER_PROCESSES_HPP
#define SHAREPOINT_KILLER_PROCESSES_HPP

#include <vector>
#include <string>
/*
 *
 * @brief Processes to kill
 *
 * @details Here's how to add a process to the blacklist:
 *
 * std::vector<std::string> PROCESS_BLACKLIST = {
 *        "SharePoint.exe",
 *        "AnotherProcess.exe",
 *        "YetAnotherProcess.exe",
 *        "AndAnotherProcess.exe"
 * };
 *
 */
std::vector<std::string> PROCESS_BLACKLIST = {
        "Microsoft.SharePoint.exe",
        "OfficeClickToRun.exe"
};

#endif //SHAREPOINT_KILLER_PROCESSES_HPP
