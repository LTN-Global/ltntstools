/* Copyright LiveTimeNet, Inc. 2017. All Rights Reserved. */

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "version.h"

/* External tool hooks */
extern int pat_inspector(int argc, char *argv[]);
extern int pmt_inspector(int argc, char *argv[]);
extern int udp_capture(int argc, char *argv[]);

typedef int (*func_ptr)(int, char *argv[]);

int main(int argc, char *argv[])
{
	printf("%s\n", COPYRIGHT);
	printf("Version: %s\n", GIT_VERSION);
	struct app_s {
		char *name;
		func_ptr func;
	} apps[] = {
#if 0
		{ "tstools_util",		demo_main, },
#endif
		{ "tstools_pat_inspector",	pat_inspector, },
		{ "tstools_pmt_inspector",	pmt_inspector, },
		{ "tstools_udp_capture",	udp_capture, },
		{ 0, 0 },
	};
	char *appname = basename(argv[0]);

	int i = 0;
	struct app_s *app = &apps[i++];
	while (app->name) {
		if (strcmp(appname, app->name) == 0)
			return app->func(argc, argv);

		app = &apps[i++];
	}

	printf("No application called %s, aborting.\n", appname);
	i = 0;
	app = &apps[i++];
	while (app->name) {
		printf("%s ", app->name);
		app = &apps[i++];
	}

	return 1;
}