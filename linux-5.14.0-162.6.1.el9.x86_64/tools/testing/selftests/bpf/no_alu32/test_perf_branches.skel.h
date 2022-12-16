/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_PERF_BRANCHES_SKEL_H__
#define __TEST_PERF_BRANCHES_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_perf_branches {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *perf_branches;
	} progs;
	struct {
		struct bpf_link *perf_branches;
	} links;
	struct test_perf_branches__bss {
		int valid;
		int required_size_out;
		int written_stack_out;
		int written_global_out;
		struct {
			__u64 _a;
			__u64 _b;
			__u64 _c;
		} fpbe[30];
	} *bss;
};

static void
test_perf_branches__destroy(struct test_perf_branches *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_perf_branches__create_skeleton(struct test_perf_branches *obj);

static inline struct test_perf_branches *
test_perf_branches__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_perf_branches *obj;
	int err;

	obj = (struct test_perf_branches *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_perf_branches__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_perf_branches__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_perf_branches *
test_perf_branches__open(void)
{
	return test_perf_branches__open_opts(NULL);
}

static inline int
test_perf_branches__load(struct test_perf_branches *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_perf_branches *
test_perf_branches__open_and_load(void)
{
	struct test_perf_branches *obj;
	int err;

	obj = test_perf_branches__open();
	if (!obj)
		return NULL;
	err = test_perf_branches__load(obj);
	if (err) {
		test_perf_branches__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_perf_branches__attach(struct test_perf_branches *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_perf_branches__detach(struct test_perf_branches *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_perf_branches__elf_bytes(size_t *sz);

static inline int
test_perf_branches__create_skeleton(struct test_perf_branches *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_perf_branches";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_per.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "perf_branches";
	s->progs[0].prog = &obj->progs.perf_branches;
	s->progs[0].link = &obj->links.perf_branches;

	s->data = (void *)test_perf_branches__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_perf_branches__elf_bytes(size_t *sz)
{
	*sz = 3104;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xe0\x09\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x70\x65\
\x72\x66\x5f\x65\x76\x65\x6e\x74\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x74\x65\x73\x74\x5f\x70\x65\x72\x66\x5f\x62\x72\x61\x6e\x63\x68\x65\x73\
\x2e\x63\0\x4c\x42\x42\x30\x5f\x33\0\x70\x65\x72\x66\x5f\x62\x72\x61\x6e\x63\
\x68\x65\x73\0\x66\x70\x62\x65\0\x77\x72\x69\x74\x74\x65\x6e\x5f\x73\x74\x61\
\x63\x6b\x5f\x6f\x75\x74\0\x72\x65\x71\x75\x69\x72\x65\x64\x5f\x73\x69\x7a\x65\
\x5f\x6f\x75\x74\0\x77\x72\x69\x74\x74\x65\x6e\x5f\x67\x6c\x6f\x62\x61\x6c\x5f\
\x6f\x75\x74\0\x76\x61\x6c\x69\x64\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\
\x65\x6c\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\0\x2e\x42\x54\x46\0\x2e\x42\
\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x29\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3e\0\0\0\0\0\x03\0\xc8\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x45\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xd8\x01\0\0\0\0\0\0\x53\
\0\0\0\x11\0\x04\0\x10\0\0\0\0\0\0\0\xd0\x02\0\0\0\0\0\0\x58\0\0\0\x11\0\x04\0\
\x08\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x6a\0\0\0\x11\0\x04\0\x04\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\x7c\0\0\0\x11\0\x04\0\x0c\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x8f\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x95\0\0\0\x11\0\x05\0\
\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xbf\x16\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\
\x1a\xf8\xff\0\0\0\0\x7b\x1a\xf0\xff\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\x7b\x1a\
\xe0\xff\0\0\0\0\x7b\x1a\xd8\xff\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\x7b\x1a\xc8\
\xff\0\0\0\0\x7b\x1a\xc0\xff\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x7b\x1a\xb0\xff\0\
\0\0\0\x7b\x1a\xa8\xff\0\0\0\0\x7b\x1a\xa0\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\
\x02\0\0\xa0\xff\xff\xff\xbf\x61\0\0\0\0\0\0\xb7\x03\0\0\x60\0\0\0\xb7\x04\0\0\
\0\0\0\0\x85\0\0\0\x77\0\0\0\xbf\x07\0\0\0\0\0\0\xb7\x08\0\0\x01\0\0\0\xbf\x71\
\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\0\x20\0\0\0\x15\x01\x1f\0\0\0\0\0\
\xb7\x08\0\0\x01\0\0\0\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\xb7\x03\0\0\0\0\
\0\0\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x77\0\0\0\xbf\x09\0\0\0\0\0\0\xbf\x61\0\0\
\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\xd0\x02\0\0\xb7\x04\0\
\0\0\0\0\0\x85\0\0\0\x77\0\0\0\xbf\x01\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\
\x01\0\0\x20\0\0\0\x15\x01\x0e\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x63\x71\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x91\0\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xb7\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\xb7\x08\0\0\0\0\0\0\
\xbf\x80\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x10\x01\0\0\0\0\0\
\0\x01\0\0\0\x05\0\0\0\x58\x01\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x70\x01\0\0\0\0\
\0\0\x01\0\0\0\x07\0\0\0\x88\x01\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\xa0\x01\0\0\0\
\0\0\0\x01\0\0\0\x09\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x98\x01\0\0\x98\x01\
\0\0\xe8\x02\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\
\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\
\x02\0\0\0\x17\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x1d\0\0\0\0\0\0\x0e\x03\0\0\
\0\x01\0\0\0\x2f\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x41\0\0\0\0\0\0\x0e\x03\0\
\0\0\x01\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\x54\0\0\0\x0a\0\0\0\0\0\0\0\x57\0\
\0\0\x0a\0\0\0\x40\0\0\0\x5a\0\0\0\x0a\0\0\0\x80\0\0\0\x5d\0\0\0\0\0\0\x08\x0b\
\0\0\0\x63\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x09\0\
\0\0\x0d\0\0\0\x1e\0\0\0\x76\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x8a\0\0\0\0\0\
\0\x0e\x0c\0\0\0\x01\0\0\0\x8f\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\
\0\0\x03\0\0\0\0\x0f\0\0\0\x0d\0\0\0\x04\0\0\0\x94\0\0\0\0\0\0\x0e\x10\0\0\0\
\x01\0\0\0\xd0\x02\0\0\x05\0\0\x0f\xe0\x02\0\0\x05\0\0\0\0\0\0\0\x04\0\0\0\x06\
\0\0\0\x04\0\0\0\x04\0\0\0\x07\0\0\0\x08\0\0\0\x04\0\0\0\x08\0\0\0\x0c\0\0\0\
\x04\0\0\0\x0e\0\0\0\x10\0\0\0\xd0\x02\0\0\xd5\x02\0\0\x01\0\0\x0f\x04\0\0\0\
\x11\0\0\0\0\0\0\0\x04\0\0\0\0\x63\x74\x78\0\x69\x6e\x74\0\x70\x65\x72\x66\x5f\
\x62\x72\x61\x6e\x63\x68\x65\x73\0\x76\x61\x6c\x69\x64\0\x72\x65\x71\x75\x69\
\x72\x65\x64\x5f\x73\x69\x7a\x65\x5f\x6f\x75\x74\0\x77\x72\x69\x74\x74\x65\x6e\
\x5f\x73\x74\x61\x63\x6b\x5f\x6f\x75\x74\0\x77\x72\x69\x74\x74\x65\x6e\x5f\x67\
\x6c\x6f\x62\x61\x6c\x5f\x6f\x75\x74\0\x5f\x61\0\x5f\x62\0\x5f\x63\0\x5f\x5f\
\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\
\x6e\x67\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\
\x5f\x5f\0\x66\x70\x62\x65\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\
\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\
\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\
\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\
\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\
\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\
\x2f\x74\x65\x73\x74\x5f\x70\x65\x72\x66\x5f\x62\x72\x61\x6e\x63\x68\x65\x73\
\x2e\x63\0\x69\x6e\x74\x20\x70\x65\x72\x66\x5f\x62\x72\x61\x6e\x63\x68\x65\x73\
\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x5f\x5f\x75\x36\x34\x20\x65\
\x6e\x74\x72\x69\x65\x73\x5b\x34\x20\x2a\x20\x33\x5d\x20\x3d\x20\x7b\x30\x7d\
\x3b\0\x09\x77\x72\x69\x74\x74\x65\x6e\x5f\x73\x74\x61\x63\x6b\x20\x3d\x20\x62\
\x70\x66\x5f\x72\x65\x61\x64\x5f\x62\x72\x61\x6e\x63\x68\x5f\x72\x65\x63\x6f\
\x72\x64\x73\x28\x63\x74\x78\x2c\x20\x65\x6e\x74\x72\x69\x65\x73\x2c\x20\x73\
\x69\x7a\x65\x6f\x66\x28\x65\x6e\x74\x72\x69\x65\x73\x29\x2c\x20\x30\x29\x3b\0\
\x09\x69\x66\x20\x28\x21\x77\x72\x69\x74\x74\x65\x6e\x5f\x73\x74\x61\x63\x6b\
\x29\0\x09\x72\x65\x71\x75\x69\x72\x65\x64\x5f\x73\x69\x7a\x65\x20\x3d\x20\x62\
\x70\x66\x5f\x72\x65\x61\x64\x5f\x62\x72\x61\x6e\x63\x68\x5f\x72\x65\x63\x6f\
\x72\x64\x73\x28\x63\x74\x78\x2c\x20\x4e\x55\x4c\x4c\x2c\x20\x30\x2c\0\x09\x77\
\x72\x69\x74\x74\x65\x6e\x5f\x67\x6c\x6f\x62\x61\x6c\x20\x3d\x20\x62\x70\x66\
\x5f\x72\x65\x61\x64\x5f\x62\x72\x61\x6e\x63\x68\x5f\x72\x65\x63\x6f\x72\x64\
\x73\x28\x63\x74\x78\x2c\x20\x66\x70\x62\x65\x2c\x20\x73\x69\x7a\x65\x6f\x66\
\x28\x66\x70\x62\x65\x29\x2c\x20\x30\x29\x3b\0\x09\x69\x66\x20\x28\x21\x77\x72\
\x69\x74\x74\x65\x6e\x5f\x67\x6c\x6f\x62\x61\x6c\x29\0\x09\x77\x72\x69\x74\x74\
\x65\x6e\x5f\x73\x74\x61\x63\x6b\x5f\x6f\x75\x74\x20\x3d\x20\x77\x72\x69\x74\
\x74\x65\x6e\x5f\x73\x74\x61\x63\x6b\x3b\0\x09\x72\x65\x71\x75\x69\x72\x65\x64\
\x5f\x73\x69\x7a\x65\x5f\x6f\x75\x74\x20\x3d\x20\x72\x65\x71\x75\x69\x72\x65\
\x64\x5f\x73\x69\x7a\x65\x3b\0\x09\x77\x72\x69\x74\x74\x65\x6e\x5f\x67\x6c\x6f\
\x62\x61\x6c\x5f\x6f\x75\x74\x20\x3d\x20\x77\x72\x69\x74\x74\x65\x6e\x5f\x67\
\x6c\x6f\x62\x61\x6c\x3b\0\x09\x76\x61\x6c\x69\x64\x20\x3d\x20\x31\x3b\0\x7d\0\
\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x70\x65\x72\x66\x5f\x65\x76\
\x65\x6e\x74\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xdc\0\0\0\
\xf0\0\0\0\0\0\0\0\x08\0\0\0\xdd\x02\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\
\xdd\x02\0\0\x0d\0\0\0\0\0\0\0\x9d\0\0\0\x25\x01\0\0\0\x58\0\0\x10\0\0\0\x9d\0\
\0\0\x42\x01\0\0\x08\x60\0\0\x78\0\0\0\x9d\0\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\x9d\
\0\0\0\x5f\x01\0\0\x12\x70\0\0\xc8\0\0\0\x9d\0\0\0\xab\x01\0\0\x06\x78\0\0\xd8\
\0\0\0\x9d\0\0\0\xc0\x01\0\0\x12\x88\0\0\x08\x01\0\0\x9d\0\0\0\xf7\x01\0\0\x13\
\x94\0\0\x50\x01\0\0\x9d\0\0\0\x3e\x02\0\0\x06\x9c\0\0\x58\x01\0\0\x9d\0\0\0\
\x54\x02\0\0\x14\xac\0\0\x70\x01\0\0\x9d\0\0\0\x78\x02\0\0\x14\xa8\0\0\x88\x01\
\0\0\x9d\0\0\0\x9c\x02\0\0\x15\xb0\0\0\xa0\x01\0\0\x9d\0\0\0\xc2\x02\0\0\x08\
\xb4\0\0\xc8\x01\0\0\x9d\0\0\0\xce\x02\0\0\x01\xc0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x40\0\0\0\0\0\0\0\xbb\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\x08\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\
\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x02\0\0\0\0\0\0\xd8\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1c\0\0\0\
\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x03\0\0\0\0\0\0\xe0\x02\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x21\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9e\0\0\0\x09\0\0\0\x40\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xe8\x03\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\
\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xad\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x38\x04\0\0\0\0\0\0\x98\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb2\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\
\x08\0\0\0\0\0\0\x10\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0";
}

#endif /* __TEST_PERF_BRANCHES_SKEL_H__ */