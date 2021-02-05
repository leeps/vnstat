#ifndef IMAGE_H
#define IMAGE_H

#include <gd.h>		  /* libgd2-dev libgd2 */
#include <gdfontt.h>  /* gdFontGetTiny() */
#include <gdfonts.h>  /* gdFontGetSmall() */
#include <gdfontmb.h> /* gdFontGetMediumBold() */
#include <gdfontl.h>  /* gdFontGetLarge() */
#include <gdfontg.h>  /* gdFontGetGiant() */

/* rectangle size */
#define YBEGINOFFSET (-1)
#define YENDOFFSET 6

/* donut size */
#define DOUTRAD 49
#define DINRAD 15

typedef struct {
	gdImagePtr im;
	gdFontPtr font;
	interfaceinfo interface;
	int cbackground, cedge, cheader, cheadertitle, cheaderdate, ctext, cline, clinel, cvnstat;
	int crx, crxd, ctx, ctxd, cbgoffset, cbgoffsetmore, showheader, showedge, showlegend, altdate;
	int lineheight, large;
	char headertext[65], databegin[18], dataend[18];
	time_t current;
} IMAGECONTENT;

typedef struct {
	time_t date;
	uint64_t rx, tx;
} HOURDATA;

void initimagecontent(IMAGECONTENT *ic);
void drawimage(IMAGECONTENT *ic);
#if HAVE_DECL_GD_NEAREST_NEIGHBOUR
void scaleimage(IMAGECONTENT *ic);
#endif
void colorinit(IMAGECONTENT *ic);
void colorinitcheck(const char *color, const int value, const char *cfgtext, const int *rgb);
void layoutinit(IMAGECONTENT *ic, char *title, const int width, const int height);
void drawlegend(IMAGECONTENT *ic, const int x, const int y, const short israte);
void drawbar(IMAGECONTENT *ic, const int x, const int y, const int len, const uint64_t rx, const uint64_t tx, const uint64_t max, const short isestimate);
void drawpole(IMAGECONTENT *ic, const int x, const int y, const int len, const uint64_t rx, const uint64_t tx, const uint64_t max);
void drawdonut(IMAGECONTENT *ic, const int x, const int y, const float rxp, const float txp);
#ifdef CHECK_VNSTAT
void drawdonut_libgd_native(IMAGECONTENT *ic, const int x, const int y, const float rxp, const float txp);
#endif
int drawhours(IMAGECONTENT *ic, const int x, const int y, const int rate);
void drawhourly(IMAGECONTENT *ic, const int rate);
void drawlist(IMAGECONTENT *ic, const char *listname);
void drawsummary(IMAGECONTENT *ic, const int layout, const int rate);
void drawsummary_alltime(IMAGECONTENT *ic, const int x, const int y);
void drawsummary_digest(IMAGECONTENT *ic, const int x, const int y, const char *mode);
void hextorgb(char *input, int *rgb);
void modcolor(int *rgb, const int offset, const int force);
char *getimagevalue(const uint64_t b, const int len, const int rate);
char *getimagescale(const uint64_t b, const int rate);
uint64_t getscale(const uint64_t input, const int rate);

#endif
