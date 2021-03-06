#ifndef _BRYNET_NET_FDSET_INCLUDED_H
#define _BRYNET_NET_FDSET_INCLUDED_H

#include <stdbool.h>
#include <brynet/net/SocketLibTypes.h>
#include <brynet/utils/stack.h>

enum CheckType
{
    ReadCheck = 0x1,
    WriteCheck = 0x2,
    ErrorCheck = 0x4,
};

#ifdef  __cplusplus
extern "C" {
#endif

struct fdset_s;

struct fdset_s* ox_fdset_new(void);
void ox_fdset_delete(struct fdset_s* self);
void ox_fdset_add(struct fdset_s* self, sock fd, int type);
void ox_fdset_del(struct fdset_s* self, sock fd, int type);
void ox_fdset_remove(struct fdset_s* self, sock fd);
void ox_fdset_visitor(struct fdset_s* self, enum CheckType type, struct stack_s* result);
int ox_fdset_poll(struct fdset_s* self, long overtime);
bool ox_fdset_check(struct fdset_s* self, sock fd, enum CheckType type);

#ifdef  __cplusplus
}
#endif

#endif
