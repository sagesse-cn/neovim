#ifndef NVIM_MISC1_H
#define NVIM_MISC1_H

#include "nvim/vim.h"
#include "nvim/os/shell.h"

/* flags for open_line() */
#define OPENLINE_DELSPACES  1   /* delete spaces after cursor */
#define OPENLINE_DO_COM     2   /* format comments */
#define OPENLINE_KEEPTRAIL  4   /* keep trailing spaces */
#define OPENLINE_MARKFIX    8   /* fix mark positions */
#define OPENLINE_COM_LIST  16   /* format comments with list/2nd line indent */

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "misc1.h.generated.h"
#endif
#endif  // NVIM_MISC1_H

#ifdef CUSTOM_UI
extern void custom_ui_buf_changed (
   linenr_T lnum, colnr_T col, linenr_T lnume, long xtra );
#endif
