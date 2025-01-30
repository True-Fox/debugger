#ifndef DEBUGGER_H
#define DEBUGGER_H


#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>

extern "C" {
    #include "linenoise.h"
}

std::vector<std::string> split(const std::string& ,char);
bool is_prefix(const std::string&, const std::string& );

class debugger {
    public:
        debugger (std::string prog_name, pid_t pid) :
        m_prog_name{std::move(prog_name)}, m_pid{pid} {}
    
    void run();
    void handle_command(const std::string&);
    void continue_execution();

    private:
        std::string m_prog_name;
        pid_t m_pid;
};

#endif