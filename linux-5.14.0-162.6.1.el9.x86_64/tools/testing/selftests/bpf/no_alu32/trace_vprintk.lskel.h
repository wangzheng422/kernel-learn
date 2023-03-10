/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */
/* THIS FILE IS AUTOGENERATED! */
#ifndef __TRACE_VPRINTK_LSKEL_SKEL_H__
#define __TRACE_VPRINTK_LSKEL_SKEL_H__

#include <stdlib.h>
#include <bpf/bpf.h>
#include <bpf/skel_internal.h>

struct trace_vprintk_lskel {
	struct bpf_loader_ctx ctx;
	struct {
		struct bpf_map_desc bss;
		struct bpf_map_desc rodata;
	} maps;
	struct {
		struct bpf_prog_desc sys_enter;
	} progs;
	struct {
		int sys_enter_fd;
	} links;
	struct trace_vprintk_lskel__bss {
		int null_data_vprintk_ret;
		int trace_vprintk_ret;
		int trace_vprintk_ran;
	} *bss;
	struct trace_vprintk_lskel__rodata {
	} *rodata;
};

static inline int
trace_vprintk_lskel__sys_enter__attach(struct trace_vprintk_lskel *skel)
{
	int prog_fd = skel->progs.sys_enter.prog_fd;
	int fd = bpf_raw_tracepoint_open(NULL, prog_fd);

	if (fd > 0)
		skel->links.sys_enter_fd = fd;
	return fd;
}

static inline int
trace_vprintk_lskel__attach(struct trace_vprintk_lskel *skel)
{
	int ret = 0;

	ret = ret < 0 ? ret : trace_vprintk_lskel__sys_enter__attach(skel);
	return ret < 0 ? ret : 0;
}

