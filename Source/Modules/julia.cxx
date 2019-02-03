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

/* required for SWIG help */
static const char *usage = "\
\
JULIA Options (available with -julia)\n\
     -verbose   - Verbose\n\
\n";


/* required for Julia SWIG module */
static File *out = 0;
static const char *julia_path = "julia";

class JULIA:public Language {
public:

  virtual void main(int argc, char *argv[]);
  virtual int top(Node *n);

};


void JULIA::main(int argc, char *argv[]) {

    int i;

    SWIG_library_directory(julia_path);
    // TODO: Look for certain command line options
    for (i = 1; i < argc; i++) {

    }
    Preprocessor_define("SWIGJULIA 1", 0);

    SWIG_typemap_lang("julia");
    // Read in default typemaps */
    // SWIG_config_file("julia.swg");

}

int JULIA::top(Node *n) {
    if (out == 0) {
      String *outfile = Getattr(n, "outfile");
      Replaceall(outfile, "_wrap.cxx", ".jl");
      Replaceall(outfile, "_wrap.c", ".jl");
      out = NewFile(outfile, "w", SWIG_output_files());
      if (!out) {
          FileErrorDisplay(outfile);
          SWIG_exit(EXIT_FAILURE);
      }
    }

}

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

