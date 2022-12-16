/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_VARLEN_SKEL_H__
#define __TEST_VARLEN_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_varlen {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
		struct bpf_map *data;
	} maps;
	struct {
		struct bpf_program *handler64_unsigned;
		struct bpf_program *handler64_signed;
		struct bpf_program *handler32_unsigned;
		struct bpf_program *handler32_signed;
		struct bpf_program *handler_exit;
	} progs;
	struct {
		struct bpf_link *handler64_unsigned;
		struct bpf_link *handler64_signed;
		struct bpf_link *handler32_unsigned;
		struct bpf_link *handler32_signed;
		struct bpf_link *handler_exit;
	} links;
	struct test_varlen__bss {
		char buf_in1[256];
		char buf_in2[256];
		int test_pid;
		bool capture;
		__u64 payload1_len1;
		__u64 payload1_len2;
		__u64 total1;
		char payload1[512];
	} *bss;
	struct test_varlen__data {
		int payload2_len1;
		int payload2_len2;
		int total2;
		char payload2[512];
		int payload3_len1;
		int payload3_len2;
		int total3;
		char payload3[512];
		int payload4_len1;
		int payload4_len2;
		int total4;
		char payload4[512];
	} *data;
};

static void
test_varlen__destroy(struct test_varlen *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_varlen__create_skeleton(struct test_varlen *obj);

static inline struct test_varlen *
test_varlen__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_varlen *obj;
	int err;

	obj = (struct test_varlen *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_varlen__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_varlen__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_varlen *
test_varlen__open(void)
{
	return test_varlen__open_opts(NULL);
}

static inline int
test_varlen__load(struct test_varlen *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_varlen *
test_varlen__open_and_load(void)
{
	struct test_varlen *obj;
	int err;

	obj = test_varlen__open();
	if (!obj)
		return NULL;
	err = test_varlen__load(obj);
	if (err) {
		test_varlen__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_varlen__attach(struct test_varlen *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_varlen__detach(struct test_varlen *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_varlen__elf_bytes(size_t *sz);

static inline int
test_varlen__create_skeleton(struct test_varlen *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_varlen";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_var.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	s->maps[1].name = "test_var.data";
	s->maps[1].map = &obj->maps.data;
	s->maps[1].mmaped = (void **)&obj->data;

	/* programs */
	s->prog_cnt = 5;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "handler64_unsigned";
	s->progs[0].prog = &obj->progs.handler64_unsigned;
	s->progs[0].link = &obj->links.handler64_unsigned;

	s->progs[1].name = "handler64_signed";
	s->progs[1].prog = &obj->progs.handler64_signed;
	s->progs[1].link = &obj->links.handler64_signed;

	s->progs[2].name = "handler32_unsigned";
	s->progs[2].prog = &obj->progs.handler32_unsigned;
	s->progs[2].link = &obj->links.handler32_unsigned;

	s->progs[3].name = "handler32_signed";
	s->progs[3].prog = &obj->progs.handler32_signed;
	s->progs[3].link = &obj->links.handler32_signed;

	s->progs[4].name = "handler_exit";
	s->progs[4].prog = &obj->progs.handler_exit;
	s->progs[4].link = &obj->links.handler_exit;

	s->data = (void *)test_varlen__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_varlen__elf_bytes(size_t *sz)
{
	*sz = 10184;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x88\x23\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x11\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x72\x61\x77\x5f\x74\
\x70\x2f\x73\x79\x73\x5f\x65\x78\x69\x74\0\x74\x70\x2f\x72\x61\x77\x5f\x73\x79\
\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x74\x70\x2f\
\x72\x61\x77\x5f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x78\
\x69\x74\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\
\x78\x69\x74\x5f\x67\x65\x74\x70\x69\x64\0\x2e\x62\x73\x73\0\x2e\x64\x61\x74\
\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x76\x61\x72\x6c\x65\
\x6e\x2e\x63\0\x4c\x42\x42\x30\x5f\x37\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\
\x30\x5f\x36\0\x4c\x42\x42\x31\x5f\x37\0\x4c\x42\x42\x31\x5f\x34\0\x4c\x42\x42\
\x31\x5f\x36\0\x4c\x42\x42\x32\x5f\x37\0\x4c\x42\x42\x32\x5f\x34\0\x4c\x42\x42\
\x32\x5f\x36\0\x4c\x42\x42\x33\x5f\x37\0\x4c\x42\x42\x33\x5f\x34\0\x4c\x42\x42\
\x33\x5f\x36\0\x4c\x42\x42\x34\x5f\x32\0\x68\x61\x6e\x64\x6c\x65\x72\x36\x34\
\x5f\x75\x6e\x73\x69\x67\x6e\x65\x64\0\x74\x65\x73\x74\x5f\x70\x69\x64\0\x63\
\x61\x70\x74\x75\x72\x65\0\x70\x61\x79\x6c\x6f\x61\x64\x31\0\x62\x75\x66\x5f\
\x69\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x31\0\x62\x75\
\x66\x5f\x69\x6e\x32\0\x70\x61\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x32\0\
\x74\x6f\x74\x61\x6c\x31\0\x68\x61\x6e\x64\x6c\x65\x72\x36\x34\x5f\x73\x69\x67\
\x6e\x65\x64\0\x70\x61\x79\x6c\x6f\x61\x64\x33\0\x70\x61\x79\x6c\x6f\x61\x64\
\x33\x5f\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x33\x5f\x6c\x65\x6e\x32\
\0\x74\x6f\x74\x61\x6c\x33\0\x68\x61\x6e\x64\x6c\x65\x72\x33\x32\x5f\x75\x6e\
\x73\x69\x67\x6e\x65\x64\0\x70\x61\x79\x6c\x6f\x61\x64\x32\0\x70\x61\x79\x6c\
\x6f\x61\x64\x32\x5f\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x32\x5f\x6c\
\x65\x6e\x32\0\x74\x6f\x74\x61\x6c\x32\0\x68\x61\x6e\x64\x6c\x65\x72\x33\x32\
\x5f\x73\x69\x67\x6e\x65\x64\0\x70\x61\x79\x6c\x6f\x61\x64\x34\0\x70\x61\x79\
\x6c\x6f\x61\x64\x34\x5f\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x34\x5f\
\x6c\x65\x6e\x32\0\x74\x6f\x74\x61\x6c\x34\0\x68\x61\x6e\x64\x6c\x65\x72\x5f\
\x65\x78\x69\x74\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2e\x72\x65\x6c\x72\x61\x77\
\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\x72\x65\x6c\x72\x61\
\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x78\x69\x74\0\x2e\x72\x65\x6c\x74\x70\
\x2f\x72\x61\x77\x5f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\
\x6e\x74\x65\x72\0\x2e\x72\x65\x6c\x74\x70\x2f\x72\x61\x77\x5f\x73\x79\x73\x63\
\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x78\x69\x74\0\x2e\x42\x54\x46\0\x2e\
\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x94\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa2\0\0\0\0\0\x03\0\x48\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xa9\0\0\0\0\0\x03\0\xc8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\0\0\
\0\0\0\x03\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb7\0\0\0\0\0\x04\0\x48\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xbe\0\0\0\0\0\x04\0\xc8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc5\0\0\0\0\0\x04\0\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xcc\0\0\0\0\0\x05\0\x78\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd3\0\0\0\0\0\
\x05\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xda\0\0\0\0\0\x05\0\x48\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe1\0\0\
\0\0\0\x06\0\x78\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\x06\0\xe0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xef\0\0\0\0\0\x06\0\x48\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf6\0\0\0\0\0\x07\0\x48\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xfd\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x58\x01\0\
\0\0\0\0\0\x10\x01\0\0\x11\0\x08\0\0\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x19\x01\
\0\0\x11\0\x08\0\x04\x02\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x21\x01\0\0\x11\0\x08\0\
\x20\x02\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\x2a\x01\0\0\x11\0\x08\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\x32\x01\0\0\x11\0\x08\0\x08\x02\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\x40\x01\0\0\x11\0\x08\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\x48\x01\0\0\x11\
\0\x08\0\x10\x02\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x56\x01\0\0\x11\0\x08\0\x18\x02\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x5d\x01\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\x58\x01\
\0\0\0\0\0\0\x6e\x01\0\0\x11\0\x09\0\x18\x02\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\x77\
\x01\0\0\x11\0\x09\0\x0c\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x85\x01\0\0\x11\0\
\x09\0\x10\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x93\x01\0\0\x11\0\x09\0\x14\x02\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\x9a\x01\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\x88\x01\0\
\0\0\0\0\0\xad\x01\0\0\x11\0\x09\0\x0c\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\xb6\x01\
\0\0\x11\0\x09\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xc4\x01\0\0\x11\0\x09\0\x04\
\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xd2\x01\0\0\x11\0\x09\0\x08\0\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\xd9\x01\0\0\x12\0\x06\0\0\0\0\0\0\0\0\0\x88\x01\0\0\0\0\0\0\xea\
\x01\0\0\x11\0\x09\0\x24\x04\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\xf3\x01\0\0\x11\0\
\x09\0\x18\x04\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x01\x02\0\0\x11\0\x09\0\x1c\x04\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\x0f\x02\0\0\x11\0\x09\0\x20\x04\0\0\0\0\0\0\x04\0\
\0\0\0\0\0\0\x16\x02\0\0\x12\0\x07\0\0\0\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x23\x02\
\0\0\x11\0\x0a\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\
\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\
\x23\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\x11\0\0\0\0\0\0\x15\x01\
\x1f\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\
\x73\0\0\0\x25\0\x06\0\0\x01\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7b\x01\0\
\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x06\0\0\0\0\0\0\xbf\x61\0\0\
\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\
\x73\0\0\0\x25\0\x04\0\0\x01\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7b\x01\0\
\0\0\0\0\0\x0f\x06\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1f\x16\0\0\
\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7b\x61\0\0\0\0\0\0\xb7\0\0\0\0\0\
\0\0\x95\0\0\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\x23\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x71\x11\0\0\0\0\0\0\x15\x01\x1f\0\0\0\0\0\x18\x06\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\
\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x73\0\0\0\xc5\0\x06\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x0f\x06\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\
\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x73\0\0\0\xc5\0\x04\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x01\0\0\0\0\0\0\x0f\x06\0\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1f\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x63\x61\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x85\0\0\
\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\
\0\0\0\0\0\x5d\x01\x29\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\x11\0\
\0\0\0\0\0\x15\x01\x25\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x85\0\0\0\x73\0\0\0\xbf\x01\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\
\0\x20\0\0\0\x25\x01\x06\0\0\x01\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\
\x02\0\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x16\0\0\0\0\0\0\xbf\
\x61\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\
\0\0\0\x73\0\0\0\xbf\x01\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\0\x20\0\0\
\0\x25\x01\x04\0\0\x01\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x02\0\0\0\0\
\0\0\x0f\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1f\x16\0\0\0\0\0\
\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x61\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\x29\0\0\0\0\0\x18\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x71\x11\0\0\0\0\0\0\x15\x01\x25\0\0\0\0\0\x18\x06\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x73\0\0\0\xbf\x01\0\0\0\0\0\0\x67\
\x01\0\0\x20\0\0\0\xc7\x01\0\0\x20\0\0\0\xc5\x01\x06\0\0\0\0\0\x18\x02\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x63\x02\0\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x0f\x16\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\0\x01\0\0\x18\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x73\0\0\0\xbf\x01\0\0\0\0\0\0\x67\x01\0\0\x20\0\
\0\0\xc7\x01\0\0\x20\0\0\0\xc5\x01\x04\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x63\x02\0\0\0\0\0\0\x0f\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x1f\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x61\0\0\0\0\0\
\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\xff\
\xff\xff\xb7\x02\0\0\x08\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x71\0\0\0\xbf\x01\
\0\0\0\0\0\0\xb7\0\0\0\x01\0\0\0\x55\x01\x01\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\
\0\0\0\0\0\0\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\0\0\0\0\0\0\0\
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
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\
\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
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
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\xff\xff\xff\xff\
\xff\xff\xff\xff\xff\xff\xff\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
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
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\x10\0\0\0\0\0\0\0\x01\0\
\0\0\x15\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x16\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\
\0\x17\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x17\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\
\x18\0\0\0\x98\0\0\0\0\0\0\0\x01\0\0\0\x19\0\0\0\xb0\0\0\0\0\0\0\0\x01\0\0\0\
\x17\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\x1a\0\0\0\xf8\0\0\0\0\0\0\0\x01\0\0\0\
\x1b\0\0\0\x18\x01\0\0\0\0\0\0\x01\0\0\0\x17\0\0\0\x30\x01\0\0\0\0\0\0\x01\0\0\
\0\x1c\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x15\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\
\x16\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\x1e\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\
\x1e\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x18\0\0\0\x98\0\0\0\0\0\0\0\x01\0\0\0\
\x1f\0\0\0\xb0\0\0\0\0\0\0\0\x01\0\0\0\x1e\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\
\x1a\0\0\0\xf8\0\0\0\0\0\0\0\x01\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\x01\0\0\0\
\x1e\0\0\0\x30\x01\0\0\0\0\0\0\x01\0\0\0\x21\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\
\x15\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x16\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\
\x23\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x23\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\
\x18\0\0\0\xb0\0\0\0\0\0\0\0\x01\0\0\0\x24\0\0\0\xc8\0\0\0\0\0\0\0\x01\0\0\0\
\x23\0\0\0\xf0\0\0\0\0\0\0\0\x01\0\0\0\x1a\0\0\0\x28\x01\0\0\0\0\0\0\x01\0\0\0\
\x25\0\0\0\x48\x01\0\0\0\0\0\0\x01\0\0\0\x23\0\0\0\x60\x01\0\0\0\0\0\0\x01\0\0\
\0\x26\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x15\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\
\x16\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\x28\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\
\x28\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x18\0\0\0\xb0\0\0\0\0\0\0\0\x01\0\0\0\
\x29\0\0\0\xc8\0\0\0\0\0\0\0\x01\0\0\0\x28\0\0\0\xf0\0\0\0\0\0\0\0\x01\0\0\0\
\x1a\0\0\0\x28\x01\0\0\0\0\0\0\x01\0\0\0\x2a\0\0\0\x48\x01\0\0\0\0\0\0\x01\0\0\
\0\x28\0\0\0\x60\x01\0\0\0\0\0\0\x01\0\0\0\x2b\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\
\0\0\0\x7c\x03\0\0\x7c\x03\0\0\x25\x05\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\
\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\x01\x0a\0\0\0\x01\0\0\x0c\x02\0\0\0\x1d\0\0\0\x01\0\0\x0c\x02\0\0\0\x2e\0\0\
\0\x01\0\0\x0c\x02\0\0\0\x41\0\0\0\x01\0\0\x0c\x02\0\0\0\x52\0\0\0\x01\0\0\x0c\
\x02\0\0\0\x5f\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\
\x09\0\0\0\x0b\0\0\0\0\x01\0\0\x64\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x78\0\0\
\0\0\0\0\x0e\x0a\0\0\0\x01\0\0\0\x80\0\0\0\0\0\0\x0e\x0a\0\0\0\x01\0\0\0\x88\0\
\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x91\0\0\0\0\0\0\x08\x10\0\0\0\x96\0\0\0\0\0\
\0\x01\x01\0\0\0\x08\0\0\x04\x9c\0\0\0\0\0\0\x0e\x0f\0\0\0\x01\0\0\0\xa4\0\0\0\
\0\0\0\x08\x13\0\0\0\xaa\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\xbd\0\0\0\0\0\0\
\x0e\x12\0\0\0\x01\0\0\0\xcb\0\0\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\xd9\0\0\0\0\0\
\0\x0e\x12\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x09\0\0\0\x0b\0\0\0\0\x02\
\0\0\xe0\0\0\0\0\0\0\x0e\x17\0\0\0\x01\0\0\0\xe9\0\0\0\0\0\0\x0e\x03\0\0\0\x01\
\0\0\0\xf7\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x05\x01\0\0\0\0\0\x0e\x03\0\0\0\
\x01\0\0\0\x0c\x01\0\0\0\0\0\x0e\x17\0\0\0\x01\0\0\0\x15\x01\0\0\0\0\0\x0e\x03\
\0\0\0\x01\0\0\0\x23\x01\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x31\x01\0\0\0\0\0\
\x0e\x03\0\0\0\x01\0\0\0\x38\x01\0\0\0\0\0\x0e\x17\0\0\0\x01\0\0\0\x41\x01\0\0\
\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x4f\x01\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x5d\
\x01\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\x64\x01\0\0\0\0\0\x0e\x17\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x09\0\0\0\x0b\0\0\0\x04\0\0\0\x6d\x01\0\0\0\0\0\
\x0e\x25\0\0\0\x01\0\0\0\xa2\x04\0\0\x08\0\0\x0f\x20\x04\0\0\x0c\0\0\0\0\0\0\0\
\0\x01\0\0\x0d\0\0\0\0\x01\0\0\0\x01\0\0\x0e\0\0\0\0\x02\0\0\x04\0\0\0\x11\0\0\
\0\x04\x02\0\0\x01\0\0\0\x14\0\0\0\x08\x02\0\0\x08\0\0\0\x15\0\0\0\x10\x02\0\0\
\x08\0\0\0\x16\0\0\0\x18\x02\0\0\x08\0\0\0\x18\0\0\0\x20\x02\0\0\0\x02\0\0\xa7\
\x04\0\0\x0c\0\0\x0f\x24\x06\0\0\x19\0\0\0\0\0\0\0\x04\0\0\0\x1a\0\0\0\x04\0\0\
\0\x04\0\0\0\x1b\0\0\0\x08\0\0\0\x04\0\0\0\x1c\0\0\0\x0c\0\0\0\0\x02\0\0\x1d\0\
\0\0\x0c\x02\0\0\x04\0\0\0\x1e\0\0\0\x10\x02\0\0\x04\0\0\0\x1f\0\0\0\x14\x02\0\
\0\x04\0\0\0\x20\0\0\0\x18\x02\0\0\0\x02\0\0\x21\0\0\0\x18\x04\0\0\x04\0\0\0\
\x22\0\0\0\x1c\x04\0\0\x04\0\0\0\x23\0\0\0\x20\x04\0\0\x04\0\0\0\x24\0\0\0\x24\
\x04\0\0\0\x02\0\0\xad\x04\0\0\x01\0\0\x0f\x04\0\0\0\x26\0\0\0\0\0\0\0\x04\0\0\
\0\0\x72\x65\x67\x73\0\x69\x6e\x74\0\x68\x61\x6e\x64\x6c\x65\x72\x36\x34\x5f\
\x75\x6e\x73\x69\x67\x6e\x65\x64\0\x68\x61\x6e\x64\x6c\x65\x72\x36\x34\x5f\x73\
\x69\x67\x6e\x65\x64\0\x68\x61\x6e\x64\x6c\x65\x72\x33\x32\x5f\x75\x6e\x73\x69\
\x67\x6e\x65\x64\0\x68\x61\x6e\x64\x6c\x65\x72\x33\x32\x5f\x73\x69\x67\x6e\x65\
\x64\0\x68\x61\x6e\x64\x6c\x65\x72\x5f\x65\x78\x69\x74\0\x63\x68\x61\x72\0\x5f\
\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x62\
\x75\x66\x5f\x69\x6e\x31\0\x62\x75\x66\x5f\x69\x6e\x32\0\x74\x65\x73\x74\x5f\
\x70\x69\x64\0\x62\x6f\x6f\x6c\0\x5f\x42\x6f\x6f\x6c\0\x63\x61\x70\x74\x75\x72\
\x65\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\
\x67\x20\x6c\x6f\x6e\x67\0\x70\x61\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x31\
\0\x70\x61\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x32\0\x74\x6f\x74\x61\x6c\
\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x32\x5f\
\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x32\x5f\x6c\x65\x6e\x32\0\x74\
\x6f\x74\x61\x6c\x32\0\x70\x61\x79\x6c\x6f\x61\x64\x32\0\x70\x61\x79\x6c\x6f\
\x61\x64\x33\x5f\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x33\x5f\x6c\x65\
\x6e\x32\0\x74\x6f\x74\x61\x6c\x33\0\x70\x61\x79\x6c\x6f\x61\x64\x33\0\x70\x61\
\x79\x6c\x6f\x61\x64\x34\x5f\x6c\x65\x6e\x31\0\x70\x61\x79\x6c\x6f\x61\x64\x34\
\x5f\x6c\x65\x6e\x32\0\x74\x6f\x74\x61\x6c\x34\0\x70\x61\x79\x6c\x6f\x61\x64\
\x34\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\
\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\
\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\
\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\
\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\
\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x76\x61\x72\x6c\
\x65\x6e\x2e\x63\0\x09\x69\x6e\x74\x20\x70\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\
\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\
\x64\x28\x29\x20\x3e\x3e\x20\x33\x32\x3b\0\x09\x69\x66\x20\x28\x74\x65\x73\x74\
\x5f\x70\x69\x64\x20\x21\x3d\x20\x70\x69\x64\x20\x7c\x7c\x20\x21\x63\x61\x70\
\x74\x75\x72\x65\x29\0\x09\x6c\x65\x6e\x20\x3d\x20\x62\x70\x66\x5f\x70\x72\x6f\
\x62\x65\x5f\x72\x65\x61\x64\x5f\x6b\x65\x72\x6e\x65\x6c\x5f\x73\x74\x72\x28\
\x70\x61\x79\x6c\x6f\x61\x64\x2c\x20\x4d\x41\x58\x5f\x4c\x45\x4e\x2c\x20\x26\
\x62\x75\x66\x5f\x69\x6e\x31\x5b\x30\x5d\x29\x3b\0\x09\x69\x66\x20\x28\x6c\x65\
\x6e\x20\x3c\x3d\x20\x4d\x41\x58\x5f\x4c\x45\x4e\x29\x20\x7b\0\x09\x09\x70\x61\
\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x31\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\
\x09\x70\x61\x79\x6c\x6f\x61\x64\x20\x2b\x3d\x20\x6c\x65\x6e\x3b\0\x09\x6c\x65\
\x6e\x20\x3d\x20\x62\x70\x66\x5f\x70\x72\x6f\x62\x65\x5f\x72\x65\x61\x64\x5f\
\x6b\x65\x72\x6e\x65\x6c\x5f\x73\x74\x72\x28\x70\x61\x79\x6c\x6f\x61\x64\x2c\
\x20\x4d\x41\x58\x5f\x4c\x45\x4e\x2c\x20\x26\x62\x75\x66\x5f\x69\x6e\x32\x5b\
\x30\x5d\x29\x3b\0\x09\x09\x70\x61\x79\x6c\x6f\x61\x64\x31\x5f\x6c\x65\x6e\x32\
\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\x74\x6f\x74\x61\x6c\x31\x20\x3d\x20\x70\x61\
\x79\x6c\x6f\x61\x64\x20\x2d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x70\x61\x79\
\x6c\x6f\x61\x64\x31\x3b\0\x7d\0\x09\x69\x66\x20\x28\x6c\x65\x6e\x20\x3e\x3d\
\x20\x30\x29\x20\x7b\0\x09\x09\x70\x61\x79\x6c\x6f\x61\x64\x33\x5f\x6c\x65\x6e\
\x31\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\x09\x70\x61\x79\x6c\x6f\x61\x64\x33\x5f\
\x6c\x65\x6e\x32\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\x74\x6f\x74\x61\x6c\x33\x20\
\x3d\x20\x70\x61\x79\x6c\x6f\x61\x64\x20\x2d\x20\x28\x76\x6f\x69\x64\x20\x2a\
\x29\x70\x61\x79\x6c\x6f\x61\x64\x33\x3b\0\x09\x09\x70\x61\x79\x6c\x6f\x61\x64\
\x32\x5f\x6c\x65\x6e\x31\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\x09\x70\x61\x79\x6c\
\x6f\x61\x64\x32\x5f\x6c\x65\x6e\x32\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\x74\x6f\
\x74\x61\x6c\x32\x20\x3d\x20\x70\x61\x79\x6c\x6f\x61\x64\x20\x2d\x20\x28\x76\
\x6f\x69\x64\x20\x2a\x29\x70\x61\x79\x6c\x6f\x61\x64\x32\x3b\0\x09\x09\x70\x61\
\x79\x6c\x6f\x61\x64\x34\x5f\x6c\x65\x6e\x31\x20\x3d\x20\x6c\x65\x6e\x3b\0\x09\
\x09\x70\x61\x79\x6c\x6f\x61\x64\x34\x5f\x6c\x65\x6e\x32\x20\x3d\x20\x6c\x65\
\x6e\x3b\0\x09\x74\x6f\x74\x61\x6c\x34\x20\x3d\x20\x70\x61\x79\x6c\x6f\x61\x64\
\x20\x2d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x70\x61\x79\x6c\x6f\x61\x64\x34\
\x3b\0\x69\x6e\x74\x20\x68\x61\x6e\x64\x6c\x65\x72\x5f\x65\x78\x69\x74\x28\x76\
\x6f\x69\x64\x20\x2a\x72\x65\x67\x73\x29\0\x09\x69\x66\x20\x28\x62\x70\x66\x5f\
\x70\x72\x6f\x62\x65\x5f\x72\x65\x61\x64\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x26\
\x62\x6c\x61\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x62\x6c\x61\x29\x2c\x20\x30\
\x29\x29\0\x2e\x62\x73\x73\0\x2e\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\
\0\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x72\x61\
\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x78\x69\x74\0\x74\x70\x2f\x72\x61\x77\
\x5f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\
\x74\x70\x2f\x72\x61\x77\x5f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\
\x5f\x65\x78\x69\x74\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\
\x73\x5f\x65\x78\x69\x74\x5f\x67\x65\x74\x70\x69\x64\0\0\0\0\0\0\0\0\x9f\xeb\
\x01\0\x20\0\0\0\0\0\0\0\x54\0\0\0\x54\0\0\0\x2c\x04\0\0\x80\x04\0\0\0\0\0\0\
\x08\0\0\0\xb5\x04\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\xc6\x04\0\0\x01\0\0\0\0\0\0\
\0\x05\0\0\0\xd6\x04\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\xf0\x04\0\0\x01\0\0\0\0\0\
\0\0\x07\0\0\0\x09\x05\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\x10\0\0\0\xb5\x04\0\0\
\x0f\0\0\0\0\0\0\0\x75\x01\0\0\xf6\x01\0\0\x0c\xa8\0\0\x08\0\0\0\x75\x01\0\0\
\xf6\x01\0\0\x27\xa8\0\0\x10\0\0\0\x75\x01\0\0\x23\x02\0\0\x06\xbc\0\0\x28\0\0\
\0\x75\x01\0\0\x23\x02\0\0\x16\xbc\0\0\x50\0\0\0\x75\x01\0\0\x45\x02\0\0\x08\
\xc8\0\0\x90\0\0\0\x75\x01\0\0\x86\x02\0\0\x06\xcc\0\0\x98\0\0\0\x75\x01\0\0\
\x9d\x02\0\0\x11\xd4\0\0\xb0\0\0\0\x75\x01\0\0\xb4\x02\0\0\x0b\xd0\0\0\xc8\0\0\
\0\x75\x01\0\0\xc6\x02\0\0\x08\xe0\0\0\xf0\0\0\0\x75\x01\0\0\x86\x02\0\0\x06\
\xe4\0\0\xf8\0\0\0\x75\x01\0\0\x07\x03\0\0\x11\xec\0\0\x10\x01\0\0\x75\x01\0\0\
\xb4\x02\0\0\x0b\xe8\0\0\x18\x01\0\0\x75\x01\0\0\x1e\x03\0\0\x13\xf8\0\0\x30\
\x01\0\0\x75\x01\0\0\x1e\x03\0\0\x09\xf8\0\0\x48\x01\0\0\x75\x01\0\0\x44\x03\0\
\0\x01\x04\x01\0\xc6\x04\0\0\x0f\0\0\0\0\0\0\0\x75\x01\0\0\xf6\x01\0\0\x0c\x18\
\x01\0\x08\0\0\0\x75\x01\0\0\xf6\x01\0\0\x27\x18\x01\0\x10\0\0\0\x75\x01\0\0\
\x23\x02\0\0\x06\x2c\x01\0\x28\0\0\0\x75\x01\0\0\x23\x02\0\0\x16\x2c\x01\0\x50\
\0\0\0\x75\x01\0\0\x45\x02\0\0\x08\x38\x01\0\x90\0\0\0\x75\x01\0\0\x46\x03\0\0\
\x06\x3c\x01\0\x98\0\0\0\x75\x01\0\0\x57\x03\0\0\x11\x44\x01\0\xb0\0\0\0\x75\
\x01\0\0\xb4\x02\0\0\x0b\x40\x01\0\xc8\0\0\0\x75\x01\0\0\xc6\x02\0\0\x08\x4c\
\x01\0\xf0\0\0\0\x75\x01\0\0\x46\x03\0\0\x06\x50\x01\0\xf8\0\0\0\x75\x01\0\0\
\x6e\x03\0\0\x11\x58\x01\0\x10\x01\0\0\x75\x01\0\0\xb4\x02\0\0\x0b\x54\x01\0\
\x18\x01\0\0\x75\x01\0\0\x85\x03\0\0\x0b\x60\x01\0\x30\x01\0\0\x75\x01\0\0\x85\
\x03\0\0\x09\x60\x01\0\x48\x01\0\0\x75\x01\0\0\x44\x03\0\0\x01\x6c\x01\0\xd6\
\x04\0\0\x0f\0\0\0\0\0\0\0\x75\x01\0\0\xf6\x01\0\0\x0c\x80\x01\0\x08\0\0\0\x75\
\x01\0\0\xf6\x01\0\0\x27\x80\x01\0\x10\0\0\0\x75\x01\0\0\x23\x02\0\0\x06\x94\
\x01\0\x28\0\0\0\x75\x01\0\0\x23\x02\0\0\x16\x94\x01\0\x50\0\0\0\x75\x01\0\0\
\x45\x02\0\0\x08\xa0\x01\0\xa8\0\0\0\x75\x01\0\0\x86\x02\0\0\x06\xa4\x01\0\xb0\
\0\0\0\x75\x01\0\0\xab\x03\0\0\x11\xac\x01\0\xc8\0\0\0\x75\x01\0\0\xb4\x02\0\0\
\x0b\xa8\x01\0\xe0\0\0\0\x75\x01\0\0\xc6\x02\0\0\x08\xb8\x01\0\x20\x01\0\0\x75\
\x01\0\0\x86\x02\0\0\x06\xbc\x01\0\x28\x01\0\0\x75\x01\0\0\xc2\x03\0\0\x11\xc4\
\x01\0\x40\x01\0\0\x75\x01\0\0\xb4\x02\0\0\x0b\xc0\x01\0\x48\x01\0\0\x75\x01\0\
\0\xd9\x03\0\0\x0b\xd0\x01\0\x60\x01\0\0\x75\x01\0\0\xd9\x03\0\0\x09\xd0\x01\0\
\x78\x01\0\0\x75\x01\0\0\x44\x03\0\0\x01\xdc\x01\0\xf0\x04\0\0\x0f\0\0\0\0\0\0\
\0\x75\x01\0\0\xf6\x01\0\0\x0c\xf0\x01\0\x08\0\0\0\x75\x01\0\0\xf6\x01\0\0\x27\
\xf0\x01\0\x10\0\0\0\x75\x01\0\0\x23\x02\0\0\x06\x04\x02\0\x28\0\0\0\x75\x01\0\
\0\x23\x02\0\0\x16\x04\x02\0\x50\0\0\0\x75\x01\0\0\x45\x02\0\0\x08\x10\x02\0\
\xa8\0\0\0\x75\x01\0\0\x46\x03\0\0\x06\x14\x02\0\xb0\0\0\0\x75\x01\0\0\xff\x03\
\0\0\x11\x1c\x02\0\xc8\0\0\0\x75\x01\0\0\xb4\x02\0\0\x0b\x18\x02\0\xe0\0\0\0\
\x75\x01\0\0\xc6\x02\0\0\x08\x24\x02\0\x20\x01\0\0\x75\x01\0\0\x46\x03\0\0\x06\
\x28\x02\0\x28\x01\0\0\x75\x01\0\0\x16\x04\0\0\x11\x30\x02\0\x40\x01\0\0\x75\
\x01\0\0\xb4\x02\0\0\x0b\x2c\x02\0\x48\x01\0\0\x75\x01\0\0\x2d\x04\0\0\x0b\x38\
\x02\0\x60\x01\0\0\x75\x01\0\0\x2d\x04\0\0\x09\x38\x02\0\x78\x01\0\0\x75\x01\0\
\0\x44\x03\0\0\x01\x44\x02\0\x09\x05\0\0\x04\0\0\0\0\0\0\0\x75\x01\0\0\x53\x04\
\0\0\0\x50\x02\0\x08\0\0\0\x75\x01\0\0\0\0\0\0\0\0\0\0\x10\0\0\0\x75\x01\0\0\
\x70\x04\0\0\x06\x60\x02\0\x48\0\0\0\x75\x01\0\0\x44\x03\0\0\x01\x70\x02\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x9d\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xe0\x02\0\0\0\0\0\0\x50\x04\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x30\x07\0\0\0\0\0\0\x58\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x22\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x08\0\0\
\0\0\0\0\x58\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x32\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x09\0\0\0\0\0\0\x88\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4c\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x0b\0\0\0\0\0\0\x88\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x65\0\0\0\x01\0\0\0\
\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x0c\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x81\0\0\0\x08\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x40\x0d\0\0\0\0\0\0\x20\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x86\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x40\x0d\0\0\0\0\0\0\x24\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x8c\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x64\x13\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x2b\x02\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x13\0\0\
\0\0\0\0\xb0\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\
\0\0\x40\x02\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x14\0\0\0\0\0\
\0\xb0\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\x54\x02\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc8\x14\0\0\0\0\0\0\
\xb0\0\0\0\0\0\0\0\x02\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x72\
\x02\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\x15\0\0\0\0\0\0\xb0\0\
\0\0\0\0\0\0\x02\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x8f\x02\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x16\0\0\0\0\0\0\xb9\x08\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x94\x02\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x1e\0\0\0\0\0\0\xa0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_VARLEN_SKEL_H__ */
