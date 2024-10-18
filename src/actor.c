#include "oasis.h"

OasisActor *oasis_actor_create(OasisWorld *super) { (void)super; return NULL;}

void oasis_actor_assign_key(OasisActor *actor, char key, void (*f)(OasisActor *)) {
    (void)actor;
    (void)key;
    (void)f;
}
