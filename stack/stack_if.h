#include "systemc.h"
#ifndef __STACK_IF_H__
#define __STACK_IF_H__

class stack_write_if: virtual public sc_interface
{
public:
  virtual bool nb_write(char) = 0;  // write a character
  virtual void reset() = 0;         // empty the stack
};

class stack_read_if: virtual public sc_interface
{
public:
  virtual bool nb_read(char&) = 0;  // read a character
};

#endif
