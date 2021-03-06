#ifndef DISASSEMBLER_H_
#define DISASSEMBLER_H_

#include <string>
#include <vector>
#include <bfd.h>

using std::string;
using std::vector;


class Disassembler
{
public:
    enum InsType
    {
        INS_UNKNOWN = 0,
        INS_MOV,
        INS_PUSH,
        INS_POP,
    };

    void Disassemble (bfd* abfd,
                      asection* section,
                      char* sectionContents,
                      const unsigned int startAddress,
                      const unsigned int endAddress);

    virtual bool HandleInstruction (const unsigned int addr,
                                    const unsigned int length,
                                    const InsType ins,
                                    const vector<char*>& args) = 0;

private:
    static InsType DecodeInsString (char* s, vector<char*>& args);
    static void DisasPrintf (void* userData, const char* format, ...);
};

#endif
