/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_CORE_RELOC_BITFIELDS_PROBED_SKEL_H__
#define __TEST_CORE_RELOC_BITFIELDS_PROBED_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_core_reloc_bitfields_probed {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test_core_bitfields;
	} progs;
	struct {
		struct bpf_link *test_core_bitfields;
	} links;
	struct test_core_reloc_bitfields_probed__bss {
		struct {
			char in[256];
			char out[256];
		} data;
	} *bss;
};

static void
test_core_reloc_bitfields_probed__destroy(struct test_core_reloc_bitfields_probed *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_core_reloc_bitfields_probed__create_skeleton(struct test_core_reloc_bitfields_probed *obj);

static inline struct test_core_reloc_bitfields_probed *
test_core_reloc_bitfields_probed__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_core_reloc_bitfields_probed *obj;
	int err;

	obj = (struct test_core_reloc_bitfields_probed *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_core_reloc_bitfields_probed__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_core_reloc_bitfields_probed__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_core_reloc_bitfields_probed *
test_core_reloc_bitfields_probed__open(void)
{
	return test_core_reloc_bitfields_probed__open_opts(NULL);
}

static inline int
test_core_reloc_bitfields_probed__load(struct test_core_reloc_bitfields_probed *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_core_reloc_bitfields_probed *
test_core_reloc_bitfields_probed__open_and_load(void)
{
	struct test_core_reloc_bitfields_probed *obj;
	int err;

	obj = test_core_reloc_bitfields_probed__open();
	if (!obj)
		return NULL;
	err = test_core_reloc_bitfields_probed__load(obj);
	if (err) {
		test_core_reloc_bitfields_probed__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_core_reloc_bitfields_probed__attach(struct test_core_reloc_bitfields_probed *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_core_reloc_bitfields_probed__detach(struct test_core_reloc_bitfields_probed *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_core_reloc_bitfields_probed__elf_bytes(size_t *sz);

static inline int
test_core_reloc_bitfields_probed__create_skeleton(struct test_core_reloc_bitfields_probed *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_core_reloc_bitfields_probed";
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

	s->progs[0].name = "test_core_bitfields";
	s->progs[0].prog = &obj->progs.test_core_bitfields;
	s->progs[0].link = &obj->links.test_core_bitfields;

	s->data = (void *)test_core_reloc_bitfields_probed__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_core_reloc_bitfields_probed__elf_bytes(size_t *sz)
{
	*sz = 5304;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x78\x12\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x74\x65\x73\x74\
\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x62\x69\x74\x66\x69\x65\x6c\
\x64\x73\x5f\x70\x72\x6f\x62\x65\x64\x2e\x63\0\x4c\x42\x42\x30\x5f\x32\0\x4c\
\x42\x42\x30\x5f\x33\0\x4c\x42\x42\x30\x5f\x35\0\x4c\x42\x42\x30\x5f\x36\0\x4c\
\x42\x42\x30\x5f\x38\0\x4c\x42\x42\x30\x5f\x39\0\x4c\x42\x42\x30\x5f\x31\x31\0\
\x4c\x42\x42\x30\x5f\x31\x32\0\x4c\x42\x42\x30\x5f\x31\x34\0\x4c\x42\x42\x30\
\x5f\x31\x35\0\x4c\x42\x42\x30\x5f\x31\x37\0\x4c\x42\x42\x30\x5f\x31\x38\0\x4c\
\x42\x42\x30\x5f\x32\x30\0\x4c\x42\x42\x30\x5f\x32\x31\0\x74\x65\x73\x74\x5f\
\x63\x6f\x72\x65\x5f\x62\x69\x74\x66\x69\x65\x6c\x64\x73\0\x64\x61\x74\x61\0\
\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x72\x61\x77\x5f\x74\x72\x61\
\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\x42\
\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5a\0\0\0\0\0\x03\0\
\x80\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\0\0\0\0\0\x03\0\x88\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x68\0\0\0\0\0\x03\0\x10\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6f\0\0\0\0\
\0\x03\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x76\0\0\0\0\0\x03\0\xa0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x7d\0\0\0\0\0\x03\0\xa8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x84\0\0\0\0\0\x03\0\x30\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8c\0\0\0\0\0\x03\0\
\x38\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x94\0\0\0\0\0\x03\0\xc0\x02\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x9c\0\0\0\0\0\x03\0\xc8\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa4\0\0\
\0\0\0\x03\0\x50\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xac\0\0\0\0\0\x03\0\x58\x03\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xb4\0\0\0\0\0\x03\0\xe0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xbc\0\0\0\0\0\x03\0\xe8\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc4\0\0\0\x12\0\
\x03\0\0\0\0\0\0\0\0\0\x10\x04\0\0\0\0\0\0\xd8\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\
\0\0\x02\0\0\0\0\0\0\xdd\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x18\x03\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x3f\0\0\0\xb7\x02\0\0\0\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x3f\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x3f\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\0\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x3d\0\0\0\xb7\x02\0\0\0\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x3e\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x3e\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\x08\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x36\0\0\0\xb7\x02\0\0\0\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x39\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x39\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\x10\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x32\0\0\0\xb7\x02\0\0\x01\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x3c\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x3c\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\x18\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\x04\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x2c\0\0\0\xb7\x02\0\0\x01\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x2c\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x2c\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\x20\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\x08\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x20\0\0\0\xb7\x02\0\0\0\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x20\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x20\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x13\x28\x01\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\
\xb7\x01\0\0\x0c\0\0\0\x0f\x13\0\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xf8\
\xff\xff\xff\xb7\x02\0\0\x04\0\0\0\x85\0\0\0\x71\0\0\0\x79\xa1\xf8\xff\0\0\0\0\
\x67\x01\0\0\x20\0\0\0\xb7\x02\0\0\x01\0\0\0\x15\x02\x02\0\0\0\0\0\xc7\x01\0\0\
\x20\0\0\0\x05\0\x01\0\0\0\0\0\x77\x01\0\0\x20\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x7b\x12\x30\x01\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\
\x4c\0\0\0\0\0\x18\0\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\x88\0\0\0\0\0\0\0\x01\0\0\
\0\x12\0\0\0\x18\x01\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\xa8\x01\0\0\0\0\0\0\x01\0\
\0\0\x12\0\0\0\x38\x02\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\xc8\x02\0\0\0\0\0\0\x01\
\0\0\0\x12\0\0\0\x58\x03\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\xe8\x03\0\0\0\0\0\0\
\x01\0\0\0\x12\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xf0\x01\0\0\xf0\x01\0\0\
\x60\x03\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\
\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\
\0\0\0\x1d\0\0\0\x07\0\0\x84\x10\0\0\0\x32\0\0\0\x06\0\0\0\0\0\0\x01\x36\0\0\0\
\x06\0\0\0\x01\0\0\x02\x3a\0\0\0\x09\0\0\0\x03\0\0\x07\x3e\0\0\0\x0c\0\0\0\x0a\
\0\0\x04\x42\0\0\0\x0f\0\0\0\x20\0\0\x14\x47\0\0\0\x09\0\0\0\x40\0\0\0\x4b\0\0\
\0\x0f\0\0\0\x60\0\0\0\x4f\0\0\0\0\0\0\x08\x07\0\0\0\x57\0\0\0\0\0\0\x08\x08\0\
\0\0\x61\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\x6f\0\0\0\0\0\0\x08\x0a\0\0\0\x78\
\0\0\0\0\0\0\x08\x0b\0\0\0\x83\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x90\0\0\0\0\
\0\0\x08\x0d\0\0\0\x97\0\0\0\0\0\0\x08\x0e\0\0\0\xa0\0\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\xac\0\0\0\0\0\0\x08\x10\0\0\0\xb4\0\0\0\0\0\0\x08\x03\0\0\0\xbe\0\
\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x11\0\0\0\x13\0\
\0\0\x04\0\0\0\xc3\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\xd7\0\0\0\0\0\0\x0e\x12\
\0\0\0\x01\0\0\0\0\0\0\0\x02\0\0\x04\0\x02\0\0\xe0\0\0\0\x16\0\0\0\0\0\0\0\xe3\
\0\0\0\x16\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x11\0\0\0\x13\0\0\0\0\x01\
\0\0\xe7\0\0\0\0\0\0\x0e\x15\0\0\0\x01\0\0\0\x3a\x03\0\0\x01\0\0\x0f\x04\0\0\0\
\x14\0\0\0\0\0\0\0\x04\0\0\0\x42\x03\0\0\x01\0\0\x0f\0\x02\0\0\x17\0\0\0\0\0\0\
\0\0\x02\0\0\0\x63\x74\x78\0\x69\x6e\x74\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\
\x5f\x62\x69\x74\x66\x69\x65\x6c\x64\x73\0\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\
\x63\x5f\x62\x69\x74\x66\x69\x65\x6c\x64\x73\0\x75\x62\x31\0\x75\x62\x32\0\x75\
\x62\x37\0\x73\x62\x34\0\x73\x62\x32\x30\0\x75\x33\x32\0\x73\x33\x32\0\x75\x69\
\x6e\x74\x38\x5f\x74\0\x5f\x5f\x75\x69\x6e\x74\x38\x5f\x74\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x75\x69\x6e\x74\x33\x32\x5f\x74\0\x5f\
\x5f\x75\x69\x6e\x74\x33\x32\x5f\x74\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\
\x6e\x74\0\x69\x6e\x74\x38\x5f\x74\0\x5f\x5f\x69\x6e\x74\x38\x5f\x74\0\x73\x69\
\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x69\x6e\x74\x33\x32\x5f\x74\0\x5f\x5f\
\x69\x6e\x74\x33\x32\x5f\x74\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\
\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\
\x65\0\x69\x6e\0\x6f\x75\x74\0\x64\x61\x74\x61\0\x2f\x72\x6f\x6f\x74\x2f\x72\
\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\
\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\
\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\
\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\
\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\
\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x63\
\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x62\x69\x74\x66\x69\x65\x6c\x64\x73\
\x5f\x70\x72\x6f\x62\x65\x64\x2e\x63\0\x69\x6e\x74\x20\x74\x65\x73\x74\x5f\x63\
\x6f\x72\x65\x5f\x62\x69\x74\x66\x69\x65\x6c\x64\x73\x28\x76\x6f\x69\x64\x20\
\x2a\x63\x74\x78\x29\0\x09\x6f\x75\x74\x2d\x3e\x75\x62\x31\x20\x3d\x20\x42\x50\
\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x5f\x42\x49\x54\x46\x49\x45\x4c\
\x44\x5f\x50\x52\x4f\x42\x45\x44\x28\x69\x6e\x2c\x20\x75\x62\x31\x29\x3b\0\x09\
\x6f\x75\x74\x2d\x3e\x75\x62\x32\x20\x3d\x20\x42\x50\x46\x5f\x43\x4f\x52\x45\
\x5f\x52\x45\x41\x44\x5f\x42\x49\x54\x46\x49\x45\x4c\x44\x5f\x50\x52\x4f\x42\
\x45\x44\x28\x69\x6e\x2c\x20\x75\x62\x32\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x75\
\x62\x37\x20\x3d\x20\x42\x50\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x5f\
\x42\x49\x54\x46\x49\x45\x4c\x44\x5f\x50\x52\x4f\x42\x45\x44\x28\x69\x6e\x2c\
\x20\x75\x62\x37\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x73\x62\x34\x20\x3d\x20\x42\
\x50\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x5f\x42\x49\x54\x46\x49\x45\
\x4c\x44\x5f\x50\x52\x4f\x42\x45\x44\x28\x69\x6e\x2c\x20\x73\x62\x34\x29\x3b\0\
\x09\x6f\x75\x74\x2d\x3e\x73\x62\x32\x30\x20\x3d\x20\x42\x50\x46\x5f\x43\x4f\
\x52\x45\x5f\x52\x45\x41\x44\x5f\x42\x49\x54\x46\x49\x45\x4c\x44\x5f\x50\x52\
\x4f\x42\x45\x44\x28\x69\x6e\x2c\x20\x73\x62\x32\x30\x29\x3b\0\x09\x6f\x75\x74\
\x2d\x3e\x75\x33\x32\x20\x3d\x20\x42\x50\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\
\x41\x44\x5f\x42\x49\x54\x46\x49\x45\x4c\x44\x5f\x50\x52\x4f\x42\x45\x44\x28\
\x69\x6e\x2c\x20\x75\x33\x32\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x73\x33\x32\x20\
\x3d\x20\x42\x50\x46\x5f\x43\x4f\x52\x45\x5f\x52\x45\x41\x44\x5f\x42\x49\x54\
\x46\x49\x45\x4c\x44\x5f\x50\x52\x4f\x42\x45\x44\x28\x69\x6e\x2c\x20\x73\x33\
\x32\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x30\x3a\x30\0\x30\x3a\
\x31\0\x30\x3a\x32\0\x30\x3a\x33\0\x30\x3a\x34\0\x30\x3a\x35\0\x30\x3a\x36\0\
\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x72\x61\x77\x5f\x74\x72\x61\
\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x9f\xeb\
\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x5c\x02\0\0\x70\x02\0\0\xac\x02\0\
\0\x08\0\0\0\x47\x03\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\x47\x03\0\0\x25\
\0\0\0\0\0\0\0\xec\0\0\0\x82\x01\0\0\0\xa4\0\0\x08\0\0\0\xec\0\0\0\xa5\x01\0\0\
\x0d\xbc\0\0\x38\0\0\0\xec\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\xec\0\0\0\xa5\x01\0\
\0\x0d\xbc\0\0\x70\0\0\0\xec\0\0\0\xa5\x01\0\0\x0d\xbc\0\0\x88\0\0\0\xec\0\0\0\
\xa5\x01\0\0\x0b\xbc\0\0\xa8\0\0\0\xec\0\0\0\xd9\x01\0\0\x0d\xc0\0\0\xc8\0\0\0\
\xec\0\0\0\0\0\0\0\0\0\0\0\xd0\0\0\0\xec\0\0\0\xd9\x01\0\0\x0d\xc0\0\0\0\x01\0\
\0\xec\0\0\0\xd9\x01\0\0\x0d\xc0\0\0\x18\x01\0\0\xec\0\0\0\xd9\x01\0\0\x0b\xc0\
\0\0\x38\x01\0\0\xec\0\0\0\x0d\x02\0\0\x0d\xc4\0\0\x58\x01\0\0\xec\0\0\0\0\0\0\
\0\0\0\0\0\x60\x01\0\0\xec\0\0\0\x0d\x02\0\0\x0d\xc4\0\0\x90\x01\0\0\xec\0\0\0\
\x0d\x02\0\0\x0d\xc4\0\0\xa8\x01\0\0\xec\0\0\0\x0d\x02\0\0\x0b\xc4\0\0\xc8\x01\
\0\0\xec\0\0\0\x41\x02\0\0\x0d\xc8\0\0\xe8\x01\0\0\xec\0\0\0\0\0\0\0\0\0\0\0\
\xf0\x01\0\0\xec\0\0\0\x41\x02\0\0\x0d\xc8\0\0\x20\x02\0\0\xec\0\0\0\x41\x02\0\
\0\x0d\xc8\0\0\x38\x02\0\0\xec\0\0\0\x41\x02\0\0\x0b\xc8\0\0\x58\x02\0\0\xec\0\
\0\0\x75\x02\0\0\x0e\xcc\0\0\x78\x02\0\0\xec\0\0\0\0\0\0\0\0\0\0\0\x80\x02\0\0\
\xec\0\0\0\x75\x02\0\0\x0e\xcc\0\0\xb0\x02\0\0\xec\0\0\0\x75\x02\0\0\x0e\xcc\0\
\0\xc8\x02\0\0\xec\0\0\0\x75\x02\0\0\x0c\xcc\0\0\xe8\x02\0\0\xec\0\0\0\xab\x02\
\0\0\x0d\xd0\0\0\x08\x03\0\0\xec\0\0\0\0\0\0\0\0\0\0\0\x10\x03\0\0\xec\0\0\0\
\xab\x02\0\0\x0d\xd0\0\0\x40\x03\0\0\xec\0\0\0\xab\x02\0\0\x0d\xd0\0\0\x58\x03\
\0\0\xec\0\0\0\xab\x02\0\0\x0b\xd0\0\0\x78\x03\0\0\xec\0\0\0\xdf\x02\0\0\x0d\
\xd4\0\0\x98\x03\0\0\xec\0\0\0\0\0\0\0\0\0\0\0\xa0\x03\0\0\xec\0\0\0\xdf\x02\0\
\0\x0d\xd4\0\0\xd0\x03\0\0\xec\0\0\0\xdf\x02\0\0\x0d\xd4\0\0\xe8\x03\0\0\xec\0\
\0\0\xdf\x02\0\0\x0b\xd4\0\0\0\x04\0\0\xec\0\0\0\x13\x03\0\0\x02\xdc\0\0\x10\0\
\0\0\x47\x03\0\0\x2a\0\0\0\x10\0\0\0\x05\0\0\0\x1e\x03\0\0\0\0\0\0\x40\0\0\0\
\x05\0\0\0\x1e\x03\0\0\x01\0\0\0\x58\0\0\0\x05\0\0\0\x1e\x03\0\0\x04\0\0\0\x60\
\0\0\0\x05\0\0\0\x1e\x03\0\0\x03\0\0\0\x70\0\0\0\x05\0\0\0\x1e\x03\0\0\x05\0\0\
\0\x80\0\0\0\x05\0\0\0\x1e\x03\0\0\x05\0\0\0\xb0\0\0\0\x05\0\0\0\x22\x03\0\0\0\
\0\0\0\xd0\0\0\0\x05\0\0\0\x22\x03\0\0\x01\0\0\0\xe8\0\0\0\x05\0\0\0\x22\x03\0\
\0\x04\0\0\0\xf0\0\0\0\x05\0\0\0\x22\x03\0\0\x03\0\0\0\0\x01\0\0\x05\0\0\0\x22\
\x03\0\0\x05\0\0\0\x10\x01\0\0\x05\0\0\0\x22\x03\0\0\x05\0\0\0\x40\x01\0\0\x05\
\0\0\0\x26\x03\0\0\0\0\0\0\x60\x01\0\0\x05\0\0\0\x26\x03\0\0\x01\0\0\0\x78\x01\
\0\0\x05\0\0\0\x26\x03\0\0\x04\0\0\0\x80\x01\0\0\x05\0\0\0\x26\x03\0\0\x03\0\0\
\0\x90\x01\0\0\x05\0\0\0\x26\x03\0\0\x05\0\0\0\xa0\x01\0\0\x05\0\0\0\x26\x03\0\
\0\x05\0\0\0\xd0\x01\0\0\x05\0\0\0\x2a\x03\0\0\0\0\0\0\xf0\x01\0\0\x05\0\0\0\
\x2a\x03\0\0\x01\0\0\0\x08\x02\0\0\x05\0\0\0\x2a\x03\0\0\x04\0\0\0\x10\x02\0\0\
\x05\0\0\0\x2a\x03\0\0\x03\0\0\0\x20\x02\0\0\x05\0\0\0\x2a\x03\0\0\x05\0\0\0\
\x30\x02\0\0\x05\0\0\0\x2a\x03\0\0\x05\0\0\0\x60\x02\0\0\x05\0\0\0\x2e\x03\0\0\
\0\0\0\0\x80\x02\0\0\x05\0\0\0\x2e\x03\0\0\x01\0\0\0\x98\x02\0\0\x05\0\0\0\x2e\
\x03\0\0\x04\0\0\0\xa0\x02\0\0\x05\0\0\0\x2e\x03\0\0\x03\0\0\0\xb0\x02\0\0\x05\
\0\0\0\x2e\x03\0\0\x05\0\0\0\xc0\x02\0\0\x05\0\0\0\x2e\x03\0\0\x05\0\0\0\xf0\
\x02\0\0\x05\0\0\0\x32\x03\0\0\0\0\0\0\x10\x03\0\0\x05\0\0\0\x32\x03\0\0\x01\0\
\0\0\x28\x03\0\0\x05\0\0\0\x32\x03\0\0\x04\0\0\0\x30\x03\0\0\x05\0\0\0\x32\x03\
\0\0\x03\0\0\0\x40\x03\0\0\x05\0\0\0\x32\x03\0\0\x05\0\0\0\x50\x03\0\0\x05\0\0\
\0\x32\x03\0\0\x05\0\0\0\x80\x03\0\0\x05\0\0\0\x36\x03\0\0\0\0\0\0\xa0\x03\0\0\
\x05\0\0\0\x36\x03\0\0\x01\0\0\0\xb8\x03\0\0\x05\0\0\0\x36\x03\0\0\x04\0\0\0\
\xc0\x03\0\0\x05\0\0\0\x36\x03\0\0\x03\0\0\0\xd0\x03\0\0\x05\0\0\0\x36\x03\0\0\
\x05\0\0\0\xe0\x03\0\0\x05\0\0\0\x36\x03\0\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x40\0\0\0\0\0\0\0\x11\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\
\x01\0\0\0\0\0\0\xe0\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\
\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x03\0\0\
\0\0\0\0\x10\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x07\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x08\
\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4c\x07\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe6\0\0\0\x09\0\0\0\x40\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x07\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\x02\0\0\0\x03\
\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x03\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xd0\x07\0\0\0\0\0\0\x68\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x38\x0d\0\0\0\0\0\0\x3c\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_CORE_RELOC_BITFIELDS_PROBED_SKEL_H__ */
