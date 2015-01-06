#ifndef IBW_H
#define IBW_H

int ibwloadcfg(const char *cfgfile);
int ibwadd(const char *iface, int limit);
void ibwlist(void);
int ibwget(const char *iface);
void ibwflush(void);
int ibwcfgread(FILE *fd);

#endif