/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_CORE_RELOC_INTS_SKEL_H__
#define __TEST_CORE_RELOC_INTS_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_core_reloc_ints {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test_core_ints;
	} progs;
	struct {
		struct bpf_link *test_core_ints;
	} links;
	struct test_core_reloc_ints__bss {
		struct {
			char in[256];
			char out[256];
		} data;
	} *bss;
};

static void
test_core_reloc_ints__destroy(struct test_core_reloc_ints *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_core_reloc_ints__create_skeleton(struct test_core_reloc_ints *obj);

static inline struct test_core_reloc_ints *
test_core_reloc_ints__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_core_reloc_ints *obj;
	int err;

	obj = (struct test_core_reloc_ints *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_core_reloc_ints__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_core_reloc_ints__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_core_reloc_ints *
test_core_reloc_ints__open(void)
{
	return test_core_reloc_ints__open_opts(NULL);
}

static inline int
test_core_reloc_ints__load(struct test_core_reloc_ints *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_core_reloc_ints *
test_core_reloc_ints__open_and_load(void)
{
	struct test_core_reloc_ints *obj;
	int err;

	obj = test_core_reloc_ints__open();
	if (!obj)
		return NULL;
	err = test_core_reloc_ints__load(obj);
	if (err) {
		test_core_reloc_ints__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_core_reloc_ints__attach(struct test_core_reloc_ints *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_core_reloc_ints__detach(struct test_core_reloc_ints *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_core_reloc_ints__elf_bytes(size_t *sz);

static inline int
test_core_reloc_ints__create_skeleton(struct test_core_reloc_ints *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_core_reloc_ints";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_cor.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "test_core_ints";
	s->progs[0].prog = &obj->progs.test_core_ints;
	s->progs[0].link = &obj->links.test_core_ints;

	s->data = (void *)test_core_reloc_ints__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_core_reloc_ints__elf_bytes(size_t *sz)
{
	*sz = 4176;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x10\x0e\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x74\x65\x73\x74\
\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x69\x6e\x74\x73\x2e\x63\0\x4c\
\x42\x42\x30\x5f\x39\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x69\x6e\x74\x73\
\0\x64\x61\x74\x61\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4e\0\
\0\0\0\0\x03\0\xb8\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x55\0\0\0\x12\0\x03\0\0\0\0\
\0\0\0\0\0\xc8\x02\0\0\0\0\0\0\x64\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\0\x02\0\0\
\0\0\0\0\x69\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb7\x01\0\0\0\
\0\0\0\x18\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x0f\x13\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\x01\0\0\0\x01\0\0\
\xb4\x06\0\0\x01\0\0\0\xb4\x02\0\0\x01\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x4a\0\0\
\0\0\0\xb7\x01\0\0\x01\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\
\0\0\0\x07\x07\0\0\x01\x01\0\0\xb4\x06\0\0\x01\0\0\0\xbf\x71\0\0\0\0\0\0\xb4\
\x02\0\0\x01\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x40\0\0\0\0\0\xb7\x01\0\0\x02\0\0\
\0\x18\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\
\x13\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\x01\0\0\x02\x01\0\0\
\xb4\x02\0\0\x02\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x34\0\0\0\0\0\xb7\x01\0\0\x04\
\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\x07\x07\0\0\x04\
\x01\0\0\xbf\x71\0\0\0\0\0\0\xb4\x02\0\0\x02\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\
\x2b\0\0\0\0\0\xb7\x01\0\0\x08\0\0\0\x18\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x07\x01\0\0\x08\x01\0\0\xb4\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\
\x55\0\x1f\0\0\0\0\0\xb7\x01\0\0\x0c\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x0f\x13\0\0\0\0\0\0\x07\x07\0\0\x0c\x01\0\0\xbf\x71\0\0\0\0\0\0\xb4\x02\0\0\
\x04\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x16\0\0\0\0\0\xb7\x01\0\0\x10\0\0\0\x18\
\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\
\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\x01\0\0\x10\x01\0\0\xb4\x02\
\0\0\x08\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x0a\0\0\0\0\0\xb7\x01\0\0\x18\0\0\0\
\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\x07\x07\0\0\x18\x01\0\
\0\xbf\x71\0\0\0\0\0\0\xb4\x02\0\0\x08\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x01\0\0\
\0\0\0\xb4\x06\0\0\0\0\0\0\xbc\x60\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\
\0\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x18\0\0\0\0\0\0\0\x01\0\0\0\x05\
\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x70\0\0\0\0\0\0\0\x01\0\0\0\x05\0\
\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\xd0\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\
\0\xe8\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\0\x05\0\0\
\0\x68\x01\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x78\x01\0\0\0\0\0\0\x01\0\0\0\x05\0\
\0\0\x90\x01\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\xc8\x01\0\0\0\0\0\0\x01\0\0\0\x05\
\0\0\0\x10\x02\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x20\x02\0\0\0\0\0\0\x01\0\0\0\
\x05\0\0\0\x38\x02\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x70\x02\0\0\0\0\0\0\x01\0\0\
\0\x05\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x9c\x02\0\0\x9c\x02\0\0\x13\x04\0\
\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\
\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\0\x18\
\0\0\0\x08\0\0\x04\x20\0\0\0\x28\0\0\0\x06\0\0\0\0\0\0\0\x31\0\0\0\x09\0\0\0\
\x08\0\0\0\x3a\0\0\0\x0c\0\0\0\x10\0\0\0\x44\0\0\0\x0f\0\0\0\x20\0\0\0\x4e\0\0\
\0\x12\0\0\0\x40\0\0\0\x58\0\0\0\x15\0\0\0\x60\0\0\0\x62\0\0\0\x17\0\0\0\x80\0\
\0\0\x6c\0\0\0\x1a\0\0\0\xc0\0\0\0\x76\0\0\0\0\0\0\x08\x07\0\0\0\x7e\0\0\0\0\0\
\0\x08\x08\0\0\0\x88\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\x96\0\0\0\0\0\0\x08\
\x0a\0\0\0\x9d\0\0\0\0\0\0\x08\x0b\0\0\0\xa6\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\
\x01\xb2\0\0\0\0\0\0\x08\x0d\0\0\0\xbb\0\0\0\0\0\0\x08\x0e\0\0\0\xc6\0\0\0\0\0\
\0\x01\x02\0\0\0\x10\0\0\0\xd5\0\0\0\0\0\0\x08\x10\0\0\0\xdd\0\0\0\0\0\0\x08\
\x11\0\0\0\xe7\0\0\0\0\0\0\x01\x02\0\0\0\x10\0\0\x01\xed\0\0\0\0\0\0\x08\x13\0\
\0\0\xf6\0\0\0\0\0\0\x08\x14\0\0\0\x01\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\
\x0e\x01\0\0\0\0\0\x08\x16\0\0\0\x16\x01\0\0\0\0\0\x08\x03\0\0\0\x20\x01\0\0\0\
\0\0\x08\x18\0\0\0\x29\x01\0\0\0\0\0\x08\x19\0\0\0\x34\x01\0\0\0\0\0\x01\x08\0\
\0\0\x40\0\0\0\x47\x01\0\0\0\0\0\x08\x1b\0\0\0\x4f\x01\0\0\0\0\0\x08\x1c\0\0\0\
\x59\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\x01\x63\x01\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x1d\0\0\0\x1f\0\0\0\x04\0\0\0\x68\x01\0\
\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x7c\x01\0\0\0\0\0\x0e\x1e\0\0\0\x01\0\0\0\0\0\
\0\0\x02\0\0\x04\0\x02\0\0\x85\x01\0\0\x22\0\0\0\0\0\0\0\x88\x01\0\0\x22\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x1d\0\0\0\x1f\0\0\0\0\x01\0\0\x8c\x01\0\0\
\0\0\0\x0e\x21\0\0\0\x01\0\0\0\xed\x03\0\0\x01\0\0\x0f\x04\0\0\0\x20\0\0\0\0\0\
\0\0\x04\0\0\0\xf5\x03\0\0\x01\0\0\x0f\0\x02\0\0\x23\0\0\0\0\0\0\0\0\x02\0\0\0\
\x63\x74\x78\0\x69\x6e\x74\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x69\x6e\
\x74\x73\0\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x69\x6e\x74\x73\0\x75\
\x38\x5f\x66\x69\x65\x6c\x64\0\x73\x38\x5f\x66\x69\x65\x6c\x64\0\x75\x31\x36\
\x5f\x66\x69\x65\x6c\x64\0\x73\x31\x36\x5f\x66\x69\x65\x6c\x64\0\x75\x33\x32\
\x5f\x66\x69\x65\x6c\x64\0\x73\x33\x32\x5f\x66\x69\x65\x6c\x64\0\x75\x36\x34\
\x5f\x66\x69\x65\x6c\x64\0\x73\x36\x34\x5f\x66\x69\x65\x6c\x64\0\x75\x69\x6e\
\x74\x38\x5f\x74\0\x5f\x5f\x75\x69\x6e\x74\x38\x5f\x74\0\x75\x6e\x73\x69\x67\
\x6e\x65\x64\x20\x63\x68\x61\x72\0\x69\x6e\x74\x38\x5f\x74\0\x5f\x5f\x69\x6e\
\x74\x38\x5f\x74\0\x73\x69\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x75\x69\x6e\
\x74\x31\x36\x5f\x74\0\x5f\x5f\x75\x69\x6e\x74\x31\x36\x5f\x74\0\x75\x6e\x73\
\x69\x67\x6e\x65\x64\x20\x73\x68\x6f\x72\x74\0\x69\x6e\x74\x31\x36\x5f\x74\0\
\x5f\x5f\x69\x6e\x74\x31\x36\x5f\x74\0\x73\x68\x6f\x72\x74\0\x75\x69\x6e\x74\
\x33\x32\x5f\x74\0\x5f\x5f\x75\x69\x6e\x74\x33\x32\x5f\x74\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x69\x6e\x74\x33\x32\x5f\x74\0\x5f\x5f\x69\
\x6e\x74\x33\x32\x5f\x74\0\x75\x69\x6e\x74\x36\x34\x5f\x74\0\x5f\x5f\x75\x69\
\x6e\x74\x36\x34\x5f\x74\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\
\x20\x6c\x6f\x6e\x67\0\x69\x6e\x74\x36\x34\x5f\x74\0\x5f\x5f\x69\x6e\x74\x36\
\x34\x5f\x74\0\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x63\x68\x61\x72\0\x5f\x5f\
\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\
\x69\x63\x65\x6e\x73\x65\0\x69\x6e\0\x6f\x75\x74\0\x64\x61\x74\x61\0\x2f\x72\
\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\
\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\
\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\
\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\
\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\
\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x69\x6e\x74\x73\
\x2e\x63\0\x69\x6e\x74\x20\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x69\x6e\x74\
\x73\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x69\x66\x20\x28\x43\x4f\
\x52\x45\x5f\x52\x45\x41\x44\x28\x26\x6f\x75\x74\x2d\x3e\x75\x38\x5f\x66\x69\
\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\x3e\x75\x38\x5f\x66\x69\x65\x6c\x64\x29\
\x20\x7c\x7c\0\x09\x20\x20\x20\x20\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\x26\
\x6f\x75\x74\x2d\x3e\x73\x38\x5f\x66\x69\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\
\x3e\x73\x38\x5f\x66\x69\x65\x6c\x64\x29\x20\x7c\x7c\0\x09\x20\x20\x20\x20\x43\
\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\x26\x6f\x75\x74\x2d\x3e\x75\x31\x36\x5f\
\x66\x69\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\x3e\x75\x31\x36\x5f\x66\x69\x65\
\x6c\x64\x29\x20\x7c\x7c\0\x09\x20\x20\x20\x20\x43\x4f\x52\x45\x5f\x52\x45\x41\
\x44\x28\x26\x6f\x75\x74\x2d\x3e\x73\x31\x36\x5f\x66\x69\x65\x6c\x64\x2c\x20\
\x26\x69\x6e\x2d\x3e\x73\x31\x36\x5f\x66\x69\x65\x6c\x64\x29\x20\x7c\x7c\0\x09\
\x20\x20\x20\x20\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\x26\x6f\x75\x74\x2d\
\x3e\x75\x33\x32\x5f\x66\x69\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\x3e\x75\x33\
\x32\x5f\x66\x69\x65\x6c\x64\x29\x20\x7c\x7c\0\x09\x20\x20\x20\x20\x43\x4f\x52\
\x45\x5f\x52\x45\x41\x44\x28\x26\x6f\x75\x74\x2d\x3e\x73\x33\x32\x5f\x66\x69\
\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\x3e\x73\x33\x32\x5f\x66\x69\x65\x6c\x64\
\x29\x20\x7c\x7c\0\x09\x20\x20\x20\x20\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\
\x26\x6f\x75\x74\x2d\x3e\x75\x36\x34\x5f\x66\x69\x65\x6c\x64\x2c\x20\x26\x69\
\x6e\x2d\x3e\x75\x36\x34\x5f\x66\x69\x65\x6c\x64\x29\x20\x7c\x7c\0\x09\x20\x20\
\x20\x20\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x28\x26\x6f\x75\x74\x2d\x3e\x73\
\x36\x34\x5f\x66\x69\x65\x6c\x64\x2c\x20\x26\x69\x6e\x2d\x3e\x73\x36\x34\x5f\
\x66\x69\x65\x6c\x64\x29\x29\0\x7d\0\x30\x3a\x30\0\x30\x3a\x31\0\x30\x3a\x32\0\
\x30\x3a\x33\0\x30\x3a\x34\0\x30\x3a\x35\0\x30\x3a\x36\0\x30\x3a\x37\0\x6c\x69\
\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x72\x61\x77\x5f\x74\x72\x61\x63\x65\
\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\0\x9f\xeb\x01\0\
\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x2c\x01\0\0\x40\x01\0\0\x8c\0\0\0\x08\0\
\0\0\xfa\x03\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\xfa\x03\0\0\x12\0\0\0\0\
\0\0\0\x91\x01\0\0\x1b\x02\0\0\0\x78\0\0\x30\0\0\0\x91\x01\0\0\x39\x02\0\0\x06\
\x8c\0\0\x60\0\0\0\x91\x01\0\0\x39\x02\0\0\x2f\x8c\0\0\x88\0\0\0\x91\x01\0\0\
\x6a\x02\0\0\x06\x90\0\0\xb0\0\0\0\x91\x01\0\0\x6a\x02\0\0\x2f\x90\0\0\xe8\0\0\
\0\x91\x01\0\0\x9b\x02\0\0\x06\x94\0\0\x10\x01\0\0\x91\x01\0\0\x9b\x02\0\0\x31\
\x94\0\0\x38\x01\0\0\x91\x01\0\0\xce\x02\0\0\x06\x98\0\0\x58\x01\0\0\x91\x01\0\
\0\xce\x02\0\0\x31\x98\0\0\x90\x01\0\0\x91\x01\0\0\x01\x03\0\0\x06\x9c\0\0\xb8\
\x01\0\0\x91\x01\0\0\x01\x03\0\0\x31\x9c\0\0\xe0\x01\0\0\x91\x01\0\0\x34\x03\0\
\0\x06\xa0\0\0\0\x02\0\0\x91\x01\0\0\x34\x03\0\0\x31\xa0\0\0\x38\x02\0\0\x91\
\x01\0\0\x67\x03\0\0\x06\xa4\0\0\x60\x02\0\0\x91\x01\0\0\x67\x03\0\0\x31\xa4\0\
\0\x88\x02\0\0\x91\x01\0\0\x9a\x03\0\0\x06\xa8\0\0\xa8\x02\0\0\x91\x01\0\0\x39\
\x02\0\0\x06\x8c\0\0\xb8\x02\0\0\x91\x01\0\0\xcb\x03\0\0\x01\xb8\0\0\x10\0\0\0\
\xfa\x03\0\0\x08\0\0\0\0\0\0\0\x05\0\0\0\xcd\x03\0\0\0\0\0\0\x68\0\0\0\x05\0\0\
\0\xd1\x03\0\0\0\0\0\0\xb8\0\0\0\x05\0\0\0\xd5\x03\0\0\0\0\0\0\x18\x01\0\0\x05\
\0\0\0\xd9\x03\0\0\0\0\0\0\x60\x01\0\0\x05\0\0\0\xdd\x03\0\0\0\0\0\0\xc0\x01\0\
\0\x05\0\0\0\xe1\x03\0\0\0\0\0\0\x08\x02\0\0\x05\0\0\0\xe5\x03\0\0\0\0\0\0\x68\
\x02\0\0\x05\0\0\0\xe9\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\
\0\0\0\0\0\0\x9d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\0\0\0\0\xa8\0\
\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x01\0\0\0\0\0\0\xc8\x02\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x04\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x08\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x54\x04\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x72\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x58\x04\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\
\0\0\x10\0\0\0\0\0\0\0\x8f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\
\x05\0\0\0\0\0\0\xc7\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x94\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x0c\0\0\0\0\0\
\0\xec\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_CORE_RELOC_INTS_SKEL_H__ */
