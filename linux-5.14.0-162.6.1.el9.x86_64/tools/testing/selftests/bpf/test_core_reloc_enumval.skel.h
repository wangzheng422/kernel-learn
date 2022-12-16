/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_CORE_RELOC_ENUMVAL_SKEL_H__
#define __TEST_CORE_RELOC_ENUMVAL_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_core_reloc_enumval {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test_core_enumval;
	} progs;
	struct {
		struct bpf_link *test_core_enumval;
	} links;
	struct test_core_reloc_enumval__bss {
		struct {
			char in[256];
			char out[256];
			_Bool skip;
		} data;
	} *bss;
};

static void
test_core_reloc_enumval__destroy(struct test_core_reloc_enumval *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_core_reloc_enumval__create_skeleton(struct test_core_reloc_enumval *obj);

static inline struct test_core_reloc_enumval *
test_core_reloc_enumval__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_core_reloc_enumval *obj;
	int err;

	obj = (struct test_core_reloc_enumval *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_core_reloc_enumval__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_core_reloc_enumval__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_core_reloc_enumval *
test_core_reloc_enumval__open(void)
{
	return test_core_reloc_enumval__open_opts(NULL);
}

static inline int
test_core_reloc_enumval__load(struct test_core_reloc_enumval *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_core_reloc_enumval *
test_core_reloc_enumval__open_and_load(void)
{
	struct test_core_reloc_enumval *obj;
	int err;

	obj = test_core_reloc_enumval__open();
	if (!obj)
		return NULL;
	err = test_core_reloc_enumval__load(obj);
	if (err) {
		test_core_reloc_enumval__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_core_reloc_enumval__attach(struct test_core_reloc_enumval *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_core_reloc_enumval__detach(struct test_core_reloc_enumval *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_core_reloc_enumval__elf_bytes(size_t *sz);

static inline int
test_core_reloc_enumval__create_skeleton(struct test_core_reloc_enumval *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_core_reloc_enumval";
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

	s->progs[0].name = "test_core_enumval";
	s->progs[0].prog = &obj->progs.test_core_enumval;
	s->progs[0].link = &obj->links.test_core_enumval;

	s->data = (void *)test_core_reloc_enumval__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_core_reloc_enumval__elf_bytes(size_t *sz)
{
	*sz = 3656;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\x0c\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x74\x65\x73\x74\
\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x65\x6e\x75\x6d\x76\x61\x6c\
\x2e\x63\0\x4c\x42\x42\x30\x5f\x32\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\x30\
\x5f\x36\0\x4c\x42\x42\x30\x5f\x38\0\x4c\x42\x42\x30\x5f\x31\x30\0\x4c\x42\x42\
\x30\x5f\x31\x32\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x76\
\x61\x6c\0\x64\x61\x74\x61\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\
\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\0\x04\0\xf1\xff\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x51\
\0\0\0\0\0\x03\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\0\0\0\0\0\x03\0\x68\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x5f\0\0\0\0\0\x03\0\x90\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x66\0\0\0\0\0\x03\0\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6d\0\0\0\0\0\x03\0\
\xd0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x75\0\0\0\0\0\x03\0\xf0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7d\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xa0\x01\0\0\0\0\0\0\x8f\0\0\0\
\x11\0\x05\0\0\0\0\0\0\0\0\0\x01\x02\0\0\0\0\0\0\x94\0\0\0\x11\0\x04\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x04\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\x18\x03\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\xb4\x02\0\0\x01\0\0\0\xb4\x01\0\0\x01\0\0\0\x55\x03\
\x01\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x18\x05\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\xb4\
\x03\0\0\x01\0\0\0\x55\x04\x01\0\0\0\0\0\xb4\x03\0\0\0\0\0\0\x18\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\xb4\x04\0\0\x01\0\0\0\x55\x05\x01\0\0\0\0\0\xb4\x04\0\0\0\0\
\0\0\x18\x06\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\xb4\x05\0\0\x01\0\0\0\x55\0\x01\0\0\
\0\0\0\xb4\x05\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x55\x06\x01\0\0\0\0\0\xb4\0\0\0\
\0\0\0\0\x18\x06\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\x55\x06\x01\0\0\0\0\0\xb4\x02\0\
\0\0\0\0\0\x18\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x73\x26\0\x01\0\0\0\0\x73\x06\
\x01\x01\0\0\0\0\x73\x56\x02\x01\0\0\0\0\x73\x46\x03\x01\0\0\0\0\x73\x36\x04\
\x01\0\0\0\0\x73\x16\x05\x01\0\0\0\0\x18\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\x63\
\x16\x08\x01\0\0\0\0\x18\x01\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\x63\x16\x0c\x01\0\0\
\0\0\x18\x01\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\x63\x16\x10\x01\0\0\0\0\x18\x01\0\0\
\x20\0\0\0\0\0\0\0\0\0\0\0\x63\x16\x14\x01\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\
\0\0\0\0\x47\x50\x4c\0\0\0\0\0\xf0\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x9f\xeb\
\x01\0\x18\0\0\0\0\0\0\0\x70\x01\0\0\x70\x01\0\0\x8e\x04\0\0\0\0\0\0\0\0\0\x02\
\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\
\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\0\x1b\0\0\0\0\0\0\x08\x06\
\0\0\0\0\0\0\0\x03\0\0\x06\x04\0\0\0\x25\0\0\0\x10\0\0\0\x34\0\0\0\x20\0\0\0\
\x43\0\0\0\x30\0\0\0\x52\0\0\0\x03\0\0\x06\x04\0\0\0\x5d\0\0\0\x01\0\0\0\x6d\0\
\0\0\x02\0\0\0\x7d\0\0\0\x03\0\0\0\x8d\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\
\0\0\0\0\0\0\x03\0\0\0\0\x08\0\0\0\x0a\0\0\0\x04\0\0\0\x92\0\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\0\xa6\0\0\0\0\0\0\x0e\x09\0\0\0\x01\0\0\0\0\0\0\0\x03\0\0\x04\
\x01\x02\0\0\xaf\0\0\0\x0d\0\0\0\0\0\0\0\xb2\0\0\0\x0d\0\0\0\0\x08\0\0\xb6\0\0\
\0\x0e\0\0\0\0\x10\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x08\0\0\0\x0a\0\0\0\0\x01\0\0\
\xbb\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x04\xc1\0\0\0\0\0\0\x0e\x0c\0\0\0\x01\0\
\0\0\x68\x04\0\0\x01\0\0\x0f\x04\0\0\0\x0b\0\0\0\0\0\0\0\x04\0\0\0\x70\x04\0\0\
\x01\0\0\x0f\x01\x02\0\0\x0f\0\0\0\0\0\0\0\x01\x02\0\0\0\x63\x74\x78\0\x69\x6e\
\x74\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x76\x61\x6c\0\
\x61\x6e\x6f\x6e\x5f\x65\x6e\x75\x6d\0\x41\x4e\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\
\x56\x41\x4c\x31\0\x41\x4e\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\0\
\x41\x4e\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x33\0\x6e\x61\x6d\x65\x64\
\x5f\x65\x6e\x75\x6d\0\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\
\x31\0\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\0\x4e\x41\
\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x33\0\x63\x68\x61\x72\0\x5f\
\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x69\x6e\0\x6f\x75\x74\0\x73\x6b\x69\x70\0\x5f\
\x42\x6f\x6f\x6c\0\x64\x61\x74\x61\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\
\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\
\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\
\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\
\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\
\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\
\x5f\x72\x65\x6c\x6f\x63\x5f\x65\x6e\x75\x6d\x76\x61\x6c\x2e\x63\0\x69\x6e\x74\
\x20\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x76\x61\x6c\x28\
\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x6f\x75\x74\x2d\x3e\x61\x6e\x6f\
\x6e\x5f\x76\x61\x6c\x33\x5f\x65\x78\x69\x73\x74\x73\x20\x3d\x20\x62\x70\x66\
\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\x5f\x65\x78\
\x69\x73\x74\x73\x28\x61\x6e\x6f\x6e\x5f\x65\x6e\x75\x6d\x2c\x20\x41\x4e\x4f\
\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x33\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\
\x61\x6e\x6f\x6e\x5f\x76\x61\x6c\x32\x5f\x65\x78\x69\x73\x74\x73\x20\x3d\x20\
\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\
\x5f\x65\x78\x69\x73\x74\x73\x28\x61\x6e\x6f\x6e\x5f\x65\x6e\x75\x6d\x2c\x20\
\x41\x4e\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\x29\x3b\0\x09\x6f\x75\
\x74\x2d\x3e\x61\x6e\x6f\x6e\x5f\x76\x61\x6c\x31\x5f\x65\x78\x69\x73\x74\x73\
\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\
\x6c\x75\x65\x5f\x65\x78\x69\x73\x74\x73\x28\x61\x6e\x6f\x6e\x2c\x20\x41\x4e\
\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x31\x29\x3b\0\x09\x6f\x75\x74\x2d\
\x3e\x6e\x61\x6d\x65\x64\x5f\x76\x61\x6c\x33\x5f\x65\x78\x69\x73\x74\x73\x20\
\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\
\x75\x65\x5f\x65\x78\x69\x73\x74\x73\x28\x65\x6e\x75\x6d\x20\x6e\x61\x6d\x65\
\x64\x5f\x65\x6e\x75\x6d\x2c\x20\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\
\x56\x41\x4c\x33\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6e\x61\x6d\x65\x64\x5f\x76\
\x61\x6c\x32\x5f\x65\x78\x69\x73\x74\x73\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\
\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\x5f\x65\x78\x69\x73\x74\
\x73\x28\x65\x6e\x75\x6d\x20\x6e\x61\x6d\x65\x64\x5f\x65\x6e\x75\x6d\x2c\x20\
\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\x29\x3b\0\x09\x6f\
\x75\x74\x2d\x3e\x6e\x61\x6d\x65\x64\x5f\x76\x61\x6c\x31\x5f\x65\x78\x69\x73\
\x74\x73\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\
\x76\x61\x6c\x75\x65\x5f\x65\x78\x69\x73\x74\x73\x28\x6e\x61\x6d\x65\x64\x2c\
\x20\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x31\x29\x3b\0\x09\
\x6f\x75\x74\x2d\x3e\x6e\x61\x6d\x65\x64\x5f\x76\x61\x6c\x31\x20\x3d\x20\x62\
\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\x28\
\x6e\x61\x6d\x65\x64\x2c\x20\x4e\x41\x4d\x45\x44\x5f\x45\x4e\x55\x4d\x5f\x56\
\x41\x4c\x31\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6e\x61\x6d\x65\x64\x5f\x76\x61\
\x6c\x32\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x65\x6e\x75\x6d\x5f\
\x76\x61\x6c\x75\x65\x28\x6e\x61\x6d\x65\x64\x2c\x20\x4e\x41\x4d\x45\x44\x5f\
\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x61\x6e\
\x6f\x6e\x5f\x76\x61\x6c\x31\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\
\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\x28\x61\x6e\x6f\x6e\x2c\x20\x41\x4e\
\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x31\x29\x3b\0\x09\x6f\x75\x74\x2d\
\x3e\x61\x6e\x6f\x6e\x5f\x76\x61\x6c\x32\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\
\x72\x65\x5f\x65\x6e\x75\x6d\x5f\x76\x61\x6c\x75\x65\x28\x61\x6e\x6f\x6e\x2c\
\x20\x41\x4e\x4f\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x32\x29\x3b\0\x09\x72\
\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x31\0\x32\0\x30\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x2e\x62\x73\x73\0\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\
\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\
\0\0\x14\0\0\0\x14\0\0\0\x2c\x01\0\0\x40\x01\0\0\xac\0\0\0\x08\0\0\0\x75\x04\0\
\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\x75\x04\0\0\x12\0\0\0\0\0\0\0\xc6\0\0\
\0\x53\x01\0\0\0\xb4\0\0\x30\0\0\0\xc6\0\0\0\x74\x01\0\0\x1a\xe8\0\0\x58\0\0\0\
\xc6\0\0\0\xc4\x01\0\0\x1a\xe4\0\0\x80\0\0\0\xc6\0\0\0\x14\x02\0\0\x1a\xe0\0\0\
\xa8\0\0\0\xc6\0\0\0\x5f\x02\0\0\x1b\xd8\0\0\xc0\0\0\0\xc6\0\0\0\xb7\x02\0\0\
\x1b\xd4\0\0\xe0\0\0\0\xc6\0\0\0\x0f\x03\0\0\x1b\xd0\0\0\xf0\0\0\0\xc6\0\0\0\
\x0f\x03\0\0\x19\xd0\0\0\x08\x01\0\0\xc6\0\0\0\xb7\x02\0\0\x19\xd4\0\0\x10\x01\
\0\0\xc6\0\0\0\x5f\x02\0\0\x19\xd8\0\0\x18\x01\0\0\xc6\0\0\0\x14\x02\0\0\x18\
\xe0\0\0\x20\x01\0\0\xc6\0\0\0\xc4\x01\0\0\x18\xe4\0\0\x28\x01\0\0\xc6\0\0\0\
\x74\x01\0\0\x18\xe8\0\0\x40\x01\0\0\xc6\0\0\0\x5d\x03\0\0\x12\xf0\0\0\x58\x01\
\0\0\xc6\0\0\0\x9d\x03\0\0\x12\xf4\0\0\x70\x01\0\0\xc6\0\0\0\xdd\x03\0\0\x11\0\
\x01\0\x88\x01\0\0\xc6\0\0\0\x1a\x04\0\0\x11\x04\x01\0\x90\x01\0\0\xc6\0\0\0\
\x57\x04\0\0\x02\x1c\x01\0\x10\0\0\0\x75\x04\0\0\x0a\0\0\0\0\0\0\0\x05\0\0\0\
\x62\x04\0\0\x0a\0\0\0\x10\0\0\0\x05\0\0\0\x64\x04\0\0\x0a\0\0\0\x40\0\0\0\x05\
\0\0\0\x66\x04\0\0\x0a\0\0\0\x68\0\0\0\x07\0\0\0\x64\x04\0\0\x0a\0\0\0\x90\0\0\
\0\x07\0\0\0\x62\x04\0\0\x0a\0\0\0\xd0\0\0\0\x07\0\0\0\x66\x04\0\0\x0a\0\0\0\
\x30\x01\0\0\x07\0\0\0\x66\x04\0\0\x0b\0\0\0\x48\x01\0\0\x07\0\0\0\x62\x04\0\0\
\x0b\0\0\0\x60\x01\0\0\x05\0\0\0\x66\x04\0\0\x0b\0\0\0\x78\x01\0\0\x05\0\0\0\
\x62\x04\0\0\x0b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xc8\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\x20\x01\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x02\0\0\0\0\0\0\xa0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xc8\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xcc\x03\0\0\0\0\0\0\x01\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x9d\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x03\
\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\
\0\0\0\0\xba\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x03\0\0\0\0\0\
\0\x16\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x09\0\0\0\0\0\0\x0c\x02\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_CORE_RELOC_ENUMVAL_SKEL_H__ */
