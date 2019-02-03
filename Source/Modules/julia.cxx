/* -----------------------------------------------------------------------------
 * This file is part of SWIG, which is licensed as a whole under version 3
 * (or any later version) of the GNU General Public License. Some additional
 * terms also apply to certain portions of SWIG. The full details of the SWIG
 * license and copyrights can be found in the LICENSE and COPYRIGHT files
 * included with the SWIG source code as distributed by the SWIG developers
 * and at http://www.swig.org/legal.html.
 *
 * julia.cxx
 *
 * Julia language module for SWIG.
 * ----------------------------------------------------------------------------- */

#include "swigmod.h"

#include <ctype.h>

static const char *usage = "\
\
JULIA Options (available with -julia)\n\
     -verbose   - Verbose\n\
\n";


static const char *julia_path = "julia";

class JULIA:public Language {
public:

  virtual void main(int argc, char *argv[]);
  virtual int top(Node *n);

};

/* -----------------------------------------------------------------------
 * swig_julia()    - Instantiate module
 * ----------------------------------------------------------------------- */

static Language *new_swig_julia() {
  return new JULIA();
}

extern "C" {
  Language *swig_julia(void) {
    return new_swig_julia();
  }
}

void JULIA::main(int argc, char *argv[]) {

}

int JULIA::top(Node *n) {

}
