#ifndef NVIM_UI_H
#define NVIM_UI_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "api/private/defs.h"
#include "nvim/buffer_defs.h"

typedef enum {
  kUICmdline = 0,
  kUIPopupmenu,
  kUITabline,
  kUIWildmenu,
} UIWidget;
#define UI_WIDGETS (kUIWildmenu + 1)

typedef struct {
  bool bold, underline, undercurl, italic, reverse;
  int foreground, background, special;
} HlAttrs;

typedef struct ui_t UI;

struct ui_t {
  bool rgb;
  bool ui_ext[UI_WIDGETS];  ///< Externalized widgets
  int width, height;
  void *data;

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "ui_events.generated.h"
#endif

  void (*event)(UI *ui, char *name, Array args, bool *args_consumed);
  void (*stop)(UI *ui);
};

#ifdef CUSTOM_UI
extern void custom_ui_start(void);
#endif

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "ui.h.generated.h"
# include "ui_events_call.h.generated.h"
#endif
#endif  // NVIM_UI_H
