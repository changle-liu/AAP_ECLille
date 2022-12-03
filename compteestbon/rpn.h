#include "list.h"
#include <string.h>
#include "stack_cs.h"
#include "stack_cd.h"
#include "stack_cld.h"

T_stack s2list(char * exp);
T_elt rpn_eval(char * exp);
void show_rpn(char * exp);