static inline void
trace_vprintk_lskel__detach(struct trace_vprintk_lskel *skel)
{
	skel_closenz(skel->links.sys_enter_fd);
}
static void
trace_vprintk_lskel__destroy(struct trace_vprintk_lskel *skel)
{
	if (!skel)
		return;
	trace_vprintk_lskel__detach(skel);
	skel_closenz(skel->progs.sys_enter.prog_fd);
	munmap(skel->bss, 4096);
	skel_closenz(skel->maps.bss.map_fd);
	munmap(skel->rodata, 4096);
	skel_closenz(skel->maps.rodata.map_fd);
	free(skel);
}
static inline struct trace_vprintk_lskel *
trace_vprintk_lskel__open(void)
{
	struct trace_vprintk_lskel *skel;

	skel = calloc(sizeof(*skel), 1);
	if (!skel)
		goto cleanup;
	skel->ctx.sz = (void *)&skel->links - (void *)skel;
	skel->bss =
		mmap(NULL, 4096, PROT_READ | PROT_WRITE,
		     MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (skel->bss == (void *) -1)
		goto cleanup;
	memcpy(skel->bss, (void *)"\
\0\0\0\0\0\0\0\0\0\0\0\0", 12);
	skel->maps.bss.initial_value = (__u64)(long)skel->bss;
	skel->rodata =
		mmap(NULL, 4096, PROT_READ | PROT_WRITE,
		     MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (skel->rodata == (void *) -1)
		goto cleanup;
	memcpy(skel->rodata, (void *)"\
\x31\0\x33\0\x35\0\x37\0\x39\0\x25\x70\x53\x0a\0\x09\0\x25\x73\x2c\x25\x64\x2c\
\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\
\x73\x2c\x25\x64\x20\x25\x64\x0a\0", 51);
	skel->maps.rodata.initial_value = (__u64)(long)skel->rodata;
	return skel;
cleanup:
	trace_vprintk_lskel__destroy(skel);
	return NULL;
}

static inline int
trace_vprintk_lskel__load(struct trace_vprintk_lskel *skel)
{
	struct bpf_load_and_run_opts opts = {};
	int err;

	opts.ctx = (struct bpf_loader_ctx *)skel;
	opts.data_sz = 3584;
	opts.data = (void *)"\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9f\xeb\x01\0\
\x18\0\0\0\0\0\0\0\x3c\x02\0\0\x3c\x02\0\0\x60\x02\0\0\0\0\0\0\0\0\0\x02\0\0\0\
\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\0\x13\0\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x05\0\0\0\x07\0\0\0\x04\0\0\0\x18\0\0\0\
\0\0\0\x01\x04\0\0\0\x20\0\0\0\x2c\0\0\0\0\0\0\x0e\x06\0\0\0\x01\0\0\0\x35\0\0\
\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x4b\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x5d\0\
\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x0a\x05\0\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x0c\0\0\0\x07\0\0\0\x02\0\0\0\x6f\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\
\0\x7d\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\x8d\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\
\x9c\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\xac\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x03\0\0\0\0\x0c\0\0\0\x07\0\0\0\x05\0\0\0\xbb\0\0\0\0\0\0\x0e\x13\
\0\0\0\0\0\0\0\xc7\0\0\0\0\0\0\x0e\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x0c\0\0\0\x07\0\0\0\x22\0\0\0\xd9\0\0\0\0\0\0\x0e\x16\0\0\0\0\0\0\0\x30\x02\0\
\0\x01\0\0\x0f\x04\0\0\0\x08\0\0\0\0\0\0\0\x04\0\0\0\x38\x02\0\0\x03\0\0\x0f\
\x0c\0\0\0\x09\0\0\0\0\0\0\0\x04\0\0\0\x0a\0\0\0\x04\0\0\0\x04\0\0\0\x0b\0\0\0\
\x08\0\0\0\x04\0\0\0\x3d\x02\0\0\x08\0\0\x0f\x33\0\0\0\x0e\0\0\0\0\0\0\0\x02\0\
\0\0\x0f\0\0\0\x02\0\0\0\x02\0\0\0\x10\0\0\0\x04\0\0\0\x02\0\0\0\x11\0\0\0\x06\
\0\0\0\x02\0\0\0\x12\0\0\0\x08\0\0\0\x02\0\0\0\x14\0\0\0\x0a\0\0\0\x05\0\0\0\
\x15\0\0\0\x0f\0\0\0\x02\0\0\0\x17\0\0\0\x11\0\0\0\x22\0\0\0\0\x63\x74\x78\0\
\x69\x6e\x74\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x63\x68\x61\x72\0\x5f\x5f\
\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\
\x69\x63\x65\x6e\x73\x65\0\x6e\x75\x6c\x6c\x5f\x64\x61\x74\x61\x5f\x76\x70\x72\
\x69\x6e\x74\x6b\x5f\x72\x65\x74\0\x74\x72\x61\x63\x65\x5f\x76\x70\x72\x69\x6e\
\x74\x6b\x5f\x72\x65\x74\0\x74\x72\x61\x63\x65\x5f\x76\x70\x72\x69\x6e\x74\x6b\
\x5f\x72\x61\x6e\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x2e\x6f\x6e\x65\0\x73\
\x79\x73\x5f\x65\x6e\x74\x65\x72\x2e\x74\x68\x72\x65\x65\0\x73\x79\x73\x5f\x65\
\x6e\x74\x65\x72\x2e\x66\x69\x76\x65\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x2e\
\x73\x65\x76\x65\x6e\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x2e\x6e\x69\x6e\x65\
\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x2e\x66\0\x73\x79\x73\x5f\x65\x6e\x74\
\x65\x72\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\
\x2e\x5f\x5f\x5f\x66\x6d\x74\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\
\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\
\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\
\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\
\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\
\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x72\x61\x63\x65\x5f\x76\x70\x72\x69\x6e\
\x74\x6b\x2e\x63\0\x69\x6e\x74\x20\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x28\x76\
\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\
\x6b\x28\x22\x5c\x74\x22\x29\x3b\0\x09\x74\x72\x61\x63\x65\x5f\x76\x70\x72\x69\
\x6e\x74\x6b\x5f\x72\x65\x74\x20\x3d\x20\x5f\x5f\x62\x70\x66\x5f\x76\x70\x72\
\x69\x6e\x74\x6b\x28\x22\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\
\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x20\x25\x64\
\x5c\x6e\x22\x2c\0\x09\x6e\x75\x6c\x6c\x5f\x64\x61\x74\x61\x5f\x76\x70\x72\x69\
\x6e\x74\x6b\x5f\x72\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x74\x72\x61\x63\x65\
\x5f\x76\x70\x72\x69\x6e\x74\x6b\x28\x66\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\
\x66\x29\x2c\x20\x4e\x55\x4c\x4c\x2c\x20\x30\x29\x3b\0\x09\x72\x65\x74\x75\x72\
\x6e\x20\x30\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x2e\x72\x6f\
\x64\x61\x74\x61\0\x66\x65\x6e\x74\x72\x79\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\
\x73\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xb4\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x0c\0\0\0\x01\
\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\x74\x72\x61\x63\x65\x5f\x76\x70\x2e\x62\x73\
\x73\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x19\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x33\0\0\0\x01\0\0\0\x80\x04\0\0\0\0\0\0\0\0\0\0\
\x74\x72\x61\x63\x65\x5f\x76\x70\x2e\x72\x6f\x64\x61\x74\x61\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x1a\0\0\0\0\0\0\0\x31\0\x33\0\x35\0\x37\0\x39\0\x25\x70\x53\x0a\0\x09\
\0\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x2c\x25\
\x73\x2c\x25\x64\x2c\x25\x73\x2c\x25\x64\x20\x25\x64\x0a\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x47\x50\x4c\0\0\0\0\0\xb7\x06\0\0\x02\0\0\0\x18\x61\0\0\x01\0\0\0\0\0\
\0\0\x0f\0\0\0\xb7\x02\0\0\x02\0\0\0\x85\0\0\0\x06\0\0\0\x18\x62\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\x61\x21\0\0\0\0\0\0\x07\x01\0\0\x01\0\0\0\x63\x12\0\0\0\0\0\0\
\xb7\x02\0\0\x0a\0\0\0\x7b\x2a\xf0\xff\0\0\0\0\x18\x62\0\0\x01\0\0\0\0\0\0\0\
\x08\0\0\0\x7b\x2a\xe8\xff\0\0\0\0\xb7\x02\0\0\x08\0\0\0\x7b\x2a\xe0\xff\0\0\0\
\0\x18\x62\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x7b\x2a\xd8\xff\0\0\0\0\xb7\x02\0\0\
\x06\0\0\0\x7b\x2a\xd0\xff\0\0\0\0\x18\x62\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x7b\
\x2a\xc8\xff\0\0\0\0\xb7\x02\0\0\x04\0\0\0\x7b\x2a\xc0\xff\0\0\0\0\x18\x62\0\0\
\x01\0\0\0\0\0\0\0\x02\0\0\0\x7b\x2a\xb8\xff\0\0\0\0\x7b\x6a\xb0\xff\0\0\0\0\
\x18\x62\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\x7b\x2a\xa8\xff\0\0\0\0\x67\x01\0\0\x20\
\0\0\0\xc7\x01\0\0\x20\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\
\x03\0\0\xa8\xff\xff\xff\x18\x61\0\0\x01\0\0\0\0\0\0\0\x11\0\0\0\xb7\x02\0\0\
\x22\0\0\0\xb7\x04\0\0\x58\0\0\0\x85\0\0\0\xb1\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\
\0\x04\0\0\0\x63\x01\0\0\0\0\0\0\x18\x61\0\0\x01\0\0\0\0\0\0\0\x0a\0\0\0\xb7\
\x02\0\0\x05\0\0\0\xb7\x03\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\xb1\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\
\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xea\0\0\0\x6d\x01\0\0\0\x3c\0\0\x01\0\
\0\0\xea\0\0\0\x86\x01\0\0\x02\x64\0\0\x05\0\0\0\xea\0\0\0\x99\x01\0\0\x16\x6c\
\0\0\x26\0\0\0\xea\0\0\0\0\0\0\0\0\0\0\0\x27\0\0\0\xea\0\0\0\x99\x01\0\0\x16\
\x6c\0\0\x2c\0\0\0\xea\0\0\0\x99\x01\0\0\x14\x6c\0\0\x2f\0\0\0\xea\0\0\0\xe2\
\x01\0\0\x1a\x7c\0\0\x35\0\0\0\xea\0\0\0\xe2\x01\0\0\x18\x7c\0\0\x38\0\0\0\xea\
\0\0\0\x25\x02\0\0\x02\x80\0\0\x1a\0\0\0\x3a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\0\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\
\x65\x70\0\0\0\0\0";
	opts.insns_sz = 1984;
	opts.insns = (void *)"\
\xbf\x16\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\x78\xff\xff\xff\xb7\x02\0\
\0\x88\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x71\0\0\0\x05\0\x17\0\0\0\0\0\x61\
\xa1\x78\xff\0\0\0\0\xd5\x01\x01\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\x61\xa1\x7c\xff\
\0\0\0\0\xd5\x01\x01\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\x61\xa1\x80\xff\0\0\0\0\xd5\
\x01\x01\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\
\x01\0\0\0\0\0\0\xd5\x01\x02\0\0\0\0\0\xbf\x19\0\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\
\x18\x60\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x61\x01\0\0\0\0\0\0\xd5\x01\x02\0\0\0\0\
\0\xbf\x19\0\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\xbf\x70\0\0\0\0\0\0\x95\0\0\0\0\0\0\
\0\x61\x60\x08\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xd0\x09\0\0\x63\x01\0\0\0\
\0\0\0\x61\x60\x0c\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xcc\x09\0\0\x63\x01\0\
\0\0\0\0\0\x79\x60\x10\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xc0\x09\0\0\x7b\
\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\x18\x61\0\0\0\0\0\0\0\0\
\0\0\xb8\x09\0\0\x7b\x01\0\0\0\0\0\0\xb7\x01\0\0\x12\0\0\0\x18\x62\0\0\0\0\0\0\
\0\0\0\0\xb8\x09\0\0\xb7\x03\0\0\x1c\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\0\0\
\0\0\xc5\x07\xd1\xff\0\0\0\0\x63\x7a\x78\xff\0\0\0\0\x61\xa0\x78\xff\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\x08\x0a\0\0\x63\x01\0\0\0\0\0\0\x61\x60\x20\0\0\0\
\0\0\x15\0\x03\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xe4\x09\0\0\x63\x01\0\0\0\
\0\0\0\xb7\x01\0\0\0\0\0\0\x18\x62\0\0\0\0\0\0\0\0\0\0\xd8\x09\0\0\xb7\x03\0\0\
\x40\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\0\0\0\0\xc5\x07\xc0\xff\0\0\0\0\x18\
\x61\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x71\0\0\0\0\0\0\x79\x63\x18\0\0\0\0\0\x15\
\x03\x04\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x18\x0a\0\0\xb7\x02\0\0\x0c\0\0\
\0\x85\0\0\0\x94\0\0\0\x18\x62\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x20\0\0\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\x30\x0a\0\0\x63\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\
\0\0\0\0\0\x28\x0a\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x38\x0a\0\0\x7b\x01\0\0\0\0\
\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\x18\x0a\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x40\
\x0a\0\0\x7b\x01\0\0\0\0\0\0\xb7\x01\0\0\x02\0\0\0\x18\x62\0\0\0\0\0\0\0\0\0\0\
\x30\x0a\0\0\xb7\x03\0\0\x20\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\0\0\0\0\xc5\
\x07\xa0\xff\0\0\0\0\x61\xa0\x78\xff\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x80\
\x0a\0\0\x63\x01\0\0\0\0\0\0\x61\x60\x30\0\0\0\0\0\x15\0\x03\0\0\0\0\0\x18\x61\
\0\0\0\0\0\0\0\0\0\0\x5c\x0a\0\0\x63\x01\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x18\
\x62\0\0\0\0\0\0\0\0\0\0\x50\x0a\0\0\xb7\x03\0\0\x40\0\0\0\x85\0\0\0\xa6\0\0\0\
\xbf\x07\0\0\0\0\0\0\xc5\x07\x90\xff\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x04\0\
\0\0\x63\x71\0\0\0\0\0\0\x79\x63\x28\0\0\0\0\0\x15\x03\x04\0\0\0\0\0\x18\x61\0\
\0\0\0\0\0\0\0\0\0\x90\x0a\0\0\xb7\x02\0\0\x33\0\0\0\x85\0\0\0\x94\0\0\0\x18\
\x62\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x61\x20\0\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\
\0\0\xd0\x0a\0\0\x63\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\xc8\x0a\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\xd8\x0a\0\0\x7b\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\
\0\0\0\0\0\x90\x0a\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xe0\x0a\0\0\x7b\x01\0\0\0\0\
\0\0\xb7\x01\0\0\x02\0\0\0\x18\x62\0\0\0\0\0\0\0\0\0\0\xd0\x0a\0\0\xb7\x03\0\0\
\x20\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\0\0\0\0\xc5\x07\x70\xff\0\0\0\0\x18\
\x62\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x61\x20\0\0\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\
\0\0\xf0\x0a\0\0\x63\x01\0\0\0\0\0\0\xb7\x01\0\0\x16\0\0\0\x18\x62\0\0\0\0\0\0\
\0\0\0\0\xf0\x0a\0\0\xb7\x03\0\0\x04\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\0\0\
\0\0\xc5\x07\x63\xff\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\xf8\x0a\0\0\x18\x61\0\
\0\0\0\0\0\0\0\0\0\x78\x0d\0\0\x7b\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\
\0\x0b\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x70\x0d\0\0\x7b\x01\0\0\0\0\0\0\x18\x60\
\0\0\0\0\0\0\0\0\0\0\xd0\x0c\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xb8\x0d\0\0\x7b\
\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\xd8\x0c\0\0\x18\x61\0\0\0\0\0\0\0\
\0\0\0\xc8\x0d\0\0\x7b\x01\0\0\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\
\x61\0\0\0\0\0\0\0\0\0\0\xe0\x0d\0\0\x7b\x01\0\0\0\0\0\0\x61\x60\x08\0\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\x80\x0d\0\0\x63\x01\0\0\0\0\0\0\x61\x60\x0c\0\0\0\
\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x84\x0d\0\0\x63\x01\0\0\0\0\0\0\x79\x60\x10\0\
\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\x88\x0d\0\0\x7b\x01\0\0\0\0\0\0\x61\xa0\
\x78\xff\0\0\0\0\x18\x61\0\0\0\0\0\0\0\0\0\0\xb0\x0d\0\0\x63\x01\0\0\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\xe8\x0d\0\0\xb7\x02\0\0\x14\0\0\0\xb7\x03\0\0\x0c\
\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\xa7\0\0\0\xbf\x07\0\0\0\0\0\0\xc5\x07\x32\
\xff\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\x68\x0d\0\0\x63\x70\x6c\0\0\0\0\0\x77\
\x07\0\0\x20\0\0\0\x63\x70\x70\0\0\0\0\0\xb7\x01\0\0\x05\0\0\0\x18\x62\0\0\0\0\
\0\0\0\0\0\0\x68\x0d\0\0\xb7\x03\0\0\x80\0\0\0\x85\0\0\0\xa6\0\0\0\xbf\x07\0\0\
\0\0\0\0\x18\x60\0\0\0\0\0\0\0\0\0\0\xd8\x0d\0\0\x61\x01\0\0\0\0\0\0\xd5\x01\
\x02\0\0\0\0\0\xbf\x19\0\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\xc5\x07\x20\xff\0\0\0\0\
\x63\x7a\x80\xff\0\0\0\0\x61\xa1\x78\xff\0\0\0\0\xd5\x01\x02\0\0\0\0\0\xbf\x19\
\0\0\0\0\0\0\x85\0\0\0\xa8\0\0\0\x61\xa0\x80\xff\0\0\0\0\x63\x06\x38\0\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x10\0\0\0\0\0\0\x63\x06\x18\0\0\0\0\0\
\x18\x61\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x61\x10\0\0\0\0\0\0\x63\x06\x28\0\0\0\0\
\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0";
	err = bpf_load_and_run(&opts);
	if (err < 0)
		return err;
	skel->bss =
		mmap(skel->bss, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED,
			skel->maps.bss.map_fd, 0);
	skel->rodata =
		mmap(skel->rodata, 4096, PROT_READ, MAP_SHARED | MAP_FIXED,
			skel->maps.rodata.map_fd, 0);
	return 0;
}

static inline struct trace_vprintk_lskel *
trace_vprintk_lskel__open_and_load(void)
{
	struct trace_vprintk_lskel *skel;

	skel = trace_vprintk_lskel__open();
	if (!skel)
		return NULL;
	if (trace_vprintk_lskel__load(skel)) {
		trace_vprintk_lskel__destroy(skel);
		return NULL;
	}
	return skel;
}

#endif /* __TRACE_VPRINTK_LSKEL_SKEL_H__ */
