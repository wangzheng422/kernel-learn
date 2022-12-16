/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_MAP_IN_MAP_SKEL_H__
#define __TEST_MAP_IN_MAP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_map_in_map {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *mim_array;
		struct bpf_map *mim_hash;
	} maps;
	struct {
		struct bpf_program *xdp_mimtest0;
	} progs;
	struct {
		struct bpf_link *xdp_mimtest0;
	} links;
};

static void
test_map_in_map__destroy(struct test_map_in_map *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_map_in_map__create_skeleton(struct test_map_in_map *obj);

static inline struct test_map_in_map *
test_map_in_map__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_map_in_map *obj;
	int err;

	obj = (struct test_map_in_map *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_map_in_map__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_map_in_map__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_map_in_map *
test_map_in_map__open(void)
{
	return test_map_in_map__open_opts(NULL);
}

static inline int
test_map_in_map__load(struct test_map_in_map *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_map_in_map *
test_map_in_map__open_and_load(void)
{
	struct test_map_in_map *obj;
	int err;

	obj = test_map_in_map__open();
	if (!obj)
		return NULL;
	err = test_map_in_map__load(obj);
	if (err) {
		test_map_in_map__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_map_in_map__attach(struct test_map_in_map *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_map_in_map__detach(struct test_map_in_map *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_map_in_map__elf_bytes(size_t *sz);

static inline int
test_map_in_map__create_skeleton(struct test_map_in_map *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_map_in_map";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "mim_array";
	s->maps[0].map = &obj->maps.mim_array;

	s->maps[1].name = "mim_hash";
	s->maps[1].map = &obj->maps.mim_hash;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "xdp_mimtest0";
	s->progs[0].prog = &obj->progs.xdp_mimtest0;
	s->progs[0].link = &obj->links.xdp_mimtest0;

	s->data = (void *)test_map_in_map__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_map_in_map__elf_bytes(size_t *sz)
{
	*sz = 3096;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xd8\x09\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x78\x64\
\x70\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\
\x6d\x61\x70\x5f\x69\x6e\x5f\x6d\x61\x70\x2e\x63\0\x4c\x42\x42\x30\x5f\x35\0\
\x78\x64\x70\x5f\x6d\x69\x6d\x74\x65\x73\x74\x30\0\x6d\x69\x6d\x5f\x61\x72\x72\
\x61\x79\0\x6d\x69\x6d\x5f\x68\x61\x73\x68\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\
\x2e\x72\x65\x6c\x78\x64\x70\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\
\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x23\0\0\0\x04\
\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x35\0\0\0\0\0\x03\0\x40\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3c\0\
\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x49\0\0\0\x11\0\x04\0\0\0\
\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x53\0\0\0\x11\0\x04\0\x28\0\0\0\0\0\0\0\x28\0\0\
\0\0\0\0\0\x5c\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb7\x01\0\0\
\x7b\0\0\0\x63\x1a\xfc\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x63\x1a\xf8\xff\0\0\0\0\
\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xf8\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x07\0\0\0\0\0\0\xb7\x06\0\0\x01\0\0\0\x15\x07\
\x1c\0\0\0\0\0\xbf\xa8\0\0\0\0\0\0\x07\x08\0\0\xf8\xff\xff\xff\xbf\xa3\0\0\0\0\
\0\0\x07\x03\0\0\xfc\xff\xff\xff\xbf\x71\0\0\0\0\0\0\xbf\x82\0\0\0\0\0\0\xb7\
\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xbf\x71\0\0\0\0\0\0\xbf\x82\0\0\0\0\0\0\
\x85\0\0\0\x01\0\0\0\x15\0\x10\0\0\0\0\0\x61\x01\0\0\0\0\0\0\x55\x01\x0e\0\x7b\
\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xf8\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\x15\0\x08\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\
\x02\0\0\xf8\xff\xff\xff\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xfc\xff\xff\xff\xbf\
\x01\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xb7\x06\0\0\x02\0\0\0\
\xbf\x60\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x30\0\0\0\0\0\
\0\0\x01\0\0\0\x05\0\0\0\xe0\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x9f\xeb\x01\0\
\x18\0\0\0\0\0\0\0\x88\x02\0\0\x88\x02\0\0\x8d\x02\0\0\0\0\0\0\0\0\0\x02\x03\0\
\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\
\0\0\x04\0\0\0\x0c\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\
\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\x02\x08\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x02\x0a\0\0\0\x19\0\0\0\0\0\0\x08\x0b\0\0\0\x1f\0\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\0\0\0\0\0\x05\0\0\x04\x28\0\0\0\x2c\0\0\0\x01\0\0\0\0\0\0\0\x31\
\0\0\0\x05\0\0\0\x40\0\0\0\x3d\0\0\0\x07\0\0\0\x80\0\0\0\x47\0\0\0\x09\0\0\0\
\xc0\0\0\0\x4b\0\0\0\x09\0\0\0\0\x01\0\0\x51\0\0\0\0\0\0\x0e\x0c\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\x02\x0f\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\
\x0d\0\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\x05\0\0\x04\x28\0\0\0\x2c\0\0\0\
\x0e\0\0\0\0\0\0\0\x31\0\0\0\x05\0\0\0\x40\0\0\0\x3d\0\0\0\x07\0\0\0\x80\0\0\0\
\x47\0\0\0\x10\0\0\0\xc0\0\0\0\x4b\0\0\0\x09\0\0\0\0\x01\0\0\x5b\0\0\0\0\0\0\
\x0e\x11\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\x64\0\0\0\x06\0\0\x04\x18\
\0\0\0\x6b\0\0\0\x0a\0\0\0\0\0\0\0\x70\0\0\0\x0a\0\0\0\x20\0\0\0\x79\0\0\0\x0a\
\0\0\0\x40\0\0\0\x83\0\0\0\x0a\0\0\0\x60\0\0\0\x93\0\0\0\x0a\0\0\0\x80\0\0\0\
\xa2\0\0\0\x0a\0\0\0\xa0\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\xb1\0\0\0\x13\0\0\
\0\xb5\0\0\0\x01\0\0\x0c\x15\0\0\0\xc2\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\
\0\0\0\0\0\0\x03\0\0\0\0\x17\0\0\0\x04\0\0\0\x04\0\0\0\xc7\0\0\0\0\0\0\x0e\x18\
\0\0\0\x01\0\0\0\x7b\x02\0\0\x02\0\0\x0f\x50\0\0\0\x0d\0\0\0\0\0\0\0\x28\0\0\0\
\x12\0\0\0\x28\0\0\0\x28\0\0\0\x81\x02\0\0\x01\0\0\x0f\x04\0\0\0\x19\0\0\0\0\0\
\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\
\x65\x64\x20\x69\x6e\x74\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\
\x69\x65\x73\0\x6d\x61\x70\x5f\x66\x6c\x61\x67\x73\0\x6b\x65\x79\0\x76\x61\x6c\
\x75\x65\0\x6d\x69\x6d\x5f\x61\x72\x72\x61\x79\0\x6d\x69\x6d\x5f\x68\x61\x73\
\x68\0\x78\x64\x70\x5f\x6d\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\x65\x6e\
\x64\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x69\x6e\x67\x72\x65\x73\x73\x5f\
\x69\x66\x69\x6e\x64\x65\x78\0\x72\x78\x5f\x71\x75\x65\x75\x65\x5f\x69\x6e\x64\
\x65\x78\0\x65\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x63\x74\
\x78\0\x78\x64\x70\x5f\x6d\x69\x6d\x74\x65\x73\x74\x30\0\x63\x68\x61\x72\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\
\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\
\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\
\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\
\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\
\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x6d\x61\x70\x5f\x69\x6e\
\x5f\x6d\x61\x70\x2e\x63\0\x69\x6e\x74\x20\x78\x64\x70\x5f\x6d\x69\x6d\x74\x65\
\x73\x74\x30\x28\x73\x74\x72\x75\x63\x74\x20\x78\x64\x70\x5f\x6d\x64\x20\x2a\
\x63\x74\x78\x29\0\x09\x69\x6e\x74\x20\x76\x61\x6c\x75\x65\x20\x3d\x20\x31\x32\
\x33\x3b\0\x09\x69\x6e\x74\x20\x6b\x65\x79\x20\x3d\x20\x30\x3b\0\x09\x6d\x61\
\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\
\x65\x6c\x65\x6d\x28\x26\x6d\x69\x6d\x5f\x61\x72\x72\x61\x79\x2c\x20\x26\x6b\
\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x6d\x61\x70\x29\0\x09\x62\x70\x66\
\x5f\x6d\x61\x70\x5f\x75\x70\x64\x61\x74\x65\x5f\x65\x6c\x65\x6d\x28\x6d\x61\
\x70\x2c\x20\x26\x6b\x65\x79\x2c\x20\x26\x76\x61\x6c\x75\x65\x2c\x20\x30\x29\
\x3b\0\x09\x76\x61\x6c\x75\x65\x5f\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\
\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x6d\x61\x70\x2c\x20\x26\
\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x76\x61\x6c\x75\x65\x5f\x70\x20\
\x7c\x7c\x20\x2a\x76\x61\x6c\x75\x65\x5f\x70\x20\x21\x3d\x20\x31\x32\x33\x29\0\
\x09\x6d\x61\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\
\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x6d\x69\x6d\x5f\x68\x61\x73\x68\x2c\x20\
\x26\x6b\x65\x79\x29\x3b\0\x7d\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x78\x64\x70\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\
\x2c\x01\0\0\x40\x01\0\0\0\0\0\0\x08\0\0\0\x89\x02\0\0\x01\0\0\0\0\0\0\0\x16\0\
\0\0\x10\0\0\0\x89\x02\0\0\x12\0\0\0\0\0\0\0\xd0\0\0\0\x55\x01\0\0\0\x64\0\0\
\x08\0\0\0\xd0\0\0\0\x7a\x01\0\0\x06\x6c\0\0\x18\0\0\0\xd0\0\0\0\x8c\x01\0\0\
\x06\x74\0\0\x28\0\0\0\xd0\0\0\0\0\0\0\0\0\0\0\0\x30\0\0\0\xd0\0\0\0\x9a\x01\0\
\0\x08\x80\0\0\x58\0\0\0\xd0\0\0\0\xc8\x01\0\0\x06\x84\0\0\x68\0\0\0\xd0\0\0\0\
\0\0\0\0\0\0\0\0\x80\0\0\0\xd0\0\0\0\xd3\x01\0\0\x02\x90\0\0\xa0\0\0\0\xd0\0\0\
\0\xff\x01\0\0\x0c\x94\0\0\xb8\0\0\0\xd0\0\0\0\x2a\x02\0\0\x0f\x98\0\0\xc0\0\0\
\0\xd0\0\0\0\x2a\x02\0\0\x12\x98\0\0\xc8\0\0\0\xd0\0\0\0\x2a\x02\0\0\x06\x98\0\
\0\xd8\0\0\0\xd0\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\xd0\0\0\0\x4c\x02\0\0\x08\xa4\
\0\0\xf8\0\0\0\xd0\0\0\0\xc8\x01\0\0\x06\xa8\0\0\x08\x01\0\0\xd0\0\0\0\0\0\0\0\
\0\0\0\0\x20\x01\0\0\xd0\0\0\0\xd3\x01\0\0\x02\xb4\0\0\x40\x01\0\0\xd0\0\0\0\
\x79\x02\0\0\x01\xc0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x7b\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\
\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x80\x01\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\xd0\x02\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x1b\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\
\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x65\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x03\0\0\0\0\0\
\0\x20\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\x6d\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x03\0\0\0\0\0\0\x2d\
\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x72\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\x08\0\0\0\0\0\0\x60\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_MAP_IN_MAP_SKEL_H__ */