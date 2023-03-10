/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_SEG6_LOOP_SKEL_H__
#define __TEST_SEG6_LOOP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_seg6_loop {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *__add_egr_x;
	} progs;
	struct {
		struct bpf_link *__add_egr_x;
	} links;
	struct test_seg6_loop__rodata {
	} *rodata;
};

static void
test_seg6_loop__destroy(struct test_seg6_loop *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_seg6_loop__create_skeleton(struct test_seg6_loop *obj);

static inline struct test_seg6_loop *
test_seg6_loop__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_seg6_loop *obj;
	int err;

	obj = (struct test_seg6_loop *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_seg6_loop__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_seg6_loop__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_seg6_loop *
test_seg6_loop__open(void)
{
	return test_seg6_loop__open_opts(NULL);
}

static inline int
test_seg6_loop__load(struct test_seg6_loop *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_seg6_loop *
test_seg6_loop__open_and_load(void)
{
	struct test_seg6_loop *obj;
	int err;

	obj = test_seg6_loop__open();
	if (!obj)
		return NULL;
	err = test_seg6_loop__load(obj);
	if (err) {
		test_seg6_loop__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_seg6_loop__attach(struct test_seg6_loop *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_seg6_loop__detach(struct test_seg6_loop *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_seg6_loop__elf_bytes(size_t *sz);

static inline int
test_seg6_loop__create_skeleton(struct test_seg6_loop *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_seg6_loop";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_seg.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "__add_egr_x";
	s->progs[0].prog = &obj->progs.__add_egr_x;
	s->progs[0].link = &obj->links.__add_egr_x;

	s->data = (void *)test_seg6_loop__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_seg6_loop__elf_bytes(size_t *sz)
{
	*sz = 7600;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb0\x1b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x08\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x6c\x77\
\x74\x5f\x73\x65\x67\x36\x6c\x6f\x63\x61\x6c\0\x2e\x72\x6f\x64\x61\x74\x61\0\
\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x73\x65\x67\x36\x5f\x6c\x6f\
\x6f\x70\x2e\x63\0\x4c\x42\x42\x30\x5f\x36\0\x4c\x42\x42\x30\x5f\x38\0\x4c\x42\
\x42\x30\x5f\x37\0\x4c\x42\x42\x30\x5f\x31\x31\0\x4c\x42\x42\x30\x5f\x32\x31\0\
\x4c\x42\x42\x30\x5f\x31\x34\0\x4c\x42\x42\x30\x5f\x31\x33\0\x4c\x42\x42\x30\
\x5f\x32\x32\0\x4c\x42\x42\x30\x5f\x31\x38\0\x4c\x42\x42\x30\x5f\x32\x34\0\x4c\
\x42\x42\x30\x5f\x32\x39\0\x4c\x42\x42\x30\x5f\x33\x31\0\x4c\x42\x42\x30\x5f\
\x33\x33\0\x5f\x5f\x61\x64\x64\x5f\x65\x67\x72\x5f\x78\0\x5f\x5f\x6c\x69\x63\
\x65\x6e\x73\x65\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\x04\0\xf1\xff\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x40\0\0\0\0\0\x03\0\x98\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\0\0\0\0\0\x03\
\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4e\0\0\0\0\0\x03\0\xa0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x55\0\0\0\0\0\x03\0\xb8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5d\0\0\0\
\0\0\x03\0\x20\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x65\0\0\0\0\0\x03\0\x38\x02\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x6d\0\0\0\0\0\x03\0\xe0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x75\0\0\0\0\0\x03\0\x60\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7d\0\0\0\0\0\x03\0\
\xd0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\0\0\x03\0\xc8\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x8d\0\0\0\0\0\x03\0\xc8\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x95\0\0\
\0\0\0\x03\0\x40\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9d\0\0\0\0\0\x03\0\x28\x06\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xa5\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xf8\x06\0\0\0\
\0\0\0\xb1\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xbf\x16\0\0\0\0\
\0\0\x61\x61\x50\0\0\0\0\0\x61\x67\x4c\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\x07\x02\0\
\0\x01\0\0\0\x2d\x12\x0d\0\0\0\0\0\x71\x72\0\0\0\0\0\0\x57\x02\0\0\xf0\0\0\0\
\x55\x02\x0a\0\x60\0\0\0\xbf\x73\0\0\0\0\0\0\x07\x03\0\0\x28\0\0\0\x2d\x13\x07\
\0\0\0\0\0\x71\x72\x06\0\0\0\0\0\x55\x02\x05\0\x2b\0\0\0\xbf\x72\0\0\0\0\0\0\
\x07\x02\0\0\x30\0\0\0\x2d\x12\x02\0\0\0\0\0\x71\x71\x2a\0\0\0\0\0\x15\x01\x03\
\0\x04\0\0\0\xb7\x08\0\0\x02\0\0\0\xbf\x80\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb7\
\x01\0\0\x10\0\0\0\x73\x1a\xef\xff\0\0\0\0\xb7\x08\0\0\x02\0\0\0\x15\x03\xfa\
\xff\0\0\0\0\xb7\x01\0\0\0\0\0\x04\x63\x1a\xd0\xff\0\0\0\0\x18\x01\0\0\x02\x12\
\0\0\0\0\0\0\xfd\0\0\0\x7b\x1a\xc0\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xc8\
\xff\0\0\0\0\x1f\x73\0\0\0\0\0\0\x71\x71\x29\0\0\0\0\0\x67\x01\0\0\x03\0\0\0\
\xbf\x30\0\0\0\0\0\0\x07\0\0\0\x08\0\0\0\x7b\x0a\xa8\xff\0\0\0\0\x0f\x10\0\0\0\
\0\0\0\xbf\x04\0\0\0\0\0\0\x67\x04\0\0\x20\0\0\0\x77\x04\0\0\x20\0\0\0\x71\x71\
\x2c\0\0\0\0\0\x67\x01\0\0\x04\0\0\0\x7b\x3a\xa0\xff\0\0\0\0\xbf\x32\0\0\0\0\0\
\0\x0f\x12\0\0\0\0\0\0\x07\x02\0\0\x18\0\0\0\xbf\x23\0\0\0\0\0\0\x67\x03\0\0\
\x20\0\0\0\x77\x03\0\0\x20\0\0\0\xb7\x01\0\0\x01\0\0\0\x1d\x43\x01\0\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x3d\x43\x0c\0\0\0\0\0\xb7\x03\0\0\x64\0\0\0\x7b\x3a\xb0\
\xff\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x05\0\x0b\0\0\0\0\0\x71\x73\x29\0\0\0\0\0\
\x67\x03\0\0\x03\0\0\0\x79\xa4\xa8\xff\0\0\0\0\x0f\x34\0\0\0\0\0\0\x67\x04\0\0\
\x20\0\0\0\x77\x04\0\0\x20\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\xad\x45\x03\0\0\0\0\0\
\xb7\x09\0\0\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x05\0\x25\0\0\0\0\0\xbf\x09\0\0\0\
\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf0\xff\xff\xff\xbf\x61\0\0\0\0\0\0\xbf\
\x28\0\0\0\0\0\0\xb7\x04\0\0\x02\0\0\0\x85\0\0\0\x1a\0\0\0\x67\0\0\0\x20\0\0\0\
\x77\0\0\0\x20\0\0\0\x55\0\xc2\xff\0\0\0\0\x71\xa3\xf0\xff\0\0\0\0\x79\xa1\xb8\
\xff\0\0\0\0\xbf\x82\0\0\0\0\0\0\xbf\x90\0\0\0\0\0\0\x15\x03\xee\xff\x05\0\0\0\
\x55\x03\x03\0\x04\0\0\0\x71\xa9\xf1\xff\0\0\0\0\x07\x09\0\0\x02\0\0\0\x05\0\
\x12\0\0\0\0\0\x71\xa1\xf1\xff\0\0\0\0\x0f\x12\0\0\0\0\0\0\xb7\x09\0\0\0\0\0\0\
\x07\x02\0\0\x02\0\0\0\x79\xa1\xb0\xff\0\0\0\0\x07\x01\0\0\xff\xff\xff\xff\x15\
\x01\x0b\0\0\0\0\0\x7b\x1a\xb0\xff\0\0\0\0\xbf\x03\0\0\0\0\0\0\x67\x03\0\0\x20\
\0\0\0\x77\x03\0\0\x20\0\0\0\xbf\x25\0\0\0\0\0\0\x67\x05\0\0\x20\0\0\0\x77\x05\
\0\0\x20\0\0\0\xb7\x01\0\0\x01\0\0\0\x1d\x35\xd2\xff\0\0\0\0\x79\xa1\xb8\xff\0\
\0\0\0\x05\0\xd0\xff\0\0\0\0\xbf\x01\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\
\0\0\x20\0\0\0\x18\x03\0\0\xff\xff\xff\xff\0\0\0\0\0\0\0\0\xbf\x27\0\0\0\0\0\0\
\x1d\x31\x06\0\0\0\0\0\xb7\x08\0\0\x02\0\0\0\x79\xa1\xb8\xff\0\0\0\0\x67\x01\0\
\0\x20\0\0\0\x77\x01\0\0\x20\0\0\0\xbf\x02\0\0\0\0\0\0\x15\x01\x9b\xff\0\0\0\0\
\xbf\x61\0\0\0\0\0\0\xbf\x28\0\0\0\0\0\0\xb7\x03\0\0\x14\0\0\0\x85\0\0\0\x4b\0\
\0\0\xbf\x82\0\0\0\0\0\0\xb7\x08\0\0\x02\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\
\x20\0\0\0\x55\0\x92\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xc0\xff\xff\
\xff\xbf\x61\0\0\0\0\0\0\xb7\x04\0\0\x14\0\0\0\x85\0\0\0\x4a\0\0\0\x67\0\0\0\
\x20\0\0\0\x77\0\0\0\x20\0\0\0\x55\0\x8a\xff\0\0\0\0\x71\xa1\xc1\xff\0\0\0\0\
\xbf\x72\0\0\0\0\0\0\x0f\x12\0\0\0\0\0\0\xb7\x04\0\0\x09\0\0\0\x07\x02\0\0\x02\
\0\0\0\xbf\x21\0\0\0\0\0\0\x79\xa3\xa0\xff\0\0\0\0\x1f\x31\0\0\0\0\0\0\x57\x01\
\0\0\x07\0\0\0\xbf\x93\0\0\0\0\0\0\x15\x01\x04\0\x07\0\0\0\xb7\x04\0\0\0\0\0\0\
\x15\x01\x02\0\0\0\0\0\xb7\x04\0\0\x08\0\0\0\x1f\x14\0\0\0\0\0\0\x7b\x2a\xb8\
\xff\0\0\0\0\xbf\x47\0\0\0\0\0\0\x67\x07\0\0\x20\0\0\0\x77\x07\0\0\x20\0\0\0\
\x1d\x37\x0a\0\0\0\0\0\xbf\x43\0\0\0\0\0\0\x1f\x93\0\0\0\0\0\0\xbf\x61\0\0\0\0\
\0\0\x79\xa2\xb8\xff\0\0\0\0\xbf\x49\0\0\0\0\0\0\x85\0\0\0\x4b\0\0\0\xbf\x94\0\
\0\0\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\x55\0\x6c\xff\0\0\0\0\x15\
\x07\x1c\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x73\x1a\xff\xff\0\0\0\0\x73\x1a\xfe\xff\
\0\0\0\0\x73\x1a\xfd\xff\0\0\0\0\x73\x1a\xfc\xff\0\0\0\0\x73\x1a\xfb\xff\0\0\0\
\0\x73\x1a\xfa\xff\0\0\0\0\x73\x1a\xf9\xff\0\0\0\0\x73\x1a\xf8\xff\0\0\0\0\x73\
\x1a\xf7\xff\0\0\0\0\x73\x1a\xf6\xff\0\0\0\0\x73\x1a\xf5\xff\0\0\0\0\x73\x1a\
\xf4\xff\0\0\0\0\x73\x1a\xf3\xff\0\0\0\0\x73\x1a\xf2\xff\0\0\0\0\xb7\x01\0\0\
\x04\0\0\0\x73\x1a\xf0\xff\0\0\0\0\xbf\x41\0\0\0\0\0\0\x07\x01\0\0\xfe\xff\xff\
\xff\x73\x1a\xf1\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf0\xff\xff\xff\
\xbf\x61\0\0\0\0\0\0\x79\xa2\xb8\xff\0\0\0\0\x85\0\0\0\x4a\0\0\0\x67\0\0\0\x20\
\0\0\0\x77\0\0\0\x20\0\0\0\x55\0\x4f\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\
\0\xef\xff\xff\xff\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\x2d\0\0\0\xb7\x04\0\0\x01\0\
\0\0\x85\0\0\0\x4a\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\x55\0\x46\xff\
\0\0\0\0\xb7\x01\0\0\xfc\x42\0\0\x7b\x1a\xd8\xff\0\0\0\0\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\x7b\x1a\xe0\xff\0\0\0\0\xb7\x08\0\0\x02\0\0\0\xbf\xa3\0\0\0\0\
\0\0\x07\x03\0\0\xd8\xff\xff\xff\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\x02\0\0\0\xb7\
\x04\0\0\x10\0\0\0\x85\0\0\0\x4c\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\
\x55\0\x37\xff\0\0\0\0\xb7\x08\0\0\x07\0\0\0\x05\0\x35\xff\0\0\0\0\x02\x12\0\0\
\xfd\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\x47\x50\x4c\0\x9f\xeb\x01\0\x18\0\0\0\0\0\
\0\0\x08\x03\0\0\x08\x03\0\0\x6d\x09\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\
\x21\0\0\x04\xc0\0\0\0\x0b\0\0\0\x03\0\0\0\0\0\0\0\x0f\0\0\0\x03\0\0\0\x20\0\0\
\0\x18\0\0\0\x03\0\0\0\x40\0\0\0\x1d\0\0\0\x03\0\0\0\x60\0\0\0\x2b\0\0\0\x03\0\
\0\0\x80\0\0\0\x34\0\0\0\x03\0\0\0\xa0\0\0\0\x41\0\0\0\x03\0\0\0\xc0\0\0\0\x4a\
\0\0\0\x03\0\0\0\xe0\0\0\0\x55\0\0\0\x03\0\0\0\0\x01\0\0\x5e\0\0\0\x03\0\0\0\
\x20\x01\0\0\x6e\0\0\0\x03\0\0\0\x40\x01\0\0\x76\0\0\0\x03\0\0\0\x60\x01\0\0\
\x7f\0\0\0\x05\0\0\0\x80\x01\0\0\x82\0\0\0\x03\0\0\0\x20\x02\0\0\x87\0\0\0\x03\
\0\0\0\x40\x02\0\0\x92\0\0\0\x03\0\0\0\x60\x02\0\0\x97\0\0\0\x03\0\0\0\x80\x02\
\0\0\xa0\0\0\0\x03\0\0\0\xa0\x02\0\0\xa8\0\0\0\x03\0\0\0\xc0\x02\0\0\xaf\0\0\0\
\x03\0\0\0\xe0\x02\0\0\xba\0\0\0\x03\0\0\0\0\x03\0\0\xc4\0\0\0\x07\0\0\0\x20\
\x03\0\0\xcf\0\0\0\x07\0\0\0\xa0\x03\0\0\xd9\0\0\0\x03\0\0\0\x20\x04\0\0\xe5\0\
\0\0\x03\0\0\0\x40\x04\0\0\xf0\0\0\0\x03\0\0\0\x60\x04\0\0\0\0\0\0\x08\0\0\0\
\x80\x04\0\0\xfa\0\0\0\x0a\0\0\0\xc0\x04\0\0\x01\x01\0\0\x03\0\0\0\0\x05\0\0\
\x0a\x01\0\0\x03\0\0\0\x20\x05\0\0\0\0\0\0\x0c\0\0\0\x40\x05\0\0\x13\x01\0\0\
\x03\0\0\0\x80\x05\0\0\x1c\x01\0\0\x0a\0\0\0\xc0\x05\0\0\x25\x01\0\0\0\0\0\x08\
\x04\0\0\0\x2b\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x03\0\0\0\x06\0\0\0\x05\0\0\0\x38\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\
\0\0\0\0\x03\0\0\0\0\x03\0\0\0\x06\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\
\0\x4c\x01\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\x56\x01\0\0\0\0\0\
\x08\x0b\0\0\0\x5c\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x05\
\x08\0\0\0\x6f\x01\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x15\0\0\0\0\0\0\0\
\x01\0\0\x0d\x0f\0\0\0\x72\x01\0\0\x01\0\0\0\x76\x01\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\x01\x7a\x01\0\0\x01\0\0\x0c\x0e\0\0\0\x86\x01\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x11\0\0\0\x06\0\0\0\x04\0\0\0\x8b\x01\0\
\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\x95\x01\0\0\0\0\0\x07\0\0\0\0\xa3\x01\0\0\0\0\
\0\x07\0\0\0\0\x4f\x09\0\0\0\0\0\x0f\x14\0\0\0\x57\x09\0\0\x01\0\0\x0f\x04\0\0\
\0\x13\0\0\0\0\0\0\0\x04\0\0\0\0\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\0\x6c\x65\
\x6e\0\x70\x6b\x74\x5f\x74\x79\x70\x65\0\x6d\x61\x72\x6b\0\x71\x75\x65\x75\x65\
\x5f\x6d\x61\x70\x70\x69\x6e\x67\0\x70\x72\x6f\x74\x6f\x63\x6f\x6c\0\x76\x6c\
\x61\x6e\x5f\x70\x72\x65\x73\x65\x6e\x74\0\x76\x6c\x61\x6e\x5f\x74\x63\x69\0\
\x76\x6c\x61\x6e\x5f\x70\x72\x6f\x74\x6f\0\x70\x72\x69\x6f\x72\x69\x74\x79\0\
\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x69\x66\x69\x6e\
\x64\x65\x78\0\x74\x63\x5f\x69\x6e\x64\x65\x78\0\x63\x62\0\x68\x61\x73\x68\0\
\x74\x63\x5f\x63\x6c\x61\x73\x73\x69\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\
\x5f\x65\x6e\x64\0\x6e\x61\x70\x69\x5f\x69\x64\0\x66\x61\x6d\x69\x6c\x79\0\x72\
\x65\x6d\x6f\x74\x65\x5f\x69\x70\x34\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x34\0\
\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x36\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x36\
\0\x72\x65\x6d\x6f\x74\x65\x5f\x70\x6f\x72\x74\0\x6c\x6f\x63\x61\x6c\x5f\x70\
\x6f\x72\x74\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x74\x73\x74\x61\x6d\x70\0\
\x77\x69\x72\x65\x5f\x6c\x65\x6e\0\x67\x73\x6f\x5f\x73\x65\x67\x73\0\x67\x73\
\x6f\x5f\x73\x69\x7a\x65\0\x68\x77\x74\x73\x74\x61\x6d\x70\0\x5f\x5f\x75\x33\
\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\
\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x66\x6c\x6f\x77\x5f\
\x6b\x65\x79\x73\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\
\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x73\x6b\0\x73\x6b\x62\0\x69\x6e\x74\0\
\x5f\x5f\x61\x64\x64\x5f\x65\x67\x72\x5f\x78\0\x63\x68\x61\x72\0\x5f\x5f\x6c\
\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\
\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\
\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\
\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\
\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\
\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\
\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x73\x65\x67\x36\
\x5f\x6c\x6f\x6f\x70\x2e\x63\0\x69\x6e\x74\x20\x5f\x5f\x61\x64\x64\x5f\x65\x67\
\x72\x5f\x78\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\x5f\x62\x75\x66\
\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x64\x61\x74\x61\x5f\x65\x6e\x64\x20\x3d\x20\
\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x73\x6b\x62\x2d\x3e\
\x64\x61\x74\x61\x5f\x65\x6e\x64\x3b\0\x09\x63\x75\x72\x73\x6f\x72\x20\x3d\x20\
\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x73\x6b\x62\x2d\x3e\
\x64\x61\x74\x61\x3b\0\x09\x69\x66\x20\x28\x28\x76\x6f\x69\x64\x20\x2a\x29\x69\
\x70\x76\x65\x72\x20\x2b\x20\x73\x69\x7a\x65\x6f\x66\x28\x2a\x69\x70\x76\x65\
\x72\x29\x20\x3e\x20\x64\x61\x74\x61\x5f\x65\x6e\x64\x29\0\x09\x69\x66\x20\x28\
\x28\x2a\x69\x70\x76\x65\x72\x20\x3e\x3e\x20\x34\x29\x20\x21\x3d\x20\x36\x29\0\
\x09\x69\x70\x20\x3d\x20\x63\x75\x72\x73\x6f\x72\x5f\x61\x64\x76\x61\x6e\x63\
\x65\x28\x63\x75\x72\x73\x6f\x72\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x2a\x69\
\x70\x29\x29\x3b\0\x09\x69\x66\x20\x28\x28\x76\x6f\x69\x64\x20\x2a\x29\x69\x70\
\x20\x2b\x20\x73\x69\x7a\x65\x6f\x66\x28\x2a\x69\x70\x29\x20\x3e\x20\x64\x61\
\x74\x61\x5f\x65\x6e\x64\x29\0\x09\x69\x66\x20\x28\x69\x70\x2d\x3e\x6e\x65\x78\
\x74\x5f\x68\x65\x61\x64\x65\x72\x20\x21\x3d\x20\x34\x33\x29\0\x09\x69\x66\x20\
\x28\x73\x72\x68\x2d\x3e\x74\x79\x70\x65\x20\x21\x3d\x20\x34\x29\0\x7d\0\x09\
\x75\x69\x6e\x74\x38\x5f\x74\x20\x6e\x65\x77\x5f\x66\x6c\x61\x67\x73\x20\x3d\
\x20\x53\x52\x36\x5f\x46\x4c\x41\x47\x5f\x41\x4c\x45\x52\x54\x3b\0\x09\x69\x66\
\x20\x28\x73\x72\x68\x20\x3d\x3d\x20\x4e\x55\x4c\x4c\x29\0\x09\x75\x69\x6e\x74\
\x38\x5f\x74\x20\x74\x6c\x76\x5b\x32\x30\x5d\x20\x3d\x20\x7b\x32\x2c\x20\x31\
\x38\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x78\x66\x64\x2c\x20\x30\x78\x30\x2c\
\x20\x30\x78\x30\x2c\x20\x30\x78\x30\x2c\x20\x30\x78\x30\x2c\x20\x30\x78\x30\
\x2c\x20\x30\x78\x30\x2c\x20\x30\x78\x30\x2c\0\x09\x75\x69\x6e\x74\x33\x32\x5f\
\x74\x20\x73\x72\x68\x5f\x6f\x66\x66\x20\x3d\x20\x28\x63\x68\x61\x72\x20\x2a\
\x29\x73\x72\x68\x20\x2d\x20\x28\x63\x68\x61\x72\x20\x2a\x29\x28\x6c\x6f\x6e\
\x67\x29\x73\x6b\x62\x2d\x3e\x64\x61\x74\x61\x3b\0\x09\x65\x72\x72\x20\x3d\x20\
\x61\x64\x64\x5f\x74\x6c\x76\x28\x73\x6b\x62\x2c\x20\x73\x72\x68\x2c\x20\x28\
\x73\x72\x68\x2d\x3e\x68\x64\x72\x6c\x65\x6e\x2b\x31\x29\x20\x3c\x3c\x20\x33\
\x2c\0\x09\x69\x66\x20\x28\x74\x6c\x76\x5f\x6f\x66\x66\x20\x21\x3d\x20\x2d\x31\
\x29\0\x09\x09\x73\x69\x7a\x65\x6f\x66\x28\x73\x74\x72\x75\x63\x74\x20\x69\x70\
\x36\x5f\x61\x64\x64\x72\x5f\x74\x29\x20\x2a\x20\x28\x73\x72\x68\x2d\x3e\x66\
\x69\x72\x73\x74\x5f\x73\x65\x67\x6d\x65\x6e\x74\x20\x2b\x20\x31\x29\x3b\0\x09\
\x63\x75\x72\x5f\x6f\x66\x66\x20\x3d\x20\x73\x72\x68\x5f\x6f\x66\x66\x20\x2b\
\x20\x73\x69\x7a\x65\x6f\x66\x28\x2a\x73\x72\x68\x29\x20\x2b\0\x09\x09\x69\x66\
\x20\x28\x63\x75\x72\x5f\x6f\x66\x66\x20\x3d\x3d\x20\x2a\x74\x6c\x76\x5f\x6f\
\x66\x66\x29\0\x09\x09\x69\x66\x20\x28\x63\x75\x72\x5f\x6f\x66\x66\x20\x3e\x3d\
\x20\x73\x72\x68\x5f\x6f\x66\x66\x20\x2b\x20\x28\x28\x73\x72\x68\x2d\x3e\x68\
\x64\x72\x6c\x65\x6e\x20\x2b\x20\x31\x29\x20\x3c\x3c\x20\x33\x29\x29\0\x09\x09\
\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x73\x6b\x62\x5f\x6c\x6f\x61\x64\x5f\
\x62\x79\x74\x65\x73\x28\x73\x6b\x62\x2c\x20\x63\x75\x72\x5f\x6f\x66\x66\x2c\
\x20\x26\x74\x6c\x76\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x74\x6c\x76\x29\x29\
\x3b\0\x09\x09\x69\x66\x20\x28\x65\x72\x72\x29\0\x09\x09\x69\x66\x20\x28\x74\
\x6c\x76\x2e\x74\x79\x70\x65\x20\x3d\x3d\x20\x53\x52\x36\x5f\x54\x4c\x56\x5f\
\x50\x41\x44\x44\x49\x4e\x47\x29\x20\x7b\0\x09\x09\x09\x2a\x70\x61\x64\x5f\x73\
\x69\x7a\x65\x20\x3d\x20\x74\x6c\x76\x2e\x6c\x65\x6e\x20\x2b\x20\x73\x69\x7a\
\x65\x6f\x66\x28\x74\x6c\x76\x29\x3b\0\x09\x09\x63\x75\x72\x5f\x6f\x66\x66\x20\
\x2b\x3d\x20\x73\x69\x7a\x65\x6f\x66\x28\x74\x6c\x76\x29\x20\x2b\x20\x74\x6c\
\x76\x2e\x6c\x65\x6e\x3b\0\x09\x66\x6f\x72\x20\x28\x6c\x6f\x6e\x67\x20\x69\x20\
\x3d\x20\x30\x3b\x20\x69\x20\x3c\x20\x31\x30\x30\x3b\x20\x69\x2b\x2b\x29\x20\
\x7b\0\x09\x69\x66\x20\x28\x2a\x74\x6c\x76\x5f\x6f\x66\x66\x20\x3d\x3d\x20\x2d\
\x31\x29\0\x09\x65\x6c\x73\x65\x20\x69\x66\x20\x28\x21\x6f\x66\x66\x73\x65\x74\
\x5f\x76\x61\x6c\x69\x64\x29\0\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x6c\
\x77\x74\x5f\x73\x65\x67\x36\x5f\x61\x64\x6a\x75\x73\x74\x5f\x73\x72\x68\x28\
\x73\x6b\x62\x2c\x20\x74\x6c\x76\x5f\x6f\x66\x66\x2c\x20\x73\x69\x7a\x65\x6f\
\x66\x28\x2a\x69\x74\x6c\x76\x29\x20\x2b\x20\x69\x74\x6c\x76\x2d\x3e\x6c\x65\
\x6e\x29\x3b\0\x09\x69\x66\x20\x28\x65\x72\x72\x29\0\x09\x65\x72\x72\x20\x3d\
\x20\x62\x70\x66\x5f\x6c\x77\x74\x5f\x73\x65\x67\x36\x5f\x73\x74\x6f\x72\x65\
\x5f\x62\x79\x74\x65\x73\x28\x73\x6b\x62\x2c\x20\x74\x6c\x76\x5f\x6f\x66\x66\
\x2c\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x69\x74\x6c\x76\x2c\x20\x74\x6c\x76\
\x5f\x73\x69\x7a\x65\x29\x3b\0\x09\x70\x61\x64\x5f\x6f\x66\x66\x20\x2b\x3d\x20\
\x73\x69\x7a\x65\x6f\x66\x28\x2a\x69\x74\x6c\x76\x29\x20\x2b\x20\x69\x74\x6c\
\x76\x2d\x3e\x6c\x65\x6e\x3b\0\x09\x70\x61\x72\x74\x69\x61\x6c\x5f\x73\x72\x68\
\x5f\x6c\x65\x6e\x20\x3d\x20\x70\x61\x64\x5f\x6f\x66\x66\x20\x2d\x20\x73\x72\
\x68\x5f\x6f\x66\x66\x3b\0\x09\x6e\x65\x77\x5f\x70\x61\x64\x20\x3d\x20\x38\x20\
\x2d\x20\x6c\x65\x6e\x5f\x72\x65\x6d\x61\x69\x6e\x69\x6e\x67\x3b\0\x09\x69\x66\
\x20\x28\x6e\x65\x77\x5f\x70\x61\x64\x20\x3d\x3d\x20\x31\x29\x20\x2f\x2f\x20\
\x63\x61\x6e\x6e\x6f\x74\x20\x70\x61\x64\x20\x66\x6f\x72\x20\x31\x20\x62\x79\
\x74\x65\x20\x6f\x6e\x6c\x79\0\x09\x65\x6c\x73\x65\x20\x69\x66\x20\x28\x6e\x65\
\x77\x5f\x70\x61\x64\x20\x3d\x3d\x20\x38\x29\0\x09\x69\x66\x20\x28\x6e\x65\x77\
\x5f\x70\x61\x64\x20\x21\x3d\x20\x6f\x6c\x64\x5f\x70\x61\x64\x29\x20\x7b\0\x09\
\x09\x09\x09\x09\x20\x20\x28\x69\x6e\x74\x29\x20\x6e\x65\x77\x5f\x70\x61\x64\
\x20\x2d\x20\x28\x69\x6e\x74\x29\x20\x6f\x6c\x64\x5f\x70\x61\x64\x29\x3b\0\x09\
\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x6c\x77\x74\x5f\x73\x65\x67\x36\
\x5f\x61\x64\x6a\x75\x73\x74\x5f\x73\x72\x68\x28\x73\x6b\x62\x2c\x20\x70\x61\
\x64\x5f\x6f\x66\x66\x2c\0\x09\x69\x66\x20\x28\x6e\x65\x77\x5f\x70\x61\x64\x20\
\x3e\x20\x30\x29\x20\x7b\0\x09\x09\x63\x68\x61\x72\x20\x70\x61\x64\x5f\x74\x6c\
\x76\x5f\x62\x75\x66\x5b\x31\x36\x5d\x20\x3d\x20\x7b\x30\x2c\x20\x30\x2c\x20\
\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\
\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2c\0\x09\x09\x70\x61\x64\x5f\
\x74\x6c\x76\x2d\x3e\x74\x79\x70\x65\x20\x3d\x20\x53\x52\x36\x5f\x54\x4c\x56\
\x5f\x50\x41\x44\x44\x49\x4e\x47\x3b\0\x09\x09\x70\x61\x64\x5f\x74\x6c\x76\x2d\
\x3e\x6c\x65\x6e\x20\x3d\x20\x6e\x65\x77\x5f\x70\x61\x64\x20\x2d\x20\x32\x3b\0\
\x09\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x6c\x77\x74\x5f\x73\x65\x67\
\x36\x5f\x73\x74\x6f\x72\x65\x5f\x62\x79\x74\x65\x73\x28\x73\x6b\x62\x2c\x20\
\x70\x61\x64\x5f\x6f\x66\x66\x2c\0\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\
\x6c\x77\x74\x5f\x73\x65\x67\x36\x5f\x73\x74\x6f\x72\x65\x5f\x62\x79\x74\x65\
\x73\x28\x73\x6b\x62\x2c\x20\x6f\x66\x66\x73\x65\x74\x2c\0\x09\x61\x64\x64\x72\
\x2e\x68\x69\x20\x3d\x20\x62\x70\x66\x5f\x63\x70\x75\x5f\x74\x6f\x5f\x62\x65\
\x36\x34\x28\x68\x69\x29\x3b\0\x09\x61\x64\x64\x72\x2e\x6c\x6f\x20\x3d\x20\x62\
\x70\x66\x5f\x63\x70\x75\x5f\x74\x6f\x5f\x62\x65\x36\x34\x28\x6c\x6f\x29\x3b\0\
\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x6c\x77\x74\x5f\x73\x65\x67\x36\
\x5f\x61\x63\x74\x69\x6f\x6e\x28\x73\x6b\x62\x2c\x20\x53\x45\x47\x36\x5f\x4c\
\x4f\x43\x41\x4c\x5f\x41\x43\x54\x49\x4f\x4e\x5f\x45\x4e\x44\x5f\x58\x2c\0\x2e\
\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x6c\x77\x74\x5f\x73\
\x65\x67\x36\x6c\x6f\x63\x61\x6c\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\
\0\0\x14\0\0\0\x1c\x05\0\0\x30\x05\0\0\0\0\0\0\x08\0\0\0\x5f\x09\0\0\x01\0\0\0\
\0\0\0\0\x10\0\0\0\x10\0\0\0\x5f\x09\0\0\x51\0\0\0\0\0\0\0\xac\x01\0\0\x30\x02\
\0\0\0\x88\x03\0\x08\0\0\0\xac\x01\0\0\x57\x02\0\0\x20\xf0\0\0\x10\0\0\0\xac\
\x01\0\0\x80\x02\0\0\x1e\xf4\0\0\x18\0\0\0\xac\x01\0\0\xa3\x02\0\0\x14\0\x01\0\
\x28\0\0\0\xac\x01\0\0\xa3\x02\0\0\x06\0\x01\0\x30\0\0\0\xac\x01\0\0\xd3\x02\0\
\0\x07\x0c\x01\0\x38\0\0\0\xac\x01\0\0\xd3\x02\0\0\x14\x0c\x01\0\x40\0\0\0\xac\
\x01\0\0\xd3\x02\0\0\x06\x0c\x01\0\x48\0\0\0\xac\x01\0\0\xec\x02\0\0\x07\x18\
\x01\0\x58\0\0\0\xac\x01\0\0\x17\x03\0\0\x06\x1c\x01\0\x60\0\0\0\xac\x01\0\0\
\x41\x03\0\0\x0a\x28\x01\0\x68\0\0\0\xac\x01\0\0\x41\x03\0\0\x06\x28\x01\0\x88\
\0\0\0\xac\x01\0\0\x5d\x03\0\0\x0b\x44\x01\0\x90\0\0\0\xac\x01\0\0\0\0\0\0\0\0\
\0\0\xa0\0\0\0\xac\x01\0\0\x72\x03\0\0\x01\x0c\x04\0\xb8\0\0\0\xac\x01\0\0\x74\
\x03\0\0\x0a\x9c\x03\0\xc8\0\0\0\xac\x01\0\0\x99\x03\0\0\x06\xac\x03\0\xd8\0\0\
\0\xac\x01\0\0\xab\x03\0\0\x0a\xb8\x03\0\x08\x01\0\0\xac\x01\0\0\xf5\x03\0\0\
\x15\xdc\x02\0\x10\x01\0\0\xac\x01\0\0\x30\x04\0\0\x20\xc4\x03\0\x18\x01\0\0\
\xac\x01\0\0\x30\x04\0\0\x2a\xc4\x03\0\x38\x01\0\0\xac\x01\0\0\x5f\x04\0\0\x06\
\xf8\x02\0\x58\x01\0\0\xac\x01\0\0\x73\x04\0\0\x25\x08\x02\0\x60\x01\0\0\xac\
\x01\0\0\x73\x04\0\0\x1d\x08\x02\0\x70\x01\0\0\xac\x01\0\0\xab\x04\0\0\x23\x04\
\x02\0\xa8\x01\0\0\xac\x01\0\0\xcf\x04\0\0\x0f\x34\x02\0\xb8\x01\0\0\xac\x01\0\
\0\xea\x04\0\0\x07\x40\x02\0\xe0\x01\0\0\xac\x01\0\0\xea\x04\0\0\x23\x40\x02\0\
\xe8\x01\0\0\xac\x01\0\0\xea\x04\0\0\x2f\x40\x02\0\xf0\x01\0\0\xac\x01\0\0\xea\
\x04\0\0\x1a\x40\x02\0\x18\x02\0\0\xac\x01\0\0\xea\x04\0\0\x07\x40\x02\0\x48\
\x02\0\0\xac\x01\0\0\0\0\0\0\0\0\0\0\x50\x02\0\0\xac\x01\0\0\x1f\x05\0\0\x09\
\x4c\x02\0\x80\x02\0\0\xac\x01\0\0\x5c\x05\0\0\x07\x50\x02\0\x88\x02\0\0\xac\
\x01\0\0\x67\x05\0\0\x0b\x5c\x02\0\xa8\x02\0\0\xac\x01\0\0\x67\x05\0\0\x07\x5c\
\x02\0\xb8\x02\0\0\xac\x01\0\0\x8c\x05\0\0\x14\x60\x02\0\xc0\x02\0\0\xac\x01\0\
\0\x8c\x05\0\0\x18\x60\x02\0\xd0\x02\0\0\xac\x01\0\0\xb2\x05\0\0\x20\x94\x02\0\
\xd8\x02\0\0\xac\x01\0\0\xb2\x05\0\0\x1a\x94\x02\0\xe8\x02\0\0\xac\x01\0\0\xb2\
\x05\0\0\x0b\x94\x02\0\xf8\x02\0\0\xac\x01\0\0\xd6\x05\0\0\x15\x28\x02\0\0\x03\
\0\0\xac\x01\0\0\xd6\x05\0\0\x02\x28\x02\0\x10\x03\0\0\xac\x01\0\0\xcf\x04\0\0\
\x0f\x34\x02\0\x48\x03\0\0\xac\x01\0\0\xcf\x04\0\0\x07\x34\x02\0\x60\x03\0\0\
\xac\x01\0\0\xf8\x05\0\0\x0f\xac\x02\0\x90\x03\0\0\xac\x01\0\0\xf8\x05\0\0\x06\
\xac\x02\0\xa8\x03\0\0\xac\x01\0\0\x0d\x06\0\0\x0c\xb4\x02\0\xc0\x03\0\0\xac\
\x01\0\0\x0d\x06\0\0\x0b\xb4\x02\0\xc8\x03\0\0\xac\x01\0\0\x26\x06\0\0\x08\x20\
\x03\0\x08\x04\0\0\xac\x01\0\0\x6f\x06\0\0\x06\x24\x03\0\x18\x04\0\0\xac\x01\0\
\0\0\0\0\0\0\0\0\0\x20\x04\0\0\xac\x01\0\0\x79\x06\0\0\x08\x30\x03\0\x48\x04\0\
\0\xac\x01\0\0\x6f\x06\0\0\x06\x34\x03\0\x50\x04\0\0\xac\x01\0\0\xc0\x06\0\0\
\x23\x48\x03\0\x60\x04\0\0\xac\x01\0\0\xc0\x06\0\0\x1b\x48\x03\0\x70\x04\0\0\
\xac\x01\0\0\xc0\x06\0\0\x0a\x48\x03\0\x78\x04\0\0\xac\x01\0\0\xe7\x06\0\0\x1c\
\x4c\x03\0\x90\x04\0\0\xac\x01\0\0\x0d\x07\0\0\x0c\x54\x03\0\xa0\x04\0\0\xac\
\x01\0\0\x2b\x07\0\0\x06\x5c\x03\0\xb0\x04\0\0\xac\x01\0\0\x5c\x07\0\0\x0b\x64\
\x03\0\xd0\x04\0\0\xac\x01\0\0\x74\x07\0\0\x0e\x74\x01\0\xe8\x04\0\0\xac\x01\0\
\0\x74\x07\0\0\x06\x74\x01\0\xf0\x04\0\0\xac\x01\0\0\x8f\x07\0\0\x16\x7c\x01\0\
\0\x05\0\0\xac\x01\0\0\xb6\x07\0\0\x09\x78\x01\0\x38\x05\0\0\xac\x01\0\0\x5c\
\x05\0\0\x07\x80\x01\0\x40\x05\0\0\xac\x01\0\0\xe4\x07\0\0\x06\x90\x01\0\x50\
\x05\0\0\xac\x01\0\0\xf8\x07\0\0\x08\x94\x01\0\xc8\x05\0\0\xac\x01\0\0\x39\x08\
\0\0\x11\xa4\x01\0\xd0\x05\0\0\xac\x01\0\0\x5c\x08\0\0\x12\xa8\x01\0\xe0\x05\0\
\0\xac\x01\0\0\x5c\x08\0\0\x10\xa8\x01\0\xf0\x05\0\0\xac\x01\0\0\xf8\x07\0\0\
\x08\x94\x01\0\xf8\x05\0\0\xac\x01\0\0\x7a\x08\0\0\x09\xb0\x01\0\x30\x06\0\0\
\xac\x01\0\0\0\0\0\0\0\0\0\0\x38\x06\0\0\xac\x01\0\0\xa9\x08\0\0\x08\xdc\x03\0\
\x68\x06\0\0\xac\x01\0\0\x6f\x06\0\0\x06\xe4\x03\0\x78\x06\0\0\xac\x01\0\0\xd6\
\x08\0\0\x0a\xf4\x03\0\x90\x06\0\0\xac\x01\0\0\xf6\x08\0\0\x0a\xf0\x03\0\xa8\
\x06\0\0\xac\x01\0\0\xd6\x08\0\0\x0a\xf4\x03\0\xb0\x06\0\0\xac\x01\0\0\x16\x09\
\0\0\x08\xf8\x03\0\xe0\x06\0\0\xac\x01\0\0\x6f\x06\0\0\x06\0\x04\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xc9\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\
\x01\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\
\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x02\0\0\
\0\0\0\0\xf8\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x1f\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\x09\0\0\0\0\0\0\x14\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x27\0\0\0\x01\
\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xcc\x09\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbb\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x09\0\0\0\0\0\0\x8d\x0c\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x60\x16\0\0\0\0\0\0\x50\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_SEG6_LOOP_SKEL_H__ */
