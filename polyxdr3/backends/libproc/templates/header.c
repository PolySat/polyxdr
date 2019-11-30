#include <stddef.h>
:: if namespace == 'IPC':
#include "cmd.h"
:: else:
#include <polysat3/cmd.h>
#include <polysat3/cmd-pkt.h>
:: #endif
#include "${header}"

void ${namespace.upper().replace('::','_',400)}_forcelink(void) {}

