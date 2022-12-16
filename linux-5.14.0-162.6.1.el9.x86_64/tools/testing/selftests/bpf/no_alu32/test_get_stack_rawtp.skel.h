/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_GET_STACK_RAWTP_SKEL_H__
#define __TEST_GET_STACK_RAWTP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_get_stack_rawtp {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *stackdata_map;
		struct bpf_map *perfmap;
		struct bpf_map *rawdata_map;
	} maps;
	struct {
		struct bpf_program *bpf_prog1;
	} progs;
	struct {
		struct bpf_link *bpf_prog1;
	} links;
};

static void
test_get_stack_rawtp__destroy(struct test_get_stack_rawtp *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_get_stack_rawtp__create_skeleton(struct test_get_stack_rawtp *obj);

static inline struct test_get_stack_rawtp *
test_get_stack_rawtp__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_get_stack_rawtp *obj;
	int err;

	obj = (struct test_get_stack_rawtp *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_get_stack_rawtp__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_get_stack_rawtp__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_get_stack_rawtp *
test_get_stack_rawtp__open(void)
{
	return test_get_stack_rawtp__open_opts(NULL);
}

static inline int
test_get_stack_rawtp__load(struct test_get_stack_rawtp *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_get_stack_rawtp *
test_get_stack_rawtp__open_and_load(void)
{
	struct test_get_stack_rawtp *obj;
	int err;

	obj = test_get_stack_rawtp__open();
	if (!obj)
		return NULL;
	err = test_get_stack_rawtp__load(obj);
	if (err) {
		test_get_stack_rawtp__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_get_stack_rawtp__attach(struct test_get_stack_rawtp *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_get_stack_rawtp__detach(struct test_get_stack_rawtp *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_get_stack_rawtp__elf_bytes(size_t *sz);

static inline int
test_get_stack_rawtp__create_skeleton(struct test_get_stack_rawtp *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_get_stack_rawtp";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 3;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "stackdata_map";
	s->maps[0].map = &obj->maps.stackdata_map;

	s->maps[1].name = "perfmap";
	s->maps[1].map = &obj->maps.perfmap;

	s->maps[2].name = "rawdata_map";
	s->maps[2].map = &obj->maps.rawdata_map;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "bpf_prog1";
	s->progs[0].prog = &obj->progs.bpf_prog1;
	s->progs[0].link = &obj->links.bpf_prog1;

	s->data = (void *)test_get_stack_rawtp__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_get_stack_rawtp__elf_bytes(size_t *sz)
{
	*sz = 4760;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x58\x10\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\
\x74\x5f\x67\x65\x74\x5f\x73\x74\x61\x63\x6b\x5f\x72\x61\x77\x74\x70\x2e\x63\0\
\x4c\x42\x42\x30\x5f\x36\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x31\0\x73\x74\x61\
\x63\x6b\x64\x61\x74\x61\x5f\x6d\x61\x70\0\x70\x65\x72\x66\x6d\x61\x70\0\x72\
\x61\x77\x64\x61\x74\x61\x5f\x6d\x61\x70\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\
\x2e\x72\x65\x6c\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\
\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\
\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\0\0\0\
\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x4f\0\0\0\0\0\x03\0\x70\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x56\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x80\x02\0\0\0\0\0\0\x60\0\0\0\x11\0\x04\
\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x6e\0\0\0\x11\0\x04\0\x20\0\0\0\0\0\0\0\
\x20\0\0\0\0\0\0\0\x76\0\0\0\x11\0\x04\0\x40\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\
\x82\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xbf\x16\0\0\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\
\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\
\x07\0\0\0\0\0\0\x15\x07\x44\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x63\x07\0\0\0\0\0\0\
\xbf\x72\0\0\0\0\0\0\x07\x02\0\0\x10\0\0\0\xbf\x61\0\0\0\0\0\0\xb7\x03\0\0\x20\
\x03\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x43\0\0\0\x63\x07\x04\0\0\0\0\0\xbf\x72\
\0\0\0\0\0\0\x07\x02\0\0\x30\x03\0\0\xbf\x61\0\0\0\0\0\0\xb7\x03\0\0\x20\x03\0\
\0\xb7\x04\0\0\0\x01\0\0\x85\0\0\0\x43\0\0\0\x63\x07\x08\0\0\0\0\0\xbf\x72\0\0\
\0\0\0\0\x07\x02\0\0\x50\x06\0\0\xbf\x61\0\0\0\0\0\0\xb7\x03\0\0\x80\x0c\0\0\
\xb7\x04\0\0\0\x09\0\0\x85\0\0\0\x43\0\0\0\x63\x07\x0c\0\0\0\0\0\xbf\x61\0\0\0\
\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\xbf\x74\0\0\0\0\
\0\0\xb7\x05\0\0\xd0\x12\0\0\x85\0\0\0\x19\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\
\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\
\x07\0\0\0\0\0\0\x15\x07\x1f\0\0\0\0\0\xb7\x09\0\0\x20\x03\0\0\xbf\x61\0\0\0\0\
\0\0\xbf\x72\0\0\0\0\0\0\xb7\x03\0\0\x20\x03\0\0\xb7\x04\0\0\0\x01\0\0\x85\0\0\
\0\x43\0\0\0\xbf\x08\0\0\0\0\0\0\xc5\x08\x17\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\x0f\
\x82\0\0\0\0\0\0\x1f\x89\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xbf\x93\0\0\0\0\0\0\
\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x43\0\0\0\xc5\0\x0f\0\0\0\0\0\x0f\x80\0\0\0\0\0\
\0\xbf\x01\0\0\0\0\0\0\x07\x01\0\0\xff\xff\xff\xff\x67\x01\0\0\x20\0\0\0\x77\
\x01\0\0\x20\0\0\0\x25\x01\x09\0\x1f\x03\0\0\x67\0\0\0\x20\0\0\0\xc7\0\0\0\x20\
\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\0\0\
\0\0\xbf\x74\0\0\0\0\0\0\xbf\x05\0\0\0\0\0\0\x85\0\0\0\x19\0\0\0\xb7\0\0\0\0\0\
\0\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\
\0\x28\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x10\x01\0\0\0\0\0\0\x01\0\0\0\x06\0\0\
\0\x50\x01\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x40\x02\0\0\0\0\0\0\x01\0\0\0\x06\0\
\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xcc\x03\0\0\xcc\x03\0\0\x46\x05\0\0\0\0\0\
\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\
\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x06\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\x19\0\0\0\0\0\0\x08\x09\0\0\0\x1f\0\0\0\
\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0b\0\0\0\x2c\0\0\0\x07\0\0\
\x04\xd0\x12\0\0\x3a\0\0\0\x02\0\0\0\0\0\0\0\x3e\0\0\0\x02\0\0\0\x20\0\0\0\x4e\
\0\0\0\x02\0\0\0\x40\0\0\0\x5e\0\0\0\x02\0\0\0\x60\0\0\0\x76\0\0\0\x0e\0\0\0\
\x80\0\0\0\x81\0\0\0\x0e\0\0\0\x80\x19\0\0\x8c\0\0\0\x14\0\0\0\x80\x32\0\0\x9f\
\0\0\0\0\0\0\x08\x0d\0\0\0\xa5\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\x03\0\0\0\0\x0c\0\0\0\x04\0\0\0\x64\0\0\0\xb8\0\0\0\x03\0\0\x04\x20\0\0\0\
\xcb\0\0\0\x10\0\0\0\0\0\0\0\xd2\0\0\0\x12\0\0\0\x20\0\0\0\0\0\0\0\x13\0\0\0\
\xc0\0\0\0\xdb\0\0\0\0\0\0\x08\x02\0\0\0\xe1\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x11\0\0\0\x04\0\0\0\x14\0\0\0\0\0\0\0\x02\0\0\x05\
\x08\0\0\0\xef\0\0\0\x0c\0\0\0\0\0\0\0\xf6\0\0\0\x0c\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x03\0\0\0\0\x0f\0\0\0\x04\0\0\0\x64\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\xf9\
\0\0\0\x01\0\0\0\0\0\0\0\xfe\0\0\0\x05\0\0\0\x40\0\0\0\x0a\x01\0\0\x07\0\0\0\
\x80\0\0\0\x0e\x01\0\0\x0a\0\0\0\xc0\0\0\0\x14\x01\0\0\0\0\0\x0e\x15\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\x02\x18\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\
\0\x04\0\0\0\0\0\0\0\0\0\0\x02\x1a\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\
\x04\0\0\0\x02\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\xf9\0\0\0\x17\0\0\0\0\0\0\0\
\xfe\0\0\0\x19\0\0\0\x40\0\0\0\x22\x01\0\0\x17\0\0\0\x80\0\0\0\x2b\x01\0\0\x17\
\0\0\0\xc0\0\0\0\x36\x01\0\0\0\0\0\x0e\x1b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\
\x1e\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0c\0\0\0\x04\0\0\0\xc8\0\0\0\0\0\0\0\x04\
\0\0\x04\x20\0\0\0\xf9\0\0\0\x01\0\0\0\0\0\0\0\xfe\0\0\0\x05\0\0\0\x40\0\0\0\
\x0a\x01\0\0\x07\0\0\0\x80\0\0\0\x0e\x01\0\0\x1d\0\0\0\xc0\0\0\0\x3e\x01\0\0\0\
\0\0\x0e\x1f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x02\
\0\0\0\x4a\x01\0\0\x21\0\0\0\x4e\x01\0\0\x01\0\0\x0c\x22\0\0\0\x58\x01\0\0\0\0\
\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x24\0\0\0\x04\0\0\0\x04\
\0\0\0\x5d\x01\0\0\0\0\0\x0e\x25\0\0\0\x01\0\0\0\x1f\x05\0\0\x03\0\0\x0f\x60\0\
\0\0\x16\0\0\0\0\0\0\0\x20\0\0\0\x1c\0\0\0\x20\0\0\0\x20\0\0\0\x20\0\0\0\x40\0\
\0\0\x20\0\0\0\x25\x05\0\0\x01\0\0\x0f\x04\0\0\0\x26\0\0\0\0\0\0\0\x04\0\0\0\0\
\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\
\x45\x5f\x5f\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\
\x6e\x74\0\x73\x74\x61\x63\x6b\x5f\x74\x72\x61\x63\x65\x5f\x74\0\x70\x69\x64\0\
\x6b\x65\x72\x6e\x5f\x73\x74\x61\x63\x6b\x5f\x73\x69\x7a\x65\0\x75\x73\x65\x72\
\x5f\x73\x74\x61\x63\x6b\x5f\x73\x69\x7a\x65\0\x75\x73\x65\x72\x5f\x73\x74\x61\
\x63\x6b\x5f\x62\x75\x69\x6c\x64\x69\x64\x5f\x73\x69\x7a\x65\0\x6b\x65\x72\x6e\
\x5f\x73\x74\x61\x63\x6b\0\x75\x73\x65\x72\x5f\x73\x74\x61\x63\x6b\0\x75\x73\
\x65\x72\x5f\x73\x74\x61\x63\x6b\x5f\x62\x75\x69\x6c\x64\x69\x64\0\x5f\x5f\x75\
\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\
\x67\0\x62\x70\x66\x5f\x73\x74\x61\x63\x6b\x5f\x62\x75\x69\x6c\x64\x5f\x69\x64\
\0\x73\x74\x61\x74\x75\x73\0\x62\x75\x69\x6c\x64\x5f\x69\x64\0\x5f\x5f\x73\x33\
\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x6f\x66\x66\x73\
\x65\x74\0\x69\x70\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\
\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x73\x74\x61\x63\x6b\x64\x61\x74\x61\
\x5f\x6d\x61\x70\0\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\
\x73\x69\x7a\x65\0\x70\x65\x72\x66\x6d\x61\x70\0\x72\x61\x77\x64\x61\x74\x61\
\x5f\x6d\x61\x70\0\x63\x74\x78\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x31\0\x63\x68\
\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\
\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\
\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\
\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\
\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\
\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x67\x65\
\x74\x5f\x73\x74\x61\x63\x6b\x5f\x72\x61\x77\x74\x70\x2e\x63\0\x69\x6e\x74\x20\
\x62\x70\x66\x5f\x70\x72\x6f\x67\x31\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\
\x29\0\x09\x5f\x5f\x75\x33\x32\x20\x6b\x65\x79\x20\x3d\x20\x30\x3b\0\x09\x64\
\x61\x74\x61\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\
\x70\x5f\x65\x6c\x65\x6d\x28\x26\x73\x74\x61\x63\x6b\x64\x61\x74\x61\x5f\x6d\
\x61\x70\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x64\x61\x74\
\x61\x29\0\x09\x64\x61\x74\x61\x2d\x3e\x70\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\
\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\
\x64\x28\x29\x3b\0\x09\x64\x61\x74\x61\x2d\x3e\x6b\x65\x72\x6e\x5f\x73\x74\x61\
\x63\x6b\x5f\x73\x69\x7a\x65\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x73\
\x74\x61\x63\x6b\x28\x63\x74\x78\x2c\x20\x64\x61\x74\x61\x2d\x3e\x6b\x65\x72\
\x6e\x5f\x73\x74\x61\x63\x6b\x2c\0\x09\x64\x61\x74\x61\x2d\x3e\x75\x73\x65\x72\
\x5f\x73\x74\x61\x63\x6b\x5f\x73\x69\x7a\x65\x20\x3d\x20\x62\x70\x66\x5f\x67\
\x65\x74\x5f\x73\x74\x61\x63\x6b\x28\x63\x74\x78\x2c\x20\x64\x61\x74\x61\x2d\
\x3e\x75\x73\x65\x72\x5f\x73\x74\x61\x63\x6b\x2c\x20\x6d\x61\x78\x5f\x6c\x65\
\x6e\x2c\0\x09\x09\x63\x74\x78\x2c\x20\x64\x61\x74\x61\x2d\x3e\x75\x73\x65\x72\
\x5f\x73\x74\x61\x63\x6b\x5f\x62\x75\x69\x6c\x64\x69\x64\x2c\x20\x6d\x61\x78\
\x5f\x62\x75\x69\x6c\x64\x69\x64\x5f\x6c\x65\x6e\x2c\0\x09\x64\x61\x74\x61\x2d\
\x3e\x75\x73\x65\x72\x5f\x73\x74\x61\x63\x6b\x5f\x62\x75\x69\x6c\x64\x69\x64\
\x5f\x73\x69\x7a\x65\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x73\x74\x61\
\x63\x6b\x28\0\x09\x62\x70\x66\x5f\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\
\x6f\x75\x74\x70\x75\x74\x28\x63\x74\x78\x2c\x20\x26\x70\x65\x72\x66\x6d\x61\
\x70\x2c\x20\x30\x2c\x20\x64\x61\x74\x61\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\
\x2a\x64\x61\x74\x61\x29\x29\x3b\0\x09\x72\x61\x77\x5f\x64\x61\x74\x61\x20\x3d\
\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\
\x6d\x28\x26\x72\x61\x77\x64\x61\x74\x61\x5f\x6d\x61\x70\x2c\x20\x26\x6b\x65\
\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x72\x61\x77\x5f\x64\x61\x74\x61\x29\0\
\x09\x75\x73\x69\x7a\x65\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x73\x74\
\x61\x63\x6b\x28\x63\x74\x78\x2c\x20\x72\x61\x77\x5f\x64\x61\x74\x61\x2c\x20\
\x6d\x61\x78\x5f\x6c\x65\x6e\x2c\x20\x42\x50\x46\x5f\x46\x5f\x55\x53\x45\x52\
\x5f\x53\x54\x41\x43\x4b\x29\x3b\0\x09\x69\x66\x20\x28\x75\x73\x69\x7a\x65\x20\
\x3c\x20\x30\x29\0\x09\x6b\x73\x69\x7a\x65\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\
\x74\x5f\x73\x74\x61\x63\x6b\x28\x63\x74\x78\x2c\x20\x72\x61\x77\x5f\x64\x61\
\x74\x61\x20\x2b\x20\x75\x73\x69\x7a\x65\x2c\x20\x6d\x61\x78\x5f\x6c\x65\x6e\
\x20\x2d\x20\x75\x73\x69\x7a\x65\x2c\x20\x30\x29\x3b\0\x09\x69\x66\x20\x28\x6b\
\x73\x69\x7a\x65\x20\x3c\x20\x30\x29\0\x09\x74\x6f\x74\x61\x6c\x5f\x73\x69\x7a\
\x65\x20\x3d\x20\x75\x73\x69\x7a\x65\x20\x2b\x20\x6b\x73\x69\x7a\x65\x3b\0\x09\
\x69\x66\x20\x28\x74\x6f\x74\x61\x6c\x5f\x73\x69\x7a\x65\x20\x3e\x20\x30\x20\
\x26\x26\x20\x74\x6f\x74\x61\x6c\x5f\x73\x69\x7a\x65\x20\x3c\x3d\x20\x6d\x61\
\x78\x5f\x6c\x65\x6e\x29\0\x09\x09\x62\x70\x66\x5f\x70\x65\x72\x66\x5f\x65\x76\
\x65\x6e\x74\x5f\x6f\x75\x74\x70\x75\x74\x28\x63\x74\x78\x2c\x20\x26\x70\x65\
\x72\x66\x6d\x61\x70\x2c\x20\x30\x2c\x20\x72\x61\x77\x5f\x64\x61\x74\x61\x2c\
\x20\x74\x6f\x74\x61\x6c\x5f\x73\x69\x7a\x65\x29\x3b\0\x7d\0\x2e\x6d\x61\x70\
\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\
\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\0\0\0\0\0\0\x9f\xeb\
\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xfc\x01\0\0\x10\x02\0\0\0\0\0\0\
\x08\0\0\0\x2d\x05\0\0\x01\0\0\0\0\0\0\0\x23\0\0\0\x10\0\0\0\x2d\x05\0\0\x1f\0\
\0\0\0\0\0\0\x66\x01\0\0\xf0\x01\0\0\0\xe8\0\0\x10\0\0\0\x66\x01\0\0\x09\x02\0\
\0\x08\0\x01\0\x20\0\0\0\x66\x01\0\0\0\0\0\0\0\0\0\0\x28\0\0\0\x66\x01\0\0\x19\
\x02\0\0\x09\x08\x01\0\x48\0\0\0\x66\x01\0\0\x4c\x02\0\0\x06\x0c\x01\0\x50\0\0\
\0\x66\x01\0\0\x58\x02\0\0\x0e\x20\x01\0\x58\0\0\0\x66\x01\0\0\x58\x02\0\0\x0c\
\x20\x01\0\x60\0\0\0\x66\x01\0\0\x81\x02\0\0\x33\x24\x01\0\x70\0\0\0\x66\x01\0\
\0\x81\x02\0\0\x1a\x24\x01\0\x90\0\0\0\x66\x01\0\0\x81\x02\0\0\x18\x24\x01\0\
\x98\0\0\0\x66\x01\0\0\xbf\x02\0\0\x33\x2c\x01\0\xa8\0\0\0\x66\x01\0\0\xbf\x02\
\0\0\x1a\x2c\x01\0\xc8\0\0\0\x66\x01\0\0\xbf\x02\0\0\x18\x2c\x01\0\xd0\0\0\0\
\x66\x01\0\0\x06\x03\0\0\x0e\x38\x01\0\xe0\0\0\0\x66\x01\0\0\x38\x03\0\0\x22\
\x34\x01\0\0\x01\0\0\x66\x01\0\0\x38\x03\0\0\x20\x34\x01\0\x08\x01\0\0\x66\x01\
\0\0\x68\x03\0\0\x02\x40\x01\0\x48\x01\0\0\x66\x01\0\0\0\0\0\0\0\0\0\0\x50\x01\
\0\0\x66\x01\0\0\xa7\x03\0\0\x0d\x4c\x01\0\x70\x01\0\0\x66\x01\0\0\xdc\x03\0\0\
\x06\x50\x01\0\x80\x01\0\0\x66\x01\0\0\xec\x03\0\0\x0a\x5c\x01\0\xb0\x01\0\0\
\x66\x01\0\0\x2e\x04\0\0\x06\x60\x01\0\xb8\x01\0\0\x66\x01\0\0\x3e\x04\0\0\x26\
\x6c\x01\0\xc8\x01\0\0\x66\x01\0\0\x3e\x04\0\0\x2f\x6c\x01\0\xd0\x01\0\0\x66\
\x01\0\0\x3e\x04\0\0\x0a\x6c\x01\0\xf0\x01\0\0\x66\x01\0\0\x81\x04\0\0\x06\x70\
\x01\0\xf8\x01\0\0\x66\x01\0\0\x91\x04\0\0\x15\x7c\x01\0\0\x02\0\0\x66\x01\0\0\
\xae\x04\0\0\x15\x80\x01\0\x28\x02\0\0\x66\x01\0\0\xdc\x04\0\0\x35\x84\x01\0\
\x38\x02\0\0\x66\x01\0\0\xdc\x04\0\0\x03\x84\x01\0\x70\x02\0\0\x66\x01\0\0\x1d\
\x05\0\0\x01\x90\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\
\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xb6\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xd0\x01\0\0\0\0\0\0\x80\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x50\x04\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x30\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x04\
\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x8b\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\x04\0\0\0\0\0\0\
\x40\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa8\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x04\0\0\0\0\0\0\x2a\x09\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xad\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x0e\0\0\0\0\0\0\x30\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_GET_STACK_RAWTP_SKEL_H__ */
