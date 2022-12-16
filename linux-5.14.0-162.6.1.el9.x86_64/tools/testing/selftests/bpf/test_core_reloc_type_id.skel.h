/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_CORE_RELOC_TYPE_ID_SKEL_H__
#define __TEST_CORE_RELOC_TYPE_ID_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_core_reloc_type_id {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test_core_type_id;
	} progs;
	struct {
		struct bpf_link *test_core_type_id;
	} links;
	struct test_core_reloc_type_id__bss {
		struct {
			char in[256];
			char out[256];
			_Bool skip;
		} data;
		struct a_struct t1;
		union a_union t2;
		enum an_enum t3;
		named_struct_typedef t4;
		char __pad0[4];
		func_proto_typedef t5;
		arr_typedef t6;
	} *bss;
};

static void
test_core_reloc_type_id__destroy(struct test_core_reloc_type_id *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_core_reloc_type_id__create_skeleton(struct test_core_reloc_type_id *obj);

static inline struct test_core_reloc_type_id *
test_core_reloc_type_id__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_core_reloc_type_id *obj;
	int err;

	obj = (struct test_core_reloc_type_id *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_core_reloc_type_id__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_core_reloc_type_id__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_core_reloc_type_id *
test_core_reloc_type_id__open(void)
{
	return test_core_reloc_type_id__open_opts(NULL);
}

static inline int
test_core_reloc_type_id__load(struct test_core_reloc_type_id *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_core_reloc_type_id *
test_core_reloc_type_id__open_and_load(void)
{
	struct test_core_reloc_type_id *obj;
	int err;

	obj = test_core_reloc_type_id__open();
	if (!obj)
		return NULL;
	err = test_core_reloc_type_id__load(obj);
	if (err) {
		test_core_reloc_type_id__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_core_reloc_type_id__attach(struct test_core_reloc_type_id *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_core_reloc_type_id__detach(struct test_core_reloc_type_id *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_core_reloc_type_id__elf_bytes(size_t *sz);

static inline int
test_core_reloc_type_id__create_skeleton(struct test_core_reloc_type_id *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_core_reloc_type_id";
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

	s->progs[0].name = "test_core_type_id";
	s->progs[0].prog = &obj->progs.test_core_type_id;
	s->progs[0].link = &obj->links.test_core_type_id;

	s->data = (void *)test_core_reloc_type_id__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_core_reloc_type_id__elf_bytes(size_t *sz)
{
	*sz = 4992;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x40\x11\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x74\x65\x73\x74\
\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x74\x79\x70\x65\x5f\x69\x64\
\x2e\x63\0\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\
\0\x64\x61\x74\x61\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x31\0\x74\x32\0\x74\
\x33\0\x74\x34\0\x74\x35\0\x74\x36\0\x2e\x72\x65\x6c\x72\x61\x77\x5f\x74\x72\
\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\
\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x51\0\0\0\x12\0\x03\0\0\0\
\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\x63\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x01\x02\0\
\0\0\0\0\0\x68\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x71\0\0\0\
\x11\0\x05\0\x04\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x74\0\0\0\x11\0\x05\0\x08\
\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x77\0\0\0\x11\0\x05\0\x0c\x02\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\x7a\0\0\0\x11\0\x05\0\x10\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x7d\0\0\0\x11\0\x05\0\x18\x02\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x80\0\0\0\x11\0\
\x05\0\x20\x02\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\x18\x02\0\0\x05\0\0\0\0\0\0\0\0\0\
\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x21\0\x01\0\0\0\0\x18\x02\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x04\x01\0\0\0\0\x18\x02\0\0\x07\0\0\0\0\0\0\0\0\
\0\0\0\x63\x21\x08\x01\0\0\0\0\x18\x02\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\x63\x21\
\x0c\x01\0\0\0\0\x18\x02\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x10\x01\0\0\0\0\
\x18\x02\0\0\x0b\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x14\x01\0\0\0\0\x18\x02\0\0\x0d\
\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x18\x01\0\0\0\0\x18\x02\0\0\x0e\0\0\0\0\0\0\0\0\
\0\0\0\x63\x21\x1c\x01\0\0\0\0\x18\x02\0\0\x0f\0\0\0\0\0\0\0\0\0\0\0\x63\x21\
\x20\x01\0\0\0\0\x18\x02\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x24\x01\0\0\0\0\
\x18\x02\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x28\x01\0\0\0\0\x18\x02\0\0\x11\
\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x2c\x01\0\0\0\0\x18\x02\0\0\x15\0\0\0\0\0\0\0\0\
\0\0\0\x63\x21\x30\x01\0\0\0\0\x18\x02\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\x63\x21\
\x34\x01\0\0\0\0\x18\x02\0\0\x0e\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x38\x01\0\0\0\0\
\x18\x02\0\0\x0f\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x3c\x01\0\0\0\0\x18\x02\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x40\x01\0\0\0\0\x18\x02\0\0\x10\0\0\0\0\0\0\0\0\
\0\0\0\x63\x21\x44\x01\0\0\0\0\x18\x02\0\0\x11\0\0\0\0\0\0\0\0\0\0\0\x63\x21\
\x48\x01\0\0\0\0\x18\x02\0\0\x15\0\0\0\0\0\0\0\0\0\0\0\x63\x21\x4c\x01\0\0\0\0\
\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\x01\0\0\0\x04\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x0c\x03\0\0\x0c\x03\0\0\0\
\x07\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\
\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\
\0\0\0\0\0\x01\0\0\x04\x04\0\0\0\x1b\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\x05\x04\0\0\0\x1b\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\x06\x04\0\0\0\x28\0\
\0\0\x7b\0\0\0\0\0\0\0\0\0\0\x02\x09\0\0\0\0\0\0\0\x01\0\0\x0d\x0a\0\0\0\0\0\0\
\0\x03\0\0\0\x38\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x04\0\0\0\0\0\0\0\x03\0\0\0\
\0\x0a\0\0\0\x0c\0\0\0\x2f\0\0\0\x3e\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x52\0\
\0\0\x01\0\0\x04\x04\0\0\0\x5b\0\0\0\x03\0\0\0\0\0\0\0\x5d\0\0\0\x02\0\0\x05\
\x04\0\0\0\x65\0\0\0\x03\0\0\0\0\0\0\0\x67\0\0\0\x03\0\0\0\0\0\0\0\x69\0\0\0\
\x03\0\0\x06\x04\0\0\0\x71\0\0\0\x01\0\0\0\x7e\0\0\0\x02\0\0\0\x8b\0\0\0\x03\0\
\0\0\x98\0\0\0\0\0\0\x08\x0d\0\0\0\xad\0\0\0\0\0\0\x08\x12\0\0\0\0\0\0\0\0\0\0\
\x02\x13\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\0\0\0\0\x14\0\0\0\xc0\0\0\0\0\0\0\
\x01\x08\0\0\0\x40\0\0\x01\xc5\0\0\0\0\0\0\x08\x17\0\0\0\xd1\0\0\0\0\0\0\x01\
\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x16\0\0\0\x0c\0\0\0\x14\0\0\0\
\0\0\0\0\0\0\0\x03\0\0\0\0\x16\0\0\0\x0c\0\0\0\x04\0\0\0\xd6\0\0\0\0\0\0\x0e\
\x18\0\0\0\x01\0\0\0\0\0\0\0\x03\0\0\x04\x01\x02\0\0\xdf\0\0\0\x1b\0\0\0\0\0\0\
\0\xe2\0\0\0\x1b\0\0\0\0\x08\0\0\xe6\0\0\0\x0a\0\0\0\0\x10\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x16\0\0\0\x0c\0\0\0\0\x01\0\0\xeb\0\0\0\0\0\0\x0e\x1a\0\0\0\x01\0\
\0\0\xf0\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\xf3\0\0\0\0\0\0\x0e\x0e\0\0\0\x01\
\0\0\0\xf6\0\0\0\0\0\0\x0e\x0f\0\0\0\x01\0\0\0\xf9\0\0\0\0\0\0\x0e\x10\0\0\0\
\x01\0\0\0\xfc\0\0\0\0\0\0\x0e\x11\0\0\0\x01\0\0\0\xff\0\0\0\0\0\0\x0e\x15\0\0\
\0\x01\0\0\0\xda\x06\0\0\x01\0\0\x0f\x04\0\0\0\x19\0\0\0\0\0\0\0\x04\0\0\0\xe2\
\x06\0\0\x07\0\0\x0f\x34\x02\0\0\x1c\0\0\0\0\0\0\0\x01\x02\0\0\x1d\0\0\0\x04\
\x02\0\0\x04\0\0\0\x1e\0\0\0\x08\x02\0\0\x04\0\0\0\x1f\0\0\0\x0c\x02\0\0\x04\0\
\0\0\x20\0\0\0\x10\x02\0\0\x04\0\0\0\x21\0\0\0\x18\x02\0\0\x08\0\0\0\x22\0\0\0\
\x20\x02\0\0\x14\0\0\0\0\x63\x74\x78\0\x69\x6e\x74\0\x74\x65\x73\x74\x5f\x63\
\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\0\x6d\x61\x72\x6b\x65\x72\x5f\x66\
\x69\x65\x6c\x64\0\x4d\x41\x52\x4b\x45\x52\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\
\0\x5f\x42\x6f\x6f\x6c\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\
\x54\x59\x50\x45\x5f\x5f\0\x61\x5f\x73\x74\x72\x75\x63\x74\0\x78\0\x61\x5f\x75\
\x6e\x69\x6f\x6e\0\x79\0\x7a\0\x61\x6e\x5f\x65\x6e\x75\x6d\0\x41\x4e\x5f\x45\
\x4e\x55\x4d\x5f\x56\x41\x4c\x31\0\x41\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\
\x32\0\x41\x4e\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x33\0\x6e\x61\x6d\x65\x64\
\x5f\x73\x74\x72\x75\x63\x74\x5f\x74\x79\x70\x65\x64\x65\x66\0\x66\x75\x6e\x63\
\x5f\x70\x72\x6f\x74\x6f\x5f\x74\x79\x70\x65\x64\x65\x66\0\x6c\x6f\x6e\x67\0\
\x61\x72\x72\x5f\x74\x79\x70\x65\x64\x65\x66\0\x63\x68\x61\x72\0\x5f\x6c\x69\
\x63\x65\x6e\x73\x65\0\x69\x6e\0\x6f\x75\x74\0\x73\x6b\x69\x70\0\x64\x61\x74\
\x61\0\x74\x31\0\x74\x32\0\x74\x33\0\x74\x34\0\x74\x35\0\x74\x36\0\x2f\x72\x6f\
\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\
\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\
\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\
\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\
\x73\x74\x5f\x63\x6f\x72\x65\x5f\x72\x65\x6c\x6f\x63\x5f\x74\x79\x70\x65\x5f\
\x69\x64\x2e\x63\0\x69\x6e\x74\x20\x74\x65\x73\x74\x5f\x63\x6f\x72\x65\x5f\x74\
\x79\x70\x65\x5f\x69\x64\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x6f\
\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\x6f\x6e\x5f\x73\x74\x72\x75\
\x63\x74\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\
\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x73\x74\x72\x75\x63\x74\x20\x7b\x20\x69\
\x6e\x74\x20\x6d\x61\x72\x6b\x65\x72\x5f\x66\x69\x65\x6c\x64\x3b\x20\x7d\x29\
\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\x6f\x6e\x5f\x75\
\x6e\x69\x6f\x6e\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\
\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x75\x6e\x69\x6f\x6e\x20\x7b\x20\
\x69\x6e\x74\x20\x6d\x61\x72\x6b\x65\x72\x5f\x66\x69\x65\x6c\x64\x3b\x20\x7d\
\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\x6f\x6e\x5f\
\x65\x6e\x75\x6d\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\
\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x65\x6e\x75\x6d\x20\x7b\x20\x4d\
\x41\x52\x4b\x45\x52\x5f\x45\x4e\x55\x4d\x5f\x56\x41\x4c\x20\x3d\x20\x31\x32\
\x33\x20\x7d\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\
\x6f\x6e\x5f\x66\x75\x6e\x63\x5f\x70\x72\x6f\x74\x6f\x5f\x70\x74\x72\x20\x3d\
\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6c\
\x6f\x63\x61\x6c\x28\x5f\x42\x6f\x6f\x6c\x28\x2a\x29\x28\x69\x6e\x74\x29\x29\
\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\x6f\x6e\x5f\x76\
\x6f\x69\x64\x5f\x70\x74\x72\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\
\x74\x79\x70\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x76\x6f\x69\x64\x20\
\x2a\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x61\x6e\x6f\x6e\
\x5f\x61\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\
\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x5f\x42\x6f\x6f\x6c\x5b\x34\x37\
\x5d\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x72\x75\
\x63\x74\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\
\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x73\x74\x72\x75\x63\x74\x20\x61\x5f\x73\
\x74\x72\x75\x63\x74\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\
\x75\x6e\x69\x6f\x6e\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\
\x70\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x75\x6e\x69\x6f\x6e\x20\x61\
\x5f\x75\x6e\x69\x6f\x6e\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\
\x5f\x65\x6e\x75\x6d\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\
\x70\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x65\x6e\x75\x6d\x20\x61\x6e\
\x5f\x65\x6e\x75\x6d\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\
\x69\x6e\x74\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\
\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x69\x6e\x74\x29\x3b\0\x09\x6f\x75\x74\
\x2d\x3e\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x72\x75\x63\x74\x5f\x74\x79\x70\x65\
\x64\x65\x66\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\
\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x6e\x61\x6d\x65\x64\x5f\x73\x74\x72\
\x75\x63\x74\x5f\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\
\x6c\x6f\x63\x61\x6c\x5f\x66\x75\x6e\x63\x5f\x70\x72\x6f\x74\x6f\x5f\x74\x79\
\x70\x65\x64\x65\x66\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\
\x70\x65\x5f\x69\x64\x5f\x6c\x6f\x63\x61\x6c\x28\x66\x75\x6e\x63\x5f\x70\x72\
\x6f\x74\x6f\x5f\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\
\x6c\x6f\x63\x61\x6c\x5f\x61\x72\x72\x5f\x74\x79\x70\x65\x64\x65\x66\x20\x3d\
\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6c\
\x6f\x63\x61\x6c\x28\x61\x72\x72\x5f\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\
\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\x5f\x73\x74\x72\x75\x63\x74\x20\x3d\x20\
\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6b\x65\
\x72\x6e\x65\x6c\x28\x73\x74\x72\x75\x63\x74\x20\x61\x5f\x73\x74\x72\x75\x63\
\x74\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\x5f\x75\x6e\x69\x6f\x6e\
\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\
\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x75\x6e\x69\x6f\x6e\x20\x61\x5f\x75\x6e\x69\
\x6f\x6e\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\x5f\x65\x6e\x75\x6d\
\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\
\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x65\x6e\x75\x6d\x20\x61\x6e\x5f\x65\x6e\x75\
\x6d\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\x5f\x69\x6e\x74\x20\x3d\
\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6b\
\x65\x72\x6e\x65\x6c\x28\x69\x6e\x74\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\
\x72\x67\x5f\x73\x74\x72\x75\x63\x74\x5f\x74\x79\x70\x65\x64\x65\x66\x20\x3d\
\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6b\
\x65\x72\x6e\x65\x6c\x28\x6e\x61\x6d\x65\x64\x5f\x73\x74\x72\x75\x63\x74\x5f\
\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\
\x5f\x66\x75\x6e\x63\x5f\x70\x72\x6f\x74\x6f\x5f\x74\x79\x70\x65\x64\x65\x66\
\x20\x3d\x20\x62\x70\x66\x5f\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\
\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x66\x75\x6e\x63\x5f\x70\x72\x6f\x74\x6f\x5f\
\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\x6f\x75\x74\x2d\x3e\x74\x61\x72\x67\
\x5f\x61\x72\x72\x5f\x74\x79\x70\x65\x64\x65\x66\x20\x3d\x20\x62\x70\x66\x5f\
\x63\x6f\x72\x65\x5f\x74\x79\x70\x65\x5f\x69\x64\x5f\x6b\x65\x72\x6e\x65\x6c\
\x28\x61\x72\x72\x5f\x74\x79\x70\x65\x64\x65\x66\x29\x3b\0\x09\x72\x65\x74\x75\
\x72\x6e\x20\x30\x3b\0\x30\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\
\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\
\0\0\x6c\x01\0\0\x80\x01\0\0\x4c\x01\0\0\x08\0\0\0\xe7\x06\0\0\x01\0\0\0\0\0\0\
\0\x04\0\0\0\x10\0\0\0\xe7\x06\0\0\x16\0\0\0\0\0\0\0\x02\x01\0\0\x8f\x01\0\0\0\
\x28\x01\0\x10\0\0\0\x02\x01\0\0\xb0\x01\0\0\x19\x60\x01\0\x38\0\0\0\x02\x01\0\
\0\0\x02\0\0\x18\x64\x01\0\x50\0\0\0\x02\x01\0\0\x4e\x02\0\0\x17\x68\x01\0\x68\
\0\0\0\x02\x01\0\0\x9e\x02\0\0\x21\x6c\x01\0\x80\0\0\0\x02\x01\0\0\xe7\x02\0\0\
\x1b\x70\x01\0\x98\0\0\0\x02\x01\0\0\x23\x03\0\0\x16\x74\x01\0\xb0\0\0\0\x02\
\x01\0\0\x5d\x03\0\0\x14\x7c\x01\0\xc8\0\0\0\x02\x01\0\0\x9b\x03\0\0\x13\x80\
\x01\0\xe0\0\0\0\x02\x01\0\0\xd6\x03\0\0\x12\x84\x01\0\xf8\0\0\0\x02\x01\0\0\
\x0f\x04\0\0\x11\x88\x01\0\x10\x01\0\0\x02\x01\0\0\x3e\x04\0\0\x1c\x8c\x01\0\
\x28\x01\0\0\x02\x01\0\0\x89\x04\0\0\x20\x90\x01\0\x40\x01\0\0\x02\x01\0\0\xd6\
\x04\0\0\x19\x94\x01\0\x58\x01\0\0\x02\x01\0\0\x15\x05\0\0\x13\x9c\x01\0\x70\
\x01\0\0\x02\x01\0\0\x53\x05\0\0\x12\xa0\x01\0\x88\x01\0\0\x02\x01\0\0\x8e\x05\
\0\0\x11\xa4\x01\0\xa0\x01\0\0\x02\x01\0\0\xc7\x05\0\0\x10\xa8\x01\0\xb8\x01\0\
\0\x02\x01\0\0\xf6\x05\0\0\x1b\xac\x01\0\xd0\x01\0\0\x02\x01\0\0\x41\x06\0\0\
\x1f\xb0\x01\0\xe8\x01\0\0\x02\x01\0\0\x8e\x06\0\0\x18\xb4\x01\0\xf0\x01\0\0\
\x02\x01\0\0\xcd\x06\0\0\x02\xc8\x01\0\x10\0\0\0\xe7\x06\0\0\x14\0\0\0\0\0\0\0\
\x05\0\0\0\xd8\x06\0\0\x06\0\0\0\x28\0\0\0\x06\0\0\0\xd8\x06\0\0\x06\0\0\0\x40\
\0\0\0\x07\0\0\0\xd8\x06\0\0\x06\0\0\0\x58\0\0\0\x08\0\0\0\xd8\x06\0\0\x06\0\0\
\0\x70\0\0\0\x01\0\0\0\xd8\x06\0\0\x06\0\0\0\x88\0\0\0\x0b\0\0\0\xd8\x06\0\0\
\x06\0\0\0\xa0\0\0\0\x0d\0\0\0\xd8\x06\0\0\x06\0\0\0\xb8\0\0\0\x0e\0\0\0\xd8\
\x06\0\0\x06\0\0\0\xd0\0\0\0\x0f\0\0\0\xd8\x06\0\0\x06\0\0\0\xe8\0\0\0\x03\0\0\
\0\xd8\x06\0\0\x06\0\0\0\0\x01\0\0\x10\0\0\0\xd8\x06\0\0\x06\0\0\0\x18\x01\0\0\
\x11\0\0\0\xd8\x06\0\0\x06\0\0\0\x30\x01\0\0\x15\0\0\0\xd8\x06\0\0\x06\0\0\0\
\x48\x01\0\0\x0d\0\0\0\xd8\x06\0\0\x07\0\0\0\x60\x01\0\0\x0e\0\0\0\xd8\x06\0\0\
\x07\0\0\0\x78\x01\0\0\x0f\0\0\0\xd8\x06\0\0\x07\0\0\0\x90\x01\0\0\x03\0\0\0\
\xd8\x06\0\0\x07\0\0\0\xa8\x01\0\0\x10\0\0\0\xd8\x06\0\0\x07\0\0\0\xc0\x01\0\0\
\x11\0\0\0\xd8\x06\0\0\x07\0\0\0\xd8\x01\0\0\x15\0\0\0\xd8\x06\0\0\x07\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\
\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xae\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\
\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x10\x02\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x04\
\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x32\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x04\0\0\0\0\0\0\
\x34\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x83\0\0\
\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x04\0\0\0\0\0\0\x10\0\0\0\0\
\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa0\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x04\0\0\0\0\0\0\x24\x0a\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa5\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x50\x0e\0\0\0\0\0\0\xec\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_CORE_RELOC_TYPE_ID_SKEL_H__ */