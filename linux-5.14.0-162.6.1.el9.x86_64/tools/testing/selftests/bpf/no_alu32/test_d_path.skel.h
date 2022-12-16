/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_D_PATH_SKEL_H__
#define __TEST_D_PATH_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_d_path {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *prog_stat;
		struct bpf_program *prog_close;
	} progs;
	struct {
		struct bpf_link *prog_stat;
		struct bpf_link *prog_close;
	} links;
	struct test_d_path__bss {
		pid_t my_pid;
		__u32 cnt_stat;
		__u32 cnt_close;
		char paths_stat[7][128];
		char paths_close[7][128];
		int rets_stat[7];
		int rets_close[7];
		int called_stat;
		int called_close;
	} *bss;
};

static void
test_d_path__destroy(struct test_d_path *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_d_path__create_skeleton(struct test_d_path *obj);

static inline struct test_d_path *
test_d_path__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_d_path *obj;
	int err;

	obj = (struct test_d_path *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_d_path__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_d_path__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_d_path *
test_d_path__open(void)
{
	return test_d_path__open_opts(NULL);
}

static inline int
test_d_path__load(struct test_d_path *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_d_path *
test_d_path__open_and_load(void)
{
	struct test_d_path *obj;
	int err;

	obj = test_d_path__open();
	if (!obj)
		return NULL;
	err = test_d_path__load(obj);
	if (err) {
		test_d_path__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_d_path__attach(struct test_d_path *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_d_path__detach(struct test_d_path *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_d_path__elf_bytes(size_t *sz);

static inline int
test_d_path__create_skeleton(struct test_d_path *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_d_path";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_d_p.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "prog_stat";
	s->progs[0].prog = &obj->progs.prog_stat;
	s->progs[0].link = &obj->links.prog_stat;

	s->progs[1].name = "prog_close";
	s->progs[1].prog = &obj->progs.prog_close;
	s->progs[1].link = &obj->links.prog_close;

	s->data = (void *)test_d_path__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_d_path__elf_bytes(size_t *sz)
{
	*sz = 7224;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x78\x19\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x65\
\x6e\x74\x72\x79\x2f\x73\x65\x63\x75\x72\x69\x74\x79\x5f\x69\x6e\x6f\x64\x65\
\x5f\x67\x65\x74\x61\x74\x74\x72\0\x66\x65\x6e\x74\x72\x79\x2f\x66\x69\x6c\x70\
\x5f\x63\x6c\x6f\x73\x65\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\
\x65\x73\x74\x5f\x64\x5f\x70\x61\x74\x68\x2e\x63\0\x4c\x42\x42\x30\x5f\x33\0\
\x4c\x42\x42\x31\x5f\x33\0\x70\x72\x6f\x67\x5f\x73\x74\x61\x74\0\x63\x61\x6c\
\x6c\x65\x64\x5f\x73\x74\x61\x74\0\x6d\x79\x5f\x70\x69\x64\0\x63\x6e\x74\x5f\
\x73\x74\x61\x74\0\x70\x61\x74\x68\x73\x5f\x73\x74\x61\x74\0\x72\x65\x74\x73\
\x5f\x73\x74\x61\x74\0\x70\x72\x6f\x67\x5f\x63\x6c\x6f\x73\x65\0\x63\x61\x6c\
\x6c\x65\x64\x5f\x63\x6c\x6f\x73\x65\0\x63\x6e\x74\x5f\x63\x6c\x6f\x73\x65\0\
\x70\x61\x74\x68\x73\x5f\x63\x6c\x6f\x73\x65\0\x72\x65\x74\x73\x5f\x63\x6c\x6f\
\x73\x65\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\
\x72\x79\x2f\x73\x65\x63\x75\x72\x69\x74\x79\x5f\x69\x6e\x6f\x64\x65\x5f\x67\
\x65\x74\x61\x74\x74\x72\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2f\x66\x69\
\x6c\x70\x5f\x63\x6c\x6f\x73\x65\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\
\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4e\0\0\0\x04\
\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x5c\0\0\0\0\0\x03\0\x08\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\0\0\0\0\0\x04\0\x18\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x6a\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\x74\0\0\0\x11\0\x05\0\x44\x07\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x80\0\0\0\x11\
\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x87\0\0\0\x11\0\x05\0\x04\0\0\0\0\0\
\0\0\x04\0\0\0\0\0\0\0\x90\0\0\0\x11\0\x05\0\x0c\0\0\0\0\0\0\0\x80\x03\0\0\0\0\
\0\0\x9b\0\0\0\x11\0\x05\0\x0c\x07\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\xa5\0\0\0\x12\
\0\x04\0\0\0\0\0\0\0\0\0\x28\x01\0\0\0\0\0\0\xb0\0\0\0\x11\0\x05\0\x48\x07\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\xbd\0\0\0\x11\0\x05\0\x08\0\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\xc7\0\0\0\x11\0\x05\0\x8c\x03\0\0\0\0\0\0\x80\x03\0\0\0\0\0\0\xd3\0\0\0\
\x11\0\x05\0\x28\x07\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\xde\0\0\0\x11\0\x06\0\0\0\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\x79\x16\0\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x18\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\x77\0\0\0\
\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\x16\
\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x17\0\0\0\0\0\0\x25\x07\x12\
\0\x06\0\0\0\xbf\x71\0\0\0\0\0\0\x67\x01\0\0\x07\0\0\0\x18\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x0f\x12\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xb7\x03\0\0\x80\0\0\0\x85\
\0\0\0\x93\0\0\0\x67\x07\0\0\x02\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\
\x71\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\
\x12\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x79\x16\0\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x18\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xb7\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\x77\0\0\0\x20\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\x18\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x17\0\0\0\0\0\0\x25\x07\x14\0\x06\0\0\
\0\xb7\x01\0\0\x10\0\0\0\x0f\x16\0\0\0\0\0\0\xbf\x71\0\0\0\0\0\0\x67\x01\0\0\
\x07\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x12\0\0\0\0\0\0\xbf\x61\0\0\
\0\0\0\0\xb7\x03\0\0\x80\0\0\0\x85\0\0\0\x93\0\0\0\x67\x07\0\0\x02\0\0\0\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x71\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x12\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\x63\
\x21\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x10\
\0\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x38\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x58\0\
\0\0\0\0\0\0\x01\0\0\0\x09\0\0\0\x88\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\xc0\0\0\
\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\xe0\0\0\0\0\0\0\0\x01\0\0\0\x09\0\0\0\x10\0\0\0\
\0\0\0\0\x01\0\0\0\x0d\0\0\0\x38\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x58\0\0\0\0\
\0\0\0\x01\0\0\0\x0e\0\0\0\x98\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\xd0\0\0\0\0\0\
\0\0\x01\0\0\0\x10\0\0\0\xf0\0\0\0\0\0\0\0\x01\0\0\0\x0e\0\0\0\x9f\xeb\x01\0\
\x18\0\0\0\0\0\0\0\x9c\x09\0\0\x9c\x09\0\0\x5f\x07\0\0\0\0\0\0\0\0\0\x02\x02\0\
\0\0\x01\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x04\0\0\0\x14\
\0\0\0\x01\0\0\0\x18\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x1c\0\0\0\x01\0\0\
\x0c\x03\0\0\0\x26\0\0\0\x01\0\0\x0c\x03\0\0\0\x31\0\0\0\x15\0\0\x04\xe8\0\0\0\
\x36\0\0\0\x08\0\0\0\0\0\0\0\x3a\0\0\0\x0f\0\0\0\x80\0\0\0\x41\0\0\0\x12\0\0\0\
\0\x01\0\0\x49\0\0\0\x13\0\0\0\x40\x01\0\0\x4e\0\0\0\x15\0\0\0\x80\x01\0\0\x55\
\0\0\0\x26\0\0\0\xa0\x01\0\0\x62\0\0\0\x27\0\0\0\xc0\x01\0\0\x6a\0\0\0\x2d\0\0\
\0\0\x02\0\0\x72\0\0\0\x2e\0\0\0\x20\x02\0\0\x79\0\0\0\x2f\0\0\0\x40\x02\0\0\
\x84\0\0\0\x34\0\0\0\x40\x03\0\0\x8a\0\0\0\x36\0\0\0\x80\x03\0\0\x92\0\0\0\x45\
\0\0\0\x80\x04\0\0\x99\0\0\0\x47\0\0\0\xc0\x04\0\0\x9e\0\0\0\x49\0\0\0\xc0\x05\
\0\0\xa8\0\0\0\x4b\0\0\0\0\x06\0\0\xb3\0\0\0\x4b\0\0\0\x40\x06\0\0\xc0\0\0\0\
\x4c\0\0\0\x80\x06\0\0\xc5\0\0\0\x4d\0\0\0\xc0\x06\0\0\xcf\0\0\0\x4e\0\0\0\0\
\x07\0\0\xd8\0\0\0\x4e\0\0\0\x20\x07\0\0\0\0\0\0\x02\0\0\x05\x10\0\0\0\xe1\0\0\
\0\x09\0\0\0\0\0\0\0\xea\0\0\0\x0b\0\0\0\0\0\0\0\xf5\0\0\0\x01\0\0\x04\x08\0\0\
\0\0\x01\0\0\x0a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x09\0\0\0\x05\x01\0\0\x02\0\0\
\x04\x10\0\0\0\0\x01\0\0\x0c\0\0\0\0\0\0\0\x13\x01\0\0\x0d\0\0\0\x40\0\0\0\0\0\
\0\0\0\0\0\x02\x0b\0\0\0\0\0\0\0\0\0\0\x02\x0e\0\0\0\0\0\0\0\x01\0\0\x0d\0\0\0\
\0\0\0\0\0\x0c\0\0\0\x18\x01\0\0\x02\0\0\x04\x10\0\0\0\x1d\x01\0\0\x10\0\0\0\0\
\0\0\0\x21\x01\0\0\x11\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\x02\x69\0\0\0\0\0\0\0\0\0\
\0\x02\x64\0\0\0\0\0\0\0\0\0\0\x02\x67\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\0\0\0\
\0\0\0\0\x0a\x65\0\0\0\x28\x01\0\0\0\0\0\x08\x16\0\0\0\x33\x01\0\0\x01\0\0\x04\
\x04\0\0\0\0\0\0\0\x17\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\x05\x04\0\0\0\x3c\x01\0\0\
\x18\0\0\0\0\0\0\0\x42\x01\0\0\x01\0\0\x04\x04\0\0\0\x4f\x01\0\0\x19\0\0\0\0\0\
\0\0\x58\x01\0\0\0\0\0\x08\x1a\0\0\0\x68\x01\0\0\x01\0\0\x04\x04\0\0\0\0\0\0\0\
\x1b\0\0\0\0\0\0\0\0\0\0\0\x03\0\0\x05\x04\0\0\0\x72\x01\0\0\x1c\0\0\0\0\0\0\0\
\0\0\0\0\x1e\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\0\0\0\0\x76\x01\0\0\0\0\0\x08\x1d\
\0\0\0\0\0\0\0\x01\0\0\x04\x04\0\0\0\x7f\x01\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\x02\
\0\0\x04\x02\0\0\0\x87\x01\0\0\x1f\0\0\0\0\0\0\0\x8e\x01\0\0\x1f\0\0\0\x08\0\0\
\0\x96\x01\0\0\0\0\0\x08\x20\0\0\0\x99\x01\0\0\0\0\0\x08\x21\0\0\0\x9e\x01\0\0\
\0\0\0\x01\x01\0\0\0\x08\0\0\0\0\0\0\0\x02\0\0\x04\x04\0\0\0\xac\x01\0\0\x23\0\
\0\0\0\0\0\0\xbb\x01\0\0\x23\0\0\0\x10\0\0\0\xc0\x01\0\0\0\0\0\x08\x24\0\0\0\
\xc4\x01\0\0\0\0\0\x08\x25\0\0\0\xca\x01\0\0\0\0\0\x01\x02\0\0\0\x10\0\0\0\xd9\
\x01\0\0\x06\0\0\x06\x04\0\0\0\xe1\x01\0\0\0\0\0\0\xf4\x01\0\0\x01\0\0\0\x04\
\x02\0\0\x02\0\0\0\x15\x02\0\0\x03\0\0\0\x27\x02\0\0\x04\0\0\0\x37\x02\0\0\x05\
\0\0\0\x4a\x02\0\0\0\0\0\x08\x28\0\0\0\x58\x02\0\0\0\0\0\x08\x29\0\0\0\0\0\0\0\
\x01\0\0\x04\x08\0\0\0\x7f\x01\0\0\x2a\0\0\0\0\0\0\0\x63\x02\0\0\0\0\0\x08\x2b\
\0\0\0\x67\x02\0\0\0\0\0\x08\x2c\0\0\0\x6d\x02\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\
\x01\x77\x02\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x84\x02\0\0\0\0\0\x08\x2d\0\0\0\
\x8c\x02\0\0\x04\0\0\x04\x20\0\0\0\x92\x02\0\0\x27\0\0\0\0\0\0\0\x98\x02\0\0\
\x30\0\0\0\x40\0\0\0\xa2\x02\0\0\x31\0\0\0\x60\0\0\0\xa6\x02\0\0\x32\0\0\0\x80\
\0\0\0\xb0\x02\0\0\0\0\0\x08\x18\0\0\0\xbf\x02\0\0\x01\0\0\x04\x04\0\0\0\xbb\
\x01\0\0\x1c\0\0\0\0\0\0\0\xd5\x02\0\0\x02\0\0\x04\x10\0\0\0\0\x01\0\0\x33\0\0\
\0\0\0\0\0\xdf\x02\0\0\x33\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\x02\x32\0\0\0\xe4\x02\
\0\0\0\0\0\x08\x35\0\0\0\xeb\x02\0\0\0\0\0\x08\x2c\0\0\0\xfb\x02\0\0\x06\0\0\
\x04\x20\0\0\0\x07\x03\0\0\x37\0\0\0\0\0\0\0\x0c\x03\0\0\x3f\0\0\0\x40\0\0\0\
\x10\x03\0\0\x40\0\0\0\x80\0\0\0\x19\x03\0\0\x41\0\0\0\xa0\0\0\0\x1d\x03\0\0\
\x41\0\0\0\xc0\0\0\0\x22\x03\0\0\x04\0\0\0\xe0\0\0\0\x29\x03\0\0\0\0\0\x08\x38\
\0\0\0\0\0\0\0\x01\0\0\x04\x08\0\0\0\x4f\x01\0\0\x39\0\0\0\0\0\0\0\x32\x03\0\0\
\0\0\0\x08\x3a\0\0\0\x40\x03\0\0\x02\0\0\x04\x08\0\0\0\0\0\0\0\x3b\0\0\0\0\0\0\
\0\x98\x02\0\0\x19\0\0\0\x20\0\0\0\0\0\0\0\x02\0\0\x05\x04\0\0\0\x48\x03\0\0\
\x1c\0\0\0\0\0\0\0\0\0\0\0\x3c\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\x04\x04\0\0\0\x4d\
\x03\0\0\x1f\0\0\0\0\0\0\0\x55\x03\0\0\x3d\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\x03\0\
\0\0\0\x1f\0\0\0\x3e\0\0\0\x03\0\0\0\x5e\x03\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\
\0\0\0\0\0\0\0\x02\x68\0\0\0\x10\x03\0\0\x05\0\0\x06\x04\0\0\0\x72\x03\0\0\0\0\
\0\0\x7e\x03\0\0\x01\0\0\0\x8b\x03\0\0\x02\0\0\0\x98\x03\0\0\x03\0\0\0\xa4\x03\
\0\0\x04\0\0\0\xb0\x03\0\0\0\0\0\x08\x42\0\0\0\0\0\0\0\x01\0\0\x04\x04\0\0\0\
\x72\x01\0\0\x43\0\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\x08\x44\0\0\0\xbd\x03\0\0\0\0\
\0\x08\x2d\0\0\0\0\0\0\0\0\0\0\x02\x46\0\0\0\0\0\0\0\0\0\0\x0a\x63\0\0\0\xce\
\x03\0\0\x06\0\0\x04\x20\0\0\0\xdc\x03\0\0\x48\0\0\0\0\0\0\0\xe2\x03\0\0\x2d\0\
\0\0\x40\0\0\0\xe7\x03\0\0\x2d\0\0\0\x60\0\0\0\xf2\x03\0\0\x2d\0\0\0\x80\0\0\0\
\xfb\x03\0\0\x2d\0\0\0\xa0\0\0\0\x05\x04\0\0\x34\0\0\0\xc0\0\0\0\x0e\x04\0\0\0\
\0\0\x01\x08\0\0\0\x40\0\0\0\x1c\x04\0\0\0\0\0\x08\x4a\0\0\0\x20\x04\0\0\0\0\0\
\x08\x02\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\x02\x66\0\0\0\0\0\0\0\0\
\0\0\x02\x62\0\0\0\x26\x04\0\0\0\0\0\x08\x4f\0\0\0\x2f\x04\0\0\0\0\0\x08\x50\0\
\0\0\x33\x04\0\0\0\0\0\x08\x2d\0\0\0\x39\x04\0\0\0\0\0\x08\x52\0\0\0\x3f\x04\0\
\0\0\0\0\x08\x04\0\0\0\x4e\x04\0\0\0\0\0\x0e\x51\0\0\0\x01\0\0\0\x55\x04\0\0\0\
\0\0\x0e\x50\0\0\0\x01\0\0\0\x5e\x04\0\0\0\0\0\x0e\x50\0\0\0\x01\0\0\0\x68\x04\
\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x56\0\0\0\x3e\0\
\0\0\x80\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x57\0\0\0\x3e\0\0\0\x07\0\0\0\x6d\x04\
\0\0\0\0\0\x0e\x58\0\0\0\x01\0\0\0\x78\x04\0\0\0\0\0\x0e\x58\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\x03\0\0\0\0\x04\0\0\0\x3e\0\0\0\x07\0\0\0\x84\x04\0\0\0\0\0\x0e\
\x5b\0\0\0\x01\0\0\0\x8e\x04\0\0\0\0\0\x0e\x5b\0\0\0\x01\0\0\0\x99\x04\0\0\0\0\
\0\x0e\x04\0\0\0\x01\0\0\0\xa5\x04\0\0\0\0\0\x0e\x04\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\x03\0\0\0\0\x56\0\0\0\x3e\0\0\0\x04\0\0\0\xb2\x04\0\0\0\0\0\x0e\x60\0\0\0\
\x01\0\0\0\xbb\x04\0\0\0\0\0\x07\0\0\0\0\xc9\x04\0\0\0\0\0\x07\0\0\0\0\x21\x01\
\0\0\0\0\0\x07\0\0\0\0\xce\x04\0\0\0\0\0\x07\0\0\0\0\xde\x04\0\0\0\0\0\x07\0\0\
\0\0\xe9\x04\0\0\0\0\0\x07\0\0\0\0\x0c\x03\0\0\0\0\0\x07\0\0\0\0\xef\x04\0\0\0\
\0\0\x07\0\0\0\0\x22\x07\0\0\x09\0\0\x0f\x4c\x07\0\0\x53\0\0\0\0\0\0\0\x04\0\0\
\0\x54\0\0\0\x04\0\0\0\x04\0\0\0\x55\0\0\0\x08\0\0\0\x04\0\0\0\x59\0\0\0\x0c\0\
\0\0\x80\x03\0\0\x5a\0\0\0\x8c\x03\0\0\x80\x03\0\0\x5c\0\0\0\x0c\x07\0\0\x1c\0\
\0\0\x5d\0\0\0\x28\x07\0\0\x1c\0\0\0\x5e\0\0\0\x44\x07\0\0\x04\0\0\0\x5f\0\0\0\
\x48\x07\0\0\x04\0\0\0\x27\x07\0\0\x01\0\0\x0f\x04\0\0\0\x61\0\0\0\0\0\0\0\x04\
\0\0\0\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\
\x67\0\x63\x74\x78\0\x69\x6e\x74\0\x70\x72\x6f\x67\x5f\x73\x74\x61\x74\0\x70\
\x72\x6f\x67\x5f\x63\x6c\x6f\x73\x65\0\x66\x69\x6c\x65\0\x66\x5f\x75\0\x66\x5f\
\x70\x61\x74\x68\0\x66\x5f\x69\x6e\x6f\x64\x65\0\x66\x5f\x6f\x70\0\x66\x5f\x6c\
\x6f\x63\x6b\0\x66\x5f\x77\x72\x69\x74\x65\x5f\x68\x69\x6e\x74\0\x66\x5f\x63\
\x6f\x75\x6e\x74\0\x66\x5f\x66\x6c\x61\x67\x73\0\x66\x5f\x6d\x6f\x64\x65\0\x66\
\x5f\x70\x6f\x73\x5f\x6c\x6f\x63\x6b\0\x66\x5f\x70\x6f\x73\0\x66\x5f\x6f\x77\
\x6e\x65\x72\0\x66\x5f\x63\x72\x65\x64\0\x66\x5f\x72\x61\0\x66\x5f\x76\x65\x72\
\x73\x69\x6f\x6e\0\x66\x5f\x73\x65\x63\x75\x72\x69\x74\x79\0\x70\x72\x69\x76\
\x61\x74\x65\x5f\x64\x61\x74\x61\0\x66\x5f\x65\x70\0\x66\x5f\x6d\x61\x70\x70\
\x69\x6e\x67\0\x66\x5f\x77\x62\x5f\x65\x72\x72\0\x66\x5f\x73\x62\x5f\x65\x72\
\x72\0\x66\x75\x5f\x6c\x6c\x69\x73\x74\0\x66\x75\x5f\x72\x63\x75\x68\x65\x61\
\x64\0\x6c\x6c\x69\x73\x74\x5f\x6e\x6f\x64\x65\0\x6e\x65\x78\x74\0\x63\x61\x6c\
\x6c\x62\x61\x63\x6b\x5f\x68\x65\x61\x64\0\x66\x75\x6e\x63\0\x70\x61\x74\x68\0\
\x6d\x6e\x74\0\x64\x65\x6e\x74\x72\x79\0\x73\x70\x69\x6e\x6c\x6f\x63\x6b\x5f\
\x74\0\x73\x70\x69\x6e\x6c\x6f\x63\x6b\0\x72\x6c\x6f\x63\x6b\0\x72\x61\x77\x5f\
\x73\x70\x69\x6e\x6c\x6f\x63\x6b\0\x72\x61\x77\x5f\x6c\x6f\x63\x6b\0\x61\x72\
\x63\x68\x5f\x73\x70\x69\x6e\x6c\x6f\x63\x6b\x5f\x74\0\x71\x73\x70\x69\x6e\x6c\
\x6f\x63\x6b\0\x76\x61\x6c\0\x61\x74\x6f\x6d\x69\x63\x5f\x74\0\x63\x6f\x75\x6e\
\x74\x65\x72\0\x6c\x6f\x63\x6b\x65\x64\0\x70\x65\x6e\x64\x69\x6e\x67\0\x75\x38\
\0\x5f\x5f\x75\x38\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x6c\
\x6f\x63\x6b\x65\x64\x5f\x70\x65\x6e\x64\x69\x6e\x67\0\x74\x61\x69\x6c\0\x75\
\x31\x36\0\x5f\x5f\x75\x31\x36\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x73\x68\
\x6f\x72\x74\0\x72\x77\x5f\x68\x69\x6e\x74\0\x57\x52\x49\x54\x45\x5f\x4c\x49\
\x46\x45\x5f\x4e\x4f\x54\x5f\x53\x45\x54\0\x57\x52\x49\x54\x45\x5f\x4c\x49\x46\
\x45\x5f\x4e\x4f\x4e\x45\0\x57\x52\x49\x54\x45\x5f\x4c\x49\x46\x45\x5f\x53\x48\
\x4f\x52\x54\0\x57\x52\x49\x54\x45\x5f\x4c\x49\x46\x45\x5f\x4d\x45\x44\x49\x55\
\x4d\0\x57\x52\x49\x54\x45\x5f\x4c\x49\x46\x45\x5f\x4c\x4f\x4e\x47\0\x57\x52\
\x49\x54\x45\x5f\x4c\x49\x46\x45\x5f\x45\x58\x54\x52\x45\x4d\x45\0\x61\x74\x6f\
\x6d\x69\x63\x5f\x6c\x6f\x6e\x67\x5f\x74\0\x61\x74\x6f\x6d\x69\x63\x36\x34\x5f\
\x74\0\x73\x36\x34\0\x5f\x5f\x73\x36\x34\0\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\
\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x66\x6d\x6f\x64\x65\x5f\
\x74\0\x6d\x75\x74\x65\x78\0\x6f\x77\x6e\x65\x72\0\x77\x61\x69\x74\x5f\x6c\x6f\
\x63\x6b\0\x6f\x73\x71\0\x77\x61\x69\x74\x5f\x6c\x69\x73\x74\0\x72\x61\x77\x5f\
\x73\x70\x69\x6e\x6c\x6f\x63\x6b\x5f\x74\0\x6f\x70\x74\x69\x6d\x69\x73\x74\x69\
\x63\x5f\x73\x70\x69\x6e\x5f\x71\x75\x65\x75\x65\0\x6c\x69\x73\x74\x5f\x68\x65\
\x61\x64\0\x70\x72\x65\x76\0\x6c\x6f\x66\x66\x5f\x74\0\x5f\x5f\x6b\x65\x72\x6e\
\x65\x6c\x5f\x6c\x6f\x66\x66\x5f\x74\0\x66\x6f\x77\x6e\x5f\x73\x74\x72\x75\x63\
\x74\0\x6c\x6f\x63\x6b\0\x70\x69\x64\0\x70\x69\x64\x5f\x74\x79\x70\x65\0\x75\
\x69\x64\0\x65\x75\x69\x64\0\x73\x69\x67\x6e\x75\x6d\0\x72\x77\x6c\x6f\x63\x6b\
\x5f\x74\0\x61\x72\x63\x68\x5f\x72\x77\x6c\x6f\x63\x6b\x5f\x74\0\x71\x72\x77\
\x6c\x6f\x63\x6b\0\x63\x6e\x74\x73\0\x77\x6c\x6f\x63\x6b\x65\x64\0\x5f\x5f\x6c\
\x73\x74\x61\x74\x65\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\
\x59\x50\x45\x5f\x5f\0\x50\x49\x44\x54\x59\x50\x45\x5f\x50\x49\x44\0\x50\x49\
\x44\x54\x59\x50\x45\x5f\x54\x47\x49\x44\0\x50\x49\x44\x54\x59\x50\x45\x5f\x50\
\x47\x49\x44\0\x50\x49\x44\x54\x59\x50\x45\x5f\x53\x49\x44\0\x50\x49\x44\x54\
\x59\x50\x45\x5f\x4d\x41\x58\0\x6b\x75\x69\x64\x5f\x74\0\x75\x69\x64\x5f\x74\0\
\x5f\x5f\x6b\x65\x72\x6e\x65\x6c\x5f\x75\x69\x64\x33\x32\x5f\x74\0\x66\x69\x6c\
\x65\x5f\x72\x61\x5f\x73\x74\x61\x74\x65\0\x73\x74\x61\x72\x74\0\x73\x69\x7a\
\x65\0\x61\x73\x79\x6e\x63\x5f\x73\x69\x7a\x65\0\x72\x61\x5f\x70\x61\x67\x65\
\x73\0\x6d\x6d\x61\x70\x5f\x6d\x69\x73\x73\0\x70\x72\x65\x76\x5f\x70\x6f\x73\0\
\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\0\x75\x36\x34\0\x5f\x5f\
\x75\x36\x34\0\x65\x72\x72\x73\x65\x71\x5f\x74\0\x75\x33\x32\0\x5f\x5f\x75\x33\
\x32\0\x70\x69\x64\x5f\x74\0\x5f\x5f\x6b\x65\x72\x6e\x65\x6c\x5f\x70\x69\x64\
\x5f\x74\0\x6d\x79\x5f\x70\x69\x64\0\x63\x6e\x74\x5f\x73\x74\x61\x74\0\x63\x6e\
\x74\x5f\x63\x6c\x6f\x73\x65\0\x63\x68\x61\x72\0\x70\x61\x74\x68\x73\x5f\x73\
\x74\x61\x74\0\x70\x61\x74\x68\x73\x5f\x63\x6c\x6f\x73\x65\0\x72\x65\x74\x73\
\x5f\x73\x74\x61\x74\0\x72\x65\x74\x73\x5f\x63\x6c\x6f\x73\x65\0\x63\x61\x6c\
\x6c\x65\x64\x5f\x73\x74\x61\x74\0\x63\x61\x6c\x6c\x65\x64\x5f\x63\x6c\x6f\x73\
\x65\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x61\x64\x64\x72\x65\x73\x73\x5f\x73\
\x70\x61\x63\x65\0\x63\x72\x65\x64\0\x66\x69\x6c\x65\x5f\x6f\x70\x65\x72\x61\
\x74\x69\x6f\x6e\x73\0\x68\x6c\x69\x73\x74\x5f\x68\x65\x61\x64\0\x69\x6e\x6f\
\x64\x65\0\x76\x66\x73\x6d\x6f\x75\x6e\x74\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\
\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\
\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\
\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\
\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\
\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x64\x5f\
\x70\x61\x74\x68\x2e\x63\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\
\x70\x72\x6f\x67\x5f\x73\x74\x61\x74\x2c\x20\x73\x74\x72\x75\x63\x74\x20\x70\
\x61\x74\x68\x20\x2a\x70\x61\x74\x68\x2c\x20\x73\x74\x72\x75\x63\x74\x20\x6b\
\x73\x74\x61\x74\x20\x2a\x73\x74\x61\x74\x2c\0\x09\x70\x69\x64\x5f\x74\x20\x70\
\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\
\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\x28\x29\x20\x3e\x3e\x20\x33\x32\x3b\0\
\x09\x63\x61\x6c\x6c\x65\x64\x5f\x73\x74\x61\x74\x20\x3d\x20\x31\x3b\0\x09\x69\
\x66\x20\x28\x70\x69\x64\x20\x21\x3d\x20\x6d\x79\x5f\x70\x69\x64\x29\0\x09\x72\
\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x64\x5f\x70\x61\x74\x68\x28\x70\x61\x74\
\x68\x2c\x20\x70\x61\x74\x68\x73\x5f\x73\x74\x61\x74\x5b\x63\x6e\x74\x5d\x2c\
\x20\x4d\x41\x58\x5f\x50\x41\x54\x48\x5f\x4c\x45\x4e\x29\x3b\0\x09\x72\x65\x74\
\x73\x5f\x73\x74\x61\x74\x5b\x63\x6e\x74\x5d\x20\x3d\x20\x72\x65\x74\x3b\0\x09\
\x63\x6e\x74\x5f\x73\x74\x61\x74\x2b\x2b\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\
\x50\x52\x4f\x47\x28\x70\x72\x6f\x67\x5f\x63\x6c\x6f\x73\x65\x2c\x20\x73\x74\
\x72\x75\x63\x74\x20\x66\x69\x6c\x65\x20\x2a\x66\x69\x6c\x65\x2c\x20\x76\x6f\
\x69\x64\x20\x2a\x69\x64\x29\0\x09\x63\x61\x6c\x6c\x65\x64\x5f\x63\x6c\x6f\x73\
\x65\x20\x3d\x20\x31\x3b\0\x09\x09\x09\x20\x70\x61\x74\x68\x73\x5f\x63\x6c\x6f\
\x73\x65\x5b\x63\x6e\x74\x5d\x2c\x20\x4d\x41\x58\x5f\x50\x41\x54\x48\x5f\x4c\
\x45\x4e\x29\x3b\0\x09\x72\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x64\x5f\x70\x61\
\x74\x68\x28\x26\x66\x69\x6c\x65\x2d\x3e\x66\x5f\x70\x61\x74\x68\x2c\0\x09\x72\
\x65\x74\x73\x5f\x63\x6c\x6f\x73\x65\x5b\x63\x6e\x74\x5d\x20\x3d\x20\x72\x65\
\x74\x3b\0\x09\x63\x6e\x74\x5f\x63\x6c\x6f\x73\x65\x2b\x2b\x3b\0\x30\x3a\x31\0\
\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x66\x65\x6e\x74\x72\x79\x2f\
\x73\x65\x63\x75\x72\x69\x74\x79\x5f\x69\x6e\x6f\x64\x65\x5f\x67\x65\x74\x61\
\x74\x74\x72\0\x66\x65\x6e\x74\x72\x79\x2f\x66\x69\x6c\x70\x5f\x63\x6c\x6f\x73\
\x65\0\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\0\0\x24\0\0\0\xd4\x01\0\
\0\xf8\x01\0\0\x1c\0\0\0\x08\0\0\0\x2f\x07\0\0\x01\0\0\0\0\0\0\0\x05\0\0\0\x4d\
\x07\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x10\0\0\0\x2f\x07\0\0\x0e\0\0\0\0\0\0\0\
\xf8\x04\0\0\x79\x05\0\0\x05\x58\0\0\x08\0\0\0\xf8\x04\0\0\xb8\x05\0\0\x0e\x64\
\0\0\x10\0\0\0\xf8\x04\0\0\xe7\x05\0\0\x0e\x74\0\0\x30\0\0\0\xf8\x04\0\0\xb8\
\x05\0\0\x29\x64\0\0\x38\0\0\0\xf8\x04\0\0\xf9\x05\0\0\x0d\x7c\0\0\x50\0\0\0\
\xf8\x04\0\0\xf9\x05\0\0\x06\x7c\0\0\x58\0\0\0\xf8\x04\0\0\0\0\0\0\0\0\0\0\x68\
\0\0\0\xf8\x04\0\0\xf9\x05\0\0\x06\x7c\0\0\x78\0\0\0\xf8\x04\0\0\x0d\x06\0\0\
\x19\x90\0\0\xa0\0\0\0\xf8\x04\0\0\x0d\x06\0\0\x08\x90\0\0\xb8\0\0\0\xf8\x04\0\
\0\x45\x06\0\0\x02\x98\0\0\xd8\0\0\0\xf8\x04\0\0\x45\x06\0\0\x11\x98\0\0\xe0\0\
\0\0\xf8\x04\0\0\x5c\x06\0\0\x0a\x9c\0\0\x08\x01\0\0\xf8\x04\0\0\x79\x05\0\0\
\x05\x58\0\0\x4d\x07\0\0\x0e\0\0\0\0\0\0\0\xf8\x04\0\0\x69\x06\0\0\x05\xb0\0\0\
\x08\0\0\0\xf8\x04\0\0\xb8\x05\0\0\x0e\xb8\0\0\x10\0\0\0\xf8\x04\0\0\x9f\x06\0\
\0\x0f\xc8\0\0\x30\0\0\0\xf8\x04\0\0\xb8\x05\0\0\x29\xb8\0\0\x38\0\0\0\xf8\x04\
\0\0\xf9\x05\0\0\x0d\xd0\0\0\x50\0\0\0\xf8\x04\0\0\xf9\x05\0\0\x06\xd0\0\0\x58\
\0\0\0\xf8\x04\0\0\0\0\0\0\0\0\0\0\x68\0\0\0\xf8\x04\0\0\xf9\x05\0\0\x06\xd0\0\
\0\x88\0\0\0\xf8\x04\0\0\xb2\x06\0\0\x05\xe8\0\0\xb0\0\0\0\xf8\x04\0\0\xd7\x06\
\0\0\x08\xe4\0\0\xc8\0\0\0\xf8\x04\0\0\xf8\x06\0\0\x02\xf0\0\0\xe8\0\0\0\xf8\
\x04\0\0\xf8\x06\0\0\x12\xf0\0\0\xf0\0\0\0\xf8\x04\0\0\x10\x07\0\0\x0b\xf4\0\0\
\x18\x01\0\0\xf8\x04\0\0\x69\x06\0\0\x05\xb0\0\0\x10\0\0\0\x4d\x07\0\0\x01\0\0\
\0\x78\0\0\0\x07\0\0\0\x1e\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x40\0\0\0\0\0\0\0\x2d\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x01\0\0\0\0\
\0\0\xb0\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\
\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x03\0\0\0\0\0\0\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x04\0\0\0\0\0\0\x28\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x41\0\0\0\x08\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x05\0\0\0\0\0\0\x4c\x07\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\0\x01\0\0\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x60\x05\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe7\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x68\x05\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x09\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xc8\x05\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\
\0\x10\0\0\0\0\0\0\0\x1f\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\
\x06\0\0\0\0\0\0\x13\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x24\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x17\0\0\0\0\
\0\0\x34\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_D_PATH_SKEL_H__ */