#ifndef DEBUGGER_H
#define DEBUGGER_H


#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <sys/personality.h>

extern "C" {
    #include "linenoise.h"
}
#include "breakpoint.h"

std::vector<std::string> split(const std::string& ,char);
bool is_prefix(const std::string&, const std::string& );

class debugger {
    public:
        debugger (std::string prog_name, pid_t pid) :
        m_prog_name{std::move(prog_name)}, m_pid{pid} {}
    
    void run();
    void handle_command(const std::string&);
    void continue_execution();
    void set_breakpoint(std::intptr_t addr);

    private:
        std::string m_prog_name;
        std::unordered_map<std::intptr_t, breakpoint> m_breakpoints;
        pid_t m_pid;
};

#endif