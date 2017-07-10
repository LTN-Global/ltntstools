/* Copyright LiveTimeNet, Inc. 2017. All Rights Reserved. */

#ifndef _PIDS_H
#define _PIDS_H

#ifdef __cplusplus
extern "C" {
#endif

#define getPID(pkt) (((*((pkt) + 1) << 8) | *((pkt) + 2)) & 0x1fff)

#define MAX_PID 8191
struct pid_statistics_s
{
	int enabled;
	uint64_t packetCount;
	uint64_t ccErrors;
};

struct stream_statistics_s
{
	struct pid_statistics_s pids[MAX_PID];
};

#ifdef __cplusplus
};
#endif

#endif /* _PIDS_H */