/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __GET_BRANCH_SNAPSHOT_SKEL_H__
#define __GET_BRANCH_SNAPSHOT_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct get_branch_snapshot {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test1;
	} progs;
	struct {
		struct bpf_link *test1;
	} links;
	struct get_branch_snapshot__bss {
		__u64 test1_hits;
		__u64 address_low;
		__u64 address_high;
		int wasted_entries;
		char __pad0[4];
		long total_entries;
		struct perf_branch_entry entries[32];
	} *bss;
};

static void
get_branch_snapshot__destroy(struct get_branch_snapshot *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
get_branch_snapshot__create_skeleton(struct get_branch_snapshot *obj);

static inline struct get_branch_snapshot *
get_branch_snapshot__open_opts(const struct bpf_object_open_opts *opts)
{
	struct get_branch_snapshot *obj;
	int err;

	obj = (struct get_branch_snapshot *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = get_branch_snapshot__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	get_branch_snapshot__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct get_branch_snapshot *
get_branch_snapshot__open(void)
{
	return get_branch_snapshot__open_opts(NULL);
}

static inline int
get_branch_snapshot__load(struct get_branch_snapshot *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct get_branch_snapshot *
get_branch_snapshot__open_and_load(void)
{
	struct get_branch_snapshot *obj;
	int err;

	obj = get_branch_snapshot__open();
	if (!obj)
		return NULL;
	err = get_branch_snapshot__load(obj);
	if (err) {
		get_branch_snapshot__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
get_branch_snapshot__attach(struct get_branch_snapshot *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
get_branch_snapshot__detach(struct get_branch_snapshot *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *get_branch_snapshot__elf_bytes(size_t *sz);

static inline int
get_branch_snapshot__create_skeleton(struct get_branch_snapshot *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "get_branch_snapshot";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "get_bran.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "test1";
	s->progs[0].prog = &obj->progs.test1;
	s->progs[0].link = &obj->links.test1;

	s->data = (void *)get_branch_snapshot__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *get_branch_snapshot__elf_bytes(size_t *sz)
{
	*sz = 3432;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x28\x0b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x65\
\x78\x69\x74\x2f\x62\x70\x66\x5f\x74\x65\x73\x74\x6d\x6f\x64\x5f\x6c\x6f\x6f\
\x70\x5f\x74\x65\x73\x74\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x67\
\x65\x74\x5f\x62\x72\x61\x6e\x63\x68\x5f\x73\x6e\x61\x70\x73\x68\x6f\x74\x2e\
\x63\0\x4c\x42\x42\x30\x5f\x31\x31\0\x4c\x42\x42\x30\x5f\x32\0\x4c\x42\x42\x30\
\x5f\x39\0\x4c\x42\x42\x30\x5f\x37\0\x74\x65\x73\x74\x31\0\x65\x6e\x74\x72\x69\
\x65\x73\0\x74\x6f\x74\x61\x6c\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x61\x64\x64\
\x72\x65\x73\x73\x5f\x68\x69\x67\x68\0\x61\x64\x64\x72\x65\x73\x73\x5f\x6c\x6f\
\x77\0\x77\x61\x73\x74\x65\x64\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x74\x65\x73\
\x74\x31\x5f\x68\x69\x74\x73\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\
\x6c\x66\x65\x78\x69\x74\x2f\x62\x70\x66\x5f\x74\x65\x73\x74\x6d\x6f\x64\x5f\
\x6c\x6f\x6f\x70\x5f\x74\x65\x73\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\
\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3a\0\
\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x50\0\0\0\0\0\x03\0\x28\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x58\0\0\0\0\0\x03\0\x38\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5f\0\0\0\0\0\x03\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x66\0\0\0\0\0\x03\0\x88\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x6d\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\x73\0\0\
\0\x11\0\x05\0\x28\0\0\0\0\0\0\0\0\x03\0\0\0\0\0\0\x7b\0\0\0\x11\0\x05\0\x20\0\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x89\0\0\0\x11\0\x05\0\x10\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\x96\0\0\0\x11\0\x05\0\x08\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\xa2\0\0\0\
\x11\0\x05\0\x18\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb1\0\0\0\x11\0\x05\0\0\0\0\0\
\0\0\0\0\x08\0\0\0\0\0\0\0\xbc\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\
\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x07\0\0\0\0\0\0\x18\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xb4\x02\0\0\0\x03\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xb0\0\0\
\0\xbf\x01\0\0\0\0\0\0\x37\x01\0\0\x18\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x7b\x12\0\0\0\0\0\0\xa5\0\x17\0\x18\0\0\0\xb7\x03\0\0\x08\0\0\0\xb7\x04\0\0\
\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x42\0\0\0\0\0\0\x0f\x36\0\0\0\
\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x79\x33\0\0\0\0\0\0\x18\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x79\x44\0\0\0\0\0\0\x18\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x50\0\0\0\0\0\0\x18\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x05\0\x07\0\0\0\0\0\
\x25\x07\x04\0\x1e\0\0\0\x07\x02\0\0\x18\0\0\0\x07\x06\0\0\x18\0\0\0\x07\x07\0\
\0\x01\0\0\0\xad\x17\x02\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x79\x29\
\0\0\0\0\0\0\x2d\x94\x08\0\0\0\0\0\xbd\x93\x07\0\0\0\0\0\x79\x69\0\0\0\0\0\0\
\x2d\x94\x05\0\0\0\0\0\xbd\x93\x04\0\0\0\0\0\x79\x89\0\0\0\0\0\0\x07\x09\0\0\
\x01\0\0\0\x7b\x98\0\0\0\0\0\0\x05\0\xef\xff\0\0\0\0\x79\x89\0\0\0\0\0\0\x55\
\x09\xed\xff\0\0\0\0\x04\0\0\0\x01\0\0\0\x63\x05\0\0\0\0\0\0\x05\0\xea\xff\0\0\
\0\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x18\0\0\0\0\0\0\
\0\x01\0\0\0\x08\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\x09\0\0\0\x80\0\0\0\0\0\0\0\
\x01\0\0\0\x08\0\0\0\xa0\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\xb8\0\0\0\0\0\0\0\
\x01\0\0\0\x0b\0\0\0\xd0\0\0\0\0\0\0\0\x01\0\0\0\x0c\0\0\0\xe8\0\0\0\0\0\0\0\
\x01\0\0\0\x0d\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x0c\x02\0\0\x0c\x02\0\0\
\xdb\x02\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\
\0\0\0\0\0\x01\0\0\x0d\x04\0\0\0\x14\0\0\0\x01\0\0\0\x18\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\x01\x1c\0\0\0\x01\0\0\x0c\x03\0\0\0\x22\0\0\0\x09\0\0\x84\x18\0\0\
\0\x34\0\0\0\x07\0\0\0\0\0\0\0\x39\0\0\0\x07\0\0\0\x40\0\0\0\x3c\0\0\0\x07\0\0\
\0\x80\0\0\x01\x44\0\0\0\x07\0\0\0\x81\0\0\x01\x4e\0\0\0\x07\0\0\0\x82\0\0\x01\
\x54\0\0\0\x07\0\0\0\x83\0\0\x01\x5a\0\0\0\x07\0\0\0\x84\0\0\x10\x61\0\0\0\x07\
\0\0\0\x94\0\0\x04\x66\0\0\0\x07\0\0\0\x98\0\0\x28\x6f\0\0\0\0\0\0\x08\x02\0\0\
\0\x75\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x08\0\0\
\0\x0a\0\0\0\x04\0\0\0\x7a\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x8e\0\0\0\0\0\0\
\x0e\x09\0\0\0\x01\0\0\0\x97\0\0\0\0\0\0\x0e\x07\0\0\0\x01\0\0\0\xa2\0\0\0\0\0\
\0\x0e\x07\0\0\0\x01\0\0\0\xae\0\0\0\0\0\0\x0e\x07\0\0\0\x01\0\0\0\xbb\0\0\0\0\
\0\0\x0e\x04\0\0\0\x01\0\0\0\xca\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\x01\xcf\0\0\
\0\0\0\0\x0e\x10\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x06\0\0\0\x0a\0\0\0\
\x20\0\0\0\xdd\0\0\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\xb2\x02\0\0\x01\0\0\x0f\x04\
\0\0\0\x0b\0\0\0\0\0\0\0\x04\0\0\0\xba\x02\0\0\x06\0\0\x0f\x28\x03\0\0\x0c\0\0\
\0\0\0\0\0\x08\0\0\0\x0d\0\0\0\x08\0\0\0\x08\0\0\0\x0e\0\0\0\x10\0\0\0\x08\0\0\
\0\x0f\0\0\0\x18\0\0\0\x04\0\0\0\x11\0\0\0\x20\0\0\0\x08\0\0\0\x13\0\0\0\x28\0\
\0\0\0\x03\0\0\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\
\x6f\x6e\x67\0\x63\x74\x78\0\x69\x6e\x74\0\x74\x65\x73\x74\x31\0\x70\x65\x72\
\x66\x5f\x62\x72\x61\x6e\x63\x68\x5f\x65\x6e\x74\x72\x79\0\x66\x72\x6f\x6d\0\
\x74\x6f\0\x6d\x69\x73\x70\x72\x65\x64\0\x70\x72\x65\x64\x69\x63\x74\x65\x64\0\
\x69\x6e\x5f\x74\x78\0\x61\x62\x6f\x72\x74\0\x63\x79\x63\x6c\x65\x73\0\x74\x79\
\x70\x65\0\x72\x65\x73\x65\x72\x76\x65\x64\0\x5f\x5f\x75\x36\x34\0\x63\x68\x61\
\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\
\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x31\x5f\x68\x69\x74\
\x73\0\x61\x64\x64\x72\x65\x73\x73\x5f\x6c\x6f\x77\0\x61\x64\x64\x72\x65\x73\
\x73\x5f\x68\x69\x67\x68\0\x77\x61\x73\x74\x65\x64\x5f\x65\x6e\x74\x72\x69\x65\
\x73\0\x6c\x6f\x6e\x67\0\x74\x6f\x74\x61\x6c\x5f\x65\x6e\x74\x72\x69\x65\x73\0\
\x65\x6e\x74\x72\x69\x65\x73\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\
\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\
\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\
\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\
\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\
\x66\x2f\x70\x72\x6f\x67\x73\x2f\x67\x65\x74\x5f\x62\x72\x61\x6e\x63\x68\x5f\
\x73\x6e\x61\x70\x73\x68\x6f\x74\x2e\x63\0\x09\x74\x6f\x74\x61\x6c\x5f\x65\x6e\
\x74\x72\x69\x65\x73\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x62\x72\x61\
\x6e\x63\x68\x5f\x73\x6e\x61\x70\x73\x68\x6f\x74\x28\x65\x6e\x74\x72\x69\x65\
\x73\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x65\x6e\x74\x72\x69\x65\x73\x29\x2c\
\x20\x30\x29\x3b\0\x09\x74\x6f\x74\x61\x6c\x5f\x65\x6e\x74\x72\x69\x65\x73\x20\
\x2f\x3d\x20\x73\x69\x7a\x65\x6f\x66\x28\x73\x74\x72\x75\x63\x74\x20\x70\x65\
\x72\x66\x5f\x62\x72\x61\x6e\x63\x68\x5f\x65\x6e\x74\x72\x79\x29\x3b\0\x09\x66\
\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\x20\x3c\x20\x45\x4e\x54\x52\
\x59\x5f\x43\x4e\x54\x3b\x20\x69\x2b\x2b\x29\x20\x7b\0\x69\x6e\x74\x20\x42\x50\
\x46\x5f\x50\x52\x4f\x47\x28\x74\x65\x73\x74\x31\x2c\x20\x69\x6e\x74\x20\x6e\
\x2c\x20\x69\x6e\x74\x20\x72\x65\x74\x29\0\x09\x09\x69\x66\x20\x28\x69\x6e\x5f\
\x72\x61\x6e\x67\x65\x28\x65\x6e\x74\x72\x69\x65\x73\x5b\x69\x5d\x2e\x66\x72\
\x6f\x6d\x29\x20\x26\x26\x20\x69\x6e\x5f\x72\x61\x6e\x67\x65\x28\x65\x6e\x74\
\x72\x69\x65\x73\x5b\x69\x5d\x2e\x74\x6f\x29\x29\0\x09\x09\x09\x74\x65\x73\x74\
\x31\x5f\x68\x69\x74\x73\x2b\x2b\x3b\0\x09\x09\x65\x6c\x73\x65\x20\x69\x66\x20\
\x28\x21\x74\x65\x73\x74\x31\x5f\x68\x69\x74\x73\x29\0\x09\x09\x09\x77\x61\x73\
\x74\x65\x64\x5f\x65\x6e\x74\x72\x69\x65\x73\x2b\x2b\x3b\0\x30\x3a\x31\0\x30\
\x3a\x30\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x66\x65\x78\x69\x74\
\x2f\x62\x70\x66\x5f\x74\x65\x73\x74\x6d\x6f\x64\x5f\x6c\x6f\x6f\x70\x5f\x74\
\x65\x73\x74\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xec\0\0\0\
\0\x01\0\0\x2c\0\0\0\x08\0\0\0\xbf\x02\0\0\x01\0\0\0\0\0\0\0\x05\0\0\0\x10\0\0\
\0\xbf\x02\0\0\x0e\0\0\0\0\0\0\0\xe5\0\0\0\x6e\x01\0\0\x12\x70\0\0\x40\0\0\0\
\xe5\0\0\0\xb5\x01\0\0\x10\x74\0\0\x68\0\0\0\xe5\0\0\0\xe9\x01\0\0\x02\x7c\0\0\
\x08\x01\0\0\xe5\0\0\0\0\0\0\0\0\0\0\0\x20\x01\0\0\xe5\0\0\0\xe9\x01\0\0\x02\
\x7c\0\0\x28\x01\0\0\xe5\0\0\0\x0c\x02\0\0\x05\x60\0\0\x38\x01\0\0\xe5\0\0\0\
\x30\x02\0\0\x1b\x88\0\0\x40\x01\0\0\xe5\0\0\0\x30\x02\0\0\x21\x88\0\0\x50\x01\
\0\0\xe5\0\0\0\x30\x02\0\0\x38\x88\0\0\x58\x01\0\0\xe5\0\0\0\x30\x02\0\0\x07\
\x88\0\0\x68\x01\0\0\xe5\0\0\0\x6c\x02\0\0\x0e\x8c\0\0\x88\x01\0\0\xe5\0\0\0\
\x7d\x02\0\0\x0d\x90\0\0\x90\x01\0\0\xe5\0\0\0\x7d\x02\0\0\x0c\x90\0\0\x98\x01\
\0\0\xe5\0\0\0\x95\x02\0\0\x12\x94\0\0\x10\0\0\0\xbf\x02\0\0\x02\0\0\0\x70\0\0\
\0\x06\0\0\0\xaa\x02\0\0\0\0\0\0\x78\0\0\0\x06\0\0\0\xae\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xf3\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x38\x01\0\0\0\0\0\0\x68\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\
\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xa0\x02\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x2d\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x04\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x35\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x04\0\0\0\0\0\0\x28\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc5\0\0\0\
\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x04\0\0\0\0\0\0\x80\0\0\0\0\0\
\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xe5\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\x04\0\0\0\0\0\0\xff\x04\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xea\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xd8\x09\0\0\0\0\0\0\x4c\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __GET_BRANCH_SNAPSHOT_SKEL_H__ */
