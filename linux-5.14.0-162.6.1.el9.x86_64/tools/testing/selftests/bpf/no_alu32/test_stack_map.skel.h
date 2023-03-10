/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_STACK_MAP_SKEL_H__
#define __TEST_STACK_MAP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_stack_map {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *map_in;
		struct bpf_map *map_out;
	} maps;
	struct {
		struct bpf_program *_test;
	} progs;
	struct {
		struct bpf_link *_test;
	} links;
};

static void
test_stack_map__destroy(struct test_stack_map *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_stack_map__create_skeleton(struct test_stack_map *obj);

static inline struct test_stack_map *
test_stack_map__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_stack_map *obj;
	int err;

	obj = (struct test_stack_map *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_stack_map__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_stack_map__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_stack_map *
test_stack_map__open(void)
{
	return test_stack_map__open_opts(NULL);
}

static inline int
test_stack_map__load(struct test_stack_map *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_stack_map *
test_stack_map__open_and_load(void)
{
	struct test_stack_map *obj;
	int err;

	obj = test_stack_map__open();
	if (!obj)
		return NULL;
	err = test_stack_map__load(obj);
	if (err) {
		test_stack_map__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_stack_map__attach(struct test_stack_map *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_stack_map__detach(struct test_stack_map *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_stack_map__elf_bytes(size_t *sz);

static inline int
test_stack_map__create_skeleton(struct test_stack_map *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_stack_map";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "map_in";
	s->maps[0].map = &obj->maps.map_in;

	s->maps[1].name = "map_out";
	s->maps[1].map = &obj->maps.map_out;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "_test";
	s->progs[0].prog = &obj->progs._test;
	s->progs[0].link = &obj->links._test;

	s->data = (void *)test_stack_map__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_stack_map__elf_bytes(size_t *sz)
{
	*sz = 3632;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xf0\x0b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x74\x65\
\x73\x74\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\
\x5f\x73\x74\x61\x63\x6b\x5f\x6d\x61\x70\x2e\x63\0\x4c\x42\x42\x30\x5f\x36\0\
\x4c\x42\x42\x30\x5f\x35\0\x5f\x74\x65\x73\x74\0\x6d\x61\x70\x5f\x69\x6e\0\x6d\
\x61\x70\x5f\x6f\x75\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\
\x74\x65\x73\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x24\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x35\0\0\
\0\0\0\x03\0\xf8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3c\0\0\0\0\0\x03\0\xf0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x43\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\
\0\x49\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x50\0\0\0\x11\0\x04\
\0\x28\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x58\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\xb7\x06\0\0\x02\0\0\0\x61\x17\x4c\0\0\0\0\0\x61\x11\x50\0\0\
\0\0\0\xbf\x72\0\0\0\0\0\0\x07\x02\0\0\x0e\0\0\0\x2d\x12\x19\0\0\0\0\0\xbf\x72\
\0\0\0\0\0\0\x07\x02\0\0\x22\0\0\0\x2d\x12\x16\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\
\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x58\
\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\x55\0\x0e\0\0\0\0\0\x61\xa1\xfc\
\xff\0\0\0\0\x63\x17\x1e\0\0\0\0\0\x07\x07\0\0\x1a\0\0\0\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x57\0\0\0\x67\
\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\xb7\x06\0\0\x01\0\0\0\x55\0\x01\0\0\0\0\0\
\xb7\x06\0\0\0\0\0\0\x67\x06\0\0\x01\0\0\0\xbf\x60\0\0\0\0\0\0\x95\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x47\x50\x4c\0\0\0\0\0\x58\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\xa0\0\0\0\0\
\0\0\0\x01\0\0\0\x07\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x18\x04\0\0\x18\x04\
\0\0\x8f\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\
\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x17\0\0\0\x05\0\0\0\0\0\
\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x02\0\0\0\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\0\0\0\0\0\0\0\x03\
\0\0\0\0\x02\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x0a\0\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\x05\0\0\x04\x28\0\0\0\x19\0\
\0\0\x01\0\0\0\0\0\0\0\x1e\0\0\0\x05\0\0\0\x40\0\0\0\x2a\0\0\0\x07\0\0\0\x80\0\
\0\0\x34\0\0\0\x07\0\0\0\xc0\0\0\0\x3d\0\0\0\x09\0\0\0\0\x01\0\0\x48\0\0\0\0\0\
\0\x0e\x0b\0\0\0\x01\0\0\0\x4f\0\0\0\0\0\0\x0e\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\x02\x0f\0\0\0\x57\0\0\0\x21\0\0\x04\xc0\0\0\0\x61\0\0\0\x10\0\0\0\0\0\0\0\
\x65\0\0\0\x10\0\0\0\x20\0\0\0\x6e\0\0\0\x10\0\0\0\x40\0\0\0\x73\0\0\0\x10\0\0\
\0\x60\0\0\0\x81\0\0\0\x10\0\0\0\x80\0\0\0\x8a\0\0\0\x10\0\0\0\xa0\0\0\0\x97\0\
\0\0\x10\0\0\0\xc0\0\0\0\xa0\0\0\0\x10\0\0\0\xe0\0\0\0\xab\0\0\0\x10\0\0\0\0\
\x01\0\0\xb4\0\0\0\x10\0\0\0\x20\x01\0\0\xc4\0\0\0\x10\0\0\0\x40\x01\0\0\xcc\0\
\0\0\x10\0\0\0\x60\x01\0\0\xd5\0\0\0\x12\0\0\0\x80\x01\0\0\xd8\0\0\0\x10\0\0\0\
\x20\x02\0\0\xdd\0\0\0\x10\0\0\0\x40\x02\0\0\xe8\0\0\0\x10\0\0\0\x60\x02\0\0\
\xed\0\0\0\x10\0\0\0\x80\x02\0\0\xf6\0\0\0\x10\0\0\0\xa0\x02\0\0\xfe\0\0\0\x10\
\0\0\0\xc0\x02\0\0\x05\x01\0\0\x10\0\0\0\xe0\x02\0\0\x10\x01\0\0\x10\0\0\0\0\
\x03\0\0\x1a\x01\0\0\x13\0\0\0\x20\x03\0\0\x25\x01\0\0\x13\0\0\0\xa0\x03\0\0\
\x2f\x01\0\0\x10\0\0\0\x20\x04\0\0\x3b\x01\0\0\x10\0\0\0\x40\x04\0\0\x46\x01\0\
\0\x10\0\0\0\x60\x04\0\0\0\0\0\0\x14\0\0\0\x80\x04\0\0\x50\x01\0\0\x16\0\0\0\
\xc0\x04\0\0\x57\x01\0\0\x10\0\0\0\0\x05\0\0\x60\x01\0\0\x10\0\0\0\x20\x05\0\0\
\0\0\0\0\x18\0\0\0\x40\x05\0\0\x69\x01\0\0\x10\0\0\0\x80\x05\0\0\x72\x01\0\0\
\x16\0\0\0\xc0\x05\0\0\x7b\x01\0\0\0\0\0\x08\x11\0\0\0\x81\x01\0\0\0\0\0\x01\
\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x10\0\0\0\x04\0\0\0\x05\0\0\0\0\
\0\0\0\0\0\0\x03\0\0\0\0\x10\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\
\0\0\0\x8e\x01\0\0\x15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x1f\0\0\0\x98\x01\0\0\0\
\0\0\x08\x17\0\0\0\x9e\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\
\x05\x08\0\0\0\xb1\x01\0\0\x19\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x20\0\0\0\0\0\0\
\0\x01\0\0\x0d\x02\0\0\0\xb4\x01\0\0\x0e\0\0\0\xb8\x01\0\0\x01\0\0\x0c\x1a\0\0\
\0\xbe\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x1c\0\
\0\0\x04\0\0\0\x04\0\0\0\xc3\x01\0\0\0\0\0\x0e\x1d\0\0\0\x01\0\0\0\xcc\x01\0\0\
\0\0\0\x07\0\0\0\0\xda\x01\0\0\0\0\0\x07\0\0\0\0\x7c\x03\0\0\x02\0\0\x0f\x50\0\
\0\0\x0c\0\0\0\0\0\0\0\x28\0\0\0\x0d\0\0\0\x28\0\0\0\x28\0\0\0\x82\x03\0\0\x01\
\0\0\x0f\x04\0\0\0\x1e\0\0\0\0\0\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\
\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x74\x79\x70\x65\
\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x6d\x61\x70\x5f\x66\x6c\x61\
\x67\x73\0\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\x73\x69\
\x7a\x65\0\x6d\x61\x70\x5f\x69\x6e\0\x6d\x61\x70\x5f\x6f\x75\x74\0\x5f\x5f\x73\
\x6b\x5f\x62\x75\x66\x66\0\x6c\x65\x6e\0\x70\x6b\x74\x5f\x74\x79\x70\x65\0\x6d\
\x61\x72\x6b\0\x71\x75\x65\x75\x65\x5f\x6d\x61\x70\x70\x69\x6e\x67\0\x70\x72\
\x6f\x74\x6f\x63\x6f\x6c\0\x76\x6c\x61\x6e\x5f\x70\x72\x65\x73\x65\x6e\x74\0\
\x76\x6c\x61\x6e\x5f\x74\x63\x69\0\x76\x6c\x61\x6e\x5f\x70\x72\x6f\x74\x6f\0\
\x70\x72\x69\x6f\x72\x69\x74\x79\0\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\
\x6e\x64\x65\x78\0\x69\x66\x69\x6e\x64\x65\x78\0\x74\x63\x5f\x69\x6e\x64\x65\
\x78\0\x63\x62\0\x68\x61\x73\x68\0\x74\x63\x5f\x63\x6c\x61\x73\x73\x69\x64\0\
\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\x65\x6e\x64\0\x6e\x61\x70\x69\x5f\x69\
\x64\0\x66\x61\x6d\x69\x6c\x79\0\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x34\0\x6c\
\x6f\x63\x61\x6c\x5f\x69\x70\x34\0\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x36\0\
\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x36\0\x72\x65\x6d\x6f\x74\x65\x5f\x70\x6f\x72\
\x74\0\x6c\x6f\x63\x61\x6c\x5f\x70\x6f\x72\x74\0\x64\x61\x74\x61\x5f\x6d\x65\
\x74\x61\0\x74\x73\x74\x61\x6d\x70\0\x77\x69\x72\x65\x5f\x6c\x65\x6e\0\x67\x73\
\x6f\x5f\x73\x65\x67\x73\0\x67\x73\x6f\x5f\x73\x69\x7a\x65\0\x68\x77\x74\x73\
\x74\x61\x6d\x70\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\
\x69\x6e\x74\0\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x5f\x5f\x75\x36\x34\0\x75\
\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x73\x6b\
\0\x73\x6b\x62\0\x5f\x74\x65\x73\x74\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\
\x6e\x73\x65\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x62\x70\
\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\
\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\
\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\
\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\
\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\
\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\
\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x71\x75\x65\x75\x65\x5f\x73\
\x74\x61\x63\x6b\x5f\x6d\x61\x70\x2e\x68\0\x69\x6e\x74\x20\x5f\x74\x65\x73\x74\
\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\x20\x2a\
\x73\x6b\x62\x29\0\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\x61\x20\x3d\x20\x28\
\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x73\x6b\x62\x2d\x3e\x64\
\x61\x74\x61\x3b\0\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\x61\x5f\x65\x6e\x64\
\x20\x3d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x73\x6b\
\x62\x2d\x3e\x64\x61\x74\x61\x5f\x65\x6e\x64\x3b\0\x09\x69\x66\x20\x28\x65\x74\
\x68\x20\x2b\x20\x31\x20\x3e\x20\x64\x61\x74\x61\x5f\x65\x6e\x64\x29\0\x09\x65\
\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x70\x6f\x70\x5f\x65\x6c\
\x65\x6d\x28\x26\x6d\x61\x70\x5f\x69\x6e\x2c\x20\x26\x76\x61\x6c\x75\x65\x29\
\x3b\0\x09\x69\x66\x20\x28\x65\x72\x72\x29\0\x09\x69\x70\x68\x2d\x3e\x64\x61\
\x64\x64\x72\x20\x3d\x20\x76\x61\x6c\x75\x65\x3b\0\x09\x65\x72\x72\x20\x3d\x20\
\x62\x70\x66\x5f\x6d\x61\x70\x5f\x70\x75\x73\x68\x5f\x65\x6c\x65\x6d\x28\x26\
\x6d\x61\x70\x5f\x6f\x75\x74\x2c\x20\x26\x69\x70\x68\x2d\x3e\x73\x61\x64\x64\
\x72\x2c\x20\x30\x29\x3b\0\x7d\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x74\x65\x73\x74\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\
\xec\0\0\0\0\x01\0\0\0\0\0\0\x08\0\0\0\x8a\x03\0\0\x01\0\0\0\0\0\0\0\x1b\0\0\0\
\x10\0\0\0\x8a\x03\0\0\x0e\0\0\0\0\0\0\0\xe3\x01\0\0\x6d\x02\0\0\0\x70\0\0\x08\
\0\0\0\xe3\x01\0\0\x8e\x02\0\0\x22\x7c\0\0\x10\0\0\0\xe3\x01\0\0\xb5\x02\0\0\
\x26\x78\0\0\x18\0\0\0\xe3\x01\0\0\xe4\x02\0\0\x0a\x90\0\0\x28\0\0\0\xe3\x01\0\
\0\xe4\x02\0\0\x06\x90\0\0\x50\0\0\0\xe3\x01\0\0\0\0\0\0\0\0\0\0\x58\0\0\0\xe3\
\x01\0\0\xfd\x02\0\0\x08\xb0\0\0\x80\0\0\0\xe3\x01\0\0\x27\x03\0\0\x06\xb4\0\0\
\x88\0\0\0\xe3\x01\0\0\x31\x03\0\0\x0f\xc0\0\0\x90\0\0\0\xe3\x01\0\0\x31\x03\0\
\0\x0d\xc0\0\0\x98\0\0\0\xe3\x01\0\0\x46\x03\0\0\x2a\xc8\0\0\xa0\0\0\0\xe3\x01\
\0\0\x46\x03\0\0\x08\xc8\0\0\xf0\0\0\0\xe3\x01\0\0\0\0\0\0\0\0\0\0\xf8\0\0\0\
\xe3\x01\0\0\x7a\x03\0\0\x01\xdc\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\
\0\x78\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\
\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\
\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\x01\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x16\0\0\0\x01\0\0\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x98\x02\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1c\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\xe8\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x61\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\
\x02\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\x6a\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x03\0\0\0\
\0\0\0\xbf\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x6f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x0a\0\0\0\0\0\0\x20\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_STACK_MAP_SKEL_H__ */
