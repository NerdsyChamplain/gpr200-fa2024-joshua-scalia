#ifndef SHADER_H
#define SHADER_H

#include <C:\Users\Josh\Documents\GitHub\gpr200-fa2024-joshua-scalia\core/ew/external/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;
    //constructor
    Shader(const char*, const char*);
    //activate shader
    void use();
    //utility functions
    void setBool(const std::string&, bool) const;

    void setInt(const std::string&, int) const;

    void setFloat(const std::string&, float) const;

private:
    //check compile errors
    void checkCompileErrors(unsigned int, std::string);
};
#endif